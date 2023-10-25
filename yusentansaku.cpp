#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int H, W;


int dfs(int y, int x, vector<vector<bool>> &v) {
	v.at(y).at(x) = true;
		if (y - 1 >= 0 && !v.at(y-1).at(x)){
			dfs(y - 1, x,v);
		}
		if (x + 1 < W && !v.at(y).at(x+1)) {
			dfs(y , x+1,v);
		}
		if (y + 1 < H && !v.at(y + 1).at(x)) {
			dfs(y + 1, x,v);
		}
		if (x - 1 >= 0 && !v.at(y).at(x-1)) {
			dfs(y , x-1,v);
		}

		return 1;
}

int main()
{
	int  Y, X;
	cin >> H >> W;
	int ans = 0;
	vector<string> maze(H);
	vector<vector<bool>> flag(H, vector<bool>(W, false));
	for (int i = 0;i < H;++i) {
		cin >> maze.at(i);
	}

	for (int i = 0;i < H;++i) {
		for (int j = 0;j < W;++j) {
			if (maze.at(i).at(j) == '#') flag.at(i).at(j) = true;
		}
	}
	

	for (int i = 0;i < H;++i) {
		for (int j = 0;j < W;++j) {
			if (!flag.at(i).at(j)) {
				ans += dfs(i, j, flag);
			}
		}
	}

	cout << ans << endl;
	return 0;
}

