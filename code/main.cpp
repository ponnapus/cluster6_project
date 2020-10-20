#include <iostream>
#include <string>


using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
		string username,name,lname;
	string num_people;
	string day_in;
	string day_out;
	int num_booking;
	string num_room;
	string tel;
	int num;
	
	cout << "============== OO SAD Hotel =============" << endl;
	cout << "+ 1. Customer                           +" << endl;
	cout << "+ 2. Employee                           +" << endl;
	cout << "=========================================" << endl;
	cout << "Enter : " ;
	cin >> num;
	
	switch(num){

		case 1:
			

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
				break;
		case 2:
			break;

		case 3:
			break;
	}
	return 0;
}
