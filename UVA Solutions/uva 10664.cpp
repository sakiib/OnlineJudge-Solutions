#include<bits/stdc++.h>
using namespace std;
//maximum subset sum also like this
int val[30];
int k=1;
int check;
int sum;
int dp[30][300];

int solve(int i,int cur) {
    if(i==k+1) return 0; //recursion stops
    if(dp[i][cur]!=-1) return dp[i][cur];
    int op1=0,op2=0;
    if(cur+val[i]<=sum) op1=val[i]+solve(i+1,cur+val[i]);
    op2=solve(i+1,cur);
    dp[i][cur]=max(op1,op2);//amra joto pari oi value er kache jabo
    //tai maximize jodi oi value peye jai oitai return korbo
    return dp[i][cur];
}
int main(int argc,char const *argv[]) {
    int t;
    cin>>t;
    cin.ignore();
    while(t--) {
        string str;
        k=1;
        getline(cin,str);
        stringstream iss(str);
        int s;
        sum=0;
        while(iss>>s) {
            val[k++]=s;
            sum+=s;
        }
        k--;
        if(sum&1) {cout<<"NO"<<endl; continue;}
        sum/=2;
        check=0;
        memset(dp,-1,sizeof(dp));
        check=solve(1,0);
        //cout<<check<<endl;
        if(check==sum) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
