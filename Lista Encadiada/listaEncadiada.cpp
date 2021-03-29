#include <stdio.h>
#include <stdlib.h>

	typedef struct No {
		int valor;
		struct No *proximo;
	}No;

	typedef struct {
		No *inicio;
		int tam;
	}Lista;

	void inserirInicio(Lista *lista, int valor) {
		No *novo = (No*)malloc(sizeof(No));
		novo->valor = valor;
		novo->proximo = lista->inicio;
		lista->inicio = novo;
		lista->tam++;
	}

	void inserirFim(Lista *lista, int valor) {
        No *no, *novo = (No*)malloc(sizeof(No));
        novo->valor = valor;
        novo->proximo = NULL;

        if(lista->inicio == NULL) {
            lista->inicio = novo;
            lista->tam++;
        }else {
            no = lista->inicio;

            while(no->proximo != NULL)
                no = no->proximo;
            no->proximo = novo;
            lista->tam++;

        }
	}

	void remover(Lista *lista, int valor) {
        No *inicio = lista->inicio;
        No * noARemover = NULL;


        if(lista->inicio != NULL && lista->inicio->valor == valor) {
            noARemover = lista->inicio;
            lista->inicio = noARemover->proximo;
        }else {
            while(inicio != NULL && inicio->proximo != NULL && inicio->proximo->valor != valor) {
                inicio = inicio->proximo;
            }
            if(inicio != NULL && inicio->proximo != NULL) {
                noARemover = inicio->proximo;
                inicio->proximo = noARemover->proximo;
            }
        }
        if(noARemover) {
            free(noARemover);
            lista->tam--;
        }
	}

	void imprimir(Lista *lista) {
		No *inicio = lista->inicio;
		printf("O tamanho eh %d\n", lista->tam);

		while (inicio != NULL) {
			printf("%d\n", inicio->valor);
			inicio = inicio->proximo;
		}
	}

	int main() {
		Lista lista;

		int opcao, valor;

		lista.inicio = NULL;
		lista.tam = 0;

		do {
			printf("\n1 Inserir no Inicio");
			printf("\n2 Imprimir");
			printf("\n3 Inserir no fim");
			printf("\n4 Remover");
			printf("\n5 Sair");
			scanf("%d", &opcao);

			switch (opcao) {
				case 1:
					printf("Digite um valor a ser inserido");
					scanf("%d", &valor);
					inserirInicio(&lista, valor);
					break;
				case 2:
					imprimir(&lista);
					break;
                case 3:
                    printf("Digite um valor a ser inserido");
					scanf("%d", &valor);
                    inserirFim(&lista, valor);
                    break;
                case 4:
                    printf("Digite um valor a ser excluiodo");
					scanf("%d", &valor);
                    remover(&lista, valor);
                    break;
				case 5:
					printf("Finalizado");
					break;
				default:
					printf("Opicao Invalida");

			}
		} while (opcao != 5);



	}



