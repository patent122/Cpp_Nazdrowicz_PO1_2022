#include <iostream>

using namespace std;

// przykładowe stałe
const char DOMYSLNA_LITERA = 'a';
const int DOMYSLNA_LICZBA = 123;

class klasa
{
public:
	// dodano listę inicjalizacyjną
	klasa(char c) : i(DOMYSLNA_LICZBA), j(DOMYSLNA_LICZBA), x(0.0), y(0.0)
	{
		this->c = c;
		cout << "konstruktor klasa(char c)" << endl;
		cout << "c = " << c << endl;
	}

	// dodano listę inicjalizacyjną
	klasa(int i, int j) : c(DOMYSLNA_LITERA), x(0.0), y(0.0)
	{
		this->i = i;
		this->j = j;
		cout << "konstruktor klasa(int i, int j)" << endl;
		cout << "i = " << i << endl;
		cout << "j = " << j << endl;
	}

	// dodano listę inicjalizacyjną
	klasa(double x, double y) : c(DOMYSLNA_LITERA), i(DOMYSLNA_LICZBA), j(DOMYSLNA_LICZBA)
	{
		this->x = x;
		this->y = y;
		cout << "konstruktor klasa(double x, double y)" << endl;
		cout << "x = " << x << endl;
		cout << "y = " << y << endl;
	}

	klasa(const klasa& inny)
	{
		c = inny.c;
		i = inny.i;
		j = inny.j;
		x = inny.x;
		y = inny.y;
		cout << "konstruktor kopiujący" << endl;
		cout << "c = " << c << endl;
		cout << "i = " << i << endl;
		cout << "j = " << j << endl;
		cout << "x = " << x << endl;
		cout << "y = " << y << endl;
	}

	char getC() const { return c; }
	int getI() const { return i; }
	int getJ() const { return j; }
	double getX() const { return x; }
	double getY() const { return y; }
private:
	char c;
	int i;
	int j;
	double x;
	double y;
};

int main(int argc, char** argv)
{
	// test
	klasa k1('x');
	klasa k2 = k1;


	return 0;
}
