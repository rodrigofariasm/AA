#include <vector>
#include <string>
#include <iostream>
#include <cstdio>
#include <sstream>
#include <cctype>
#include <utility>
#include <algorithm>
#include <math.h>

using namespace std;
#define ll long long
#define FOR(i,a,b) for(int i=(a),_b=(b); i<=_b; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b); i>=_b; i--)
#define REP(i,a) for(int i=0,_a=(a); i<_a; i++)
#define EACH(it,a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); ++it)
#define DEBUG(x) { cout << #x << " = " << x << endl; }
#define PR(a,n) { cout << #a << " = "; FOR(_,1,n) cout << a[_] << ' '; cout << endl; }
#define PR0(a,n) { cout << #a << " = "; REP(_,n) cout << a[_] << ' '; cout << endl; }
vector<ll> bit;
ll Q(int idx){
	ll sum=0;
    while(idx>0) {
        sum+=bit[idx];
        idx -= idx&-idx;
    }
    return sum;
}

void U(int idx, ll val){
	while(idx<bit.size()){
		bit[idx] += val;
		idx += idx&-idx;
	}
}

int main(){
	int tc, n, idx;
	cin >> tc;
	REP(t, tc){
		cin >> n;
		vector<ll>  A, cpA;
		ll ans = 0;
		A.assign(n, 0);
		bit.assign(n, 0);
		REP(i, n){
			cin >> A[i];
		}
		cpA = A;
		sort(cpA.begin(), cpA.end()); //ordenando a cópia.
		//mapeando valores para trabalhar com indices menores
		REP(i, n){
			// não sei porque o - .begin estava na referencia da funcao
			idx = lower_bound(cpA.begin(), cpA.end(), A[i]) - cpA.begin();
			A[i] = idx+1;
		}
		FORD(i, n-1, 0){
			ans += Q(A[i]-1);
			U(A[i],1);
		}
		cout << ans << endl;
	}
  return 0;
}
