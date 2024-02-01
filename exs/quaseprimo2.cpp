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

const int MAXN = 1e9 + 7;

bool vetor[MAXN];

int n, k;

vi primos;
int cont;

int main(){_

    cin >> n >> k;

    for (int i=0; i<k; i++){
        int x;
        cin >> x;
        for (int j=x; j<=n; j+=x){
            vetor[j] = 1;
        }
    }

    for (int i=1; i<=n; i++){
        if (vetor[i] == 0) cont++;
    }

    cout << cont << endl;

    return 0;
}