#include <iostream>
#include <cstdlib>
#include <ctime>	
#include <vector >	
#include <sstream>
#include <fstream>
#include <iomanip>

using namespace std;
class Rand_id;//3 i
class Rand_SDT;//3 iv
class Rand_interger;// 2
class Rand_GPA;//3 iii
class Fullname;
class RandomIntegerGenerator;
class RandomFullnameGenerator;

class RandomIntegerGenerator {
public:
	RandomIntegerGenerator();
public:
	int next();
	int next(int);
	int next(int, int);
};
RandomIntegerGenerator::RandomIntegerGenerator() {
	srand((unsigned)time(0));
}
int RandomIntegerGenerator::next() {
	int result = rand();
	return result;
}
/// <summary>
/// Sinh số ngẫu nhiên trong nửa khoảng [0, max)
/// </summary>
/// <param name="ceiling">Giá trị tối đa</param>
/// <returns>Số nguyên ngẫu nhiên</returns>
int RandomIntegerGenerator::next(int ceiling) {
	int result = rand() % ceiling;
	return result;
}
/// <summary>
/// Sinh số ngẫu nhiên trong đoạn [left, right]
/// </summary>
/// <param name="left">Biên trái</param>
/// <param name="right">Biên phải</param>
/// <returns>Số nguyên ngẫu nhiên</returns>
int RandomIntegerGenerator::next(int left, int right) {
	int result = rand() % (right - left + 1) + left;
	return result;
}

class Fullname {
private:
	string _firstname;
	string _middlename;
	string _lastname;
public:
	Fullname(string first, string middle, string last) {
		_firstname = first;
		_middlename = middle;
		_lastname = last;
	}

	string toString() {
		stringstream builder;

		builder << _firstname << " "
			<< _middlename << " "
			<< _lastname;

		string result = builder.str();
		return result;
	}
};
class RandomFullnameGenerator {
private:
	vector<string> _CommonfirstNames;
	vector<string> _firstNames;
	vector<string> _middleNames;
	vector<string> _lastNames;
	RandomIntegerGenerator _rng;

public:
	RandomFullnameGenerator();
	Fullname next();
};
RandomFullnameGenerator::RandomFullnameGenerator() {
	_CommonfirstNames = {"Nguyen", "Le", "Bui", "Pham", "Vu", "Vo", "Hoang", "Huynh", "Do", "Phan", "Dang", "Tran", "Ho", "Ngo", "Duong", "Ly"};//Ho

	fstream of;
	string Ho_phu;
	of.open("Ho.txt");
	//int nn = 1;
	while (of >> Ho_phu) {//////////// Doc file ho pho bien
		//nn++;
		_firstNames.push_back(Ho_phu);
	}
	of.close();
	//nn--;

	fstream oof;
	string lot;
	oof.open("Tenlot.txt");
	//int nn = 1;
	while (oof >> lot) {//////////// Doc file ten lot
		//nn++;
		_middleNames.push_back(lot);
	}
	oof.close();

	fstream ff;
	string name;
	ff.open("Ten.txt");
	//nn = 1;
	while (ff >> name) {//////////// Doc file ten
		_lastNames.push_back(name);
		//nn++;
	}
	ff.close();
	//nn--;
}

