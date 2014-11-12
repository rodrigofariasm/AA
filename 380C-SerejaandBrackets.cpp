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

ll left(ll p){return p << 1;}
ll right(ll p){return (p << 1)+1;}

void build(int p, int l, int r){

	if(l==r){
		//T[p].gap = 1;
				
		if(s[l] == '('){
			T[p].fd=1; //falta fechar a direita
		}else{
			T[p].fe=1; // falta fechar a esquerda
		}
		//cout << p << " " << T[p].fe << " " << T[p].fd << " " <<  T[p].gap<< endl;
	}else{
		build(left(p), l, (l+r)/2);
		build(right(p), (l+r)/2+1, r);
		seg p1 = T[left(p)], p2 = T[right(p)];
		int aux = min(p1.fd, p2.fe);
		T[p].gap  = p1.gap + p2.gap + aux;
		T[p].fe = p2.fe + p1.fe - aux;
		T[p].fd = p2.fd + p1.fd - aux;
		//cout << p << " " << T[p].fe << " " << T[p].fd << " " <<  T[p].gap<< endl;
	}
}


seg rmq(ll p, ll l, ll r, ll x, ll y){
	seg ret;
	//cout << p << " gap= " << T[p].gap << endl;
	//cout << x << " = x y= " << y<< endl;
	if(	l > y || r < x){
		ret.gap = -1;
		return ret;	
	} 
	ll mid = (x+y)/2;
	if(x >= l && y <=r){
			return T[p];		
	}else{
		seg p1 = rmq(left(p), l, r, x, mid );
		seg p2 = rmq(right(p), l, r, mid+1, y );
		if(p1.gap == -1){
			return p2;
		}
		if (p2.gap == -1){
			return p1;
		}
		//	cout << "p1= " << p1.gap << " p2 = " << p2.gap << endl;
		ll aux = min(p1.fd, p2.fe);
		//cout << "return = " << p1.gap + p2.gap + aux<<endl;
		ret.gap  = p1.gap + p2.gap + aux;
		ret.fe = p2.fe + p1.fe - aux;
		ret.fd = p2.fd + p1.fd - aux;
		return ret;
	} 
	
	
	
}


void solve(ll l, ll r){
	cout << 2*rmq(1, l, r, 1, s.size()).gap << endl;
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
