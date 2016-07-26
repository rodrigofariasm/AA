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

void subproblem(int (&m)[9][9], int i, int j){
  int total = m[i][j];
  m[i+2][j+1] = (total - (m[i+2][j] + m[i+2][j+2]))/2;
  m[i+1][j] = m[i+2][j] + m[i+2][j+1];
  m[i+1][j+1] = m[i+2][j+1] + m[i+2][j+2];
}

int main(){
  int n;
  cin >> n;
  int m[9][9];
  REP(inst, n){
    for(int i = 0; i< 9; i+=2){
      for(int j = 0;j <= i; j+= 2){
        cin >> m[i][j];
      }
    }
    for(int i = 0; i< 7; i+=2){
      for(int j = 0;j <= i; j+= 2){
        subproblem(m, i, j);
      }
    }
    for(int i = 0; i< 9; i++){
      for(int j = 0; j <= i; j++){
        if(j) cout << " ";
        cout << m[i][j];
      }
      cout << endl;
    }
  }

  return 0;
}
