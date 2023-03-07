#include <iostream>

using namespace std;

// klasa punkty 2D
class punkt
{
public:
	// konstruktor
	punkt(double x, double y)
	{
		this->x = x;
		this->y = y;
	}

	// gettery
	double getX() const { return x; }
	double getY() const { return y; }
private:
	double x;
	double y;
};

// klasa wektora (właściwie jest to odcinek bo składa się z 2 punktów)
class wektor
{
public:
	// konstruktor domyślny
	wektor() : a(0, 0), b(1, 1)
	{
		ileInstancji++;
	}
	
	// konstruktor przyjmujący 2 punkty
	wektor(const punkt& a, const punkt& b) : a(a), b(b)
	{
		ileInstancji++;
	}

	// destruktor
	~wektor()
	{
		cout << "Zadanie wykonane" << endl;
	}

	// dodawanie wektorów
	wektor dodaj(const wektor& inny)
	{
		return wektor(punkt(a.getX() + inny.a.getX(), a.getY() + inny.a.getY()), 
			punkt(b.getX() + inny.b.getX(), b.getY() + inny.b.getY()));
	}

	// odejmowanie wektorów
	wektor odejmij(const wektor& inny)
	{
		return wektor(punkt(a.getX() - inny.a.getX(), a.getY() - inny.a.getY()),
			punkt(b.getX() - inny.b.getX(), b.getY() - inny.b.getY()));
	}

	// mnożenie przez skalar
	wektor pomnoz(double wartosc)
	{
		return wektor(punkt(a.getX() * wartosc, a.getY() * wartosc),
			punkt(b.getX() * wartosc, b.getY() * wartosc));
	}

	// zwraca liczbę utworzonych instancji
	static int getIleInstancji()
	{
		return ileInstancji;
	}
private:
	punkt a;
	punkt b;
	static int ileInstancji;
};

// zmienne statyczne trzeba inicjalizować "na zewnątrz", tak właśnie jest
// w przypadku zmiennej ileInstancji należącej do klasy wektor
int wektor::ileInstancji = 0;

// początek programu
int main(int argc, char** argv)
{
	// przykładowe wektory
	wektor w1(punkt(0, 0), punkt(0, 5));
	wektor w2(punkt(0, 0), punkt(5, 0));
	wektor w3 = w1.dodaj(w2);
	wektor w4 = w1.odejmij(w2);
	wektor w5 = w1.pomnoz(1.2345);

	// wypisanie informacji
	cout << "Liczba utworzonych wektorów: " << wektor::getIleInstancji() << endl;

	return 0;
}
