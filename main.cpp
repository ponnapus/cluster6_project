#include <iostream>
#include <string>
#include "customer.h"
#include "Booking.h"
#include "Room.h"

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	customer obj; 
	Booking obj1;
	Room obj2;
	obj2.readfile();
	string num_people;
	int num;
	
	cout << "============== OO SAD Hotel =============" << endl;
	cout << "+ 1. Customer                           +" << endl;
	cout << "+ 2. Employee                           +" << endl;
	cout << "+ 3. Exit                               +" << endl;
	cout << "=========================================" << endl;
	cout << "Enter : " ;
	cin >> num;
	
	switch(num){

		case 1:{
			
			cout << "Enter Num People : ";
				cin >> num_people;
			obj2.show(num_people);
			obj1.book();
			obj2.ChangeStatus(obj1.num_room);
			obj2.write_file();
			break;
		}	
		case 2:{
			//login
			break;
		}
			
		case 3:{
			break;
		}
		
	}
	return 0;
}
