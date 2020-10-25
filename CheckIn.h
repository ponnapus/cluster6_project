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
		string numNight;
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
		void check(string num);
		void c(string code);
		//void BookedInformation();
		void CheckInComplete();
		void WalkInCheckIn();
		//void ShowEmptyRoom();
		void ChooseRoom();
		//void Room::ChangeStatus(string No_Room);
	
};//class show
#endif
