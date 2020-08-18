#include<bits/stdc++.h>
using namespace std;
char bin[100005];
int tree[350005];
void update(int node, int b, int e, int i, int j)
{
    if(e < i || b > j)
        return;
    if(b >= i && e <= j)
    {
        tree[node]++;
        return;
    }
    int mid = (b+e)/2;
    update(2*node, b, mid, i, j);
    update(2*node+1, mid+1, e, i, j);
    return;
}
int query(int node, int b, int e, int x)
{
    if(b == e && b == x)
        return tree[node];
    if(x < b || x > e)
        return 0;
    int mid = (b+e)/2;
    return query(2*node, b, mid, x)+query(2*node+1, mid+1, e, x)+tree[node];
}
int main()
{
    int t, k, i, j, p, q, x, y;
    char ch;
    scanf("%d", &t);
    for(k = 1; k <= t; k++)
    {
        for(i = 0; i < 350005; i++)
            tree[i] = 0;
        scanf("%s", bin);
        p = strlen(bin);
        //printf("%d\n", p);
        scanf("%d", &q);
        printf("Case %d:\n", k);
        for(i = 0; i < q; i++)
        {
            scanf(" %c", &ch);
            //printf("%c\n", ch);
            if(ch == 'I')
            {
                scanf("%d %d", &x, &y);
                //printf("%d %d\n", x, y);
                update(1, 1, p, x, y);
            }
            else
            {
                scanf("%d", &x);
                j = query(1, 1, p, x);
                cerr<<"== "<<j<<endl;
                if((j%2 && bin[x-1] == '0') || (j%2 == 0 && bin[x-1] == '1'))
                {
                    printf("1\n");
                }
                else
                    printf("0\n");
            }
        }
    }
    return 0;
}
