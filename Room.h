#ifndef ROOM_H
#define ROOM_H
#include "node_room.h"
#include <string>

using namespace std;
class Room
{
	public:
		node_room *head_room;
		node_room *tail_room;
		string num;
		string No_Room;
		string type;
		string people;
		string price;
		string status;
		int count_room;
		
		Room();
		void add(string No_Room,string type,string people,string price,string status);
		void readfile();
		void show(string num);
		void write_file();
		void ChangeStatus(string No_Room);
		void ChangeSta(string No_Room);
	protected:
		
};

#endif
