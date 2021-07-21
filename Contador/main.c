#include <locale.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct dado {
  int dado;
  bool percorrido;
};

int main(void) {

  setlocale(LC_ALL, "Portuguese");
  //   srand(time(NULL));

  struct dado matriz[7][7];

  int sum=0;
  int a, b;
  int acumulador = 0;

  printf("\n------matriz aleatória-------\n\n\n");
  for (int x = 0; x < 7; x++) {
    for (int y = 0; y < 7; y++) {
      printf(" %d ", matriz[x][y].dado = rand() % 99);
      matriz[x][y].percorrido = 0;
    }
    printf("\n");
  }

  printf("\n\n\n");

  int x = 0;
  int y = 0;

  bool path;
  int dpath = matriz[0][0].dado;
  printf("%d->", dpath);
  while (1) {

    if (x == 6 || y == 6) {
      break;
    }
    path = false;
    if (x == 6 || y == 6 && x == 6) {
      break;
    }

    // Direita
    if (matriz[x][y + 1].percorrido == false && path == false) {
      if (y != 0 && matriz[x][y + 1].dado >= matriz[x][y - 1].dado) {
        dpath = matriz[x][y + 1].dado;
        matriz[x][y + 1].percorrido = true;
        path = true;
        y++;
        sum += matriz[x][y + 1].dado;
      }
      if (path == false && y < 7 &&
          matriz[x][y + 1].dado >= matriz[x + 1][y].dado) {
        dpath = matriz[x][y + 1].dado;
        matriz[x][y + 1].percorrido = true;
        path = true;
        y++;
        sum += matriz[x][y + 1].dado;
      }
    }
    // Baixo
    if (matriz[x + 1][y].percorrido == false && path == false) {
      if (matriz[x + 1][y].dado >= matriz[x][y + 1].dado) {
        dpath = matriz[x + 1][y].dado;
        matriz[x + 1][y].percorrido = true;
        path = true;
        x++;
        sum += matriz[x + 1][y].dado;
      }
      if (path == false && y != 0 &&
          matriz[x + 1][y].dado >= matriz[x][y - 1].dado) {
        dpath = matriz[x + 1][y].dado;
        matriz[x + 1][y].percorrido = true;
        path = true;
        x++;
        sum += matriz[x + 1][y].dado;
      }
    }
    // Esquerda
    if (y != 0 && matriz[x][y - 1].percorrido == false && path == false) {
      if (matriz[x][y - 1].dado >= matriz[x][y + 1].dado) {
        dpath = matriz[x][y - 1].dado;
        matriz[x][y - 1].percorrido = true;
        path = true;
        y--;
        sum += matriz[x][y - 1].dado;
      }
      if (path == false && matriz[x][y - 1].dado >= matriz[x + 1][y].dado) {
        dpath = matriz[x][y - 1].dado;
        matriz[x][y - 1].percorrido = true;
        path = true;
        y--;
        sum += matriz[x][y - 1].dado;
      }
    }
    printf("%d-> ", dpath);
  }
  printf("\nConta total: %d\n\n",sum);
}
