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

double acum[500005],ans[500005];

bool isVowel(char c){
    return (c == 'A' || c == 'E' || c == 'I' || c == 'O'
            || c == 'U' || c == 'Y');
}

int main() {
    string s;
    cin >> s;
    int len = SZ(s);
    acum[0] = ans[0] = 0;
    FOR(i, 1, len){
        acum[i] += acum[i-1] + isVowel(s[i-1]);
    }
    FOR(i, 1, len+1){
        ans[i] = ans[i-1] +(acum[len-i+1]- acum[i-1]);
    }
    double result = 0.0;
    FOR(i, 1, len+1){
        result += ans[i] /(i);
    }
    printf("%.6f\n", result);
    return 0;
}
