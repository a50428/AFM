// Função menu_1() "menu_1.c"
// Função que implementa as operações do Menu 1 (Inserir/Editar)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Outras funções

// ###############################################################

int ver_jogos(void)
{
   int i,j,x,y,a,b;

    system("clear");
    printf("| Local | Data | Resultados | ---> Marcadores |\n");
    printf("+---------------------------+");
    for (i=1;i<R;i++)
        {
            if (result[i].id==0) break;
            a=result[i].equipa_a;
            b=result[i].equipa_b;
            printf("\n| %s | %s | %s [%d] - %s [%d]",result[i].local,result[i].data,equip[a].nome,result[i].golos_a,equip[b].nome,result[i].golos_b);
            printf("\n");
            for (j=1;j<21;j++) // lista os marcadores para cada jogo
            {
                x=result[i].marcadores[j];
                y=result[i].marcados[j];
                if (x>0) printf("\n\---> %s [%d] ",jog[x].nome,y);
            }
            printf("\n");
        }

    printf("\n+-----------FIM-------------+\n");
    printf("\nQualquer tecla para voltar...");


    getchar();
    getchar();
    menu_1();



}

// ############################################################

int listar_jog(void) // função que lista jogadores existentes
{
    int op,i,team;

    system("clear");
    printf("|  ID  | NOME | IDADE | EQUIPA | POSICAO |\n");
    printf("+----------------------------------------+");
    for (i=1;i<J;i++)
        {
            if (jog[i].ativo!=0)
            {
                team=jog[i].eq;
                printf("\n| %d | %s | %d | %s | %s |",i,jog[i].nome,jog[i].idade,equip[team].nome,jog[i].pos);
            }

        }

    printf("\n\n+------------------FIM-------------------+\n");

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

    printf("\n\n+------------------FIM-------------------+\n");

    getchar();

}

// ############################################################

int listar_jog_a(int x) // função que lista jogadores existentes na Equipa x (argumento da função, ID da equipa A ou B)
{
    int op,i,team;

    system("clear");
    printf("|  ID  | NOME | IDADE | EQUIPA | POSICAO |\n");
    printf("+----------------------------------------+");
    for (i=1;i<J;i++)
        {
            if (jog[i].num_cc==0) break;

            if (jog[i].eq==equip[x].id) printf("\n| %d | %s | %d | %s | %s |",i,jog[i].nome,jog[i].idade,equip[x].nome,jog[i].pos);
        }

    printf("\n\n+------------------FIM-------------------+\n");

    getchar();

}

// ####################################################

int inserir_jog(void) // função que insere novo jogador
{
    int op;
    int i=0;
    do
    {
        i++; // vai para o ultimo registo (ou seja o primeiro indice onde jog[i].ativo=0)
    } while (jog[i].ativo>0);

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
       //
       printf("Escolha a Posição: [1]-Guarda-Redes;[2]-Defesa;[3]-Médio;[4]-Avançado.");
       do {
        scanf("%d",&jog[i].pos_list);
       } while (jog[i].pos_list<1 || jog[i].pos_list>4);

       if (jog[i].pos_list==1) strcpy(jog[i].pos,"Guarda-Redes"); // se escolha =1 copia string...
       else
        {
            printf("Posição Especifica: ");
            scanf(" %99[^\n]",&jog[i].pos);
        }
       jog[i].ativo=1;
       i++;

       while (jog[i].ativo>0) i++; // vai para o proximo indice não ativo (jog[i].ativo=0)

       printf("\nDeseja Inserir outro Jogador? [1] SIM / [0] NÃO\n");
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
            if (equip[i].id!=0) printf("\n| %d | %s |",equip[i].id,equip[i].nome);
        }

    printf("\n\n+-----FIM-----+\n");

    getchar();

}

// ####################################################

