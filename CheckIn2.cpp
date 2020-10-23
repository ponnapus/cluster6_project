#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
#include<Windows.h>
#include<sstream>
#include "CheckIn2.h"
#include "customer.h"
using namespace std;
/*class nodeCustomer{
	public:
		string Customername;
		string Customertel;
		string CustomerdayIn;
		string CustomerdayOut;
		string Customeramount;
		nodeCustomer *linkCustomer;
};//class node customer
class Customer{
   public:
       nodeCustomer *headCustomer;
	   nodeCustomer *tailCustomer;
	   nodeCustomer *tempCustomer;	
	Customer(){
	   this->headCustomer = NULL;
 	   this->tailCustomer = NULL;
	   this->tempCustomer = NULL;
	}//constructor customer
	void addCustomer(string name,string tel,string dayIn,string dayOut,int amount){
	 	if(headCustomer==NULL){
	    	headCustomer = new nodeCustomer;
	    	headCustomer->Customername = name;
	    	headCustomer->Customertel = tel;
	    	headCustomer->CustomerdayIn = dayIn;
	    	headCustomer->CustomerdayOut = dayOut;
	    	headCustomer->Customeramount = amount;
	    	tailCustomer = headCustomer;
	    	tailCustomer->linkCustomer = NULL;
	 	}else{
	    	tempCustomer = new nodeCustomer;
	    	tempCustomer->Customername = name;
	    	tempCustomer->Customertel = tel;
	    	tempCustomer->CustomerdayIn = dayIn;
	    	tempCustomer->CustomerdayOut = dayOut;
	    	tempCustomer->Customeramount = amount;
	    	tailCustomer->linkCustomer = tempCustomer;
	    	tailCustomer = tempCustomer;
	    	tailCustomer->linkCustomer = NULL;
	 	}
	}//add data customer
};*/
		CheckIn2::CheckIn2()
		{
			numRoom = "";
		}
		string CheckIn2::getRoom(){
			return numRoom;
		}//get room
		void CheckIn2::setRoom(string room){
			numRoom = room;
		}//set room
		void CheckIn2::getCustomerData(){
			name = " ";
			tel = " ";
			dayIn = " ";
			dayOut = " ";
			amount = 0;
		}//get customer data
		void CheckIn2::setCustomerData(string n,string t,string in,string out,int a){
			name = n;
			tel = t;
			dayIn = in;
			dayOut = out;
			amount = a;
		}//set customer data
		void CheckIn2::MenuCheckIn(){
			cout << "========== CHECK IN ==========" << endl;
			cout << endl;
			cout << "  1. Booked " << endl;
			cout << "  2. Walk in " << endl;
			cout << endl;
			cout << "==============================" << endl;
		}//Menu check in
		void CheckIn2::BookedCode(){
			cout << "========== CHECK IN ==========" << endl;
			cout << endl;
			cout << " Book code : " << endl;//booking code
			cout << " Day check in : " << endl;//DayCheckIn
			cout << endl;
			cout << "==============================" << endl;
		}//show booked code
		void CheckIn2::BookedInformation(){
			cout << "======BOOKING INFORMATION======" << endl;
			cout << " Name : " << name << endl; //Name customer
			cout << " Tel : " << tel << endl; //Tel customer
			cout << " Day check in : " << dayIn << endl; //Day check in
			cout << " Day check out : " << dayOut << endl; //Day check out
			cout << " Amount : " << amount << endl; //Number people
			cout << " Room number : " << numRoom << endl;
		}//Booked information
		void CheckIn2::CheckInComplete(){
			cout << "========== CHECK IN ==========" << endl;
			cout << "          COMPLETE!!          " << endl;
			cout << " Name : " << name << endl; //Name customer
			cout << " Tel : " << tel << endl; //Tel customer
			cout << " Day check in : " << dayIn << endl; //Day check in
			cout << " Day check out : " << dayOut << endl; //Day check out
			cout << " Amount : " << amount << endl; //Number people
			cout << " Room number : " << numRoom << endl; //Room number
			cout << "===============================" << endl;
			cout << "  WELCOME TO CLUSTER 6 HOTEL  " << endl;
		}//check in complete
		void CheckIn2::WalkInCheckIn(){
			cout << "===============CHECK IN===============" << endl;
			cout << " Please input your information" << endl;
			cout << " Name : " ; //Name customer
			cin >> name;
			cout << " Tel : " ; //Tel customer
			cin >> tel;
			cout << " Day check in : " ; //Day check in
			cin >> dayIn;
			cout << " Day check out : " ; //Day check out
			cin >> dayOut;
			cout << " Amount : " ; //Number people
			cin >> amount;
			cout << "=======================================" << endl;
		}//walk in check in
		void CheckIn2::ShowEmptyRoom(){
			cout << "========== CHECK IN ==========" << endl;
			cout << " Empty room" << endl;
			cout << endl;// 1st Floor 102 105 106 109
			cout << endl;//2nd 201 207
			cout << "Enter room : " ;
			cin >> numRoom;//Choose room;
			cout << "===============================" << endl;
		}//show empty room
		void CheckIn2::ChooseRoom(){
			cout << " Room number : " ; //Room number
			cin >> numRoom;
		}//choos room
		/*void Room::ChangeStatus(string No_Room){
			node_room *temp = head_room;
	      		for(int i=1;i<=count_room;i++){
					if(No_Room==temp->num_room){
				//	cout << "-"<<temp->status_room;

						temp->status_room="Full";
						//cout << "/"<<temp->status_room;
							break;
					}
					//	cout << "o"<<temp->status_room;
					temp=temp->next;
				}
		}*/
//};//customer

/*

int main(){
	int MenuCheckIn,dayin,dayout;
	char choose;
	string n,b,t,in,out,a,room;
	stringstream ss;
	Show s;
	s.MenuCheckIn();
	cin>>MenuCheckIn;
		if(MenuCheckIn==1){   //Booked
			s.BookedCode();
			s.BookedInformation();
			cout << "NEXT or BACK(n/b) : " ;
			cin >> choose;
				if(choose = 'n'){
					s.CheckInComplete();
				}else if(choose = 'b'){
					s.MenuCheckIn();
				}//if check in complete
		}else if(MenuCheckIn == 2){   //Walk in
			do{
				s.getCustomerData();
				s.WalkInCheckIn();
				ss>>in;
				ss<<dayin;
				ss>>out;
				ss<<dayout;
			}while(dayin>30 && dayout>30);
			s.ShowEmptyRoom();
			s.getRoom();
			s.setRoom(room);
			r.ChangeStatus(room);
			s.CheckInComplete();
		}//if Menu check in
}//main*/
