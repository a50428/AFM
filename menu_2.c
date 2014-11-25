// Funcao menu_2()
// Funcao que implementa as operacoes do Menu 2 (Listar/Pesquisar)

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Funcao listar resultados por equipa
int result_equip(void)
{

	int equipa, a, b, i;

	system("clear");

	listar_equip();
	printf("\n\nQual a equipa?: ");
	scanf("%d",&equipa);

	printf("\n|     Local     |     Data    |            Resultados           |");
	printf("\n+---------------------------------------------------------------+");

	for (i=1;i<E;i++)
    	{
        	if (equipa==result[i].equipa_a || equipa==result[i].equipa_b)
        	{
        	a=result[i].equipa_a;
            b=result[i].equipa_b;
        	printf("\n\n| %-13s | %-11s | %-10s[%-2d] - %-10s[%-2d] |",result[i].local,result[i].data,equip[a].nome,result[i].golos_a,equip[b].nome,result[i].golos_b);
    		}
    	}

	printf("\n\n+-----------------------------FIM-------------------------------+\n");
	printf("\nQualquer tecla para continuar...\n");
	getchar();
	getchar();

}

// Funcao listar jogadores por equipa
int jog_equip(void)
{

	int equipa, x, i;

	system("clear");

	listar_equip();
	printf("\n\nQual a equipa?: ");
	scanf("%d",&equipa);

	system("clear");

	printf("\n|     Jogadores de %s     |" , equip[equipa].nome);
	printf("\n+----------------------------+\n");
	for (i=1;i<J;i++)
        {
            if (jog[i].eq==equipa) printf("\n| %-3d | %-20s |",i,jog[i].nome);
        }
    printf("\n\n+------------FIM-------------+\n");
    printf("\nQualquer tecla para continuar...\n");
    getchar();
    getchar();

}

// Funcao listar jogadores por idade
int jog_idade(void)
{

	int idade, i;

	system("clear");

	printf("+         PESQUISAR IDADE        +\n\n");
	printf("Qual a idade?: ");
	scanf("%d", &idade);
	printf("\n\n");
	printf("| ID  |       NOME         | IDADE |      POSICAO     |\n");
    printf("+-----------------------------------------------------+");

	for (i=1;i<J;i++)
    	{
        	if (idade==jog[i].idade && jog[i].ativo>0 && jog[i].ativo!=2)
         	printf("\n| %-3d | %-18s |  %d   | %-16s |",i,jog[i].nome,jog[i].idade,jog[i].pos);
    	}

    printf("\n\n+----------------------FIM----------------------------+\n");
    printf("\nQualquer tecla para continuar...\n");
    getchar();
    getchar();

}

// Funcao listar jogadores por posicao
int jog_pos(void)
{

	int i, posic;

	system("clear");

	printf("+         PESQUISAR POSICAO        +\n\n");
	printf("Escolha a Posicao: [1]-Guarda-Redes;[2]-Defesa;[3]-Medio;[4]-Avancado ");
	scanf("%d" , &posic);

	printf("\n\n");
	printf("| ID  |        NOME        | IDADE |      POSICAO      |\n");
    printf("+------------------------------------------------------+");

	for (i=1;i<J;i++)
    	{
        	if (posic==jog[i].pos_list && jog[i].ativo>0 && jog[i].ativo!=2)
         	printf("\n| %-3d | %-18s |  %d   | %-17s |",i,jog[i].nome,jog[i].idade,jog[i].pos);
    	}

    printf("\n\n+------------------------FIM---------------------------+\n");
    printf("\nQualquer tecla para continuar...\n");
    getchar();
    getchar();

}

// Funcao menu_2
int menu_2()
{

    int op;

	//system("chcp 1252>null"); CODEPAGE PT

	do {

        system("clear");

        printf("+          LISTAR / PESQUISAR        +\n\n");
        printf("| 1.Listar Resultados por Equipa    |\n");
        printf("| 2.Listar Jogadores por Equipa     |\n");
        printf("| 3.Pesquisar Jogadores por Idade   |\n");
        printf("| 4.Pesquisar Jogadores por Posicao |\n");
        printf("| 0.Sair                            |\n");
        printf("\n");

        scanf("%d",&op);

		switch (op)
        	{
            	case 1:
                	result_equip();
					break;
            	case 2:
                	jog_equip();
					break;
            	case 3:
                	jog_idade();
					break;
            	case 4:
                	jog_pos();
					break;
            	case 0:
					break;
        	}

    	} while (op!=0);

}
