//Rodrigo Farias
#include <bits/stdc++.h>
using namespace std;
typedef long long lint;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;


int arr[100004];
int original[100004];


int XOR(int value, int aux){
//	cout <<  (value ^ aux)  <<endl;
	return value^aux;	
}

int  rsq( int y){
	 int y1;
	 int sum = 0;
	 for(y1 = y; y1 > 0; y1 -= y1&(-y1)){
	 		sum += arr[y1];
	 }
	 return sum;
}

int update(int y, int value){
	int a=value;
    for(int i=y;i<100004;i+=(i & -i)){
    	arr[i]+=a;	
    } 
}


void rsqX( int l, int r, int value){
	int a, aux2;
    for(int i=l;i<=r;i++){
    	aux2 = XOR(value, original[i]);
    	a= aux2 - original[i];
    	original[i] = aux2;
    	update(i, a);		
    } 
}


int main(){

	int n, ins, o, l, r;
	int value, aux;
	
	cin >> n;
	for(int i = 1; i<=n; i++){
		cin >> aux;
		original[i] = aux;
		update(i, aux);
	}
	scanf("%d", &ins);
	for(int i = 0; i<ins; i++){
		scanf("%d", &o);
		if(o == 1){
			cin >> l >> r;
			aux = rsq(r) - (l==1 ? 0 : rsq(l-1));
			cout << aux << endl;
		}else{
			cin >> l >> r >> value;
			rsqX(l,r,value);
			
		}
	}
}
	
