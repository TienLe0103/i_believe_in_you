/*
 *  @date: 11 . 07 . 2024
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

cs int N   = 2000 + 5;
cs int oo  = 1e18;

//Biểu diễn cạnh 1
int n, m, dist[N][N];

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n >> m;
    while (m--) {
        int u, v; cin >> u >> v;
        dist[u][v] = dist[v][u] = 1;
    }
    frr (i, 1, n) {
        frr (j, 1, n) cout << dist[i][j] << ' ';
        cout << '\n';
    }
}