#include<iostream>
#include<algorithm>
#include<stack>
#include<queue>
#include<vector>

#define MX 1001
using namespace std;

int id, d[MX];
bool finished[MX];
vector<int> a[MX];
vector<vector<int>> SCC;
stack<int> s;


// DFS�� �� ������ ������ŭ �����մϴ�.
int dfs(int x) {
	d[x] = ++id;  // ��帶�� ������ ��ȣ �Ҵ� 
	s.push(x);   // ���ÿ� �ڱ� �ڽ��� �����մϴ�.

	int parent = d[x];
	for (int i = 0; i < a[x].size(); i++) {
		int y = a[x][i];
		//�湮���� ���� �̿�
		if (d[y] == 0) parent = min(parent, dfs(y));
		//ó�� ���� �̿�
		else if (!finished[y]) parent = min(parent, d[y]);
	}

	if (parent == d[x]) {
		vector<int> scc;
		while (1) {
			int t = s.top();
			s.pop();
			scc.push_back(t);
			finished[t] = true;
			if (t == x) break;
		}
		SCC.push_back(scc);
	}
	return parent;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int v = 11;
	a[1].push_back(2);
	a[2].push_back(3);
	a[3].push_back(1);

	a[4].push_back(2);
	a[4].push_back(5);

	a[5].push_back(7);
	a[6].push_back(5);
	a[7].push_back(6);

	a[8].push_back(5);
	a[8].push_back(9);


	a[10].push_back(11);
	a[11].push_back(3);
	a[11].push_back(8);

	for (int i = 1; i <= v; i++) {
		if (d[i] == 0) dfs(i);
	}

	cout << "SCC�� ���� >> " << SCC.size() << '\n';
	for (int i = 0; i < SCC.size(); i++) {
		cout << i + 1 << "��° SCC >> ";
		for (int j = 0; j < SCC[i].size(); j++) cout << SCC[i][j] << ' ';
		cout << '\n';
	}


	return 0;
}