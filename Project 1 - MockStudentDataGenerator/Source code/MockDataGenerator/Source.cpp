#include <string>
#include <string.h>
#include <cctype>
#include <algorithm>
#include <regex>
#include <iomanip>
#include "Header.h"
#pragma warning(disable : 4996)

using namespace std;

int RandomIntegerGenerator::next() {
	int result = rand();
	return result;
}
int RandomIntegerGenerator::next(int ceiling) {
	int result = rand() % ceiling;
	return result;
}
int RandomIntegerGenerator::next(int left, int right) {
	int result = rand() % (right - left + 1) + left;
	return result;
}

unsigned long Number::RandomInteger(long left, long right) {
	unsigned long x = rand() & 0xff;
	x |= (rand() & 0xff) << 8;
	x |= (rand() & 0xff) << 16;
	x |= (rand() & 0xff) << 24;
	unsigned long a = x % (right - left + 1) + left;
	return a;
}

string Student::toStringFull() {
	stringstream ss;
	ss << "Student: " << id() << " - " << name().toString() << endl;
	ss << "\tGPA=" << fixed << setprecision(2) << GPA() << ", " << "Telephone: " << tel() << endl;
	ss << "\tEmail=" << email() << endl;
	ss << "\tDOB=" << DOB().toString() << endl;
	ss << "\tAddress=" << address() << endl;
	string s = ss.str();
	return s;
}
string Student::toStringShort() {
	stringstream ss;
	ss << id() << " - " << name().toString();
	ss << ", GPA: " << fixed << setprecision(2) << GPA() << endl;
	string s = ss.str();
	return s;
}

string date::toString() {
	stringstream ss;
	ss.fill('0');
	ss << setw(2) << _day << '/' << setw(2) << _month << '/' << setw(4) << _year;
	string s = ss.str();
	return s;
}
readStudent::readStudent(fstream& f, int& pos) {
	f.seekg(pos, ios::beg);
	string s1, s2, s3, s4; char c[256]; double d; int i, j, k;

	//Set id
	f.seekg(9, ios_base::cur); //"Student " co 9 ky tu
	f.getline(c, 256, '-');
	s1 = string(c);
	s1.erase(prev(s1.end())); //Xoa dau cach
	_S.setid(s1);

	//Set Name
	f.seekg(1, ios_base::cur); //Nhay 1 dau cach
	f.getline(c, 256, '\n');
	s1 = string(c);
	s2 = s1.substr(0, s1.find(' '));
	s3 = s1.substr(s1.rfind(' ') + 1, s1.length() - s1.rfind(' ') - 1);
	s4 = s1.substr(s1.find(' ') + 1, s1.rfind(' ') - s1.find(' ') - 1);
	Fullname name(s3, s4, s2);
	_S.setName(name);
	pos = f.tellg();
	//Set GPA
	f.seekg(8, ios_base::cur);//"    GPA=" co 8 ky tu
	f.getline(c, 256, ',');
	d = atof(c); _S.setGPA(d);

	//Set Tel
	f.seekg(11, ios_base::cur);//Nhay 11 ky tu
	f.getline(c, 256, '\n');
	s1 = string(c); _S.setTel(s1);

	//Set Email
	f.seekg(10, ios_base::cur);//"    Email=" co 10 ky tu
	f.getline(c, 256, '\n');
	s1 = string(c); _S.setEmail(s1);

	//Set DOB
	f.seekg(8, ios_base::cur);//"    DOB=" co 8 ky tu
	f.getline(c, 3, '/');
	i = atoi(c);  //Set Day
	f.getline(c, 3, '/');
	j = atoi(c); //Set Month
	f.getline(c, 5, '\n');
	k = atoi(c); //Set Year
	date DOB(i, j, k);
	_S.setDOB(DOB);

	//Set Address
	f.seekg(12, ios_base::cur);
	f.getline(c, 256, '\n');
	s1 = string(c); _S.setAddress(s1);
	pos = f.tellg();
}

FakeFullnameGenerator::FakeFullnameGenerator() {
	_CommonlastNames = { "Nguyen", "Le", "Bui", "Pham", "Vu", "Vo", "Hoang", "Huynh", "Do", "Phan", "Dang", "Tran", "Ho", "Ngo", "Duong", "Ly" };//Ho

	fstream of;
	string Ho_phu;
	of.open("Ho.txt");
	//int nn = 1;
	while (of >> Ho_phu) {//////////// Doc file ho pho bien
		//nn++;
		_lastNames.push_back(Ho_phu);
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
		_firstNames.push_back(name);
		//nn++;
	}
	ff.close();
	//nn--;
}

