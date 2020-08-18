#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,num,zer=0;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>num;
        if(num==0) zer++;
    }
    //cout<<zer<<endl;
    if(n==1&&zer==1){
        cout<<"NO"<<endl;
        return 0;
    }
    else if(n==1&&zer==0){
        cout<<"YES"<<endl;
        return 0;
    }
    else{
        if(zer==1) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
