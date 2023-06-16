#include <iostream>
#include <fstream>
#include <cctype>
#include <iomanip>
using namespace std;
class Bank_Account{
	
	int Money_Deposit;
	char type;
	int acno;
	char name[70];
public:
	
	void report() const;
	int retMoney_Deposit() const;
	void create_Bank_Account();
	void dep(int);
	int retacno() const;
	void Display_Account() const;
	void Updation();
	char rettype() const;
	void draw(int);
};


void Bank_Account::Updation(){
	cout<<"\n\tEnter account number : "<<acno;
	cout<<"\n\tUpdate holder name : ";
	cin.ignore();
	cin.getline(name,50);
	cout<<"\n\tUpdate type of the account (C/S) : ";
	cin>>type;
	type=toupper(type);
	cout<<"\n\tUpdate balance total-money : ";
	cin>>Money_Deposit;
}
void Bank_Account::create_Bank_Account(){
	system("CLS");
	cout<<"\n\tEnter account number : ";
	cin>>acno;
	cout<<"\n\n\tEnter the name of the holder : ";
	cin.ignore();
	cin.getline(name,50);
	cout<<"\n\tEnter type of the account (C/S) : ";
	cin>>type;
	type=toupper(type);
	cout<<"\n\tEnter the starting total-money : ";
	cin>>Money_Deposit;
	cout<<"\n\n\tAccount created..";
}
void Bank_Account::Display_Account() const{
	cout<<"\n\tAccount Number : "<<acno;
	cout<<"\n\tHolder name : ";
	cout<<name;
	cout<<"\n\tType of account : "<<type;
	cout<<"\n\tBalance total-money : "<<Money_Deposit;
}
int Bank_Account::retacno() const{
	return acno;
}
char Bank_Account::rettype() const{
	return type;
}
void Bank_Account::report() const{
	cout<<acno<<setw(10)<<" "<<name<<setw(10)<<" "<<type<<setw(10)<<Money_Deposit<<endl;
}
void Bank_Account::dep(int x){
	Money_Deposit+=x;
}
void Bank_Account::draw(int x){
	Money_Deposit-=x;
}
int Bank_Account::retMoney_Deposit() const{
	return Money_Deposit;
}


void write_Bank_Account();
void display_sp(int);
void display_all();

void delete_Bank_Account(int);
void Money_Deposit_withdraw(int, int);
void Updation_Bank_Account(int);
int main(){
	char ch;
	int num;
	do
	{
	system("CLS");
	cout<<"\n\n\t\t============================";
	
	cout<<"\t\tBANK MANAGEMENT SYSTEM";
	cout<<"\n\t\t============================";

		cout<<"\t\t    ::MAIN MENU::\n";
		cout<<"\n\t\t1. Create new account";
		cout<<"\n\t\t2. Deposit money";
		cout<<"\n\t\t3. Withdraw money";
		cout<<"\n\t\t4. Balance enquiry";
		cout<<"\n\t\t5. All Holder List";
		cout<<"\n\t\t6. Close an account";
		cout<<"\n\t\t7. Update an account";
		cout<<"\n\t\t8. Exit";
		cout<<"\n\n\t\tSelect Your Option (1-8): ";
		cin>>ch;

		switch(ch)
		{
		case '1':
			write_Bank_Account();
			break;
		case '2':
			system("CLS");
			cout<<"\n\n\tEnter account number : "; cin>>num;
			Money_Deposit_withdraw(num, 1);
			break;
		case '3':
			system("CLS");
			cout<<"\n\n\tEnter account number : "; cin>>num;
			Money_Deposit_withdraw(num, 2);
			break;
		case '4':
			system("CLS");
			cout<<"\n\n\tEnter account number : "; cin>>num;
			display_sp(num);
			break;
		case '5':
			display_all();
			break;
		case '6':
			system("CLS");
			cout<<"\n\n\tEnter account number : "; cin>>num;
			delete_Bank_Account(num);
			break;
		 case '7':
		 	system("CLS");
			cout<<"\n\n\tEnter account number : "; cin>>num;
			Updation_Bank_Account(num);
			break;
		 case '8':
		 	system("CLS");
			cout<<"\n\n\tWritten by ninetysixer";
			break;
		 default :cout<<"\a";
		}
		cin.ignore();
		cin.get();
    }while(ch!='8');
	return 0;
}





