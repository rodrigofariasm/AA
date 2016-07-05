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

#define N 100001
int obj[N];
int paths[N], n, pathc[N];
inline bool read()
{
	if (!(cin >> n))
		return false;
   	REP(i, n)
   	 	scanf("%d", &obj[i]);

	REP(i, n){
        cin >> paths[i];
        paths[i]--;
        if (paths[i] != -1)
        	pathc[paths[i]]++;
   	}

   	return true;
}
int main(){
  while(read()){

  vector<int> res;
  REP(i, n){
    if(obj[i] == 1){
        vector<int> aux;
        int idx = i;

        while(paths[idx] != -1 && pathc[paths[idx]] <= 1 ){
          aux.push_back(idx);
          idx = paths[idx];
        }

        aux.push_back(idx);
        if(res.size() < aux.size()) res = aux;

    }
  }
  cout << res.size() << endl;
  reverse(res.begin(), res.end());
  REP(i, res.size()){
  		if (i) cout << " ";
  		cout <<  res[i] + 1;
  }
	puts("");

  }
  return 0;
}
