/*Ежов 204
 *Комплексные числа
 * Сложение, вычитание, умножение, деление
 * нахождение сопряжённого, сравнение комплексных чисел
 * */
#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

class Complex
{
    private:
        double a, b;
    public:
        Complex(){
            //Коэфициенты комплексного числа
            a = 0;
            b = 0;
        }
        //Конструктор
        Complex(double arg1, double arg2){
            a = arg1;
            b = arg2;
        }
        //Геттеры и сеттеры для private переменных
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
        //Нахождение модуля комплексного числа
        double Mod() const{
            return sqrt(a*a + b*b);
        }
        //Печать комплексного числа в консоль
        void Print() const{
            cout << a;
            if (b > 0)
                cout << "+";
            cout << b << "*i" << endl;
        }
        //Функция нахлждения сопряжённого
        Complex Coni(){
            Complex res = Complex(a, -b);
            return res;
        }
        //Прототипы операторов
        friend Complex operator +(Complex &first, Complex &second);
        friend Complex operator -(Complex &first, Complex &second);
        friend Complex operator *(Complex &first, Complex &second);
        friend Complex operator /(Complex &first, Complex &second);
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
    Complex res = Complex((first.a * second.a + first.b*second.b)/(second.Mod()*second.Mod()), 
                            (first.b*second.a-first.a*second.b)/(second.Mod()*second.Mod()));
    return res;
}

bool operator < (Complex &first, Complex &second){
    if (first.Mod() < second.Mod())
        return true;
    else
        return false;
}

bool operator > (Complex &first, Complex &second){
    if (first.Mod() > second.Mod())
        return true;
    else
        return false;
}

bool operator >= (Complex &first, Complex &second){
    if (first.Mod() >= second.Mod())
        return true;
    else
        return false;
}

bool operator <= (Complex &first, Complex &second){
    if (first.Mod() <= second.Mod())
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
    //Если передали аргументом имя файла, то читаем комплексные числа из него
    if (argc == 1)
    {
        cin >> a1 >> b1 >> a2 >> b2;
        if(cin.fail()){
            //Если не число, то выдаём ошибку
            cout << "ERROR!" << endl;
            return 1;
        }
    }
    //В ином случае читаем с консоли
    else
    {
        ifstream file (argv[1]);
        file >> a1 >> b1 >> a2 >> b2;
        if(file.fail()){
            //Если не число, то выдаём ошибку
            cout << "ERROR!" << endl;
            return 1;
        }
        file.close();
    }
    //Первое комплексное число
    Complex a = Complex (a1, b1);
    //Второе комплексное число
    Complex b = Complex(a2, b2);
    //Комплексное число для хранения результатов арифмитических операций
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
    res = a.Coni();
    cout << "Сопряжённое с a: ";
    res.Print();
    res = b.Coni();
    cout << "Сопряжённое с b: ";
    res.Print();
    cout << "a < b?: " << (int)(a<b) << endl << "a > b ?: " << (int)(a>b) << endl << "a == b ?: " <<  (int)(a==b)
                                                                                                        << endl;
    return 0;
}