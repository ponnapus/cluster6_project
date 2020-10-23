#include "customer.h"
#include <iostream>
#include <fstream>
#include "nodeCustomer.h"

using namespace std;
customer::customer()
{
	
}
void customer::addcustomer(string n,string t,string numr,string r_codebook,string r_dayin,string r_dayout,string c_in,string c_out){
	nodeCustomer *temp = new nodeCustomer();
			temp->name = n;
			temp->tel = t;
			temp->numroom = numr;
			temp->codebooked = r_codebook;
			temp->dayin = r_dayin;
			temp->dayout = r_dayout;
			temp->checkin = c_in;
			temp->checkout = c_out;
			
			if(head_customer == NULL){
				head_customer = temp;
				head_customer -> next = NULL;
				tail_customer = temp;
				tail_customer->next =NULL;
					
			}else{
				tail_customer->next = temp;
				tail_customer = temp;
				tail_customer->next = NULL;
			}	

			this->countCustomer++;
}
void customer::readfilec(){
	string line;
 		ifstream myfile;
		myfile.open("customer.txt",ios::in);

		if(myfile.fail()){
			cout << "not open file" << endl; 
		
		}else{
		while(getline(myfile,line)){	
		

				name = line.substr(0,line.find(','));
					line.erase(0,line.find(',')+1);
				tel = line.substr(0,line.find(','));
					line.erase(0,line.find(',')+1);
				numroom = line.substr(0,line.find(','));
					line.erase(0,line.find(',')+1);
				codebooked = line.substr(0,line.find(','));
					line.erase(0,line.find(',')+1);	
				dayin = line.substr(0,line.find(','));
					line.erase(0,line.find(',')+1);	
				dayout = line.substr(0,line.find(','));
					line.erase(0,line.find(',')+1);	
				c_in = line.substr(0,line.find(','));
					line.erase(0,line.find(',')+1);	
				c_out = line;
				addcustomer(name,tel,numroom,codebooked,dayin,dayout,c_in,c_out);

			}
			  		myfile.close();
		}
}

void customer::write_file(string n,string l,string t,string numr,string codebooked,string dayin,string dayout,string checkin,string checkout){
//	nodeCustomer *temp = new nodeCustomer();
	
	ofstream myfile ("customer.txt",ios::app);
	if (myfile.is_open()){
	
			//	for(int i=1;i<=countCustomer;i++){	
						myfile<</*i<<","<<*/ n  << " " << l<<","<<t<<","<<numr<<","<<codebooked<<","<<dayin<<","<<dayout;
						myfile<<endl;
					
				//	temp = temp->next;
			//	}	
			
	}
	myfile.close();	
}
