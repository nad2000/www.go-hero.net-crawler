#include <queue>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 10086;
const int INF = 1000000007;

int d[MAXN], l[MAXN];
int maxd[MAXN];

int main() {
    int re, n;
    bool flag;

    scanf("%d", &re);
    for (int ri = 1; ri <= re; ++ri) {
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            scanf("%d%d", &d[i], &l[i]);
        }
        scanf("%d", &d[n]);

        priority_queue<pair<int, int> > pq;
        flag = false;
        fill(maxd, maxd + n, -INF);
        maxd[0] = d[0];
        pq.push(make_pair(maxd[0], 0));
        while (!pq.empty()) {
            int s = pq.top().second;
            int t = pq.top().first;
            pq.pop();
            // printf("maxd[%d] = %d\n", s, t);
            if (maxd[s] != t) {
                continue;
            } else if (maxd[s] + d[s] >= d[n]) {
                flag = true;
                break;
            }
            for (int i = 0; i < n; ++i) {
                int dd = abs(d[s] - d[i]);
                if (dd <= maxd[s] && min(dd, l[i]) > maxd[i]) {
                    maxd[i] = min(dd, l[i]);
                    pq.push(make_pair(maxd[i], i));
                }
            }
        }
        printf("Case #%d: %s\n", ri, flag ? "YES" : "NO");
    }

    return 0;
}

