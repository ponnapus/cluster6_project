#include "node_room.h"
#include <iostream>
#include <string>

using namespace std;
node_room::node_room()
{
		people_room = "";
		price_room = "";
		type_room= "";
		num_room = "";
		status_room="";
		next = NULL;
		
}
void node_room::chagestatus(string status){
	status_room=status;	
}
