  #include <iostream>

  using namespace std;

  int A[110][110], B[110][110];

  int main(){
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; ++i){ //Para cada linha
      for(int j = 0; j < m; ++j){ //Para cada coluna
        cin >> A[i][j]; //Leia um elemento e armazene na matriz A
      }
    }

    for(int i = 0; i < n; ++i){ //Para cada linha
      for(int j = 0; j < m; ++j){ //Para cada coluna
        cin >> B[i][j]; //Leia um elemento e armazene na matriz B
      }
    }

    for(int i = 0; i < n; ++i){ //Para cada linha
      for(int j = 0; j < m; ++j){ //Para cada coluna
        cout << A[i][j] + B[i][j] << " "; //Imprima o resultado da soma de cada elemento da matriz A elemento correspondente na matriz B
      }
      cout << "\n";
    }
    return 0;
  }
