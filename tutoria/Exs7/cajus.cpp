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
ll maior, atual;
int l, c, m , n, num;

int main(){_

    cin >> l >> c >> m >> n;

    for (int i=1; i<=l; i++){
        for (int j=1; j<=c; j++){
            cin >> num;

            psa[i][j]  = psa[i-1][j] + psa[i][j-1] - psa[i-1][j-1] + num;


            if (i>=m && j>=n){
                atual = psa[i][j] - psa[i][j-n] - psa[i-m][j] + psa[i-m][j-n];

                maior = max(maior, atual);        
            }
        }
    }

    cout << maior << endl;

    return 0;
}