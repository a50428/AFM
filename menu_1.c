// Função menu_1()
// Função que implementa as operações do Menu 1 (Inserir/Editar)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*
#define J 100

typedef struct{

    int num_cc[9];
    char nome[50];
    char morada[50];
    char telefone[9];
    int idade;
    int ano_entrada[4];
    char pos[20];

} jogador;

typedef jogador listajog[J];
*/

// Cabeçalho da função menu_1
int menu_1(void);

// Outras funções

int inserir_jog(void)
{
    char op;
    int i=0;
    listajog jog;
    do
    {
       system("clear");
       printf("\nInserir Novo Jogador\n");
       printf("\nCC: ");
       scanf("%d",&jog[i].num_cc);
       printf("\nNome: ");
       scanf("%s",&jog[i].nome);
       printf("\nMorada: ");
       scanf("%s",&jog[i].morada);
       printf("\nTelefone: ");
       scanf("%s",&jog[i].telefone);
       printf("\nIdade: ");
       scanf("%d",&jog[i].idade);
       pintf("\nAno de Entrada: ");
       scanf("%d",&jog[i].ano_entrada);
       printf("\nPosição: ");
       scanf("%s",&jog[i].pos);

       i++;

       printf("\nDeseja Inserir outro Jogador? [1] SIM / [2] NÃO\n");
       scanf("%d", &op);
   	}while (op == 1);

return 0;

}


// Função menu_1
int menu_1(void)
{


    char op; // variável de opção para o menu

	//system("chcp 1252>null"); //CODEPAGE PT

	// MENU PRINCIPAL
	printf("+         INSERIR / EDITAR        +\n\n");
	printf("| 1.Inserir Novo Jogador          |\n");
	printf("| 2.Editar Jogador Existente      |\n");
	printf("| 3.Inserir Nova Equipa           |\n");
	printf("| 4.Editar Equipa Existente       |\n");
	printf("| 5.Registo de Jogos e Resultados |\n");
	printf("| 0.Sair                          |\n");
	printf("\n");

	op=getchar(); // ou getch(); em windows

	system("clear"); // ou system("cls"); em windows
	switch (op) {
		case '1':
				inserir_jog(); // chama função menu inserir jogador
				break;
		case '2':
				printf("| 2.Listar/Pesquisar |\n"); // chama função menu Listar/Pesquisar
				break;
		case '3':
				printf("| 3.Estatisticas     |\n"); // chama função menu Estatisticas
				break;
		case '4':
				printf("| 4.Carregar/Salvar  |\n"); // chama função menu Carregar/Salvar
				break;
		case '0':
				break; // sai do programa
	}

	getchar(); // ou system("pause"); em windows


return 0;


}

