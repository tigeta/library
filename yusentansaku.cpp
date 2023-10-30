#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

vector <int> movey = { 0,0,1,-1,1,-1,1,-1 }; //隣接マスを調べるためのy,x方向の配列
vector <int> movex = { 1,-1,0,0,1,1,-1,-1 };

int H, W;


void dfs(int y, int x, vector<vector<bool>> &f) { //再帰で記述した深さ優先探索
	f.at(y).at(x) = true;
		if (y - 1 >= 0 && !f.at(y-1).at(x)){
			dfs(y - 1, x,f);
		}
		if (x + 1 < W && !f.at(y).at(x+1)) {
			dfs(y , x+1,f);
		}
		if (y + 1 < H && !f.at(y + 1).at(x)) {
			dfs(y + 1, x,f);
		}
		if (x - 1 >= 0 && !f.at(y).at(x-1)) {
			dfs(y , x-1,f);
		}

}

void bfs(vector<vector<bool>> &f,vector<string> &g, int y, int x) { //幅優先探索(1度調べたかを保存する配列ｆと迷路の配列g)
	queue <int> qy;
	queue <int> qx;
	qy.push(y);
	qx.push(x);

	while (!qy.empty()) { //queueの中身が無くなるまで探索
		
			for (int i = 0;i < 8;++i) {
				int y = qy.front() + movey.at(i);
				int x = qx.front() + movex.at(i);

				if (x >= 0 && y >= 0 && x < W && y < H && !f.at(y).at(x)) {
					if (g.at(y).at(x) == '#') {
						f.at(y).at(x) = true;
						qy.push(y);
						qx.push(x);
					}
				}
			}
			qy.pop();
			qx.pop();
	}

}
