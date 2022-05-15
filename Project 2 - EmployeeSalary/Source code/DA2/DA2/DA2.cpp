#include <iostream>
#include <conio.h>
#include <regex>
#include "Header.h"
using namespace std;

Manager* Manager::member = NULL;
DailyEmployee* DailyEmployee::member = NULL;
HourlyEmployee* HourlyEmployee::member = NULL;
ProductEmployee* ProductEmployee::member = NULL;

void DisplayMenu() {
    cout << "Menu:" << endl;
    cout << "1. In thong tin." << endl;
    cout << "0. Thoat chuong trinh." << endl;
}
void errorCode(string n) {
    switch (stoi(n)) {
    case 1: cout << "Ban da nhap chuoi rong, vui long nhap lai: "; break;
    case 2: cout << "Lenh ban nhap khong hop le, vui long nhap lai: "; break;
    default:
        cout << "Thanh cong.";
    }
}
class Choice {
public:
    static const int InfoList = 1;
    static const int Exit = 0;
};
int main()
{
    int code;
    ListEmployee* L = new ListEmployee("Test.txt", code);
    if (code == 0) {
        _getch();
        return 0;
    }
    string choice;
    bool continue_program = true;
    do {
        DisplayMenu();
        cout << "Nhap lenh: ";
        getline(cin, choice);
        regex match("[01]");

        while (choice == "" || regex_match(choice, match) == false) {
            if (choice == "") errorCode("1");
            else if (regex_match(choice, match) == false) errorCode("2");
            getline(cin, choice);
        }
        //S.infoList();
        if (choice == to_string(Choice::InfoList)) {
            cout << endl; L->infoList();
        }
        else if (choice == to_string(Choice::Exit)) {
            continue_program = false;
        }
        cout << endl;
    } while (continue_program);
    return 0;
}