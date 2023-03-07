#include <iostream>

using namespace std;

// przykładowa klasa
class klasa
{
public:
	// konstruktor z 1 parametrem typu char
	klasa(char c)
	{
		this->c = c;
		i = j = 0;
		x = y = 0.0;
		cout << "konstruktor klasa(char c)" << endl;
		cout << "c = " << c << endl;
	}

	// konstruktor z dwoma parametrami typu int
	klasa(int i, int j)
	{
		c = 'a';
		this->i = i;
		this->j = j;
		x = y = 0.0;
		cout << "konstruktor klasa(int i, int j)" << endl;
		cout << "i = " << i << endl;
		cout << "j = " << j << endl;
	}

	// konstruktor z dwoma parametrami typu double
	klasa(double x, double y)
	{
		c = 'a';
		i = j = 0;
		this->x = x;
		this->y = y;
		cout << "konstruktor klasa(double x, double y)" << endl;
		cout << "x = " << x << endl;
		cout << "y = " << y << endl;
	}

	// gettery
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

// początek programu
int main(int argc, char** argv)
{
	// test
	klasa k1('a'), k2(123, 456), k3(1.111, 2.222);

	return 0;
}
