#include <iostream>
#include <sstream>
#include <string>
#include "customer.h"
#include "Booking.h"
#include "Room.h"
#include "Employee.h"
#include<fstream>
#include<iomanip>
#include<Windows.h>
#include "CheckIn.h"


using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	customer obj; 
	Booking obj1;
	Room obj2;
	Employee login;
	int MenuCheckIn,dayin,dayout;
	string choose;
	string n,b,t,in,out,a,room;
	stringstream ss;
	CheckIn s;
	obj2.readfile();
	string num_people,choice;
	int result=0;
	string username;
	string password;
	do{
		cout<<"*******************************"<<endl;
		cout<<"************ LOGIN ************"<<endl;
		cout<<"  Enter username : ";
		cin>>username;
		cout<<"  Enter password : ";
		cin>>password;
		cout<<"*******************************"<<endl;
		cout<<"*******************************"<<endl;
		system("cls");
		result = login.inputLogin(username,password);
		if(result==2){
			cout << "           -FAIL-           " << endl;
			Sleep(2000);
			system("cls");
		}
	}while(result != 1);
//	cout << "           -SUCCESS-           " << endl;
//	Sleep(5000);
//	system("cls");
	int num;
	do{
		menumain:
		cout << "============== OO SAD Hotel =============" << endl;
		cout << "+ 1. Customer                           +" << endl;
		cout << "+ 2. Employee                           +" << endl;
		cout << "+ 3. Exit                               +" << endl;
		cout << "=========================================" << endl;
		cout << "Enter : " ;
		cin >> choice;
	}while(choice!="1"&&choice!="2"&&choice!="3");
	//stringstream ss;
	ss<<choice;
	ss>>num;
	/*if(num < 1 || num > 3)
	{
		system("cls");
		goto menumain;
	}*/
	ss.clear();
	switch(num){

		case 1:{
			
			cout << "Enter Num People : ";
				cin >> num_people;
			obj2.show(num_people);
			obj1.book();
			obj2.ChangeStatus(obj1.num_room);
		//	obj2.show(num_people);
			obj2.write_file();
			obj1.randomcode();
			//cout << "hh";
		//	obj.write_file();
			break;
		}	
		case 2:{
			menuemployee:
			cout << "============== Employee ==============" << endl
				 << "1.Check-in" << endl
				 << "2.Check-out" << endl
				 << "3.Exit" << endl
				 << "======================================" << endl
				 << "Input your choice : " << endl;
			cin >> choice;
			if(choice == "1")
			{
				menucheckin:
				s.MenuCheckIn();
				cin>>MenuCheckIn;
				if(MenuCheckIn==1){  //Booked
					s.BookedCode();
					//s.BookedInformation();
					cout << "NEXT or BACK(n/b) : " ;
					cin >> choose;
					if(choose == "n"){
						s.CheckInComplete();
					}else if(choose == "b"){
						goto menucheckin;
					}//if check in complete
				}else if(MenuCheckIn == 2){   //Walk in
				//do{
					s.getCustomerData();
					s.WalkInCheckIn();
					/*ss<<in;
					ss>>dayin;
					ss.clear();
					ss<<out;
					ss>>dayout;
					ss.clear();*/
					//}while(dayin>30 && dayout>30);
				//s.ShowEmptyRoom();
				//s.getRoom();
				//s.setRoom(room);
				//obj2.ChangeStatus(room);
				s.CheckInComplete();
				}//if Menu check in
			//login
				break;
			}
			else if(choice == "2")
			{
				
			}
			else if(choice == "3")
			{
				goto exit;
			}
			else
			{
				system("cls");
				cout << "Error, wrong choice" << endl;
				goto menuemployee;
			}
		case 3:{
			
			break;
		}
		}
	}
	exit:
	return 0;
}
