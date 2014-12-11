// Projeto Modulo Temático LTIC 2014/15
// AFM - Software gestão para Associação de Futebol do Montenegro
// "menu_3"

/* !
* \ file menu_3.c
* \ brief Projeto Modulo Temático LTIC 2014/15 "menu_3.c"
* \ details "menu_3.c" que implementa as operações do Menu 3 e respetivas funções
* \ author Patrick Arsenio
* \ date 01 dez 2014
* \ bug sem erros detetados
* \ version 0.1
* \ copyright GNU Public License.
*/

#include <stdio.h>

// ! medgolos
/* *
* função que mostra no ecran a media de golos de todos os jogos realizados
* \ param void
* \ return int
*/
int medgolos (void)
{
    int a,b,numgolos=0, numjogos=0,i,aux=0;
    float media;
    for (i=0;i<R;i++)
        {
            if  (result[i].ativo==1)
              {
              a=result[i].golos_a;
              b=result[i].golos_b;
              numgolos=a+b;
              aux=aux+numgolos;
              numjogos++;
                }
         }
    media=(float)aux/numjogos; // "cast" do valor ((float)aux/numjogos), transforma inteiro em float

    printf("\n\-> Numero de jogos realizados: %d",numjogos);
    printf("\n\-> Total de golos marcados: %d",aux);
    printf("\n\-> Media de golos marcados no total de jogos realizados: %.2f",media);
    printf("\n\nQualquer tecla para continuar...");
    getchar();
    getchar();

}

// ! medidades
/* *
* função que mostra no ecran a media de idades de todos os jogadores
* \ param void
* \ return int
*/
int medidades (void)
{
    int idades=0, numjogadores=0,i,equipa,b;
    float media;
    listar_equip();
    printf("\nQual a equipa?: ");
    scanf("%d",&equipa);
    for (i=1;i<J;i++) // percorre jogadores
        {
            if (jog[i].eq==equipa) // se for == a equipa escolhida
                {
                 idades=idades+jog[i].idade; // soma idades dos jogadores da mesma equipa
                 numjogadores++; //incrementa numero de jogadores
                }
        }
    media=(float)idades/numjogadores; // calcula media

    printf("\nA Media de idades do %s: %.f",equip[equipa].nome,media);
    printf("\n\nQualquer tecla para continuar...\n");
    getchar();
    getchar();
}

// ! mmarcador
/* *
* função que mostra no ecran os dez melhores marcadores
* \ param void
* \ return int
*/

int mmarcador (void)
{
int i,j,temp,k;

//ordenar array
 for (i=1;i<=(J-1);i++)
     for (j=J;j>i;j--)
         if (jog[j].golos>jog[j-1].golos) // se j for maior que o anterior troca
            {
             temp=jog[j-1].golos;
             jog[j-1].golos=jog[j].golos;
             jog[j].golos=temp;
            }
//mostrar top 10
system("clear");
printf("+         TOP 10          +\n\n");
printf("| ID | Nome jogador | golos marcados |\n");
    for (k=1;k<11;k++) printf("\n| %3d | %20s | %3d |",k, jog[k].nome,jog[k].golos);
printf("\n\n+-------------FIM-------------+\n");
printf("\nQualquer tecla para continuar...\n");
    getchar();
    getchar();
}

// ! menu_3
/* *
* funcao que implementa as operações do "Menu 3" (Estatisticas)
* \ param void
* \ return int
*/
int menu_3(void)
{
	int op; // variavel de opção para o menu
	//system("chcp 1252>null"); //CODEPAGE PT
	// MENU ESTATISTICAS
	do{
		system ("clear");
        printf("+         ESTATISTICAS         +\n\n");
        printf("| 1.Media de golos por jogo    |\n");
        printf("| 2.Media de idades por equipa |\n");
        printf("| 3.Melhor marcador            |\n");
        printf("| 0.Sair                       |\n");
        printf("\n");

        scanf("%d", &op);

        switch (op) {
            case 1:
                    medgolos(); // chama função media de golos
                    break;
            case 2:
                    medidades();// medidades(); // chama função media de idades
                    break;
            case 3:
                    mmarcador();// melhor(); // chama função melhor marcadord
                    break;

            case 0:
                   return;
                   // sai do menu_3
        }


	} while (op !=0 );


}

// FIM de menu_3.c #############################################################
