#include<bits/stdc++.h>
using namespace std;

#define ll long long int

ll A[2000010],B[2000010];

int main(){
    ll n,k,q,a,b,l,r;
    cin>>n>>k>>q;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        A[a]++; A[b+1]--;
    }
    for(int i=0;i<=200000;i++){
        A[i]+=A[i-1];
    }
    /*for(int i=0;i<100;i++){
        cout<<A[i]<< " ";
    }*/
    for(int i=0;i<=200000;i++){
        if(A[i]>=k) A[i]=1;
        else A[i]=0;
    }
    for(int i=0;i<=200000;i++){
        A[i]+=A[i-1];
    }
    /*for(int i=0;i<100;i++){
        cout<<A[i]<< " ";
    }*/
    while(q--){
        cin>>l>>r;
        cout<<A[r]-A[l-1]<<endl;
    }
    return 0;
}
