#include "raylib.h"
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define LARGURA 800
#define ALTURA 800
#define PASSO 20
#define TAMANHO_QUADRADO 20
#define TAMANHO_MATRIZ 40
#define TRUE 1
#define FALSE 0

void preencheMatriz(int matriz[TAMANHO_MATRIZ][TAMANHO_MATRIZ]);
void desenhaCampo(int matriz[TAMANHO_MATRIZ][TAMANHO_MATRIZ]);

int main(void){
    srand(time(NULL));
    InitWindow(LARGURA, ALTURA, "Movimento");//Inicializa janela, com certo tamanho e título
    SetTargetFPS(60);
    int posX = 400;
    int posY = 400;
    int obstaculos[TAMANHO_MATRIZ][TAMANHO_MATRIZ] = {};
    preencheMatriz(obstaculos);
    while (!WindowShouldClose())
    {
        if (IsKeyPressed(KEY_RIGHT)) posX += PASSO;
        if (IsKeyPressed(KEY_LEFT)) posX -= PASSO;
        if (IsKeyPressed(KEY_UP)) posY -= PASSO;
        if (IsKeyPressed(KEY_DOWN)) posY += PASSO;

        if (posX < 0 || posX >= LARGURA || posY < 0 || posY >= ALTURA) break;

        BeginDrawing();
        ClearBackground(WHITE);
        DrawRectangle(posX, posY, TAMANHO_QUADRADO, TAMANHO_QUADRADO, PURPLE);
        desenhaCampo(obstaculos);
        EndDrawing();
    }
    CloseWindow();// Fecha a janela e o contexto OpenGL
    return 0;
}

void preencheMatriz(int matriz[TAMANHO_MATRIZ][TAMANHO_MATRIZ]){
    for (int i = 0; i < TAMANHO_MATRIZ; i++){
        for (int j = 0; j < TAMANHO_MATRIZ; j++){
                matriz[i][j] = rand() % 10;
        }
    }
}

void desenhaCampo(int matriz[TAMANHO_MATRIZ][TAMANHO_MATRIZ]) {
    for (int i = 0; i < TAMANHO_MATRIZ; i++) {
        for (int j = 0; j < TAMANHO_MATRIZ; j++) {
            if (matriz[i][j] == 1)
                DrawRectangle(j * TAMANHO_QUADRADO, i * TAMANHO_QUADRADO, TAMANHO_QUADRADO, TAMANHO_QUADRADO, BLACK);
          }
       }
    }
