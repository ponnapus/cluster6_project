#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <iostream>
#include<string>
#include<fstream>
#include <iomanip>

using namespace std;

class Employee
{
	protected:
		string username;
		string password;
	public:
		Employee();
		void Login();
		int Login(string username,string password);
};

#endif
