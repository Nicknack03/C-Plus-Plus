#include <iostream>

using namespace std;

class Time
{
private:
    int hours;
    int minutes;

public:
    // Set the time
    void setTime(int h, int m)
    {
        hours = h;
        minutes = m;
    }

    // Display the time
    void display() const
    {
        cout << hours << " Hours " << minutes << " Minutes" << endl;
    }

    // Friend function declaration
    friend Time add(Time t1, Time t2);
};

// Friend function definition
Time add(Time t1, Time t2)
{
    Time result;

    result.minutes = t1.minutes + t2.minutes;
    result.hours = t1.hours + t2.hours;

    // Convert extra minutes into hours
    result.hours += result.minutes / 60;
    result.minutes %= 60;

    return result;
}

int main()
{
    Time t1, t2, t3;

    t1.setTime(2, 45);
    t2.setTime(3, 30);

    t3 = add(t1, t2);

    cout << "Time 1 : ";
    t1.display();

    cout << "Time 2 : ";
    t2.display();

    cout << "Total  : ";
    t3.display();

    return 0;
}