#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    if(n==6){
        cout<<1<< " "<<2<<endl;
        return 0;
    }
    if(n==5||n==4||n==3||n==2){
        cout<<0<< " "<<2<<endl;
        return 0;
    }
    if(n==1){
        cout<<0<<" "<<1<<endl;
        return 0;
    }
    if(n==7){
        cout<<2<< " "<<2<<endl;
        return 0;
    }
    int mn=2*(n/7);
    if(n%7>5) mn++;
    int mx=2*(n/7);
    if(n%7>2) mx+=2;
    else mx+=(n%7);
    cout<<mn<< " "<<mx;
    return 0;


}
