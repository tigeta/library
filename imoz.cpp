#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N, Q;
	cin >> N >> Q;
	int ans = 0;
	vector<int> vec(N, 0);
	for (int i = 0;i < Q;++i) {
		int l, r;
		cin >> l >> r;
		l--; r--;

		vec.at(l)++;
		if(r+1 < N) vec.at(r + 1)--;
	}

	for (int i = 1;i < N;++i) {
		vec.at(i) += vec.at(i - 1);
		ans = max(ans, vec.at(i));
	}

	cout << ans << endl;
	return 0;
}

