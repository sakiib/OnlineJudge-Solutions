#include<bits/stdc++.h>
using namespace std;

int main(int argc,char const *argv[]) {
    int n;
    cin>>n;
    int ara[100010];
    vector<pair<int,int> > V;
    for(int i=1;i<=n;i++) {
        cin>>ara[i];
        V.push_back(make_pair(ara[i],i));
    }
    /*for(int i=0;i<V.size();i++) {
        cout<<V[i].first<< " " <<V[i].second<<endl;
    }*/
    set<int> S;
    sort(V.begin(),V.end());
    for(int i=0;i<V.size();i++) {
        //cout<<V[i].first<< " " <<V[i].second<<endl;
        S.insert(V[i].first);
    }
    if(S.size()>=n-1) {
        cout<<"NO"<<endl; return 0;
    }
    else cout<<"YES"<<endl;
    int t;
    int ind=0;
    for(int t=1;t<=3;t++) {
        if(t==1) {
            for(int i=0;i<V.size();i++) {
                cout<<V[i].second<< " ";
            }
            cout<<endl;
        }
        if(t==2) {
            for(int i=0;i<V.size()-1;i++) {
                if(V[i].first==V[i+1].first) {
                     swap(V[i].second,V[i+1].second);
                     ind=i+1;
                     break;
                }
            }
            for(int i=0;i<V.size();i++) {
                cout<<V[i].second<< " ";
            }
            cout<<endl;
        }
        cerr<<ind<<endl;
        if(t==3) {
            for(int i=ind;i<V.size()-1;i++) {
                if(V[i].first==V[i+1].first) {
                    swap(V[i].second,V[i+1].second);
                    cerr<<ind<<endl;
                    break;
                }
            }
            for(int i=0;i<V.size();i++) {
                cout<<V[i].second<< " ";
            }
            cout<<endl;
        }
    }
    return 0;
}
