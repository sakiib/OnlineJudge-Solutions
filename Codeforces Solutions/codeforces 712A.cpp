#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,ara[100001];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>ara[i];
    }
    for(int i=0;i<n-1;i++){
        ara[i]=ara[i]+ara[i+1];
    }
    for(int i=0;i<n;i++){
        cout<<ara[i]<< " ";
    }
    cout<<endl;
    return 0;
}
