#include<bits/stdc++.h>
using namespace std;

int n;

struct data {

    string name;
    int Win,gScore,gAgainst,Tie,Loss;
    int Played,Diff,Point;
    data() {}
    data(string n,int W,int S,int A,int T,int L) {
        name=n; Win=W; gScore=S;
        gAgainst=A; Tie=T; Loss=L;
    }
    bool operator<(const data &q) const {
        if(Point!=q.Point) return (Point>q.Point);
        if(Win!=q.Win) return (Win>q.Win);
        if(Diff!=q.Diff) return (Diff>q.Diff);
        if(gScore!=q.gScore) return (gScore>q.gScore);
        if(Played!=q.Played) return (Played<q.Played);
        for(int i=0;i<q.name.size();i++) {
            char x=q.name[i]; char y=name[i];
            if(x>='A'&&x<='Z') x-='A',x+='a';
            if(y>='A'&&y<='Z') y-='A',y+='a';
            return (y<x);
        }
    }
} Team[1005];

int st_int (string &str) {
    int num; stringstream iss(str);
    iss>>num; return num;
}
void process_string (string &str) {
    int a=str.find('#');
    string team1=str.substr(0,a);
    str=str.substr(a+1);
    int b=str.find('@');
    string ga=(str.substr(0,b));
    int g1=st_int(ga);
    str=str.substr(b+1);
    int c=str.find('#');
    string gb=(str.substr(0,c));
    int g2=st_int(gb);
    string team2=str.substr(c+1);

    for(int i=1;i<=n;i++) {
        if(Team[i].name==team1) {
            Team[i].gScore+=g1; Team[i].gAgainst+=g2;
            if(g1>g2) Team[i].Win++;
            if(g1==g2) Team[i].Tie++;
            if(g1<g2) Team[i].Loss++;
        }
        else if(Team[i].name==team2) {
            Team[i].gScore+=g2; Team[i].gAgainst+=g1;
            if(g1>g2) Team[i].Loss++;
            if(g1<g2) Team[i].Win++;
            if(g1==g2) Team[i].Tie++;
        }
    }
}
int main(int argc,char const *argv[]) {
    #ifdef Sakib
    freopen("sakib_in","r",stdin);
    freopne("sakib_out","w",stdout);
    #endif // Sakib
    int t,tc; cin>>t; cin.ignore();
    for(tc=1;tc<=t;tc++) {
        string tour; getline(cin,tour);
        cin>>n; cin.ignore();
        for(int i=1;i<=n;i++) {
            string t_name;
            getline(cin,t_name);
            Team[i].name=t_name; Team[i].Win=0;
            Team[i].gScore=0; Team[i].gAgainst=0;
            Team[i].Tie=0; Team[i].Loss=0;
            Team[i].Played=0; Team[i].Diff=0; Team[i].Point=0;
        }
        int k; cin>>k; cin.ignore();
        for(int i=1;i<=k;i++) {
            string s;
            getline(cin,s);
            process_string(s);
        }
        for(int i=1;i<=n;i++) {
            Team[i].Played=Team[i].Win+Team[i].Loss+Team[i].Tie;
            Team[i].Diff=(Team[i].gScore-Team[i].gAgainst);
            Team[i].Point=Team[i].Win*3+Team[i].Tie*1;
        }
        sort(Team+1,Team+n+1);
        cout<<tour<<endl;
        for(int i=1;i<=n;i++) {
            cout<<i<<") "<<Team[i].name<<" "<<Team[i].Point<<"p, "<<
            Team[i].Played<<"g"<<" ("<<Team[i].Win<<"-"<<Team[i].Tie<<"-"<<
            Team[i].Loss<<"),"<<" "<<Team[i].Diff<<"gd"<<" "<<"("<<
            Team[i].gScore<<"-"<<Team[i].gAgainst<<")"<<endl;
        }
        if(tc!=t) cout<<endl;
    }
    return 0;
}
