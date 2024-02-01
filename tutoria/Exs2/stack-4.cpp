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

int n;
stack<int> pilha;
vector<int> v;
vector<int> resp;

int main(){_

    cin >> n;

    v = vi(n);
    resp = vi(n);

    for (int i=0; i<n; i++){
        cin >> v[i];
    }


    pilha.push(v[n-1]);
    resp[n-1] = -1; //-1 Denota um asterisco;

    for (int i=n-2; i>=0; i--){
        while(!pilha.empty()){
            if (v[i] < pilha.top() ){
                resp[i] = pilha.top(); 
                break;
            } else {
                pilha.pop();
            }
        }

        if (pilha.empty()) resp[i] = -1;

        pilha.push(v[i]);
    }

    cout << resp[0];

    for (int i=1; i<n; i++){
        if (resp[i] == -1){
            cout << " *";
        } else {
            cout << " " << resp[i];
        }
    }
    cout << endl;

    return 0;
}