void write_Bank_Account(){
	Bank_Account ac;
	ofstream outFile;
	outFile.open("Bank_Account.dat",ios::binary|ios::app);
	ac.create_Bank_Account();
	outFile.write(reinterpret_cast<char *> (&ac), sizeof(Bank_Account));
	outFile.close();
}
void delete_Bank_Account(int n){
	Bank_Account ac;
	ifstream inFile;
	ofstream outFile;
	inFile.open("Bank_Account.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	outFile.open("Temp.dat",ios::binary);
	inFile.seekg(0,ios::beg);
	while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(Bank_Account)))
	{
		if(ac.retacno()!=n)
		{
			outFile.write(reinterpret_cast<char *> (&ac), sizeof(Bank_Account));
		}
	}
    inFile.close();
	outFile.close();
	remove("Bank_Account.dat");
	rename("Temp.dat","Bank_Account.dat");
	cout<<"\n\nRecord Deleted ..";
}
void display_sp(int n){
	Bank_Account ac;
	bool flag=false;
	ifstream inFile;
	inFile.open("Bank_Account.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be opened! Press any key...";
		return;
	}
	cout<<"\n\tBalance Details\n";
    	while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(Bank_Account)))
	{
		if(ac.retacno()==n)
		{
			ac.Display_Account();
			flag=true;
		}
	}
    inFile.close();
	if(flag==false)
		cout<<"\n\n\tAccount number does not exist";
}
void display_all(){
	system("CLS");
	Bank_Account ac;
	ifstream inFile;
	inFile.open("Bank_Account.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be opened! Press any key...";
		return;
	}
	cout<<"\n\n\t\tAccount Holder List\n\n";
	cout<<"================================================================\n";
	cout<<"Acc no.         NAME                 Type  Balance\n";
	cout<<"================================================================\n";
	while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(Bank_Account)))
	{
		ac.report();
	}
	inFile.close();
}
void Updation_Bank_Account(int n){
	bool found=false;
	Bank_Account ac;
	fstream File;
    File.open("Bank_Account.dat",ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"File could not be opened! Press any key...";
		return;
	}
	while(!File.eof() && found==false)
	{
		File.read(reinterpret_cast<char *> (&ac), sizeof(Bank_Account));
		if(ac.retacno()==n)
		{
			ac.Display_Account();
			cout<<"\n\n\tEnter the new details of the account"<<endl;
			ac.Updation();
			int pos=(-1)*static_cast<int>(sizeof(Bank_Account));
			File.seekp(pos,ios::cur); //fncallat1353
		    File.write(reinterpret_cast<char *> (&ac), sizeof(Bank_Account));
		    cout<<"\n\n\tRecord updated";
		    found=true;
		  }
	}
	File.close();
	if(found==false)
		cout<<"\n\n\tRecord not found ";
}
void Money_Deposit_withdraw(int n, int option){
	int amt;
	bool found=false;
	Bank_Account ac;
	fstream File;
    File.open("Bank_Account.dat", ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"File could not be opened! Press any key...";
		return;
	}
	while(!File.eof() && found==false)
	{
		File.read(reinterpret_cast<char *> (&ac), sizeof(Bank_Account));
		if(ac.retacno()==n)
		{
			ac.Display_Account();
			if(option==1)
			{
				cout<<"\n\n\tDeposit money";
				cout<<"\n\n\tEnter the total amount to be deposited: ";
				cin>>amt;
				ac.dep(amt);
			}
		    if(option==2)
			{
				cout<<"\n\n\tWithdraw money";
				cout<<"\n\n\tEnter the total amount to be withdrawn: ";
				cin>>amt;
				int bal=ac.retMoney_Deposit()-amt;
				if(bal<0)
					cout<<"Insufficient balance";
				else
					ac.draw(amt);
		      }
			int pos=(-1)*static_cast<int>(sizeof(ac));
			File.seekp(pos,ios::cur);
			File.write(reinterpret_cast<char *> (&ac), sizeof(Bank_Account));
			cout<<"\n\n\tRecord updated";
			found=true;
	       }
         }
    File.close();
	if(found==false)
		cout<<"\n\n\tRecord not found ";
}
