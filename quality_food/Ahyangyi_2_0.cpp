#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int t;
long long money;
long long fee;
int n;
/*
long long dp[2000001];
*/

struct fun
{
    long long time, price;
} data[200];

bool operator < (const fun& a, const fun& b)
{
    return a.time < b.time || a.time == b.time && a.price > b.price;
}

long long work ()
{
    sort (data, data + n);
    {
        int m = 0;
        for (int i = 0; i < n; i ++)
        {
            while (m > 0 && data[i].price <= data[m - 1].price)
                m --;
            data[m ++ ] =data[i];
        }
        n = m;
    }

/*
    dp[0] = fee;
    for (int i = 0; i < n; i ++)
        for (int j = (i == 0? 0 : data[i - 1].time) + 1; j <= data[i].time; j ++)
            dp[j] = dp[j - 1] + data[i].price;
*/
    long long best = 0;
    for (int i = 1; i <= money / fee; i ++)
    {
        long long tmp = money - i * fee;

        long long days = 0;
        for (int j = 0; j < n; j ++)
        {
            long long deltat = (data[j].time - (j > 0? data[j-1].time : 0));

//            cout << "j = " << j << ", deltat = " << deltat << endl;

            if (tmp / data[j].price / i / deltat >= 1)
            {
                days += deltat * i;
                tmp -= (data[j].price * i * deltat);
            }
            else
            {
                days += tmp / data[j].price;
                break;
            }
        }

        if (days > best)
            best = days;
    }

    return best;
}

int main ()
{
    cin >> t;
    for (int ct = 1; ct <= t; ct ++)
    {
        cin >> money >> fee >> n;
        for (int i = 0; i < n; i ++)
        {
            cin >> data[i].price >> data[i].time;
            data[i].time ++;
        }

        cout << "Case #" << ct << ": " << work() << endl;
    }

    return 0;
}
