#include <bits/stdc++.h>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;
const int maxN = 1005;
int a[maxN];
int t, tt;
int n, m;
inline bool test(int x)
{
    int sum = 0, cnt = 1;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
        if (sum > x)
        {
           sum = a[i];
           cnt++;
        }
    }
    printf("count=%d\n",cnt);
    return (cnt > m);//(Eita bepar nah//True or false return kortese thats it bruh)//
}
int Bsearch(int l, int r)//(low,high)//
{
    while (l < r)
    {
        int mid = (r + l) / 2;
        if (test(mid))
         l = mid + 1;//(low=mid+1)//
        else
         r = mid;//(high=mid)//
    }
    return r;//(high)//
}
void solve()
{
    scanf("%d %d", &n, &m);
    int l = 0, r = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        if (a[i] > l)
            l = a[i];//Maximum//
        r += a[i];
    }
    int res = Bsearch(l, r);//(maximum,total)//
    printf("Case %d: %d\n", ++tt, res);
}
int main()
{
    scanf("%d", &t);
    while (t--)
    {
      solve();
    }
    return 0;
}
