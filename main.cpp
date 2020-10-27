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
#include"checkout.h"
#include "Review.h"
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	menumain:
	//checkout check_out;
	customer obj; 
	Booking obj1;
	Review review;
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
//	cout << "           -SUCCESS-           " << endl;
//	Sleep(5000);
//	system("cls");
	int num;
	do{
		system("cls");
		cout << endl << "============== OO SAD Hotel =============" << endl;
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
	ss.clear();
	switch(num){
		case 1:{
			menucustomer:
			system("cls");
			cout << endl << "============== Customer =============" << endl
						 << "1.Searching Room and Booking" << endl
						 << "2.Review" << endl
						 << "3.Back" << endl
				 		 << "=====================================" << endl
				 		 << "Input your choice : ";
				 	cin >> choice;
			if(choice == "1")
			{
				cout << "============== Search room =============" << endl;
				cout << "Enter Num People : ";
				cin >> num_people;
				system("cls");
				obj2.show(num_people);
				cout << "==== Booking ===="<< endl;
				cout << "1. Booking" << endl;
				cout << "2. return home" << endl;
				cout << "=================" << endl;
				cout << "Enter : ";
				cin >> choice;
					if(choice=="1"){
						obj1.book();
						obj2.ChangeStatus(obj1.num_room,"Booked");
						//	obj2.show(num_people);
						obj2.write_file();
						obj1.randomcode();
						cout << "Booked thank you !" << endl;
						cout << "Input anykey to continue :";
						cin >> choice;
						goto menucustomer;
					}
					else if(choice=="2"){
						goto menumain;
					}
			//cout << "hh";
		//	obj.write_file();
				break;
			}
			else if(choice == "2")
			{
				review.reviewhotel();
				goto menumain;
			}
			else if(choice == "3")
			{
				goto menumain;
			}
			else
			{
				cout << "Error, wrong choice" << endl;
				goto menucustomer;
			}
		}	
		case 2:{
			do{
			cout<<endl<<"*******************************"<<endl;
			cout<<"************ LOGIN ************"<<endl;
			cout<<"  Enter username : ";
			cin>>username;
			cout<<"  Enter password : ";
			cin>>password;
			cout<<"*******************************"<<endl;
			cout<<"*******************************"<<endl;
			system("cls");
			result = login.Login(username,password);
			if(result==2){
				cout << "           -FAIL-           " << endl;
				Sleep(2000);
				system("cls");
			}
	}while(result != 1);
			menuemployee:
			cout << endl << "============== Employee ==============" << endl
						 << "1.Check-in" << endl
						 << "2.Check-out" << endl
						 << "3.Logout" << endl
						 << "4.Exit" << endl
						 << "======================================" << endl
						 << "Input your choice : ";
			cin >> choice;
			if(choice == "1")
			{
				menucheckin:
				s.MenuCheckIn();
				cout << "Input your choice : ";
				cin>>MenuCheckIn;
				if(MenuCheckIn==1){  //Booked
					s.BookedCode();
					//s.BookedInformation();
					goto menucheckin;
				}else if(MenuCheckIn == 2){   //Walk in
				//do{
					s.getCustomerData();
					s.WalkInCheckIn();
					goto menuemployee;
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
			//	s.CheckInComplete();
				}
				else if(MenuCheckIn == 3){
					goto menuemployee;
				}
				else
				{
				system("cls");
				cout << "Error, wrong choice" << endl;
				goto menucheckin;
				}
			}
			else if(choice == "2")
			{
				checkout check_out;
				//obj.readfile();
				//obj2.readfile();
				check_out.optcheckout();	
				goto menuemployee;
			}
			else if(choice == "3")
			{
				goto menumain;
			}
			else if(choice == "4")
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
