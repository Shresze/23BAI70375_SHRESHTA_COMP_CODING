#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
const int B = 200;

vector<int> p[N];
int n, m, a[N], g[N], f[500][N];

int main() {
    int i = 0, j, l, r, t, ans = 0;

    scanf("%d%d", &n, &m);
    for (; i < n; ++i) {
        scanf("%d", &a[i]);
        --a[i];
        p[a[i]].push_back(i);
    }

    for (i = 0; i * B < n; ++i) {
        memset(g, 0, sizeof(int) * n);
        t = 0;
        for (j = i * B; j < n; ++j)
            f[i][j] = t += (g[a[j]]++ < m);
    }

    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &l, &r);
        l = (l + ans) % n;
        r = (r + ans) % n;
        if (l > r) swap(l, r);

        ans = 0;
        if (l / B == r / B) {
            for (j = l; j <= r; ++j)
                ans += (g[a[j]]++ < m);
            for (j = l; j <= r; ++j)
                g[a[j]] = 0;
        } else {
            int i2 = l / B + 1;
            ans = f[i2][r];
            for (j = i2 * B - 1; j >= l; --j) {
                if (!g[a[j]]) {
                    g[a[j]] = upper_bound(p[a[j]].begin(), p[a[j]].end(), r)
                              - lower_bound(p[a[j]].begin(), p[a[j]].end(), i2 * B);
                }
                ans += (g[a[j]]++ < m);
            }
            for (j = i2 * B - 1; j >= l; --j)
                g[a[j]] = 0;
        }

        printf("%d\n", ans);
    }

    return 0;
}
