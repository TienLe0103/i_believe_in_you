/*
 *  @date: 23 . 07 . 2024
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

int n, m, x, u, v, c, res = 0;
vi a[N];
bool vst[N];
queue<int> q;

// void bfs(int s) {
//     vst[s] = true, q.push(s);
//     while (!q.empty()) {
//         int u = q.front();
//         q.pop();
//         for (int v : a[u]) 
//             if (!vst[v]) vst[v] = true, q.push(v);
//     }
// }

void dfs(int s) {
    vst[s] = true;
    for (int v : a[s]) if (!vst[v]) dfs(v);
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n >> m >>x;
    while (m--) {
        cin >> u >> v >> c;
        if (c >= x) a[u].pb(v), a[v].pb(u);
    }
    // frr (i, 1, n) if (!vst[i]) bfs(i), res++;
    frr (i, 1, n) if (!vst[i]) dfs(i), res++;
    cout << res;
}