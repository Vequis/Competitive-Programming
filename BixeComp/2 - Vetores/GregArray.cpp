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
#define LM 112345

using namespace std;

int n, m, k;
ll a[LM], op[LM][3], v[LM], w[LM];
ll pso[LM], psa[LM];

int main(){_

    cin >> n >> m >> k;

    for (int i=1; i<=n; i++) cin >> a[i];

    for (int i=1; i<=m; i++) cin >> op[i][0] >> op[i][1] >> op[i][2]; //li, ri, di

    for (int i=1; i<=k; i++){
        int x, y;
        cin >> x >> y;
        v[x]++;
        v[y+1]--;
    }

    // O vetor w e v funcionam para marcar quando cada operação começa e termina;

    pso[0] = 0; // O vetor pso guardará a quantidade de vezes que cada operação deve ser executada;
    for (int i=1; i<=m; i++) {
        pso[i] = pso[i-1] + v[i];
        w[op[i][0]] += op[i][2] * pso[i];
        w[op[i][1] + 1] -= op[i][2] * pso[i];
    }

    psa[0] = 0;
    for (int i=1; i<=n; i++){
        psa[i] = psa[i-1] + w[i];
        cout << a[i] + psa[i] << ' ';
    }

    return 0;
}