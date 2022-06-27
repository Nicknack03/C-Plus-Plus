#include<iostream.h> 
#include<conio.h> 
class complex 
{ 
float x,y; 
public: 
void get(float r,float i) 
{ 
x=r; 
y=i; 
} 
void show() 
{ 
cout<<x<<" +j "<<y<<endl; 
} 
friend complex add(complex c1,complex c2) 
{ 
complex c3; 
c3.x=c1.x+c2.x; 
c3.y=c1.y+c2.y; 
} 
}; 
void main() 
{

clrscr(); 
complex c1,c2,c; 
c1.get(3.1,5.65); 
c2.get(2.75,1.2); 
c=add(c1,c2); 
cout<<"C1 = "; 
c1.show(); 
cout<<"C2 = "; 
c2.show(); 
cout<<"C3 = "; 
c.show(); 
getch(); 
} 
Out
