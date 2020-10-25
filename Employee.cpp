#include "Employee.h"
#include<iostream>
#include<string>
#include<fstream>
#include<iomanip>
#include<Windows.h>

Employee::Employee(){
			
	username = " ";
	password = " ";
				
}

int Employee::Login(string username,string password){
	string filein,logUser,logPass;
	int num=0;
	ifstream myFile; 
		myFile.open("DataStaff.txt",ios::in);
		if(myFile.fail()){
			return 0;
		}
		else{
			while(getline(myFile,filein)){
				logUser=filein.substr(0,filein.find(','));
    		   		filein.erase(0,filein.find(',')+1);
    			logPass=filein.substr(0,filein.find(','));
    				filein.erase(0,filein.find(',')+1);
				if(username == logUser && password == logPass){
					return 1;
				}else{
					return 2;
				}//if success																									
			}//while				
		}//if myfile open
	myFile.close();
}//bool inputLogin



