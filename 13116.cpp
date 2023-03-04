// 30번
// https://www.acmicpc.net/problem/13116

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

#define fast ios_base::sync_with_stdio(false); cin.tie(0), cout.tie(0)
#define ll long long

int main() {
    fast;
    int T, a, b;
    cin >> T;
    while (T--) {
        cin >> a >> b;
        vector<int> va;
        vector<int> vb;
        if (a > b) {
            int tmp = a;
            a = b;
            b = tmp;
        }
        while (a > 0) {
            va.push_back(a);
            a /= 2;
        }
        while (b > 0) {
            vb.push_back(b);
            b /= 2;
        }
        sort(va.begin(), va.end());
        sort(vb.begin(), vb.end());
        int ans = 1;
        for (int i = 0; i < va.size(); i++)
            if (va[i] == vb[i]) ans = va[i];
        cout << ans * 10 << "\n";
    }
}
