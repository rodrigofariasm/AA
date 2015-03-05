// Rodrigo Farias de Macêdo

#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define FOR(i,a,b) for(int i=(a),_b=(b); i<=_b; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b); i>=_b; i--)
#define REP(i,a) for(int i=0,_a=(a); i<_a; i++)
#define EACH(it,a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); ++it)
#define SZ(S) ((int) ((S).size()))
#define DEBUG(x) { cout << #x << " = " << x << endl; }
#define PR(a,n) { cout << #a << " = "; FOR(_,1,n) cout << a[_] << ' '; cout << endl; }
#define PR0(a,n) { REP(_,n) cout << a[_] << ' '; cout << endl; }


#define MAX 301
int n,nFac;
int values[MAX];
int cost[MAX];
int DP[MAX][1<<9];
int memo[MAX];

int dp(int c, int mask){
    if(c > n+1){
		if(mask == (1<<nFac)-1) return 0;
		return 1000000000;
	}
	int &result = DP[c][mask];
	if(result != -1) return result;
	result = 1000000000;
	result = min(result, dp(c+1, mask));
	result = min(result, dp(c+1, mask | memo[c]) + cost[c]);
	return result;
}

int main() {
    int ans = 1000000000;
    cin >> n;
    REP(i, n){
        cin>>values[i];

    }
    REP(i, n) cin>>cost[i];
    REP(i, n){
    	vector<int> factors;
    	int val = values[i];
    	for(int j = 2; j*j <= val; j++)
    		if(val % j == 0){
    			factors.push_back(j);
    			while(val % j == 0)
    				val /= j;
    		}

    	if(val > 1)
    		factors.push_back(val);
    	nFac = factors.size();

    	REP(j,n){
    		memo[j] = 0;
    		REP(k, nFac)
    			if(values[j] % factors[k] != 0)
    				memo[j] |= (1<<k);
    	}
    	memset(DP, 0xff, sizeof(DP));
    	ans = min(ans, cost[i] + dp(1, 0));
    }
    if(ans == 1000000000) ans = -1;
    cout << ans<<endl;
    return 0;
}
