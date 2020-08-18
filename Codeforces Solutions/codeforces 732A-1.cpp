#include<bits/stdc++.h>
using namespace std;
int main()
{
    int price,ruble,i=2,n=10,taka;
    cin>>price>>ruble;

    if(price%10==ruble){
        cout<<1<<endl;
        return 0;
    }
    if(price%10==0){
        cout<<1<<endl;
        return 0;
    }
    taka=price;
    while(1){
        taka=taka+price;
        //cout<<taka<<endl;
        if(taka%10==ruble||taka%10==0){
            cout<<i<<endl;
            return 0;
        }
        else i++;
    }

    return 0;
}
