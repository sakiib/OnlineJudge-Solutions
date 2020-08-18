#include <bits/stdc++.h>
#define LL long long
using namespace std;

LL f(LL x)
{
    LL lo = 0, hi = 1e9+7;
    while (lo<hi) {
        LL m = (lo + hi+1)/2;
        if (m*m<=x)     lo = m;
        else            hi = m-1;
    }
    return lo;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<LL> a;

    for (int p=2; p<=1000000; p++) {
        int rt = sqrt(p);
        if (rt*rt == p) continue;

        LL x = p;
        for (int i=3; pow(p, i) <=2e18; i+=2) {
            x=x*p*p;
            assert(x>0);
            a.push_back(x);
        }
    }

    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());

    //for (int i=0; i<10; i++)    cout<<a[i]<<" ";
    int q;
    cin>>q;
    while (q--)
    {
        LL l, r;
        cin>>l>>r;
        LL ans = f(r) - f(l-1);
        cout << ans << endl;
        ans += upper_bound(a.begin(), a.end(), r) - lower_bound(a.begin(), a.end(), l);
        cout<<ans<<"\n";
    }
}
