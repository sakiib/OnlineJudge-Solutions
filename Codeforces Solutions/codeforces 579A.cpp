#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,ans=0,a;
    cin>>n;
    while(n!=0){
        a=n%2;
        if(a) ans++;
        n=n/2;
    }
    cout<<ans;
}
