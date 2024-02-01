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

using namespace std;

map<string, double> precos;
int t, n, m;

int main(){_

    cin >> t;

    for (int i=0; i<t; i++){
        cin >> n;
        for (int j=0; j<n; j++){
            string fruta;
            double x;
            cin >> fruta >> x;
            precos[fruta] = x;
        }

        cin >> m;
        double soma = 0;
        for (int j=0; j<m; j++){
            string fruta;
            int qtd;
            cin >> fruta >> qtd;

            soma += qtd*(precos[fruta]);
        }

        cout << fixed << setprecision(2);
        cout << "R$ " << soma << endl;
        precos.clear();
    }

    return 0;
}