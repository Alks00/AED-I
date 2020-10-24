#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct pessoa
{
    char nome[30];
    int idade;
    int altura;
    int cont;
    struct pessoa *prox;
}Pessoa;

void add(Pessoa *pInicial);
void imprime(Pessoa *pInicial);

int main()
{
    Pessoa *pInicial;
    int op;

    if((pInicial =(Pessoa *) malloc(sizeof(Pessoa)))==NULL){
		printf("Memoria Insuficiente");
		exit(1);
	}

    pInicial -> cont = 0;
    pInicial -> prox = NULL;
    
    do
    {
        printf("Menu:\n");
        printf("1- Adicionar nova pessoa \n");
        printf("2- Imprimir e sair\n");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            add(pInicial);
            break;
        case 2:
            imprime(pInicial);
            break;
        default:
            printf("Opção Invalida!\n");
            break;
        }
    } while (op != 2);
    


    free (pInicial);
    return 0;
}

void add(Pessoa *pInicial){
    Pessoa *aux;
    
    aux = (Pessoa*)malloc(sizeof(Pessoa));

    /*if(p -> cont != 1){
        if((p = realloc(p, p->cont * sizeof(Pessoa))) == NULL){
            printf("Memoria Insuficiente!");
            exit (1);
        }
    }*/
    
    printf("Digite o nome: \n");
    getchar();
    fgets(aux->nome,30,stdin);

    printf("Digite a idade: \n");
    scanf("%d", &aux->idade);

    printf("Digite a altura(cm): \n");
    scanf("%d", &aux->altura);

    aux->prox = pInicial->prox;
    pInicial->prox = aux;
    pInicial->cont++;

}

void imprime(Pessoa *pInicial){
    Pessoa *aux;
    aux = pInicial;
    
    if(aux->prox != NULL){
        aux = aux->prox;
        for(int i=1;i <= pInicial->cont;i++){
            printf("Nome: %s\n", aux->nome);
            printf("Idade: %d\n", aux->idade);
            printf("Altura(cm): %d\n\n", aux->altura);
            aux = aux->prox;
        }
    }

}
