#include <stdio.h>
#include "boolean.h"
#include "mesinkar.h"
#include "mesinkata.h"

boolean EndKata;
Kata CKata;

void IgnoreBlank(){
  while (CC == BLANK) {
    ADV();
  }
}
/* Mengabaikan satu atau beberapa BLANK
   I.S. : CC sembarang
   F.S. : CC != BLANK atau CC = MARK */
void STARTKATA(){
  START();
  IgnoreBlank();
  if (CC == MARK) {
    EndKata = true;
  } else {
    EndKata = false;
    SalinKata();
  }
}
/* I.S.: CC sembarang
   F.S.: EndKata = true, dan CC = Mark;
      atau EndKata = false,
      CKata adalah kata yang sudah diakuisisi,
      CC karakter pertama sesudah karakter terakhir kata */
void ADVKATA(){
  IgnoreBlank();
  if (CC == MARK) {
    EndKata = true;
  } else {
    SalinKata();
  }
}
/* I.S.: CC adalah karakter pertama kata yang akan diakuisisi
F.S.: CKata adalah kata terakhir yang sudah diakuisisi,
CC adalah karakter pertama dari kata berikutnya, mungkin MARK
Proses: Akuisisi kata menggunakan procedure SalinKata */
void SalinKata(){
  int i = 0;
  while ((CC != MARK) && (CC != BLANK)) {
    CKata.TabKata[i] = CC;
    ADV();
    i++;
  }
  CKata.Length = i;
}
/* Mengakuisisi kata, menyimpan dalam CKata
I.S.: CC adalah karakter pertama dari kata
F.S.: CKata berisi kata yang sudah diakuisisi;
CC = BLANK atau CC = MARK;
CC adalah karakter sesudah karakter terakhir yang diakuisisi */