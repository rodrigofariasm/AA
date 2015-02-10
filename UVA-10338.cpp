// Rodrigo Farias de Macêdo

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define FOR(i,a,b) for(int i=(a),_b=(b); i<=_b; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b); i>=_b; i--)
#define REP(i,a) for(int i=0,_a=(a); i<_a; i++)
#define EACH(it,a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); ++it)
#define EACHR(it,a) for(__typeof(a.rbegin()) it = a.rbegin(); it != a.rend(); ++it)
#define SZ(S) ((int) ((S).size()))
#define DEBUG(x) { cout << #x << " = " << x << endl; }
#define PR(a,n) { cout << #a << " = "; FOR(_,1,n) cout << a[_] << ' '; cout << endl; }
#define PR0(a,n) { cout << #a << " = "; REP(_,n) cout << a[_] << ' '; cout << endl; }
typedef vector<int> vi;

char factorials[21];
char word[27];
int occurs[26];
ull int results[21];
int main(){
	
	int n;
	ull res;
	cin >> n;
	int cc = 1;
	results[2]=2;
    for(int i=3;i<21;i++)results[i]=results[i-1]*i;
    
	while(n--){
		res = 1;
		scanf("%s", &word);
		for(int j=0;j<=20;j++)factorials[j]=0;
        for(int i=0;i<26;i++)occurs[i]=0;
        int i = strlen(word);
        REP(j, i)  occurs[word[j]-'A']++;
        REP(j, 26) factorials[occurs[j]]++;
        res = results[i];
		for(int j=2;j<=20;j++)
            for(i=1;i<=factorials[j];i++)
                res/=results[j];
		printf("Data set %d: %llu\n",cc++,res);
	}
	return 0;
}