int inserir_equip(void) // função que insere nova equipa
{
    int op;
    int i=0,j=1;
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
       do
       {
           printf("\nPretende selecionar jogadores para %s? [1] SIM / [2] NAO: ",equip[i].nome);
           scanf("%d",&op);
           if (op==1)
            {
                system("clear");
                listar_jogx();
                printf("\nSelecione o ID do jogador que pretende: ");
                scanf("%d", &id);
                jog[id].eq=i;
                equip[i].lista[j]=id; j++; // regista id jogador no array lista de jogadores max 25
                printf("\n\nJogador %s adicionado a %s com sucesso!\n", jog[id].nome,equip[i].nome);
                getchar();
            }
       } while (op!=2 && equip[i].lista[j]<26);
       i++;
       while (equip[i].id>0) i++; // vai para o proximo indice não ativo (equip[i].ativo=0)
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
        printf("\n\nApagar Jogador (%d) - %s? [1] SIM / [2] NAO, Quero editar : ",id,jog[id].nome);
        scanf("%d", &op);
        if (op==1)
            {
                //jog[id].num_cc=0;
                jog[id].ativo=0; // jogador indice [id] passa à condição de inativo ou seja apagado
                printf("\nJogador ID [%d] apagado com sucesso!\n",id);
                getchar();
            }
        if (op==2)
            {
                // Mostra ficha de jogador...
                system("clear");
                printf("\t| FICHA DE JOGADOR [%d] |",id);
                printf("\n\t+-----------------------+");
                printf("\n\t| Numero CC: %d ",jog[id].num_cc);
                printf("\n\t| Nome: %s ",jog[id].nome);
                printf("\n\t| Morada: %s ",jog[id].morada);
                printf("\n\t| Telefone: %s ",jog[id].telefone);
                printf("\n\t| Idade: %d ",jog[id].idade);
                printf("\n\t| Ano de Entrada: %d ",jog[id].ano_entrada);
                printf("\n\t| Posicao: %s ",jog[id].pos);
                printf("\n\t+-----------------------+\n\n");
                //Editar jogador...
                printf("\tEditar Jogador [%d]\n\n", id);
                printf("\tNumero CC: ");
                scanf("%d",&jog[id].num_cc);
                printf("\tNome: ");
                scanf(" %99[^\n]",&jog[id].nome);
                printf("\tMorada: ");
                scanf(" %99[^\n]",&jog[id].morada);
                printf("\tTelefone: ");
                scanf(" %99[^\n]",&jog[id].telefone);
                printf("\tIdade: ");
                scanf("%d",&jog[id].idade);
                printf("\tAno de Entrada: ");
                scanf("%d",&jog[id].ano_entrada);
                //
                printf("Escolha a Posição: [1]-Guarda-Redes;[2]-Defesa;[3]-Médio;[4]-Avançado.");
                do {
                    scanf("%d",&jog[id].pos_list);
                } while (jog[id].pos_list<1 || jog[id].pos_list>4);

                if (jog[id].pos_list==1) strcpy(jog[id].pos,"Guarda-Redes"); // se escolha =1 copia string...
                else
                {
                    printf("Posição Especifica: ");
                    scanf(" %99[^\n]",&jog[id].pos);
                }
            }

        printf("\nDeseja apagar/editar outro Jogador? [1] SIM / [0] NÃO\n");
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
   int x,k,op,id_eq,id_jog,j=1;

   do {
        system("clear");
        listar_jog(); // lista jogadores
        printf("\nQual o ID do jogador a tranferir? [0] Sair: ");
        scanf("%d", &id_jog);
        if (id_jog==0) break;
        // eliminar o jogador da lista da equipa anterior...
        x=jog[id_jog].eq;
        for (k=1;k<26;k++)
            {
                if (equip[x].lista[k]==id_jog) equip[x].lista[k]=0; // quando encontrar coloca a zero.
            }
        listar_equip(); // lista equipas
        printf("\nQual o ID da equipa de destino? [0] Sair: ");
        scanf("%d", &id_eq);
        if (id_eq==0) break;
        jog[id_jog].eq=id_eq;
        while (equip[id_eq].lista[j]!=0) j++; // avança até encontrar vazio...
        equip[id_eq].lista[j]=id_jog; j++; // regista id jogador no array lista de jogadores max 25
        printf("\n\nTranferencia efectuada com sucesso!");
        printf("\n\nDeseja tranferir outro Jogador? [1] SIM / [2] NÃO\n");
        scanf("%d", &op);

    }while (op == 1 || j<26); //max 25

   menu_1();

}

