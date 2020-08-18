#include<bits/stdc++.h>
using namespace std;

bool check(int *ara,int n){
    for(int i=2;i<=n;i++){
        if(ara[i]<=ara[i-1]) return false;
    }
    return true;
}
void res(int *ara,int f,int s){
    while(f<s){
        swap(ara[f],ara[s]);
        f++,s--;
    }
    return;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    int n,ara[10000],f,s;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>ara[i];
    }
    if(check(ara,n)){
        cout<<"0 0"<<endl;
        return 0;
    }
    for(int i=2;i<=n;i++){
        if(ara[i]<ara[i-1]){
            f=i-1; break;
        }
    }
    for(int i=n;i>1;i--){
        if(ara[i]<ara[i-1]){
            s=i; break;
        }
    }
    //cout<<f<< " " <<s<<endl;
    res(ara,f,s);
   /* for(int i=1;i<=n;i++){
        cout<<ara[i]<< " ";
    }*/
    if(check(ara,n)) cout<<f<< " " <<s<<endl;
    else cout<<"0 0"<<endl;
    return 0;
}
