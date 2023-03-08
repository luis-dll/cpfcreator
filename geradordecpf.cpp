#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


int gerarNumeroAleatorio(int min, int max) {
    return rand() % (max - min + 1) + min;
}

int gerarDigitoVerificador(int* cpf, int tam) {
    int soma = 0;

    for (int i = 0; i < tam; i++) {
        soma += cpf[i] * (tam + 1 - i);
    }

    int resto = soma % 11;

    if (resto < 2) {
        return 0;
    } else {
        return 11 - resto;
    }
}

int main() {

    srand(time(NULL));

    int cpf[9];
    int digito1, digito2;


    for (int i = 0; i < 9; i++) {
        cpf[i] = gerarNumeroAleatorio(0, 9);
    }


    digito1 = gerarDigitoVerificador(cpf, 9);


    cpf[9] = digito1;

    digito2 = gerarDigitoVerificador(cpf, 10);

    cpf[10] = digito2;

    cout << "CPF gerado: ";
    for (int i = 0; i < 11; i++) {
        cout << cpf[i];
        if (i == 2 || i == 5) {
            cout << ".";
        } else if (i == 8) {
            cout << "-";
        }
    }
    cout << endl;

    return 0;
}
