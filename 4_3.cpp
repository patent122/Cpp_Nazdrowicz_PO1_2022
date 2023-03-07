#include <iostream>


using namespace std;


class Resistor
{
public:
    Resistor()
    {
        _r = 0.0;
    }

    Resistor(double wartosc)
    {
        _r = wartosc;
    }

    double r()
    {
        return _r;
    }
    void r(double wartosc)
    {
        _r = wartosc;
    }
    friend Resistor operator+(const Resistor& o1, const Resistor& o2);
    friend Resistor operator*(const Resistor& o1, const Resistor& o2);
    friend ostream& operator<<(ostream& out, const Resistor& o);
private:
    double _r;
};

Resistor operator+(const Resistor& o1, const Resistor& o2)
{
    return Resistor(o1._r + o2._r);
}
Resistor operator*(const Resistor& o1, const Resistor& o2)
{
    return Resistor((o1._r * o2._r) / (o1._r + o2._r));
}

ostream& operator<<(ostream& out, const Resistor& o)
{
    return out << o._r;
}

int main()
{
    Resistor opornik1(20), opornik2(10);
    Resistor opornik3 = opornik1 + opornik2;
    Resistor opornik4 = opornik1 * opornik2;

    cout << "opornik1 = " << opornik1.r() << endl;
    cout << "opornik2 = " << opornik2.r() << endl;
    cout << "opornik3 = " << opornik3.r() << endl;
    cout << "opornik4 = " << opornik4.r() << endl;

    opornik1.r(20);

    return 0;
}
