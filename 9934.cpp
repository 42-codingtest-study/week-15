// 완전 이진 트리
// https://www.acmicpc.net/problem/9934

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

#define fast ios_base::sync_with_stdio(false); cin.tie(0), cout.tie(0)
#define ll long long

int k;
int num;
int arr[1050];
vector<int> tree[10];

void solution(int s, int e, int d) {
    if (d >= k) return;
    if (s == e) {
        tree[d].push_back(arr[s]);
        return;
    }
    int m = (s + e) / 2;
    if (m < 0 || m >= num) return;
    tree[d].push_back(arr[m]); //중간 값 트리 내 depth d에 push
    solution(s, m - 1, d + 1); //왼쪽 서브 트리
    solution(m + 1, e, d + 1); //오른쪽 서브 트리
}

int main(void) {
    fast;
    cin >> k;
    num = pow(2, k) - 1;
    for (int i = 0; i < num; i++) cin >> arr[i];
    solution(0, num - 1, 0);
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < tree[i].size(); j++) cout << tree[i][j] << " ";
        cout << endl;
    }
    return 0;
}
