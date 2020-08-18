#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k,ara[10001],extra=0;
    cin>>n>>k;

    for(int i=0;i<n;i++){
        cin>>ara[i];
    }
    for(int i=1;i<n;i++){
        if(ara[i-1]+ara[i]<k){
            extra+=k-(ara[i-1]+ara[i]);
            ara[i]=(k-ara[i-1]);
        }
    }
    cout<<extra<<endl;
    for(int i=0;i<n;i++){
        cout<<ara[i]<< " ";
    }
    return 0;
}
