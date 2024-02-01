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

vector<int> nums;
stack<int> pilha;

int n, movs = 0, alg, pos;

int main(){_
    cin >> n; 

    pos = 0;

    while(n!=0){
        pilha.push(n%10);
        n/=10;
    }
    while(!pilha.empty()){
        alg = pilha.top();
        pilha.pop();

        movs+= min(abs(pos-alg), 10-abs(alg-pos));

        pos = alg;
    }

    cout << movs << endl;

    return 0;
}