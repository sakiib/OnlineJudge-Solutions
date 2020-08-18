#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(int argc,char const *argv[]) {
    ios_base::sync_with_stdio(false); cin.tie(0);

    string str;
    cin>>str;
    ll query;
    cin>>query;

    while(query--) {
        ll l,r,t;
        cin>>l>>r>>t;
        l--,r--;
        t%=(r-l+1);
        string temp="";
        for(ll i=l;i<=r;i++) {
            temp+=str[i];
        }
        //cerr<<temp<<endl;
        ll len=temp.size();
        string x="";
        while(t!=0) {
           x+=temp[len-1];
           //cerr<<x<<endl;
           temp.erase(len-1,1);
           len--;
           t--;
        }
        reverse(x.begin(),x.end());
        x+=temp;
        ll j=0;
        //cerr<<"x "<<x<<endl;
        for(int i=l;i<=r;i++) {
            str[i]=x[j++];
        }
        //cout<<"after "<<str<<endl;
    }
    cout<<str<<endl;
    return 0;
}
