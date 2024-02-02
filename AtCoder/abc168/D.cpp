#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main() {

    int n,m;
    cin >> n >> m;

    vector< vector<int> > matrix(n);

    for (int i=0; i<m; i++) { //Lendo a matriz de adjacência
        int a, b;
        cin >> a >> b;

        matrix[a-1].push_back(b-1);
        matrix[b-1].push_back(a-1);
    }

    queue<int> q;
    q.push(0);

    int resp[n+5];
    for (int i=0; i<n; i++) resp[i] = -1;

    while (!q.empty()){

        int atual = q.front();

        for (int i=0; i<matrix[atual].size(); i++){

            if (resp[matrix[atual][i]] == -1){ //Para ver se ja foi percorrida
                q.push(matrix[atual][i]);
                resp[matrix[atual][i]] = atual;
            }
        }
        q.pop();
    }

    int var = 4;
    while(var!=1){
        cout << resp[var-1]+1 << " -> ";
        var = resp[var-1] + 1;
    }

    bool ok = true;

    for (int i=1; i<n; i++) {
        if (resp[i]==-1) ok = false;
    }

    if (ok){
        cout << "Yes" << endl;
        for (int i=1; i<n; i++) {
            cout << resp[i]+1 << endl;
        }
    } else {
        cout << "No" << endl;
    }

    return 0;
}
