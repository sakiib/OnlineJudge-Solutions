#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll oleg,g_1,g_2,pos,n,cnt=0;
int main()
{
    cin>>oleg>>g_1>>g_2;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>pos;
        if(pos>g_1&&pos<g_2) cnt++;
    }
    cout<<cnt;

    return 0;
}
