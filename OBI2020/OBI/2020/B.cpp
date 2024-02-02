#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <assert.h>
#include <iomanip>


int max1 = 1e9;

using namespace std;

int matriz[505][505];
int visitados[505][505];
int n;
int f;

void dfs(int a, int b){
    visitados[a][b] = 1;
    matriz[a][b] = -1;
    if (b+1<=n and matriz[a][b+1]<=f and visitados[a][b+1] == 0) dfs(a, b+1);
    if (b-1>0 and matriz[a][b-1]<=f and visitados[a][b-1] == 0) dfs(a, b-1);
    if (a+1<=n and matriz[a+1][b]<=f and visitados[a+1][b] == 0) dfs(a+1, b);
    if (a-1>0 and matriz[a-1][b]<=f and visitados[a-1][b] == 0) dfs(a-1, b);
}

int main(int argc, const char * argv[]) {

    std::ios::sync_with_stdio(false);
    cout << fixed << setprecision(12);
    cin.tie(NULL);
    
    cin >> n >> f;

    for (int i=1; i<=n; i++){
        string s;
        cin >> s;

        for (int j=1; j<=n; j++){
            matriz[i][j] = s[j-1] - '0';
        }
    }

    if (matriz[1][1] <= f){
        dfs(1,1);
    }

    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            if (matriz[i][j]>0) cout << matriz[i][j];
            else cout << '*';
        }
        cout << endl;
    }

	return 0;
}
