#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,x;
    cin>>a>>b>>x;
    if(a==x||b==x||x%a==0||x%b==0||x%(a+b)==0){
        cout<<"Yes"<<endl;
        return 0;
    }
    while(a+b<=x){
        x-=(a+b);
        if(x%a==0||x%b==0||x%(a+b)==0){
            cout<<"Yes"<<endl;
            return 0;
        }
    }
    if(x==0) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}

