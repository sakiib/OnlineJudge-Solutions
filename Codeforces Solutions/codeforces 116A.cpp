#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,a,b,now=0,mx=0;
    cin>>n;
    while(n--){
        cin>>a>>b;
        now-=a;
        now+=b;
        mx=max(mx,now);
    }
    cout<<mx<<endl;
    return 0;
}
