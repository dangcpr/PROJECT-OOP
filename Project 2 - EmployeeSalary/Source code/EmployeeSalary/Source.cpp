#include "Header.h"
#include <sstream>
string Fullname::toString() {
	stringstream ss;
	ss << _firstName;
	if (_midName == "") ss << ' ' << _lastName;
	else ss << ' ' << _midName << ' ' << _lastName;

	string s = ss.str();
	return s;
}

double DailyEmployee::totalPayment() {
	double t;
	t = _dailyPayment * _totalDays;
	return t;
}
string DailyEmployee::toString() {
	stringstream ss;
	ss << "DailyEmployee: " << _fullname.toString() << endl;
	ss << "    DailyPayment=" << _dailyPayment << "; TotalDays=" << _totalDays << "; TotalPayment=" << totalPayment() << endl;

	string s = ss.str();
	return s;
}