#include<bits/stdc++.h>
using namespace std;
int ara[10001];
int main()
{
    int n,count=0,height=0,num;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>num;
        ara[num]++;
    }
    for(int i=0;i<10001;i++)
    {
        if(ara[i])
        count++;
        if(ara[i]>height)
        height=ara[i];
    }
    cout<<height<< " " <<count<<endl;
    return 0;
}
