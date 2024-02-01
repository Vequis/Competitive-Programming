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

string s, resp = "kobusacdefghijlmnpqrtvwxyz", kob="kobus";
int n;
int menor;
stack<char> pilha;
char ant;
int impossivel;

int main(){_

    cin >> n;

    for (int i=0; i<n; i++){
        cin >> s;
        for(int j=0; j<sz(s); j++){
            if (s[j]!=kob[j]) break;
           
            if(j>4) break;

            if(j==(sz(s) - 1)){
                impossivel=1;
            }
        }

        pilha.push('u');
        pilha.push('b');
        pilha.push('o');
        pilha.push('k');

        for(int j=0; j<sz(s); j++){
            char c;
            if(!pilha.empty()){
                c= pilha.top();
            } else {
                break;
            }

            if (s[j] == c and (j+1<sz(s) and s[j+1]==c)){
                impossivel=1;
            }

            if(s[j] == c){
                pilha.pop();
            }
        }

        while(!pilha.empty()) pilha.pop();
    }

    if(impossivel){
        cout << "sem chance" << endl;
    } else {    
        cout << resp << endl;
    }


    return 0;
}