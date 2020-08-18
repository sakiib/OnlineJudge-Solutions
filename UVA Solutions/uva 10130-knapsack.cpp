#include<algorithm>
#include<iostream>
#include<iterator>
#include<cassert>
#include<sstream>
#include<fstream>
#include<cstdlib>
#include<cstring>
#include<utility>
#include<complex>
#include<string>
#include<cctype>
#include<cstdio>
#include<vector>
#include<bitset>
#include<stack>
#include<queue>
#include<cmath>
#include<deque>
#include<list>
#include<set>
#include<map>

#define sc scanf
#define pf printf
#define ll long long
#define pi 2*acos(0.0)

#define ff first
#define se second
#define inf (1<<30)                                              //infinity value
#define pb push_back
#define mod  1000000007
#define ST(v) sort(v.begin(),v.end())
#define cover(a,d) memset(a,d,sizeof(a))
#define input freopen("in.txt","r",stdin)
#define output freopen("out.txt","w",stdout)
#define maxall(v) *max_element(v.begin(),v.end())
#define minall(v) *min_element(v.begin(),v.end())
#define un(v) ST(v), v.erase(unique(v.begin(),v.end()),v.end())

using namespace std;
int profit[1010][1010],value[1010],weight[1010];
int main()
{

     int knapsack_weight,n,t;
     cin>>t;
     while(t--)
     {
         cin>>n;
         for(int i=1;i<=n;i++)
         {
             cin>>value[i]>>weight[i];
         }
         int a,sum=0;
         cin>>a;
         cover(profit,0);
         for(int i=0;i<a;i++)
         {
             cin>>knapsack_weight;
             for(int i=1;i<=n;i++)
             {
                for(int w=1;w<=knapsack_weight;w++)
                {
                    if(weight[i]>w)
                    {
                        profit[i][w] = profit[i-1][w];
                        }
                    else
                    {
                        if(profit[i-1][w]>profit[i-1][w-weight[i]]+value[i])
                        {
                            profit[i][w] = profit[i-1][w];
                            }
                         else
                         {
                            profit[i][w] = profit[i-1][w-weight[i]]+value[i];
                            }
                    }
                 }
              }
              sum+=profit[n][knapsack_weight];
         }
         pf("%d\n",sum);
     }
    return 0;
}
