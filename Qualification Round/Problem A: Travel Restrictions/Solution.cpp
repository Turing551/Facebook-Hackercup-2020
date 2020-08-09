#include <bits/stdc++.h>
#include <climits>
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define sll(x) LL x = scanLong();
#define pll(x) printf("%lld ", x)
#define clr(a) memset(a, 0, sizeof(a))

using namespace std;
typedef long long int LL; 

const LL MOD = 1e9+7;

inline int scanInt() {
	int n = 0;
	char ch = getchar();
	int sign = 1;
	while(ch < '0' || ch > '9') {
		if(ch == '-')	sign = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9') {
		n = (n<<1)+(n<<3)+(int)(ch-'0');
		ch = getchar();
	}
	return n*sign;
}

inline LL scanLong() {
	LL n = 0;
	char ch = getchar();
	LL sign = 1;
	while(ch < '0' || ch > '9') {
		if(ch == '-')	sign = -1;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9') {
		n = (n<<1)+(n<<3)+(LL)(ch-'0');
		ch = getchar();
	}
	return n*sign;
}

int main() {
	sll(t);
	rep(c, 1, t+1) {
		cout << "Case #" << c << ":\n"; 
		sll(n);
		string x1, y1;
		cin >> x1 >> y1;
		bool arr1[n][n]; clr(arr1);
		rep(i, 0, n) {
			rep(j, 0, n) {
				if(i == j)	arr1[i][j] = true;
				else if(i < j) {
					arr1[i][j] = (y1[i] == 'Y' && x1[j] == 'Y');
					rep(k, i+1, j) {
						arr1[i][j] = arr1[i][j] && (x1[k] == 'Y' && y1[k] == 'Y');
						
					}
				}
				else if(i > j) {
					arr1[i][j] = (y1[i] == 'Y' && x1[j] == 'Y');
					rep(k, j+1, i) {
						arr1[i][j] = arr1[i][j] && (x1[k] == 'Y' && y1[k] == 'Y');
					}
				}
			}
		}

		rep(i, 0, n) {
			rep(j, 0, n) {
				cout << (arr1[i][j] ? 'Y' : 'N');
			}
			cout << endl;
		}
	}
}
