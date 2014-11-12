// Função menu_1()
// Função que implementa as operações do Menu 1 (Inserir/Editar)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Outras funções

// ############################################################

int listar_jog(void) // função que lista jogadores existentes
{
    int op,i,team;

    system("clear");
    printf("|  ID  | NOME | IDADE | EQUIPA | POSICAO |\n");
    printf("+----------------------------------------+");
    for (i=1;i<J;i++)
        {
            if (jog[i].num_cc==0) break;
            team=jog[i].eq;
            printf("\n| %d | %s | %d | %s | %s |",i,jog[i].nome,jog[i].idade,equip[team].nome,jog[i].pos);
        }

    printf("\n\n+------------------FIM-----------------+\n");

    getchar();

}

// ############################################################

int listar_jogx(void) // função que lista jogadores sem clube
{
    int op,i,team;

    system("clear");
    printf("|  ID  | NOME | IDADE | EQUIPA | POSICAO |\n");
    printf("+----------------------------------------+");
    for (i=1;i<J;i++)
        {
            if (jog[i].num_cc==0) break;
            team=jog[i].eq;
            if (jog[i].eq==0) printf("\n| %d | %s | %d | %s | %s |",i,jog[i].nome,jog[i].idade,equip[team].nome,jog[i].pos);
        }

    printf("\n\n+------------------FIM-----------------+\n");

    getchar();

}

// ############################################################

int listar_jog_a(int x) // função que lista jogadores existentes na Equipa a
{
    int op,i,team;

    system("clear");
    printf("|  ID  | NOME | IDADE | EQUIPA | POSICAO |\n");
    printf("+----------------------------------------+");
    for (i=1;i<J;i++)
        {
            if (jog[i].num_cc==0) break;

            if (jog[i].eq==equip[x].id) printf("\n| %d | %s | %d | %s | %s |",i,jog[i].nome,jog[i].idade,equip[team].nome,jog[i].pos);
        }

    printf("\n\n+------------------FIM-----------------+\n");

    getchar();

}

// ####################################################

int inserir_jog(void) // função que insere novo jogador
{
    int op;
    int i=0;

    do
    {
        i++; // vai para o ultimo registo
    } while (jog[i].num_cc>0);

    do
    {
       system("clear");
       printf("Inserir Novo Jogador ID [%d]\n\n",i );
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
   	}while (op == 1 && op<J);

    menu_1();

}

// ############################################################

int listar_equip(void) // função que lista equipas existentes
{
    int op;
    int i;

    system("clear");
    printf("|  ID  | NOME |\n");
    printf("+-------------+");
    for (i=1;i<J;i++)
        {
            if (equip[i].id==0) break;
            printf("\n| %d | %s |",equip[i].id,equip[i].nome);
        }

    printf("\n\n+-----FIM-----+\n");

    getchar();

}

// ####################################################

int inserir_equip(void) // função que insere novo jogador
{
    int op;
    int i=0;
    int id;
    do
    {
        i++; // vai para o ultimo registo
    } while (equip[i].id>0);

    do
    {
       system("clear");
       equip[i].id=i;
       printf("Inserir Nova Equipa ID [%d]\n\n",i );
       printf("Nome: ");
       scanf(" %99[^\n]",&equip[i].nome);
       equip[i].ativo=1;
       printf("\nPretende selecionar jogadores para %s? [1] SIM / [2] NAO: ",equip[i].nome);
       scanf("%d",&op);
       if (op==1)
        {
            listar_jogx();
            printf("\nSelecione o ID do jogador que pretende: ");
            scanf("%d", &id);
            jog[id].eq=i;
            printf("\n\nJogador %s adicionado a %s com sucesso!\n", jog[id].nome,equip[i].nome);
            getchar();
        }
       i++;
       printf("\nDeseja Inserir outra Equipa? [1] SIM / [2] NÃO\n");
       scanf("%d", &op);
   	}while (op == 1 && op<E);

    menu_1();

}

// ############################################################

int editar_jog(void) // função que edita dados dos jogadores existentes
{
   int op,id;

   do {
        system("clear");
        listar_jog(); // lista jogadores
        printf("\nQual o ID do jogador a apagar/editar? [0] Sair: ");
        scanf("%d", &id);
        if (id==0) break;
        printf("\n\nApagar Jogador [%d] ? [1] SIM / [2] NAO, Quero editar : ", id);
        scanf("%d", &op);
        if (op==1)
            {
                jog[id].num_cc=0;
                jog[id].ativo=0;
                printf("\nJogador ID [%d] apagado com sucesso!\n",id);
                getchar();
            }
        if (op==2)
            {
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
            }

        printf("\n\nDeseja apagar/editar outro Jogador? [1] SIM / [2] NÃO\n");
        scanf("%d", &op);

    }while (op == 1);

   menu_1();

}

