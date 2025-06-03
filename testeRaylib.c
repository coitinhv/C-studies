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
    InitWindow(LARGURA, ALTURA, "Movimento");
    SetTargetFPS(60);
    int posX = 798;
    int posY = 798;
    int obstaculos[TAMANHO_MATRIZ][TAMANHO_MATRIZ] = {};
    preencheMatriz(obstaculos);
    while (!WindowShouldClose())
    {
        int novaPosX = posX;
        int novaPosY = posY;

        if (IsKeyPressed(KEY_RIGHT)) novaPosX += PASSO;
        if (IsKeyPressed(KEY_LEFT)) novaPosX -= PASSO;
        if (IsKeyPressed(KEY_UP)) novaPosY -= PASSO;
        if (IsKeyPressed(KEY_DOWN)) novaPosY += PASSO;

        int novoI = novaPosY / TAMANHO_QUADRADO;
        int novoJ = novaPosX / TAMANHO_QUADRADO;

        if (obstaculos[novoI][novoJ] != 1){
            posX = novaPosX;
            posY = novaPosY;
        }

        if (novaPosX < 0 || novaPosX >= LARGURA || novaPosY < 0 || novaPosY >= ALTURA) break;

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
