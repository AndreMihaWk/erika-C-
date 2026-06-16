/*
aula 6  15-06-2026
POO Erika
*/

#include <iostream>
#include <string>

// Classe 1: Representa uma pessoa genérica
class Pessoa {
private:
    std::string nome;
    int idade;

public:
    // Construtor
    Pessoa(std::string n, int i) {
        nome = n;
        idade = i;
    }

   
    void seApresentar() {
        std::cout << "Olá, meu nome é " << nome << " e eu tenho " << idade << " anos.\n";
    }
};


class Estudante {
private:
    std::string nome;
    std::string curso;

public:
  
    Estudante(std::string n, std::string c) {
        nome = n;
        curso = c;
    }


    void estudar() {
        std::cout << "O estudante " << nome << " est matriculado no curso de " << curso << ".\n";
    }
};

int main() {

    Pessoa objetoPessoa("Carlos Silva", 30);
    objetoPessoa.seApresentar();

   
    Estudante objetoEstudante("Ana Souza", "Engenharia de Software");
    objetoEstudante.estudar();

    return 0;
}
