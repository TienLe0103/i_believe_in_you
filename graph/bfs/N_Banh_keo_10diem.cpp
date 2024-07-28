/*
 *  @date: 26 . 07 . 2024
 *  @tienle0103
 */

#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <map>
#include <queue>

using namespace std;

#define int            long long
#define fi             first
#define se             second
#define pb             push_back
#define all(x)         x.begin(), x.end()
#define rall(x)        x.rbegin(), x.rend()
#define fr(x, l, r)    for (int x = l; x < r; x++)
#define frr(x, l, r)   for (int x = l; x <= r; x++)
#define fd(x, l, r)    for (int x = l; x >= r; x--)
#define cs             const

typedef double         db;
typedef string         str;
typedef vector<int>    vi;
typedef greater<int>   gi;
typedef map<int, int>  mii;
typedef pair<int, int> ii;

cs int N   = 1e6 + 5;
cs int oo  = 1e18;

int n, m, k, u, v, t, c= oo, res = 0;
vi a[N];
bool vst[N] = {0};

void dfs(int u) {
    vst[u] = 1;
    for (auto v : a[u]) 
        if (!vst[v]) 
            dfs(v);
}   

void solve() {
    frr (i, 1, n) 
        if (!vst[i])
            dfs(i), res++;
    cout << res;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n >> m >> k;
    frr (i, 1, k) {
        int x; cin >> x;
        c = min(c, x);
    }
    frr (i, 1, m) {
        cin >> u >> v >> t;
        if (t >= c) a[u].pb(v), a[v].pb(u);
    }
    solve;
}   