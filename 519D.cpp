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

int values[26];
ll sum[100090];
vector<int> idx[27];
string S;
int main(void){
    REP(i, 26) cin >> values[i];
    cin >> S;
    sum[0] = values[S[0] - 'a'];
    idx[S[0]-'a'].push_back(0);
    FOR(i, 1, SZ(S)-1){
        sum[i] += sum[i-1] + values[S[i] - 'a'];
        idx[S[i]-'a'].push_back(i);
    }
    int ans = 0;
    REP(i, 27){
        if(idx[i].size() > 1){
            REP(j, SZ(idx[i])-1){
                if(sum[idx[i][j]]-sum[idx[i][j+1]-1] == 0 || idx[i][j]+1 == idx[i][j+1]){
                        ans++;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
