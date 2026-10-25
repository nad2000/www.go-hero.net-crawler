#include <cmath>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1024;
const double EPS = 1e-6;

pair<double, int> p[MAXN];
double r[MAXN], x[MAXN], y[MAXN];

int main() {
    int re, n;
    double w, h, rate;
    bool done;
    int cnt;

    scanf("%d", &re);
    for (int ri = 1; ri <= re; ++ri) {
        scanf("%d%lf%lf", &n, &w, &h);
        for (int i = 0; i < n; ++i) {
            scanf("%lf", &r[i]);
            p[i].first = r[i];
            p[i].second = i;
        }
        sort(p, p + n);
        reverse(p, p + n);
        for (int i = 0; i < n; ++i) {
            r[i] = p[i].first;
        }
        cnt = 0;

GAO:
        for (int i = 0; i < n; ++i) {
            x[i] = rand() * w / RAND_MAX;
            y[i] = rand() * h / RAND_MAX;
        }
        done = false;
        rate = 1.2;
        while (!done) {
            if (++cnt % 12 == 0) {
                goto GAO;
            }
            done = true;
            for (int i = 0; i < n; ++i) {
                // printf("[%d] %lf %lf\n", i, x[i], y[i]);
                double dx = 0;
                double dy = 0;
                for (int j = 0; j < n; ++j) {
                    if (i == j) {
                        continue;
                    }
                    double d = hypot(x[i] - x[j], y[i] - y[j]);
                    if (d < r[i] + r[j] + EPS) {
                        // printf("%lf < %lf\n", d, r[i] + r[j]);
                        double t = (r[i] + r[j] - d) / d;
                        done = false;
                        dx += t * (x[i] - x[j]);
                        dy += t * (y[i] - y[j]);
                    }
                }
                x[i] += rate * dx;
                x[i] = max(0.0, min(w, x[i]));
                y[i] += rate * dy;
                y[i] = max(0.0, min(h, y[i]));
            }
        }
        fprintf(stderr, "cnt = %d\n", cnt);
        printf("Case #%d:", ri);
        for (int i = 0; i < n; ++i) {
            int k = -1;
            for (int j = 0; j < n; ++j) {
                if (p[j].second == i) {
                    k = j;
                    break;
                }
            }
            printf(" %.9lf %.9lf", x[k], y[k]);
        }
        puts("");
    }

    return 0;
}

