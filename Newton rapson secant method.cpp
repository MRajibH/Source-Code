#include<iostream>
#include<iomanip>
#include<math.h>
using namespace std;
double f(double x)
{
    return x*x*x+3*x*x+12*x+8;
}
int main(void)
{
    int it;
    double x,x1,x2,h,ir;
    cout<<"Enter the  value of x0: ";
    cin>>x;
    cout<<"Enter the  value of x1: ";
    cin>>x1;
    cout<<"How many Iteration: ";
    cin>>it;
    cout<<setw(20)<<"APPROX. ROOT"<<setw(20)<<"ERROR"<<endl;
    for(int i = 0; i < it; i++)
    {
        h = f(x1)*(x1-x);
        ir = f(x1)-f(x);
        x2 = x1-(h/ir);

        cout<<setw(20)<<x2;
        double r = fabs((x2-x1)/x2)*100;
        cout<<setw(20)<<r<<endl;
        x = x1;
        x1 = x2;
    }
}
