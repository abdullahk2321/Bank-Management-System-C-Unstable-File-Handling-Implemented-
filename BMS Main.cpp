#include<iostream>
#include<conio.h>
#include<string>
#include<fstream>
using namespace std;
struct details {
	string name;
	double balance;
	string password;
	string id;
};
void create(details info[]){
	fstream myFile;
	cout<<"How many users do you want to create? "<<endl; int size; cin>>size;
	for(int i=0;i<size;i++){
	cout<<"Entering details of the user " <<i+1 <<": "<<endl;
	cout<<endl;
	string file;
	cout<<"Enter the Name "<<endl; 	cin>>info[i].name;
	file="C:\\Users\\mg112\\Desktop\\BMS C++\\Files\\" + info[i].name + ".txt";  
	myFile.open(file,ios::out);
	cout<<"Enter any unique 4 digit ID "<<endl; 	cin>>info[i].id;
	info[i].balance=0;
	cout<<"Set a Unique Password "<<endl; cin>>info[i].password;
	myFile<<"Name: "<<info[i].name<<endl;
	myFile<<"ID "<<info[i].id<<endl;
	myFile<<"Orignal Balance "<<info[i].balance<<endl;
	myFile.close();
	}
}
void login(details info[]){
	fstream myFile;
	string id;
	string file;
	string password;
	cout<<"Enter ID "<<endl; cin>>id;
	int size= 50;
	for(int i=0;i<size;i++){
		if(id==info[i].id){
			file="C:\\Users\\mg112\\Desktop\\BMS C++\\Files\\"+info[i].name + ".txt";
			myFile.open(file,ios::app);
			cout<<"Welcome! "<<info[i].name<<endl;
			cout<<"Enter Password "<<endl;
			cin>>password;
			if(password==info[i].password){
				cout<<"Welcome to your Account "<<info[i].name<<endl;
				getch();
				system("cls");
				cout<<"What do you want to perform "<<endl;
				cout<<"1. View Balance "<<endl;
				cout<<"2. Add Balance "<<endl;
				cout<<"3. Withdraw Cash "<<endl;
				cout<<"4. Transfer Funds "<<endl;
				int option; cin>>option;
			do{
				switch(option) {
					case 1:{
						break;
				cout<<"Your Current Balance is "<<info[i].balance<<endl;
				break; }
					case 2:{
				cout<<"How much money would you like to add in your Account "<<endl;
				int cash; cin>>cash;
				info[i].balance+=cash;
				myFile<<"\n Money Deposited "<<cash<<" Remaining Balance is "<<info[i].balance<<endl;
				cout<<cash<<" has been added successfully "<<endl;
				break; }
					case 3: {
				cout<<"How much cash would you like to withdraw "<<endl;
				int withdraw; cin>>withdraw;
				info[i].balance-=withdraw;
				cout<<withdraw<<" has been withdrawn, Your remaining balance is "<<info[i].balance<<endl;
				myFile<<"Money Withdrawal "<<withdraw<<" Remaining Balance is "<<info[i].balance<<endl;
				myFile.close();
				break; }
					case 4: {
				double money; 
				cout<<"Enter the ID you want to send to "<<endl;
				string ide; cin>>ide;
				for(int i=0;i<size;i++){
					if(ide==info[i].id){
				cout<<"How much money do you want to transfer "<<endl;
					cin>>money;	
					info[i].balance+=money;
				string secondfile="C:\\Users\\mg112\\Desktop\\BMS C++\\Files\\"+info[i].name + ".txt";
				myFile.open(secondfile,ios::app);
				myFile<<"\nMoney Transferred (+"<<money<<" Remaining Account Balance is "<<info[i].balance<<" )"<<endl;
				cout<<"Your funds have been transferred "<<endl;
				myFile.close();
				break;
					}
				else
						cout<<"ID Doesn't Exist "<<endl;
						break;
				}
				info[i].balance-=money;
				myFile.open(file,ios::app);
				myFile<<"Money Transferred (-"<<money<<" Remaining Account Balance is "<<info[i].balance<<" )"<<endl;
				break;
			}
				default:
					{
				cout<<"Invalid option "<<endl;
		}
				}
		} while(option<=4);
			}
			else {
				cout<<"Incorrect Password, Try Again "<<endl;
				getch();
				login(info);
			}
		}
		else {
			cout<<"ID Doesn't Exist "<<endl;
			break;
		}
	}
}
void statement(details info[]){
	string file;
	fstream myFile;
	string line;
	int size=50;
	cout<<"Enter Name "<<endl;
	string name;
	cin>>name;
	system("cls ");
	file="C:\\Users\\mg112\\Desktop\\BMS C++\\Files\\"+name+".txt";
	myFile.open(file,ios::in);
	if(myFile.is_open()){
		while(getline(myFile,line)){
			cout<<line<<endl;
		}
	}
	else {
		cout<<"File doesn't Exist "<<endl;
	}
		myFile.close();
}
int main(){
	details info[50];

	int opt;
	
char restart;
do{
	cout<<"Enter what do you want to perform? "<<endl;
	cout<<"1. Create a new Account "<<endl;
	cout<<"2. Manage your Account "<<endl;
	cout<<"3. Mini Statement "<<endl;
	cin>>opt;
	if(opt==1){
		create(info);
	}
	else if(opt==2){
		login(info);
	}
	else if(opt==3){
		statement(info);
	}
	else{
		cout<<"Invalid "<<endl;
		getch();
		system("cls");
		main();
	}
	cout<<"You want to restart? Y/N";
 cin>>restart;
}
while(restart=='Y');
}