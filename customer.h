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
		
		string name;
		string tel;
		string numroom;
		string codebooked;
		int countCustomer;
		customer();
		void write_file(string name,string lname,string tel,string numroom,string codebooked);
		void readfile();
		void addcutomer(string name,string tel,string numroom,string codebooked);
	
	protected:
		
		
};

#endif

