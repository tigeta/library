#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N, X, Y;
	cin >> N >> X >> Y;
	vector<int> sum(N + 1, 0);


	for (int i = 0;i < N;++i) {
		int a; cin >> a;
		sum.at(i + 1) = sum.at(i) + a;
	}

	cout << sum.at(Y + 1) - sum.at(X) << endl;
}

