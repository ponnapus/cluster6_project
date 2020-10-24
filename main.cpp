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
#include <unistd.h>



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
	string c;//input chioce  in customer
	string username;
	string password;

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
			mm:	
				system("cls");
				cout << "====================== WELCOME TO OO SAD HOTEL =====================" << endl;
				cout << "1.Check Room Empty" << endl;
				cout << "2.Review Hotel" << endl;
				cout << "3.Return Menu Home" << endl;
				cout <<  "====================================================================" << endl;
				do{
				cout << "Enter : " ;
					cin >> c;
				}while(c != "1" && c != "2" && c!="3");
				if(c == "1"){
					do{	
						cout << "Please Enter Num People (1,2,3,4,5,6,7,10): ";
							cin >> num_people;
					}while(num_people != "1" && num_people != "2" && num_people != "3" 
						&& num_people != "4" &&num_people != "5" && num_people != "6"&&num_people != "7" && num_people != "10");
					obj2.show(num_people);
					obj1.book();
					obj2.ChangeStatus(obj1.num_room);
					//	obj2.show(num_people);
					obj2.write_file();
					cout << "++++++++++++++ Thank You For Booking ++++++++++++" << endl;
					cout << "   ==== Please Remember Code For Check-In ====" << endl;
					obj1.randomcode();
						sleep(3);
					goto mm;
					break;
				}else if(c == "2"){
					
					//review
					goto mm;
					break;
				}else{
					goto menumain;
					break;
				}
		}	
		case 2:{
			
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
	menuemployee:
			cout << "============== Employee ==============" << endl
				 << "1.Check-in" << endl
				 << "2.Check-out" << endl
				 << "3.Exit" << endl
				 << "======================================" << endl
				 << "Input your choice : " ;
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
						cout << "check-in complete" << endl;
					//	s.CheckInComplete();
					}else if(choose == "b"){
						goto menucheckin;
					}//if check in complete
					
				}else //check in book 
				
				if(MenuCheckIn == 2){   //Walk in
				
					s.getCustomerData();
					s.WalkInCheckIn();
					s.CheckInComplete();
				//	obj.write_file();
				}//check in walkin 
			//login
				sleep(3);
				system("cls");
				goto menuemployee;
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
