#include <iostream>
#include <algorithm>

using namespace std;

struct Aluno{ //Criando o tipo aluno
  string nome;
  double nota;
};

bool comparaAlunos(Aluno a, Aluno b){ //Função para compara Alunos
  return a.nota < b.nota; //Aluno a vem antes do Aluno b se a nota do aluno a é menor que a nota do aluno b
}

int main(){
  Aluno aluno[3]; //Criando um vetor de alunos

  for(int i=0;i<3;i++){
    cin>>aluno[i].nome>>aluno[i].nota; //Lendo o nome e a nota de cada aluno.
  }

  sort(aluno, aluno + 3, comparaAlunos); //Queremos comparar alunos usando a função comparaAlunos

  for(int i=0;i<3;i++){
    cout<<aluno[i].nome<<" "<<aluno[i].nota<<"\n"; //Imprimindo cada aluno
  }

}
