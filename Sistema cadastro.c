#include <stdio.h>
#include <conio.h>


 struct cadastro_do_usuario {

    char  nome[60];
    char sobrenome[50];
    int CPF;
    int RG;
    int ddmmaa;
    char email[50];
    char senha[70];
};

    struct cadastro_de_ativos {

      char houst[50];
      char marca[30];
      char modelo[20];
      char serviceteg[50];
      int notafiscal;
};

    struct cadastro_de_dispmoveis {

      char houst[50];
      char marca[30];
      char modelo[30];
      char imei[20];
      int notafiscal;
      int numerodeserie;
      int numerogsm;
};

int main(void) {

    FILE *usu_arq;
    FILE *at_arq;
    FILE *mob_arq;

    usu_arq = fopen("progcadastrousuario.bin", "ab");
    at_arq = fopen("progcadastroativo.bin", "ab");
    mob_arq = fopen("progcadastromobile.bin", "ab");

    if (usu_arq == NULL){
        printf("Arquivo nao encontrado");

    }else
          printf("arquivo encontrado\n");

    if (at_arq == NULL){
        printf("Arquivo nao encontrado");

    }else
          printf("arquivo encontrado\n");

    if (mob_arq == NULL){
        printf("Arquivo nao encontrado");

    }else
          printf("arquivo encontrado\n");

int opc;

    struct cadastro_do_usuario usuario;
     struct cadastro_de_ativos ativo;
     struct cadastro_de_dispmoveis mobile;

    while (1) {

    printf("1 - Cadastro de usuario\n");
    printf("2 - Cadastro de ativos\n");
    printf("3 - Cadastro de dispositivos moveis\n");
    scanf("%d",&opc);



    switch (opc) {

    case 1:

        printf("-----------Cadastro do usuario-----------------\n");


            printf("Nome:");
            scanf("%s",usuario.nome);

            printf("Sobrenome:");
            scanf("%s",usuario.sobrenome);

            printf("CPF:");
            scanf("%d",&usuario.CPF);

            printf("RG:");
            scanf("%d",&usuario.RG);

            printf("Data de Nascimento DD/MM/AA:");
            scanf("%d",&usuario.ddmmaa);

            printf("e-mail:");
            scanf("%s",usuario.email);

            printf("Senha:");
            scanf("%s",usuario.senha);

            fwrite(&usuario,sizeof(usuario),1, usu_arq);
            fclose(usu_arq);
         break;

    case 2 :
            printf("Cadastro de ativo\n");

            printf("Houstname:");
            scanf("%s",&ativo.houst);

            printf("Marca do equipamento:");
            scanf("%s",&ativo.marca);

            printf("Modelo de equipamento:");
            scanf("%s",&ativo.modelo);

            printf("Serviceteg:");
            scanf("%s",&ativo.serviceteg);

            printf("Nota Fiscal:");
            scanf("%d",&ativo.notafiscal);
            fwrite(&ativo,sizeof(struct cadastro_do_usuario),1, at_arq);
           fclose(at_arq);
            break;

    case  3:
            printf("Cadastrar dispositivo mobile\n");

            printf("Houstname:");
            scanf("%s",&mobile.houst);

            printf("Marca do dispositivo:");
            scanf("%s",&mobile.marca);

            printf("Modelo:");
            scanf("%s",&mobile.modelo);

            printf("IMEI:");
            scanf("%s",&mobile.imei);

            printf("Numero de Serie:");
            scanf("%d",&mobile.numerodeserie);

            printf("Nota Fiscal:");
            scanf("%d",&mobile.notafiscal);

            printf("Numero de Telefone Dispositivo:");
            scanf("%d",&mobile.numerogsm);
            fwrite(&mobile,sizeof(mobile),1, mob_arq);
            fclose(mob_arq);
            break;
     break;
    }
    }


return (0);
}

