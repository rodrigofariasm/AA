// Rodrigo Farias de Macêdo

#include <bits/stdc++.h>

using namespace std;
#define ll long long
#define FOR(i,a,b) for(int i=(a),_b=(b); i<=_b; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b); i>=_b; i--)
#define REP(i,a) for(int i=0,_a=(a); i<_a; i++)
#define EACH(it,a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); ++it)
#define SZ(S) ((int) ((S).size()))
#define DEBUG(x) { cout << #x << " = " << x << endl; }
#define PR(a,n) { cout << #a << " = "; FOR(_,1,n) cout << a[_] << ' '; cout << endl; }
#define PR0(a,n) { cout << #a << " = "; REP(_,n) cout << a[_] << ' '; cout << endl; }

struct User{
	int status;
	int cont;
	vector<int> amigos;
	vector<int> amigosP;
};

int n, m, q;
const int sqr = 500;
vector<User> users(50000);

void change(int u){
	users[u].status = 1-users[u].status;
	if(users[u].amigos.size() < sqr){
		REP(i, users[u].amigos.size()){
			if(users[users[u].amigos[i]].status == 1){
				users[users[u].amigos[i]].cont ++;
			}else users[users[u].amigos[i]].cont--;
		}
	}
	PR0(users[u].amigos,users[u].amigos.size());
}

void add(int a, int b){
	if(users[a].amigos.size()+1 >=sqr && users[a].amigos.size() < sqr ){
		users[a].amigos.push_back(b);
		REP(i, users[a].amigos.size()){
			users[users[a].amigos[i]].amigosP.push_back(a);
			users[users[a].amigos[i]].cont+= users[a].status;
		}
		users[b].amigosP.push_back(a);
	}else if(users[a].amigos.size() >= sqr){
		users[a].amigos.push_back(b);
		users[b].amigosP.push_back(a);
	}else{
		users[a].amigos.push_back(b);
		users[a].cont += users[b].status;
	}
	PR0(users[a].amigos,users[a].amigos.size());
}

void del(int a, int b){
	if(users[a].amigos.size()-1 <sqr && users[a].amigos.size() >= sqr ){
		users[a].cont -= users[b].status;
		REP(i, users[b].amigosP.size()){
		if(users[b].amigosP[i] == a){
			users[b].amigosP.erase(users[b].amigosP.begin()+i);
		}
		}
	}else if(users[a].amigos.size()-1 >= sqr){
		users[a].cont -= users[b].status;
		REP(i, users[b].amigosP.size()){
		if(users[b].amigosP[i] == a){
			users[b].amigosP.erase(users[b].amigosP.begin()+i);
		}
		}
	}
	REP(i, users[a].amigos.size()){
		if(users[a].amigos[i] == b){
			users[a].amigos.erase(users[a].amigos.begin()+i);
		}
	}
	//PR0(users[a].amigos,users[a].amigos.size());
}

void count(int a){
	int aux = users[a].cont;
	REP(i, users[a].amigosP.size()){
		DEBUG(aux);
		aux += users[users[a].amigosP[i]].status;
	}
	cout << aux << endl;
}

int main(){
	ios :: sync_with_stdio(false);
	char op;
	int a, b;	
	cin>> n >> m >> q;
	users.resize(n+1);
	int o, aux;
	cin>> o;
	REP(i, o){
		cin >> aux;
		change(aux);
	}
	
	REP(i, m){
		cin >> a >> b;
		add(a, b);
		add(b, a);
	}

	REP(i,q){
		cin >> op;
		if(op == 'O' || op == 'F'){
			cin >> a;
			change(a);
		}else if(op == 'C'){
			cin >> a;
			count(a);
		}else if(op == 'A'){
			cin >> a >> b;
			add(a,b);
			add(b,a);
		}else if(op == 'D'){
			cin >> a >> b;
			del(a,b);
			del(b,a);
		}
	}
	
	return 0;
}
