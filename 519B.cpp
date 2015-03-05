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

int n, aux;
map<int, int> numbers, numbers2;
int main(void){
    cin >> n;
    REP(i, n){
        cin >> aux;
        numbers[aux]++;
        numbers2[aux]++;
    }
    REP(i, n-1){
        cin >> aux;
        numbers[aux]--;
    }
    REP(i, n-2){
        cin >> aux;
        numbers2[aux]--;
    }
    EACH(it,numbers){
        if(it->second >= 1){
            cout << it->first << endl;
            numbers2[it->first]--;
        }
    }
    EACH(it,numbers2){
        if(it->second >= 1){
            cout << it->first << endl;
        }
    }

    return 0;
}
