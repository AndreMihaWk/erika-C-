#include <iostream>

int main() {
    int n;

    std::cout << "Digite o número de termos: ";
    std::cin >> n;

    if (n <= 0) {
        std::cout << "Por favor, digite um número positivo." << std::endl;
        return 0;
    }

    long long t1 = 0, t2 = 1, proximoTermo = 0;

    std::cout << "Sequência de Fibonacci: ";

    for (int i = 1; i <= n; ++i) {
        // Imprime os dois primeiros termos.
        if(i == 1) {
            std::cout << t1 << ", ";
            continue;
        }
        if(i == 2) {
            std::cout << t2 << ", ";
            continue;
        }
        
        // Calcula o próximo termo e atualiza as variáveis
        proximoTermo = t1 + t2;
        t1 = t2;
        t2 = proximoTermo;
        
        std::cout << proximoTermo;
        if (i < n) {
            std::cout << ", ";
        }
    }
    std::cout << std::endl;

    return 0;
}
