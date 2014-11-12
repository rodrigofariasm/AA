//Rodrigo Farias
#include <bits/stdc++.h>
using namespace std;
typedef long long lint;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;


int arr[100004];
int original[100004], n;

struct seg{
  int sum;
  int flag;
};
 
const int tmax = (int)1e5 + 100;
 
seg T[tmax * 4];
int left(int p){return p << 1;}
int right(int p){return (p << 1)+1;}
 
void doLazy(  int node, int ini, int fim ){
  if( T[node].flag ){
    T[node].sum += (fim - ini + 1) * T[node].flag;
    if( ini != fim ) {
      T[left(node)].flag += T[node].flag;
      T[right(node)].flag += T[node].flag;
    }
    T[node].flag = 0;
  }
}
 
void update( int i, int j, int node, int ini , int fim , int valor){
  doLazy(node,ini,fim);
  if( i > fim || j < ini || ini > fim || i > j ) return;
  if( i <= ini && j >= fim ){
    T[node].flag += valor;
    doLazy(node,ini,fim);
    return;
  }
  update(i,j,left(node),ini,(ini+fim)/2,valor);
  update(i,j,right(node),(ini+fim)/2+1,fim,valor);
  T[node].sum = T[left(node)].sum + T[right(node)].sum;
}
 
int get( int i, int j,  int node = 0, int ini = 0, int fim = n -1){
  doLazy(node,ini,fim);
  if( i > fim || j < ini || ini > fim ) return 0;
  if( i <= ini && j >= fim ) return T[node].sum;
  return get(i,j,left(node),ini,(ini+fim)/2) + get(i,j,right(node),(ini+fim)/2+1,fim);
}

int main(){

	int  ins, o, l, r;
	int value, aux;
	
	cin >> n;
	for(int i = 0; i<n; i++){
		cin >> aux;
		update(i,i,1,0,n-1,aux);
	}
	scanf("%d", &ins);
	for(int i = 0; i<n*2; i++){
		cout << T[i].sum << "sum i " << i << endl;
	}
	for(int i = 0; i<ins; i++){
		scanf("%d", &o);
		if(o == 1){
			cin >> l >> r;
			get(l,r, 1, 0, n-1);
		}else{
			cin >> l >> r >> value;
			update(i,i,1,0,n-1,value);
			
		}
	}
}

