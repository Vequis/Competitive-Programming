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

int psa[4000][4000], pot, n, g, num;
bool ok = false;
int atual;

int main(){_

    cin >> n >> g;

    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++) {
            cin >> num;
            psa[i][j] = psa[i-1][j] + psa[i][j-1] - psa[i-1][j-1] + num;
        }
    }

    pot = 1;

    while(!ok){
        ok = true;
        for (int i=pot; i<=n; i+=pot){
            for (int j=pot; j<=n; j+=pot){
                atual = psa[i][j] - psa[i-pot][j] - psa[i][j-pot] + psa[i-pot][j-pot];
                if (atual < g){
                    ok = false;
                    pot *= 2;
                    break;
                }
            }
        }
    }

    cout << (n*n)/(pot*pot) << endl;

    return 0;
}