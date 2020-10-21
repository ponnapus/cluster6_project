#ifndef BOOKING_H
#define BOOKING_H
#include "customer.h"
#include <string>

using namespace std;
class Booking
{
	public:
		customer obj;
		string username,name,lname;
		string num_people;
		string day_in;
		string day_out;
		int num_booking;
		string num_room;
		string codebook;
		string tel;
		
		
		Booking();
		void book();
		//string getnumroom();
		//string getname();
		//string gettel();
		string randomcode();
		void add();
		
};

#endif
