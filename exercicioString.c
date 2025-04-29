//Dado um texto, identificar cada palavra deste texto e verificar se é palíndroma.
//Uma palavra palíndroma é aquela que apresenta a mesma grafia quando lida a partir
//do início ou de trás para diante; exemplo: RIR, SOLOS, ASA, RALAR, AMA. O
//programa deve utilizar uma função booleana para verificar se uma palavra
//identificada no texto é palíndroma. A saída do programa deve ser uma tabela listando
//as palavras identificadas e, para cada uma, a mensagem dizendo se é ou não
//palíndroma.

#include <stdio.h>
#include <string.h>

#define TAMANHO 100

int main(){
    char texto[TAMANHO] = {};
    char palavra[TAMANHO] = {};
    char palavraInvertida[TAMANHO] = {};
    int contador, j = 0, flag = 0;
    
    printf("Por favor, digite o texto: ");
    fgets(texto, sizeof(texto), stdin);
    contador = strlen(texto)-1;

    texto[strlen(texto+1)] = ' ';

    for (int i = 0; i < TAMANHO; i++){
        if (texto[i] != ' '){
            palavra[j] = texto[i];
            j++;
        }
        else if (texto[i] == ' ' || texto[i] == '\0'){
            printf("\n%s", palavra);
            j = 0;
            contador = strlen(palavra)-1;
            for (int k = 0; k < TAMANHO; k++){
                palavraInvertida[k] = palavra[contador];
                contador = contador-1;
            }
            contador = strlen(palavra);
            for (int z = 0; z < strlen(palavra); z++){
                if (palavra[z] == palavraInvertida[z]){
                    flag = 1;
                    }
                else
                    flag = 0;
            }
            if (flag == 1)
                printf(" -> palindromo");
            memset(palavra, 0, strlen(palavra) + 1);
            }
        }
    return 0;

}
