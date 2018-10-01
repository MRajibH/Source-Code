#include <iostream>
#include<iomanip>
#include<math.h>
using namespace std;

double f(double x)
{
    /// Returns the value of the function
    return x*x*x-0.165*x*x+0.0003993;
}

int main(void)
{
    double a = 0;
    double b= 0.11;
    double xm,r,xmold;
    int itn;

    {
    if (f(a) * f(b) < 0)

    {cout<<"Boundary is valid"<<endl;
    cout<<"How many Iteration :";
    cin>>itn;
      cout<<setw(20)<<"a"<<setw(20)<<"b"<<setw(20)<<"xm"<<setw(20)<<"f(xm)"<<setw(20)<<"Error"<<endl;
    for(int i = 0 ;i < itn; i++)


    {
          xmold = xm;
          xm = (a+b)/2;

         if (xm != 0 )
         {
            r = fabs((xm- xmold)/xm)*100;
         }

         if (f(xm) < 0)
         {
               b = xm;
         }
         if (f(xm) > 0)
         {
             a = xm;
         }
         if (i==0)
         {
             cout<<setw(20)<<a<<setw(20)<<b<<setw(20)<<xm<<setw(20)<<f(xm)<<setw(20)<<"-------"<<endl;
         }
           else

      {
         cout<<setw(20)<<a<<setw(20)<<b<<setw(20)<<xm<<setw(20)<<f(xm)<<setw(20)<<r<<endl;
      }


    }

    }


}
}
