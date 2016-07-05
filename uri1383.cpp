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

bool linha(int (&m)[9][9]){
  REP(i, 9){
    int check[9]= {};
    REP(j, 9){
      if(check[m[i][j]-1] == 0){
        check[m[i][j]-1] = 1;
      }else return false;
    }
  }
  return true;
}

bool coluna(int (&m)[9][9]){
  REP(j, 9){
    int check[9]= {};
    REP(i, 9){
      if(check[m[i][j]-1] == 0){
        check[m[i][j]-1] = 1;
      }else return false;
    }
  }
  return true;
}
bool bloco(int (&m)[9][9]){
  for(int q = 0; q< 9; q+=3){
    for(int q2 =0; q2<9;q2+=3){
      int check[9] = {};
      REP(i, 3){
        REP(j, 3){
          if(check[m[q+i][q2+j] -1] == 0) check[m[q+i][q2+j] -1] = 1;
          else return false;
        }
      }
    }
  }

  return true;
}

int main(){
  int n;
  int m[9][9];
  cin >> n;
  REP(inst, n){
    REP(i, 9){
      REP(j,9){
        cin >> m[i][j];
      }
    }
    printf("Instancia %d\n", inst+1);

    if (linha(m) && coluna(m)&& bloco(m))cout << "SIM\n" << endl;
    else cout << "NAO\n" << endl;
  }
  return 0;
}
