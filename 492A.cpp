// Rodrigo Farias de Mac�do

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

const int MN = 1001;
int n;
vector<double> l;
int main(){
	ios :: sync_with_stdio(false);
	cin >> n;
	int lvl = 1;
	int aux = 0;
	int b = 1;
	while(n>0){
		aux = lvl + aux;
		if(n - aux >= 0){
			lvl++;
			n-=aux;
		}else{
			break;
		}
		
		//DEBUG(aux);
		
	}
	cout << lvl-1<<endl;
	return 0;
}
