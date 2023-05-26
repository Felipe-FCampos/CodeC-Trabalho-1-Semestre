#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <locale.h>
#include <cstdio>


int welcomeStart(){
	
	
	
	printf("\n \t Bem-vindo ao organizador de tarefas \n");
	
	

}

// barra de carregamento //

int loadingBar(){
    char a = 22;
    for (int i = 0; i < 3; i++){
    	printf("%c ", a);
	}   
	
	sleep(1);
	
	for (int i = 0; i < 5; i++){
    	printf("%c ", a);
	}
	
	sleep(2);
}

// Variaveis para armazenamento das informa��es

typedef struct {
    int dia;
} Data;

typedef struct {
    Data data;
    int peso;
    int dificuldade;
    int prioridade;
    char nome[50];
} Atividade;

// Fun��o para o calculo do mes

int calculo(int diaEntrega, int mesEntrega, int diaAtual, int mesAtual){
    int calculo=0, a=0;
    int array[13]= {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    for(int i=mesAtual; i!=mesEntrega+1; i++){
    	if(i==mesAtual && a!=0){	
			calculo=calculo+(array[i]-diaAtual);
		}
		
		else if(i!=mesAtual && i!=mesEntrega){
			calculo= calculo+array[i];
		}
		else if(i==mesEntrega && a==0){
			calculo=calculo+(diaEntrega-diaAtual);
		}
		
		else if(i==mesEntrega){
			calculo=calculo+diaEntrega;
		}
		a++;
	}
	
	return calculo;
}

// Fun��o principal: pega informa��es principais de dias

int main() {
    int numAtividades, diaEntrega, mesEntrega, diaAtual, mesAtual;
	
	setlocale(LC_ALL, "Portuguese");
	
	welcomeStart();
	
	loadingBar();
	
    printf("Digite o n�mero de atividades: ");
    scanf("%d", &numAtividades);
    
    printf("Digite o dia atual: ");
    scanf("%d",&diaAtual);
    printf("Digite o m�s atual: ");
    scanf("%d", &mesAtual);

    Atividade atividades[numAtividades];

    for (int i = 0; i < numAtividades; i++) {
        printf("\nAtividade %d:\n", i + 1);

        printf("Digite o nome da atividade: \n");
        scanf(" %[^\n]s", atividades[i].nome);
		
		printf("Digite o dia de entrega: ");
   		scanf("%d", &diaEntrega);
    
    	printf("Digite um m�s: ");
   		scanf("%d", &mesEntrega);
   		
   		// Puxando a fun��o c�lculo
   		
   		atividades[i].data.dia=calculo(diaEntrega, mesEntrega, diaAtual, mesAtual);
		
		//  - - - - - - - - - - - - - - - 
	
        printf("Digite o peso (1-10): \n");
        scanf("%d", &atividades[i].peso);

        printf("Digite a dificuldade (1-10): \n");
        scanf("%d", &atividades[i].dificuldade);
    }

    for (int i = 0; i < numAtividades - 1; i++) {
        for (int j = i + 1; j < numAtividades; j++) {
            int prioridade_i = atividades[i].peso * atividades[i].dificuldade;
            int prioridade_j = atividades[j].peso * atividades[j].dificuldade;
            if (prioridade_i < prioridade_j) {
                // Trocar as posi��es das atividades
                Atividade temp = atividades[i];
                atividades[i] = atividades[j];
                atividades[j] = temp; 
            }
        }
    }
	
	
	printf("\n\n \tAperte Enter para organizar!!!!\n");
    getchar(); // Wait for Enter key press
    getchar(); // Wait for Enter key press
	// 	Quando o c�digo acabar, gerar arquivo txt das atividades organizadas

    printf("\n \nAtividades organizadas: \n \n");
    for (int i = 0; i < numAtividades; i++) {
        printf("Atividade %d:\n \n", i + 1);
        printf("Nome: %s\n", atividades[i].nome);
        printf("Dias faltando: %d\n", atividades[i].data.dia);
        printf("Peso: %d\n", atividades[i].peso);
        printf("Dificuldade: %d\n \n", atividades[i].dificuldade);
        printf("\n");
        
        if (atividades[i].dificuldade >= 7) {
            printf("Classifica��o: Dificil\n\n");
        } else if (atividades[i].dificuldade >= 4) {
            printf("Classifica��o: Medio\n\n");
        } else {
            printf("Classifica��o: Facil\n\n");
        }
    }
}
