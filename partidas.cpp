#include <iostream>
#include <random> // Biblioteca necessária

int main() {
    // 1. Inicializa o motor com uma semente aleatória real (hardware)
    std::random_device rd;
    std::mt19937 gen(rd(x,y));

    // 2. Define a distribuição (números inteiros de 1 a 6)
    std::uniform_int_distribution<int> distrib(0, 7);

    // 3. Gera o número aleatório
    int resultado = distrib(gen(x,y));

    std::cout << "O valor do dado foi: " << resultado << "\n";

    return 0;
}