Fullname FakeFullnameGenerator::next() {
	int a = _rng.next(90);
	int b1 = _rng.next(9);
	double b = (double)((double)b1 / 10);

	string last = "";
	double random = ((double)rand()) / RAND_MAX;
	double ab = 100 * random;
	if (ab > 0 && ab <= 38.4) {
		last = _CommonlastNames[0];
	}
	else if (ab <= 48.7) {
		last = _CommonlastNames[1];
	}
	else if (ab <= 56.9) {
		last = _CommonlastNames[2];
	}
	else if (ab <= 63.6) {
		last = _CommonlastNames[3];
	}
	else if (ab <= 69.1) {
		int c = _rng.next(1, 2);
		if (c == 1)
			last = _CommonlastNames[4];
		else
			last = _CommonlastNames[5];
	}
	else if (ab <= 73.1) {
		int c = _rng.next(1, 2);
		if (c == 1)
			last = _CommonlastNames[6];
		else
			last = _CommonlastNames[7];
	}
	else if (ab <= 76.5) {
		last = _CommonlastNames[8];
	}
	else if (ab <= 79.6) {
		last = _CommonlastNames[9];
	}
	else if (ab <= 82.1) {
		last = _CommonlastNames[10];
	}
	else if (ab <= 84.2) {
		last = _CommonlastNames[11];
	}
	else if (ab <= 85.5) {
		last = _CommonlastNames[12];
	}
	else if (ab <= 86.8) {
		last = _CommonlastNames[13];
	}
	else if (ab <= 87.8) {
		last = _CommonlastNames[14];
	}
	else if (ab <= 88.3) {
		last = _CommonlastNames[15];
	}
	else {
		int ho = _rng.next(_lastNames.size());
		last = _lastNames[ho];
	}

	int tenlot = _rng.next(_middleNames.size());
	string middle = _middleNames[tenlot];

	int ten = _rng.next(_firstNames.size());
	string first = _firstNames[ten];

	Fullname result(first, middle, last);
	return result;
}

double FakeGPA::rand_gpa() {
	stringstream buil;
	int l = 0;
	int r = 10;
	int a = rand() % (r - l + 1) + l;
	if (a == 10)
		//buil << a << '.' << "00";
		return (double)a;
	else {
		r = 9;
		int b = _rng.next(l, r);
		int c = _rng.next(l, r);
		double gpa = a + (double)b / 10 + (double)c / 100;
		//buil << a << '.' << b << c;
		return gpa;
	}

}

int FakeInterger::rand() {
	int r = 10;
	int l = 5;
	int n = rand() % (r - l + 1) + 1;
	return n;
}

string FakeId::rand_id(int i, int year) {
	stringstream buil;
	int ab;
	if (year <= 2000) ab = _rng.next(18, 21);
	else if (year <= 2001) ab = _rng.next(19, 21);
	else if (year <= 2002) ab = _rng.next(20, 21);
	else ab = 21;
	int cd = _rng.next(11, 28);
	int c[5] = { 0,5,6,7 };
	int cc = _rng.next(1, 4);;
	buil << ab << cd << c[cc - 1];
	if (i <= 9)
		buil << "00" << i;
	else if (i <= 99)
		buil << "0" << i;
	else
		buil << i;
	return buil.str();
}

FakeEmail::FakeEmail() {
	_domain =
	{ "gmail.com","yahoo.com","hotmail.com","outlook.com","yandex.com","zoho.com","inbox.com","icloud.com","apple.com","vtv.vn" };
}
string FakeEmail::next(string name) {
	stringstream em;
	string tmp;
	transform(name.begin(), name.end(), name.begin(), ::tolower);
	int k = _rng.RandomInteger(0, _domain.size() - 1);
	while (name.find(' ') != -1) {
		int f = name.find(' ');
		tmp = name.substr(0, f);
		em << tmp[0];
		name.erase(name.begin(), name.begin() + f + 1);
	}
	em << name << "@" << _domain[k];
	string email = em.str();
	return email;
}

