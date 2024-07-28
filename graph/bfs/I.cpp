/*
 *  @date: 19 . 07 . 2024
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

// Quân mã
int dx[] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[] = {-2, -1, 1, 2, 2, 1, -1, -2};
int n, m, dist[1005][1005];
ii s, e;
queue<ii> q;

void bfs(ii s) {
    frr (i, 1, n) frr (j, 1, m) dist[i][j] = -1;
    dist[s.fi][s.se] = 0, q.push(s);
    while (!q.empty()) {
        int u = q.front().fi, v = q.front().se;
        q.pop();
        fr (i, 0, 8) {
            int x = u + dx[i], y = v + dy[i];
            if (x < 0 || x > n) continue;
            if (y < 0 || y > m) continue;
            if (dist[x][y] == -1) dist[x][y] = dist[u][v] + 1, q.push({x,y});
        }
    }
}   

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n >> m >> s.fi >> s.se >> e.fi >> e.se;
    bfs(s);
    cout << dist[e.fi][e.se];   
}