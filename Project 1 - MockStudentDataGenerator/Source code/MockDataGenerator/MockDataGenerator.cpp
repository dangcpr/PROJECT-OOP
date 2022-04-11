#include <iostream>
#include <iomanip>
#include "Header.h"
using namespace std;

int main()
{
    vectorStudent S("students.txt");
    FakeEmail email;
    srand(time(NULL));
    string name = "Tran Nguyen Van Minh";
    cout << email.next(name);
    cout << '\n' << name;

    //Test Date of Birth;
    int day, month, year;
    FakeBirthday k;
    k.next(day, month, year);
    cout.fill('0');
    cout << endl << setw(2) << day << setw(2) << month << setw(4) << year;
}