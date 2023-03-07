#include <iostream>


using namespace std;

class LiczbaZespolona
{
private:
    double _re; // 1
    double _im; // 2
public:
    LiczbaZespolona(double re = 1, double im = 1)
    {
        _re = re;
        _im = im;
    }

    // z1.dodaj(z2)
    LiczbaZespolona dodaj(LiczbaZespolona inna) // ina._re = 3, inna._im = 4
    {
        LiczbaZespolona wynik(_re + inna._re, _im + inna._im);

        return wynik;
    }
    LiczbaZespolona odejmij(LiczbaZespolona inna) // ina._re = 3, inna._im = 4
    {
        LiczbaZespolona wynik(_re - inna._re, _im - inna._im);

        return wynik;

        // a = _re
        // b = _im
        // c = inna._re
        // d = inna._im
    }
    LiczbaZespolona mnoz(LiczbaZespolona inna) // ina._re = 3, inna._im = 4
    {
        double re = _re * inna._re - _im * inna._im;
        double im = _re * inna._im - _im * inna._re;
        LiczbaZespolona wynik(re, im);

        return wynik;
    }
    LiczbaZespolona dziel(LiczbaZespolona inna)
    {
        double mianownik = inna._re * inna._re + inna._im * inna._im;
        double re = (_re * inna._re + _im * inna._im) / mianownik;
        double im = (_im * inna._re - _re * inna._im) / mianownik;
        LiczbaZespolona wynik(re, im);

        return wynik;
    }

    void wypisz()
    {
        // _re = 1
        // _im = 5
        // 1 + 5i

        cout << _re << " + " << _im << "i" << endl;
    }
};

int main() {

    system("chcp 65001 > NUL");

    // 01.Pobieramy pierwszą liczbę zespoloną
    // 02.Pobieramy drugą liczbą zespoloną
    // 03.Pobieramy rodzaj operacji (+, -, *, /)
    // 04.Wykonajumey działanie i wypisujemy wynik1

    double a, b, c ,d;

    cout << "z1.re = ";
    cin >> a;
    cout << "z1.im = ";
    cin >> b;
    cout << "z2.re = ";
    cin >> c;
    cout << "z2.im = ";
    cin >> d;

    LiczbaZespolona z1(a, b);
    LiczbaZespolona z2(c, d);
    LiczbaZespolona z7;

    z1.wypisz();
    z2.wypisz();

    LiczbaZespolona z3 = z1.dodaj(z2);  // z3 = z1 + z2
    LiczbaZespolona z4 = z1.odejmij(z2); // z4 = z1 - z2
    LiczbaZespolona z5 = z1.mnoz(z2);
    LiczbaZespolona z6 = z1.dziel(z2);

    cout << "z1 + z2 =";
    z3.wypisz();
    cout << "z1 - z2 =";
    z4.wypisz();
    cout << "z1 * z2 =";
    z5.wypisz();
    cout << "z1 / z2 =";
    z6.wypisz();
    cout << "Bez argumenetów = ";
    z7.wypisz();

    return 0;
}
