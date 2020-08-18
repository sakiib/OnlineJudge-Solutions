#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int main(){
    ll a,b,cnt=0;
    cin>>a>>b;
    while(a>0&&b>0){
        if(a>=b){
            cnt=cnt+a/b;
            a=a%b;
        }
        else{
            cnt=cnt+b/a;
            b=b%a;
        }
    }
    cout<<cnt;
    return 0;
}
