#ifndef NODECUSTOMER_H
#define NODECUSTOMER_H
#include <iostream>
#include <string>
using namespace std;
class nodeCustomer
{
	public:
		string name;
		string tel;
		string numroom;
		string codebooked;
		nodeCustomer *next;
		nodeCustomer();
	protected:
};

#endif
