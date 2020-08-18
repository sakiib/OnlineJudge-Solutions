#include<bits/stdc++.h>
using namespace std;

const int N=110;

int r,c;
string pres;
string str[N];
char ch;
set<char> S;

int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};

bool valid(int nx,int ny) {
    return (nx>=0&&ny>=0&&nx<r&&ny<c);
}
void get_ans(int x,int y) {
    for(int i=0;i<4;i++) {
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(valid(nx,ny)&&str[nx][ny]!='.'&&str[nx][ny]!=ch) {
            S.insert(str[nx][ny]);
        }
    }
}
int main(int argc,char const *argv[]) {
    cin>>r>>c>>pres;
    for(int i=0;i<r;i++) {
        cin>>str[i];
    }
    ch=pres[0];
    for(int i=0;i<r;i++) {
        for(int j=0;j<c;j++) {
            if(str[i][j]==ch) {
                get_ans(i,j);
            }
        }
    }
    //for(auto c:S) cout<<c<<" ";
    //cout<<endl;
    int ans=(int)(S.size());
    cout<<ans<<endl;
    return 0;
}
