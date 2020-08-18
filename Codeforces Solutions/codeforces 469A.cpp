#include<bits/stdc++.h>
using namespace std;
int main(){

    int n,x,y,A[10000],B[10000];
    cin>>n;
    bool check[1000];
    cin>>x;
    for(int i=0;i<x;i++){
        cin>>A[i];
        check[A[i]]=true;
    }
    cin>>y;
    for(int i=0;i<y;i++){
        cin>>B[i];
        check[B[i]]=true;
    }
    for(int i=1;i<=n;i++){
        if(!check[i]){
            cout<<"Oh, my keyboard!"<<endl;
            return 0;
        }
    }
    cout<<"I become the guy."<<endl;
    return 0;
}
