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


#define MAX 50
int n, m;
char tab[MAX][MAX];
bool visited[MAX][MAX];

#define DFS(nx,ny){ if(nx>=0&&nx<n&&ny>=0&&ny<m&&(nx!=fx||ny!=fy)&&tab[nx][ny]==tab[x][y]&&dfs(nx,ny,x,y))return true;}
bool dfs(int x,int y,int fx,int fy){
	if(visited[x][y])return true;
	visited[x][y] = true;
	DFS(x-1, y);
	DFS(x+1,y);
	DFS(x,y-1);
	DFS(x,y+1);

	return false;
}

int main() {
    cin >> n >> m;
    REP(i,n){
        REP(j, m){
            cin >> tab[i][j];
        }
    }
    REP(i, n){
        REP(j, m){
          if(!visited[i][j]&&dfs(i,j,-1,-1)){
              puts("Yes");
              return 0;
          }
        }
    }

    puts("No");
    return 0;
}
