#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main()
{
    ll l;
    cin>>l;
    if(l<3){
        cout<<-1<<endl;
        return 0;
    }
    if(l%2==0){
        l=l*l;
        l=l/4;
        cout<<l-1<< " "<<l+1<<endl;
    }
    else if(l%2!=0){
        l=l*l;
        l+=1;
        l=l/2;
        cout<<l-1<< " "<<l<<endl;
    }
    return 0;
}
