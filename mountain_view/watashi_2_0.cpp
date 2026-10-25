#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 2048;
const int INF = 1000000007;

int v[MAXN], h[MAXN];

void gao(int k, int l, int r) {
    while (l < r) {
        int m = v[l];
        if (m <= l || m > r) {
            throw 1;
        }
        // printf("%d[%d, %d]\n", k, l, r);
        gao(k + 1, l + 1, m);
        int diff = (h[l] + k * (m - l)) - h[m];
        for (int i = l + 1; i <= m; ++i) {
            h[i] += diff;
        }
        l = m;
    }
    /*
    printf("%d[%d, %d];", k, ll, r);
    for (int i = ll; i <= r; ++i) {
        printf(" %d", h[i]);
    }
    puts("");
    */
}

int main() {
    int re, n, m;

    scanf("%d", &re);
    for (int ri = 1; ri <= re; ++ri) {
        scanf("%d", &n);
        for (int i = 0; i < n - 1; ++i) {
            scanf("%d", &v[i]);
            --v[i];
        }
        fill(h, h + n, 0);
        printf("Case #%d: ", ri);
        try {
            gao(1, 0, n - 1);
            m = *min_element(h, h + n);
            for (int i = 0; i < n; ++i) {
                printf(" %d", h[i] - m);
            }
            puts("");
        } catch (...) {
            puts("Impossible");
        }
    }

    return 0;
}

