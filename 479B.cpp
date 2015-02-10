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

int n, k, tw[110], moves[2010], mn, mx, idxmx,idxmn;
void printM(){
    for(int i = 0; i < 2010; i+=2){
        if(moves[i] != -1){
            printf("%d %d\n", moves[i], moves[i+1]);
        }else break;
    }
}

int main(){
	ios :: sync_with_stdio(false);

    memset(moves, -1, 8040);
    scanf("%d %d", &n, &k);
    REP(i, n){
        scanf("%d", &tw[i]);
    }
    int moveCount = 0;
    REP(hue, k){
        mx = -1, mn = 10009;
        idxmx = 0; idxmn = 0;

        REP(i, n){
            if(tw[i] < mn){
                mn = tw[i];
                idxmn = i+1;
            }
            if(tw[i] > mx){
                mx = tw[i];
                idxmx = i+1;
            }
        }
        if(mx - mn > 1){
            moves[moveCount] = idxmx;
            moves[moveCount+1] = idxmn;
            tw[idxmn-1]++;
            tw[idxmx-1]--;
            moveCount += 2;
        }else{
            printf("%d %d\n", mx-mn, hue);
            printM();
            break;
        }
        if(hue + 1 == k){
            mx = -1, mn = 10009;
            REP(i, n){
                if(tw[i] <= mn){
                    mn = tw[i];
                    idxmn = i+1;
                }
                if(tw[i] >= mx){
                    mx = tw[i];
                    idxmx = i+1;
                }
            }
            printf("%d %d\n", mx-mn, k);
            printM();
        }
    }
	return 0;
}

