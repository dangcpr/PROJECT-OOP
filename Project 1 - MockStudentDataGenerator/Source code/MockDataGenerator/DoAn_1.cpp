#include <iostream>
#include <cstdlib>
#include <ctime>	
#include <vector >	
#include <sstream>
#include <fstream>

using namespace std;
class Rand_id;//3 i
class Rand_name;//3 ii
class Rand_SDT;//3 iv
class Rand_interger;// 2
class Rand_GPA;//3 iii
class Rand_GPA {
public:
	vector<string> rand_gpa(int );
};
class Rand_interger {
public:
	int rand();
};
int Rand_interger::rand() {
	int r = 10;
	int l = 5;
	int n = rand() % (r - l + 1) + 1;
	return n;
}
class Rand_id {
public:
	vector<string> rand_id();
};	

class Rand_name {
public:
	vector<string> rand_name(int);
};
class Rand_SDT {
public :
	vector<string> rand_sdt(int);
};
vector<string> Rand_GPA::rand_gpa(int n) {
	vector<string> g;
	stringstream buil[1001];
	for (int i = 1;i <= n;i++) {
		int l = 0;
		int r = 10;
		int a = rand() % (r - l + 1) + l;
		if (a == 10)
			buil[i] << a << '.' << "00";
		else {
			r = 9;
			int b = rand() % (r - l + 1) + l;
			int c = rand() % (r - l + 1) + l;
			buil[i] << a << '.' << b << c;
		}
	}
	for (int i = 1;i <= n;i++) {
		g.push_back(buil[i].str());
	}
	return g;
}
vector<string> Rand_SDT::rand_sdt(int n) {
	vector<string> g;
	stringstream buil[1001];
	string mb[10] = { "090", "093", "089", "070", "079", "077", "076", "078" };
	string vt[15] = { "086", "096", "097", "098", "032", "033", "034", "035", "036", "037", "038", "039" };
	string vn[10] = { "088", "091", "094", "081", "082", "083", "084", "085" };
	string vnmb[5] = { "092", "056", "058" };
	for (int i = 1;i <= n;i++) {
		int a = rand() % (4 - 1 + 1) + 1;
		int b = 0;
		if (a == 1) {
			b = rand() % (8 - 1 + 1) + 1;
			buil[i] << mb[b - 1];
		}
		else if (a == 2) {
			b = rand() % (12 - 1 + 1) + 1;
			buil[i] << vt[b - 1];
		}
		else if (a == 3) {
			b = rand() % (8 - 1 + 1) + 1;
			buil[i] << vn[b - 1];
		}
		else if (a == 4) {
			b = rand() % (3 - 1 + 1) + 1;
			buil[i] << vnmb[b - 1];
		}
		for (int j = 1;j <= 7;j++) {
			int c = rand() % (9 - 0 + 1) + 0;
			buil[i] << c;
		}
	}
	for (int i = 1;i <= n;i++) {
		g.push_back(buil[i].str());
	}
	return g;
}
vector<string> Rand_id::rand_id() {
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
		 g.push_back(buil[i].str());
	}
	return g;
}

vector<string> Rand_name::rand_name(int n) {
	stringstream buil[1000];
	string s[18] = {"Nguyen", "Le", "Bui", "Pham", "Vu", "Vo", "Hoang", "Huynh", "Do", "Phan", "Dang", "Tran", "Ho", "Ngo", "Duong", "Ly"};
	//s[] : ho pho bien 
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
	Rand_id a;
	vector<string> g = a.rand_id();

	Rand_name b;
	vector<string> g2 = b.rand_name(g.size());

	Rand_SDT c;
	vector<string> g3 = c.rand_sdt(g.size());

	Rand_GPA d;
	vector<string> g4 = d.rand_gpa(g.size());

	for (int i = 0;i < g.size();i++) {
		cout << g[i] << ' ' << g2[i] << ' ' << g3[i] << ' ' << g4[i] << endl;
	}

}
