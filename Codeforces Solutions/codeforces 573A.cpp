#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,num;
    cin>>n;
    vector<int> V;
    for(int i=0;i<n;i++){
        cin>>num;
        V.push_back(num);
    }
    for(int i=0;i<V.size();i++){
        while(V[i]%2==0){
            V[i]/=2;
        }
        while(V[i]%3==0){
            V[i]/=3;
        }
    }
    set<int> S;
    for(int i=0;i<V.size();i++){
        S.insert(V[i]);
    }
    if(S.size()==1) puts("Yes");
    else puts("No");
    return 0;
}
