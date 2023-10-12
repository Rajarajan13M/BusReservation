#include<conio.h>
#include<stdio.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<dos.h>
using namespace std;
int p = 0;
class a
{
  char busn[5], driver[20], arrival[10], depart[10], from[10], to[10], seat[8][4][10];
public:
  void busd();
  void allotment();
  void empty();
  void show();
  void avail();
  void position(int i);
}
bus[10];
void vline(char ch)
{
  for (int i=80;i>0;i--)
  cout<<ch;
}
void a::busd()
{
  clrscr();
  cout<<"Enter bus no: ";
  cin>>bus[p].busn;
  cout<<"\nEnter driver's name: ";
  cin>>bus[p].driver;
  cout<<"\nDeparture time: ";
  cin>>bus[p].depart;
  cout<<"\nArrival time: ";
  cin>>bus[p].arrival;
  cout<<"\nFrom: ";
  cin>>bus[p].from;
  cout<<"\nTo: ";
  cin>>bus[p].to;
  bus[p].empty();
  p++;
  clrscr();
}
void a::allotment()
{
  clrscr();
  int seat;
  char snumber[5];
  top:
  cout<<"Bus no: ";
  cin>>snumber;
  int n;
  for(n=0;n<=p;n++)
  {
    if(strcmp(bus[n].busn, snumber)==0)
    break;
  }
  while(n<=p)
  {
    cout<<"\nSeat Number: ";
    cin>>seat;
    if(seat>32)
    {
      cout<<"\nThere are only 32 seats available in this bus.";
    }
    else
    {
    if (strcmp(bus[n].seat[seat/4][(seat%4)-1], "Empty")==0)
      {
	cout<<"Enter passanger's name: ";
	cin>>bus[n].seat[seat/4][(seat%4)-1];
	break;
      }
    else
      cout<<"The seat no. is already reserved.\n";
      }
   }
    if(n>p)
    {
      cout<<"Enter correct bus no.\n";
      goto top;
    }
   clrscr();
}
void a::empty()
{
  for(int i=0; i<8;i++)
  {
    for(int j=0;j<4;j++)
    {
      strcpy(bus[p].seat[i][j], "Empty");
    }
  }
}
void a::show()
{
  clrscr();
  int n;
  char number[5];
  cout<<"Enter bus no: ";
  cin>>number;
  for(n=0;n<=p;n++)
  {
    if(strcmp(bus[n].busn, number)==0)
    break;
  }
while(n<=p)
{
  vline('*');
  cout<<"Bus no: "<<bus[n].busn;
  cout<<"\nDriver: "<<bus[n].driver;
  cout<<"\nDeparture time: "<<bus[n].depart;
  cout<<"\nArrival time: "<<bus[n].arrival;
  cout<<"\nFrom: "<<bus[n].from;
  cout<<"\n\To: "<<bus[n].to<<"\n";
  vline('*');
  bus[0].position(n);
  int a=1;
  for (int i=0; i<8; i++)
  {
    for(int j=0;j<4;j++)
    {
      a++;
    }
  }
  break;
  }
  getch();
  if(n>p)
    cout<<"Enter correct bus no:";
}
void a::position(int l)
{
  int s=0;p=0;
  for (int i =0; i<8;i++)
  {
    cout<<"\n";
    for (int j = 0;j<4; j++)
    {
      s++;
      if(strcmp(bus[l].seat[i][j], "Empty")==0)
	{
	  cout.width(5);
	  cout.fill(' ');
	  cout<<s<<".";
	  cout.width(10);
	  cout.fill(' ');
	  cout<<bus[l].seat[i][j];
	  p++;
	}
	else
	{
	cout.width(5);
	cout.fill(' ');
	cout<<s<<".";
	cout.width(10);
	cout.fill(' ');
	cout<<bus[l].seat[i][j];
	}
      }
    }
  cout<<"\n\nThere are "<<p<<" seats empty in Bus No: "<<bus[l].busn;
}
void a::avail()
{
  clrscr();
  for(int n=0;n<p;n++)
  {
    vline('*');
    cout<<"Bus no: "<<bus[n].busn;
    cout<<"\nDriver: "<<bus[n].driver;
    cout<<"\nDeparture Time: "<<bus[n].depart;
    cout<<"\nArrival time: "<<bus[n].arrival;
    cout<<"\nFrom: "<<bus[n].from;
    cout<<"\nTo: "<<bus[n].to<<"\n";
    vline('*');
    vline('_');
  }
  cout<<"\n\n\t\t\tPress enter to continue";
  getch();
}
void developdet()
{
 clrscr();
 cout<<"\n\n\n\n\n\n\n\t\t\t\tDeveloped by:\n";
 delay(500);
 cout<<"\n\t\t\t\tS. Arunnesh Kumar";
 delay(1000);
 cout<<"\n\t\t\t\tB.K.A. Dhanush Ram";
 delay(1500);
 cout<<"\n\t\t\t\tM. Rajarajan";
}
void main()
{
clrscr();
developdet();
delay(4500);
clrscr();
int x;
while(1)
{
  cout<<"\n\n\n\n\n\n";
  cout<<"\t\t\t\t1.Enter Bus Details\n\t\t\t\t";
  cout<<"2.Reservation\n\t\t\t\t";
  cout<<"3.Show\n\t\t\t\t";
  cout<<"4.Buses Available. \n\t\t\t\t";
  cout<<"5.Exit\n";
  cout<<"\n\tEnter your choice: ";
  cin>>x;
  switch(x)
  {
    case 1:
      bus[p].busd();
      break;
    case 2:
      bus[p].allotment();
      break;
    case 3:
      bus[0].show();
      break;
    case 4:
      bus[0].avail();
      break;
    case 5:
      exit(0);
  }
}
getch();
}
