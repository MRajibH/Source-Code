#include <iostream>
using namespace std;
int main(void)
{
    int a[100][100];
     int i,j,v;
      cout<<"How many Vertex :";

      cin>>v;
      int count = 1;
    while(1)
    {





          cout<<"Edge No " <<count<<":";
          cin>>i>>j;


       if(i>v || j>v)
       {
           cout<<"Wrong value "<<endl;
           break;
       }


      if(i==0 && j==0)
      {
          break;
      }
      a[i][j] = 1;
      count++;


    }
    cout<<"Your entered graph is showing below:"<<endl;
     for(int p = 1; p <= v; p++)
      {

          for(int q = 1; q <= v;q++)
          {
              cout<<a[p][q]<<" ";
          }
          cout<<endl;
      }



}
