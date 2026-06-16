#include <iostream>


class Animal {
private:
    
    std::string especie;
    std::string som;

public:
    
    Animal(std::string esp, std::string somAnimal) {
        especie = esp;
        som = somAnimal;
    }

   
    void emitirSom() {
        std::cout << "O animal da especie [" << especie << "] faz: " << som << "!\n";
    }
};

int main() {
   
    Animal cachorro("canino familiaris", "Au Au");
    cachorro.emitirSom();

    
    Animal gato("felino", "Miau");
    gato.emitirSom();

    return 0;
}
