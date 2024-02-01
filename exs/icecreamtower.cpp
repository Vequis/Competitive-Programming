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

int temp[312345];
int a[312345];
int k;
int n;

bool solve(int qtd) {

    for(int i = 1; i <= qtd; i++) temp[i] = 0;

    int cont = k;
    int idxcont = 1;
    int ptr = 1;
    while(cont > 0) {
        while(ptr != n+1 and idxcont != qtd+1) {
            if (a[ptr] >= 2*temp[idxcont]) {
                temp[idxcont] = a[ptr];
                idxcont++;
            }
            ptr++;
        }

        if (idxcont == qtd + 1) {
            idxcont = 1;
            // for(int i = 1; i <=qtd; i++) cout << temp[i] << ' ';
            // cout << endl;
            cont--;
        } else if (ptr == n+1) {
            return 0;
        }
    }

    return 1;
}

signed main(){_

    int t;
    cin >> t;
    int cas = 1;

    while(cas <= t) {
        cin >> n >> k;

        for(int i = 1; i <=n; i++) cin >> a[i];

        int ini = 0, fim = n/k + 1, mid;
        while(ini < fim) {

            mid = ini + (fim - ini)/2;
            // cout << ini << ' ' << mid << ' ' << fim << endl;

            if (solve(mid)) ini = mid + 1;
            else fim = mid;
        }

        cout << "Case #" << cas << ": ";
        cout << ini - 1 << endl;

        cas++;
    }

    return 0;
}
