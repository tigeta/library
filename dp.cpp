#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, x, a, y, b, z, c;
    cin >> n >> x >> a >> y >> b >> z >> c;

    vector<int> dp(2000,100000000);
    dp.at(0) = 0;
    dp.at(x) = a;

    for (int i = 1;i < n+z;++i) {
        if(i >= x) {
            dp.at(i) = min(dp.at(i), dp.at(i - x) + a);
        }
        if (i >= y) {
            dp.at(i) = min(dp.at(i), dp.at(i - y) + b);
        }
        if (i >= z) {
            dp.at(i) = min(dp.at(i), dp.at(i - z) + c);
        }
    }

    for (int i = n + z - 1;i > 0;i--) {
        dp.at(i) = min(dp.at(i), dp.at(i + 1));
    }

    cout << dp.at(n) << endl;
    return 0;
}

