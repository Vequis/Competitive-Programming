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

using namespace std;

int n;
vi coins;
int sominha, soma;

bool cmp(int a, int b){
    return a>b;
}

int main(){_

    cin >> n;

    coins = vi(n);
    for (int i=0; i<n; i++) {
        cin >> coins[i];
        soma+=coins[i];
    }
    sort(all(coins), cmp);

    soma/=2;
    for (int i=0; i<n; i++) {
        sominha += coins[i];
        if (sominha>soma){
            cout << i+1 << endl;
            return 0;
        }
    }

    return 0;

}