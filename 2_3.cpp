#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;
class Osoba {
private:
    string _imie;
    string _nazwisko;
    string _adres;
    unsigned int _pesel;
public:
    Osoba(const string& imie, const string& nazwisko, const string& adres, long long pesel)
    {
        _imie = imie;
        _nazwisko = nazwisko;
        _adres = adres;
        _pesel = pesel;
    }
    const string& getimie() const
    {
        return _imie;
    }

    const string& getnazwisko() const
    {
        return _nazwisko;
    }

    const string& getadres() const
    {
        return _adres;
    }

    long long getpesel() const
    {
        return _pesel;
    }

};

const int MAKSYMALNY_ROZMIAR_KARTOTEKI = 100;

class KartotekaOsob
{
private:
   Osoba* _osoby[MAKSYMALNY_ROZMIAR_KARTOTEKI]; // [NULL, NULL, ..., NULL]
   int _rozmiar;

public:
    KartotekaOsob()
    {
        _rozmiar = 0;
        for (int i = 0; i < MAKSYMALNY_ROZMIAR_KARTOTEKI; i++)
        {
            _osoby[i] = NULL;
        }
    }
    bool dodaj(const string& imie, const string& nazwisko, const string& adres, long long pesel)
    {
        if (_rozmiar < MAKSYMALNY_ROZMIAR_KARTOTEKI)
        {
            for (int i = 0; i < MAKSYMALNY_ROZMIAR_KARTOTEKI; i++)
            {
                if (_osoby[i] == NULL)
                {
                    Osoba *osoba = new Osoba(imie, nazwisko, adres, pesel);
                    _osoby[i] = osoba;

                    break;
                }
            }
            _rozmiar++;

            return true;
        }
        return false;


    }
    bool usun(long long pesel)
    {
        for (int i = 0; i < MAKSYMALNY_ROZMIAR_KARTOTEKI; i++)
        {
            if (_osoby[i] != NULL && _osoby[i]->getpesel() == pesel)
            {
                delete _osoby[i];
                _osoby[i] = NULL;
                _rozmiar--;
                return true;
            }
        }
        return false;
    }

    void wypisz()
    {
        for (int i = 0; i < MAKSYMALNY_ROZMIAR_KARTOTEKI; i++){
        if (_osoby[i] != NULL) {
            Osoba *osoba = _osoby[i];

            cout << osoba->getimie() << " " << osoba->getnazwisko() << " "
                 << osoba->getadres() << " " << setfill('0') << setw(11) <<
                 osoba->getpesel() << endl;
        }
        }
    }

    void zapisz(const string& sciezka)
    {
        ofstream plik(sciezka);

        if (plik.good());
        {
            for (int i = 0; i < MAKSYMALNY_ROZMIAR_KARTOTEKI; i++)
            {
                if (_osoby[i] != NULL)
                {
                    Osoba* osoba = _osoby[i];

                    plik << osoba->getimie() << endl;
                    plik << osoba->getnazwisko() << endl;
                    plik << osoba->getadres() << endl;
                    plik << osoba->getpesel() << endl;
                }
            }
            plik.close();
        }
    }

    void wczytaj(const string& sciezka)
    {
        ifstream plik(sciezka);

        if (plik.good())
        {
            string imie, nazwisko, adres, t;
            long long pesel;

            while (getline(plik, imie) && getline(plik, nazwisko) && getline(plik, adres) && getline(plik, t))
            {
                pesel = stoll(t);
                dodaj(imie, nazwisko, adres, pesel);
            }

            plik.close();
        }
    }

};


long long pobierzLiczbe()
{
    long long n;
    string t;

    cin >> n;
    getline(cin, t);
    return n;
}

void dodajOsobe(KartotekaOsob& kartoteka)
{
    string imie, nazwisko, adres;
    long long pesel;

    cout << "Podaj imię: ";
    getline(cin, imie);
    cout << "Podaj nazwisko ";
    getline(cin, nazwisko);
    cout << "Podaj adres ";
    getline(cin, adres);
    cout << "Podaj PESEL: ";
    pesel = pobierzLiczbe();

    if (kartoteka.dodaj(imie, nazwisko, adres, pesel))
    {
        cout << "OK" << endl;
    }
    else
    {
        cout << "BRAK MIEJSCA" << endl;
    }

}

void usunOsobe(KartotekaOsob& kartoteka) {
    long long pesel;
    cout << "Podaj PESEL:";
    pesel = pobierzLiczbe();
    if (kartoteka.usun(pesel)) {
        cout << "OK" << endl;
    } else {
        cout << "NIE ZNALEZIONO" << endl;
    }
}

int main() {

    system("chcp 65001 > NUL");

    KartotekaOsob kartoteka;


    int wybor = -1;

    kartoteka.wczytaj("Osoby.txt");

    while (wybor != 4){

        cout << "1) Dodaj osobę" << endl;
        cout << "2) Usuń osobę" << endl;
        cout << "3) Wypisz osoby" << endl;
        cout << "4) Zakończ" << endl;
        wybor = pobierzLiczbe();

        if (wybor == 1)
        {
           dodajOsobe(kartoteka);
        }
        else if (wybor == 2)
        {
            usunOsobe(kartoteka);
        }
        else if (wybor == 3)
        {
            kartoteka.wypisz();
        }
        else if (wybor != 4)
        {
            cout << "Nieprawidłowy wybor!" << endl;
        }
    }

    kartoteka.zapisz("Osoby.txt");

    return 0;
}
