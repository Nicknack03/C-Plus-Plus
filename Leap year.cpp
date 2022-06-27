#include<iostream.h> 
#include<conio.h> 
void main() 
{ 
clrscr(); 
int a; 
cout<<"ENTER THE YEAR = "; 
cin>>a; 
if((a%400==0)||((a%4==0)&&(a%100!=0))) 
cout<<endl<<"LEAP YEAR"; 
else 
cout<<"NOT A LEAP YEAR"; 
getch(); 
} 
