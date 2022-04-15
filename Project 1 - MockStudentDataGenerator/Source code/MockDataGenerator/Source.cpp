#include <string>
#include <string.h>
#include <sstream>
#include <cctype>
#include <algorithm>
#include <regex>
#include "Header.h"
#pragma warning(disable : 4996)

using namespace std;

unsigned long Number::RandomInteger(long left, long right) {
	unsigned long x = rand() & 0xff;
	x |= (rand() & 0xff) << 8;
	x |= (rand() & 0xff) << 16;
	x |= (rand() & 0xff) << 24;
	unsigned long a = x % (right - left + 1) + left;
	return a;
}
readStudent::readStudent(fstream& f, int& pos) {
	f.seekg(pos, ios::beg);
	string s1, s2; char c[256]; double d; int i;

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
	s2 = s1.substr(0, s1.find(' ')); _S.setLname(s2);
	s2 = s1.substr(s1.rfind(' ') + 1, s1.length() - s1.rfind(' ') - 1); _S.setFname(s2);
	s2 = s1.substr(s1.find(' ') + 1, s1.rfind(' ') - s1.find(' ') - 1); _S.setMname(s2);

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
	i = atoi(c);  _S.setBirDay(i); //Set Day
	f.getline(c, 3, '/');
	i = atoi(c); _S.setBirMonth(i); //Set Month
	f.getline(c, 5, '\n');
	i = atoi(c); _S.setBirYear(i); //Set Year

	//Set Address
	f.seekg(12, ios_base::cur);
	f.getline(c, 256, '\n');
	s1 = string(c); _S.setAddress(s1);
	pos = f.tellg();
}
vectorStudent::vectorStudent(string file) {
	fstream f; int pos = 0;
	f.open(file, ios_base::in);
	while (!f.eof()) {
		readStudent tmp(f, pos);
		_VS.push_back(tmp.getS());
	}
	f.close();
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

void FakeBirthday::next(int& day, int& month, int& year) {
	unsigned long k = _rng.RandomInteger((long)_start, (long)_end);
	time_t tk = (time_t)k;

	struct tm* tm;

	tm = localtime(&tk);
	day = tm->tm_mday;
	month = tm->tm_mon + 1;
	year = tm->tm_year + 1900;
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