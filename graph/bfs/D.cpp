/*
 *  @date: 17 . 07 . 2024
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

// BFS có hướng
int n, m, s, t, dist[N];
vi a[N];
queue<int> q;

void bfs(int s) {   
    frr (i, 1, n) dist[i] = -1;
    dist[s] = 0;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : a[u])
            if (dist[v] == -1) dist[v] = dist[u] + 1, q.push(v);
    }
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n >> m >> s >> t;
    while (m--) {
        int x, y; cin >> x >> y;
        a[x].pb(y);
    }
    bfs(s);
    cout << dist[t];
}