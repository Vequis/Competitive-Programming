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
// #define int long long -> solução divina?

using namespace std;

string treino, s;
int resp[1111], invalido[1111];
int atual, last, primeiro;

int main(){_

    cin >> treino >> s;

    for (int i=0; i<sz(treino); i++){
        atual = 0;
        primeiro = -1;
        for (int j=0; j<sz(s); j++){
            if (s[j] == treino[i] and !invalido[j]) {
                if((primeiro == -1) or (resp[j]>=atual)) {
                    invalido[j] = 1;
                    primeiro = j;
                }
                resp[j]++;
                atual = resp[j];
            }

            resp[j] = max(resp[j], atual);
        }
        for (int j=0; j<sz(s); j++)cout<<resp[j];
        cout << endl;
    }

    cout << resp[sz(s)-1] << endl;

    return 0;
}

//saddps
//d t s d p a s d p
//0 0 1 1 1 1 1 1 1
//0 0 1 1 1 2 2 2 2
//1 1 1 2 2 2 2 3 3
//1 1 1 2 2 2 2 3 3
//