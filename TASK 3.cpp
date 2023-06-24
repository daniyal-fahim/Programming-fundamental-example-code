#include<iostream>

using namespace std;

class bank
{
int acc_num;
   string name;
   int balance=0;

public:
	void openaccount(int k,string n,int b)
	{
		acc_num=k;
		name=n;
		balance=b;
	}
	void showaccount()
	{
		cout<<endl<<"ACCOUNT NUMBER "<<acc_num;
		cout<<endl<<"NAME "<<name;
		cout<<endl<<"BALANCE "<<balance;
	}
	void withdrawl(int p)
	{
		int q;
		if(balance>p)
		{
			q=balance-p;
			balance=q;
			cout<<"the amount has been withdrowl succesfully";
		}
		else
		cout<<endl<<"NOT ENOUGH BALANCE FAILED";
	}
	void deposit(int l)
	{
		balance=balance+l;
	}
 int getaccnum()
	{
		return acc_num;
	}
};


int main()
{
	bank b[3];
int k,T,am,acc,choice,i,l,pk;
	string n;
	do {
cout<<endl<<"ENTER 1 TO OPEN ACCOUNT";
cout<<endl<<"ENTER 2 TO SHOW ACCOUNT";
cout<<endl<<"ENTER 3 TO DEPOSIT";
cout<<endl<<"ENTER 4 TO WITHDRAWL";
cout<<endl<<"ENTER 5 TO SEARCH";
cout<<endl<<"ENTER 6 TO END/EXIT";
	cin>>choice;
	switch(choice)
	{
		case 1:
	cout<<endl<<"enter your customer num (array num)";
	cin>>i;
	
	cout<<"ENTER THE ACCOUNT NUMBER    ";
	cin>>k;

	fflush(stdin);
	cout<<"ENTER NAME         ";
	getline(cin,n);
	cout<<"ENTER BALANCE  ";
	cin>>T;
			for(l=0;l<3;l++)
	{
			if (b[l].getaccnum()==k)
	  		{
	  	    cout<<"invalid acc num";
	  	    pk=1;
			  }
	}
	if(pk!=1)
		b[i].openaccount(k,n,T);

	break;
	
	   case 2:
	   		cout<<endl<<"enter your customer num (array num)";
	cin>>i;
	b[i].showaccount();
	break;
	
	  case 3:
	  		cout<<endl<<"enter your customer num (array num)";
	cin>>i;
	  	cout<<endl<<"enter the amount you want to deposit";
	  	cin>>am;
	  	b[i].deposit(am);
	  	break;
	
	  case 4:
	  		cout<<endl<<"enter your customer num (array num)";
	cin>>i;
		  cout<<endl<<"enter the amount you want to withdraw";
	  	cin>>am;
	  	b[i].withdrawl(am);
	  	break;
	  	
	  case 5:
	 
	  	cout<<"ENTER ACC NUM YOU WANT TO SEARCH";
	  	cin>>acc;
	  	for(i=0;i<3;i++)
	  	{
	  		if (b[i].getaccnum()==k)
	  		{
	  		b[i].showaccount();
			  }
		}
		break;
		
		case 6:
		return 0;
		
	  	
	
	}
}while(choice!=6);
}