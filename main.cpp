#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

class Complex
{
    public:
        double a, b;
        Complex()
        {
            a = 0;
            b = 0;
        }
        Complex(double arg1, double arg2)
        {
            a = arg1;
            b = arg2;
        }
        double mod()
        {
            return sqrt(a*a + b*b);
        }
        void Print()
        {
            cout << a;
            if (b >= 0)
                cout << "+";
            cout << b << "*i" << endl;
        }
        ~Complex() //деструктор
        {

        }
};

Complex operator +(Complex &first, Complex &second)
{
    Complex res = Complex(first.a + second.a, first.b + second.b);
    return res;
}

Complex operator -(Complex &first, Complex &second)
{
    Complex res = Complex(first.a - second.a, first.b - second.b);
    return res;
}

Complex operator *(Complex &first, Complex &second)
{
    Complex res = Complex(first.a * second.a - first.b*second.b, first.a*second.b + first.b*second.a);
    return res;
}

Complex operator /(Complex &first, Complex &second)
{
    Complex res = Complex((first.a * second.a + first.b*second.b)/(second.mod()*second.mod()), 
                            (first.b*second.a-first.a*second.b)/(second.mod()*second.mod()));
    return res;
}

Complex coni(Complex &comp)
{
    Complex res = Complex(comp.a, -comp.b);
    return res;
}

bool operator < (Complex &first, Complex &second)
{
    if (first.mod() < second.mod())
        return true;
    else
        return false;
}

bool operator > (Complex &first, Complex &second)
{
    if (first.mod() > second.mod())
        return true;
    else
        return false;
}

bool operator >= (Complex &first, Complex &second)
{
    if (first.mod() >= second.mod())
        return true;
    else
        return false;
}

bool operator <= (Complex &first, Complex &second)
{
    if (first.mod() <= second.mod())
        return true;
    else
        return false;
}

bool operator ==(Complex &first, Complex &second)
{
    if(first.a == second.a && first.b == second.b)
        return true;
    else
        return false;
    
}

int main(int argc, char *argv[])
{
    double a1, b1, a2, b2;
    if (argc == 1)
    {
        cin >> a1 >> b1 >> a2 >> b2;
    }
    else
    {
        ifstream file (argv[1]);
        file >> a1 >> b1 >> a2 >> b2;
        file.close();
    }
    Complex a = Complex (a1, b1);
    Complex b = Complex(a2, b2);
    Complex res = Complex();

    res = a+b;
    res.Print();
    res = a-b;
    res.Print();
    res = a*b;
    res.Print();
    res = a/b;
    res.Print();
    res = coni(a);
    res.Print();
    cout << (int)(a<b) << ' ' << (int)(a>b) << (int)(a==b) << endl;
    return 0;
}