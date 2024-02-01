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

signed main(){_

    int x, maior, cont;

    int n;
    cin >> n;
    x = n;

    maior = x;
    cont = 0;

    while(x!=1){
        cont++;
        maior = max(maior, x);
    
        if(x%2) x = 3*x + 1;
        else x/=2;
    }

    cout << cont << ' ' << maior << endl;

    return 0;
}
