#include <iostream>
using namespace std;

// definicao de tipo
struct NO {
	int valor;
	NO* prox;
};

NO* primeiro = NULL;

// headers
void menu();
void inicializar();
void exibirQuantidadeElementos();
void exibirElementos();
void inserirElemento();
void excluirElemento();
void buscarElemento();
NO* posicaoElemento(int numero);
//--------------------------


int main()
{
	menu();
}

void menu()
{
	int op = 0;
	while (op != 7) {
		system("cls"); // somente no windows
		cout << "Menu Lista Ligada";
		cout << endl << endl;
		cout << "1 - Inicializar Lista \n";
		cout << "2 - Exibir quantidade de elementos \n";
		cout << "3 - Exibir elementos \n";
		cout << "4 - Buscar elemento \n";
		cout << "5 - Inserir elemento \n";
		cout << "6 - Excluir elemento \n";
		cout << "7 - Sair \n\n";

		cout << "Opcao: ";
		cin >> op;

		switch (op)
		{
		case 1: inicializar();
			break;
		case 2: exibirQuantidadeElementos();
			break;
		case 3: exibirElementos();
			break;
		case 4: buscarElemento();
			break;
		case 5: inserirElemento();
			break;
		case 6: excluirElemento();
			break;
		case 7:
			return;
		default:
			break;
		}

		system("pause"); // somente no windows
	}
}

void inicializar()
{
	// se a lista já possuir elementos
// libera a memoria ocupada
	NO* aux = primeiro;
	while (aux != NULL) {
		NO* paraExcluir = aux;
		aux = aux->prox;
		free(paraExcluir);
	}

	primeiro = NULL;
	cout << "Lista inicializada \n";

}

void exibirQuantidadeElementos() {

	int nElementos = 0;
	NO* aux = primeiro;
	while (aux != NULL) {
		nElementos++;
		aux = aux->prox;
	}
	cout << "Quantidade de elementos: " << nElementos << endl;

}

void exibirElementos()
{
	if (primeiro == NULL) {
		cout << "Lista vazia \n";
		return;
	}
	else {
		cout << "Elementos: \n";
		NO* aux = primeiro;
		while (aux != NULL) {
			cout << aux->valor << endl;
			aux = aux->prox;
		}
	}
}

void inserirElemento()
{
	// aloca memoria dinamicamente para o novo elemento
	NO* novo = (NO*)malloc(sizeof(NO));
	if (novo == NULL)
	    NO* novo = (NO*)malloc(sizeof(NO));
    if (novo == NULL) {
        return; 
    }

    cout << "Digite o elemento: ";
    cin >> novo->valor;
    novo->prox = NULL;

    NO* aux2 = primeiro;
    bool elementoRepetido = false;

    while (aux2 != NULL) {
        if (aux2->valor == novo->valor) {
            elementoRepetido = true;
            break; 
        }
        aux2 = aux2->prox; 
    }

    if (elementoRepetido) {
        free(novo); 
        cout << "Este elemento já existe na lista" << endl;
    }
    else {
        if (primeiro == NULL) {
            primeiro = novo;
        } 
        else if (primeiro->valor > novo->valor) {
            novo->prox = primeiro;
            primeiro = novo;
        }
        else {
            NO* aux = primeiro;

            while (aux->prox != NULL && aux->prox->valor < novo->valor) {
                aux = aux->prox; 
            }

            novo->prox = aux->prox;
            aux->prox = novo;    
        }
    }
}

void excluirElemento()
{
    int valorDeletar;
    cout << "Digite um elemento para efetuar a exclusao: ";
    cin >> valorDeletar;

    if (primeiro == NULL) {
        cout << "A lista esta vazia." << endl;
        return;
    }


    if (primeiro->valor == valorDeletar) {
        NO* temp = primeiro;
        primeiro = primeiro->prox;  
        delete temp;  
        cout << "Elemento excluido com sucesso!" << endl;
        return;
    }


    NO* aux = primeiro;
    while (aux->prox != NULL && aux->prox->valor != valorDeletar) {
        aux = aux->prox;  
    }

    if (aux->prox == NULL) {
        cout << "Elemento não encontrado na lista." << endl;
        return;
    }


    NO* deletar = aux->prox;  
    aux->prox = deletar->prox;  
    delete deletar;  
    cout << "Elemento excluído com sucesso!" << endl;
}


void buscarElemento()
{
    if (primeiro == NULL) {
        cout << "A lista esta vazia." << endl;
        return;
    }

    int valorBusca;
    cout << "Digite o valor que deseja buscar: ";
    cin >> valorBusca;

    NO* aux = primeiro;
    int posicao = 1; 

    while (aux != NULL) {
        if (aux->valor == valorBusca) {
            cout << "Elemento " << valorBusca << " encontrado na posiçao " << posicao << "." << endl;
            return;
        }
        aux = aux->prox;  
        posicao++;  
    }

    cout << "Elemento " << valorBusca << " nao encontrado na lista." << endl;
}


