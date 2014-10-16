// Função menu_1()
// Função que implementa as operações do Menu 1 (Inserir/Editar)

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

// Outras funções

int inserir ()
{
    typedef struct
            {
                char num_cc[9];
                char nome[30];
                char morada[50];
                char telefone[9];
                char idade[2];
                char ano_entrada[4];
                char pos[20];
            }dados;

    dados jogador;
    int op;
    FILE *jogadores;


    jogadores=fopen("jogadores.txt", "a");

    do
        {
            system("clear");
            printf("\nInserir Novo Jogador\n");
            printf("\nCC: ");
            fflush(stdin);
            gets(jogador.num_cc);
            printf("\nNome: ");
            fflush(stdin);
            gets(jogador.nome);
            printf("\nMorada: ");
            fflush(stdin);
            gets(jogador.morada);
            printf("\nTelefone: ");
            fflush(stdin);
            gets(jogador.telefone);
            printf("\nIdade: ");
            fflush(stdin);
            gets(jogador.idade);
            printf("\nAno de Entrada: ");
            fflush(stdin);
            gets(jogador.ano_entrada);
            printf("\nPosição: ");
            fflush(stdin);
            gets(jogador.pos);

            //Inserir os dados no TXT

            fprintf(jogadores, "\n%s %s %s %s %s %s %s", jogador.num_cc, jogador.nome, jogador.morada, jogador.telefone, jogador.idade, jogador.ano_entrada, jogador.pos);
            fclose(jogadores);
            printf("\nDeseja Inserir outro Jogador? [1] SIM / [2] NÃO\n");
            scanf("%d", &op);
     	}while (op == 1);

return 0;




}


// Função menu_1
int menu_1()
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

	system("clear"); //system("cls");
	switch (op) {
		case '1':
				inserir(); // chama função menu Inserir
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

	getchar(); //system("pause");


return 0;


}

