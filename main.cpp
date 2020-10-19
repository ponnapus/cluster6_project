#include <iostream>
#include <string>
#include "customer.h"

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	customer obj; 
	int num;
	
	cout << "============== OO SAD Hotel =============" << endl;
	cout << "+ 1. Customer                           +" << endl;
	cout << "+ 2. Employee                           +" << endl;
	cout << "+ 3. Exit                               +" << endl;
	cout << "=========================================" << endl;
	cout << "Enter : " ;
	cin >> num;
	
	switch(num){

		case 1:{
			obj.Booking();
			break;
		}	
		case 2:{
			break;
		}
			
		case 3:{
			break;
		}
		
	}
	return 0;
}
