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

priority_queue<int, vi, gi> res;
queue<int> q;
bool vst[N];
int n, k;
vi a[N];

void bfs(int s) {
    res.push(s), vst[s] = true, q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : a[u])  
            if (!vst[v]) 
                vst[v] = true, res.push(v), q.push(v);
    }
}

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    cin >> n >> k;
    frr (i, 1, n) {
        int size; cin >> size;
        while (size--) {
            int x; cin >> x; a[i].pb(x);
        }
    }
    bfs(k);
    cout << res.size() << '\n';
    while (!res.empty()) {
        cout << res.top() << ' '; res.pop();
    }
}