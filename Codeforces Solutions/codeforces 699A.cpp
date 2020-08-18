#include<bits/stdc++.h>
using namespace std;
int ara[200005];
bool found=false;
int main()
{
    int n,ans=1000000000;
    cin>>n;
    string str;
    cin>>str;
    for(int i=0;i<n;i++){
        cin>>ara[i];
    }
    for(int i=0;i<n-1;i++){
        if(str[i]=='R'&&str[i+1]=='L'){
            ans=min(ans,(ara[i+1]-ara[i])/2);
            found=true;
        }
    }
    if(found==true) cout<<ans<<endl;
    else cout<<-1<<endl;
    return 0;
}
