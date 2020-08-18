#include <bits/stdc++.h>
using namespace std;

vector< pair<long long,long long> > V;

int main()
{
    long long N, ll = 0,rr = 0,l,r;

    cin >> N;

    for(int k = 0; k < N; k++){
        cin >> l >> r;
        ll+=l;
        rr+=r;
        V.push_back({l,r});
    }
    /*//Printing Vector Pair//
    for(int k=0;k<V.size();k++){

        cout<<V[k].first<< " " <<V[k].second<<endl;
    }
    */
    long long maxx = abs(ll-rr),maxxi = 0;

    for(int k = 0; k < N; k++){
        long long ff = V[k].first;
        long long ss = V[k].second;

        long long tL = ll;
        long long tR = rr;

        tL-=ff;tL+=ss;
        tR-=ss;tR+=ff;

        long long res = abs(tL-tR);

        if(res >= maxx){
            //cout << res << endl;
            maxx = res;
            maxxi = k+1;
        }

    }

    cout << maxxi << endl;
    return 0;
}
