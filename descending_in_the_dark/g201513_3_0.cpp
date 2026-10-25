#include<stdio.h>
#include<vector>
#include<algorithm>
#include<set>

using namespace std;

int ntest;
int n, m;
char s[80][80];
bool OK[80];
int U[80];
bool vis[80][80];

void get(int x, int y, vector<pair<int, int> > & u) {
	if(vis[x][y] || s[x][y] == '#') return;
	vis[x][y] = true;
	u.push_back(make_pair(x, y));

	get(x-1, y, u);
	get(x, y-1, u);
	get(x, y+1, u);
}

set<vector<pair<int, int> > > T;

const int dx[] = {1, 0, 0};
const int dy[] = {0, -1, 1};

bool simulate(vector<pair<int, int> > u, int x, int y) {
	sort(u.begin(), u.end());
	u.resize(unique(u.begin(), u.end()) - u.begin());

	if(u.size() == 1 && u[0] == make_pair(x, y)) return true;

	for(int i=0; i<u.size(); i++) {
		if(u[i].first > x) return false;
	}

	if(T.find(u) != T.end()) return false;
	T.insert(u);

	vector<pair<int, int> > v;
	for(int i=0; i<3; i++) {
		v.clear();
		for(int j=0; j<u.size(); j++) {
			int x = u[j].first;
			int y = u[j].second;
			if(s[x+dx[i]][y+dy[i]] == '#') v.push_back(make_pair(x, y));
			else v.push_back(make_pair(x+dx[i], y+dy[i]));
		}

		if(simulate(v, x, y)) return true;
	}

	return false;
}

int main() {
	freopen("D-small-attempt0.in", "r", stdin);
	freopen("D-small-attempt0.out", "w", stdout);

	scanf("%d", &ntest);
	for(int test = 1; test <= ntest; test++) {
		scanf("%d%d", &n, &m);
		memset(s, '#', sizeof(s));
		for(int i=1; i<=n; i++) {
			scanf("%s", s[i]);
			s[i][m+2] = '#';
		}

		int cnt = -1;
		for(int i=1; i<=n; i++) {
			for(int j=1; j<=m; j++) {
				if(s[i][j] >= '0' && s[i][j] <= '9') {
					if(cnt < s[i][j] - '0') cnt = s[i][j] - '0';
					vector<pair<int, int> > u;
					memset(vis, 0, sizeof(vis));
					T.clear();
					get(i, j, u);
					U[s[i][j]-'0'] = u.size();
					OK[s[i][j]-'0'] = simulate(u, i, j);
				}
			}
		}

		printf("Case #%d:\n", test);
		for(int i=0; i<=cnt; i++) printf("%d: %d %s\n", i, U[i], OK[i]?"Lucky":"Unlucky");
	}
	return 0;
}