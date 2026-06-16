/*aula 6  15-06-2026
Linguagem C++
Profº Erika

POO (Programação Orientada Objetos)
*/

#include <iostream>

class notebook
{
private:
    std::string marca;
    std::string nome;
    bool ligado;

public:
    notebook(std::string m, std::string n);

    this->marca = m;
    this->nome = n;
    this->ligado = false;

    void ligar()
    {
        if (!ligado)
        {
            ligado = true;
            std::cout << "O notebook"<< m <<" esta funcionando" << endl;
        } else{
            std:: cout<< "O Notebook precisa ser ligado!"
        }

    }
}