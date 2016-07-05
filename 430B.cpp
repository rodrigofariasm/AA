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
int delet(vector<int> v){

  int aux=0 , b, j = 0;
  REP(i, v.size()-1){
    aux = 0;
    while(v[i+ aux + 1] == v[i] && i+aux+1 < v.size()){
      aux++;
    }
    //DEBUG(aux);
    if(aux > j){
      j = aux; b = i;
    }
  }
  if(j > 1){
    vector<int> vaux(v.begin(), v.begin()+b);
    vaux.insert(vaux.end(), v.begin()+b+j+1, v.end());
    //PR(vaux, vaux.size());
    return j + 1 + delet(vaux);
  }
  return 0;

}
int main(){
  int n , k, x;
  vector<int> v;
  cin >> n >> k >> x;
  int a, b, sum=0;
  REP(i, n){
    cin >> a;
    v.push_back(a);
  }
  for(int i = 0; i < n-1; i++){
    int sumaux =0;
    int aux = 0;
    if(v[i] == x){
      aux = 0;
      while (v[i+ aux + 1] == v[i]){
        aux ++;
      }
      if(aux > 0){
        vector<int> vaux(v.begin(), v.begin()+i);
        vaux.insert(vaux.end(), v.begin()+i+aux+1, v.end());
      //  PR0(vaux, vaux.size());
    //    DEBUG(aux);
    //    DEBUG(i);
        sumaux += aux+1;
        sumaux += delet(vaux);
      }

    }
    sum = max(sum, sumaux);
  }
  cout << sum << endl;


  return 0;
}
