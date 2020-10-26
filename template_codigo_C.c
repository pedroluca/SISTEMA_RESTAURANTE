#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>

//VARIÁVEIS
char bolos[15][20] = {"BOLO DE CHOCOLATE", "BOLO DE MORANGO", "BOLO DE LARANJA", "BOLO DE CENOURA", "BOLO DE LIMÃO"};
float pBolos[15] = {5, 5, 5, 5, 5};
char bebidas[15][30] = {"SUCO DE MORANGO 1L", "SUCO DE LARANJA 1L", "SUCO DE LIMÃO 1L", "SUCO DE ABACAXI 1L", "COCA-COLA 1L", "COCA-COLA 2L", "SUCO DE UVA 1L", "CERVEJA SKOL", "VINHO TINTO","FANTA LARANJA 2L", "FANTA UVA 2L", "FANTA SPRITE 2L", "FANTA MARACUJÁ 2L"};
float pBebidas[15] = {3, 3, 3, 3, 4, 7, 3, 4.5, 5, 4, 4, 4, 4};
char comidas[15][40] = {"PORÇÃO DE BATATA FRITA", "CHURRASCO PEQUENO", "CHURRASCO MÉDIO", "CHURRASCO GRANDE", "PORÇÃO DE MANDIOCA", "PORÇÃO DE TOMATE", "ALMOÇO SIMPLES", "ALMOÇO COMPLETO"};
float pComidas[15] = {8, 25, 35, 45, 8, 7, 37, 64};
char salgados[15][30] = {"TORTINHA DE FRANGO", "MINI PIZZA", "PASTEL DE CARNE", "PASTEL DE FRANGO", "PASTEL DE QUEIJO", "PASTEL DE PIZZA", "COXINHA", "COXINHA C/ CATUPIRY", "QUIBE", "EMPADA DE CARNE", "EMPADA DE FRANGO", "PASTEL ASSADO DE CARNE", "PASTEL ASSADO DE FRANGO", "PORÇÃO DE BOLINHA DE QUEIJO"};
float pSalgados[15] = {5, 4.5, 2.5, 2.5, 2.5, 2.5, 2.5, 3, 2, 3, 3, 3, 3, 10};
char doces[15][30] = {"CUPCAKE", "BRIGADEIRO", "BEIJINHO", "ARROZ DOCE", "TORTA DE MAÇÃ"};
float pDoces[15] = {3, 1, 1 , 4, 8};
char clientes[15][30] = {"PEDRO LUCA", "OTÁVIO", "ALDA", "TOM", "MARIA EDUARDA"};
int opcao, idPedidos[30], emptCliente[15], quantPedidos, codPedidos, quantNotaPedido[45];
char pedidos[30][30];
char addPedido[1][40];
char clienteAtual[1][35];
//VARIÁVEIS DE DINHEIRO
float caixaTotal, notaPedido, preco;
int quantidade, produtoGeral;
//CONTROLE DE VERSÃO
char version[] = "v1.2";

void novoCliente(){
    system("cls");
    char novoC[1][30], valid[] = "123";
    printf("<<== = = = = ==>> NOVO CLIENTE <<== = = = = ==>>\n");
    printf("INFORME O NOME DO NOVO CLIENTE: (DIGITE 123 PARA VOLTAR)\n");
    printf("R: ");
    for(int i = 0; i <= 9; i++){
        if(emptCliente[i] == 0){
            scanf("%s", novoC);
            if(strcmp(novoC, valid) == 0){
                printf("\n\nVOLTANDO... \n");
                system("pause");
                iniciarPrograma();
            }
            if(strlen(novoC) > 30){
                printf("\nO NOME ULTRAPASSOU O LIMITE DE 30 LETRAS!\nTENTE NOVAMENTE.\n");
                system("pause");
                novoC[1][0] = '\0';
                novoCliente();
            }else{
                strcpy(clientes[i], novoC);
                emptCliente[i] = 1;
                system("cls");
                printf("CLIENTE ADICIONADO COM SUCESSO!\n");
                system("pause");
                iniciarPrograma();
            }
        }
    }
}

void verCliente(){
    system("cls");
    printf("<<== = = = = ==>> ESCOLHER CLIENTE <<== = = = = ==>>\n");
    for(int i = 0; i < 10; i++){
        printf("ID: %d | NOME: %s\n", i + 1, clientes[i]);
        printf("<<== = = = = = = = = = = = = = = = = = = = = = ==>>\n");
    }
    system("pause");
    iniciarPrograma();
}

