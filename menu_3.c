#include <stdio.h>

// função que calcula a media de golos por jogo
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

int medidades (void)
{
    int a=0, numjogadores=0,i,equipa,b;
    float media;
    listar_equip();
    printf("Qual a equipa?\n");
    scanf("%d",&equipa);
    for (i=1;i<26;i++)
        {
            if  (equip[equipa].lista[i]>0)
              {
              b=equip[equipa].lista[i]; //id jogador
              a=a+(jog[b].idade);
              numjogadores++;

                }
         }
    media=(float)a/numjogadores;

    printf("media de idades é: %.f",media);
    getchar();
getchar();
menu_3();
}

int mmarcador (void)
{
int i,j,temp,k;

//ordenar array
 for (i=1;i<=(J-1);i++)
     for (j=J;j>i;j--)
         if (jog[j].golos>jog[j-1].golos)
            {
             temp=jog[j-1].golos;
             jog[j-1].golos=jog[j].golos;
             jog[j].golos=temp;
            }
//mostrar top 10
printf("+         ESTATISTICAS          +\n\n");
printf("| Nome jogador | golos marcados |\n");
    for (k=1;k<11;k++) printf("\n| %s | %d |", jog[k].nome,jog[k].golos);
printf("\n\n+-------------FIM-------------+\n");
    getchar();
getchar();
menu_3();



}


// função menu_3
int menu_3()
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
