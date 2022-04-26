#include <iostream>
#include <iomanip>
#include "Header.h"
using namespace std;

int main()
{
    srand(time(NULL));
    vectorStudent S("students.txt");
    S.RandomListStudent();
    S.infoList();
    S.saveList("students.txt");
}