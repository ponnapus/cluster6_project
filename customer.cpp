#include "customer.h"
#include "nodeCustomer.h"
#include <iostream>
#include <fstream>
#include "nodeCustomer.h"

using namespace std;
customer::customer()
{
		head_customer=NULL;
		tail_customer=NULL;
		temp=NULL;
		name="";
		tel="";
		numroom="";
		codebooked="";
		dayin="";
		dayout="";
		check_in="";
		check_out="";
		countCustomer=0;	
}
void customer::addcutomer(string n,string t,string numr,string codebooked,string dayin,string dayout,string checkin,string checkout){
	nodeCustomer *temp = new nodeCustomer();
			temp->name = n;
			temp->tel = t;
			temp->numroom = numr;
			temp->codebooked = codebooked;
			temp->dayin = dayin;
			temp->dayout = dayout;
			temp->checkin = checkin;
			temp->checkout = checkout;
			
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
				codebooked = line.substr(0,line.find(d));
					line.erase(0,line.find(d)+1);
				dayin = line.substr(0,line.find(d));
					line.erase(0,line.find(d)+1);
				dayout = line.substr(0,line.find(d));
					line.erase(0,line.find(d)+1);
				check_in = line.substr(0,line.find(d));
					line.erase(0,line.find(d)+1);
				check_out = line;	
				
				addcutomer(name,tel,numroom,codebooked,dayin,dayout,check_in,check_out);
			}
			  		myfile.close();
		}
}

void customer::write_file(){
	temp = head_customer;
	ofstream myfile ("customer.txt",ios::out);
		if (myfile.is_open()){
			for(int i=1;i<=countCustomer;i++){
						myfile<<temp->name<<","<<temp->tel<<","<<temp->numroom<<","<<temp->codebooked<<","<<temp->dayin<<","<<temp->dayout
						<<","<<temp->checkin<<","<<temp->checkout;
						myfile<<endl;
				temp = temp->next;		
			}
			
		}else{
			cout << "!!! Not open !!!"<< endl;
		}
			myfile.close();	
			
}
void customer::show(){
		temp = head_customer;
		for(int i=1;i<=countCustomer;i++){
			cout<<temp->name<<endl;
			temp=temp->next;
		}

}
