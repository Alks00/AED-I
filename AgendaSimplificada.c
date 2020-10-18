#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Pessoa
{
    char nome[20];
    struct Pessoa *prox;
}pessoa;

void insere(pessoa *agenda);
void listar(pessoa *agenda);
void apagar(pessoa *agenda);


int main()
{
    int op;
    pessoa *agenda;
    
    if((agenda =(pessoa *) malloc(sizeof(pessoa)))==NULL){
		printf("Memoria Insuficiente\n");
		exit(1);
	}
    agenda -> prox = NULL;

    do
    {
        printf("Selecione uma das opções:\n");
        printf("Incluir: 1\n");
        printf("Listar: 2\n");
        printf("Apagar: 3\n");
        printf("Sair: 4\n\n");

        scanf("%d", &op);

        switch (op)
        {
        case 1:
            insere(agenda);
            break;
        case 2:
            listar(agenda);
            break;
        case 3:
            apagar(agenda);
            break;
        case 4:
            break;

        default:
        printf("Opção inválida!\n");
            break;
        }
    } while (op != 4);

    free(agenda);
    
    
    return 0;
}

void insere(pessoa *agenda){
    pessoa *aux;
    
    aux = (pessoa*)malloc(sizeof(pessoa));
    
    printf("Escreva o nome: \n");
    scanf("%s", aux->nome);

    aux -> prox = agenda -> prox;
    agenda -> prox = aux;
}

void listar(pessoa *agenda){
    pessoa *aux;
    int cont = 1;

    for (aux = agenda -> prox; aux != NULL; )
    {
        printf("%d - %s \n", cont, aux -> nome);
        aux = aux -> prox;
        cont++;
    }
    
}

void apagar(pessoa *agenda){
	
	char nome[20];							
	pessoa *aux, *auxprox;								

	printf("Nome a ser excluído: \n");
	scanf("%s", nome);
	
	aux = agenda;									
	auxprox = agenda -> prox;                         
	while((auxprox != NULL) && (strcmp (auxprox -> nome, nome) != 0)){
		aux = auxprox;
		auxprox = auxprox -> prox;
	}
	if (auxprox != NULL){
		aux -> prox = auxprox -> prox;
		free(auxprox);
		printf("Nome apagado com sucesso!\n");
	}
	else
		printf("Nome não encontrado!\n\n");
}

