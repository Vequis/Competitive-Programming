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

vi v;
int n, aux, alvo;

int main(){_

    cin >> n >> alvo;

    v = vi(n+1);

    for (int i=0; i<n; i++) cin >> v[i];

    int lo = 0;
    int hi = n-1;
    while(lo<hi){
        for (int i=lo; i<=hi; i++) cout << v[i] << ' ';
        cout << endl;
        int md = lo + (hi-lo)/2;
        if (v[md]>=alvo) hi = md;
        else lo = md+1;

    }

    cout << v[lo] << endl;

    return 0;
}