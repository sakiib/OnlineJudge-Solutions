#include<bits/stdc++.h>
using namespace std;

struct edge
{
    int u, v;
    edge() {}
    edge(int u, int v): u(u), v(v) {}
};

vector<edge>cycle;
vector<int>vec[505];
int col[505], par[505], mark;

void dfs1(int s)
{
    int i, j, k, p;

    col[s] = 1;
    for(i = 0; i < vec[s].size(); i++)
    {
        if(cycle.size()) return;

        j = vec[s][i];
        if(col[j] == 1)
        {
            k = s;
            cycle.push_back(edge(k, j));
            while(par[k] != j)
            {
                cycle.push_back(edge(par[k], k));
                k = par[k];
            }
            cycle.push_back(edge(j, k));
            return;
        }
        else if(col[j] == 0)
        {
            par[j] = s;
            dfs1(j);
        }
    }
    col[s] = 2;
}

void dfs2(int s, int u, int v)
{
    int i, j, k, p;

    col[s] = 1;
    for(i = 0; i < vec[s].size(); i++)
    {
        if(mark) return;

        j = vec[s][i];
        if(s == u && j == v) continue;

        if(col[j] == 1)
        {
            mark = 1;
            return;
        }
        else if(col[j] == 0) dfs2(j, u, v);
    }
    col[s] = 2;
}

void prexit()
{
    printf("YES\n");
    exit(0);
}

int main()
{
    int n, m, i, j, k, p, q, x, y;

    scanf("%d %d", &n, &m);
    for(i = 0; i < m; i++)
    {
        scanf("%d %d", &x, &y);
        vec[x].push_back(y);
    }

    for(i = 1; i <= n; i++)
    {
        if(col[i] == 0)
        {
            dfs1(i);
            if(cycle.size()) break;
        }
    }
    cout << "=====================" << endl;
    for( int i = 0; i < cycle.size(); i++ ) {
        cout << cycle[i].u << " "<< cycle[i].v << endl;
    }
    if(cycle.size() == 0) prexit();

    for(j = 0; j < cycle.size(); j++)
    {
        memset(col, 0, sizeof(col));
        mark = 0;
        int u = cycle[j].u, v = cycle[j].v;

        for(i = 1; i <= n; i++)
        {
            if(col[i] == 0)
            {
                dfs2(i, u, v);
                if(mark) break;
            }
        }
        if(mark == 0) prexit();
    }

    printf("NO\n");

    return 0;
}
