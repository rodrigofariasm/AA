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

#define MAX 100010;
ll MOD = 1000000009;
ll n, x, y;
map<pair<ll, ll>, ll> tab;
vector<pair<ll, ll> > coordenadas;
set<ll> available;
set<ll> unavailable;
queue<ll> ans;

void build(){
    vector<pair<ll,ll> > bases;
    EACH(it, tab){
        if(!unavailable.count(it->second)) available.insert(it->second);
        if(tab.count(make_pair(it->first.first-1, it->first.second-1))) bases.push_back(make_pair(it->first.first-1, it->first.second-1));
        if(tab.count(make_pair(it->first.first, it->first.second-1))) bases.push_back(make_pair(it->first.first, it->first.second-1));
        if(tab.count(make_pair(it->first.first+1, it->first.second-1))) bases.push_back(make_pair(it->first.first+1, it->first.second-1));
        if(bases.size()==1){
            unavailable.insert(tab[bases[0]]);
            available.erase(tab[bases[0]]);
        }
        bases.clear();
    }
}
bool isavailable(pair<int, int> c){
    int b = 0;
    if(!tab.count(c)) return true;
    if(tab.count(make_pair(c.first-1, c.second-1))) b++;
    if(tab.count(make_pair(c.first, c.second-1))) b++;
    if(tab.count(make_pair(c.first+1, c.second-1))) b++;
    if (b==1) return false;
    return true;
}

void att(pair<int, int> c){
    if(tab.count(c)){
        unavailable.erase(tab[c]);
    if(isavailable(make_pair(c.first+1, c.second+1)) && isavailable(make_pair(c.first, c.second+1)) && isavailable(make_pair(c.first-1, c.second+1))){
        available.insert(tab[c]);
    }else{
        available.erase(tab[c]);
        unavailable.insert(tab[c]);
    }
    }
}
void retira(int cubo){
    ans.push(cubo);
    available.erase(cubo);
    pair<ll, ll> c = coordenadas[cubo];
    tab.erase(c);
    att(make_pair(c.first+1, c.second));
    att(make_pair(c.first-1, c.second));
    att(make_pair(c.first+2, c.second));
    att(make_pair(c.first-2, c.second));
    att(make_pair(c.first+1, c.second-1));
    att(make_pair(c.first, c.second-1));
    att(make_pair(c.first-1, c.second-1));
}

void play(){
    set<ll>::iterator it;
    int a = 0;
    while(a!=n ){
        if(a%2 == 0){
            it = available.end();
            it--;
        }else it = available.begin();
        retira(*it);
        a++;
    }
}

void solve(){
    int aux;
    ll result=0, aux2 = 1;
    while(!ans.empty()){
        aux = ans.front();
        ans.pop();
        result = ( result*n + aux) % MOD;
    }
    cout << result%MOD << endl;
}

int main(void){
    FAST;
    cin >> n;
    REP(i, n){
        cin >> x >> y;
        tab.insert(make_pair(make_pair(x, y), i));
        coordenadas.push_back(make_pair(x,y));
    }
    build();
    play();
    solve();
    return 0;
}
