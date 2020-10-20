#ifndef NODE_ROOM_H
#define NODE_ROOM_H
#include <iostream>
#include <string>

using namespace std;
class node_room
{
	public:
		string people_room;
		string price_room;
		string type_room;
		string num_room;
		string status_room;
		node_room *next;
		node_room();
};

#endif
