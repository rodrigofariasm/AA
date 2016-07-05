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
  float a, b, c;
  scanf("%f %f %f", &a, &b, &c);
  float delta = (b*b) - (4*a*c);
  if(a == 0 || delta < 0) printf("%s\n", "Impossivel calcular");
  else if(delta == 0) printf("%s = %.5f\n", "R1", -b/(2*a));
  else{
    float r1 = (-b + sqrt(delta)) /(2*a);
    float r2 = (-b - sqrt(delta)) /(2*a);
    printf("%s = %.5f\n", "R1", r1);
    printf("%s = %.5f\n", "R2", r2);
  }

return 0;
}
