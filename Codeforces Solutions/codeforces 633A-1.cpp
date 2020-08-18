#include<bits/stdc++.h>
using namespace std;
int main()
{
    int a,b,x;
    cin>>a>>b>>x;
    for(int i=0;i*a<=x;i++){
        for(int j=0;j*b<=x;j++){
            if(x==a*i+b*j){
                cout<<"Yes"<<endl;
                return 0;
            }
        }
    }
    cout<<"No"<<endl;
    return 0;
}
