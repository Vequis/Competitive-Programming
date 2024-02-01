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

int mode(int a, int b){
    int var = a%b;

    if (var<0) var+=b;
    
    return var;
}

int n, k, m, cont;
vector<int> a, f;

int func(int t){
    if (t<= cont){
        return f[t];
    }

    int num = 0;

    for (int i=1; i<=n; i++){
        num += mode( (a[i] * func(t-i)) , m);
    }

    f[t] = mode(num, m);
    cont++;
    return f[t];
}

int main(){_

    cin >> n >> k >> m;

    a = vi(n+1);
    f = vi(k+1);

    for (int i=1; i<=n; i++){
        int num;
        cin >> num;
        a[i] = mode(num, m);
    }

    for (int i=1; i<=n; i++){
        int num;
        cin >> num;
        f[i] = mode(num, m);
    }
    cont = n;

    cout << func(k) << endl;

    return 0;
}