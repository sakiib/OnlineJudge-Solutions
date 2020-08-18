#include<bits/stdc++.h>
using namespace std;
struct node{int x,y,f;};
int n,m,i,j,x,y,jump[][2]={{1,0},{0,1},{0,-1},{-1,0}},f,u,v,dis[1024][1024],l,r;
char s[1024][1024];
queue<node>q;
int main(){
	memset(dis,0x3f3f3f3f,sizeof dis);
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++){
		scanf("%s",s[i]);
		for(j=0;j<m&&f<2;j++)
			if(s[i][j]=='S')
				x=i,y=j,f++;
			else if(s[i][j]=='T')
				l=i,r=j,f++;

	}
	for(i=0;i<4;i++){
		node a={x,y,i};
		q.push(a);
	}
	dis[x][y]=0;
	while(q.size()){
		node a=q.front();
		q.pop();
		for(i=0;i<4;i++){
			u=a.x+jump[i][0],v=a.y+jump[i][1];
			if(u>=0&&u<n&&v>=0&&v<m&&s[u][v]!='*'&&dis[u][v]>=dis[a.x][a.y]+(a.f==i?0:1)){
                cerr<<"u : "<<dis[u][v]<< " " <<dis[a.x][a.y]<<endl;
				dis[u][v]=dis[a.x][a.y]+(a.f==i?0:1);
                cerr<<"d : "<<dis[u][v]<< " " <<dis[a.x][a.y]<<endl;
				node b={u,v,i};
				q.push(b);
			}
		}
	}
	printf("%s\n",dis[l][r]<3?"YES":"NO");
}
