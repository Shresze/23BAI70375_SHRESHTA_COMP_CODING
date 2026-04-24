#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n), b(n);
    int sumA = 0, sumB = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        sumA += a[i];
        sumB += b[i];
    }

    // dp[k][s] = max sum of b using k glasses with total a = s
    vector<vector<int>> dp(n + 1, vector<int>(sumA + 1, -1e9));
    dp[0][0] = 0;

    for (int i = 0; i < n; i++) {
        for (int k = i; k >= 0; k--) {
            for (int s = sumA - a[i]; s >= 0; s--) {
                if (dp[k][s] < 0) continue;
                dp[k + 1][s + a[i]] = max(dp[k + 1][s + a[i]],
                                          dp[k][s] + b[i]);
            }
        }
    }

    cout << fixed << setprecision(10);

    for (int k = 1; k <= n; k++) {
        double best = 0.0;
        for (int s = 0; s <= sumA; s++) {
            if (dp[k][s] < 0) continue;
            best = max(best,
                       min((double)2 * s,
                           (double)dp[k][s] + sumB));
        }
        cout << best / 2.0 << " ";
    }

    return 0;
}
