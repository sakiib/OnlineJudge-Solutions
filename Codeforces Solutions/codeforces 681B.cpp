#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ll taka,a=1234567,b=123456,c=1234;
    cin>>taka;
    if(taka%a==0||taka%b==0||taka%c==0){
        cout<<"YES"<<endl;
        return 0;
    }
    if(taka<c){
        cout<<"NO"<<endl;
        return 0;
    }
    for(int i=0;i<=taka/a;i++){
        for(int j=0;j<=taka/b;j++){
            if(((taka-i*a-b*j)%c==0)&&(taka-i*a-b*j>=0)){
               // cout<<i<< " "<<j<<endl;
                cout<<"YES"<<endl;
                return 0;
            }
        }
    }
    cout<<"NO"<<endl;

    return 0;
}
