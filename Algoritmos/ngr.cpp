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

int n, num;
stack<int> pilha;
vi ngr, a;

int main(){_
    cin >> n;

    a = vi(n+1);
    ngr = vi(n+1);

    for (int i=0; i<n; i++){
        cin >> num;
        a[i] = num;

        while (!pilha.empty() and num > a[pilha.top()]){
            ngr[pilha.top()] = num;
            pilha.pop();
        }

        pilha.push(i);
    }

    for (int i=0; i<n; i++){
        if(ngr[i]) cout << ngr[i] << ' ';
        else cout << '*' << ' ';
    }
    cout << endl;

    return 0;
}