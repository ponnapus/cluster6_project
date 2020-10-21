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
		
		//obj.write_file(name,lname,tel,num_room,codebook);
		
		Booking();
		void book();
		//string getnumroom();
		//string getname();
		//string gettel();
		void randomcode();
		void add();
		
};

#endif
