#include<bits/stdc++.h>
#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

#define MX 100
#define INF 1000000000
using namespace std;

int n = 6, result;
int c[MX][MX], f[MX][MX], d[MX];
vector<int> a[MX];

void maxFlow(int start, int end) {

	// 실제 유량이 계속 누적되므로 최대 유량을 찾을 수 있다. 
	// while(1)을 계속 돌려 더 이상 흘려보낼수 없을 때까지 찾는다. 
	while (1) {
		//cout << "here" << endl;
		fill(d, d + MX, -1);
		queue<int> q;
		q.push(start);

		while (!q.empty()) {
			int x = q.front();
			q.pop();

			for (int& y : a[x]) {
				//int y = a[x][i];
				// 방문하지 않은 노드 중에 용량이 안믄 경우 
				if (c[x][y] - f[x][y] > 0 && d[y] == -1) {
					q.push(y);
					d[y] = x;
					if (y == end) break; // 도착지에 도달한 경우 
				}
			}
		}

		//cout << d[end] << endl;
		if (d[end] == -1) break; // 모든 경로를 다 찾은 뒤에 탈출합니다. 

		int flow = INF;
		for (int i = end; i != start; i = d[i]) { // 거꾸로 최소 유량 탐색
			flow = min(flow, c[d[i]][i] - f[d[i]][i]);
		}

		// 최소 유량만큼 추가합니다.
		for (int i = end; i != start; i = d[i]) {
			f[d[i]][i] += flow;
			f[i][d[i]] -= flow;
		}
		result += flow;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	a[1].push_back(2);
	a[2].push_back(1);
	c[1][2] = 12;

	a[1].push_back(4);
	a[4].push_back(1);
	c[1][4] = 11;

	a[2].push_back(3);
	a[3].push_back(2);
	c[2][3] = 6;

	a[2].push_back(4);
	a[4].push_back(2);
	c[2][4] = 3;

	a[2].push_back(5);
	a[5].push_back(2);
	c[2][5] = 5;

	a[2].push_back(6);
	a[6].push_back(2);
	c[2][6] = 9;

	a[3].push_back(6);
	a[6].push_back(3);
	c[3][6] = 8;

	a[4].push_back(5);
	a[5].push_back(4);
	c[4][5] = 9;

	a[3].push_back(5);
	a[5].push_back(3);
	c[5][3] = 3;

	a[6].push_back(5);
	a[5].push_back(6);
	c[5][6] = 4;

	maxFlow(1, 6);
	cout << result << '\n';
	return 0;
}