Fullname RandomFullnameGenerator::next() {
	int a = _rng.next(90);
	int b1 = _rng.next(9);
	float b = (float)((float)b1 / 10);

	string first = "";
	float ab = (float)a + b;
	if (ab > 0 && ab <= 38.4) {
		first = _firstNames[0];
	}
	else if (ab <= 48.7) {
		first = _firstNames[1];
	}
	else if (ab <= 56.9) {
		first = _firstNames[2];
	}
	else if (ab <= 63.6) {
		first = _firstNames[3];
	}
	else if (ab <= 69.1) {
		int c = _rng.next(1, 2);
		if (c == 1)
			first = _firstNames[4];
		else
			first = _firstNames[5];
	}
	else if (ab <= 73.1) {
		int c = _rng.next(1,2);
		if (c == 1)
			first = _firstNames[6];
		else
			first = _firstNames[7];
	}
	else if (ab <= 76.5) {
		first = _firstNames[8];
	}
	else if (ab <= 79.6) {
		first = _firstNames[9];
	}
	else if (ab <= 82.1) {
		first = _firstNames[10];
	}
	else if (ab <= 84.2) {
		first = _firstNames[11];
	}
	else if (ab <= 85.5) {
		first = _firstNames[12];
	}
	else if (ab <= 86.8) {
		first = _firstNames[13];
	}
	else if (ab <= 87.8) {
		first = _firstNames[14];
	}
	else if (ab <= 88.3) {
		first = _firstNames[15];
	}
	else {
		int ho = _rng.next(_CommonfirstNames.size());
		first = _CommonfirstNames[ho];
	}

	int tenlot = _rng.next(_middleNames.size());
	string middle = _middleNames[tenlot];

	int ten = _rng.next(_lastNames.size());
	string last = _lastNames[ten];

	Fullname result(first, middle, last);
	return result;
}

class Rand_GPA {
private:
	RandomIntegerGenerator _rng;
public:
	double rand_gpa( );
};

double Rand_GPA::rand_gpa() {
	stringstream buil;
	int l = 0;
	int r = 10;
	int a = rand() % (r - l + 1) + l;
	if (a == 10)
		//buil << a << '.' << "00";
		return (double)a;
	else {
		r = 9;
		int b = _rng.next(l,r);
		int c = _rng.next(l,r);
		double gpa = a + (double)b / 10 + (double)c / 100;
		//buil << a << '.' << b << c;
		return gpa;
	}

}
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
private:
	RandomIntegerGenerator _rng;
public:
	string rand_id();
};	
string Rand_id::rand_id() {
	stringstream buil;
	int ab = _rng.next(18, 21);
	int cd = _rng.next(11, 28);
	int c[5] = { 0,5,6,7 };
	int cc = _rng.next(1, 4);;
	buil << ab << cd << c[cc];
	
	return buil.str();
}
class Rand_SDT {
private:
	vector<string> mb;
	vector<string> vt;
	vector<string> vn;
	vector<string> vnmb;
	RandomIntegerGenerator _rng;

public :
	Rand_SDT();
	string rand_sdt();
};
Rand_SDT::Rand_SDT() {
	mb = { "090", "093", "089", "070", "079", "077", "076", "078" };
	vt = { "086", "096", "097", "098", "032", "033", "034", "035", "036", "037", "038", "039" };
	vn = { "088", "091", "094", "081", "082", "083", "084", "085" };
	vnmb = { "092", "056", "058" };
}

string Rand_SDT::rand_sdt() {
	stringstream buil;
	
	int a = _rng.next(1, 4);
	int b = 0;
	if (a == 1) {
		b = _rng.next(1,8);
		buil << mb[b - 1];
	}
	else if (a == 2) {
		b = _rng.next(1, 12);;
		buil << vt[b - 1];
	}
	else if (a == 3) {
		b = _rng.next(1, 8);;
		buil << vn[b - 1];
	}
	else if (a == 4) {
		b = _rng.next(1, 3);
		buil << vnmb[b - 1];
	}
	for (int j = 1;j <= 7;j++) {
		int c = _rng.next(0, 9);;
		buil << c;
	}
	
	return buil.str();
}

int main() {
	srand((unsigned)time(0));
	RandomFullnameGenerator rng;
	Rand_GPA b;
	vector<Fullname> a;
	Rand_id c;
	Rand_SDT d;
	vector<string> v_id;
	int minimum = 10;
	int maximum = 270;

	stringstream buil[1001];
	for (int i = 0; i < 10; i++) {
		Fullname person = rng.next();
		a.push_back(person);
	
		string ID = c.rand_id();
		if (i <= 9)
			buil[i] << ID <<  "00" << i;
		else if (i <= 99)
			buil[i] << ID << "0" << i;
		else
			buil[i] << ID << i;
		v_id.push_back(buil[i].str());
	}


	for (int i = 0; i < a.size(); i++) {
		cout << v_id[i] <<' ' <<  a[i].toString() << ' ' << b.rand_gpa() << ' ' << d.rand_sdt() << endl;
	}
}
