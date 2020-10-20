#ifndef BOOKING_H
#define BOOKING_H
#include <string>

using namespace std;
class Booking
{
	public:
		string username,name,lname;
		string num_people;
		string day_in;
		string day_out;
		int num_booking;
		string num_room;
		string tel;
		Booking();
		void book();
	protected:
		
};

#endif
