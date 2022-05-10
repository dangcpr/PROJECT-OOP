#include <iostream>
#include "Header.h"
using namespace std;

int main()
{
    Fullname f = Fullname("John", "Walker");
    Employee* e = new DailyEmployee(f, 100, 28);
    cout << e->toString();
    delete e;
    return 0;
}