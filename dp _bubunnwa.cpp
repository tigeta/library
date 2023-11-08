#include <iostream>
#include <vector>
using namespace std;


int main()
{
    int n, x;
    cin >> n >> x;
   
    vector<int> vec(n);
    vector<int> dp(x+1,100000000);

    dp.at(0) = 0;
    for (int i = 0;i < n;++i) {
        cin >> vec.at(i);
    }

    
        for (int i = 0;i < n;++i) {
            for (int j = vec.at(i);j <= x;j++) {
                if (dp.at(j - vec.at(i)) != 100000000) {
                    dp.at(j) = min(dp.at(j - vec.at(i)) + 1, dp.at(j));
                }
            }
        }
    
   

    if (dp.at(x) == 100000000) {
        cout << "no" << endl;
    }
    else {
        cout << "yes" << endl;
    }

    return 0;
}

