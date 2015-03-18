#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define MEMO(A, B) memset(A,B,sizeof(A));
#define FAST ios :: sync_with_stdio(false);
#define FOR(i,a,b) for(int i=(a),_b=(b); i<=_b; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b); i>=_b; i--)
#define REP(i,a) for(int i=0,_a=(a); i<_a; i++)
#define EACH(it,a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); ++it)
#define SZ(S) ((int) ((S).size()))
#define DEBUG(x) { cout << #x << " = " << x << endl; }
#define PR(a,n) { cout << #a << " = "; FOR(_,1,n) cout << a[_] << ' '; cout << endl; }
#define PR0(a,n) { REP(_,n) cout << a[_] << ' '; cout << endl; }

#define MAX 1000000
vector< vector<pair<int, int> > > G;
vector<int> taken;
priority_queue<pair<int, int> > pq;
int n, k, m, u, v, w, c=0;

void process(int vtx){
    taken[vtx] = 1;
    REP(j, G[vtx].size()){
        pair<int, int> v = G[vtx][j];
        if(!taken[v.second]){
           pq.push(make_pair(-v.first, -v.second));
        }
    }
}

int prim(){
    ll cost = 0;
    process(0);
    while(!pq.empty()){
       pair<int, int> f = pq.top(); pq.pop();
       u = -f.second; w = -f.first;
       if(!taken[u]){
           cost += w, process(u);
        }
    }



}

int main(void){
    FAST;
    while (scanf("%d", &n ) == 1){
        G.resize(n+1);
        taken.push_back(0);
        c++;
        if (c > 1) printf("\n");
        REP(i, n-1){
            scanf("%d %d %d\n", &u, &v, &w);
            taken.push_back(0);
            G[u-1].push_back(make_pair(w, v-1));
            G[v-1].push_back(make_pair(w, u-1));
        }
        printf("%d\n", prim());
        G.clear();
        taken.clear();
        G.resize(n+1);
        taken.push_back(0);

        scanf("%d", &k);
        REP(i, k){
            scanf("%d %d %d\n", &u, &v, &w);
            taken.push_back(0);
            G[u-1].push_back(make_pair(w, v-1));
            G[v-1].push_back(make_pair(w, u-1));
        }
        scanf("%d", &m);
        REP(op, m){
            scanf("%d %d %d\n", &u, &v, &w);
            taken.push_back(0);
            G[u-1].push_back(make_pair(w, v-1));
            G[v-1].push_back(make_pair(w, u-1));
        }
        printf("%d\n", prim());
        G.clear();
        taken.clear();
    }
    return 0;

}
