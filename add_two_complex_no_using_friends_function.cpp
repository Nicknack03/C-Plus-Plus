#include <iostream>
using namespace std;

class Complex
{
private:
    float real, imag;

public:
    // Function to initialize the complex number
    void setData(float r, float i)
    {
        real = r;
        imag = i;
    }

    // Function to display the complex number
    void display() const
    {
        cout << real;

        if (imag >= 0)
            cout << " + j" << imag;
        else
            cout << " - j" << -imag;

        cout << endl;
    }

    // Friend function to add two complex numbers
    friend Complex add(Complex c1, Complex c2);
};

// Friend function definition
Complex add(Complex c1, Complex c2)
{
    Complex c3;
    c3.real = c1.real + c2.real;
    c3.imag = c1.imag + c2.imag;
    return c3;
}

int main()
{
    Complex c1, c2, c3;

    c1.setData(3.1, 5.65);
    c2.setData(2.75, 1.20);

    c3 = add(c1, c2);

    cout << "First Complex Number  : ";
    c1.display();

    cout << "Second Complex Number : ";
    c2.display();

    cout << "Sum of Complex Numbers: ";
    c3.display();

    return 0;
}