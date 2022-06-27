#include<iostream.h> 
#include<stdio.h> 
#include<conio.h> 
#include<string.h> 
class input 
{ 
int no; 
char nm[30]; 
public: 
input() 
{ 
no=3; 
strcpy(nm,"NIKHIL"); 
} 
input(int x,char y[30]) 
{ 
no=x; 
strcpy(nm,y); 
} 
input(input &z) 
{ 
no=z.no; 
strcpy(nm,z.nm); 
} 
void display()
{ 
cout<<"NUMBER = "<<no<<endl<<"NAME = "<<nm<<endl; 
} 
}; 
void main() 
{ 
clrscr(); 
input ob1; 
ob1.display(); 
input ob2(30,"CHARLES"); 
ob2.display(); 
input ob3=ob2; 
ob3.display(); 
getch(); 
} 