void verCaixa(){
    system("cls");
    printf("<<== = = = = = ==>> CAIXA <<== = = = = = ==>>\n");
    printf("\nVALOR REGISTRADO EM DINHEIRO: R$%.2f \n", caixaTotal);
    printf("\nQUANTIDADE DE PRODUTOS JÁ VENDIDOS: %d \n\n", produtoGeral);
    printf("<<== = = = = = = = = = = = = = = = = = = ==>>\n");
    system("pause");
    iniciarPrograma();
}

void novoPedido(){
    system("cls");
    printf("<<== = = = = ==>> ESCOLHER CLIENTE <<== = = = = ==>>\n");
    for(int i = 0; i < 10; i++){
        printf("ID: %d | NOME: %s\n", i + 1, clientes[i]);
        printf("<<== = = = = = = = = = = = = = = = = = = = = = ==>>\n");
    }
    printf("ESCOLHA UM CLIENTE - (PARA VOLTAR DIGITE 123)\n");
    printf("R: ");
    scanf("%d", &opcao);
    if(opcao == 123){
        printf("\n\nVOLTANDO...\n\n");
        system("pause");
        iniciarPrograma();
    }
    opcao = opcao - 1;
    strcpy(clienteAtual, clientes[opcao]);
    prosseguirPedido();
}

void iniciarPrograma(){
    int opc;
    system("cls");
    printf("<<== = = = = ==>> MENU <<== = = = = ==>>\n");
    printf("  ||                                ||\n");
    printf("  || 1- INICIAR PEDIDO              ||\n");
    printf("  || 2- NOVO CLIENTE                ||\n");
    printf("  || 3- VER CLIENTES                ||\n");
    printf("  || 4- VER CAIXA                   ||\n");
    printf("  || 5- FECHAR PROGRAMA             ||\n");
    printf("  ||                                ||\n");
    printf("<<== = = = = = = = = = = = = = = =  ==>>\n");
    printf("ESCOLHA: ");
    scanf("%d", &opc);
    switch(opc){
    case 1:
        novoPedido();
        break;
    case 2:
        novoCliente();
        break;
    case 3:
        verCliente();
        break;
    case 4:
        verCaixa();
        break;
    case 5:
        exit(opc);
        break;
    default:
        printf("\n\nERRO! ESSA OPÇÃO É INVÁLIDA\n");
        system("pause");
        iniciarPrograma();
    }
}

void fechamento(){
    //FUNÇÃO PARA FINALIZAR E RESETAR AS VARIÁVEIS
    system("cls");
    produtoGeral = produtoGeral + quantPedidos;
    caixaTotal = notaPedido;
    preco = 0;
    for(int i = 0; i <= quantPedidos; i++){
        pedidos[i][0] = '\0';
    }
    quantidade = 0;
    quantPedidos = 0;
    printf("\nPRONTO! R$%.2f FORAM ADICIONADOS AO CAIXA!\n", notaPedido);
    notaPedido = 0;
    system("pause");
    iniciarPrograma();
}

void fecharPedido(){
    int opc;
    system("cls");
    printf("\n<<== = = ==>> CUPOM FISCAL <<== = = ==>>\n");
    printf("  CLIENTE: %s\n", clienteAtual);
    printf("<<== = = = = = = = = = = = = = = =  ==>>\n");
    printf("  PEDIDOS: \n");
    printf("  CÓDIGO | PRODUTO | QUANTIDADE\n");
    for(int i = 0; i < codPedidos; i++){
        printf("  %d | %s | %d \n", i + 1, pedidos[i], quantNotaPedido[i]);
    }
    printf("<<== = = = = = = = = = = = = = = =  ==>>\n");
    printf("  QUANTIDADE DE PRODUTOS: %d\n", quantPedidos);
    printf("\n  VALOR TOTAL: R$%.2f", notaPedido);
    printf("\n<<== = = = = = = = = = = = = = = =  ==>>\n");
    printf("\n FECHAR PEDIDO? [1-SIM|2-NÃO]\n");
    printf(" R: ");
    scanf("%d", &opc);
    if(opc == 1){
        fechamento();
    }else{
        printf("\n\nOPERAÇÃO CANCELADA!\n");
        system("pause");
        prosseguirPedido();
    }
}

