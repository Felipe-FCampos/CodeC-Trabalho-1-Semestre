#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <locale.h>
#include <cstdio>

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

// - - - - - -

int urgenciaDeterminador(int qtDias, int dificul){


if(qtDias <= 5){

        if(dificul >= 7){
            printf("Urgencia1");
        } else if(dificul >= 4){
            printf("cuidado2");
        } else {
            printf("Safe3");
        }
    }

    else if(qtDias <= 10){

        if(dificul >= 7){
            printf("cuidado1");
        } else {
            printf("Safe2");
        }
    }

    else {
            printf("Safe4");
    }
}


int welcomeStart(){
	
	printf("\n Bem-vindo ao organizador de tarefas \n");
    printf("\n \tAperte Enter para iniciar!!!!\n");
    getchar(); // Wait for Enter key press
    loadingBar();

}

// Fun��o principal: pega informa��es principais de dias

int main() {
    int numAtividades, diaEntrega, mesEntrega, diaAtual, mesAtual;
	
	setlocale(LC_ALL, "Portuguese");
	
	welcomeStart();
	
	loadingBar();
	
    printf("\n\tDigite o n�mero de atividades: ");
    scanf("%d", &numAtividades);
    
    printf("\tDigite o dia atual: ");
    scanf("%d",&diaAtual);
    printf("\tDigite o m�s atual: ");
    scanf("%d", &mesAtual);

    Atividade atividades[numAtividades];

    for (int i = 0; i < numAtividades; i++) {
        printf("\n\tAtividade %d: ", i + 1);

        printf("\tDigite o nome da atividade: ");
        scanf(" %[^\n]s", atividades[i].nome);
		
		printf("\tDigite o dia de entrega: ");
   		scanf("%d", &diaEntrega);
    
    	printf("\tDigite um m�s: ");
   		scanf("%d", &mesEntrega);
   		
   		// Puxando a fun��o c�lculo
   		
   		atividades[i].data.dia=calculo(diaEntrega, mesEntrega, diaAtual, mesAtual);
		
		//  - - - - - - - - - - - - - - - 
	
        printf("\tDigite o peso (1-10): ");
        scanf("%d", &atividades[i].peso);

        printf("\tDigite a dificuldade (1-10): ");
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

    printf("\n \n\tAtividades organizadas: \n \n");
    for (int i = 0; i < numAtividades; i++) {
        printf("Atividade %d:\n \n", i + 1);
        printf("\tNome: %s\n", atividades[i].nome);
        printf("\tDias faltando: %d\n", atividades[i].data.dia);
        printf("\tPeso: %d\n", atividades[i].peso);
        printf("\tDificuldade: %d\n \n", atividades[i].dificuldade);
        printf("\n");
        
        urgenciaDeterminador(atividades[i].data.dia, atividades[i].dificuldade);
        
        if (atividades[i].dificuldade >= 7) {
            printf("\tClassifica��o: Dificil\n\n");
        } else if (atividades[i].dificuldade >= 4) {
            printf("\tClassifica��o: Medio\n\n");
        } else {
            printf("\tClassifica��o: Facil\n\n");
        }
    }
}
