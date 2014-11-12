// Rodrigo Farias de Macêdo

#include <bits/stdc++.h>

using namespace std;
#define ll long long

const ll MAXVAL = 1000100000;
ll n, m, w;
vector<ll> a;

void read(){
    cin >> n >> m >> w;
    a.resize(n);
    for (ll i = 0; i < n; i++)
        cin >> a[i];
}

bool check(ll x){
    vector<ll> st(n,0);
    ll falta = 0;
    ll moves = 0;
   
    for (ll i = 0; i < n; i++)
    {
        falta -= i - w >= 0 ? st[i - w] : 0;

        if (a[i] + falta < x)
        {
            st[i] = x - a[i] - falta;
            
            falta += st[i];
            moves += st[i];
        }
        if (moves > m)
            return 0;
    }
    return moves <= m;
}
void solve(){
    ll l = 1;
    ll r = MAXVAL;
    ll x;
    bool aux;
    while (l <= r){ //bs
        ll mid = (l + r) >> 1;
        aux = check(mid);
		//cout << aux << " mid = " << md	<<endl;
        if (aux){
            x = mid;
            l = mid + 1;
        }else r = mid - 1;
    }

    cout << x << endl;
}

int main(){
	ios_base::sync_with_stdio(0);
    read();
    solve();
    return 0;
}
