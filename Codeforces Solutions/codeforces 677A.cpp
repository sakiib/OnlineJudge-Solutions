#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,h,num,ans;
    cin>>n>>h;
    ans=n;
    for(int i=0;i<n;i++){
        cin>>num;
        if(num>h) ans++;
    }
    cout<<ans<<endl;
    return 0;
}
