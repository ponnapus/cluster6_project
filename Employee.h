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
		Login();
		int inputLogin(string username,string password);
};

#endif
