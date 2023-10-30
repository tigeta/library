//二次元のいもす法
#include <iostream>
#include <vector>
using namespace std;

int main()
{	
	int N,M, K; cin >> N >> M >> K;
	int ans = 0;
	vector<vector<int>> vec(N, vector<int>(M, 0));

	
	for (int i = 0;i < K;++i) {
		int a, b, c, d; 
		cin >> a >> b >> c >> d;
		a--; b--; c--; d--;

		vec.at(b).at(a)++;
		if(c + 1 < M) vec.at(b).at(c+1)--; //範囲内なら終点から1引く
		if(d + 1 < N) vec.at(d+1).at(a)--; //範囲内なら終点から1引く
		if(d + 1 < N && c + 1<M) vec.at(d+1).at(c+1)++; //範囲内なら対角線に1加える
	}

	for (int i = 0;i < N;++i) {
		for (int j = 1;j < M;++j) {
			vec.at(i).at(j) += vec.at(i).at(j - 1); //各行の累積和
		}
	}

	for (int i = 0;i < M;++i) {
		for (int j = 1;j < N;++j) {
			vec.at(j).at(i) += vec.at(j-1).at(i); //各列の累積和
		}
	}

	for (int i = 0;i < N;++i) {
		for (int j = 0;j < M;++j) {
			ans = max(ans, vec.at(i).at(j));
		}
	}
	cout << ans << endl;
	return 0;
}

