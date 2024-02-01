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

int atual, total;
vi v;

int Kadane(){

    for (int i=0; i<sz(v); i++){
        atual += v[i];

        if (atual< 0) atual = 0;

        if (atual > total) total = atual;
    }

    return total;
}

int n;

int main(){_

    cin >> n;

    v = vi(n);

    for (int i=0; i<n; i++){
        cin >> v[i];
    }

    cout << Kadane() << endl;

    return 0;
}