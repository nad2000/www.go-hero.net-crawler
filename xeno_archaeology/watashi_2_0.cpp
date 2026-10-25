#include <set>
#include <map>
#include <queue>
#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

const int MAXN = 404;

int x[MAXN], y[MAXN], z[MAXN];

int main() {
    char ch;
    int re, n, ansx, ansy;

    scanf("%d", &re);
    for (int ri = 1; ri <= re; ++ri) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d%d %c", &x[i], &y[i], &ch);
            z[i] = ch == '.' ? 0 : 1;
        }
        ansx = ansy = MAXN + 1;
        for (int i = -MAXN; i <= MAXN; ++i) {
            for (int j = -MAXN; j <= MAXN; ++j) {
                if (abs(i) + abs(j) > abs(ansx) + abs(ansy)) {
                    continue;
                }
                bool flag = true;
                for (int k = 0; k < n; ++k) {
                    if (max(abs(x[k] - i), abs(y[k] - j)) % 2 != z[k]) {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    ansx = i;
                    ansy = j;
                }
            }
        }
        printf("Case #%d: ", ri);
        if (ansx <= MAXN) {
            printf("%d %d\n", ansx, ansy);
        } else {
            puts("Too damaged");
        }
    }

    return 0;
}


