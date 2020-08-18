#include<bits/stdc++.h>
using namespace std;

map<int,int> M;
set<int> S;

void primefact(int p){
    while(p%2==0){
        p=p/2;
        //M[2]++;
        S.insert(2);
    }
    for(int i=3;i<=p/2;i+=2){
        while(p%i==0){
            p=p/i;
            //M[i]++;
            S.insert(i);
        }
    }
    if(p>1) //M[p]++;
        S.insert(p);
}
int main(){
    int p,ans=1;
    cin>>p;
    p--;
    primefact(p);
    set<int> :: iterator it;
    for(it=S.begin();it!=S.end();it++){
        int z=*it;
        cout<<z<<endl;
        ans*=(1-1/z);
    }
    ans*=p;
    cout<<ans<<endl;
    return 0;
}
