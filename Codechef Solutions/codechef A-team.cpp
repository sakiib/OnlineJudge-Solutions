#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t,m,n,a,b;
    cin>>t;
    for(int i=0;i<t;i++){
        set<int> S;
        cin>>m>>n;
        while(n--){
            cin>>a>>b;
            S.insert(a);
            S.insert(b);
        }
       //cout<<S.size()<<endl;
        m=m-S.size();
        if(m==0||m%2==0) puts("yes");
        else puts("no");
        S.clear();
    }
    return 0;

}
