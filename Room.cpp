#include "Room.h"
#include "node_room.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
Room::Room()
{
		head_room =NULL;
		tail_room =NULL;
		count_room = 0;
}

void Room::add(string No_Room,string type,string people,string price,string status){
	node_room *temp = new node_room();
			temp->num_room = No_Room;
			temp->type_room = type;
			temp->people_room = people;
			temp->price_room = price;
			temp->status_room=status;
			
			if(head_room == NULL){
				head_room = temp;
				head_room -> next = NULL;
				tail_room = temp;
				tail_room->next =NULL;
					
			}else{
				tail_room->next = temp;
				tail_room = temp;
				tail_room->next = NULL;
			}	

			this->count_room++;
}

void Room::readfile(){
	string line;
	string d = ",";	
 		ifstream myfile;
		myfile.open("room.txt",ios::in);

		if(myfile.fail()){
			cout << "not open file" << endl; 
		
		}else{
		while(getline(myfile,line)){	
		

				num = line.substr(0,line.find(d));
					line.erase(0,line.find(d)+1);
				No_Room = line.substr(0,line.find(d));
					line.erase(0,line.find(d)+1);
				type = line.substr(0,line.find(d));
					line.erase(0,line.find(d)+1);
				people = line.substr(0,line.find(d));
					line.erase(0,line.find(d)+1);
				price = line.substr(0,line.find(d));
					line.erase(0,line.find(d)+1);
				status = line.substr(0,line.find(d));	
					add(No_Room,type,people,price,status);

			}
			  		myfile.close();
		}
}
void Room::write_file(){
	node_room *temp = head_room;
	for(int i=1;i<=count_room;i++){
	ofstream myfile ("room.txt",ios::app);
				if (myfile.is_open()){	
						myfile<<i<<","<<temp->num_room<<","<<temp->type_room<<","<<temp->people_room<<","<<temp->price_room<<","<<temp->status_room;
						myfile<<endl;
					}	
			myfile.close();	
			temp = temp->next;
	}
}
void Room::ChangeStatus(string No_Room){
	node_room *temp = head_room;
	for(int i=1;i<=count_room;i++){
		if(No_Room==temp->num_room){
			temp->status_room="Booked";
			break;
		}
		temp=temp->next;
	}
}
void Room::show(string num){
	node_room *temp = head_room;
		cout << "=============================" << "NUM PEOPLE "<< num <<" PER ONE ROOM" <<"=============================================================" << endl;
		cout << "ROOMID" << "\t" << "\tTYPE ROOM" << "\t"<< "PRICE ROOM"<< endl;
		cout << "=============================================================================================================================" << endl;

		for(int i=0;i<count_room;i++){
			//cout << temp->people_room<< endl;
			//cout << "="<<temp->type_room<<  endl;
			if(temp->status_room=="Empty"){
				if(num == temp->people_room){
				cout << temp->num_room << "\t"<< temp->type_room << "\t\t"<<temp->price_room<< "$"<< endl;
				}	
					temp = temp->next;	
			}	
		}
			cout << "===================== OTHER ROOM ====================" << endl;	
			temp = head_room;
			
		cout << "ROOMID" << "\t" << "NUM PEOPLE\t"  << "TYPE ROOM" << "\t"<< "PRICE ROOM"<< endl;
		for(int i=0;i<count_room;i++){
			//cout << temp->people_room<< endl;
			//cout << "="<<temp->type_room<<  endl;
			if(temp->status_room=="Empty"){
				if(num != temp->people_room){
					cout << temp->num_room << "\t" << temp->people_room  << "people \t"<< temp->type_room << "\t\t"<<temp->price_room<< "$"<< endl;
				}	
				temp = temp->next;
			}
		}
		cout << "=========================================" << endl;
		
}
