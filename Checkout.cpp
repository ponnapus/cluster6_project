#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include "checkout.h"
#include"nodeCustomer.h"
#include"node_room.h"
using namespace std;
checkout::checkout()
{
	roomnumber = "";
	ac_dayout = "";
	amount_of_day = 0;
	vat = 0.07;
	total = 0.00;
	predictday = 0;
	getRoom.readfile();
	getCus.readfile();
}
int checkout::checkday(string dayin,string dayout){
	int dayinmonth, dayinmonth2,total;
	string date1, date2,dateeee1,dateeee2;
	date1 = dayin;
	date2 = dayout;
	dateeee1=date1.substr(3,2);
	dateeee2=date2.substr(3,2);
	//cout<<dateeee1<<" "<<dateeee2<<endl;
	 if(dateeee1==dateeee2){
	 	//cout<<dateeee1<<endl;
	 //	cout<<dateeee2<<endl;
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
//	cout<<"Total day1 :"<<total<<endl;
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
				//cout<<dayinmonth<<endl;
			}
			else if(dateeee1=="02"){
				int temp;
				stringstream ss;
				ss<<date1.substr(0,2);
				ss>>temp;
				ss.clear();
				temp--;
				dayinmonth=28-temp;
			//	cout<<dayinmonth<<endl;				
			}
			else{
				int temp;
				stringstream ss;
				ss<<date1.substr(0,2);
				ss>>temp;
				ss.clear();
				temp--;
				dayinmonth=30-temp;
			//	cout<<dayinmonth<<endl;
			}
		stringstream ss;
		ss<<date2.substr(0,2);
		ss>>dayinmonth2;
		ss.clear();
		total=dayinmonth2+dayinmonth;
		cout<<"Total day2 :"<<total<<endl;
	}
	return total;
}


void checkout::optcheckout()
{
	//string roomnumber;
	string conf;
	recheckout:
	cout << endl << "=================== Check out ===================" << endl;
	cout << "Input Room number : ";
	cin >> roomnumber;
	cout << "Input actual day check-out : ";
	cin >> ac_dayout;
	nodeCustomer *find = getCus.head_customer;
	for(int i=1;i<=getCus.countCustomer;i++)
	{
		if(roomnumber == find->numroom)
		{
			info:
			//string tempdayin,tempdayout;
			find->checkout=ac_dayout;
			predictday=checkday(find->dayin,find->dayout);
		//	cout<<find->checkin<<endl;
			//cout<<find->checkout<<endl;
			total_ac_day=checkday(find->checkin,find->checkout);
			cout << endl << "=================== Customer information ===================" << endl
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
				//getRoom.ChangeSta()
				getRoom.write_file();
				Receipt(roomnumber);
				writecheckout(find->name);
				//getCus.write_file();
				cout << "Confirmation? (y/n): ";
				cin >> conf;
				if(conf == "y" || conf == "Y" || conf == "yes" || conf == "Yes" || conf == "YES")
				{
					getRoom.ChangeStatus(roomnumber, "Empty");
					getRoom.write_file();
					cout << "Check-out completed !" << endl;
				}
				else if(conf == "n" || conf == "N" || conf == "no" || conf == "No" || conf == "NO")
				{
					goto info;
				}
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
				goto recheckout;
			}
			break;
		}
		else if(i == getCus.countCustomer)
		{
			cout << "Not found" << endl;
		}
		find = find->next;
	}
//	getRoom.write_file();
}
void checkout::Receipt(string room){	
	node_room *temp = getRoom.head_room;
	for(int i=0;i<getRoom.count_room;i++){
		if(temp->num_room==room){
			cout << endl << "=================== Receipt ===================" << endl
		 		 << "Room number : " << roomnumber << endl
		 		 << "Type room : " << temp->type_room << "	price : " << temp->price_room <<endl
		 		 << "Amount of days : "<<total_ac_day<<endl
		 		 << "Vat include 7 %" << endl
		 		 << "Total : "<<calculate(roomnumber)<<endl
		 		 << "===============================================" << endl;
		 	break;
		}
		temp=temp->link;
	}
	
}
float checkout::calculate(string room){
	node_room *temp = getRoom.head_room;
	for(int i=0;i<getRoom.count_room;i++){
		if(temp->num_room==room){	
		 	break;
		}
		temp=temp->link;
	}
	stringstream ss;
	
	ss<<temp->price_room;
	ss>>total;
	ss.clear();
	total=total*predictday;
	
	nodeCustomer *Customer = getCus.head_customer;
	for(int i=0;i<getCus.countCustomer;i++){
		if(Customer->numroom==room){	
		 	break;
		}
		Customer=Customer->next;
	}
	ss<<temp->price_room;
	int tmp;
	ss>>tmp;
	ss.clear();
	if(checkday (Customer->dayout,Customer->checkout )-1>=0){
			total=total+( (checkday (Customer->dayout,Customer->checkout )-1) * (tmp+500));
			total=total+(total*vat);
			return total;	
	}
	else{
		return total;
	}
}
 void checkout:: writecheckout(string name){
 		nodeCustomer *temp = getCus.head_customer;
				ofstream myfile ("customer.txt",ios::out);
				if (myfile.is_open()){
					temp = getCus.head_customer;
					for(int i=1;i<=getCus.countCustomer;i++){
						if(temp->name==name){
							ofstream myfile ("History.txt",ios::app);
							if (myfile.is_open()){
								myfile<<temp->name<<","<<temp->tel<<","<<temp->numroom<<","<<temp->codebooked<<","<<temp->dayin<<","<<temp->dayout
								<<","<<temp->checkin<<","<<temp->checkout;
								myfile<<endl;
							}
						else{
							cout << "!!! Not open !!!"<< endl;
						}
				myfile.close();
						}
						
						else{
							myfile<<temp->name<<","<<temp->tel<<","<<temp->numroom<<","<<temp->codebooked<<","<<temp->dayin<<","<<temp->dayout
							<<","<<temp->checkin<<","<<temp->checkout;
							myfile<<endl;	
						}
					
						temp = temp->next;		
					}	
				}else{
					cout << "!!! Not open !!!"<< endl;
				}
				myfile.close();
}
