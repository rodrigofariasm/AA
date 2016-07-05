#include <vector>
#include <string>
#include <iostream>
#include <cstdio>
#include <sstream>
#include <cctype>
#include <utility>
#include <algorithm>
#include <math.h>

using namespace std;
#define ll long long
#define FOR(i,a,b) for(int i=(a),_b=(b); i<=_b; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b); i>=_b; i--)
#define REP(i,a) for(int i=0,_a=(a); i<_a; i++)
#define EACH(it,a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); ++it)
#define DEBUG(x) { cout << #x << " = " << x << endl; }
#define PR(a,n) { cout << #a << " = "; FOR(_,1,n) cout << a[_] << ' '; cout << endl; }
#define PR0(a,n) { cout << #a << " = "; REP(_,n) cout << a[_] << ' '; cout << endl; }

int main(){
  int n , k;
  int off[10001];
  cin >> n >> k;
  while(k > 0 || n > 0){
    int a, sum =0;
    REP(i, k){
      cin >>a;
      off[i] =a;
    }
    sum += n - off[0];
    FOR(i, 1, k-1){
      if(off[i-1] > off[i]) sum += off[i-1] - off[i];
    }
    printf("%d\n", sum);
    cin >> n >> k;
  }
  return 0;
}
