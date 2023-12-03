#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h>
#include <windows.h>
using namespace std;
//************************************************************************************//
enum direction {up=1 ,down , righte , lefte};
struct  map {int widht , height ,frutX,frutY;};
struct  snake { int headX,headY,tail_N,tail_x[1000],tail_y[1000]; direction dir;};
struct  player { int scour ; bool lose ;};
map map1 ;snake snake1 ;player player1;
//**************************************************************************************//
void Shift_tail (int arr[],int sizee){
for(int i =sizee -2 ;i>=0 ;i--)
    arr[i+1]=arr[i];
}
void Random_fruit(){
srand(time(NULL));
map1.frutX=rand() % (map1.widht-2) +1; // 0) 1   38 ( 39
map1.frutY=rand() % (map1.height-2) +1;// 0) 1  18  ( 19
}
void setup(){
map1.widht=40;
map1.height=20;
  Random_fruit();

  //***********************************************//
snake1.headX=map1.widht / (2);
snake1.headY=map1.height /(2);
snake1.tail_N= 0;
//*************************************************//
player1.scour=0;
player1.lose=false;
}
void drawmap(){
system("cls");
for(int i=0;i<map1.height;i++)
{
    for(int j =0; j<map1.widht;j++)
    {
        if(i==0||i==map1.height -1)
            cout<<"A";
        else if (j==0||j==map1.widht  -1 )
            cout<<"W";
        else if (j == snake1.headX && i == snake1.headY)
              cout<<"@";
        else if (j == map1.frutX   && i == map1.frutY  )
            cout<<"$";

        else{bool a=false;
            for(int z=0;z<snake1.tail_N;z++){
            if(snake1.tail_x[z]==j&&snake1.tail_y[z]==i){
                cout<<"o";
                a=true;
                break;
            }
                }if (!a)
                cout<<" ";
        }
    }
cout<<endl;
}
cout<<"your scour is :"<<player1.scour<<endl;
  cout<<"made by : Amgad Alwattar"<<endl;
}
void input (){
if (_kbhit()){
        char c = _getch();
    switch (c)
    {case'w':
        if(snake1.dir != down) snake1.dir= up;
    break;
    case's':
        if(snake1.dir != up) snake1.dir = down;
    break;
    case'd':
        if(snake1.dir != lefte) snake1.dir= righte;
    break;
    case'a' :
        if(snake1.dir != righte)snake1.dir= lefte;
    break;
    case'x':exit(0);
    default:
        break;
    }
}
}
void move (){
Shift_tail(snake1.tail_x,50);
Shift_tail(snake1.tail_y,50);
snake1.tail_x[0]=snake1.headX;
snake1.tail_y[0]=snake1.headY;
switch (snake1.dir)
{case up    : snake1.headY --;break;
case down   : snake1.headY ++;break;
case righte : snake1.headX ++;break;
case lefte  : snake1.headX --;break;
}
if(snake1.headY>=map1.height||snake1.headY<=0||snake1.headX>=map1.widht||snake1.headX<=0)
player1.lose=true;
if (snake1.headY==map1.frutY &&snake1.headX==map1.frutX)
   {
  Random_fruit();
player1.scour++;
snake1.tail_N++;
}
}
void law_of_this_game (){
cout<<"the law of this game "<<endl;
 cout<<endl;
 cout<<"  w "<<endl;
 cout<< "a s d"<<endl;
 cout<<"Click on (w) to go to up"<<endl;
 cout<<"Click on (s) to go to down"<<endl ;
 cout<<"Click on (d) to go to right "<<endl ;
 cout<<"Click on (a) to go to left "<<endl ;
 cout<<"Click on (x) to exit"<<endl;
 cout<<endl;
 cout<<"ENTER ANY KEY TO START PLAY"<<endl;
 cout<<endl;cout<<endl; cout<<endl; cout<<endl;cout<<endl; cout<<endl;cout<<endl;cout<<endl; cout<<endl; cout<<endl;cout<<endl; cout<<endl;cout<<endl;cout<<endl; cout<<endl;
cout<<"made by a Amgad Alwattar"<<endl;
}
int start_game (int x){
cin >>x;
}
int main  (){
    law_of_this_game ();
    int x,c,cs;
cout<<start_game  (x);
  setup();
 while (!player1.lose)
   {drawmap();
    input ();
    move ();
    }
Sleep(2000);
return 0;}
