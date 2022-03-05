#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long t, n, ans;
    string final, inp;
    cin >> t;
    for (int tt = 1; tt <= t; ++tt)
    {
        ans = 0;
        // final to keep track of greatest number till now
        cin >> n >> final;
        for (int j = 1; j < n; ++j)
        {
            cin >> inp;
            if (inp.length() > final.length())
            {
                final = inp;
                continue;
            }
            else
            {
                bool done = false;
                // When there is some different digits in inp and final
                // if a digit value is greater than final -> add 0s and make the string length equal to final
                // else if a digit value is less than final -> make length of inp one greater than final
                for (int i = 0; i < inp.length(); ++i)
                {
                    if (inp[i] > final[i])
                    {
                        ans += final.size() - inp.size();
                        inp.resize(final.size(), '0');
                        done = true;
                        break;
                    }
                    else if (inp[i] < final[i])
                    {
                        ans += final.size() - inp.size() + 1;
                        inp.resize(final.size() + 1, '0');
                        done = true;
                        break;
                    }
                }
                // If all the digits of inp is same as final
                // increase final by 1
                if (!done)
                {
                    int ind, pos = inp.size();
                    for (ind = final.size() - 1; ind >= pos; --ind)
                    {
                        if (final[ind] != '9')
                        {
                            ++final[ind];
                            break;
                        }
                        // make greator by making previous digit +1 and later digits 0
                        else
                            final[ind] = '0';
                    }
                    // inp = 1234
                    // final = 12349999
                    // change final to 123400000
                    if (ind < pos)
                    {
                        ans += final.size() - inp.size() + 1;
                        inp.resize(final.size() + 1, '0');
                        final = inp;
                    }
                    else
                    {
                        ans += final.size() - inp.size();
                    }
                }
                else
                    final = inp;
            }
        }
        cout << "Case #" << tt << ": " << ans << endl;
    }
    return 0;
}
