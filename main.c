#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"
#define MAX 45


int main(int argc, char *argv[]) {
	
	lista *li = criarlista();
		
	int A, B, C;
	
	do {	
		printf ("--- Gerenciador de alunos ---\n");
		printf ("[1]. Adicionar Novo Aluno\n");
		printf ("[2]. Adicionar Notas.\n");
		printf ("[3]. Buscar Aluno\n");
		printf ("[4]. Verificar se um aluno esta aprovado\n");
		printf ("[5]. Mostrar todos os alunos, aprovacoes e medias\n");
		printf ("[6]. Remover Aluno\n");
		printf ("[0]. Sair.\n");
		printf ("Escolha uma opcao: ");
		scanf ("%d",&o);
		system("cls");
		
		switch (A){	
		
			case 1:	
				C = inserirfinal(li);
				if(	C == 0	){
					printf("Erro.\nLista Cheia ou inexistente.");
				}					
			break;
			
			case 2:
				printf("--- Adicionar notas ---\n");
				B=buscaraluno(li);
				if(B!= -1){
					printf("\nPosicao: %d\n", B+1);					
					printf("Nome: %s\n",li->dados[B].nome);			
					printf("Matricula: %d\n", li->dados[B].matricula);
					do{
						printf("Digite a nota 1: (0 a 30)\n");
						scanf("%f", &li->dados[B].n1);	
					}while( li->dados[B].n1 < 0 || li->dados[B].n1 > 30 );
					
					do{
						printf("Digite a nota 2: (0 a 30)\n");
						scanf("%f", &li->dados[B].n2);	
					}while( li->dados[B].n2 < 0 || li->dados[B].n2 > 30 );
					
					do{
						printf("Digite a nota 3: (0 a 40)\n");
						scanf("%f", &li->dados[B].n3);	
					}while( li->dados[B].n3 < 0 || li->dados[B].n3 > 40 );					
				}	
			break;
				
			case 3:
				if(li->qtd==0){
					printf("lista vazia.\n");	
				}else{
					printf ("--- Buscar aluno ---\n");
					B = buscaraluno(li);
					if (B != -1){
						printf("\n--- Aluno encontrado ---\n");
						printf("Posicao: %d\n", B+1);					
						printf("Nome: %s\n",li->dados[B].nome);			
						printf("Matricula: %d\n", li->dados[B].matricula);			
						printf("Nota 1: %.1f\n",li->dados[B].n1);				
						printf("Nota 2: %.1f\n",li->dados[B].n2);		
						printf("Nota 3: %.1f\n",li->dados[B].n3);
					}
				}			
			break;	
			
			case 4:
				if(li->qtd==0){
					printf("lista vazia.\n");
				}else{
					alunoaprovado(li);	
				}
					
			break;
			
			case 5:
				if(li->qtd==0){
					printf("lista vazia.\n");	
				}else{
					listaralunos(li);
				}	
			break;
				
			case 6:
				if(li->qtd==0){
					printf("lista vazia.\n");	
				}else{
					printf("--- Remover aluno ---\n");
					remover(li);
				}
			break;
			
					
			case 0:
				printf("Saindo");
			break;
				
			default: 
				printf ("Opcao invalida\n");	
					
		}
		printf("\n");
		system("pause");
		system("cls");
	}while(A!=0);
	
	return 0;
}
