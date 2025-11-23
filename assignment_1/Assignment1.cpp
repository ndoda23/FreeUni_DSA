#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    long long m;
    cin >> n >> m;

    vector<int> writtenNums(n);
    for (int i = 0; i < n; i++) {
        cin >> writtenNums[i];
    }

    vector<int> eratosthene(1000001, 0);
    vector<int> primes;

    for (long long i = 2; i <=1000000 ; i ++) {
        if (eratosthene[i]==1) continue;
        primes.push_back(i);
        for (long long j = i*i ; j <=1000000 ; j += i) {
            eratosthene[j] = 1;
        }
    }

    unordered_map<int,int> maximums;
    for (long long x_orig: writtenNums) {
        long long x = x_orig;
        for (long long y: primes) {
            if (y*y > x) break;
            int cnt = 0 ;
            while (x % y == 0) {
                x /= y;
                cnt++;
            }

            if (cnt > 0) maximums[y] = max(maximums[y],cnt);
        }
        if (x > 1) maximums[x] = max(maximums[x], 1);

    }

    long long cnt = 1;
    for (pair<int,int> kv : maximums) {
        cnt = (cnt * (kv.second + 1))%m;
    }

    long long res = (cnt - n) % m;
    if (res < 0) res += m;
    cout << res << "\n";

    return 0;
}
