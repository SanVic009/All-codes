#include <iostream>
using namespace std;

class complex
{

    int real;
    int imag;

public:
    complex() : real(0), imag(0) {}

    void readcomplex()
    {
        cout << "Enter the real part : ";
        cin >> real;
        cout << "Enter the imaginary part : ";
        cin >> imag;
    }

    void printcomplex()
    {
        cout << "\n\n complex no. ";
        cout << real;
        cout << "+";
        cout << imag << "i" << endl;
    }

    complex operator+(complex c2)
    {
        complex temp;
        temp.real = real + c2.real;
        temp.imag = imag + c2.imag;

        return temp;
    }

    complex operator-(complex c2)
    {
        complex temp;
        temp.real = real - c2.real;
        temp.imag = imag - c2.imag;
        return temp;
    }

    complex operator*(complex c2)
    {
        complex temp;
        temp.real = (real * c2.real) - (imag * c2.imag);
        temp.imag = (imag * c2.real) + (real * c2.imag);
        return temp;
    }

    complex operator/(complex c2)
    {
        complex temp;
        temp.real = ((real * c2.real) + (imag * c2.imag)) / ((c2.real * c2.real) + (c2.imag * c2.imag));
        temp.imag = ((imag * c2.real) + (real * c2.imag)) / ((c2.real * c2.real) + (c2.imag * c2.imag));

        return temp;
    }
};

int main()
{
    complex c1, c2, c3;
    int choice = 0, cont;
    do
    {
        cout << "hello";
        cout << "\t\t COMPLEXNUMBERS\n\n 1.Addition \n\n 2.Subtraction \n\n 3. Multiplication \n\n 4. Division ";

        cout << "\n\n Enter your choice : ";
        cin >> choice;

        if (choice == 1 || choice == 2 || choice == 3 || choice == 4)
        {
            cout << "\n\n First complex Number \t";
            c1.readcomplex();
            cout << "\n\n Second Complex Number \t";
            c2.readcomplex();
        }

        switch (choice)
        {
        case 1:
            c3 = c1 + c2;
            cout << "\n\nSUM =  ";
            c3.printcomplex();
            break;

        case 2:
            c3 = c1 - c2;
            cout << "\n\nSubtraction=  ";
            c3.printcomplex();
            break;

        case 3:
            c3 = c1 * c2;
            cout << "\n\nproduct =  ";
            c3.printcomplex();
            break;

        case 4:
            c3 = c1 / c2;
            cout << "\n\nSUM =  ";
            c3.printcomplex();
            break;
        default:
            cout << "\n\n Undefined choice ";
        }

        cout << "\n\nDO you want to continue ?(1-Y,0-N)";
        cin >> cont;
    } while (cont == 1);
    return 0;
}