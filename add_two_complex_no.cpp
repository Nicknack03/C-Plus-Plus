#include <iostream>

using namespace std;

class Complex
{
private:
    float real;
    float imaginary;

public:
    // Function to initialize the complex number
    void setValue(float r, float i)
    {
        real = r;
        imaginary = i;
    }

    // Function to display the complex number
    void display() const
    {
        cout << real;

        if (imaginary >= 0)
            cout << " + ";

        cout << imaginary << "i" << endl;
    }

    // Function to add two complex numbers
    void add(const Complex &c1, const Complex &c2)
    {
        real = c1.real + c2.real;
        imaginary = c1.imaginary + c2.imaginary;
    }
};

int main()
{
    Complex c1, c2, c3;

    c1.setValue(3.1, 5.65);
    c2.setValue(2.75, 1.20);

    c3.add(c1, c2);

    cout << "First Complex Number : ";
    c1.display();

    cout << "Second Complex Number: ";
    c2.display();

    cout << "Sum                  : ";
    c3.display();

    return 0;
}