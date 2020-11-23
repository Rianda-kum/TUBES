#include <stdio.h>
#include <stdlib.h>
#include "boolean.h"
#include "jam.h"
#include "point.h"
#include "matriks.h"
#include "mesinkar.h"
#include "mesinkata.h"
#include "stackt.h"

typedef struct{
  char* Player;
  float Uang;
  POINT Posisi;
  JAM Current_time;
  JAM Build_time;
} Game;

void BacaKata(Kata *X){
  int i = 0;
	(*X).Length = 0;
	while ((X->TabKata[i]!='\n')&&(i<5)) {
		scanf("%c", &X->TabKata[i] );
		(*X).Length = (*X).Length + 1;
    i = i+1;
	}
}

boolean IsKataSama(Kata K1, Kata K2){
  boolean result = (K1.Length == K2.Length);
  if (result){
    int i;
    for (i=0; i < K1.Length; i++){
      result = (result && (K1.TabKata[i] == K2.TabKata[i]));
    }
  }
  return result;
}

Kata w, s, a, d;

//Command untuk gerak (wasd)
void gerak(){
  Kata w;
  w.TabKata[0] = 'w';
  w.TabKata[1] = '\n';
  Kata a;
  a.TabKata[0] = 'a';
  a.TabKata[1] = '\n';
  Kata s;
  s.TabKata[0] = 's';
  s.TabKata[1] = '\n';
  Kata d;
  d.TabKata[0] = 'd';
  d.TabKata[1] = '\n';
}

Kata newgame;
Kata quit;

void game(){  
  //Command untuk new game
  Kata newgame;
  newgame.TabKata[0] = 'n';
  newgame.TabKata[1] = 'e';
  newgame.TabKata[2] = 'w';
  newgame.TabKata[3] = '\n';
  newgame.Length = 4;
  //Command untuk quit (q)
  Kata quit;
  quit.TabKata[0] = 'q';
  quit.TabKata[1] = 'u';
  quit.TabKata[2] = 'i';
  quit.TabKata[3] = 't';
  quit.TabKata[4] = '\n';
  quit.Length = 5;
}

Kata build, upgrade, buy, undo, execute, keluar;

void pilihan(){  

  Kata build;
  build.TabKata[0] = 'b';
  build.TabKata[1] = 'u';
  build.TabKata[2] = 'i';
  build.TabKata[3] = 'l';
  build.TabKata[4] = 'd';
  build.TabKata[5] = '\n';
  build.Length = 6;

  Kata upgrade;
  upgrade.TabKata[0] = 'u';
  upgrade.TabKata[1] = 'p';
  upgrade.TabKata[2] = 'g';
  upgrade.TabKata[3] = 'r';
  upgrade.TabKata[4] = 'a';
  upgrade.TabKata[5] = 'd';
  upgrade.TabKata[6] = 'e';
  upgrade.TabKata[7] = '\n';
  upgrade.Length = 8;
  
  Kata buy;
  buy.TabKata[0] = 'b';
  buy.TabKata[1] = 'u';
  buy.TabKata[2] = 'y';
  buy.TabKata[3] = '\n';
  buy.Length = 4;

  Kata undo;
  undo.TabKata[0] = 'u';
  undo.TabKata[1] = 'n';
  undo.TabKata[2] = 'd';
  undo.TabKata[3] = 'o';
  undo.TabKata[4] = '\n';
  undo.Length = 5;

  Kata execute;
  execute.TabKata[0] = 'e';
  execute.TabKata[1] = 'x';
  execute.TabKata[2] = 'e';
  execute.TabKata[3] = 'c';
  execute.TabKata[4] = 'u';
  execute.TabKata[5] = 't';
  execute.TabKata[6] = 'e';
  execute.TabKata[7] = '\n';
  execute.Length = 8;

  Kata keluar;
  keluar.TabKata[0] = 'm';
  keluar.TabKata[1] = 'a';
  keluar.TabKata[2] = 'i';
  keluar.TabKata[3] = 'n';
  keluar.TabKata[4] = '\n';
  build.Length = 5;
}

int main() {
  // MAIN MENU
  printf("Welcome to Willy Wangky's fun factory!!\n");
  printf("New game / exit?\n");
  Kata input;
  game();
  BacaKata(&input);
  if(IsKataSama(input, newgame)){
    printf("Memulai permainan baru\n");
    printf("Masukan nama:\n");
    
    // PREPARATION PHASE
    /*Stack S;
    infotype X;
    BacaKata(&input);
    while (!(IsKataSama(input,keluar))){
      if(IsKataSama(input,build)){
        // Build
        FILE *fp1;
        fp1 = fopen("wahana.txt", "w+");
        fclose(fp1);
        // masukin yang udah di build dalam array
      } else if(IsKataSama(input,upgrade)){
        // Upgrade
        
      } else if(IsKataSama(input,buy)){
        // Buy
        FILE *fp2;
        fp2 = fopen("material.txt", "");
      } else if(IsKataSama(input,undo)){
        // Undo
        Pop(&S,&X);
      } else {
        // Execute
      }
    }
    // MAIN PHASE
    // Serve
    // Repair
    // Office
    // Detail
    // Prepare
    */
  } else {
    printf("Thanks for playing!!!");
  }
  return 0;
}