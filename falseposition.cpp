 #include <iostream>
#include<iomanip>
#include<math.h>
using namespace std;

double f(double x)
{
    /// Returns the value of the function
    return -0.6*x*x+2.4*x+5.5;
}

int main(void)
{
    double a = 5;
    double b= 10;
    double xm,r,xmold;
    int itn;



    if (f(a) * f(b) < 0)

    {cout<<"Boundary is valid"<<endl;
    cout<<"How many Iteration :";
    cin>>itn;
      cout<<setw(20)<<"a"<<setw(20)<<"b"<<setw(20)<<"xm"<<setw(20)<<"f(xm)"<<setw(20)<<"Error"<<endl;
    for(int i = 0 ;i < itn; i++)


    {
          xmold = xm;
          xm = (b*f(a)-a*f(b))/(f(a)-f(b));

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

