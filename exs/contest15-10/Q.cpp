#include<bits/stdc++.h>

#define _ ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define sz(x) (int)(x).size()
#define pb push_back
#define eb emplace_back
#define vi vector<int>
#define all(x)  (x).begin() , (x).end()
#define fs first
#define sc second
#define ii pair<int, int>
#define vii vector<ii>
#define endl '\n'
#define ll long long int
#define MAXX 1073741823
#define MAX (1<<20)
#define INF 0x3f3f3f3f
#define MODN 1000000007
#define int long long // -> solução divina

using namespace std;

int n;
int v[55];
int resp;
int memo[55][55][55];

// int bb(int x, int ini, int fim){ //Achar o primeiro menor que x
//     if (ini > fim) return ini;
    
//     int mid = ini + (fim - ini)/2;

//     // cout << ini << ' ' << mid << ' ' << fim << endl;

//     if (v[mid] < x) return bb(x, mid+1, fim);
//     else if (ini == fim) return fim;
//     else if (v[mid] >= x) return bb(x, ini, mid);
// }


int bb(int x, int ini, int fim){
    int in = ini, fm = fim+1, mid;
    while(in<fm) {
        mid = in + (fm-in)/2;
        if (v[mid] >= x) fm = mid;
        else in = mid + 1;
    }

    return in;
}

int f(int a, int ini, int fim){
    if(memo[a][ini][fim] != -1 ) return memo[a][ini][fim];
    if (ini == fim) return 0;
    int ratual = 0;

    for(int j=ini; j<=fim; j++){
        // int ind = (lower_bound(vx.begin() + j+1, vx.begin() + n, v[i] + v[j]) - vx.begin() - 1);

        int ind = bb(v[a] + v[j], j+1, fim) - 1;
        // cout << ind << endl;

        ratual += ind - j;
        ratual += f(a, j+1, ind); 
    }

    return memo[a][ini][fim] = ratual;
}

signed main(){_

    cin >> n;

    memset(memo, -1, sizeof(memo));

    for(int i=1; i<=n; i++){
        cin >> v[i];
    }

    sort(v+1, v+n+1);
    vector<int> vx(v, v+1+n);

    for(int i=1; i<=n-1; i++){
        resp += f(i, i+1, n);
    }   

    cout << resp << endl;

    return 0;
}
