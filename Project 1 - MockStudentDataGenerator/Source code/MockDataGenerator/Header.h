#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>
using namespace std;

class Number {
public:
	unsigned long RandomInteger(long, long);
	double RandomDouble(double);
	int StepInteger(int, int);
};

class Student {
private:
	string _id;
	string _lastname;
	string _midname;
	string _firstname;
	double _GPA;
	string _tel;
	string _email;
	int _birDay;
	int _birMonth;
	int _birYear;
	string _address;
public:
	string id() { return _id; }
	string lname() { return _lastname; }
	string mname() { return _midname; }
	string fname() { return _firstname; }
	double GPA() { return _GPA; }
	string tel() { return _tel; }
	string email() { return _email; }
	int birDay() { return _birDay; }
	int birMonth() { return _birMonth; }
	int birYear() { return _birYear; }
	string address() { return _address; }
	void setid(string id) { _id = id; }
	void setLname(string Lname) { _lastname = Lname; }
	void setMname(string Mname) { _midname = Mname; }
	void setFname(string Fname) { _firstname = Fname; }
	void setGPA(double GPA) { _GPA = GPA; }
	void setTel(string tel) { _tel = tel; }
	void setEmail(string Email) { _email = Email; }
	void setBirDay(int day) { _birDay = day; }
	void setBirMonth(int month) { _birMonth = month; }
	void setBirYear(int year) { _birYear = year; }
	void setAddress(string add) { _address = add; }
};

class readStudent {
private:
	Student _S;
public:
	readStudent(fstream&, int&);
	Student getS() { return _S; }
};

class vectorStudent {
private:
	vector<Student> _VS;
public:
	vectorStudent(string);
	vector<Student> getVS() { return _VS; }
};

class FakeEmail {
private:
	vector<string> _domain;
	Number _rng;
public:
	FakeEmail();
	string next(string);
};

class FakeBirthday {
private:
	time_t _start;
	time_t _end;
	Number _rng;
public:
	FakeBirthday();
	void next(int&, int&, int&);
};

class FakeAddress {
private:
	vector<vector<string>> _Data;
	Number _rng;
public:
	FakeAddress();
	string next();
};