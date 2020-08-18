#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    int m,n,a,b;
    int A[100001],B[100001];

    cin>>m>>n;
    cin>>a>>b;

    vector<int> K,X;

    for(int i=1;i<=m;i++){
        cin>>A[i];
        if(i<=a) K.push_back(A[i]);//egulo khujbo
    }

    for(int i=1;i<=n;i++){
        cin>>B[i];
    }
    for(int i=n;;i--){
        if(i==n-b) break;
        X.push_back(B[i]);//etar moddhe khujbo
    }

    sort(X.begin(),X.end());
    for(int i=0;i<K.size();i++){
        if(K[i]>=X[0]){
            puts("NO");
            return 0;
        }
    }

    puts("YES");

   /* for(int i=0;i<K.size();i++){
        cout<<K[i]<< " ";
    }
    cout<<endl;
    for(int i=0;i<X.size();i++){
        cout<<X[i]<< " ";
    }
    cout<<endl;*/

    return 0;
}

