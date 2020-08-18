#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,c,mis=0,cis=0;
    cin>>n;
    while(n--){
        cin>>m>>c;
        if(m>c) mis++;
        else if(m<c) cis++;
    }
    if(mis>cis) cout<<"Mishka"<<endl;
    else if(cis>mis) cout<<"Chris"<<endl;
    else cout<<"Friendship is magic!^^"<<endl;
    return 0;
}
