#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <conio.h>

int main(void)
{
    setlocale(LC_ALL,"Portuguese");
    
    int liv, nivel, numero, escolha=0, rob, i=0,secreto, max;
    float pontos = 1000;
    float perdidos;
    
	do
	{
		system("cls");
		printf("\n\n*Bem-vindo ao jogo de adivinhação*\n\n");
		printf("\nBebe [1] Adolescente [2] Adulto [3] Master [4] Expert [5] ");
			
		do
		{
		    printf("\n\nEscolha a dificuldade do jogo: \n\n");
		    scanf("%d",&nivel);
		    system("cls");
			    
		    if( nivel > 5 | nivel < 0){
		    	printf("\nOpçao inválida");
			}
		}while( nivel > 5 | nivel < 0);
		
	    switch (nivel)
		{
		case 1: liv=15; max = 20;break;
		
		case 2:liv=15; max = 40;break;
		
		case 3:liv=25; max = 60;break;
		    
		case 4:liv=25; max = 80;break;  
			
		case 5:liv=30; max = 100;break;	  
	    }
	    
	    srand(time(0));
	    secreto = rand() % max;
	    
	    for(i=1; i<=liv; i++)
		{
			system("cls");
			printf("\nVocê tem %d de %d",i,liv),
		    printf("\n\nEscolha um número de 1 a %d:",max);
		    scanf("%d",&numero);
		
		    if(numero<1 | numero>100){
		        i--;
		    }
		    if(numero>secreto)	{
		        printf("\nSeu chute foi maior que o esperado!\n");
		        getch();
		    }
		    else if(numero<secreto)	{
		        printf("\nSeu chute foi menor que o esperado!\n");
		        getch();
		    }
			else{
			    printf("\nUHUL!! PARABÉNS VOCÊ ACERTOU! o número secreto era: %d\n",secreto);
			    getch();
			   	break;
		    }
		    perdidos = (abs(numero-secreto))/ 2.0;
		    pontos = perdidos - pontos;
	    }
	
	    if(numero==secreto)
		{
	        printf("\nPARABÉNS VOCE GANHOU *-* %.1f pontos\n",pontos);
	    }
		
		else
		{
	        printf("\nPOXA QUE PENA, VOCÊ PERDEU .-. %.1f pontos\n",pontos);
	    }
	    
	    do
		{
			system("cls");
		    printf("\n(1)SIM (2)NÃO");
			printf("\nDeseja continuar?...");
			scanf("%d", &escolha);
			if ( escolha > 2 | escolha < 0)
			{
				printf("\nOpção inválida");
			}
		}while( escolha > 2 | escolha < 0);
	}while(escolha != 2);
}
