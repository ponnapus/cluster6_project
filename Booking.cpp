#include "Booking.h"
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;
Booking::Booking()
{
		username = "";
		name = "";
		lname = "";
		num_people = "";
		day_in = "";
		day_out = "";
		num_booking = 0;
		num_room = "";
		tel = "";
}

void Booking::book(){
			//cout << "Enter Num People : ";
			//cin >> num_people;
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
				
				
			}else if(num_booking == 2){
				cout<<"Loading............"<<endl;
			}	
}
/*
string Booking::getnumroom(){
	return num_room;
}
string Booking::getname(){
	return name+" "+lname;
}
string Booking::gettel(){
	return tel;
}
*/

/*void Booking::add(){
	string n;
	//n = name+" "+lname;
	obj.addcutomer(name,tel,num_room,codebook);
}*/

void Booking::randomcode(){
	int num[6];
	srand (time(NULL));
	for(int i = 0; i < 6 ; i++){
	num[i] = rand() % 52;
	}
	string code="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	
	for(int i=0;i<6;i++){
		codebook=codebook+code[num[i]];
	}
	cout<<"Code: "<<codebook;	
	obj.write_file(name,lname,tel,num_room,codebook);

//return codebook;	
}

		
