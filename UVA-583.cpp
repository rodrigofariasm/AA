// Rodrigo Farias de Macêdo

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define FOR(i,a,b) for(int i=(a),_b=(b); i<=_b; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b); i>=_b; i--)
#define REP(i,a) for(int i=0,_a=(a); i<_a; i++)
#define EACH(it,a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); ++it)
#define EACHR(it,a) for(__typeof(a.rbegin()) it = a.rbegin(); it != a.rend(); ++it)
#define SZ(S) ((int) ((S).size()))
#define DEBUG(x) { cout << #x << " = " << x << endl; }
#define PR(a,n) { cout << #a << " = "; FOR(_,1,n) cout << a[_] << ' '; cout << endl; }
#define PR0(a,n) { cout << #a << " = "; REP(_,n) cout << a[_] << ' '; cout << endl; }
typedef vector<int> vi;
bitset<1000000> nprime;
vi primos;
vi results;
void findprimes(){
	int length = 1000000;
 
    for ( int i = 2; i <= length; i++ ) {
    	if(!nprime[i]){
    		primos.push_back(i);
    	}
        for ( int j = i * 2; j < 1000005; j += i )
            nprime [j] = true;
    }
 	
}

int main(){
	findprimes();
	ll n, res;
	cin >> n;
	while(n!= 0){
		res = n;
		
		if(n < 0){
			results.push_back(-1);
			res = res/-1;
		}
		int idx = 0;
		while(res != 1){
			DEBUG(res);
			if(res%primos[idx] == 0){
				res = res/primos[idx];
				results.push_back(primos[idx]);
			}else{
				idx++;
			}
		}
		printf("%d = ", n);
		REP(i, results.size()-1) printf("%d x ", results[i]);
		printf("%d\n", results[results.size()-1]);
		
		
		cin >> n;
		results.clear();
	}
	
	
}
