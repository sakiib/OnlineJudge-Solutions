#include<bits/stdc++.h>
using namespace std;
#define M 1000005

int mp[M], pri[M];

int main()
{
    int i, j, k, p, q, x, y = M;

    for(i = 2; i < M; i++)
    {
        if(mp[i]) continue;
        for(j = i; j < M; j += i) {
            mp[j] = max(mp[j], i);
        }
    }
    for(i = 2; i < M; i++) pri[i] = i-mp[i]+1;

    cin>>x;

    for(i = pri[x]; i <= x; i++)
    {
        if(mp[i] == i) continue;
        y = min(y, pri[i]);
    }
    cout<<y<<endl;

    return 0;
}
