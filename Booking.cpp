#include "Booking.h"
#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <fstream>

using namespace std;
Booking::Booking()
{
		username = "";
		name = "";
		lname = "";
		num_people = "";
		day_in = "";
		day_out = "";
		num_booking = 0;
		num_room = "";
		tel = "";
}
bool Booking::checkAnswer(string room){
	string line,nameroom,temp;
	string d = ",";	
 		ifstream myfile;
		myfile.open("room.txt",ios::in);

		if(myfile.fail()){
			cout << "not open file" << endl; 
		
		}else{
		while(getline(myfile,line)){	
				line.erase(0,line.find(d)+1);
				nameroom = line.substr(0,line.find(d));
				if(nameroom==room){
					temp="0";
					break;
				}
				else {
					temp="1";
				}
			}
		myfile.close();
		if(temp == "0"){
			return true;
		}
		else if(temp == "1"){
			return false;	
		}
		}
	/*node_room *temp = head_room;
	for(int i=1;i<=count_room;i++){
		if(temp->num_room==room){
			return false;
		}
		temp=temp->next;
	}
	return true;*/
}

void Booking::book(){
			//cout << "Enter Num People : ";
			//cin >> num_people;
			//	data();
			cout << "Booking"<< endl;
			cout << "1. Booking" << endl;
			cout << "2. return home" << endl;
			cout << "=================" << endl;
			cout << "Enter : ";
				cin >> num_booking;
			if(num_booking == 1){
				booking:
				cout << "+++++++++++++++++++ BOOKING ++++++++++++++++++++" << endl;
				cout << "Enter number room : ";
					cin >> num_room;
					//cout<<"Numroom : "<<num_room;
					if(checkAnswer(num_room)==false){
						goto booking;
					}
					else if(checkAnswer(num_room)==true){
						cout << "Enter day in : ";
						cin >> day_in;
			cout << "Enter day out : ";
			cin >> day_out;
						cout << "Enter Name : ";
							cin >> name ;
						cout << "num tel : " ;
							cin >> tel;
						cout << "================================================" << endl;
					}
				
			}else if(num_booking == 2){
				cout<<"Loading............"<<endl;
			}	
}
/*
string Booking::getnumroom(){
	return num_room;
}
string Booking::getname(){
	return name+" "+lname;
}
string Booking::gettel(){
	return tel;
}
*/

/*void Booking::add(){
	string n;
	//n = name+" "+lname;
	obj.addcutomer(name,tel,num_room,codebook);
}*/

void Booking::randomcode(){
	int num[6];
	srand (time(NULL));
	for(int i = 0; i < 6 ; i++){
	num[i] = rand() % 59;
	}
	string code="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	
	for(int i=0;i<6;i++){
		codebook=codebook+code[num[i]];
	}
	cout<<"Code: "<<codebook << endl;
	obj.readfile();	
	obj.addcutomer(name+lname,tel,num_room,codebook,day_in,day_out,"-","-");
	obj.write_file();
	

//return codebook;	
}


		
