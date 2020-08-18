#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    int ans=0;
    int k=1;
    cin>>n;
    while(n!=0){
        if(n%10==4) ans+=k;
        else ans+=2*k;
        k*=2;
        n=n/10;
    }
    cout<<ans<<endl;
    return 0;
}
