#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>

//declaração de variáveis globais
char velha[3][3];

//procedimento para mostrar o jogo da velha
void mostraVelha(){
	int i, j;
	
	printf("  0   1   2\n");
	for(i=0;i<3;i++){						// i controla o numero da linha da matriz
		printf("%d ", i);			
		for(j=0;j<3;j++){					// j controla o numero da coluna da matriz
			printf("%c ", velha[i][j]);		//mostra o elemento da matriz
			if(j<2){
				printf("| ");
			}
		}
		
		if(i<2){
			printf("\n  ---------\n");
		}
	}
	printf("\n");
}

main(){
	//configuração
	setlocale(LC_ALL, "");
	
	//declaração de variaáveis locais
	char nomeX[20], nomeO[20], peca, op;
	int cont, lin, col;
	
	peca='X';
	//let nome dos jogadores
	printf("# JOGO DA VELHA #\n\n");
	printf("Nome do jogador X:");
	fflush(stdin);
	gets(nomeX);
	printf("Nome do jogador O:");
	fflush(stdin);
	gets(nomeO);
	
	for(cont=1;cont<10;cont++){
		system("cls");
		
		printf("Rodada %d\n", cont);
		printf("Jogador %c - ", peca);
		if(peca == 'X'){
			printf("%s\n\n", nomeX);
		}else{
			printf("%s\n\n", nomeO);
		}	
		
		mostraVelha();
		do{
			//let a linha com validação: 0 - 2
			do{
				printf("Linha:");
				scanf("%d", &lin);
			}while(lin<0 || lin>2);
			//let a coluna com validação: 0 - 2
			do{
				printf("Coluna:");
				scanf("%d", &col);
			}while(col<0 || col>2);
			if(velha[lin][col] == 'X' || velha[lin][col]=='O'){
				printf("Posição já ultilizada.Tente novamente.\n\n");
			}
		
		}while(velha[lin][col] == 'X' || velha[lin][col]=='O');
		//marcar a peça a matriz
		velha[lin][col]=peca;
		
		//verificação horizontal
		if(velha[lin][0]== peca && velha[lin][1]==peca && velha[lin][2]==peca){
			printf("Alinhamento horizontal na linha %d\n\n, lin");
			break;	
		}
		
		//verificação vertical
		if(velha[0][col]==peca && velha[1][col]==peca && velha[2][col]==peca){
			printf("Alinhamento vertical na coluna %d\n\n", col);
			break;
		}
		
		//verificação diagonal principal
		if(velha[0][0]==peca && velha[1][1]==peca &&velha[2][2]==peca){
			printf("Alinhamento na diagonal principal\n\n");
			break;
		}
		
		//verificação diagonal secund[aria
		if(velha[0][2]== peca && velha[1][1]==peca && velha[2][0] ==peca){
			printf("Alinhamento na diagonal secundária\n\n");
			break;
		}
		
		//mostra velha
		if(peca== 'X'){
			peca = 'O';
		}else {
			peca='X';
		}
	}
	mostraVelha();
}
