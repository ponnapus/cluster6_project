#include "Review.h"
#include<string>
#include<iostream>
#include<sstream>
#include<fstream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <iomanip>
using namespace std;
Review::Review(){
}
void Review::icon(string namefile){
	string filein;
	if(namefile=="thx"){
		ifstream infile("thankyou.txt",std::ios::in);
			if(infile.is_open()){
				while(getline(infile,filein)){
					cout<<filein<<endl;
				}
			}
	infile.close();
	}
	if(namefile=="exit"){
		ifstream infile("exit.txt",std::ios::in);
			if(infile.is_open()){
				while(getline(infile,filein)){
					cout<<filein<<endl;
				}
			}
	infile.close();
	}
	if(namefile=="menu"){
		ifstream infile("menu.txt",std::ios::in);
			if(infile.is_open()){
				while(getline(infile,filein)){
					cout<<filein<<endl;
				}
			}
	infile.close();
	}
	if(namefile=="reviewcomment"){
		ifstream infile("reviewcomment.txt",std::ios::in);
			if(infile.is_open()){
				while(getline(infile,filein)){
					cout<<filein<<endl;
				}
			}
	infile.close();
	}
	if(namefile=="rating"){
		ifstream infile("rating.txt",std::ios::in);
			if(infile.is_open()){
				while(getline(infile,filein)){
					cout<<filein<<endl;
				}
			}
	infile.close();
	}
	if(namefile=="ViewComment"){
		ifstream infile("ViewComment.txt",std::ios::in);
			if(infile.is_open()){
				while(getline(infile,filein)){
					cout<<filein<<endl;
				}
			}
	infile.close();
	}
	if(namefile=="star1"){
		ifstream infile("star1.txt",std::ios::in);
				if(infile.is_open()){
					while( getline(infile,filein) ) {
						cout<<filein<<endl;
					}
				}
		infile.close();
		}
		if(namefile=="star2"){
		ifstream infile("star2.txt",std::ios::in);
				if(infile.is_open()){
					while( getline(infile,filein) ) {
						cout<<filein<<endl;
					}
				}
		infile.close();
		}
		if(namefile=="star3"){
		ifstream infile("star3.txt",std::ios::in);
				if(infile.is_open()){
					while( getline(infile,filein) ) {
						cout<<filein<<endl;
					}
				}
		infile.close();
		}
		if(namefile=="star4"){
		ifstream infile("star4.txt",std::ios::in);
				if(infile.is_open()){
					while( getline(infile,filein) ) {
						cout<<filein<<endl;
					}
				}
		infile.close();
		}
		if(namefile=="star5"){
		ifstream infile("star5.txt",std::ios::in);
				if(infile.is_open()){
					while( getline(infile,filein) ) {
						cout<<filein<<endl;
					}
				}
		infile.close();
		}
}
void Review::reviewhotel(){
	string ch;
	string choose,nname,comment,name;
	int num;
	float total,score;
	menureview:
	Y:
	icon("menu");
	cout<<"Enter : ";
	cin>>choose;
	system("cls");
		if(choose=="1"){//Review & Comment
		
		icon("reviewcomment");
			cout<<"Enter your name : ";
			cin>>name;
			score:
			cout<<"Enter score : ";
				cin>>score;
					if(score<0||score>11){
						cout<<"score between 0-10 only!"<<endl;
						goto score;
					}
			cout<<"Enter Comment : ";
			cin>>comment;
			ofstream myfile ("datareview.txt",ios::app);
				if (myfile.is_open()){
					myfile <<score<<","<<name<<","<<comment;
					myfile<<endl;	
				}
			myfile.close();
			cout<<"======================="<<endl;			
			do{
				cout<<"!Enter Y/N only!"<<endl;
				cout<<"Go back to the start menu? (Y/N) : ";
					cin>>ch;
				
			}while((ch != "Y")&&(ch != "N")&&(ch != "y")&&(ch != "n"));
			sleep(1);
			system("cls");
			if(ch=="Y"||ch=="y"){
				goto Y;
			}
			else {
				goto N;
			}	
		}
		else if(choose=="2"){//View Rating Of Hotel
		icon("rating");
			string filein;
			int count=0;
			ifstream infile("datareview.txt",std::ios::in);
				if(infile.is_open()){
					while( getline(infile,filein) ) {
						string rate;
						rate=filein.substr(0,filein.find(','));
			   	 		filein.erase(0,filein.find(',')+1);
                        stringstream ss;
						ss<<rate;
						ss>>num;
						ss.clear();
						total=total+num;
						count++;
					}
				}
		infile.close();
		cout<<"Total number of people reviewing : ";
		cout<<count<<endl;
		total=total/count;//calculate*
		//total=total/2;
		cout<<endl;
		cout<<"Total rating of hotel : ";
		cout<<setprecision(3);
		cout<<total<<endl;
		cout<<endl;
		if(total>=9.0){//calculate star
			icon("star5");
		}
		else if(total>=7.0){
			icon("star4");
		}
		else if(total>=5.0){
			icon("star3");
		}
		else if(total>=3.0){
			icon("star2");
		}
		else if(total>=1.0){
			icon("star1");
		}
		cout<<"=========================="<<endl;
		do{
				cout<<"!Enter Y/N only!"<<endl;
				cout<<"Go back to the start menu? (Y/N) : ";
					cin>>ch;
				
			}while((ch != "Y")&&(ch != "N")&&(ch != "y")&&(ch != "n")); //Loop do-while check Answer
			sleep(1);
			system("cls");
			if(ch=="Y"||ch=="y"){
				goto Y;
			}
			else {
				goto N;
			}
		}
		else if(choose=="3"){//View Comment
		icon("ViewComment");
			cout<<setw(5)<<left<<"No."<<setw(15)<<left<<" Name "<<setw(10)<<left<<" Comment "<<endl;
			cout<<endl;
			string filein;
			int count=1;
			ifstream infile("datareview.txt",std::ios::in);
				if(infile.is_open()){
					while( getline(infile,filein) ) {
						filein.erase(0,filein.find(',')+1);
						nname=filein.substr(0,filein.find(','));
            			filein.erase(0,filein.find(',')+1);
						comment=filein.substr(0,filein.find(','));
            			filein.erase(0,filein.find(',')+1);
            			//cout<<setw(10)<<left<<" Name "<<setw(10)<<left<<" Comment "<<endl;
            			cout<<setw(5)<<left<<count<<setw(15)<<left<<nname<<" "<<setw(15)<<left<<comment<<endl;
            			count++;
					}
				}
			cout<<"============================================================================="<<endl;
			do{
				cout<<"!Enter Y/N only!"<<endl;
				cout<<"Go back to the start menu? (Y/N) : ";
					cin>>ch;
				
			}while((ch != "Y")&&(ch != "N")&&(ch != "y")&&(ch != "n"));
			sleep(1);
			system("cls");
			if(ch=="Y"||ch=="y"){
				goto Y;
			}
			else {
				goto N;
			}
		}
		else if(choose=="4"){
			N:
		icon("exit");
			sleep(1);
			system("cls");
			icon("thx");
			sleep(1);
		}
		else{
			goto menureview;
		}
		
}

	

