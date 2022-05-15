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

Employee* Employee::EmployeeFactory(string type) {
	if (type == "DailyEmployee") {
		DailyEmployee* dai = new DailyEmployee();
		dai->member = dai;
		return dai;
	}
	else if (type == "Manager") {
		Manager* man = new Manager();
		man->member = man;
		return man;
	}
	else if (type == "HourlyEmployee") {
		HourlyEmployee* hour = new HourlyEmployee();
		hour->member = hour;
		return hour;
	}
	else if (type == "ProductEmployee") {
		ProductEmployee* pro = new ProductEmployee();
		pro->member = pro;
		return pro;
	}
}

Employee* DailyEmployee::instance() {
	if (member == NULL) {
		member = new DailyEmployee;
	}
	return member;
}
/*Employee* DailyEmployee::instance(Fullname fullname, double dailyPayment, int totalDays) {
	if (DailyEmployee::member == NULL) {
		DailyEmployee::member = new DailyEmployee(fullname, dailyPayment, totalDays);
	}
	return member;
}*/
double DailyEmployee::totalPayment() {
	double t = 0;
	t = _dailyPayment * _totalDays;
	return t;
}
string DailyEmployee::toString() {
	stringstream ss;
	ss << "DailyEmployee: " << _fullname.toString() << endl;
	ss << "   DailyPayment=" << _dailyPayment << "$; TotalDays=" << _totalDays << "; TotalPayment=" << totalPayment() << "$" << endl;

	string s = ss.str();
	return s;
}

Employee* Manager::instance() {
	if (member == NULL) {
		member = new Manager();
	}
	return member;
}
/*Employee* Manager::instance(Fullname fullname, double fixedPayment, int totalEmployees, double paymentPerEmployee) {
	if (member == NULL) {
		member = new Manager(fullname, fixedPayment, totalEmployees, paymentPerEmployee);
	}
	return member;
}*/
double Manager::totalPayment() {
	double t = 0;
	t = _fixedPayment + _totalEmployees * _paymentPerEmployee;
	return t;
}
string Manager::toString() {
	stringstream ss;
	ss << "Manager: " << _fullname.toString() << endl;
	ss << "   FixedPayment=" << _fixedPayment << "$; TotalEmployees=" << _totalEmployees << "; PaymentPerEmployee=" << _paymentPerEmployee << "$; TotalPayment=" << totalPayment() << "$" << endl;

	string s = ss.str();
	return s;
}

Employee* HourlyEmployee::instance() {
	if (member == NULL) {
		member = new HourlyEmployee();
	}
	return member;
}

double HourlyEmployee::totalPayment() {
	double t = 0;
	t = _hourlyPayment * _totalHours;
	return t;
}
string HourlyEmployee::toString() {
	stringstream ss;
	ss << "HourlyEmployee: " << _fullname.toString() << endl;
	ss << "   HourlyPayment=" << _hourlyPayment << "$; TotalHours=" << _totalHours << "; TotalPayment=" << totalPayment() << "$" << endl;

	string s = ss.str();
	return s;
}

Employee* ProductEmployee::instance() {
	if (member == NULL) {
		member = new ProductEmployee();
	}
	return member;
}
double ProductEmployee::totalPayment() {
	double t = 0;
	t = _paymentPerProduct * _totalProduct;
	return t;
}
string ProductEmployee::toString() {
	stringstream ss;
	ss << "ProductEmployee: " << _fullname.toString() << endl;
	ss << "   PaymentPerProduct=" << _paymentPerProduct << "$; TotalProducts=" << _totalProduct << "; TotalPayment=" << totalPayment() << "$" << endl;

	string s = ss.str();
	return s;
}

ListEmployee::ListEmployee(string file, int& code) {
	f.open(file, ios::in);
	if (!f.is_open()) {
		cout << "Mo file khong thanh cong, nhan bat ki phim nao de thoat." << endl;
		code = 0;
		return;
	}
	else {
		code = 1;
		cout << "Mo file thanh cong." << endl;
	}
	string line;
	Employee* tmp = NULL;
	while (!f.eof()) {
		getline(f, line, ':');
		if (line == "") break;
		if (line == "DailyEmployee") {
			tmp = Employee::EmployeeFactory("DailyEmployee");
			DailyEmployee* dai = (DailyEmployee*)tmp->getMember();
			f.seekg(1, ios::cur);
			getline(f, line, '\n');
			dai->setFullname(SplitFullname::split(line));

			f.seekg(16, ios::cur);
			getline(f, line, '$');

			dai->setDailyPayment(stod(line));
			f.seekg(12, ios::cur);
			getline(f, line, '\n');
			dai->setTotalDays(stoi(line));
		}
		else if (line == "Manager") {
			tmp = Employee::EmployeeFactory("Manager");
			Manager* man = (Manager*)tmp->getMember();
			f.seekg(1, ios::cur);
			getline(f, line, '\n');
			man->setFullname(SplitFullname::split(line));

			f.seekg(16, ios::cur);
			getline(f, line, '$');
			man->setFixedPayment(stod(line));

			f.seekg(17, ios::cur);
			getline(f, line, ';');
			man->setTotalEmployees(stoi(line));

			f.seekg(20, ios::cur);
			getline(f, line, '$');
			man->setPaymentPerEmployee(stod(line));

			f.seekg(2, ios::cur);
		}
		else if (line == "HourlyEmployee") {
			tmp = Employee::EmployeeFactory("HourlyEmployee");
			HourlyEmployee* hour = (HourlyEmployee*)tmp->getMember();
			f.seekg(1, ios::cur);
			getline(f, line, '\n');
			hour->setFullname(SplitFullname::split(line));

			f.seekg(17, ios::cur);
			getline(f, line, '$');
			hour->setHourlyPayment(stod(line));

			f.seekg(13, ios::cur);
			getline(f, line, '\n');
			hour->setTotalHours(stoi(line));

		}
		else if (line == "ProductEmployee") {
			tmp = Employee::EmployeeFactory("ProductEmployee");
			ProductEmployee* pro = (ProductEmployee*)tmp->getMember();
			f.seekg(1, ios::cur);
			getline(f, line, '\n');
			pro->setFullname(SplitFullname::split(line));

			f.seekg(21, ios::cur);
			getline(f, line, '$');
			pro->setPaymentPerProduct(stod(line));

			f.seekg(16, ios::cur);
			getline(f, line, '\n');
			pro->setTotalProduct(stoi(line));

		}
		_member.push_back(tmp);
	}
	f.close();
}

void ListEmployee::infoList() {
	for (int i = 0; i < _member.size(); i++) {
		cout << _member[i]->toString();
	}
}