#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *pBuffer;

typedef struct pessoa
{
    char nome[20];
}pessoa;

typedef struct variavel
{
    int op,i,cont,a;
}var;

void incluir(var *aux, pessoa *nome);
void apagar(var *aux);
void buscar(var *aux);
void listar(var *aux);


int main()
{
    var *aux;
    pessoa *nome;

    if((pBuffer =(var *) malloc(sizeof(var)))==NULL){
		printf("Memoria Insuficiente");
		exit(1);
	}

    aux = pBuffer;
    aux -> cont = 0;

    do
    {
        printf("Selecione uma das opções:\n");
        printf("Incluir: 1\n");
        printf("Apagar: 2\n");
        printf("Buscar: 3\n");
        printf("Listar: 4\n");
        printf("Sair: 5\n");

        scanf("%d", &aux->op);

        switch (aux->op)
        {
        case 1:
        incluir(aux,nome);
        break;

        case 2:
        apagar(aux);
        break;

        case 3:
        buscar(aux);
        break;

        case 4:
        listar(aux);
        break;

        case 5:
        break;
        
        default:
        printf("Opção Inválida!\n");
            break;
        }
    } while (aux->op != 5);

    free(pBuffer);
    

    return 0;
}

void incluir(var *aux, pessoa *nome){
	if((pBuffer=realloc(pBuffer,sizeof(var)+sizeof(pessoa)+(aux->cont * sizeof(pessoa))))==NULL){
        printf("Nao foi possivel alocar memoria");
        exit(1);
	}
	aux = pBuffer;
	nome = pBuffer + sizeof(var) + (aux->cont * sizeof(pessoa));

	printf("Escreva um nome:\n");
	getchar();
	fgets(nome->nome,20,stdin);

	aux->cont++;
}

void apagar(var *aux){
    if(aux->cont>0){
        if((pBuffer=realloc(pBuffer,sizeof(var)+sizeof(pessoa)+(aux->cont-1 * sizeof(pessoa))))==NULL){
            printf("Nao foi possivel alocar memoria");
            exit(1);
        }
    }else{
        printf("Nao ha mais nomes para serem apagados!");
    }
	aux->cont--;
}

void buscar(var *aux){
    pessoa  *buscar,*nome;

    nome = pBuffer + sizeof(var);

    if((buscar = (pessoa *)calloc(1,sizeof(pessoa)))== NULL){
        printf("Memoria Insuficiente");
        exit(1);
    }

    printf("Digite o nome:\n");
    scanf("%s",buscar->nome);
    printf("\n");

    for(aux->i = 0; aux->i < aux->cont; aux->i++){
		if((strcmp(buscar->nome,nome->nome))== 0){
			printf("%s\n",nome->nome);
			nome++;
			aux->a++;
		}
		else
			nome++;
	}

	if(aux->a == 0){
        printf("O nome nao existe na agenda\n");
	}
	printf("\n");

	aux->a = 0;

	free(buscar);
}

void listar(var *aux){
    pessoa *nome;
    nome = pBuffer + sizeof(var);
    for(aux->i=0;aux->i<aux->cont;aux->i++){
        printf("%s",nome->nome);
        nome++;
    }
}
