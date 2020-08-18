#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    int ara[]={6,8,4,2};
    cin>>n;
    if(n==0) cout<<1;
    else cout<<ara[n%4];
    return 0;
}
