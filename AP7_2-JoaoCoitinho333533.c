//Uma banca online de venda de frutas vende tre s tipos de frutas: laranja, maça e lima o. Faça um programa
//em que o cliente informa a quantidade de cada fruta que deseja comprar, o endereço para entrega e se o mesmo
//se localiza na zona A ou B da cidade. O cliente sempre deve informar as quantidades das 3 frutas, caso ele na o
//deseje comprar alguma delas deve entrar o valor zero

//a) (1,5pts) Uma funcao que retorne o preço total da compra ao receber as quantidades desejadas (em
//nu mero de frutas de cada tipo) e adicionando ao preço base o imposto de cada fruta segundo a lista:

//qb) (1,5pts) Uma funça o que calcule o valor da entrega que deve considerar:
//• Zona de entrega: se A a entrega e R$ 10,00 e se for B e R$ 5,00.
//• Cada entrega somente pode levar 25 unidades, caso o cliente tenha adquirido mais de 25 vai pagar
//mais entregas. Por exemplo: cliente selecionou 51 frutas vai pagar 3 entregas.
//c) (1,5pts) Uma funcao sem retorno de valor que imprime o valor total das frutas, valor total da entrega e
//valor total geral.
//d) (1,5pts) No main do programa, apo s a entrada de dados utilize somente as funço es acima para calcular e
//exibir o valor total a pagar.


#include <stdio.h>

#define QUANT_FRUTAS 3

float calculaPreco(int laranja, int maca, int limao);
float calculaFrete(char area, int quantTotal);

int main(){
    char fruteira[QUANT_FRUTAS][20] = {"laranja", "maca", "limao"};
    char endereco[100] = {};
    int frutas[QUANT_FRUTAS] = {};
    int fruta = 0, quantTotal = 0;
    float preco = 0;
    char area;
    printf("Tabela de precos:\nLaranja: R$3,00 | 2%% imposto\nMaca: R$2,00 | 5%% imposto\nLimao: R$1,00 | 3%% imposto");

    for (int i = 0; i < QUANT_FRUTAS;i++){
        printf("\nPor favor, informe a quantidade desejada de %ss: ", fruteira[i]);
        scanf("%d", &fruta);
        if (fruta < 0){
            printf("Por acaso voce esta tentando roubar frutas de nosso estoque?");
            return 1;
        }
        else 
            quantTotal = quantTotal+fruta;
        frutas[i] = fruta;

    }

    getchar();

    printf("Endereco de entrega: ");
    fgets(endereco, sizeof(endereco), stdin);
    printf("Area:");
    scanf("%c", &area);

    preco = calculaPreco(frutas[0], frutas[1], frutas[2]);
    printf("Total da compra: R$%.4f", preco);

    return 0;
}

float calculaPreco(int laranja, int maca, int limao){
    float precoLaranja = 0, precoMaca = 0, precoLimao = 0, preco = 0;

    precoLaranja = laranja * 3;
    precoLaranja = precoLaranja + (precoLaranja*3)/100;
    precoMaca = maca * 2;
    precoMaca = precoMaca + (precoMaca*2)/100;
    precoLimao = limao;
    precoLimao = precoLimao + (precoLimao)/100;
    preco = precoLaranja+precoMaca+precoLimao;
    return preco;
}

float calculaFrete(char area,int quantTotal ){
    
    




}

