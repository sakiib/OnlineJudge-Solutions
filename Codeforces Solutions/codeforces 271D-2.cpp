#include <bits/stdc++.h>

using namespace std;
typedef unsigned long  long LL;

const int p = 31; // for lower case alpha only prime
const int mod = 1e9+9; // mod value
// Better to precalc the Powers of prime p
LL POW[ 100005 ]; // sizeof inpust string

void CalcPower( ) {
    POW[0] = 1;
    for( int i = 1; i <= 2000; i++ ) POW[i] = (POW[i-1]*p);
}
LL Compute_Hash( string s ) {
    LL HashVal = 0;
    for( int i = 0; i < s.size(); i++ ) {
       HashVal = ( HashVal+( s[i]-'a'+1 )*POW[i] );
    }
    return HashVal;
}
int main()
{
    set <long long> ans;
    string s;
    cin >> s;
    char c[26];
    CalcPower();
    for (int i = 0; i < 26; i++) cin >> c[i];
    int k;
    cin >> k;
    for (int i=0; i < s.size(); i++)
    {
        long long hash=0;
        int m = k;
        string temp = "";
        for (int j=i; j < s.size(); j++)
        {
            if (c[s[j] - 'a'] == '0')
            {
                if (!m) break;
                m--;
            }
            temp += s[j];
            hash = Compute_Hash( temp );
            //hash = hash*29 + s[j] - 'a' + 1;
            ans.insert(hash);
        }
    }
    cout << ans.size();
    return 0;
}
