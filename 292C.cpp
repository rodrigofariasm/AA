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
map<int, ll> fat;
int a, occurs[10];
ll total;
char number[17];
char ans[50];

void init(){
    fat['0'] = 1;
    fat['1'] = 1;
    FOR(i, 2, 9){
        char aux[10], aux2[10];
        itoa(i,aux, 10);
        itoa((i-1),aux2, 10);
        fat[aux[0]] = fat[aux2[0]] * i;
    }
}

void nayvePrimeFactors(){
    REP(i, a){
        if(number[i] == '2') occurs[2]++;
        else if(number[i] == '3'){
            occurs[2]++;
            occurs[3]++;
        }else if(number[i] == '4'){
            occurs[2]+=3;
            occurs[3]++;
        }else if(number[i] == '5'){
            occurs[2]+=3;
            occurs[3]++;
            occurs[5]++;
        }else if(number[i] == '6'){
            occurs[2]+=4;
            occurs[3]+=2;
            occurs[5]++;
        }else if(number[i] == '7'){
            occurs[2]+=4;
            occurs[3]+=2;
            occurs[5]++;
            occurs[7]++;
        }else if(number[i] == '8'){
            occurs[2]+=7;
            occurs[3]+=2;
            occurs[5]++;
            occurs[7]++;
        }else if(number[i] == '9'){
            occurs[2]+=7;
            occurs[3]+=4;
            occurs[5]++;
            occurs[7]++;
        }
   }
}

void solve(){
    int pos = 0;
    while(occurs[2] > 0 || occurs[3] > 0 || occurs[5] > 0 || occurs[7] > 0 ){
        if(occurs[7] > 0){
            occurs[7]--;
            occurs[5]--;
            occurs[3]-=2;
            occurs[2]-=4;
            ans[pos] = '7';
            pos++;
        }else if(occurs[5] > 0){
            occurs[5]--;
            occurs[3]-=1;
            occurs[2]-=3;
            ans[pos] = '5';
            pos++;
        }else if(occurs[3] > 0){
            occurs[3]-=1;
            occurs[2]-=1;
            ans[pos] = '3';
            pos++;
        }else if(occurs[2] > 0){
            occurs[2]-=1;
            ans[pos] = '2';
            pos++;
        }

    }
    REP(i, pos) cout << ans[i];
    cout << endl;
}

int main() {
    init();
    cin >> a;
    cin >> number;
    nayvePrimeFactors();
    solve();
    return 0;
}
