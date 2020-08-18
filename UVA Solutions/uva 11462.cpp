#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;
int main()
{
    vector<int>myv;
    int num,n;
    while(scanf("%d",&n)==1&&n!=0)
    {
        for(int i=0;i<n;i++)
        {
          scanf("%d",&num);
          myv.push_back(num);
        }
       for(int i=0;i<n;i++)
       {
           cout << myv[i] <<endl;
       }
    }
    return 0;
}
