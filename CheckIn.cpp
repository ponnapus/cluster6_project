#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
#include<Windows.h>
#include<sstream>
#include "CheckIn.h"
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
		CheckIn::CheckIn()
		{
			numRoom = "";
			obj.readfile();
		}
		string CheckIn::getRoom(){
			return numRoom;
		}//get room
		void CheckIn::setRoom(string room){
			numRoom = room;
		}//set room
		void CheckIn::getCustomerData(){
			name = " ";
			tel = " ";
			dayIn = " ";
			dayOut = " ";
			amount = " ";
			numNight = 0;
		}//get customer data
		/*void CheckIn::setCustomerData(string n,string t,string in,string out,int a,int night){
			name = n;
			tel = t;
			dayIn = in;
			dayOut = out;
			amount = a;
			numNight = night;
		}//set customer data*/
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
			cout << " Book code : " ;//booking code	
			cin >> code;
			for(int i=1;i<=obj.countCustomer;i++)
			{	
				if(code == obj.temp->codebooked)
				{
					cout << " Day check in : ";//DayCheckIn
					cin >> acdayin;
					cout << endl;
					obj.temp->checkin = acdayin;
					/*cout << obj.temp->codebooked << " "
				     	   << obj.temp->name << " "
				     	   << obj.temp->tel << " "
				     	   << obj.temp->numroom << " "
				     	   << obj.temp->dayin << " "
				     	   << obj.temp->dayout << " "
					 	   << obj.temp->checkin << " "
					 	   << obj.temp->checkout << endl;*/
					cout << "==============================" << endl;
					/*BookedInformation();
					cout << "Confirmation? (y/n) : ";
					cin >> choice;
					if(choice == "y" || choice == "Y" || choice == "yes" || choice == "Yes" || choice == "YES")
					{
						CheckInComplete();
						Sleep(2000);
					}
					else if(choice == "n" || choice == "N" || choice == "no" || choice == "No" || choice == "NO")
					{
						goto booked;
					}*/
					/*cout << obj.temp->name << endl;
					cout << obj.temp->tel << endl;
					cout << obj.temp->dayin << endl;
					cout << obj.temp->numroom << endl;*/
					//obj.readfile();			
					cout << "======BOOKING INFORMATION======" << endl;
					cout << " Name : " << obj.temp->name << endl; //Name customer
					cout << " Tel : " << obj.temp->tel << endl; //Tel customer
					cout << " Day check in : " << obj.temp->dayin << endl; //Day check in
					cout << " Room number : " << obj.temp->dayin << endl;
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
/*		void CheckIn::BookedInformation(){
		
		}//Booked information*/
		void CheckIn::CheckInComplete(){
			cout << "========== CHECK IN ==========" << endl;
			cout << "          COMPLETE!!          " << endl;
			cout << " Name : " << name << endl; //Name customer
			cout << " Tel : " << tel << endl; //Tel customer
			cout << " Day check in : " << dayIn << endl; //Day check in
			//cout << " Num of night : " << numNight << endl; //numNight
			//cout << " Amount : " << amount << endl; //Number people
			cout << " Room number : "<< numRoom << endl ; //Room number
			cout << "===============================" << endl;
			cout << "  WELCOME TO CLUSTER 6 HOTEL  " << endl;
		}//check in complete
		void CheckIn::WalkInCheckIn(){
			cout << "===============CHECK IN===============" << endl;
			cout << " Please input your information" << endl;
			cout << " Name : " ; //Name customer
			cin >> name;
			cout << " Tel : " ; //Tel customer
			cin >> tel;
			cout << " Day check in : " ; //Day check in
			cin >> dayIn;
			cout << " Num of night : " ; //numNight
			cin >> numNight;
			cout << " Amount : " ; //Number people
			cin >> amount;
			cout << "=======================================" << endl;
			r.readfile();
			obj.readfile();
			r.show(amount);
			cout << "Enter room : " ;
			cin >> numRoom;//Choose room;
			r.ChangeStatus(numRoom);
			cout << "===============================" << endl;
			/*check customer*/
			nodeCustomer *cus = obj.head_customer;
			for(int i=1;i<=obj.countCustomer;i++)
			{
				if()
				{
					
				}
			}
			/*check room*/
			node_room *temp = r.head_room;
			for(int i=1;i<=r.count_room;i++){
				if(numRoom == temp->num_room){
				//	cout << "-"<<temp->status_room;
					temp->status_room="FULL";
					//cout << "/"<<temp->status_room;
				break;
			}
			//	cout << "o"<<temp->status_room;
			temp=temp->next;
			}
		}//walk in check in
		/*void CheckIn::ShowEmptyRoom(){

		}//show empty room*/
		void CheckIn::ChooseRoom(){
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
