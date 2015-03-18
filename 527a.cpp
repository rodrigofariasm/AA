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

char a[200001], b[200001];
vector<int> diffs;
int dist = 0, k=-1, j=-1;
bool hasSwapped = false;

void swap1(){
    if(dist > 1 && !hasSwapped){
        REP(i, dist -1){
            if(a[diffs[i]] == b[diffs[dist-1]] && b[diffs[i]] == a[diffs[dist-1]]){
                hasSwapped = true; k = diffs[i]+1; j = diffs[dist-1]+1;
                dist -= 2;
                break;
            }else if(a[diffs[i]] == b[diffs[dist-1]] || b[diffs[i]] == a[diffs[dist-1]]){
                k = diffs[i]+1; j = diffs[dist-1]+1;

            }
        }


    }

}


int main(void){
    FAST;
    int n;
    cin >> n;
    cin >> a >> b;
    REP(i, n){
        if(a[i]!= b[i]){
            dist++;
            diffs.push_back(i);
            if(!hasSwapped) swap1();
        }
    }
    if(!hasSwapped && k != -1) dist--;
    cout << dist << endl;
    cout << k << " " << j << endl;
    return 0;

}
