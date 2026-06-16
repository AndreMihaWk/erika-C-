#include <iostream>

using namespace std;

int main()
{

    string nome;
    int senha;

    cout << "digite seu Login: " << endl;
    cin >> nome;
    cout << "Digite sua Senha: " << endl;
    cin >> senha;

    for (int i = 1; i <= 3; i++)
    {

        cout << "digite seu Login: " << endl;
        cin >> nome;
        cout << "Digite sua Senha: " << endl;
        cin >> senha;
        if (senha == 1234)
        {
            cout << "Acesso permitido" << endl;
            break;
        }
        else
        {
            cout << "Senha invalida" << endl;
        }
    }
}