// ############################################################

int editar_equip(void) // função que edita dados dos jogadores existentes
{
   int op,id;

   do {
        system("clear");
        listar_equip(); // lista equipas
        printf("\nQual o ID da equipa a apagar/editar? [0] Sair: ");
        scanf("%d", &id);
        if (id==0) break;
        printf("\n\nApagar [%s] ? [1] SIM / [2] NAO, Quero editar : ", equip[id].nome);
        scanf("%d", &op);
        if (op==1)
            {
                equip[id].id=0;
                equip[id].ativo=0;
                printf("\nEquipa apagada com sucesso!");
                getchar();
            }
        if (op==2)
            {
                printf("\n\nEditar equipa [%d]\n", id);
                printf("Nome: ");
                scanf(" %99[^\n]",&equip[id].nome);
                equip[id].ativo=1;
            }

        printf("\n\nDeseja apagar/editar outra Equipa? [1] SIM / [2] NÃO\n");
        scanf("%d", &op);

    }while (op == 1);

   menu_1();

}

// ############################################################

int tranferir_jog(void) // função que edita dados dos jogadores existentes
{
   int op,id_eq,id_jog;

   do {
        system("clear");
        listar_jog(); // lista jogadores
        printf("\nQual o ID do jogador a tranferir? [0] Sair: ");
        scanf("%d", &id_jog);
        if (id_jog==0) break;
        listar_equip(); // lista equipas
        printf("\nQual o ID da equipa de destino? [0] Sair: ");
        scanf("%d", &id_eq);
        if (id_eq==0) break;
        jog[id_jog].eq=id_eq;
        printf("\n\nTranferencia efectuada com sucesso!");
        printf("\n\nDeseja tranferir outro Jogador? [1] SIM / [2] NÃO\n");
        scanf("%d", &op);

    }while (op == 1);

   menu_1();

}

// ####################################################

int registar_jogos(void) // função que regista jogos e resultados
{
    int a,b,op,marcador,golos,i=0;

    do
    {
        i++; // vai para o ultimo registo
    } while (result[i].id>0);

    do
    {
       system("clear");
       printf("Registar Jogos e Resultados ID [%d]\n\n",i );
       printf("Data: ");
       scanf(" %99[^\n]",&result[i].data);
       printf("\nLocal: ");
       scanf(" %99[^\n]",&result[i].local);
       listar_equip();
       printf("\nEquipa A ID: ");
       scanf("%d",&a);
       result[i].equipa_a=a;
       printf("\nEquipa B ID: ");
       scanf("%d",&b);
       result[i].equipa_b=b;
       //
       listar_jog_a(a);
       printf("\nMarcador ID Equipa A?: ");
       scanf("%d",&marcador);
       printf("\nQuantos golos marcou %s?: ", jog[marcador].nome);
       scanf("%d", &golos);
       jog[marcador].golos=jog[marcador].golos+golos;
       result[i].marcadores[i]=marcador;
       result[i].golos_a=result[i].golos_a+golos;
       //
       listar_jog_a(b);
       printf("\nMarcador ID Equipa B?: ");
       scanf("%d",&marcador);
       printf("\nQuantos golos marcou %s?: ", jog[marcador].nome);
       scanf("%d", &golos);
       jog[marcador].golos=jog[marcador].golos+golos;
       result[i].marcadores[i]=marcador;
       result[i].golos_a=result[i].golos_b+golos;
       //
       if (result[i].golos_a>result[i].golos_b)
        {
            equip[a].vitorias++;
            equip[b].derrotas++;
        }
       if (result[i].golos_a<result[i].golos_b)
        {
            equip[a].derrotas++;
            equip[b].vitorias++;
        }
        if (result[i].golos_a==result[i].golos_b)
        {
            equip[a].empates++;
            equip[b].empates++;
        }


       result[i].ativo=1;
       i++;

       printf("\nDeseja Registar outro Resultado? [1] SIM / [2] NÃO\n");
       scanf("%d", &op);
   	}while (op == 1 && op<R);

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
	printf("| 5.Transferencias de jogadores   |\n");
	printf("| 6.Registo de Jogos e Resultados |\n");
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
				editar_jog(); // chama a função que edita jogadores
				break;
		case '3':
				inserir_equip(); // chama a função inserir equipa
				break;
		case '4':
				editar_equip(); // chama função editar equipa
				break;
		case '5':
				tranferir_jog(); // chama função editar equipa
				break;
        case '6':
				registar_jogos(); // chama função editar equipa
				break;
		case '0':
				return; //regressa ao menu principal "afm.c"

	}


}

