#include "customer.h"
#include <iostream>

using namespace std;
customer::customer()
{
}

void customer::Booking(){
			cout << "Enter Num People : ";
			cin >> num_people;
			cout << "Enter day in : ";
			cin >> day_in;
			cout << "Enter day out : ";
			cin >> day_out;
			//	data();
			cout << "Booking"<< endl;
			cout << "1. Booking" << endl;
			cout << "2. return home" << endl;
			cout << "=================" << endl;
			cout << "Enter : ";
				cin >> num_booking;
			if(num_booking == 1){
			
				cout << "+++++++++++++++++++ BOOKING ++++++++++++++++++++" << endl;
				cout << "Enter number room : ";
					cin >> num_room;
				cout << "Enter Name and lastname ";
					cin >> name >> lname;
				cout << "num tel" ;
					cin >> tel;
				cout << "================================================" << endl;
			}else{
				
			}	

}
