#include<bits/stdc++.h>
using namespace std;

int main(int argc,char const *argv[]) {
    int n;
    cin>>n;
    for(int i=0;i<n;i++) {
        string str;
        cin>>str;
    }
    int t,x,y;
    t=n*(n-1)/2;
    //cerr<<"T :"<<t<<endl;
    map<string,int> M;
    for(int i=0;i<t;i++) {
        string a,b="",c="";
        cin>>a;
        bool found=false;
        for(int i=0;i<a.size();i++) {
            if(a[i]=='-'){
                found=true; continue;
            }
            if(!found) b+=a[i];
            if(found) c+=a[i];
        }
        //cout<<a[0]<<" "<<a[1]<<" "<<a[2]<<endl;
        scanf("%d:%d",&x,&y);
        //printf("%d %d\n",x,y);
        if(x>y) M[b]+=3;
        else if(x<y) M[c]+=3;
        else if(x==y) {
            M[b]+=1;
            M[c]+=1;
        }
    }
    vector<pair<int,string> > V;
    map<string,int> :: iterator it;
    for(it=M.begin();it!=M.end();it++) {
        V.push_back(make_pair(it->second,it->first));
    }
   /*for(int i=0;i<V.size();i++) {
        cout<<V[i].first<< " " <<V[i].second<<endl;
    }*/
    sort(V.rbegin(),V.rend());
   /*for(int i=0;i<V.size();i++) {
        cout<<V[i].first<< " " <<V[i].second<<endl;
    }*/
    set<string> S;
    for(int i=0;i<n/2;i++) {
        S.insert(V[i].second);
    }
    set<string> :: iterator itt;
    for(itt=S.begin();itt!=S.end();itt++) {
        string ans=*itt;
        cout<<ans<<endl;
    }
    return 0;
}
