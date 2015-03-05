// Rodrigo Farias de Macêdo

#include <bits/stdc++.h>

using namespace std;
#define ll long long

int n,k,d;
const int mod = 1e9 + 7;

ll aux[100][2];

int main(){
    ios::sync_with_stdio(0);
    cin >> n >> k >> d;
    aux[0][0] = 1;
    aux[0][1] = 0;
    for(int i = 1; i <= n ; i++){
        aux[i][0] = aux[i][1] = 0;
        for(int j = 1 ; j <= k ; ++j){

            if(i-j < 0) break;

            if(j < d)
            {
                aux[i][0]+= aux[i-j][0];
                aux[i][0] = aux[i][0]% mod;
                aux[i][1]+= aux[i-j][1];
                aux[i][1] = aux[i][1]% mod;
            }
            else
            {
                aux[i][1]+= aux[i-j][0];
                aux[i][1] = aux[i][1]% mod;
                aux[i][1]+= aux[i-j][1];
                aux[i][1] = aux[i][1]% mod;
            }
        }
        //cout << "i= "<< i << " " <<aux[i][0]<<" " <<aux[i][1] << endl;
    }
    cout << aux[n][1] << endl;
    return 0;
}
