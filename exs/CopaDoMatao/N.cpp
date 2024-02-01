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

#define maxn 11234

int valor[maxn];
int peso[maxn];
int capacidade[maxn];
int pesoIntegrantes[maxn];
int valorIntegrantes[maxn];

int dp1[11234][123];
int dp2[11234][123];

int knapSack1(int W, int wt[], int val[], int n)
{
    if (n == 0 || W == 0)
        return 0;

    if(dp1[W][n] != -1) return dp1[W][n];

    if (wt[n - 1] > W)
        return dp1[W][n] = knapSack1(W, wt, val, n - 1);
    else
        return dp1[W][n] = max(
            val[n - 1]
                + knapSack1(W - wt[n - 1],
                           wt, val, n - 1),
            knapSack1(W, wt, val, n - 1));
}

int knapSack2(int W, int wt[], int val[], int n)
{
    if (n == 0 || W == 0)
        return 0;

    if(dp2[W][n] != -1) return dp2[W][n];

    if (wt[n - 1] > W)
        return dp2[W][n] = knapSack2(W, wt, val, n - 1);
    else
        return dp2[W][n] = max(
            val[n - 1]
                + knapSack2(W - wt[n - 1],
                           wt, val, n - 1),
            knapSack2(W, wt, val, n - 1));
}

signed main()
{
    int n, k, l;

    cin >> n >> k >> l;
 
    memset(dp1, -1, sizeof(dp1));
    memset(dp2, -1, sizeof(dp2));

    for (int i = 0; i < n; i++) {
        cin >> capacidade[i] >> pesoIntegrantes[i];
    }

    for (int i = 0; i < k; i++) {
        cin >> peso[i] >> valor[i];
    }

    for (int i = 0; i < n;  i++) {
        valorIntegrantes[i] = knapSack1(capacidade[i], peso, valor, k);
    }

    cout << knapSack2(l, pesoIntegrantes, valorIntegrantes, n) << endl;
    return 0;
}
 
