// Rodrigo Farias de Macêdo

#include <bits/stdc++.h>

using namespace std;
#define ll long long

struct seg{
	ll gap;
	ll fe; 
  	ll fd;
  	
};
const ll MAXVAL = 1000000;
ll q, l, r;
string s;
seg T[MAXVAL*4];

ll rmq(ll p, ll l, ll r, ll x, ll y){
	cout << p << " gap= " << T[p].gap << endl;
	cout << l << " = l r= " << r<< endl;
	if(	l > y || r < x) return 0;
	ll mid = (x+y)/2;
	if(l >= x && r <=y){
		if(check(T[p])){
			cout << "will return " << T[p].gap << endl;
			return T[p].gap;		
		}else{
			return 0;
		}
	} 
	
	ll p1 = rmq(left(p), l, mid, x, y );
	ll p2 = rmq(right(p), mid+1, r, x, y );
	cout << "p2gap = " << T[p2].gap<<endl;
	
	if(p1 == 0) return p2;
	//cout << "will return " << T[p1].gap << endl;
	if(p2 == 0) return p1;
	return T[p1].gap <= T[p2].gap ? p1:p2;
	
}


void solve(ll l, ll r){
	cout << rmq(1, l, r, 0, s.size()) << endl;
}
void read(){
    cin >> s;
    
    build(1, 0, s.size()-1);
    cin >> q;
    while(q--){
    	cin >> l >> r;
    	solve(l,r);
    }
}

int main(){
	ios_base::sync_with_stdio(0);
    read();
    return 0;
}
