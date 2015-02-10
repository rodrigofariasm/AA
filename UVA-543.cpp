// Rodrigo Farias de Macêdo

#include <bits/stdc++.h>
using namespace std;
#define ll long long
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

void findprimes(){
	int length = (int) sqrt (1000005);
 
    for ( int i = 2; i <= length; i++ ) {
        for ( int j = i * 2; j < 1000005; j += i )
            nprime [j] = true;
    }
 
}

int main(){
	int a;
	findprimes();
	cin >> a;
	bool flag = false;
	while(a != 0){
		FORD(i, a-3, 3){
			if(!nprime[i] && !nprime[a-i]){
				printf("%d = %d + %d\n", a, a-i, i);
				flag = true;
				break;
			}
		}
		if(!flag){
			printf("Goldbach's conjecture is wrong.\n");
		}
		cin >> a;
	}
	
	return 0;
}
