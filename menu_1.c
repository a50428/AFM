// Função menu_1()
// Função que implementa as operações do Menu 1 (Inserir/Editar)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Outras funções

// ############################################################

int listar_jog(void) // função que lista jogadores existentes
{
    int op;
    int i;

    system("clear");
    printf("|  ID  | NOME | IDADE | POSICAO |\n");
    printf("+-------------------------------+\n");
    for (i=1;i<J;i++)
        {
            if (jog[i].num_cc==0) break;
            printf("\n| %d | %s | %d | %s |",i,jog[i].nome,jog[i].idade,jog[i].pos);
        }

    printf("\n+-------------------------------+\n\n");
    //printf("\n\nQualquer tecla pra voltar para voltar...\n");
    getchar();
    //getchar();
   	//menu_1();

}

// ####################################################

int inserir_jog(void) // função que insere novo jogador
{
    int op;
    int i=1;

    do
    {
       system("clear");
       printf("Inserir Novo Jogador\n");
       printf("CC: ");
       scanf("%d",&jog[i].num_cc);
       printf("Nome: ");
       scanf(" %99[^\n]",&jog[i].nome);
       printf("Morada: ");
       scanf(" %99[^\n]",&jog[i].morada);
       printf("Telefone: ");
       scanf(" %99[^\n]",&jog[i].telefone);
       printf("Idade: ");
       scanf("%d",&jog[i].idade);
       printf("Ano de Entrada: ");
       scanf("%d",&jog[i].ano_entrada);
       printf("Posição: ");
       scanf(" %99[^\n]",&jog[i].pos);
       jog[i].ativo=1;
       i++;

       printf("\nDeseja Inserir outro Jogador? [1] SIM / [2] NÃO\n");
       scanf("%d", &op);
   	}while (op == 1);

    menu_1();

}

// ############################################################

int editar_jog(void) // função que edita dados dos jogadores existentes
{
   int op,id;
   listar_jog(); // lista jogadores
   do {
        printf("\n\nQual o ID do jogador a editar? [0] Sair: ");
        scanf("%d", &id);
        if (id==0) break;
        printf("\n\nEditar Jogador [%d]\n", id);
        printf("CC: ");
        scanf("%d",&jog[id].num_cc);
        printf("Nome: ");
        scanf(" %99[^\n]",&jog[id].nome);
        printf("Morada: ");
        scanf(" %99[^\n]",&jog[id].morada);
        printf("Telefone: ");
        scanf(" %99[^\n]",&jog[id].telefone);
        printf("Idade: ");
        scanf("%d",&jog[id].idade);
        printf("Ano de Entrada: ");
        scanf("%d",&jog[id].ano_entrada);
        printf("Posição: ");
        scanf(" %99[^\n]",&jog[id].pos);

        printf("\nDeseja editar outro Jogador? [1] SIM / [2] NÃO\n");
        scanf("%d", &op);

   	}while (op == 1);

    menu_1();

}



// Função menu_1
int menu_1(void)
{


    int op = '\n'; // variável de opção para o menu

	//system("chcp 1252>null"); //CODEPAGE PT

	// MENU PRINCIPAL
	system("clear");
	printf("+         INSERIR / EDITAR        +\n\n");
	printf("| 1.Inserir Novo Jogador          |\n");
	printf("| 2.Editar Jogador Existente      |\n");
	printf("| 3.Inserir Nova Equipa           |\n");
	printf("| 4.Editar Equipa Existente       |\n");
	printf("| 5.Registo de Jogos e Resultados |\n");
	printf("| 0.Menu Principal                |\n");
	printf("\n");

    while(op == '\n')
        scanf("%c",&op);
	//system("clear"); // ou system("cls"); em windows
	switch (op) {
		case '1':
				inserir_jog(); // chama função menu inserir jogador
				break;
		case '2':
				//listar_jog(); // chama função menu Listar jogadorees
				editar_jog(); // chama a função que edita jogadores
				break;
		case '3':
				printf("| 3.Estatisticas     |\n"); // chama função menu Estatisticas
				break;
		case '4':
				printf("| 4.Carregar/Salvar  |\n"); // chama função menu Carregar/Salvar
				break;
		case '0':
				return;//menu_principal();
				//break; // sai do programa
	}

	//getchar(); // ou system("pause"); em windows



}

