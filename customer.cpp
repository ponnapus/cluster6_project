#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <string>

using namespace std;
class customer
{
	public:
		string username,name,lname;
		string num_people;
		string day_in;
		string day_out;
		int num_booking;
		string num_room;
		string tel;
		customer();
		void Booking();
	protected:
};

#endif
