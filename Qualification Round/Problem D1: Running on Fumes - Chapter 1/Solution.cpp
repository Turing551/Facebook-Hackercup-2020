#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;

#define lli long long
#define fi first
#define FOR(i,n) for(int i=0;i<n;i++)
#define MAXC 1000005

int n, m, i, j, t, q, ok, cnt, V[MAXC];
lli k, r, x, y, z, ans, dp[MAXC];
string str1, str2;

int main(int argc, char **argv){
	freopen("finalinputd1.txt", "r", stdin);
    freopen("finaloutputd1.txt", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    for(q=1, ok=1;q<=t;q++, ok=1){
        cin >> n >> m;
        FOR(i, n){
            cin >> V[i];
            V[i] = V[i]?V[i]:-1;
        }
        set< pair< lli, int > > S;
        dp[n-1] = V[n-1] = 0;
        S.insert({0, n-1});
        for(int i=n-2;i>=0;i--){
            if(S.empty()){
                ok = 0;
                break;
            }
            dp[i] = S.begin()->fi;
            if(V[i]!=-1){
                S.insert({dp[i] + V[i], i});
            }
            if(i + m <= n-1 && V[i+m]!=-1){
                S.erase({dp[i+m] + V[i+m], i+m});
            }
        }
        cout << "Case #" << q << ": " << (ok?dp[0]:-1) << '\n';
    }
}
