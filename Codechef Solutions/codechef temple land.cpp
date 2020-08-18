#include<bits/stdc++.h>
using namespace std;

bool solve(vector<int> &V,int n)
{
    bool left=true;
    bool right=true;

   /* for(int i=0;i<V.size();i++){
        cout<<V[i]<< " ";
    }*/

    if(V[0]!=1||V[n-1]!=1) return false;

    if(n%2==0) return false;

    for(int i=0;i<V.size()/2;i++){
        if(V[i]+1==V[i+1]) continue;
        else return false;
    }
    for(int i=V.size()/2;i<V.size()-1;i++){
        if(V[i]-1==V[i+1]) continue;
        else return false;
    }
    if(left&&right) return true;

}
int main()
{
    int t,n,num;

    scanf("%d",&t);

    while(t--){
        vector<int> V;

        scanf("%d",&n);

        for(int i=0;i<n;i++){
            scanf("%d",&num);
            V.push_back(num);
        }

      if(solve(V,n)) puts("yes");

      else puts("no");
    }
    return 0;
}
