#ifndef CHECKOUT_H
#define CHECKOUT_H
#include<iostream>
#include "customer.h"
#include "Room.h"
//#include "Bill.h"
using namespace std;
class checkout
{
	public:
		Room getRoom;
		customer getCus;
		//Bill b;
		string ac_dayout;
		string roomnumber;
		int amount_of_day;
		float vat;
		float total;
		float price;
		int total_ac_day;
		int predictday;
		checkout();
		string predict_day_tocheckout();
		void optcheckout();
		void Receipt();
		//void checkday();
		int checkday(string dayin,string dayout);
		
	protected:
};

#endif
