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

#define N 20000000
bool mark [N];
vector <int> primeList;
 
void findprimes(){
    memset (mark, true, sizeof (mark));
    mark [0] = mark [1] = false;
 
    for ( int i = 4; i < N; i += 2 )
        mark [i] = false;
 
    for ( int i = 3; i * i <= N; i++ ) {
        if ( mark [i] ) {
            for ( int j = i*i; j<N; j += 2*i )
                mark [j] = false;
        }
    }
 
    primeList.clear ();
    primeList.push_back (2);
 
    for ( int i = 3; i < N; i += 2 ) {
        if ( mark [i] )
            primeList.push_back (i);
    }
}

int main(){
	findprimes();
	int s;
	vector <int> twins;
    for ( size_t i = 1; i < primeList.size (); i++ ) {
        if ( primeList [i] - primeList [i-1] == 2 )
            twins.push_back (primeList [i-1]);
    }
 	while ( scanf ("%d", &s) != EOF ) {
        printf ("(%d, %d)\n", twins[s-1], twins[s-1]+2);
    }
 
    return 0;
}
