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

vector< vi > cont(10e5+5, vi(10));
int n, q;
vi total(10);

int main(){_

    cin >> n >> q;

    cont[0] = {0,0,0,0,0,0,0,0,0,0};

    for (int i=1; i<=n; i++){
        cont[i] = cont[i-1];
        int num;
        cin >> num;

        cont[i][num]++;
    }

    int ant, prox;
    cin >> ant;
    total = cont[1];

    for (int i=1; i<=q-1; i++){
        cin >> prox;

        if(prox> ant){
            for (int j=0; j<=9; j++){
                total[j] += cont[prox][j] - cont[ant][j];
            }
        } else {
            for (int j=0; j<=9; j++){
                total[j] += cont[ant-1][j] - cont[prox-1][j];
            }
        }

        ant = prox;
    }

    for (int i=0; i<=9; i++){
        cout << total[i];
        if (i!=9) cout << ' ';
    }
    
    cout << endl;

    return 0;
}