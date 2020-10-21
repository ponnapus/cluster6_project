#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <string>
#include "customer.h"
#include "nodeCustomer.h"

using namespace std;
class customer
{
	public:
		nodeCustomer *head_customer;
		nodeCustomer *tail_customer;
		
	//	Booking obj;
		string name;
		string tel;
		string numroom;
		string codebooked;
		int countCustomer;
		customer();
		void write_file(string n,string l,string t,string numr,string codebooked);
		void readfile();
		void addcutomer(string name,string tel,string numroom,string codebooked);
	
	protected:
		
		
};

#endif

