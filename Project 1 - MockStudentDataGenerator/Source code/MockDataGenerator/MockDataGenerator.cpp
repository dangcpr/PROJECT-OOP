#include <iostream>
#include <iomanip>
#include <regex>
#include "Header.h"
using namespace std;

void DisplayMenu() {
    cout << "Menu:" << endl;
    cout << "1. Random them sinh vien." << endl;
    cout << "2. Diem trung binh toan danh sach va cac sinh vien co diem cao hon." << endl;
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
    static const int RandomNew = 1;
    static const int AverageStudent = 2;
    static const int Exit = 0;
};

int main()
{
    srand(time(NULL));
    vectorStudent S("students.txt");
    string choice;
    bool continue_program = true;
    do {
        DisplayMenu();
        cout << "Nhap lenh: ";
        getline(cin, choice);
        regex match("[012]");

        while (choice == "" || regex_match(choice, match) == false) {
            if (choice == "") errorCode("1");
            else if (regex_match(choice, match) == false) errorCode("2");
            getline(cin, choice);
        }
        //S.infoList();
        if (choice == to_string(Choice::RandomNew)) {
            S.RandomListStudent();
            S.saveList("students.txt");
        }
        else if (choice == to_string(Choice::AverageStudent)) {
            cout << endl << "Diem trung binh toan danh sach: " << S.averageGPA() << endl;
            cout << endl << "Danh sach sinh vien co diem tren trung binh toan danh sach:" << endl;
            S.StudentMoreAveGPA();
        }
        else if (choice == to_string(Choice::Exit)) {
            continue_program = false;
        }
        cout << endl;
    } while (continue_program);
    return 0;
}