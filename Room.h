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
		Room();
		void add(string No_Room,string type,string people,string price);
		void readfile();
		void show(string num);
		int count_room;
		
	protected:
		
};

#endif
