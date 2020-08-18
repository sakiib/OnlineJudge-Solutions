#include <bits/stdc++.h>
using namespace std;

#define SIZE 11
#define BOUNDARY(x,y) ((x>=0 && x<row) && (y>=0 && y<col))

char grid[SIZE][SIZE];
bool visited[SIZE][SIZE];
int row,col;
char last;

int X[]={0, 0, 1, -1};
int Y[]={1, -1, 0,  0};

struct point
{
    int x;
    int y;
    int z;
    point(){}
    point(int x, int y, int z)
    {
        this->x=x;
        this->y=y;
        this->z=z;
    }
};

int bfs(point p, char current)
{
    if(current==last) return p.z;
    memset(visited, 0, sizeof visited);
    queue <point> qq;
    qq.push(p);

    while(!qq.empty())
    {
        p=qq.front();
        qq.pop();

        for(int i=0; i<4; i++)
        {
            int aa=p.x+X[i];
            int bb=p.y+Y[i];

            if(!BOUNDARY(aa, bb)) continue;

            if(grid[aa][bb]==current+1)
            {
                return bfs(point(aa, bb, p.z+1), current+1);
            }
            else if(!visited[aa][bb] && (grid[aa][bb]=='.' || isalpha(grid[aa][bb])) && grid[aa][bb]<=current )
            {
                visited[aa][bb]=true;
                qq.push(point(aa, bb, p.z+1));
            }
        }
    }
    return -1;
}
int main()
{
    int t;
    scanf("%d", &t);

    for(int cs=1; cs<=t; cs++)
    {
        int n;
        memset(visited, 0, sizeof visited);
        int cnt=0,mv=0, a, b;
        scanf("%d", &n);
        row=col=n;
        last='A';

        for(int i=0; i<n; i++)
        {
            scanf("%s", grid[i]);
            for(int j=0; j<n; j++)
            {
                if(grid[i][j]!='.' && grid[i][j]!='#')
                {
                    last=max(last, grid[i][j]);
                }
                if(grid[i][j]=='A')
                {
                    a=i;
                    b=j;
                }
            }
        }

        int res=bfs(point(a, b, 0), 'A');

        if(res>=0)
        {
            printf("Case %d: %d\n", cs, res);
        }
        else
        {
            printf("Case %d: Impossible\n", cs);
        }
    }
    return 0;
}
