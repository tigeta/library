#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n; cin >> n;
    vector<int> vec(n);
    vector<int> dp(n);

    cin >> vec.at(0);
  
    for (int i = 1;i < n;++i) {
        cin >> vec.at(i);
    }

    for (int i = 0;i < n;++i) {
        dp.at(i) = 1;
        for (int j = 0;j < i;++j) {
            if (vec.at(j) > vec.at(i)) {
                dp.at(i) = max(dp.at(i), dp.at(j) + 1);
            }
        }
    }


    cout << *max_element(dp.begin(),dp.end()) << endl;
    return 0;
}

