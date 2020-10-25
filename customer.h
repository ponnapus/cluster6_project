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
		string dayin;
		string dayout;
		string c_out;
		string c_in;
		int countCustomer;
		customer();
		void write_file(string n,string l,string t,string numr,string codebooked,string dayin,string dayout,string checkin,string checkout);
		void readfilec();
		void addcustomer(string name,string tel,string numroom,string codebooked,string dayin,string dayout,string c_in,string c_out);
	
	protected:
		
		
};

#endif

