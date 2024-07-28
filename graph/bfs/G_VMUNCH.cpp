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

int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};
int row, column, dist[105][105];
char a[105][105];
ii s, e;
queue<ii> q;

void bfs(ii s) {
    frr (i, 1, row) frr (j, 1, column) dist[i][j] = -1;
    dist[s.fi][s.se] = 0, q.push(s);
    while (!q.empty()) {
        int u = q.front().fi, v = q.front().se;
        q.pop();    
        fr (i, 0, 4) {
            int x = u + dx[i], y = v + dy[i];
            if (x < 0 || x > row) continue;
            if (y < 0 || y > column) continue;
            if (dist[x][y] == -1 && a[x][y] != '*') dist[x][y] = dist[u][v] + 1, q.push({x, y});
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> row >> column;
    frr (i, 1, row) 
        frr (j, 1, column) {
            cin >> a[i][j]; 
            if (a[i][j] == 'B') s = {i, j};
            if (a[i][j] == 'C') e = {i, j};
        }
    bfs(s);
    cout << dist[e.fi][e.se];
}