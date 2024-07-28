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

cs int N   = 1e6 + 5;
cs int oo  = 1e18;

// Biểu diễn cạnh 2
int n, m;
vector<priority_queue<int, vi, gi>> q;

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n >> m;
    q.resize(n + 1);
    while (m--) {
        int u, v; cin >> u >> v;
        q[u].push(v), q[v].push(u);
    }
    frr (i, 1, n) {
        cout << q[i].size() << ' ';
        while (!q[i].empty()) cout << q[i].top() << ' ', q[i].pop();
        cout << '\n';
    }
}