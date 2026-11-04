#include <iostream> // biblioteca de entrada e saida (cout)
#include <utility> // biblioteca que fornece o swap
using namespace std; // evita escrever std:: antes de cout, swap e endl

void imprimir(int arr[], int n) { // funcao auxiliar que mostra o array na tela
    cout << "[ "; // abre os colchetes da impressao
    for (int k = 0; k < n; k++) { // percorre todas as posicoes do array
        cout << arr[k] << " "; // imprime o elemento da posicao k
    }
    cout << "]"; // fecha os colchetes
}

void bubbleSort(int arr[], int n, int &comparacoes, int &trocas) { // recebe o array, o tamanho e os contadores por referencia
    for (int i = 0; i < n - 1; i++) { // cada passagem coloca o maior elemento restante no fim (maximo n-1 passagens)
        bool trocou = false; // flag que indica se houve troca nesta passagem
        cout << "Passagem " << i + 1 << endl; // mostra o numero da passagem atual
        for (int j = 0; j < n - i - 1; j++) { // compara pares adjacentes; os i ultimos ja estao no lugar certo
            comparacoes++; // conta uma comparacao a cada par verificado
            cout << "  j=" << j << " compara " << arr[j] << " > " << arr[j + 1]; // mostra quais elementos estao sendo comparados
            if (arr[j] > arr[j + 1]) { // se o da esquerda e maior, esta fora de ordem
                swap(arr[j], arr[j + 1]); // troca os dois elementos de posicao
                trocas++; // conta uma troca realizada
                trocou = true; // registra que houve troca nesta passagem
                cout << " -> troca "; // informa que houve troca
            } else { // caso o par ja esteja em ordem
                cout << " -> nao troca "; // informa que nao houve troca
            }
            imprimir(arr, n);
            cout << endl;
        }
        if (!trocou) { // se nenhuma troca ocorreu, o array ja esta ordenado
            break; // encerra antes de fazer passagens desnecessarias
        }
    }
}

int main() {
    int arr[] = {5, 3, 8, 1, 2}; // array de entrada do teste de mesa
    int n = sizeof(arr) / sizeof(arr[0]); // calcula a quantidade de elementos
    int comparacoes = 0; // contador de comparacoes comeca em zero
    int trocas = 0; // contador de trocas comeca em zero

    cout << "Array inicial: ";
    imprimir(arr, n);
    cout << endl << endl;

    bubbleSort(arr, n, comparacoes, trocas); // chama a ordenacao passando os contadores

    cout << endl << "Array final: ";
    imprimir(arr, n);
    cout << endl;
    cout << "Comparacoes: " << comparacoes << endl;
    cout << "Trocas: " << trocas << endl;
    return 0; // fim do programa sem erros
}
