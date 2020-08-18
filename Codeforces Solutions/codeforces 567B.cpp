#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,ans=0,cur=0;
    cin>>n;
    set<int> S;
    for(int i=0;i<n;i++){
        string a;
        int x;
        cin>>a>>x;
        if(a=="+"){
            S.insert(x);
        }
        else{
            if(S.find(x)==S.end()){
                ans++;
            }
            else S.erase(x);
        }
        ans=max(ans,(int)S.size());
    }
   cout<<ans<<endl;
   return 0;
}
