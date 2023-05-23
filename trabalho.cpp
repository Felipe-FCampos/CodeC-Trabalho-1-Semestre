#include<stdio.h>
#include<string.h>
#include <unistd.h>

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

// Variaveis para armazenamento das informações

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

// Função para o calculo do mes

int calculo(int diaEntrega, int mesEntrega, int diaAtual, int mesAtual){
    int calculo=0;
    int array[13]= {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    
    for(int i=mesAtual; i!=mesEntrega+1; i++){
    	if(i==mesAtual){	
			calculo=calculo+(array[i]-diaAtual);
		}
		
		else if(i!=mesAtual && i!=mesEntrega){
			calculo= calculo+array[i];
		}
		
		else if(i==mesEntrega){
			calculo=calculo+diaEntrega;
		}
	}
	
	return calculo;
}

// Função principal: pega informações principais de dias

int main() {
    int numAtividades, diaEntrega, mesEntrega, diaAtual, mesAtual;

	loadingBar();
	
    printf("Digite o numero de atividades: ");
    scanf("%d", &numAtividades);
    
    printf("Digite o dia atual: ");
    scanf("%d",&diaAtual);
    printf("Digite o mes atual: ");
    scanf("%d", &mesAtual);

    Atividade atividades[numAtividades];

    for (int i = 0; i < numAtividades; i++) {
        printf("\nAtividade %d:\n", i + 1);

        printf("Digite o nome da atividade: \n");
        scanf(" %[^\n]s", atividades[i].nome);
		
		printf("Digite o dia de entrega: ");
   		scanf("%d", &diaEntrega);
    
    	printf("Digite um mes: ");
   		scanf("%d", &mesEntrega);
   		
   		// Puxando a função cálculo
   		
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
                // Trocar as posições das atividades
                Atividade temp = atividades[i];
                atividades[i] = atividades[j];
                atividades[j] = temp; 
            }
        }
    }

	// 	Quando o código acabar, gerar arquivo txt das atividades organizadas

    printf("\n \nAtividades organizadas: \n \n");
    for (int i = 0; i < numAtividades; i++) {
        printf("Atividade %d:\n \n", i + 1);
        printf("Nome: %s\n", atividades[i].nome);
        printf("Dias faltando: %d\n", atividades[i].data.dia);
        printf("Peso: %d\n", atividades[i].peso);
        printf("Dificuldade: %d\n \n", atividades[i].dificuldade);
        printf("\n");
        
        if (atividades[i].dificuldade >= 7) {
            printf("Classificação: Dificil\n\n");
        } else if (atividades[i].dificuldade >= 4) {
            printf("Classificação: Medio\n\n");
        } else {
            printf("Classificação: Facil\n\n");
        }
    }
}
