#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

/**
Number of subarray whose avrg >= k
*/

struct Treap{
    struct node{
        ll p, data, cnt;
        node* l, *r;

        node(ll prior, ll d) : data(d), p(prior), cnt(1), l(NULL), r(NULL){}
    };

    typedef node* pnode;

    int get(pnode r){
        return r? r -> cnt : 0;
    }

    void upd_cnt(pnode root){
        if(root)
            root -> cnt = 1 + get(root -> l) + get(root -> r);
    }

    void split(pnode root, pnode &l, pnode &r, ll x){
        if(!root) return void(l = r = NULL);

        if(root -> data > x) split(root -> l, l, root -> l, x), r = root;
        else split(root -> r, root -> r, r, x), l = root;

        upd_cnt(root);
    }

    void merge(pnode &root, pnode lft, pnode rgt){
        if(!lft || !rgt) return void(root = lft? lft : rgt);

        if(lft -> p > rgt -> p) merge(lft -> r, lft -> r, rgt), root = lft;
        else merge(rgt -> l, lft, rgt -> l), root = rgt;

        upd_cnt(root);
    }

    pnode insert(pnode root, pnode cur){
        if(!root) return cur;
        if(root -> p < cur -> p){
            pnode t1, t2;
            split(root, t1, t2, cur -> data);
            cur -> l = t1, cur -> r = t2;

            upd_cnt(cur);
            return cur;
        }
        if(root -> data > cur -> data) root -> l = insert(root -> l, cur);
        else root -> r = insert(root -> r, cur);
        upd_cnt(root);
        return root;
    }

    void insert(ll data){
        pnode cur = new node(rand(), data);
        root = insert(root, cur);
    }

    ll query(ll x){
        pnode t1, t2;
        split(root, t1, t2, x);
        ll ans = get(t1);
        merge(root, t1, t2);
        return ans;
    }

    pnode root;
    Treap() : root(NULL){}
};

int main(){
    ios_base :: sync_with_stdio(0);
    cin.tie(0);

    ll n, k;
    scanf("%lld %lld",&n ,&k);
    vector<ll> v(n);
    for(int j = 0; j < n; j++) scanf("%lld",&v[j]), v[j] -= k;

    Treap t;
    ll pre = 0;
    t.insert(pre);

    ll ans = 0;
    for(int j = 0; j < n; j++){
        pre += v[j];
        ans += t.query(pre);
        t.insert(pre);
    }
    cout << ans << endl;
    return 0;
}
