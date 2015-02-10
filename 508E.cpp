// Rodrigo Farias de Macêdo

#include <bits/stdc++.h>

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

int n, dp[610][610], st[610][610], l[610], r[610];
int sol[1220];
void solve(int a,int b){
    if(a==b) printf("()");

    else if(dp[a][b]==a){
        if(st[a][b]==1){
            printf("()");
            solve(a+1,b);
        }
        else{
            printf("(");
            solve(a+1,b);
            printf(")");
        }
    }
    else{
        solve(a,dp[a][b]);
        solve(dp[a][b]+1,b);
    }
}

int main(){
    ios :: sync_with_stdio(false);
    int n;
    cin>>n;
    REP(i,n){
        cin>>l[i]>>r[i];
    }
    REP(i,n){
        if(l[i]==1)
            st[i][i]=1;
    }
    FOR(k, 2, n){
        REP(i, n){
            FOR(j, i, i+k-1){
                if(j==i){
                    if(l[i]==1 && st[j+1][i+k-1]>0){
                        dp[i][i+k-1]=j;
                        st[i][i+k-1]=1;
                        break;
                    }
                    if(l[i]<=2*k-1 && r[i]>=2*k-1 && st[j+1][i+k-1]>0){
                        dp[i][i+k-1]=j;
                        st[i][i+k-1]=2;
                        break;
                    }
                }
                else{
                    if(st[i][j]>0 && st[j+1][i+k-1]>0){
                        dp[i][i+k-1]=j;
                        st[i][i+k-1]=1;
                        break;
                    }
                }
            }
        }
    }
    if(st[0][n-1]==0){
        cout<<"IMPOSSIBLE"<<endl;
    }
    else{
        solve(0,n-1);
        printf("\n");
    }
    return 0;
}
