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

// Ma trận 0 1 (5 điểm)
int dx[]= {0, 1, 0 ,-1}, dy[] = {1, 0, -1, 0};
int n, m, k,d =  0, s,ss;
bool a[1005][1005], vst[1005][1005];
queue<ii> q;

void bfs(ii s) {
    q.push(s);
    vst[s.fi][s.se] = 1;
    d--;
    while (!q.empty()) {
        int u = q.front().fi, v = q.front().se;
        q.pop();
        fr (i, 0, 4) {
            int x = u + dx[i], y = v + dy[i];
            if (x < 1 || x > n) continue;
            if (y < 1 || y > m) continue;
            if (!vst[x][y] && a[x][y]) vst[x][y] = true, q.push({x, y}), d--;
            if (!d) return;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n >> m >> k;
    frr (i, 1, n ) 
        frr (j, 1, m) {
            cin >> a[i][j];
            if (a[i][j]) d++, s = i, ss = j;
        }
    d -= k;
    bfs({s, ss});
    frr (i, 1, n) frr (j, 1, m ) if (!vst[i][j] && a[i][j]) cout << i << ' ' << j << '\n';
}