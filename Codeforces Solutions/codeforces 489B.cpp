#include<bits/stdc++.h>
using namespace std;

bool found=false;
bool used[100000];

int main()
{
    int b,g,cnt=0,m,n;
    vector<int> B,G;

    cin>>b;

    memset(used,false,sizeof(used));

    for(int i=0;i<b;i++){
        cin>>n;
        B.push_back(n);
    }

    cin>>g;
    for(int i=0;i<g;i++){
        cin>>m;
        G.push_back(m);
    }

    sort(B.begin(),B.end());
    sort(G.begin(),G.end());

  /*  for(int i=0;i<b;i++){
        cout<<B[i]<< " ";
    }
    cout<<endl;

    for(int i=0;i<g;i++){
        cout<<G[i]<< " ";
    }
    cout<<endl;*/

    for(int i=0;i<b;i++){
        for(int j=0;j<g;j++){
            if(abs(B[i]-G[j])<=1&&!used[G[j]]){
                cnt++;
                G[j]=100000;
               // cout<<abs(B[i]-G[j])<<endl;
                break;
            }
        }
    }

    cout<<cnt;

    return 0;
}
