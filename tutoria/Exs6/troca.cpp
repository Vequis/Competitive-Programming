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

vi psa, a;
int n, t;
vii cartas;

int main(){_

    cin >> n >> t;

    cartas = vii(n+1);
    a = vi(n+2);
    psa = vi(n+1);

    for (int i=1; i<=n; i++){
        int num;
        cin >> num;
        cartas[i] = {num, 0};
    }

    for (int i=1; i<=n; i++){
        int num;
        cin >> num;
        cartas[i] = {cartas[i].fs, num};
    }

    while(t--){
        int x, y;
        cin >> x >> y;

        a[x]++;
        a[y+1]--;
    }

    for (int i=1; i<=n; i++){
        psa[i] = psa[i-1] + a[i];

        cout << (psa[i]%2 ? cartas[i].sc : cartas[i].fs) << ' ';
    }
    return 0;
}