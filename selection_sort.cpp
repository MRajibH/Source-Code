///Algorithm provided by Md. Shamsujjoha Sir(Senior Lecturer, East West University,Bangladesh).
///IDE: Code::Blocks
#include<iostream>
#include<vector>
using namespace std;
vector <int> A;

int main(void)
{
    int limit,a,k;
    cout<<"How many numbers? ";
    cin>>limit;
    for (int i = 0;i < limit;i++)
    {
        cin>>a;
        A.push_back(a);
    }
     for (int i = 0;i < A.size()-1;i++)
    {
        k = i;
        for (int j = i+1; j < A.size();j++)
        {
            if (A[j] < A[k])
            {
                k = j;
            }
        }
        if (k != i)
        {
            swap (A[i] , A[k]);
        }
    }
    cout<<"Your inputted Numbers in descending order : ";
   for (int i = 0;i < limit;i++)
    {
       cout<<A[i]<<" ";
    }

}
