#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 45
//
typedef struct {
	int qtd;
	aluno dados[MAX];
}lista;
//
int tamanholista(lista *li){
	if(li == NULL){
		return -1;
	}else{
		return li->qtd;
	}
}
//
typedef struct {
	char nome[30];
	int matricula;
	float n1, n2, n3; 
	
}aluno;
//
int listacheia(lista *li){
	if(li == NULL){
		return -1;
	}
	return (li->qtd == MAX);
}
//
int listavazia(lista *li){
	if(li == NULL){
		return -1;
	}
	return (li->qtd == 0);
}
//
lista* criarlista(){
	lista *li;
	li = (lista*) malloc(sizeof(lista));
	if(li != NULL){
		li->qtd = 0;
	}
	return li;
}
//
int inserirfinal(lista *li){
	if(li == NULL){
		return 0;
	}
	if(listacheia(li)){
		return 0;
	}
	
	printf("--- Cadastrar Aluno ---\n");
	printf("Nome do Aluno ");
	scanf("%s",&li->dados[li->qtd].nome);
	printf("Numero da Matricula do Aluno ");
	scanf ("%d",&li->dados[li->qtd].matricula);
	li->dados[li->qtd].n1= 0;
	li->dados[li->qtd].n2= 0;
	li->dados[li->qtd].n3= 0;
	li->qtd++;
	printf("\nAluno cadastrado com sucesso.");
	return 1;
}
//
void listaralunos(lista *li){
	int i;
	float t = 0;
	printf("--- Alunos Cadstrados ---\n");
	for(i=0; i< li->qtd;i++){
		printf("Posicao: %d\n", i+1);					
		printf("Nome: %s\n",li->dados[i].nome);			
		printf("Matricula: %d\n", li->dados[i].matricula);			
		printf("Nota 1: %.1f\n",li->dados[i].n1);				
		printf("Nota 2: %.1f\n",li->dados[i].n2);		
		printf("Nota 3: %.1f\n",li->dados[i].n3);
		if( (li->dados[i].n1) + (li->dados[i].n2) + (li->dados[i].n3) >= 60  ){
			printf("Aluno aprovado.\n");	
		}else{
			printf("Aluno reprovado.\n");	
		}
		printf("_______________\n");
		t += (li->dados[i].n1) + (li->dados[i].n2) + (li->dados[i].n3 );
	}
	printf("\n--- Total ---\n");
	printf("Soma total dos alunos: %.1f.\n", t);
	printf("Media total dos alunos: %.1f.\n", t/li->qtd);
		
}
//
int buscaraluno(lista *li){
	aluno tmp;
	int A,i;
	int d;
	printf ("[1]. Pelo nome.\n");
	printf ("[2]. Pela matricula.\n");
	printf ("[3]. Pela posicao.\n");
	printf ("[0]. Cancelar.\n");
	printf ("Opcao: ");
	scanf ("%d",&A);	
	switch (A){	
	
		case 1:
			printf("Digite o nome do aluno:");
			scanf ("%s",&tmp.nome);
			for(i=0; i < li->qtd; i++){
				if( strcmp(li->dados[i].nome,tmp.nome) == 0 ){
					
					return i;		
				}		
			}
			
			printf("Nome nao encontrado.");
			return -1;								
		break;
			
		case 2:
			printf("Digite o numero de matricula: ");
			scanf ("%d",&tmp.matricula);
			
			for(i=0; i < li->qtd; i++){
				if( li->dados[i].matricula == tmp.matricula ){	
					return i;			
				}		
			}
			printf("Matricula nao encontrado.");
			return -1;
		break;
		
		case 3:
			printf("Digite a posicao valida: ");
			scanf("%d",&d);
			if((d >= 0) && ( d <= li->qtd)){	
				return d-1;	
			}else{		
				printf("posicao nao encontrada");
				return -1;
			}	
		break;
			
		case 0:
			printf("Saindo");
			return -1;	
		break;
			
		default:
		printf ("Opcao invalida\n");					
	}		
	return -1;
}
//
void alunoaprovado(lista *li){
	printf("--- Verificar aprovacao ---\n");
	int B = buscaraluno(li);
	if (B==-1){
		return;
	}
	if( (li->dados[B].n1) + (li->dados[B].n2) + (li->dados[B].n3) >= 60  ){
		
		printf("\nPosicao: %d\n", B+1);					
		printf("Nome: %s\n",li->dados[B].nome);			
		printf("Matricula: %d\n", li->dados[B].matricula);			
		printf("Nota 1: %.1f\n",li->dados[B].n1);				
		printf("Nota 2: %.1f\n",li->dados[B].n2);		
		printf("Nota 3: %.1f\n",li->dados[B].n3);
		printf("\nAluno aprovado.");
	}else{
		
		printf("\nPosicao: %d\n", B+1);					
		printf("Nome: %s\n",li->dados[B].nome);			
		printf("Matricula: %d\n", li->dados[B].matricula);			
		printf("Nota 1: %.1f\n",li->dados[B].n1);				
		printf("Nota 2: %.1f\n",li->dados[B].n2);		
		printf("Nota 3: %.1f\n",li->dados[B].n3);
		printf("\nAluno reprovado.\n");
	}
	
}
//
void remover(lista *li){
	int i;
	int B = buscaraluno(li);
	if(B!=-1){
		for (i = B; i < li->qtd;i++ ){
		li->dados[i]= li->dados[i+1];
		}
		li->qtd--;
		printf("\nAluno removido da lista.\n");
	}

}
//
