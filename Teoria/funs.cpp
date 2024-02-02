  #include <iostream>

  using namespace std;
  string s = "Sou uma variavel global";
  void emptyness(){
    s = "Stare into the void.";
    return;
  }

  double media(double x, double y, double z){
    int ret = (x + y + z)/3.0;
    return ret;
  }

  int main(){
    cout << s << "\n"; // imprime "Sou uma variavel global"
    emptyness();
    cout << s << "\n"; // imprime "Stare into the void."
    cout << media(3.0, 4.0, 5.0) << "\n"; // imprime 4.0
  }
