#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Classe Jogo para representar resultados e palpites
class Jogo {
public:
    int golsA, golsB;
    Jogo(int gA = 0, int gB = 0) : golsA(gA), golsB(gB) {}
};

class Apostador {
private:
    string nome;
    Jogo* palpites; // Vetor dinâmico
    int numJogos;
    int pontuacao;

public:
    Apostador(string n = "", int num = 4) : nome(n), numJogos(num), pontuacao(0) {
        palpites = new Jogo[numJogos];
    }

    ~Apostador() {
        delete[] palpites;
    }

    void setNome(string n) { nome = n; }
    string getNome() const { return nome; }
    void setPalpite(int idx, int gA, int gB) { palpites[idx] = Jogo(gA, gB); }
    
    void calcularPontos(Jogo oficiais[]) {
        pontuacao = 0;
        for (int i = 0; i < numJogos; i++) {
            // 1. Placar exato (10 pts)
            if (palpites[i].golsA == oficiais[i].golsA && palpites[i].golsB == oficiais[i].golsB) {
                pontuacao += 10;
            } else {
                // 2. Vencedor correto ou empate (5 pts)
                bool vitPalpite = (palpites[i].golsA > palpites[i].golsB);
                bool vitOficial = (oficiais[i].golsA > oficiais[i].golsB);
                bool empPalpite = (palpites[i].golsA == palpites[i].golsB);
                bool empOficial = (oficiais[i].golsA == oficiais[i].golsB);

                if ((vitPalpite && vitOficial) || (empPalpite && empOficial)) pontuacao += 5;

                // 3. Diferença de gols (2 pts)
                int difPalpite = palpites[i].golsA - palpites[i].golsB;
                int difOficial = oficiais[i].golsA - oficiais[i].golsB;
                if (difPalpite == difOficial) pontuacao += 2;
            }
        }
    }

    int getPontuacao() const { return pontuacao; }
};

int main() {
    Jogo oficiais[4];
    Apostador apostadores[3] = {Apostador("Apostador 1"), Apostador("Apostador 2"), Apostador("Apostador 3")};
    int opcao;
    bool resultadosRegistrados = false;

    do {
        cout << "\n--- MENU BOLAO COPA 2026 ---\n1. Registrar resultados oficiais\n2. Registrar apostas\n3. Calcular pontuação e ranking\n4. Sair\nOpcao: ";
        cin >> opcao;

        if (opcao == 1) {
            oficiais[0] = Jogo(3, 0); oficiais[1] = Jogo(1, 1);
            oficiais[2] = Jogo(1, 2); oficiais[3] = Jogo(4, 2);
            cout << "Resultados oficiais registrados automaticamente." << endl;
            resultadosRegistrados = true;
        } 
        else if (opcao == 2) {
            for (int i = 0; i < 3; i++) {
                string nome;
                cout << "\nNome do apostador " << i + 1 << ": ";
                cin >> nome;
                apostadores[i].setNome(nome);
                for (int j = 0; j < 4; j++) {
                    int gA, gB;
                    cout << "Palpite Jogo " << j + 1 << " (gols A e gols B): ";
                    cin >> gA >> gB;
                    apostadores[i].setPalpite(j, gA, gB);
                }
            }
        } 
        else if (opcao == 3) {
            if (!resultadosRegistrados) { cout << "Registre os resultados primeiro!" << endl; continue; }
            for (int i = 0; i < 3; i++) apostadores[i].calcularPontos(oficiais);
            
            // Ordenação simples (Bubble Sort)
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2 - i; j++) {
                    if (apostadores[j].getPontuacao() < apostadores[j+1].getPontuacao())
                        swap(apostadores[j], apostadores[j+1]);
                }
            }
            cout << "\n--- RANKING ---\n";
            for (int i = 0; i < 3; i++)
                cout << i + 1 << "o Lugar: " << apostadores[i].getNome() << " - " << apostadores[i].getPontuacao() << " pts" << endl;
        }
    } while (opcao != 4);

    return 0;
}