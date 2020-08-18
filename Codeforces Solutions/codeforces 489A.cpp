#include<bits/stdc++.h>
using namespace std;

bool check(int *ara,int n){
    for(int i=0;i<n-1;i++){
        if(ara[i+1]<ara[i]) return false;
    }
    return true;
}
int main(){

    int n,ara[10000];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>ara[i];
    }
    if(check(ara,n)){
        cout<<0<<endl;
        return 0;
    }
    int cnt=0,k,i,j,t;
    vector<pair<int,int> > V;

    for(i=0;i<n;i++){
            k=ara[i];
            bool flag=false;
        for(j=i;j<n;j++){
            if(ara[j]<k){
                t=j;
                k=ara[j];
                flag=true;
            }
        }
        if(flag){
            swap(ara[i],ara[t]);
            //cout<<i<< " "<<t<<endl;
            V.push_back(make_pair(i,t));
            cnt++;
        }
    }
    cout<<cnt<<endl;
    for(int i=0;i<V.size();i++){
        cout<<V[i].first<< " "<<V[i].second<<endl;;
    }
    return 0;
}
