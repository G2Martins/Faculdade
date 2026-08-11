#include <iostream>
#include <queue>

using namespace std;

int searchQueue(queue<int> q, int value)
{
    int index = 0;

    // Procurar o valor na fila
    while (!q.empty()) {
        if (q.front() == value) {
            return index;
        }
        q.pop();
        index++;
    }

    // Se o valor não for encontrado, retorna -1
    return -1;
}

int main()
{
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);

    int value;
    cout << "Digite o valor a ser buscado: ";
    cin >> value;

    int index = searchQueue(q, value);

    if (index != -1) {
        cout << "Valor " << value << " encontrado na posição " << index << " da fila." << endl;
    } else {
        cout << "Valor " << value << " não encontrado na fila." << endl;
    }

    return 0;
}

