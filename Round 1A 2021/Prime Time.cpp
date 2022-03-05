#include <bits/stdc++.h>

#define ll long long

using namespace std;

int main()
{
    ll t, ans, p, m, n, sum, start, copyI, sum1;
    cin >> t;
    for (int tt = 1; tt <= t; ++tt)
    {
        ans = 0, sum = 0;
        map<int, int> frequency;
        cin >> m;
        for (int i = 0; i < m; ++i)
        {
            cin >> p >> n;
            frequency[p] = n;
            sum += p * n;
        }
        start = max(2LL, sum - 29940);
        for (ll i = start; i < sum; ++i)
        {
            auto temp = frequency;
            copyI = i;
            sum1 = sum;
            for (auto &x : temp)
            {
                while (x.second && (copyI % x.first == 0))
                {
                    --x.second;
                    copyI /= x.first;
                    sum1 -= x.first;
                }
            }
            if (copyI == 1 && sum1 == i)
                ans = max(ans, i);
        }
        cout << "Case #" << tt << ": " << ans << endl;
    }
    return 0;
}
