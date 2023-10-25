#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N, M, Q;
	int a, b, c, d;
	cin >> N >> M >> Q;

	vector<vector<int>> sum(N + 1, vector<int>(M + 1, 0));
	

	

	for (int i = 0;i < N;++i) {
		for (int j = 0;j < M;++j) {
			int s; cin >> s;
			sum.at(i + 1).at(j + 1) = sum.at(i).at(j + 1) + sum.at(i + 1).at(j) - sum.at(i).at(j) + s;
		}
	}

	for (int i = 0;i < Q;++i) {
		cin >> a >> b >> c >> d;
		cout << sum.at(c + 1).at(d + 1) - sum.at(c + 1).at(b) - sum.at(a).at(d + 1) + sum.at(a).at(b) << endl;
	}


	return 0;
}

