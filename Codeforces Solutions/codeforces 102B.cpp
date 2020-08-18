#include<bits/stdc++.h>
using namespace std;
int solve(string &str)
{
    if(str.size()==1) return 0;

    int sum=0,cnt=1,temp;

    for(int i=0;i<str.size();i++){
        sum+=str[i]-'0';
    }
    while(sum>9){
        temp=0;
        while(sum){
            temp+=sum%10;
            sum=sum/10;
        }
        sum=temp;
        cnt++;
    }
    return cnt;
}
int main()
{
    int ans;
    string str;

    cin>>str;

    ans=solve(str);

    cout<<ans<<endl;
    return 0;
}
