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

void findInterval(float x){
  float intervals[] = {0.0, 25.0, 50.0, 75.0, 100.0};
  if(x < 0 || x > 100){
     printf("%s\n", "Fora de intervalo");
     return;
   }
  for(int i = 1; i < 5; i++){
    if(x <= intervals[i]){
        if(i == 1){
          printf("%s\n","Intervalo [0,25]" );
        }else{
          printf("Intervalo (%d,%d]\n", int(intervals[i-1]), int(intervals[i]));
        }
      return;
    }
  }
  return;
}

int main(){
  float a;
  scanf("%f", &a);
  findInterval(a);

return 0;
}
