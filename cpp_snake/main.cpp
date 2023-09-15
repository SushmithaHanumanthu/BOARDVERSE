#include<bits/stdc++.h>
#include<windows.h>
#include<conio.h>

using namespace std ;


bool gameOver  ;
const int width = 50 ;
const int height = 50 ;

int Snakex[1000] ;
int Snakey[1000] ;

int x,y ;
int lengthTail ;

int fruitX, fruitY ;

int score ;

enum eDirection  {STOP =0 , LEFT , RIGHT  , UP , DOWN};

eDirection dir ;


void init()
{
    gameOver = false ;
    lengthTail = 0 ;
    dir = STOP ;
    x = width/2 ;
    y = height/2 ;
    fruitX = rand()%(width-1) ;
    fruitY = rand()%(height-1) ;
    score = 0 ;

}

void Box()
{
    system("cls") ;

    bool space = false ;

    for(int i = 0 ; i<height ; i++)
    {
        for(int j = 0 ; j<width ; j++)
        {
            space = false ;
            if((j== 0) || (j == (width-1)) || (i ==0) || (i==height-1))
            {
                cout<<"#" ;
            }
            else if(j == fruitX && i == fruitY)
            {
                cout<<"F" ;
            }
            else if(j == x && i == y)
            {
                cout<<"0";
            }
            else
            {
                for(int z = 0 ; z<lengthTail ; z++)
                {
                    if(i==Snakey[z] && j == Snakex[z])
                    {
                        cout<<"o" ;
                        space = true ;
                    }
                }
            }

            if(!space)
            {
                cout<<" " ;
            }

        }
        cout<<"\n" ;
    }
}

void Input()
{
    if(_kbhit())
    {
        switch(_getch())
        {
            case 'a' :
                dir = LEFT ;
                break ;
            case 'd' :
                dir = RIGHT ;
                break ;
            case 'w' :
                dir = UP ;
                break ;

            case 's' :
                dir = DOWN ;
                break ;

            case 'x' :
                gameOver = true ;
                break ;

            default :
                break ;

        }
    }
}

void Running()
{

    if(lengthTail >=1)
    {
        int prevX = Snakex[0] ;
        int prevY = Snakey[0] ;

        int prev2X  ;
        int prev2Y ;
        Snakex[0] = x ;
        Snakey[0] = y ;
        for(int i = 1 ; i<lengthTail ; i++)
        {
            prev2X = Snakex[i] ;
            prev2Y = Snakey[i] ;

            Snakex[i] = prevX ;
            Snakey[i] = prevY ;

            prevX = prev2X ;
            prevY = prev2Y ;
        }
    }


    switch(dir)
    {
        case LEFT :
            x-=1 ;
            break ;

        case RIGHT :
            x+=1 ;
            break ;

        case UP :
            y-=1 ;
            break ;

        case DOWN :
            y+=1 ;
            break ;

        default :
            break ;

    }


    if(x == width || x==0)
    {
        x = width - x ;
    }
    if(y == height  || y==0)
    {
        y = height - y ;
    }




    for(int i = 0 ; i<lengthTail ; i++)
    {
        if(Snakex[i] == x && Snakey[i] ==y)
        {
            gameOver = true ;
            return ;
        }
    }

    if(x == fruitX && y == fruitY)
    {
        score+=1 ;

        lengthTail+=1 ;


        fruitX = rand()%(width-1) ;
        fruitY = rand()%(height-1);

    }






}

int main()
{
    srand(time(0));
    init() ;
    while(!gameOver)
    {
        Box() ;
        Input() ;
        Running() ;
        Sleep(50) ;
    }
    system("cls") ;

    cout<<"Thanks for playing \n" ;
    cout<<"Your Score is \t" <<score<<"\n" ;
    return 0 ;
}
