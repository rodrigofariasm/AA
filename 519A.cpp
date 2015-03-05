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

int white = 0, black = 0;
int main(void){
    map<char, int> tab;
    tab['Q']=9; tab['R']=5; tab['B']=3; tab['N']=3; tab['P']=1; tab['K']=0;
    char aux, aux2;
    REP(i, 64){
        cin >> aux;
        aux2 = toupper(aux);
        if(aux != aux2) black += tab[aux2];
        else white += tab[aux2];
    }
    if(white > black){
        cout << "White"<<endl;
    }else if(white < black){
        cout << "Black"<<endl;
    }else cout << "Draw" << endl;
    return 0;
}
