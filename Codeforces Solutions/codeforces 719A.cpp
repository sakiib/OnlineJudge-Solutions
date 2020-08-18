#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,ara[100001];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>ara[i];
    }
    if(ara[n-1]==15){
        cout<<"DOWN"<<endl;
        return 0;
    }
    if(n==1){
        if(ara[0]==0||ara[0]==15)
            cout<<"UP"<<endl;
        else cout<<-1<<endl;
        return 0;
    }
    if(ara[n-1]==0){
        cout<<"UP"<<endl;
        return 0;
    }
    if(ara[n-1]>ara[n-2]){
        cout<<"UP"<<endl;
        return 0;
    }
    if(ara[n-1]<ara[n-2]){
        cout<<"DOWN"<<endl;
        return 0;
    }
    return 0;

}
