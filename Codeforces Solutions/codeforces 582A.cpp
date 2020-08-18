#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int main()
{
    ll n,num;
    vector<ll> V;
    set<ll> S;
    map<ll,bool> M;

    cin>>n;
    for(int i=0;i<n*n;i++){
        cin>>num;
        V.push_back(num);
        S.insert(num);
    }
    sort(V.rbegin(),V.rend());
    if(S.size()<n){
        for(int i=0;i<n;i++){
            cout<<V[i]<< " ";
        }
        return 0;
    }
    for(int i=0;i<n;i++){
        if(!M[V[i]]){
            cout<<V[i]<< " ";
            M[V[i]]=true;
        }
        else n++;
    }
    return 0;
}
