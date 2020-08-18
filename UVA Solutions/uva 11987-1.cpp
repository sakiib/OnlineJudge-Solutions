#include<stdio.h>
#include<string.h>
#define MAXD 200010
int N, M, p[MAXD], id[MAXD], num[MAXD], cnt;
long long sum[MAXD];
void init()
{
    int i;
    for(i = 1; i <= N; i ++) id[i] = p[i] = sum[i] = i, num[i] = 1;
    cnt = N;
}
int find(int x)
{
    return p[x] == x ? x : (p[x] = find(p[x]));
}
void Union(int x, int y)
{
    int tx = find(id[x]), ty = find(id[y]);
    if(tx!=ty) {
    p[tx] = ty, num[ty] += num[tx], sum[ty] += sum[tx];
    }
}
void Delete(int x)
{
    int tx = find(id[x]);
    -- num[tx], sum[tx] -= x;
    id[x] = ++ cnt, p[id[x]] = id[x], num[id[x]] = 1, sum[id[x]] = x;
}
void solve()
{
    int i, x, y, op;
    for(i = 0; i < M; i ++)
    {
        scanf("%d", &op);
        if(op == 1)
        {
            scanf("%d%d", &x, &y);
            if(find(id[x]) != find(id[y])) Union(x, y);
        }
        else if(op == 2)
        {
            scanf("%d%d", &x, &y);
            if(find(id[x]) != find(id[y])) Delete(x), Union(x, y);
        }
        else
        {
            scanf("%d", &x);
            printf("%d %lld\n", num[find(id[x])], sum[find(id[x])]);
        }
    }
}
int main()
{
    while(scanf("%d%d", &N, &M) == 2)
    {
        init();
        solve();
    }
    return 0;
}
