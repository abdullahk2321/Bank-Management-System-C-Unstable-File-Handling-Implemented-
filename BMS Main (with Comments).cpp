#include<iostream>
#include<conio.h>
#include<string>
#include<fstream>
using namespace std;

//Struct to handle the data of different data types


struct details {
	string name; //Name of the user
	double balance; //Balance of the user
	string password; //Password set by the user
	string id; //ID of the user
};
//Function used to create a new user and also make a file containing his records as well


void create(details info[]){ //info[] is a struct array that can handle multiple data as a single object


	fstream myFile; //used for filehandling
	
	
	cout<<"How many users do you want to create? "<<endl; int size; cin>>size; //Used to take multiple inputs (Loop)
	
	
	for(int i=0;i<size;i++){
		
		
	cout<<"Entering details of the user " <<i+1 <<": "<<endl;
	
	
	cout<<endl;
	
	string file; //used to store the location with extension using the given name (String Concatenation)
	
	cout<<"Enter the Name "<<endl; 	cin>>info[i].name;
	
	
	file="C:\\Users\\mg112\\Desktop\\BMS C++\\Files\\" + info[i].name + ".txt";   //Concatenation used
	
	
	myFile.open(file,ios::out);  //used to create a file
	
	// Below are the steps used to set orignal details for the user
	
	
	cout<<"Enter any unique 4 digit ID "<<endl; 	cin>>info[i].id; 
	info[i].balance=0;
	cout<<"Set a Unique Password "<<endl; cin>>info[i].password;
	
	//Storing the Information in the File created
	
	
	myFile<<"Name: "<<info[i].name<<endl;
	myFile<<"ID "<<info[i].id<<endl;
	myFile<<"Orignal Balance "<<info[i].balance<<endl;
	
	//Closing the file
	
	
	myFile.close();
	}
}

//Functions to be performed when user is logged in and wants to perform certain functions 

//This can be made using seperate function...


