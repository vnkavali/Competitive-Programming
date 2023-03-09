#include <iostream>
using namespace std;

int main()
{
    int t, r, c;
    cin >> t;
    for (int i = 1; i <= t; ++i)
    {
        cout << "Case #" << i << ":" << endl;

        cin >> r >> c;

        // Row 1
        cout << "..";
        for (int j = 0; j < c - 1; j++)
            cout << "+-";
        cout << "+" << endl;

        // Row 2
        cout << ".";
        for (int j = 0; j < c; j++)
            cout << ".|";
        cout << endl;

        // Row 3
        for (int j = 0; j < c; j++)
            cout << "+-";
        cout << "+" << endl;

        for (int j = 1; j < r; j++)
        {
            for (int k = 0; k < c; k++)
                cout << "|.";
            cout << "|" << endl;

            for (int k = 0; k < c; k++)
                cout << "+-";
            cout << "+" << endl;
        }
    }
    return 0;
}