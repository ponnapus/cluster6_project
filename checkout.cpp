#include<iostream>
#include "checkout.h"
using namespace std;
checkout::checkout()
{
	roomnumber = "";
	ac_dayout = "";
	amount_of_day = 0;
	vat = 0.07;
	total = 0.00;
	price = 0.00;
	predictday = 0;
}
int checkout::checkday(string dayin,string dayout){
	int dayinmonth, dayinmonth2,total;
	string date1, date2,dateeee1,dateeee2;
	date1 = dayin;
	date2 = dayout;
	dateeee1=date1.substr(3,2);
	dateeee2=date2.substr(3,2);
	cout<<dateeee1<<" "<<dateeee2<<endl;
	 if(dateeee1==dateeee2){
	 	int temp;
	 	stringstream ss;
		ss<<date2.substr(0,2);
		ss>>dayinmonth2;
		ss.clear();
		ss<<date1.substr(0,2);
		ss>>dayinmonth;
		dayinmonth--;
		ss.clear();
	total=dayinmonth2-dayinmonth;
	cout<<"Total day :"<<total<<endl;
	
	 }
	else{
	 		if(dateeee1=="01"||dateeee1=="03" ||dateeee1=="05"||dateeee1== "07"||dateeee1== "08"||dateeee1== "10"||dateeee1== "12"){
				int temp;
				stringstream ss;
				ss<<date1.substr(0,2);
				ss>>temp;
				ss.clear();
				temp--;
				dayinmonth=31-temp;
				cout<<dayinmonth<<endl;
			}
			else if(dateeee1=="02"){
				int temp;
				stringstream ss;
				ss<<date1.substr(0,2);
				ss>>temp;
				ss.clear();
				temp--;
				dayinmonth=28-temp;
				cout<<dayinmonth<<endl;				
			}
			else{
				int temp;
				stringstream ss;
				ss<<date1.substr(0,2);
				ss>>temp;
				ss.clear();
				temp--;
				dayinmonth=30-temp;
				cout<<dayinmonth<<endl;
			}
		stringstream ss;
		ss<<date2.substr(0,2);
		ss>>dayinmonth2;
		ss.clear();
	total=dayinmonth2+dayinmonth;
	cout<<"Total day :"<<total<<endl;
	}
	return total;
}


void checkout::optcheckout()
{
	//string roomnumber;
	string conf;
	cout << "Input Room number : ";
	cin >> roomnumber;
	cout << "Input actual day check-out : ";
	cin >> ac_dayout;
	
	getCus.readfile();
	nodeCustomer *find = getCus.head_customer;
	for(int i=1;i<=getCus.countCustomer;i++)
	{
		if(roomnumber == find->numroom)
		{
			info:
			find->checkout=ac_dayout;
			predictday=checkday(find.dayin,find.dayout);
			total_ac_day=checkday(find.checkin,find.checkout);
			cout << "=================== Customer information ===================" << endl
				 << "Name : " << find->name << endl
				 << "Tel : " << find->tel << endl
				 << "Room number : " << find->numroom << endl
				 << "Day check-in : " << find->dayin << endl
				 << "Day check-out : " << find->dayout << endl
				 << "Actual day check-in : " << find->checkin << endl
				 << "Actual day check-out : " << find->checkout << endl
				 << "============================================================" << endl
				 << "Confirmation? (y/n): ";
			cin >> conf;
			if(conf == "y" || conf == "Y" || conf == "yes" || conf == "Yes" || conf == "YES")
			{
				Receipt
			//	receipt:
				//b.Receipt();
			//	cout << "Confirmation? (y/n)" << endl;
			//	if(conf == "y" || conf == "Y" || conf == "yes" || conf == "Yes" || conf == "YES")
			//	{
			//	 		
			//	}
			//	else if(conf == "n" || conf == "N" || conf == "no" || conf == "No" || conf == "NO")
			//	{
			//		goto receipt;
			//	}
			}
			else if(conf == "n" || conf == "N" || conf == "no" || conf == "No" || conf == "NO")
			{
				goto info;
			}
			break;
		}
		else if(i == getCus.countCustomer)
		{
			cout << "Not found" << endl;
		}
		find = find->next;
	}
	getRoom.readfile();
}
void checkout::Receipt(){	
	cout << "=================== Receipt ===================" << endl
		 << "Room number : " << getRoom.No_Room << endl
		 << "Type room : " << getRoom.type << "	" << getRoom.price <<endl
		 << "Amount of days : ";
		 << "Vat include 7 %" << endl
		 << "Total : ";
		 << "===============================================" << endl;
}