FakeTel::FakeTel() {
	mb = { "090", "093", "089", "070", "079", "077", "076", "078" };
	vt = { "086", "096", "097", "098", "032", "033", "034", "035", "036", "037", "038", "039" };
	vn = { "088", "091", "094", "081", "082", "083", "084", "085" };
	vnmb = { "092", "056", "058" };
}
string FakeTel::rand_tel() {
	stringstream buil;

	int a = _rng.next(1, 4);
	int b = 0;
	if (a == 1) {
		b = _rng.next(1, 8);
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
	buil << "-";
	for (int j = 1; j <= 3; j++) {
		int c = _rng.next(0, 9);
		buil << c;
	}
	buil << "-";
	for (int j = 4; j <= 7; j++) {
		int c = _rng.next(0, 9);
		buil << c;
	}
	return buil.str();
}

FakeBirthday::FakeBirthday() {
	int s_day = 1, s_month = 1, s_year = 1970;
	int e_day = 31, e_month = 12, e_year = 2003;

	struct tm* tm;
	time(&_start);
	tm = localtime(&_start);
	tm->tm_year = s_year - 1900;
	tm->tm_mon = s_month - 1;
	tm->tm_mday = s_day;
	_start = mktime(tm);

	time(&_end);
	tm = localtime(&_end);
	tm->tm_year = e_year - 1900;
	tm->tm_mon = e_month - 1;
	tm->tm_mday = e_day;
	_end = mktime(tm);
}

date FakeBirthday::next() {
	date DOB;
	unsigned long k = _rng.RandomInteger((long)_start, (long)_end);
	time_t tk = (time_t)k;

	struct tm* tm;

	tm = localtime(&tk);
	int day = tm->tm_mday; DOB.setDay(day);
	int month = tm->tm_mon + 1; DOB.setMonth(month);
	int year = tm->tm_year + 1900; DOB.setYear(year);
	
	return DOB;
}

FakeAddress::FakeAddress() {
	fstream f;
	f.open("Address.csv", ios::in);
	char c[256]; string s; int n = 0;
	vector<string> temp;
	f.getline(c, 256, '\n');
	while (!f.eof()) {
		f.getline(c, 256, ',');
		temp.push_back(string(c));
		f.getline(c, 256, ',');
		temp.push_back(string(c));
		f.getline(c, 256, '\n');
		temp.push_back(string(c));
		_Data.push_back(temp);
		temp.resize(0);
	}
	f.close();
}
string FakeAddress::next() {
	int index = _rng.RandomInteger(0, _Data.size() - 1);
	int _numHouse = _rng.RandomInteger(0, 300);
	
	stringstream ss;
	ss << _numHouse << " " << _Data[index][0];

	regex k("\\d+");
	if (regex_match(_Data[index][1], k)) {
		ss << ", " << "Ward " << _Data[index][1];
	}
	else {
		ss << ", " << _Data[index][1] << " Ward";
	}

	if (regex_match(_Data[index][2], k)) {
		ss << ", " << "District " << _Data[index][2];
	}
	else {
		ss << ", " << _Data[index][2] << " District";
	}

	ss << ", Ho Chi Minh City";
	string s = ss.str();
	return s;
}

vectorStudent::vectorStudent(string file) {
	fstream f; int pos = 0;
	f.open(file, ios_base::in);
	while (!f.eof()) {
		readStudent tmp(f, pos);
		_VS.push_back(tmp.getS());
	}
	f.close();
	cout << "Da doc danh sach sinh vien." << endl;
}
RandomStudent::RandomStudent(int i) {
	FakeBirthday FDOB; date dob = FDOB.next(); _S.setDOB(dob);
	FakeId FId; _S.setid(FId.rand_id(i, dob.year()));
	FakeFullnameGenerator FName; Fullname name = FName.next(); _S.setName(name);
	FakeGPA FGpa; _S.setGPA(FGpa.rand_gpa());
	FakeTel FTel; _S.setTel(FTel.rand_tel());
	FakeEmail FEmail; _S.setEmail(FEmail.next(name.toString()));
	FakeAddress FAdd; _S.setAddress(FAdd.next());
}
void vectorStudent::RandomListStudent() {
	int numStudent = _rng.next(5, 10);
	int startID = _rng.next(1, 990);
	for (int i = 0; i < numStudent; i++) {
		RandomStudent S(startID + i);
		_VS.push_back(S.info());
	}
	cout << "Da random them " << numStudent << " sinh vien." << endl;
}
void vectorStudent::infoList() {
	for (int i = 0; i < _VS.size(); i++) {
		cout << _VS[i].toStringFull();
	}
}
void vectorStudent::saveList(string Filename) {
	fstream f;
	f.open(Filename, ios::out);
	for (int i = 0; i < _VS.size(); i++) {
		f << "Student: " << _VS[i].id() << " - " << _VS[i].name().toString() << endl;
		f << "    GPA=" << fixed << setprecision(2) << _VS[i].GPA() << ", " << "Telephone=" << _VS[i].tel() << endl;
		f << "    Email=" << _VS[i].email() << endl;
		f << "    DOB=" << _VS[i].DOB().toString() << endl;
		f << "    Address=" << _VS[i].address();
		if (i != _VS.size() - 1) f << endl;
	}
	f.close();
}
double vectorStudent::averageGPA() {
	double sum = 0;
	for (int i = 0; i < _VS.size(); i++) {
		sum += _VS[i].GPA();
	}
	double ave = sum / _VS.size();
	return ave;
}
void vectorStudent::StudentMoreAveGPA() {
	for (int i = 0; i < _VS.size(); i++) {
		if (_VS[i].GPA() > averageGPA()) 
			cout << _VS[i].toStringShort();
	}
}