void login(details info[]){
	fstream myFile;
	string id; //ID used for comparing the data already present 
	
	
	string file;
	string password; //Password used to verify the password set by the user
	
	
	cout<<"Enter ID "<<endl; cin>>id; //used to take the input ID from the user
	
	
	int size= 50; //Size can vary according the customers 
	for(int i=0;i<size;i++){
		if(id==info[i].id){
			file="C:\\Users\\mg112\\Desktop\\BMS C++\\Files\\"+info[i].name + ".txt"; //Concatenation Used to specify the location based on the name 
			
		//Used because we set the name of the file as the name of the user
		
		
			myFile.open(file,ios::app); //"app" is used because it will make changes to the file for the Mini Statement function and track the overall record
			cout<<"Welcome! "<<info[i].name<<endl;
			cout<<"Enter Password "<<endl;
			
			cin>>password;
			if(password==info[i].password){ //Password being compared to verify 
			
			
				cout<<"Welcome to your Account "<<info[i].name<<endl;
				getch();
				system("cls"); //Clear the overall contents of the screen
				
				
				cout<<"What do you want to perform "<<endl;
				cout<<"1. View Balance "<<endl;
				cout<<"2. Add Balance "<<endl;
				
				cout<<"3. Withdraw Cash "<<endl;
				cout<<"4. Transfer Funds "<<endl;
				int option; cin>>option; //used to take the options input
				
				
			do{ //do-while is used for the repitition of function if needed
				switch(option) {
						
					case 1:	//Default Balance or the balance deposited after the repition of the function
					{ 
						break;
				cout<<"Your Current Balance is "<<info[i].balance<<endl;
				break; 
				}
				
				
					case 2: //Used to Handle the money being deposited 
						
						
					{
				cout<<"How much money would you like to add in your Account "<<endl;
				int cash; cin>>cash;
				
				
				info[i].balance+=cash; 	//Increment in the account with the cash deposited
				
				
				myFile<<"\n Money Deposited "<<cash<<" Remaining Balance is "<<info[i].balance<<endl;
				cout<<cash<<" has been added successfully "<<endl;
				break;
				 }
				 
				 
					case 3:  //Used to handle the cash being withdrawn
					
					{
				cout<<"How much cash would you like to withdraw "<<endl;
				int withdraw; cin>>withdraw;
				
				info[i].balance-=withdraw; //Decrement the money withdrawn from the user's account 
				
				//Can be improved by having a condition that checks for the current balance first and gives an error message if the balance is insufficient
				
				cout<<withdraw<<" has been withdrawn, Your remaining balance is "<<info[i].balance<<endl;
				myFile<<"Money Withdrawal "<<withdraw<<" Remaining Balance is "<<info[i].balance<<endl;
				myFile.close();
				break; }
				
				
					case 4:  //Used to transfer money to another user if they exist 
					
					{
				double money; 
				cout<<"Enter the ID you want to send to "<<endl;
				string ide; cin>>ide;
				for(int i=0;i<size;i++){
					if(ide==info[i].id){	//Check if the other ID exists
				cout<<"How much money do you want to transfer "<<endl;
					cin>>money;	
					info[i].balance+=money; //Increment in the target account
				string secondfile="C:\\Users\\mg112\\Desktop\\BMS C++\\Files\\"+info[i].name + ".txt"; //Opening the file to change its statement as well
				
				
				myFile.open(secondfile,ios::app);	//"app" used to edit the file
				myFile<<"\nMoney Transferred (+"<<money<<" Remaining Account Balance is "<<info[i].balance<<" )"<<endl;
				
				
				cout<<"Your funds have been transferred "<<endl;
				myFile.close();
				break;
					}
				else
						cout<<"ID Doesn't Exist "<<endl; //Error message if the other ID doesn't exist
						break;
				}
				info[i].balance-=money; //Decrement in the user's account
				myFile.open(file,ios::app); //Opening the main file to edit the record / statement 
				myFile<<"Money Transferred (-"<<money<<" Remaining Account Balance is "<<info[i].balance<<" )"<<endl;
				break;
			}
			
			
				default: //Error message alongside automatic repitition
					{
				cout<<"Invalid option "<<endl;
		}
				}
				
				
		} while(option<=4);
			}
			else {
				cout<<"Incorrect Password, Try Again "<<endl;
				getch();
				login(info); //self call to repeat the whole function on wrong password command
			}
		}
		
		
		else {
			cout<<"ID Doesn't Exist "<<endl; //Error text if function fails to find the corresponding ID
			break;
		}
	}
}

//Function to handle the statement and display it on terminal screen
void statement(details info[]){
	string file;
	fstream myFile;
	string line; //used to read from the file
	int size=50;
	cout<<"Enter Name "<<endl;
	
	//Used to compare the file name as we set the record database the name of the users
	string name;
	cin>>name;
	system("cls ");
	file="C:\\Users\\mg112\\Desktop\\BMS C++\\Files\\"+name+".txt";
	myFile.open(file,ios::in); //"in" indicated opening a file for reading
	if(myFile.is_open()){
		
		while(getline(myFile,line)){ //Used to read the lines in the file and store them in the line variable to display
		
			cout<<line<<endl;
		}
	}
	else {
		cout<<"File doesn't Exist "<<endl; //Error if the file doesn't exists
	}
		myFile.close();
}
int main(){
	details info[50]; //Structure array

	int opt; 
	
char restart;
do{ //Used to handle program repitition
	
	
	
	//Three Main options 
	
	cout<<"Enter what do you want to perform? "<<endl;
	cout<<"1. Create a new Account "<<endl;
	cout<<"2. Manage your Account "<<endl;
	cout<<"3. Mini Statement "<<endl;
	cin>>opt;
	if(opt==1){
		create(info); //Calling the create function 
	}
	else if(opt==2){
		login(info);	//Calling the login function 
	}
	else if(opt==3){
		statement(info); //Calling the Statement function
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