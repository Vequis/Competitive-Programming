#include <iostream>

using namespace std;

int matriz[10010][10010];

int main(){

    int x1a, y1a, x2a, y2a;
    cin >> x1a >> y1a >> x2a >> y2a;

    int x1b, y1b, x2b, y2b;
    cin >> x1b >> y1b >> x2b >> y2b;

    for (int i=min(y1a,y2a); i<=max(y1a,y2a); i++){

        for (int j=min(x1a,x2a); j<=max(x1a,x2a); j++){
            matriz[i][j] = 1;
        }

    }

    long long int area = 0;

    for (int i=min(y1b,y2b)+1; i<=max(y1b,y2b)-1; i++){
        for (int j=min(x1b,x2b)+1; j<=max(x1b,x2b)-1; j++){
            if (matriz[i][j] == 1) area++;
        }
    }

    cout << area << endl;
    return 0;
}