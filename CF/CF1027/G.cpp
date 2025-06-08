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

// esta em volta dos fatores 2 dos numeros colocados
// imagina que a[i] = 2^k * impar 
// b[i] = 2^k
// 1 1 2 4 2 1


// Problema se 
// 2 4 2 4 2
// k = 14- > impossivel de fazer
// 
/*
2 1 4
k = 7 tbm é impossivel

if (sum all (b[i]) < k) return false

se o impar de bi eh igual ao impar do vizinho bi tem que ser antes

bi -> vizinho

.....$*.......*$...
caso onde vai dar errado
$ tem que ser construido antes
$ +1
* -1
se cur < 0 return false

cada $ pode soh olhar pro prox

caso 
5 7
5 1 6 3 10
1 1 2 1 2
5 1 3 3 5

4 6
6 8 5 10
2 8 1 2
3 1 5 5

2 1 4
1 -> 2
3 -> 2


vai dar ruim se o vizinho de bi
for exatamente o impar que ele tem que adicionar
b[i] --
pq ai ele vai colocar primeiro 2*impar e dps vai somando de impar em impar
NÃO, ESTA ERRADO ^
se o vizinho for 2*impar por ex e eu quero chegar em 8*impar
eu tenho que começar com 2* o que da problema
entao se for
256 32
64i 32i
65 nums no max

b[i]*2 + 1

talvez fixar a posição em que começa
se eu começar na posição i
todos que estao a esquerda tem que tomar cuidado com o vizinho da direita -> delta_l -> por ex 65 - 256
psa_delta_l[i-1] + psa_delta_r[n] - psa_delta_r[i]
*/

int n, k;
int a[112345];
int b[112345];
int impar[112345];
int psa_delta_l[112345];
int psa_delta_r[112345];

void solve() {
    cin >> n >> k;

    int sum_b = 0;
    int flag = false;
    for (int i = 1; i <=n; i++) {
        cin >> a[i];
        int it = 1;
        while(a[i] % it == 0) {
            if (a[i] % (2*it) == 0) it*=2;
            else break;
        }
        b[i] = it;
        impar[i] = a[i]/b[i];
        sum_b += b[i];

        if (i!= 1 and a[i-1] == a[i]) flag = true;
    }

    if (sum_b < k or flag) {
        cout << "NO" << endl;
        return;
    }

    psa_delta_l[0] = 0;
    psa_delta_r[0] = 0;
    for (int i = 1; i <=n; i++) {
        int cur_delta_l = 0;
        int cur_delta_r = 0;
        if (i < n and impar[i] == impar[i+1] and b[i] > b[i+1]) {
            // cur_b = b[i] - b[i+1] + 1;
            cur_delta_l = -2*b[i+1] + 1;
        }

        if (i > 1 and impar[i] == impar[i-1] and b[i] > b[i-1]) {
            cur_delta_r = -2*b[i-1] + 1;
        }

        psa_delta_l[i] = psa_delta_l[i-1] + cur_delta_l;
        psa_delta_r[i] = psa_delta_r[i-1] + cur_delta_r;
        // cout << i << ' ' << psa_delta_l[i] << ' ' << psa_delta_r[i] << endl;
    }

    int melhor_resp = -1;
    // melhor_resp *= INF;
    for (int i = 1; i <=n; i++) {
        int cur = sum_b + psa_delta_l[i-1] + psa_delta_r[n] - psa_delta_r[i];
        melhor_resp = max(cur, melhor_resp);
    }

    // cout << melhor_resp << endl;
    if (melhor_resp >= k) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }



}

signed main(){_
    int t;
    cin >> t;
    // t=1;

    while(t--) {
        solve();
    }

    return 0;
}