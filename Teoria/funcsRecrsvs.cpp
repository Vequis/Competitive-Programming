  #include <iostream>

  using namespace std;

  int fib(int n){
    if(n < 2){
      return 1; //Casos de base, F(1) e F(0)
    }
    return fib(n - 1) + fib(n - 2); //funciona para os demais casos
  }

  int main(){
    int n;
    cin >> n;
    cout << fib(n) << "\n";

    return 0;
  }
