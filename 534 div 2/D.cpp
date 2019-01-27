#include <bits/stdc++.h>
using namespace std;



signed main()
{
    string s;
    cin >> s;
    while (s != "end" && s != "mistake") {
        int x = 0, y = 1;
        s = "y";
        while (s == "y") {
            cout << "? " << x << " " << y << endl;
            cin >> s;
            if (s == "y") {
                x = y;
                y *= 2;
            }
        }
        while (y - x > 1) {
            int m = (x + y) / 2;
            cout << "? " << x << " " << m << endl;
            cin >> s;
            if (s == "y") {
                x = m;
            }
            else {
                y = m;
            }
        }
        cout << "! " << x + 1 << endl;
        cin >> s;
    }
    if (s == "mistake") {
        return 0;
    }
    return 0;
}
