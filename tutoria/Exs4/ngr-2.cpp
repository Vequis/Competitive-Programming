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
     
    stack<int> pilha;
    vi ngrr, ngrl;
    int n, x, p, dist1, dist2;
    vii cidades;
     
    int main(){_
     
        cin >> n;
     
        cidades = vii(n+1);
        ngrr = vi(n+1, INT_MAX);
        ngrl = vi(n+1, INT_MAX);
     
        for (int i=1; i<=n; i++){
            cin >> x >> p;
     
            cidades[i] = {x,p};
        }
     
        for (int i=1; i<=n; i++){
            while(!pilha.empty() and cidades[i].sc > cidades[pilha.top()].sc){
                ngrr[pilha.top()] = i;
                pilha.pop();
            }
     
            pilha.push(i);
        }
     
        while(!pilha.empty()) pilha.pop();
     
        for (int i=n; i>=1; i--){
            while(!pilha.empty() and cidades[i].sc > cidades[pilha.top()].sc){
                ngrl[pilha.top()] = i;
                pilha.pop();
            }
     
            pilha.push(i);
        }
     
        for (int i=1; i<=n; i++){
            if (i!=1) cout << ' ';
            else cout << endl;
            
            if (ngrr[i] == INT_MAX and ngrl[i] == INT_MAX) {
                cout << -1;
                continue;
            }
            
            if (ngrr[i] != INT_MAX) dist1 = cidades[ngrr[i]].fs - cidades[i].fs;
            else dist1 = INT_MAX;
     
            if (ngrl[i] != INT_MAX) dist2 = cidades[i].fs - cidades[ngrl[i]].fs ;
            else dist2 = INT_MAX;
     
            if (dist1 == dist2) {
                if (cidades[ngrr[i]].sc > cidades[ngrl[i]].sc) cout << ngrr[i];
                else cout << ngrl[i];
            }
            else if (dist1<dist2) cout << ngrr[i];
            else cout << ngrl[i];
        }
     
        cout << endl;
     
        return 0;
    }