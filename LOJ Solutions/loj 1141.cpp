#include<bits/stdc++.h>
using namespace std;

vector<bool> isprime(1100,true);
vector<int> factor[1100];

void sieve() {
    isprime[0]=false; isprime[1]=false;
    for(int i=4;i<=1100;i+=2) {
        isprime[i]=false;
    }
    int sq=sqrt(1100);
    for(int i=3;i<=sq;i+=2) {
        if(isprime[i]) {
            for(int j=i*i;j<=1100;j+=2*i) {
                isprime[j]=false;
            }
        }
    }
}
void primefactorize() {
    for(int i=2;i<1100; ) {
        if(isprime[i]) {
            for(int j=2;i*j<1100;j++) {
                factor[i*j].push_back(i);
            }
        }
        if(i==2) i++;
        else i+=2;
    }
}

int a,b;
int dist[10100];
bool visited[10100];

void bfs() {
    dist[a]=0;
    queue<int> Q;
    Q.push(a);
    while(!Q.empty()) {
        int F=Q.front();
        Q.pop();
        for(int i=0;i<factor[F].size();i++) {
            int k=factor[F][i];
            int now=F+k;
            if(dist[now]==-1&&now<=b) {
                dist[now]=dist[F]+1;
                if(now==b) return;
                Q.push(now);
            }
        }
    }
}
int main(int argc,char const *argv[]) {
    sieve();
    primefactorize();
        int tc=1;
        while(scanf("%d%d",&a,&b)) {
        if(a==0&&b==0) break;
        memset(dist,-1,sizeof(dist));
        bfs();
        printf("Case %d: %d\n",tc,dist[b]);
        tc++;
    }
    return 0;
}
