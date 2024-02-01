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

ii days[112345];
int n;
int psa[112345];


signed main(){


    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> days[i].sc >> days[i].fs;
    }

    //Prefix Sum (no caso, suffix)
    psa[n+1] = 0;
    for (int i = n; i>=0; i--) {
        psa[i] = psa[i+1] + days[i].sc;
        days[i].sc = psa[i];//Gambiarra para não usar outra estrutura de dados
    }

    sort(days, days+n);

    int resp = 0;
    int jaComprado = 0;

    for (int i=0; i < n; i++) {
        resp += max((int)0,(days[i].sc - jaComprado))*days[i].fs;
        jaComprado = max(jaComprado, days[i].sc);
    }

    cout << resp << endl;


    return 0;
}
