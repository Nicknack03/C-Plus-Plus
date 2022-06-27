#include<iostream.h> 
#include<conio.h> 
class time 
{ 
int x,y; 
public: 
void set(int h,int m) 
{ 
x=h; 
y=m; 
} 
void show() 
{ 
cout<<x<<" HOURS "<<y<<" MINUTES"<<endl; 
} 
friend time add(time t1,time t2) 
{ 
time t3; 
t3.y=t1.y + t2.y; 
t3.x=t3.y/60; 
t3.y=t3.y%60; 
t3.x=t3.x+t1.x+t2.x; 
return(t3); 
}

}; 
void main() 
{ 
clrscr(); 
time t1,t2,t; 
t1.set(2,45); 
t2.set(3,30); 
t=add(t1,t2); 
cout<<"T1 = "; 
t1.show(); 
cout<<"T2 = "; 
t2.show(); 
cout<<"T3 = "; 
t.show(); 
getch(); 
} 
