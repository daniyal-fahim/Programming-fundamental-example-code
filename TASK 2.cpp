#include<iostream>

using namespace std;
class glass
{
	 int liqlevel;
	
public:
	glass()
	{
		liqlevel=200;
	}
  int getliq()
  {
   return liqlevel;
  }
  void refill(int q)
  {
  	if(liqlevel<100)
  	{
  		int p;
  		p=200-liqlevel;
  		cout<<endl<<"the robot has refilled the glass with  "<<p<<"  millileter"<<endl;
  		liqlevel=200;
	  }
  }
  void drink(int a)
{
	  int q=liqlevel-a;
	  liqlevel=q;
}
};


int main()
{
	glass g;
	int level,q;
do {
	cout<<endl<<"ENTER THE LEVEL OF LIQUID";
	cin>>level;
	g.drink(level);
    cout<<endl<<"remaining liq level  "<<g.getliq();
    if(g.getliq()<100)
    {
    	g.refill(level);
    	cout<<endl<<"remaining liq level  "<<g.getliq();
	}
    
	cout<<endl<<"enter 4 to exit";
	cin>>q;
}while(q!=4);
}