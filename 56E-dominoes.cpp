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
#define MAX 100001

struct domino {
	ll pos;
	ll h;
	int o;
	bool m ;
	int chain;
};
bool  comp(domino d1,domino d2)
 {
  return d1.pos>d2.pos;
 }
struct sort_pred2 {
    bool operator()(const domino &left, domino &right) {
        return left.o > right.o;
    }
};


vector<domino>dom;
int result[100001];
int main(){
		int n;
		ll pos, h;
		struct domino d;
		cin >> n;
		REP(i, n){
			cin >> pos >> h;
			d.o  = i;
			d.pos = pos;
			d.h = h;
			d.chain= 1;
			dom.push_back(d);
		}
		sort(dom.begin(), dom.end(), comp);

		for(int i = 1; i <n; i++){
			int j = i-1;
			while(j >= 0 && dom[j].pos <= dom[i].pos+dom[i].h-1){
				dom[i].chain+=dom[j].chain;
				j-=dom[j].chain;
			}
		}
		//organizando output
		for(int i=0;i<n;i++)
    {
      result[dom[i].o]=dom[i].chain;
    }
    REP(i, n) cout<<result[i]<<" ";
		cout << endl;
}
