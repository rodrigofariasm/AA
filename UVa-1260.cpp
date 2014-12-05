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
#define PR0(a,n) { cout << #a << " = "; REP(_,n) cout << a[_] << ' '; cout << endl; }

int n, m;
vector<int> numb;//numbers 

void solve(int q){
	int CS = 1e18; //closestSum
	int minDif = 1e18; //closestSum
	int sum;
	int dif;
	REP(i, n-1){
		FOR(j, i+1, n-1){
			sum = numb[i] + numb[j];
			dif = abs(q-sum);
			
			if(dif < minDif){
				minDif = dif;
				CS = sum;
			} 
			if(sum > q) break;
		}
	}
	printf("Closest sum to %d is %d.\n", q, CS);
	
}

int main(){
	int TC = 0;
	scanf("%d", &n);
	int query, aux;
	while(n!=0){
		TC++;
		printf("Case %d:\n", TC);
		REP(i, n){
			scanf("%d", &aux);
			numb.push_back(aux);
		}
		sort(numb.begin(), numb.begin()+n);
		scanf("%d", &m);
		REP(i, m){
			scanf("%d", &query);
			solve(query);
		}
		numb.erase(numb.begin(), numb.begin()+n);
		scanf("%d", &n);
		
	}
	return 0;
}
