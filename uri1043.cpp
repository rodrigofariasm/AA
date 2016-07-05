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
#define SZ(S) ((int) ((S).k()))
#define DEBUG(x) { cout << #x << " = " << x << endl; }
#define PR(a,n) { cout << #a << " = "; FOR(_,1,n) cout << a[_] << ' '; cout << endl; }
#define PR0(a,n) { cout << #a << " = "; REP(_,n) cout << a[_] << ' '; cout << endl; }

int main(){
  float sides[3];
  scanf("%f %f %f", &sides[0], &sides[1], &sides[2]);
  float mx = max(sides[0], sides[1]);
  mx = max(mx, sides[2]);
  mx = mx + mx - (sides[0] + sides[1] + sides[2]);

  if(mx < 0){
    float perimetro = sides[0] + sides[1] + sides[2];
    printf("Perimetro = %.1f\n", perimetro);
  }else{
    float area = (sides[0]+sides[1])/2 * sides[2];
    printf("Area = %.1f\n", area);
  }
return 0;
}
