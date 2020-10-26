#ifndef CHECKOUT_H
#define CHECKOUT_H
#include<iostream>
#include "customer.h"
#include"node_room.h"
#include "Room.h"
//#include "Bill.h"
using namespace std;
class checkout
{
	public:
		Room getRoom;
		customer getCus;
		//Bill b;
		int people;
		string ac_dayout;
		string roomnumber;
		int amount_of_day;
		float vat;
		float total;
		int total_ac_day;
		int predictday;
		checkout();
		string predict_day_tocheckout();
		void optcheckout();
		void Receipt(string room);
		//void checkday();
		int checkday(string dayin,string dayout);
		float calculate(string room);
		void writecheckout(string name);
	protected:
};

#endif
