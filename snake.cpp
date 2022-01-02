#include<bits/stdc++.h>
#include<windows.h>
#include<unistd.h>
using namespace std;

class Snake
{
    public:
    int height,width,targetX,targetY;
    bool endOfGame=false;
    void map(int height,int width)
    {
        cout << "\033[2J\033[1;1H";
        int i,j;
        for(i=0;i<width;i++)
            cout<<"#";
        cout<<endl;
        targetX=rand()%(height-2) + 1;
        targetY=rand()%(width-1) +1;
        for(i=1;i<height;i++)
        {
            for(j=0;j<width;j++)
            {
                if(j==0)
                    cout<<"#";
                else if(i==(height-1))
                    cout<<"#";
                else
                {   
                    if(i==targetX && j==targetY)
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
};

int main()
{
    Snake game;
    game.height=10;
    game.width=20;
    cout << "\033[2J\033[1;1H";
    while(game.endOfGame!=true)
    {
        game.map(game.height,game.width);
        sleep(1);
    }
    return 0;
}