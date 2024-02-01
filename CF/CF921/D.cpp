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

int power(int x, int y)
{
    if (y == 0)
        return 1;
 
    int p = power(x, y / 2) % MODN;
    p = (p * p) % MODN;
 
    return (y % 2 == 0) ? p : (x * p) % MODN;
}

int mdc(int a, int b) {
    if (a < b) swap(a,b);
    else if (b == 0) return a;
    return mdc(b, a%b);
}

int invmod(int A)
{
    return power(A, MODN - 2);
}

int mult(int a, int b) {return (a*b)%MODN;}
int soma(int a, int b) {return (a+b)%MODN;}

signed main(){_

    int t;
    cin >> t;
    while(t--) {
        int n, m, k;
        cin >> n >> m >> k;

        int s0 = 0;
        for(int i = 0; i < m; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            s0 = soma(s0, c);
        }

        int resp = 0;

        int qp = n*(n-1)/2 % MODN;
        int p = m*invmod(qp)%MODN;
        int s = 0;

        // for(int i = 0; i <= k-1; i++) s = soma(s, s0 + i);


        int kfat = 1;

        for(int i = 1; i <=k; i++) {
            kfat = mult(kfat, i);
        }
        int constante = mult(kfat, power(invmod(soma(qp, MODN-m)), k));
        int cur = mult(invmod(kfat), constante);

        for(int i = 0; i<=k; i++) {
            resp = soma(resp, mult(s, cur));

            // cout << resp << endl;
            cout << i << ' ' << resp << ' ' << s << ' ' << cur << endl;
            cur = mult(cur, mult(k-(i + 1), mult(m, mult( invmod( soma(qp, MODN-m)), invmod(i + 1)))));
            s = soma(s, s0 + i);
        }

        // resp = mult(resp, invmod(k+1));
        resp = mult(resp, power(invmod(qp), k));
        // resp = mult(resp, constante);

        cout << resp << endl;
    }

    return 0;
}
