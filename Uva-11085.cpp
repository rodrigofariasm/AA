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

int row[8], minMove;

bool flag = true;
int solCounter = 0;
int solutions[100][8];

bool preValid(int r, int c){
	REP(i, c){
		if(row[i] == r || (abs(row[i] - r)) == abs(i-c)){
			return false;
		}
	}
	return true;
}


void prebacktrack(int c, int b, int a){
	if(c == 8 && row[b] == a){
		REP(i, 8){
			solutions[solCounter][i] = row[i];
			
		}
		solCounter++;
		REP(i,8){
        	solutions[solCounter][i]= 7 - solutions[solCounter-1][i];
        }
        solCounter++;
	}
	REP(i, 8){
		if (preValid(i, c)){
			row[c] = i;
			prebacktrack(c+1, b, a);
		}
	}
	
}

void preProcess(){
	prebacktrack(0, 0, 0);
	prebacktrack(0, 0, 1);	
	prebacktrack(0, 0, 2);
	prebacktrack(0, 0, 3);
	//DEBUG(solCounter);
}

bool valid(int c, int l){
    REP(i, c){
		if(row[i] == l || (abs(row[i] - l)) == abs(i-c)){
			return false;
		}
	}
	return true;
}


int main(){
	int testC=0;
    preProcess();
    int sum; 
    while(scanf("%d %d %d %d %d %d %d %d", &row[0], &row[1], &row[2],&row[3],&row[4],&row[5],&row[6],&row[7])!=EOF){
    	REP(i,8) row[i]--;
        testC++;
        
        minMove = 10;
        REP(i, solCounter){
        	sum = 0;
        	REP(j, 8){
        		if(row[j] != solutions[i][j]) sum++;
			}
        	//PR0(solutions[i], 8);
        	//DEBUG(sum);
        	//DEBUG(sumaux);
        	minMove = min(minMove, sum);
        }
        printf("Case %d: %d\n", testC, minMove);
    
    }
    
    
   return 0;   
}
