#include <string>
#include <string.h>
#include "Header.h"
using namespace std;
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
}