void verPedidos(){
    system("cls");
    printf("<<== = = ==>> PEDIDOS <<== = = ==>>\n");
    printf("  CÓDIGO | PRODUTO | QUANTIDADE\n");
    for(int i = 0; i < codPedidos; i++){
        printf("  %d | %s | %d \n", i + 1, pedidos[i], quantNotaPedido[i]);
    }
    printf("<<== = = = = = = = = = = = = = ==>>\n");
    system("pause");
    prosseguirPedido();
}

void prosseguirPedido(){
    system("cls");
    int opc, sOpc, conf;
    printf("\nCLIENTE: %s | QUANTIDADE DE PEDIDOS: %d \n", clienteAtual[0], quantPedidos);
    printf("\n");
    printf("<<== = = = ==>> CARDÁPIO <<== = = = ==>>\n");
    printf("  || 1- BOLOS                       ||\n");
    printf("  || 2- COMIDAS                     ||\n");
    printf("  || 3- SALGADOS                    ||\n");
    printf("  || 4- BEBIDAS                     ||\n");
    printf("  || 5- DOCES                       ||\n");
    printf("  || 6- CANCELAR                    ||\n");
    if(quantPedidos >= 1){
        printf("  || 7- VER PEDIDOS                 ||\n");
        printf("  || 8- FECHAR PEDIDO               ||\n");
    }
    printf("<<== = = = = = = = = = = = = = = =  ==>>\n");
    printf("ESCOLHA: ");
    scanf("%d", &opc);
    switch(opc){
        case 1:
            system("cls");
            printf("<<== = = = ==>> BOLOS <<== = = = ==>>\n");
            for(int i = 0; i < 15; i++){
                printf("  %d- %s | R$%.2f \n", i + 1, bolos[i], pBolos[i]);
                printf("<<==================================>>\n");
            }
            printf("ESCOLHA UM SABOR: (DIGITE 123 PARA VOLTAR)\n");
            printf("R: ");
            scanf("%d", &sOpc);
            sOpc = sOpc - 1;
            if(sOpc == 122){
                prosseguirPedido();
            }
            printf("\nINFORME A QUANTIDADE: ");
            scanf("%d", &quantidade);
            printf("\nCONFIRMAR PEDIDO? [1-SIM|2-NÃO]\n");
            printf("R: ");
            scanf("%d", &conf);
            if(conf == 1){
                preco = pBolos[sOpc];
                strcpy(addPedido, bolos[sOpc]);
                adicionarPedido();
            }else{
            printf("\n\nPEDIDO CANCELADO! \n");
            system("pause");
            prosseguirPedido();
            }
            break;
        case 2:
            system("cls");
            printf("<<== = = = ==>> COMIDAS <<== = = = ==>>\n");
            for(int i = 0; i < 15; i++){
                printf("  %d- %s | R$%.2f \n", i + 1, comidas[i], pComidas[i]);
                printf("<<==================================>>\n");
            }
            printf("ESCOLHA UMA COMIDA: (DIGITE 123 PARA VOLTAR)\n");
            printf("R: ");
            scanf("%d", &sOpc);
            sOpc = sOpc - 1;
            if(sOpc == 122){
                prosseguirPedido();
            }
            printf("\nINFORME A QUANTIDADE: ");
            scanf("%d", &quantidade);
            printf("\nCONFIRMAR PEDIDO? [1-SIM|2-NÃO]\n");
            printf("R: ");
            scanf("%d", &conf);
            if(conf == 1){
                preco = pComidas[sOpc];
                strcpy(addPedido, comidas[sOpc]);
                adicionarPedido();
            }else{
            printf("\n\nPEDIDO CANCELADO! \n");
            system("pause");
            prosseguirPedido();
            }
            break;
        case 3:
            system("cls");
            printf("<<== = = = ==>> SALGADOS <<== = = = ==>>\n");
            for(int i = 0; i < 15; i++){
                printf("  %d- %s | R$%.2f \n", i + 1, salgados[i], pSalgados[i]);
                printf("<<==================================>>\n");
            }
            printf("ESCOLHA UM SALGADO: (DIGITE 123 PARA VOLTAR)\n");
            printf("R: ");
            scanf("%d", &sOpc);
            sOpc = sOpc - 1;
            if(sOpc == 122){
                prosseguirPedido();
            }
            printf("\nINFORME A QUANTIDADE: ");
            scanf("%d", &quantidade);
            printf("\nCONFIRMAR PEDIDO? [1-SIM|2-NÃO]\n");
            printf("R: ");
            scanf("%d", &conf);
            if(conf == 1){
                preco = pSalgados[sOpc];
                strcpy(addPedido, salgados[sOpc]);
                adicionarPedido();
            }else{
            printf("\n\nPEDIDO CANCELADO! \n");
            system("pause");
            prosseguirPedido();
            }
            break;
        case 4:
            system("cls");
            printf("<<== = = = ==>> BEBIDAS <<== = = = ==>>\n");
            for(int i = 0; i < 15; i++){
                printf("  %d- %s | R$%.2f \n", i + 1, bebidas[i], pBebidas[i]);
                printf("<<==================================>>\n");
            }
            printf("ESCOLHA UMA BEBIBA: (DIGITE 123 PARA VOLTAR)\n");
            printf("R: ");
            scanf("%d", &sOpc);
            sOpc = sOpc - 1;
            if(sOpc == 122){
                prosseguirPedido();
            }
            printf("\nINFORME A QUANTIDADE: ");
            scanf("%d", &quantidade);
            printf("\nCONFIRMAR PEDIDO? [1-SIM|2-NÃO]\n");
            printf("R: ");
            scanf("%d", &conf);
            if(conf == 1){
                preco = pBebidas[sOpc];
                strcpy(addPedido, bebidas[sOpc]);
                adicionarPedido();
            }else{
            printf("\n\nPEDIDO CANCELADO! \n");
            system("pause");
            prosseguirPedido();
            }
            break;
        case 5:
            system("cls");
            printf("<<== = = = ==>> DOCES <<== = = = ==>>\n");
            for(int i = 0; i < 15; i++){
                printf("  %d- %s | R$%.2f \n", i + 1, doces[i], pDoces[i]);
                printf("<<==================================>>\n");
            }
            printf("ESCOLHA UM DOCE: (DIGITE 123 PARA VOLTAR)\n");
            printf("R: ");
            scanf("%d", &sOpc);
            sOpc = sOpc - 1;
            if(sOpc == 122){
                prosseguirPedido();
            }
            printf("\nINFORME A QUANTIDADE: ");
            scanf("%d", &quantidade);
            printf("\nCONFIRMAR PEDIDO? [1-SIM|2-NÃO]\n");
            printf("R: ");
            scanf("%d", &conf);
            if(conf == 1){
                preco = pDoces[sOpc];
                strcpy(addPedido, doces[sOpc]);
                adicionarPedido();
            }else{
            printf("\n\nPEDIDO CANCELADO! \n");
            system("pause");
            prosseguirPedido();
            }
            break;
        case 6:
            iniciarPrograma();
            break;
        case 7:
            verPedidos();
            break;
        case 8:
            if(quantPedidos <= 0){
                printf("\n\nNENHUM PEDIDO REGISTRADO!\n");
                system("pause");
                prosseguirPedido();
            }
            fecharPedido();
            break;
        default:
            system("cls");
            printf("OPÇÃO INVÁLIDA!\n");
            iniciarPrograma();
    }
}

