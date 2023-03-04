// 콜라츠 추측
// https://www.acmicpc.net/problem/6615

#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>
#include <map>

using namespace std;

#define fast ios_base::sync_with_stdio(false); cin.tie(0), cout.tie(0)
#define ll long long

void clear(map<ll, int> &mm) {
    mm = map<ll, int>();
}

int main(){
    ll a, b;
    int num1, num2;

    map<ll, int> mm;
    while (1) {
        scanf("%lld %lld", &a, &b);
        if (a == 0 && b == 0) break;
        num1 = a; num2 = b;
        bool flag = true;
        int cnt1 = 0, cnt2 = 0;
        while (a != 1) {
            mm[a] = ++cnt1;
            if (a % 2) a = a * 3 + 1;
            else a /= 2;
        }
        mm.insert(make_pair(1, ++cnt1));
        while (b != 1) {
            ++cnt2;
            if (mm[b] != 0) {
                printf("%d needs %d steps, %d needs %d steps, they meet at %lld\n", num1, mm[b] - 1, num2, cnt2 - 1, b);
                flag = false;
                break;
            }
            if (b % 2) b = b * 3 + 1;
            else b /= 2;
        }
        if (flag) printf("%d needs %d steps, %d needs %d steps, they meet at %d\n", num1, mm[1] - 1, num2, cnt2, 1);
        clear(mm);
    }
    return 0;
}
