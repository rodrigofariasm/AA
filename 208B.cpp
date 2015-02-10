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

string s;

void melhorPior(){
    FORD(i, SZ(s)-2, 0){
            if((s[i] - '0') % 2 == 0){
               char temp = s[i];
               s[i] = s[SZ(s)-1];
               s[SZ(s)-1] = temp;
               break;
               }
       }
}

void piorMelhor(){
    int ui = s[SZ(s) - 1] - '0';
     bool flag = false;
        FOR(i, 0, SZ(s)-1){
            if((s[i] - '0') % 2 == 0 && (s[i]-'0') < ui) {
               char temp = s[i];
               s[i] = s[SZ(s)-1];
               s[SZ(s)-1] = temp;
               flag = true;
               break;
               }
        }
        if(!flag) melhorPior();
}

int main(){
	ios :: sync_with_stdio(false);

    cin >> s;
    int j = 0;
    while((s[j] - '0')%2 == 1){
        j++;
    }


    if(j >= SZ(s) -1 ){
        cout << -1 << endl;
    }else{
       piorMelhor();
       cout << s << endl;
    }

	return 0;
}
