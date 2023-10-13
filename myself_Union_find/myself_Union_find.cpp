#include <iostream>
#include <vector>
using namespace std;

struct UnionFind {

    vector<int> parent;
    vector<int> rank;
    
    UnionFind(int n) {
        parent.resize(n, 0);
        rank.resize(n, 0);
        for (int i = 0;i < n;++i) {
            parent.at(i) = i;
            rank.at(i) = 1;
        }
    }

    int find(int x) {
        if (parent.at(x) == x) {
            return x;
        }
        else {
            parent.at(x) = find(parent.at(x));
            return parent.at(x);
        }
    }
    
    void unite(int a, int b) {
        int s, t;
        s = find(a);
        t = find(b);
        if (s != t) {
            if (rank.at(s) >= rank.at(t)) {
                parent.at(t) = s;
                if (rank.at(s) == rank.at(t)) rank.at(s)++;
            }
            else {
                parent.at(s) = t;
            }
        }
    }
};



int main()
{
    int N, Q;
    cin >> N >> Q;
    
    UnionFind uf(N);

    for (int i = 0;i < Q;++i) {
        int A, B;
        cin >> A >> B;
        uf.unite(A, B);
    }
 
    for (int i = 0;i < N;++i) {
        cout << uf.parent.at(i) << endl;
    }

    for (int i = 0;i < N;++i) {
        cout << uf.rank.at(i) << endl;
    }
    return 0;
}

