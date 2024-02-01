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

void tt(int tes) {
    cout<<"Case #"<<tes<<": ";
}

int a[2123456];
int b[2123456];
int n;
// bool ab(int a, int b) {
//     return a < b;
// }

bool fa(int x) {
    if (x <= n) return a[x];
    if (x <= 2*n) return b[(x-1)%n + 1];
    return a[x%n];
}

bool fb(int x) {
    if (x <= n) return b[x];
    if (x <= 2*n) return a[(x-1)%n + 1];
    return b[x%n];
}

void solve() {
    cin >> n;

    for(int i = 1; i <=n; i++) {
        cin >> a[i];
    }
    for(int i = 1; i <=n; i++) {
        cin >> b[i];
    }

    int inicial = 0; //0 a[0] < b[0] ; 1 a[0] > b[0]
    int segundaparte = 0;

    int indigual = -1;
    //tratar caso primeiros iguais
    if (a[1] < b[1]) inicial = 0;
    else if (a[1] > b[1]) inicial = 1;
    else {
        segundaparte = 1;
        indigual = 1;
    }

    int cont1, cont2;
    cont1= 1;
    cont2= 0;
    int numcomp = 0;

    int contiguais = 0;


    for(int i = 2; i <=n; i++) {
        if (inicial == 0) {
            if (a[i] < b[i]) cont1++;
            else if (a[i] > b[i]) {
                segundaparte=1;
                cont2++;
            } else {
                if(segundaparte) {
                    cout << -1 << endl;
                    return;
                }
                segundaparte = 1;
                indigual = i;
            } 
        }
        if (inicial == 1) {
            if (a[i] > b[i]) cont1++;
            else if (a[i] < b[i]) {
                segundaparte=1;
                cont2++;
            } else {
                if(segundaparte) {
                    cout << -1 << endl;
                    return;
                }
                segundaparte = 1;
                indigual = i;
            } 
        }

        if (a[i] < b[i] and inicial == 0 and segundaparte) {
            cout << -1 << endl;
            return;
        }
        if (a[i] > b[i] and inicial == 1 and segundaparte) {
            cout << -1 << endl;
            return;
        }
    }

    int desloca;
    if (inicial == 0) {
        if (cont1 >= n/2) {
            desloca = (n-cont2) - (n+1)/2;
        } else {
            desloca = cont1 + n- (n+1)/2;
        }
    } else {
        desloca = (n-cont2) + n- (n+1)/2;
    }

    // int desloca = n/2 - min(cont1, cont2);
    // if (inicial == 1) desloca+=n;

    if (n%2 == 0) {
        if (cont1 + cont2 != n) {
            cout << -1 << endl;
            return;
        }


        for(int i = 1; i<=n; i++) {
            // cout << i << endl;
            // cout << fa(i+desloca) << ' ' << fb(n+1-i + desloca) << endl;
            if (fa(i+desloca) != fb(n+1-i + desloca)) {
                cout << -1 << endl;
                return;
            }
        }
    } else {
        if (cont1 + cont2 == n-1) {
            for(int i = 1; i<=n; i++) {
                if (i+desloca == cont1 + 1) continue;
                // cout << i << endl;
                // cout << fa(i+desloca) << ' ' << fb(n+1-i + desloca) << endl;
                if (fa(i+desloca) != fb(n+1-i + desloca)) {
                    cout << -1 << endl;
                    return;
                }
            }
        } else {
            cout << -1 << endl;
            return;
        }
    }

    // cout << cont1 << ' ' << cont2 << ' ' << desloca << endl;
    cout << desloca << endl;
}

signed main(){_

    freopen("meta_game_input.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        tt(i);
        solve();
    }

    return 0;
}
