#include <iostream>
using namespace std;

int main(void)
{
    int x,y;
    cin>>x>>y;


    while(y != 0)
    {
        if(y <0)
        {
            y++;
            x--;
        }
        else
            { x++;
            y--; }
    }
    cout<<x;
}

