#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>

#define MX 10
using namespace std;

int n, inDgree[MX];
vector<int> a[MX];

void topologySort() {
	int result[MX];

	queue<int> q;

	for (int i = 0; i <= n; i++) {
		if (inDgree[i] == 0) q.push(i);
	}

	for (int i = 1; i <= n; i++) {
		if (q.empty()) {
			cout << "cycle " << endl;
			return;
		}

		int x = q.front(); q.pop();
		result[i] = x;
		for (int i = 0; i < a[x].size(); i++) {
			int y = a[x][i];
			if (--inDgree[y] == 0) q.push(y);
		}
	}

	for (int i = 1; i <= n; i++) cout << result[i] << ' ';
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	n = 7;
	a[1].push_back(2);
	inDgree[2]++;

	return 0;
}