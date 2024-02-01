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

queue<char> equipes;

char equipe;

int main(){_

    for (int i=0; i<16; i++){
        equipes.push('A' + i);
    }

    for (int i=0; i<15; i++){
        int a, b;
        cin >> a >> b;

        if (a>b){
            equipe = equipes.front();
            equipes.push(equipe);
            equipes.pop();
            equipes.pop();
        } else {
            equipes.pop();
            equipe = equipes.front();
            equipes.push(equipe);
            equipes.pop();
        }
    }

    cout << equipes.front() << endl;

    return 0;
}