#include <iostream>
#include <vector>
using namespace std;

int find(int x, vector<int>& a) {
    if (a.at(x) == x) {
        return x;
    }
    else {
        x = a.at(x);
        return find(x, a);
    }
}

int main()
{
    int N, Q;
    cin >> N >> Q;
    vector<int> parent(N);
    for (int i = 0;i < N;++i) {
        parent.at(i) = i;
    }

    for (int i = 0;i < Q;++i) {
        int a, b;
        cin >> a >> b;
        int s, t;
        s = find(a, parent);
        t = find(t, parent);
        if (s != t) parent.at(b) = a;
    }
    
    for (int i = 0;i < N;++i) {
        cout << parent.at(i) << endl;
    }

    return 0;
}

