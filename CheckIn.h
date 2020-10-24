#ifndef CHECKIN2_H
#define CHECKIN2_H
#include"Room.h"
#include "node_room.h"
#include "Booking.h"
//#include "nodeCustomer.h"
#include "customer.h"
#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
#include<Windows.h>
#include<sstream>

using namespace std;
/*class nodeCustomer{
	public:
		string Customername;
		string Customertel;
		string CustomerdayIn;
		string CustomerdayOut;
		string Customeramount;
		nodeCustomer *linkCustomer;

};//class node customer*/
/*class Customer{
   public:
       nodeCustomer *headCustomer;
	   nodeCustomer *tailCustomer;
	   nodeCustomer *tempCustomer;	
	
	
		Customer();
		void addCustomer(string name,string tel,string dayIn,string dayOut,int amount);
};//class customer*/

class CheckIn{
	protected:
		customer obj;
		Room r;
		string name;
		string tel;
		string dayIn;
		string dayOut;
		string acdayin;
		string amount;
		int numNight;
		string numRoom;
		string code;
	public:
		CheckIn();
		string getRoom();
		void setRoom(string room);
		void getCustomerData();
		void setCustomerData(string n,string t,string in,string out,int a,int night);
		void MenuCheckIn();
		void BookedCode();
		//void BookedInformation();
		void CheckInComplete();
		void WalkInCheckIn();
		//00void ShowEmptyRoom();
		void ChooseRoom();
		//void Room::ChangeStatus(string No_Room);
	
};//class show
#endif
