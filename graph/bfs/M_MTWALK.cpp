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

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int n, res = oo, a[105][105], dist[105][105];
queue<ii> q;

bool bfs(int l, int r) {
    if (a[1][1] < l || a[1][1] > r) return 0;
    frr (i, 1, n) frr (j, 1, n) dist[i][j] = -1; 
    dist[1][1] = 0;
    q.push({1, 1});
    while (!q.empty()) {
        int u = q.front().fi, v = q.front().se;
        q.pop();
        fr (i, 0, 4) {
            int x = u + dx[i], y = v + dy[i];
            if (x > 0 && x <= n && y > 0 && y <= n && a[x][y] >= l && a[x][y] <= r && dist[x][y] == -1) 
                dist[x][y] = dist[u][v] + 1, q.push({x, y});
        }
    }
    return (dist[n][n] != -1) ? 1 : 0;
}

void solve() {
    frr (i, 0, 100) 
        frr (j, i, 100) 
            if (bfs(i, j)) res = min(res, j - i);
    cout << res;
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n;
    frr (i, 1, n) frr (j, 1, n) cin >> a[i][j];
    solve();
}