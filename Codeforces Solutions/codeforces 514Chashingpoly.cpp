#include <bits/stdc++.h>
using namespace std;
#define endl           '\n'
#define LL             long long
#define ULL            unsigned long long
#define Max(a, b)      a > b ? a : b
#define Min(a, b)      a < b ? a : b
#define all(x)         x.begin(), x.end()
#define fill(a, b)     memset(a, b, sizeof a)

const int N = 6e5 + 5;

map <LL, bool> has;
char s[N];

struct HashString {
    LL Hash[N], Pow[N];
    const int P = 31;
    const LL Mod = 74747474747474747LL;
    void BuildHash(char *s) {
        Hash[0] = s[0], Pow[0] = 1;
        for (int i = 1; s[i]; i++) {
            Pow[i] = (Pow[i - 1] * P) % Mod;
            Hash[i] = (Hash[i - 1] + Pow[i] * s[i]-'a'+1 ) % Mod;
        }
    }
    inline LL GetHash(int l, int r) {
        return l ? Hash[r] - Hash[l - 1] : Hash[r];
    }
    inline bool isMatch(LL h1, char *s) {
        for (int i = 0; s[i]; i++) {
            cout << "main " << h1 << endl;
            LL h2 = (h1 - (s[i]-'a'+1) * Pow[i]) % Mod;
            h2 = (h2 + Mod) % Mod;
            // cout << "h2 : " << h2 << endl;
            for (char ch = 'a'; ch <= 'c'; ch++) {
                if (ch == s[i]) continue;
                // cout <<" && : " << (h2 + ch * Pow[i]) % Mod << endl;
                if (has.count((h2 + (ch-'a'+1) * Pow[i]) % Mod)) return true;
            }
        }
        return false;
    }
} helper;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    while (n--) {
        scanf("%s", s);
        helper.BuildHash(s);
        cout << s << " " << helper.GetHash(0, strlen(s) - 1) << endl;
        has[helper.GetHash(0, strlen(s) - 1)] = true;
    }
    while (m--) {
        scanf("%s", s);
        helper.BuildHash(s);
        LL h = helper.GetHash( 0 , strlen(s)-1 );
        // cout << "sent : " << h << endl;
        puts(helper.isMatch(h, s) ? "YES" : "NO");
    }
    return 0;
}
