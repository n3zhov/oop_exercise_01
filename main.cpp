#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

class Complex
{
    private:
        double a, b;
    public:
        Complex(){
            a = 0;
            b = 0;
        }
        Complex(double arg1, double arg2){
            a = arg1;
            b = arg2;
        }
        double get_a() const{
            return a;
        }
        double get_b() const{
            return b;
        }
        void set_a(double input){
            a = input;
        }
        void set_b(double input){
            b = input;
        }
        double mod() const{
            return sqrt(a*a + b*b);
        }
        void Print() const{
            cout << a;
            if (b > 0)
                cout << "+";
            cout << b << "*i" << endl;
        }
        Complex coni(){
            Complex res = Complex(a, -b);
            return res;
        }
        friend Complex operator +(Complex &first, Complex &second);
        friend Complex operator -(Complex &first, Complex &second);
        friend Complex operator *(Complex &first, Complex &second);
        friend Complex operator /(Complex &first, Complex &second);
        friend Complex coni(Complex &comp);
        friend bool operator ==(Complex &first, Complex &second);

        ~Complex() //деструктор
        = default;
};

Complex operator +(Complex &first, Complex &second){
    Complex res = Complex(first.a + second.a, first.b + second.b);
    return res;
}

Complex operator -(Complex &first, Complex &second){
    Complex res = Complex(first.a - second.a, first.b - second.b);
    return res;
}

Complex operator *(Complex &first, Complex &second){
    Complex res = Complex(first.a * second.a - first.b*second.b, first.a*second.b + first.b*second.a);
    return res;
}

Complex operator /(Complex &first, Complex &second){
    Complex res = Complex((first.a * second.a + first.b*second.b)/(second.mod()*second.mod()), 
                            (first.b*second.a-first.a*second.b)/(second.mod()*second.mod()));
    return res;
}

bool operator < (Complex &first, Complex &second){
    if (first.mod() < second.mod())
        return true;
    else
        return false;
}

bool operator > (Complex &first, Complex &second){
    if (first.mod() > second.mod())
        return true;
    else
        return false;
}

bool operator >= (Complex &first, Complex &second){
    if (first.mod() >= second.mod())
        return true;
    else
        return false;
}

bool operator <= (Complex &first, Complex &second){
    if (first.mod() <= second.mod())
        return true;
    else
        return false;
}

bool operator ==(Complex &first, Complex &second){
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
        if(cin.fail()){
            cout << "ERROR!" << endl;
            return 0;
        }
    }
    else
    {
        ifstream file (argv[1]);
        file >> a1 >> b1 >> a2 >> b2;
        if(file.fail()){
            cout << "ERROR!" << endl;
            return 0;
        }
        file.close();
    }
    Complex a = Complex (a1, b1);
    Complex b = Complex(a2, b2);
    Complex res = Complex();

    res = a+b;
    cout << "a + b = ";
    res.Print();
    res = a-b;
    cout << "a - b = ";
    res.Print();
    res = a*b;
    cout << "a * b = ";
    res.Print();
    res = a/b;
    cout << "a / b = ";
    res.Print();
    res = a.coni();
    cout << "Сопряжённое с a: ";
    res.Print();
    res = b.coni();
    cout << "Сопряжённое с b: ";
    res.Print();
    cout << "a < b?: " << (int)(a<b) << endl << "a > b ?: " << (int)(a>b) << endl << "a == b ?: " <<  (int)(a==b)
                                                                                                        << endl;
    return 0;
}