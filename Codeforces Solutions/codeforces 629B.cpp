#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,from,to,male[100001]={0},fem[100001]={0},ans,mn=-1;
    cin>>n;
    while(n--){
        string a;
        cin>>a>>from>>to;
        if(a=="M"){
            for(int i=from;i<=to;i++){
                male[i]++;
            }
        }
        else{
            for(int i=from;i<=to;i++){
                fem[i]++;
            }
        }
    }
    for(int i=1;i<=366;i++){
        ans=min(male[i],fem[i]);
        if(ans>mn) mn=ans;
    }
    cout<<mn*2<<endl;
    return 0;
}
