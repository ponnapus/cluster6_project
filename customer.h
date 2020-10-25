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
		nodeCustomer *temp;
		
	//	Booking obj;
		string name;
		string tel;
		string numroom;
		string codebooked;
		string dayin;
		string dayout;
		string check_in;
		string check_out;
		int countCustomer;
		customer();
		void write_file();
		void readfile();
		void show();
		void addcutomer(string name,string tel,string numroom,string codebooked,string dayin,string dayout,string checkout,string checkin);
	
	protected:
		
		
};

#endif

