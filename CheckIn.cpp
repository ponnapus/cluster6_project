#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
#include<Windows.h>
#include<sstream>
#include "CheckIn.h"
#include "customer.h"
using namespace std;

CheckIn::CheckIn(){
	numRoom = "";
	obj.readfile();
}//constuctor
		
string CheckIn::getRoom(){
	return numRoom;
}//get room


void CheckIn::setRoom(string room){
	numRoom = room;
}//set room


void CheckIn::getCustomerData(){
	name = "";
	tel = "";
	dayIn = "";
	dayOut = "";
	amount = "";
	numNight = "";
}//get customer data

void CheckIn::MenuCheckIn(){
	cout << "========== CHECK IN ==========" << endl;
	cout << endl;
	cout << "  1. Booked " << endl;
	cout << "  2. Walk in " << endl;
	cout << endl;
	cout << "==============================" << endl;
}//Menu check in



	void CheckIn::BookedCode( ){
			string choice;
			booked:
			obj.temp = obj.head_customer;
			cout << "========== CHECK IN ==========" << endl;
			cout << endl;
			cout << " Book code : " << endl;//booking code
			cout << " Day check in : " << endl;//DayCheckIn
			cout << endl;
			cout << "==============================" << endl;
			cout << " Book code : " ;//booking code	
			cin >> code;
			for(int i=1;i<=obj.countCustomer;i++){	
				if(code == obj.temp->codebooked)
				{
					cout << " Day check in : ";//DayCheckIn
					cin >> acdayin;
					cout << endl;
					obj.temp->checkin = acdayin;
							
					cout << "======BOOKING INFORMATION======" << endl;
					cout << " Name : " << obj.temp->name << endl; //Name customer
					cout << " Tel : " << obj.temp->tel << endl; //Tel customer
					cout << " Day check in : " << obj.temp->dayin << endl; //Day check in
					cout << " Room number : " << obj.temp->numroom << endl;
					obj.write_file();
					break;
				}
				else if(i == obj.countCustomer)
				{
					cout << "Not found this code" << endl;
				}
				obj.temp = obj.temp->next;
			}
		}//show booked code
				
			
		void CheckIn::CheckInComplete(){	
			cout << "========== CHECK IN ==========" << endl;
			cout << "          COMPLETE!!          " << endl;
			cout << " Name : " << name << endl; //Name customer
			cout << " Tel : " << tel << endl; //Tel customer
			cout << " Day check in : " << dayIn << endl; //Day check in
			//cout << " Num of night : " << numNight << endl; //numNight
			//cout << " Amount : " << amount << endl; //Number people
			cout << " Room number : "<< numRoom << endl ; //Room number
			cout << "=======================================" << endl;
			cout << "   	WELCOME TO OO SAD HOTEL   " << endl;

		}//check in complete
	
	void CheckIn::check(string num){	
		node_room *temp = r.head_room;
			for(int i=1;i<=r.count_room;i++){
				if(num == temp->num_room){
				//	cout << "-"<<temp->status_room;
					temp->status_room="FULL";
					//cout << "/"<<temp->status_room;
					r.write_file();
				//	write_file();
					
					break;
				}
			//	cout << "o"<<temp->status_room;
			temp=temp->link;
			}
	}
		void CheckIn::WalkInCheckIn(){
			cout << "===============CHECK IN===============" << endl;
			cout << " Please input your information" << endl;
			cout << " Name : " ; //Name customer
			cin >> name;
			cout << " Tel : " ; //Tel customer
			cin >> tel;
			cout << " Day check in(day/mont/year) : " ; //Day check in
			cin >> dayIn;
			cout << " Day check out(day/mont/year) : " ; //Day check out
			cin >> numNight;
			cout << " Amount : " ; //Number people
			cin >> amount;
			cout << "========================================" << endl;
			r.readfile();
			obj.readfile();
			r.show(amount);
			cout << "Enter room : " ;
			cin >> numRoom;//Choose room;
			r.ChangeStatus(numRoom);
			cout << "=======================================" << endl;
		
			/*check customer*/
			obj.addcutomer(name,tel,numRoom,"-","-","-",dayIn,numNight);						
			/*check room*/
			
			node_room *temp = r.head_room;
			
			check(numRoom);
		/*	for(int i=1;i<=r.count_room;i++){
				if(numRoom == temp->num_room){
				//	cout << "-"<<temp->status_room;
					temp->status_room="FULL";
					//cout << "/"<<temp->status_room;
					r.write_file();
				//	write_file();
					
					break;
				}
			//	cout << "o"<<temp->status_room;
			temp=temp->link;
			}*/
			
			obj.write_file();
		}//walk in check in
		
		
		/*void CheckIn::ShowEmptyRoom(){

		}//show empty room*/
		void CheckIn::ChooseRoom(){
			cout << " Room number : " ; //Room number
			cin >> numRoom;
		}//choos room
		

