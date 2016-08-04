
// SPOJ - LCA (Lowest Common Ancestor)

#include <bits/stdc++.h>

#define rep(i,n) for(i=0; i<n; i++)
#define repl(i,n) for(i=1; i<=n; i++)

#define sz(x) (int) x.size()
#define pb(x) push_back(x)
#define all(x) x.begin(),x.end()
#define uu first
#define vv second
#define mem(x, y) memset(x, y, sizeof(x));

#define sdi(x) scanf("%d", &x)
#define sdii(x, y) scanf("%d %d", &x, &y)
#define sdiii(x, y, z) scanf("%d %d %d", &x, &y, &z)
#define sdl(x) scanf("%lld", &x)
#define sdll(x, y) scanf("%lld %lld", &x, &y)
#define sdlll(x, y, z) scanf("%lld %lld %lld", &x, &y, &z)
#define sds(x) scanf("%s", x)
#define pfi(x) printf("%d\n", x)
#define pfii(x, y) printf("%d %d\n", x, y)
#define pfiii(x, y, z) printf("%d %d %d\n", x, y, z)
#define pfl(x) printf("%lld\n", x)
#define pfll(x, y) printf("%lld %lld\n", x, y)
#define pflll(x, y, z) printf("%lld %lld %lld\n", x, y, z)

#define eps 1e-9
#define OK printf("ok\n")
#define DB(x) cout << #x << " = " << x << endl;

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair <int, int> pii;

inline int setBit(int N, int pos) { return N=N | (1<<pos); }
inline int resetBit(int N, int pos) { return N= N & ~(1<<pos); }
inline bool checkBit(int N, int pos) { return (bool)(N & (1<<pos)); }

//int kx[] = {+2, +1, -1, -2, -2, -1, +1, +2};
//int ky[] = {+1, +2, +2, +1, -1, -2, -2, -1}; //Knight Direction
//int fx[] = {+0, +0, +1, -1, -1, +1, -1, +1};
//int fy[] = {-1, +1, +0, +0, +1, +1, -1, -1}; //Four & Eight Direction


const int MAX=100005;
int n, par[MAX][30], level[MAX];
vector <int> graph[MAX], people[MAX][30], single[MAX];

inline void print(vector <int> v) {
    for(auto x:v) cout << x << " ";
    puts("");
}

inline vector <int> Merge(vector <int> x, vector <int> y) {
    vector <int> ret;
    merge(all(x), all(y), back_inserter(ret));
    ret.erase(unique(all(ret)), ret.end());
    if(sz(ret) > 10) ret.erase(ret.begin()+10, ret.end());
    return ret;
}

void dfs(int u, int l) {
    level[u] = l;

    int i, siz=sz(graph[u]);
    rep(i, siz) {
        int v = graph[u][i];
        if(v != par[u][0]) {
            par[v][0] = u;
            people[v][0] = Merge(single[v], single[u]);
            dfs(v, l+1);
        }
    }
}

void init() {
    int i, j;
    mem(par, -1);
    dfs(0, 0);
    for(j=1; (1<<j)<n; j++) {
        rep(i, n) {
            if(par[i][j-1] != -1) {
                par[i][j] = par[ par[i][j-1] ][j-1];
                people[i][j] = Merge(people[i][j-1], people[ par[i][j-1] ][j-1]);
            }
        }
    }
}

inline vector <int> lca(int u, int v) {
    int i, lg;
    vector <int> ret;
    if(level[u] < level[v]) swap(u, v);
    lg = log2(level[u]);
    for(i=lg; i>=0; i--) {
        if(level[u] - (1<<i) >= level[v]) {
            ret = Merge(ret, people[u][i]);
            u = par[u][i];
        }
    }
    if(u == v) return ret;
    lg = log2(level[v]);
    for(i=lg; i>=0; i--) {
        if(par[u][i] != -1 && par[u][i] != par[v][i]) {
            ret = Merge(ret, people[u][i]);
            ret = Merge(ret, people[v][i]);
            u = par[u][i];
            v = par[v][i];
        }
    }
    ret = Merge(ret, people[u][0]);
    ret = Merge(ret, people[v][0]);
    return ret;
}

int main() {
//    freopen("in.txt","r",stdin);
//    freopen("out.txt","w",stdout);

    int m, q, u, v, x, a, i;

    sdiii(n, m, q);
    rep(i, n-1) {
        sdii(u, v);
        u--, v--;
        graph[u].pb(v);
        graph[v].pb(u);
    }
    rep(i, m) {
        sdi(x);
        x--;
        if(sz(single[x]) < 10) single[x].pb(i);
    }
    init();
    while(q--) {
        sdiii(u, v, a);
        vector <int> p;
        if(u == v) p = single[u-1];
        else p = lca(u-1, v-1);
        int k = min(sz(p), a);
        printf("%d", k);
        rep(i, k) printf(" %d", p[i]+1);
        puts("");
    }

    return 0;
}
