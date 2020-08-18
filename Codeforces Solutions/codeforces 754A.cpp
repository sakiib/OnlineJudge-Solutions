#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n,a[200],cc = 0,sum = 0,pos;

    cin >> n;

    for(int k = 0; k < n; k++)
    {
        cin >> a[k];

        if(a[k] == 0)cc++;

        sum+=a[k];

        if(sum)
        {
            pos = k + 1;
        }

    }

    if(cc == n)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;

        if(pos == n)
        {
            cout << "1" << endl;
            cout << "1 " << n << endl;
        }
        else
        {
            cout << "2" << endl;
            cout << "1 " << pos << endl;
            cout << pos+1 << " " << n << endl;
        }

    }

  return 0;
}
