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

int genNumber(string s){
  int sum = 0;
  REP(i, s.size()){
    sum += s[i] - '0';

  }
  if(sum < 10) return sum;
  else return genNumber(to_string(sum));

}

int main(){
  string n, m;

  while(!(cin >> n >> m) || n != "0" || m!= "0" ){
    int a = genNumber(n);
    int b = genNumber(m);
    if(a > b) cout << 1 << endl;
    else if(b >a) cout << 2 << endl;
    else cout << 0 << endl;
  }
return 0;
}
