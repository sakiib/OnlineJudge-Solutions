#include<bits/stdc++.h>
using namespace std;

int main(){

    int n,a,b,c,num;
    cin>>n;
    vector<int> V;
    for(int i=1;i<=3;i++){
        cin>>num;
        V.push_back(num);
    }
    sort(V.begin(),V.end());

    a=V[0],b=V[1],c=V[2];
    int mx=0;
    for(int i=0;i*c<=n;i++){
        for(int j=0;j*b<=n;j++){
            for(int k=0;k*a+j*b+i*c<=n;k++){
                if(k*a+j*b+i*c==n){
                    mx=max(k+j+i,mx);
                    if(mx==n){
                        cout<<mx<<endl; return 0;
                    }
                   // cout<<i<< " " <<j<< " "<<k<<endl;
                   // return 0;
                }
            }
        }
    }
    cout<<mx<<endl;
    return 0;
}
