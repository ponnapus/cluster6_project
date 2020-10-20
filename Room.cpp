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
}

void Room::add(string No_Room,string type,string people,string price){
	node_room *temp = new node_room();
			temp->num_room = No_Room;
			temp->type_room = type;
			temp->people_room = people;
			temp->price_room = price;
			
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
				No_Room = line.substr(0,line.find(" "));
					line.erase(0,line.find(" ")+1);
				type = line.substr(0,line.find(d));
					line.erase(0,line.find(d)+1);
				people = line.substr(0,line.find(d));
					line.erase(0,line.find(d)+1);
				price = line.substr(0,line.find(d));
					//	line.erase(0,line.find(d)+1);
					add(No_Room,type,people,price);

			}
			  		myfile.close();
		}
}

void Room::show(string num){
	node_room *temp = head_room;
		
		for(int i=0;i<count_room;i++){
			if(num == temp->people_room){
			cout << temp->num_room << "\t" << temp->people_room << temp->price_room << "\t"<<temp->type_room << endl;
			temp = temp->next;
			}	
		}
	
}
