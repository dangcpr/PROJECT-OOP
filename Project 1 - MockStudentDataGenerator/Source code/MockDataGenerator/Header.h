#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>
#include <sstream>
using namespace std;

class Number {
public:
	unsigned long RandomInteger(long, long);
};
class RandomIntegerGenerator {
public:
	int next();
	int next(int);
	int next(int, int);
};
class Fullname {
private:
	string _firstname;
	string _middlename;
	string _lastname;
public:
	Fullname() {
		_firstname = "";
		_middlename = "";
		_lastname = "";
	}
	Fullname(string first, string middle, string last) {
		_firstname = first;
		_middlename = middle;
		_lastname = last;
	}

	string toString() {
		stringstream builder;

		builder << _lastname << " "
			<< _middlename << " "
			<< _firstname;

		string result = builder.str();
		return result;
	}
	string lname() { return _lastname; }
	string mname() { return _middlename; }
	string fname() { return _firstname; }
	void setLname(string Lname) { _lastname = Lname; }
	void setMname(string Mname) { _middlename = Mname; }
	void setFname(string Fname) { _firstname = Fname; }
};
class date {
private:
	int _day;
	int _month;
	int _year;
public:
	date() {
		_day = 1;
		_month = 1;
		_year = 1970;
	}
	date(int day, int month, int year) {	
		_day = day;
		_month = month;
		_year = year;
	}
	int day() { return _day; }
	int month() { return _month; }
	int year() { return _year; }
	void setDay(int day) { _day = day; }
	void setMonth(int month) { _month = month; }
	void setYear(int year) { _year = year; }
	string toString();
};

class Student {
private:
	string _id;
	Fullname _name;
	double _GPA;
	string _tel;
	string _email;
	date _DOB;
	string _address;
public:
	Student() {
		_id = "";
		_GPA = 0;
		_tel = "";
		_email = "";
		_address = "";
	}
	Student(string id, Fullname name, double GPA, string tel, string email, date DOB, string address) {
		_id = id;
		_name = name;
		_GPA = GPA;
		_tel = tel;
		_email = email;
		_DOB = DOB;
		_address = address;
	}
	string id() { return _id; }
	Fullname name() { return _name; }
	double GPA() { return _GPA; }
	string tel() { return _tel; }
	string email() { return _email; }
	date DOB() { return _DOB; }
	string address() { return _address; }
	void setid(string id) { _id = id; }
	void setName(Fullname name) { _name = name; }
	void setGPA(double GPA) { _GPA = GPA; }
	void setTel(string tel) { _tel = tel; }
	void setEmail(string Email) { _email = Email; }
	void setDOB(date DOB) { _DOB = DOB; }
	void setAddress(string add) { _address = add; }
	string toStringFull();
	string toStringShort();
	~Student() {};
};

class readStudent {
private:
	Student _S;
public:
	readStudent(fstream&, int&);
	Student getS() { return _S; }
	~readStudent() { };
};



class FakeFullnameGenerator {
private:
	vector<string> _CommonlastNames;
	vector<string> _firstNames;
	vector<string> _middleNames;
	vector<string> _lastNames;
	RandomIntegerGenerator _rng;

public:
	FakeFullnameGenerator();
	Fullname next();
};

class FakeGPA {
private:
	RandomIntegerGenerator _rng;
public:
	double rand_gpa();
};

class FakeInterger {
public:
	int rand();
};

class FakeId {
private:
	RandomIntegerGenerator _rng;
public:
	string rand_id(int, int);
};

class FakeEmail {
private:
	vector<string> _domain;
	Number _rng;
public:
	FakeEmail();
	string next(string);
};

class FakeTel {
private:
	vector<string> mb;
	vector<string> vt;
	vector<string> vn;
	vector<string> vnmb;
	RandomIntegerGenerator _rng;

public:
	FakeTel();
	string rand_tel();
};

class FakeBirthday {
private:
	time_t _start;
	time_t _end;
	Number _rng;
public:
	FakeBirthday();
	date next();
};

class FakeAddress {
private:
	vector<vector<string>> _Data;
	Number _rng;
public:
	FakeAddress();
	string next();
};
class RandomStudent {
private:
	Student _S;
	RandomIntegerGenerator _rng;
public:
	RandomStudent(int);
	Student info() { return _S; }
	~RandomStudent() {}
};
class vectorStudent {
private:
	vector<Student> _VS;
	RandomIntegerGenerator _rng;
public:
	vectorStudent(string);
	void RandomListStudent();
	void infoList();
	void saveList(string);
	double averageGPA();
	void StudentMoreAveGPA();
	vector<Student> getVS() { return _VS; }
	~vectorStudent() { };
};