#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
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

class SplitFullname : public Fullname {
public:
	static Fullname split(string name) {
		string s1 = string(name);
		string s2 = s1.substr(0, s1.find(' ')); s1.substr(0, s1.find(' '));
		string s3 = s1.substr(s1.rfind(' ') + 1, s1.length() - s1.rfind(' ') - 1);

		s1.erase(0, s1.find(' ') + 1); s1.erase(s1.rfind(' ') + 1, s1.length() - s1.rfind(' '));

		return Fullname(s2, s1, s3);
	}
};


class Employee {
protected:
	Fullname _fullname;
public:
	virtual string toString() = 0;
	virtual double totalPayment() = 0;
	virtual string className() = 0;

	//virtual Employee* instance() = 0;
	virtual Employee* getMember() = 0;
	static Employee* EmployeeFactory(string type);
	void setFullname(Fullname fullname) { _fullname = fullname; }
};
class DailyEmployee : public Employee {
private:
	double _dailyPayment;
	int _totalDays;
public:
	static DailyEmployee* member;
	Employee* getMember() {
		return member;
	}
	DailyEmployee() : Employee()  {
		_dailyPayment = 0;
		_totalDays = 0;
	}
	DailyEmployee(Fullname fullname, double dailyPayment, int totalDays) : Employee() {
		_fullname = fullname;
		_dailyPayment = dailyPayment;
		_totalDays = totalDays;
	}
	static Employee* instance();
	//static Employee* instance(Fullname, double, int);

	void setDailyPayment(double dailyPayment) { _dailyPayment = dailyPayment; }
	void setTotalDays(int totalDays) { _totalDays = totalDays; }
	double totalPayment();
	string toString();
	string className() { return "DailyEmployee"; }
	~DailyEmployee() {
		cout << "Delete DailyEmployee!" << endl;
	}
};
class Manager : public Employee {
private:
	double _fixedPayment;
	int _totalEmployees;
	double _paymentPerEmployee;
public:
	static Manager* member;
	Employee* getMember() {
		return member;
	}
	Manager() : Employee() {
		_fixedPayment = 0;
		_totalEmployees = 0;
		_paymentPerEmployee = 0;
	}
	Manager(Fullname fullname, double fixedPayment, int totalEmployees, double paymentPerEmployee) : Employee() {
		_fullname = fullname;
		_fixedPayment = fixedPayment;
		_totalEmployees = totalEmployees;
		_paymentPerEmployee = paymentPerEmployee;
	}
	static Employee* instance();
	//static Employee* instance(Fullname, double, int, double);
	void setFixedPayment(double fixedPayment) { _fixedPayment = fixedPayment; }
	void setTotalEmployees(int totalEmployees) { _totalEmployees = totalEmployees; }
	void setPaymentPerEmployee(double paymentPerEmployee) { _paymentPerEmployee = paymentPerEmployee; }
	double totalPayment();
	string toString();
	string className() { return "Manager"; }
	~Manager() {
		cout << "Delete Manager!" << endl;
	}
};
class ListEmployee{
private:
	fstream f;
	vector<Employee*> _member;
public:
	ListEmployee(string, int&);
	vector<Employee*> getList() { return _member; }
	void infoList();
	~ListEmployee() {
		for (int i = 0; i < _member.size(); i++) {
			delete _member[i];
		}
	}
};