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
#define MAX (1<<10) //2^10 = 1024

using namespace std;

int psa[1010][1010];
ll maior = -1, atual;
int n,m, l;

int main(){_

    cin >> n >> m;

    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            char c;
            cin >> c;

            psa[i][j] = psa[i-1][j] + psa[i][j-1] - psa[i-1][j-1];

            psa[i][j] += (c=='C' ? 25 : 12);
        }
    }

    cin >> l;

    for (int i=l; i<=n; i++){
        for (int j=l; j<=m; j++){
            atual = psa[i][j] - psa[i-l][j] - psa[i][j-l] + psa[i-l][j-l];

            if (atual == l*l*12 or atual == l*l*25) continue;

            maior = max(atual, maior);
        }
    }

    cout << maior << endl;

    return 0;
}