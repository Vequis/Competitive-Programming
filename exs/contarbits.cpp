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

int n;

// int pot(int a, int b){
//     int resposta = 1;
//     for(int i=1; i<=b; i++) resposta*=a;
//     return resposta;
// }

signed main(){_

    cin >> n;
    // n = pot(2, 45) - 1; -> Deu certo o teste!

    int cont = 0;
    while(n>0){
        if(n%2) cont++;
        n = (n>>1);
    }

    cout << cont << endl;

    return 0;
}
