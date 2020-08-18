#include<bits/stdc++.h>
using namespace std;
vector<string>vs;
string test;
int found;
int k=0;
int ans=10000009;

int solve(int n)
{
    for(int i=0;i<n;i++){
            k=0;
        for(int j=0;j<n;j++){
             if(i!=j){
             test=vs[j]+vs[j];
             found=test.find(vs[i]);
             if(found!=string::npos){
               k+=found;
             }
             else{
                return -1;
             }
           }
        }
        if(k<ans) ans=k;
    }
    return ans;
}
int main()
{

    int n,ans;
    string str;
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>str;
        vs.push_back(str);
    }
    ans=solve(n);
    cout<<ans<<endl;
    return 0;
}




