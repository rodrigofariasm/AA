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

int row[8], TC, a ,b, lineC;

bool valid(int r, int c){
	REP(i, c){
		if(row[i] == r || (abs(row[i] - r)) == abs(i-c)){
			return false;
		}
	}
	return true;
}


void backtrack(int c){
	if(c == 8 && row[b] == a){
		printf("%2d      %d", ++lineC, row[0]+1);
		FOR(j, 1, 7) printf(" %d", row[j]+1);
		printf("\n");
	}
	REP(i, 8){
		if (valid(i, c)){
			row[c] = i;
			backtrack(c+1);
		}
	}
	
}


int main(){
	scanf("%d", &TC);
	while(TC--){
		scanf("%d %d", &a, &b); a--; b--;
		memset(row, 0, sizeof row);
		lineC= 0;
		printf("SOLN       COLUMN\n");
		printf(" #      1 2 3 4 5 6 7 8\n\n");
		backtrack(0);
		if(TC) printf("\n");
	}
	return 0;
}
