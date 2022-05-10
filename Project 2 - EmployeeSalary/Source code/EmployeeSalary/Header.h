#pragma once
#include <iostream>
#include <string>
using namespace std;

class Fullname {
private:
	string _firstName;
	string _midName;
	string _lastName;
public:
	Fullname() {
		_firstName = "";
		_midName = "";
		_lastName = "";
	}
	Fullname(string fname, string lname) {
		_firstName = fname;
		_midName = "";
		_lastName = lname;
	}
	Fullname(string fname, string mname, string lname) {
		_firstName = fname;
		_midName = mname;
		_lastName = lname;
	}
	string fname() { return _firstName; }
	string mname() { return _midName; }
	string lname() { return _lastName; }
	void setFname(string fname) { _firstName = fname; }
	void setMname(string mname) { _midName = mname; }
	void setLname(string lname) { _lastName = lname; }
	string toString();
	~Fullname() {};
};

class ReadEmployee {

};

class Employee {
protected:
	Fullname _fullname;
public:
	virtual string toString() = 0;
	virtual double totalPayment() = 0;
};
class DailyEmployee : public Employee {
private:
	double _dailyPayment;
	int _totalDays;
public:
	DailyEmployee() : Employee() {
		_dailyPayment = 0;
		_totalDays = 0;
	}
	DailyEmployee(Fullname fullname, double dailyPayment, int totalDays) : Employee() {
		_fullname = fullname;
		_dailyPayment = dailyPayment;
		_totalDays = totalDays;
	}
	double totalPayment();
	string toString();
	string className() { return "DailyEmployee"; }
};