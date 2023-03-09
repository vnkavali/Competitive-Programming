#include <iostream>
#include <stdio.h>
using namespace std;

int main()
{
    freopen("test_set_2/ts2_input.txt","r",stdin);
    int t, n;
    int s, sM;

    cin >> t;
    for (int i = 1; i <= t; ++i)
    {
        int cnt[1000001] = {0};
        cin >> n;
        sM = 0;

        for (int j = 0; j < n; j++)
        {
            cin >> s;
            cnt[s]++;

            sM = sM < s ? s : sM;
        }

        int len = 0;
        for (int j = 4; j <= sM; j++)
        {
            if (cnt[j] == 0)
                continue;

            len += cnt[j];
            len = len > j ? j : len;
        }

        cout << "Case #" << i << ": " << len << endl;
    }
    return 0;
}