#include <vector>
#include <string>
#include <iostream>
#include <cstdio>
#include <sstream>
#include <cctype>
#include <utility>
#include <algorithm>
#include <math.h>
#include <bitset>
using namespace std;
#define ll long long
#define FOR(i,a,b) for(int i=(a),_b=(b); i<=_b; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b); i>=_b; i--)
#define REP(i,a) for(int i=0,_a=(a); i<_a; i++)
#define EACH(it,a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); ++it)
#define SZ(S) ((int) ((S).k()))
#define DEBUG(x) { cout << #x << " = " << x << endl; }
#define PR(a,n) { cout << #a << " = "; FOR(_,1,n) cout << a[_] << ' '; cout << endl; }
#define PR0(a,n) { cout << #a << " = "; REP(_,n) cout << a[_] << ' '; cout << endl; }

int main(){
  int a, b, c;
  cin >> a >> b >> c;
  bitset<600> bs;
  for(int i = a; i< a+200; i++){
    bs[i] = 1;
  }
  for(int i = b; i< b+200; i++){
    bs[i] = 1;
  }
  for(int i = c; i< c+200; i++){
    bs[i] = 1;
  }
  int total = 0;
  for(int i = 0; i<600; i++){
    if(!bs[i]) total +=100;
  }
  cout << total << endl;
  return 0;
}
