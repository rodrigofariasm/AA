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

void genNext(vector<int> (&m)){
  int j;
  vector<int> nm;
  for(int i = 0; i < m.size(); i++){
    j = 0;
    while(m[i] == m[i+j] && i+j < m.size()) j++;

    nm.push_back(j);
    j--;
    nm.push_back(m[i]);
    i += j;
  }
  m = nm;
}

int main(){
  int n;

  while((cin >> n) && n <=40){
    vector<int> seq;
    seq.push_back(3);
    REP(i, n-1){
      genNext(seq);
    }
    REP(i, seq.size()){
      cout << seq[i];
    }
    cout << endl;
  }
  return 0;
}
