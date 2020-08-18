#include<bits/stdc++.h>
using namespace std;
int main()
{
    int first,fav,dif,ans,check;
    cin>>first>>fav>>dif;
    if(dif==0){
        if(first==fav){
            cout<<"YES"<<endl;
            return 0;
        }
        else{
            cout<<"NO"<<endl;
            return 0;
        }
    }
    ans=(fav-first)/dif+1;
    //cout<<ans<<endl;
    if(ans<=0){
        cout<<"NO"<<endl;
        return 0;
    }
    check=first+(ans-1)*dif;
    if(check==fav) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}
