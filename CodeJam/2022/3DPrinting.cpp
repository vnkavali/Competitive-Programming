#include <iostream>
using namespace std;

int main()
{
    int t, c[3], m[3], y[3], k[3];
    cin >> t;
    for (int i = 1; i <= t; ++i)
    {
        cout << "Case #" << i << ": ";

        int Oc = 1000000, Om = 1000000, Oy = 1000000, Ok = 1000000;
        for (int i = 0; i < 3; i++)
        {
            cin >> c[i] >> m[i] >> y[i] >> k[i];

            Oc = Oc < c[i] ? Oc : c[i];
            Om = Om < m[i] ? Om : m[i];
            Oy = Oy < y[i] ? Oy : y[i];
            Ok = Ok < k[i] ? Ok : k[i];
        }

        if (Oc + Om + Oy + Ok < 1000000)
            cout << "IMPOSSIBLE" << endl;
        else
        {
            cout << Oc << " ";

            if (Oc + Om >= 1000000)
            {
                cout << 1000000 - Oc << " " << 0 << " " << 0 << endl;
                continue;
            }

            cout << Om << " ";

            if (Oc + Om + Oy >= 1000000)
            {
                cout << 1000000 - Oc - Om << " " << 0 << endl;
                continue;
            }

            cout << Oy << " " << 1000000 - Oc - Om - Oy << endl;
        }
    }
    return 0;
}