// ####################################################

int registar_jogos(void) // função que regista jogos e resultados
{
    int a,b,op,marcador,golos,i=0,j=1;

    do
    {
        i++; // vai para o ultimo registo
    } while (result[i].id>0);

    do
    {
       system("clear");
       printf("Registar Jogos e Resultados ID [%d]? [1] Registar [0] Sair : ",i);
       scanf("%d",&op);
       if (op==0) break;
       printf("\n\tData: ");
       scanf(" %99[^\n]",&result[i].data);
       printf("\n\tLocal: ");
       scanf(" %99[^\n]",&result[i].local);
       listar_equip();
       printf("\nEquipa A ID?: ");
       scanf("%d",&a);
       result[i].equipa_a=a; // carrega equipa A ID para struct
       printf("\nEquipa B ID?: ");
       scanf("%d",&b);
       result[i].equipa_b=b; // // carrega equipa B ID para struct
       // repete registo de marcador equipa A
       do {
           listar_jog_a(a);
           printf("\nMarcador ID Equipa A? [0] Sem golos: "); // repetir
           scanf("%d",&marcador);


           if (marcador==0)
            {
                op=0;
                result[i].golos_a=0; // a equipa A não marcou golos
            }
           else // senão è zero...
            {
                printf("\nQuantos golos marcou %s?: ", jog[marcador].nome);
                scanf("%d", &golos);
                jog[marcador].golos=jog[marcador].golos+golos; // acumula golos jogador
                result[i].marcadores[j]=marcador; // regista marcadores para o jogo atual
                result[i].marcados[j]=golos;
                j++;
                result[i].golos_a=result[i].golos_a+golos; // soma golos equipa A
                printf("\nRegistar mais marcadores para Equipa A? [1] Sim [0] Nao: ");
                scanf("%d",&op);
            }



       } while (op!=0);

       // repete registo de marcador equipa B
       do {
           listar_jog_a(b);
           printf("\nMarcador ID Equipa B? [0] Sem golos: "); // repetir
           scanf("%d",&marcador);

           if (marcador==0)
            {
                op=0;
                result[i].golos_a=0; // a equipa B não marcou golos
            }
           else //senão è zero...
            {
               printf("\nQuantos golos marcou %s?: ", jog[marcador].nome);
               scanf("%d", &golos);
               jog[marcador].golos=jog[marcador].golos+golos;
               result[i].marcadores[j]=marcador;
               result[i].marcados[j]=golos;
               j++;
               result[i].golos_b=result[i].golos_b+golos;
               printf("\nRegistar mais marcadores para Equipa B? [1] Sim [0] Nao: ");
               scanf("%d",&op);
            }


       } while (op!=0);

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

        printf("\n\t %s [%d] - %s [%d]",equip[a].nome,result[i].golos_a,equip[b].nome,result[i].golos_b);

       result[i].ativo=1;
       result[i].id++;
       i++;

       printf("\n\nDeseja Registar outro Resultado? [1] SIM / [2] NÃO\n");
       scanf("%d", &op);
   	}while (op==1 && op<R);

    menu_1();

}


//função de testes para listar todas as equipas e jogadores por equipa
int eq_list(void)
{
    int i,j,id;

    system("clear");
    printf("| Lista de jogadores por equipa |");
    for (i=1;i<J;i++)
        {
            if (equip[i].id!=0) printf("\n| %d | %s |",equip[i].id,equip[i].nome);

            for (j=1;j<26;j++)
                {
                    id=equip[i].lista[j];
                    if (id!=0) printf("\n\t|--> %s - %d - %s ",jog[id].nome,jog[id].idade,jog[id].pos);
                }
        }
    printf("\n\nQualquer tecla para continuar...");
    getchar();
    getchar();
    menu_1();
}
// ####################################################################################################

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
	printf("| 7.Visualizar Jogos e Resultados |\n");
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
        case '7':
				ver_jogos(); // chama função ver jogos
				break;
        // temp
		case '8':
				eq_list();
				return; //regressa ao menu principal "afm.c"
		case '0':
				return; //regressa ao menu principal "afm.c"

	}


}

