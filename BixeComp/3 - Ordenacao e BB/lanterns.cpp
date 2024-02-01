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
// #define int long long -> solução divina?

using namespace std;

int n, l;
vi a;
double resp;

int main(){_

    cin >> n >> l;

    for (int i=0; i<n; i++){
        int num;
        cin >> num;
        a.pb(num);
    }

    sort(all(a));

    resp = a[0];

    for (int i=1; i<n; i++){
        double atual = a[i] - a[i-1]; atual/=2;
        if(resp < atual) resp = atual;
    }

    if (resp < l - a[n-1]) resp = l- a[n-1];

    cout << fixed;
    cout << setprecision(10) << resp << endl;

    return 0;
}