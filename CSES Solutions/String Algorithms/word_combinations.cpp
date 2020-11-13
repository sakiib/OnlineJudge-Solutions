#include <bits/stdc++.h>
using namespace std;

/**
verdict: TLE in 4(out of 61) cases
probably needs Aho corasick
*/

struct node {
  int cnt;
  bool endmark;
  node* nxt[26];
  node() {
    cnt = 0;
    endmark = false;
    for (int i = 0; i < 26; i++) nxt[i] = NULL;
  }
}*root;

struct trie_string {
  inline int get_id(char c) {
    return c - 'a';
  }
  inline void insert(string &s) {
    int l = s.size();
    node *cur = root;
    for (int i = 0; i < l; i++) {
      int id = get_id(s[i]);
      if (cur -> nxt[id] == NULL) {
        cur -> nxt[id] = new node();
      }
      cur = cur -> nxt[id];
    }
    cur -> endmark = true;
  }
  inline bool find(string &s) {
    int l = s.size();
    node *cur = root;
    for (int i = 0; i < l; i++) {
      int id = get_id(s[i]);
      if (cur -> nxt[id] == NULL) return false;
      cur = cur -> nxt[id];
    }
    return cur -> endmark;
  }
} trie;

const int N = 5e3 + 5;
const int mod = 1e9 + 7;

string s;
int len;
int dp[N];
vector <int> occ[N];

int solve(int idx) {
    if (idx == len) return 1;
    if (idx > len) return 0;
    if (dp[idx] != -1) return dp[idx];
    int ret = 0;
    if ((int)occ[idx].size() == 0) return 0;
    for (auto x: occ[idx]) {
        ret += solve(x + 1);
        if (ret >= mod) ret -= mod;
    }
    return dp[idx] = ret;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    root = new node();
    cin >> s;
    len = s.size();

    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        string st;
        cin >> st;
        trie.insert(st);
    }

    for (int i = 0; i < len; i++) {
        string temp = "";
        for (int j = i; j < len; j++) {
            temp += s[j];
            if (trie.find(temp)) occ[i].push_back(j);
        }
    }

    memset(dp, -1, sizeof(dp));
    cout << solve(0) << "\n";
    return 0;
}
