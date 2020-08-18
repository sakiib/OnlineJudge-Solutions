#include<bits/stdc++.h>
using namespace std;

vector<string> V;

vector<string> check(int num) {
    string str="";
    while(num!=0) {
        int a=num%2;
        num/=2;
        str+=(a+'0');
    }
    reverse(str.begin(),str.end());
    string temp=str;
    while(temp.size()<8) {
        temp='0'+str;
        str=temp;
    }
    V.push_back(str);
    return V;
}
int main(int argc,char const *argv[]) {
    int n,m,k;
    cin>>n>>m>>k;
    int ara[100010];
    for(int i=1;i<=m+1;i++) {
        cin>>ara[i];
    }
    /*for(int i=1;i<=m+1;i++) {
        check(ara[i]);
    }*/
    vector<string> ans;
    for(int i=1;i<=m+1;i++) {
        ans=check(ara[i]);
    }
    for(int i=0;i<ans.size();i++) {
        cout<<ans[i]<< " ";
    }
    cout<<endl;
    return 0;
}
