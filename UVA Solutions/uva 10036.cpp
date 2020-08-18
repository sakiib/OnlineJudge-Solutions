#include<iostream>
#include<list>
#include<string>
#include<cstring>
#include<sstream>
#include<cctype>
#include<string.h>
#include<algorithm>
#include<cmath>
#include<stack>
#include<fstream>
#include<cstdlib>
#include<vector>
#include<map>
#include<utility>
#include<iomanip>
#include<queue>
using namespace std;
#define clr(a) memset(a,0,sizeof(a))
#define fill(a,v) memset(a,v,sizeof(a))
#define PB push_back
#define pi acos(-1.0)
#define eps 1e-9
long n,k,arr[10000+5];
int dp[100+5][10000+5];
vector<long>v1;
vector<long>v2;

bool func(int sum, int position)
{
    bool check=false;

    sum=((sum%k)+k)%k;
    if(position==n)
    {
        if(sum==0) return true;
        else
        return false;
    }

    if(dp[sum][position]!=-1) return dp[sum][position];

    //func(sum+arr[position],position+1);
    //func(sum-arr[position],position+1);
    check=check | func(sum+arr[position],position+1);
    check=check | func(sum-arr[position],position+1);

    return dp[sum][position]=check;
}

int main()
{
    long tc,i;
    cin>>tc;
    while(tc--)
    {

    cin>>n>>k;

    for(i=0;i<n;i++)
    cin>>arr[i];
    memset(dp,-1,sizeof(dp));
    bool ans=func(arr[0],1);
    if(ans)
    cout<<"Divisible"<<endl;
    else
    cout<<"Not divisible"<<endl;

    }

return 0;
}
