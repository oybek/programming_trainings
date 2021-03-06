
#include <set>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <cmath>
#include <bitset>
#include <cstdio>
#include <string>
#include <vector>
#include <cassert>
#include <cstring>
#include <climits>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <unordered_map>

#define INF 1000000001
#define SQR(x) ((x)*(x))

typedef unsigned long long uint64;
typedef long long int64;

using namespace std;

#define C_MAX 5001

class ufds_t {
	private:
		int parent[C_MAX],
			size[C_MAX],
			size_max;

	public:
		void init(int n = C_MAX-1) {
			size_max = 1;
			for (int i = 0; i <= n; ++i) {
				parent[i] = i;
				size[i] = 1;
			}
		}

		int find(int x) {
			return x == parent[x] ? x : parent[x] = find(parent[x]);
		}

		void join(int x, int y) {
			x = find(x);
			y = find(y);

			if (x == y) {
				return;
			} else {
				parent[x] = parent[y];
				size[x] += size[y];
				size[y] = size[x];
				size_max = max(size[x], size_max);
			}
		}

		int get_size_max() {
			return size_max;
		}
};

int C, R;
string s, s1, s2;
ufds_t ufds;
unordered_map<string, int> names;

int main() {
	while (1) {
		names.clear();
		cin >> C >> R;
		if (!C && !R)
			break;
		for (int i = 0; i < C; ++i) {
			cin >> s;
			names[s] = i;
		}

		ufds.init(C);
		for (int i = 0; i < R; ++i) {
			cin >> s1 >> s2;
			ufds.join(names[s1], names[s2]);
		}
		cout << ufds.get_size_max() << endl;
	}

	return 0;
}

