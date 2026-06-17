#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class Restaurante {
private:
    std::string nome;
    std::vector<std::string> cardapio;

public:
    
    Restaurante(std::string nomeInicial) : nome(nomeInicial) {}

   
    std::string getNome() const {
        return nome;
    }

    
    void setNome(std::string novo_nome) {
        if (!novo_nome.empty()) {
            nome = novo_nome;
        } else {
            std::cout << "Erro: O nome nao pode ser vazio." << std::endl;
        }
    }

    
    void adicionarPrato(std::string prato) {
        if (std::find(cardapio.begin(), cardapio.end(), prato) == cardapio.end()) {
            cardapio.push_back(prato);
            std::cout << "Prato '" << prato << "' adicionado ao cardapio." << std::endl;
        } else {
            std::cout << "O prato '" << prato << "' já existe no cardapio." << std::endl;
        }
    }

    void listarCardapio() const {
        std::cout << "\n--- Cardapio do " << nome << " ---" << std::endl;
        for (const auto& prato : cardapio) {
            std::cout << "- " << prato << std::endl;
        }
        std::cout << "--------------------------\n" << std::endl;
    }

    
    void atenderCliente(std::string nome_cliente, std::string prato) {
        if (std::find(cardapio.begin(), cardapio.end(), prato) != cardapio.end()) {
            std::cout << "Pedido confirmado! Cliente: " << nome_cliente 
                      << " | Prato: " << prato << std::endl;
        } else {
            std::cout << "Desculpe, " << nome_cliente << ". O prato '" 
                      << prato << "' nao existe em nosso cardapio." << std::endl;
        }
    }
};

int main() {
    
    Restaurante r("Sabor Caseiro");


    r.adicionarPrato("Feijoada");
    r.adicionarPrato("Bife Acebolado");
    r.adicionarPrato("Salada Caesar");

 
    r.listarCardapio();
    r.atenderCliente("Joao", "Feijoada");
    r.atenderCliente("Maria", "Sushi"); 

  
    std::cout << "\nNome atual: " << r.getNome() << std::endl;
    r.setNome("Sabor Caseiro Gourmet");
    std::cout << "Novo nome definido: " << r.getNome() << std::endl;

    return 0;
}