#include<bits/stdc++.h>
#include<math.h>
#include<iomanip>

using namespace std;
double func(double x)
{
    return exp(-x)-x;
}
double derivFunc(double x)
{
    return -exp(-x)-1;
}
int main(void)
{
    int it;
    double x,xold;
    cout<<"How many Iteration: ";
    cin>>it;
    cout<<"Enter the initial value of x: ";
    cin>>x;
    cout<<setw(14)<<"Root"<<setw(25)<<"Error"<<endl;
    for(int i = 0; i < it; i++)
    {
        double h = func(x)/derivFunc(x);
        double x1=x-h;

        cout<<setw(14)<<x1<<setw(20);
        xold = fabs((x1-x)/x1)*100;
        cout<<setw(24)<<xold<<"%"<<endl;
        x = x1;


    }
}

