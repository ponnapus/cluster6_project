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
			cout << "=================== Customer information ===================" << endl
				 << "Name : " << find->name << endl
				 << "Tel : " << find->tel << endl
				 << "Room number : " << find->numroom << endl
				 << "Day check-in : " << find->dayin << endl
				 << "Day check-out : " << find->dayout << endl
				 << "Actual day check-out : " << ac_dayout << endl
				 << "============================================================" << endl
				 << "Confirmation? (y/n)" << endl;
			cin >> conf;
			if(conf == "y" || conf == "Y" || conf == "yes" || conf == "Yes" || conf == "YES")
			{
				receipt:
				//b.Receipt();
				cout << "Confirmation? (y/n)" << endl;
				if(conf == "y" || conf == "Y" || conf == "yes" || conf == "Yes" || conf == "YES")
				{
				 	
				}
				else if(conf == "n" || conf == "N" || conf == "no" || conf == "No" || conf == "NO")
				{
					goto receipt;
				}
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
