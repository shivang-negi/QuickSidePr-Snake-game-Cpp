#include<bits/stdc++.h>
#include<windows.h>
#include<unistd.h>
#include<conio.h>
using namespace std;
class Snake
{
    public:
    int height,width,targetX,targetY;
    int monitorX,monitorY;
    string dir="right";
    Snake(int x,int y)
    {
        height=x;
        width=y;
        targetX=rand()%(height-2) + 1;
        targetY=rand()%(width-1) +1;
        monitorX=height/2;
        monitorY=width/2;
    }
    bool endOfGame=false;
    void map(int height,int width)
    {
        cout << "\033[2J\033[1;1H";
        int i,j;
        for(i=0;i<height;i++)
        {
            for(j=0;j<width;j++)
            {
                if(i==0)
                    cout<<"#";
                else if(j==0)
                    cout<<"#";
                else if(i==(height-1))
                    cout<<"#";
                else
                {   
                    if(i==monitorX && j==monitorY)
                        cout<<"=";
                    else if(i==targetX && j==targetY)
                        cout<<"*";
                    else
                        cout<<" ";
                }                
                
                if(j==(width-1))
                    cout<<"#";
            }
            cout<<endl;
        }
    }
    void target()
    {
        targetX=rand()%(height-2) + 1;
        targetY=rand()%(width-1) +1;
    }
    void work()
    {
        if(dir=="right")
        {
            monitorY++;
            if(monitorY==width)
                monitorY=1;
        }
        if(dir=="left")
        {
            monitorY--;
            if(monitorY==0)
                monitorY=width-1;
        }
        if(dir=="up")
        {
            monitorX--;
            if(monitorX==1)
                monitorX=height-1;
        }
        if(dir=="down")
        {
            monitorX++;
            if(monitorX==height-1)
                monitorX=1;
        }
    }
    void input()
    {
        if(GetKeyState('A') & 0x8000/*Check if high-order bit is set (1 << 15)*/)
        {
            cout<<dir;
            dir="left";
        }
        if(GetKeyState('D') & 0x8000/*Check if high-order bit is set (1 << 15)*/)
        {
            dir="right";
        }
        if(GetKeyState('S') & 0x8000/*Check if high-order bit is set (1 << 15)*/)
        {
            dir="down";
        }
        if(GetKeyState('W') & 0x8000/*Check if high-order bit is set (1 << 15)*/)
        {
            dir="up";
        }
    }
};

int main()
{
    Snake game(10,10);
    cout << "\033[2J\033[1;1H";
    while(game.endOfGame!=true)
    {
        Sleep(250); 
        game.input();
        game.map(game.height,game.width);
        game.work();
    }
    return 0;
}