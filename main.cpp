#include <iostream>
#include <string>
#include<Windows.h>
#include "customer.h"
#include "Booking.h"
#include "Room.h"
#include<fstream>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	customer obj; 
	Booking obj1;
	Room obj2;
	obj2.readfile();
	string num_people;
	int num;
	int result=0;
	string username;
	string password;
	string filein,logUser,logPass;
	
	cout << "============== OO SAD Hotel =============" << endl;
	cout << "+ 1. Customer                           +" << endl;
	cout << "+ 2. Employee                           +" << endl;
	cout << "+ 3. Exit                               +" << endl;
	cout << "=========================================" << endl;
	cout << "Enter : " ;
	cin >> num;
	
	switch(num){

		case 1:{
			
			cout << "Enter Num People : ";
				cin >> num_people;
			obj2.show(num_people);
			obj1.book();
			break;
		}	
		case 2:{
			
	do{	
		cout<<"============== LOGIN =============="<<endl;
		cout<<"  Enter username : ";
		cin>>username;
		cout<<"  Enter password : ";
		cin>>password;
		cout<<"===================================" << endl;
		system("cls");
		ifstream myFile; 
		myFile.open("DataStaff.txt",ios::in);
			if(myFile.fail()){
				return 0;
			}else{
				while(getline(myFile,filein)){
					logUser=filein.substr(0,filein.find(','));
    				   		filein.erase(0,filein.find(',')+1);
    				logPass=filein.substr(0,filein.find(','));
    						filein.erase(0,filein.find(',')+1);
					if(username == logUser && password == logPass){
						result = 1;
					}else{
						//result = 2;
					}
				}
				if(result == 2){
					cout << "           - F A I L -           " << endl;
					Sleep(2000);
					system("cls");
				}
			}
	}while(result != 1);
	cout << "           - S U C C E S S -           " << endl;
	Sleep(5000);
	system("cls");
			//login
			break;
		}
			
		case 3:{
			break;
		}
		
	}
	return 0;
}
