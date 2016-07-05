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
  float a, b, c, d, e;
  scanf("%f %f %f %f", &a, &b, &c, &d);
  float average = (2*a + 3*b + 4*c + d)/ 10;
  printf("Media: %.1f\n", average);
  if(average >= 7.0){
    printf("Aluno aprovado.\n");
  }else if(average < 5.0) printf("Aluno reprovado.\n" );
  else {
    printf("Aluno em exame.\n");
    scanf("%f", &e);
    average = (average + e)/2;
    printf("Nota do exame: %.1f\n", e);
    (average<5.0) ? printf("Aluno reprovado.\n") : printf("Aluno aprovado.\n");
    printf("Media final: %.1f\n", average);

  }
return 0;
}
