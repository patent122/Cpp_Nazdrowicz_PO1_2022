#include <iostream>

using namespace std;

class klasa
{
public:
	klasa(char c)
	{
		this->c = c;
		i = j = 0;
		x = y = 0.0;
		cout << "konstruktor klasa(char c)" << endl;
		cout << "c = " << c << endl;
	}

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

	// konstruktor kopiujący
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
	klasa k1(444, 555);
	klasa k2 = k1;



	return 0;
}
