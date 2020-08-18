#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,res,ans;
    cin>>n;
    if(n==1||n==2){
        cout<<1<<endl;
        return 0;
    }
    res=2*(n/3);
    if(n%3>0) res++;
    cout<<res<<endl;
    return 0;
}
