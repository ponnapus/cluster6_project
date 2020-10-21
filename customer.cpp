#include "customer.h"
#include <iostream>
#include <fstream>
#include "nodeCustomer.h"

using namespace std;
customer::customer()
{
	
}
void customer::addcutomer(string n,string t,string numr,string codebooked){
	nodeCustomer *temp = new nodeCustomer();
			temp->name = n;
			temp->tel = t;
			temp->numroom = numr;
			temp->codebooked = codebooked;
			
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
void customer::readfile(){
	string line;
	string d = ",";	
 		ifstream myfile;
		myfile.open("customer.txt",ios::in);

		if(myfile.fail()){
			cout << "not open file" << endl; 
		
		}else{
		while(getline(myfile,line)){	
		

				name= line.substr(0,line.find(d));
					line.erase(0,line.find(d)+1);
				tel = line.substr(0,line.find(d));
					line.erase(0,line.find(d)+1);
				numroom = line.substr(0,line.find(d));
					line.erase(0,line.find(d)+1);	
				codebooked = line.substr(0,line.find(" "));
				//codebooked=line.erase(0,line.find(d)+1);
				addcutomer(name,tel,numroom,codebooked);
			}
			  		myfile.close();
		}
}

void customer::write_file(string n,string l,string t,string numr,string codebooked){
//	nodeCustomer *temp = new nodeCustomer();
	
	ofstream myfile ("customer.txt",ios::app);
	if (myfile.is_open()){
	
			//	for(int i=1;i<=countCustomer;i++){	
						myfile<</*i<<","<<*/ n  << " " << l<<","<<t<<","<<numr<<","<<codebooked;
						myfile<<endl;
					
				//	temp = temp->next;
			//	}	
			
	}
	myfile.close();	
}
