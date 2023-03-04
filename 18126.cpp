// 너구리 구구
// https://www.acmicpc.net/problem/18126

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

#define fast ios_base::sync_with_stdio(false); cin.tie(0), cout.tie(0)
#define ll long long

vector<pair<int, ll> > v[5010];
ll dfs(int x, int p);

int main()
{
    fast;
    int n, a, b, c;
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b >> c;
        v[a].push_back(make_pair(b, c));
        v[b].push_back(make_pair(a, c));
    }
    cout << dfs(1, -1);
    return 0;
}

ll dfs(int x, int p)
{
    ll ret = 0;
    for (int i = 0; i < v[x].size(); i++) {
        if (v[x][i].first == p) continue;
        ret = max(ret, dfs(v[x][i].first, x) + v[x][i].second);
    }
    return ret;
}
