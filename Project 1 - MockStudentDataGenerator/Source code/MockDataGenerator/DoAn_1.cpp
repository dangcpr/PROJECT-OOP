#include <iostream>
#include <cstdlib>
#include <ctime>	
#include <vector >	
#include <sstream>
#include <fstream>

using namespace std;

class Student {
public:
	vector<string> sinh_id();
	vector<string> sinh_name(int );
};
vector<string> Student::sinh_id() {
	vector<string> g;
	stringstream buil[1001];
	int fgh = rand() % (99 - 1 + 1) + 1;//=-------999
	for (int i = 1;i <= fgh;i++) {
		int ab = rand() % (21 - 18 + 1) + 18;
		int cd = rand() % (28 - 11 + 1) + 11;
		int c[5] = {0,5,6,7};
		int cc = rand() % (4 - 1 + 1) + 1;
		buil[i] << ab << cd << c[cc];
		if (i <= 9)
			buil[i] << "00" << i;
		else if (i <= 99)
			buil[i] << "0" << i;
		else
			buil[i] << i;	
	}
	for (int i = 1;i <= fgh;i++) {
		 g.push_back(buil[i].str()) ;
	}
	return g;
}
vector<string> Student::sinh_name(int n) {
	stringstream buil[1000];
	string s[18] = {"Nguyen", "Le", "Bui", "Pham", "Vu", "Vo", "Hoang", "Huynh", "Do", "Phan", "Dang", "Tran", "Ho", "Ngo", "Duong", "Ly"};
	for (int i = 1;i <= n;i++) {
		int a = rand() % (90 - 0 + 1) + 0;
		float b = rand() % (9 - 0 + 1) + 0;
		b = b / 10;

		float ab = (float)a + b;
		if (ab > 0 && ab <= 38.4) {
			buil[i] << s[0];
		}
		else if (ab <= 48.7) {
			buil[i] << s[1];
		}
		else if (ab <= 56.9) {
			buil[i] << s[2];
		}
		else if (ab <= 63.6) {
			buil[i] << s[3];
		}
		else if (ab <= 69.1) {
			int c = rand() % (2 - 1 + 1) + 1;
			if (c == 1)
				buil[i] << s[4];
			else
				buil[i] << s[5];
		}
		else if (ab <= 73.1) {
			int c = rand() % (2 - 1 + 1) + 1;
			if (c == 1)
				buil[i] << s[6];
			else
				buil[i] << s[7];
		}
		else if (ab <= 76.5) {
			buil[i] << s[8];
		}
		else if (ab <= 79.6) {
			buil[i] << s[9];
		}
		else if (ab <= 82.1) {
			buil[i] << s[10];
		}
		else if (ab <= 84.2) {
			buil[i] << s[11];
		}
		else if (ab <= 85.5) {
			buil[i] << s[12];
		}
		else if (ab <= 86.8) {
			buil[i] << s[13];
		}
		else if (ab <= 87.8) {
			buil[i] << s[14];
		}
		else if (ab <= 88.3) {
			buil[i] << s[15];
		}
		else {
			fstream of;
			string Ho_phu[10000];
			of.open("Ho.txt");
			int nn = 1;
			while (of >> Ho_phu[nn]) {
				nn++;
			}
			of.close();
			nn--;

			int ho = rand() % (nn - 1 + 1) + 1;
			buil[i] << ' ' << Ho_phu[ho];
		}
		//Ten lot 
		fstream oof;
		string lot[10000];
		oof.open("Tenlot.txt");
		int nn = 1;
		while (oof >> lot[nn]) {
			nn++;
		}
		oof.close();
		nn--;
		int tenlot = rand() % (nn - 0 + 1) + 0;
		if (tenlot != 0)
			buil[i] << ' ' << lot[tenlot];

		//Ten
		fstream of;
		string name[10000];
		of.open("Ten.txt");
		nn = 1;
		while (of >> name[nn]) {
			nn++;
		}
		of.close();
		nn--;
		int ten = rand() % (nn - 1 + 1) + 1;
		buil[i] << ' ' << name[ten];
	}
	vector<string>g;
	for (int i = 1;i <= n;i++) {
		g.push_back(buil[i].str());
	}
	return g;
}
int main() {
	srand((unsigned)time(0));
	Student a;
	vector<string> g = a.sinh_id();
	vector<string> g2 = a.sinh_name(g.size());
	for (int i = 0;i < g.size();i++) {
		cout << g[i] << ' ' << g2[i] << endl;
	}

}