void adicionarPedido(){
    float a;
    for(int i = 0; i < 30; i++){
        if(idPedidos[i] == 0){
            idPedidos[i] = 1;
            quantNotaPedido[i] = quantidade;
            quantPedidos = quantPedidos + quantidade;
            codPedidos++;
            a = quantidade * preco;
            notaPedido = notaPedido + a;
            strcpy(pedidos[i], addPedido);
            system("cls");
            printf("\nPEDIDO ADICIONADO!\n");
            system("pause");
            system("cls");
            prosseguirPedido();
        }
    }
}

void setup(){
    setlocale(LC_ALL, "");
    for(int i = 0; i <= 4; i++){
        emptCliente[i] = 1;
    }
    iniciarPrograma();
}

int main(){
    printf("\n\n<<== = = = = = = = = = = = = = = = = ==>>\n");
    printf("  ||                                 ||\n");
    printf("  ||                                 ||\n");
    printf("  ||           RESTAURANTE           ||\n");
    printf("  ||                                 ||\n");
    printf("  ||               DA                ||\n");
    printf("  ||                                 ||\n");
    printf("  ||              MARIA              ||\n");
    printf("  ||                                 ||\n");
    printf("  ||                                 ||\n");
    printf("<<== = = = = = = = = = = = = = = = = ==>>  %s\n", version);
    system("pause");
    setup();
}
