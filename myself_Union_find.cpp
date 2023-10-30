//Union-Find
#include <iostream>
#include <vector>
using namespace std;

struct UnionFind {

    vector<int> parent;
    UnionFind(int n) {
        parent.resize(n, -1); //-1で初期化
    }

    bool same(int e, int f) { //所属判定
        if (find(e) == find(f)) {
            return true;
        }
        else {
            return false;
        }
    }

    int find(int x) { //経路圧縮しながら親を見つける
        if (parent.at(x) < 0) {
            return x;
        }
        else {
            parent.at(x) = find(parent.at(x));
            return parent.at(x);
        }
    }
    
    void unite(int a, int b) { //ランクの大きいほうに低いほうを結合
        int s, t;
        s = find(a);
        t = find(b);
        if (s != t) {
            if (abs(parent.at(s)) >= abs(parent.at(t))) {
                if (parent.at(s) == parent.at(t)) parent.at(s)--;
                parent.at(t) = s;
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
    vector<int> value(N);
    for (int i = 0;i < Q;++i) {
        int A, B;
        cin >> A >> B;
        uf.unite(A, B);
    }
 
    for (int i = 0;i < N;++i) {
        cout << uf.parent.at(i) << endl;
    }

    return 0;
}

