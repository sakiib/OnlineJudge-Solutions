#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main()
{
    ll n,num,sum=0,res=0,inf=99999999999;
    cin>>n;
    while(n--){
        cin>>num;
        if(num>0) sum+=num;
        if(abs(num)%2==1){//we know even-odd=odd tai,eita ber kore rakhi
            inf=min(inf,abs(num));
            //cout<<inf<<endl;
        }
    }
    if(sum%2==1) cout<<sum;//jodi odd hoy then etai max ans
    else cout<<sum-inf<<endl;//jodi even hoy then min odd theke bad diye max odd ber kori
    return 0;
}
