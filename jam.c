#include "boolean.h"
#include <stdio.h>
#include "jam.h"
/* 
***************************************************************** */
/* DEFINISI PRIMITIF                                                 */
/* ***************************************************************** */
/* KELOMPOK VALIDASI TERHADAP TYPE                                   */
/* ***************************************************************** */
boolean IsJAMValid (int H, int M, int S)
{
  return((H>=0 && H<=23)&&(M>=0 && M<=59)&&(S>=0 && S<=59));
}
/* Mengirim true  jika H,M,S dapat membentuk J yang valid */
/* dipakai untuk mentest SEBELUM membentuk sebuah Jam */

/* *** Konstruktor: Membentuk sebuah JAM dari komponen-komponennya *** */
JAM MakeJAM (int H, int M, int S)
{
  JAM J;
  J.HH = H;
  J.MM = M;
  J.SS = S;
  return MakeJAM(H,M,S);
}
/* Membentuk sebuah JAM dari komponen-komponennya yang valid */
/* Prekondisi : HH, MM, SS valid untuk membentuk JAM */

/* ***************************************************************** */
/* KELOMPOK BACA/TULIS                                               */
/* ***************************************************************** */
void BacaJAM (JAM * J)
{
  int H,M,S;
  do {
    printf("Masukkan jam : "); scanf("%d",&H);
    printf("Masukkan menit : "); scanf("%d",&M);
    printf("Masukkan detik : "); scanf("%d",&S);
  } while (!IsJAMValid(H,M,S));
  (*J).HH = H;
  (*J).MM = M;
  (*J).SS = S;
}
/* I.S. : J tidak terdefinisi */
/* F.S. : J terdefinisi dan merupakan jam yang valid */
/* Proses : mengulangi membaca komponen HH, MM, SS sehingga membentuk J */
/* yang valid. Tidak mungkin menghasilkan J yang tidak valid. */
/* Pembacaan dilakukan dengan mengetikkan komponen HH, MM, SS
   dalam satu baris, masing-masing dipisahkan 1 spasi, diakhiri enter. */
/* Jika JAM tidak valid maka diberikan pesan: "Jam tidak valid", dan pembacaan
   diulangi hingga didapatkan jam yang valid. */
/* Contoh:
   60 3 4
   Jam tidak valid
   1 3 4
   --> akan terbentuk JAM <1,3,4> */

void TulisJAM (JAM J)
{
  printf("Jam: %d:%d:%d",J.HH,J.MM,J.SS);
}
/* I.S. : J sembarang */
/* F.S. :   Nilai J ditulis dg format HH:MM:SS */
/* Proses : menulis nilai setiap komponen J ke layar dalam format HH:MM:SS
   tanpa karakter apa pun di depan atau belakangnya, termasuk spasi, enter, dll.
   Jika jam / menit / detik hanya satu digit, tuliskan satu digit tanpa 0 di depannya. */

/* ***************************************************************** */
/* KELOMPOK KONVERSI TERHADAP TYPE                                   */
/* ***************************************************************** */
long JAMToDetik (JAM J)
{
  int N;
  N =3600*J.HH + 60*J.MM + J.SS;
  return N;
}
/* Diberikan sebuah JAM, mengkonversi menjadi jumlah detik dari pukul 0:0:0 */
/* Rumus : detik = 3600*HH + 60*MM + SS */
/* Nilai maksimum = 3600*23+59*60+59 */

JAM DetikToJAM (long N)
{
  int sisa;
  JAM JOut;
  N = N%86400;
  Hour(JOut) = N/3600;
  sisa = N%3600;
  Minute(JOut)=sisa/60;
  Second(JOut)=sisa%60;
  return JOut;
}
/* Mengirim  konversi detik ke JAM */
/* Catatan: Jika N >= 86400, maka harus dikonversi dulu menjadi jumlah detik yang
   mewakili jumlah detik yang mungkin dalam 1 hari, yaitu dengan rumus:
   N1 = N mod 86400, baru N1 dikonversi menjadi JAM */

/* ***************************************************************** */
/* KELOMPOK OPERASI TERHADAP TYPE                                    */
/* ***************************************************************** */
/* *** Kelompok Operator Relational *** */
boolean JEQ (JAM J1, JAM J2)
{
  return((J1.HH==J2.HH)&&(J1.MM==J2.MM)&&(J1.SS==J2.SS));
}
/* Mengirimkan true jika J1=J2, false jika tidak */
boolean JNEQ (JAM J1, JAM J2)
{
  return((J1.HH!=J2.HH)|(J1.MM!=J2.MM)|(J1.SS!=J2.SS));
}
/* Mengirimkan true jika J1 tidak sama dengan J2 */
boolean JLT (JAM J1, JAM J2)
{
  if (J1.HH<J2.HH) return 1;
  else if ((J1.HH==J2.HH)&&(J1.MM<J2.MM)) return 1;
  else if ((J1.HH==J2.HH)&&(J1.MM<J2.MM)&&(J1.SS<J2.SS)) return 1;
  else return 0;
}
/* Mengirimkan true jika J1<J2, false jika tidak */
boolean JGT (JAM J1, JAM J2)
{
  if (J1.HH>J2.HH) return 1;
  else if ((J1.HH==J2.HH)&&(J1.MM>J2.MM)) return 1;
  else if ((J1.HH==J2.HH)&&(J1.MM>J2.MM)&&(J1.SS>J2.SS)) return 1;
  else return 0;
}
/* Mengirimkan true jika J1>J2, false jika tidak */
/* *** Operator aritmatika JAM *** */
JAM NextDetik (JAM J)
{
  J.SS++;
  printf("\n J1 Setelah NextDetik: ");
  TulisJAM(J);
  return J;
}
/* Mengirim 1 detik setelah J dalam bentuk JAM */
JAM NextNDetik (JAM J, int N)
{
  J.SS+=N;
  printf("\n J1 Setelah Next N Detik: ");
  TulisJAM(J);
  return J;
}
/* Mengirim N detik setelah J dalam bentuk JAM */
JAM PrevDetik (JAM J)
{
  J.SS--;
  printf("\n J1 Setelah PrevDetik: ");
  TulisJAM(J);
  return J;
}
/* Mengirim 1 detik sebelum J dalam bentuk JAM */
JAM PrevNDetik (JAM J, int N)
{
  J.SS-=N;
  printf("\n J1 Setelah Prev N Detik");
  TulisJAM(J);
  return J;
}
/* Mengirim N detik sebelum J dalam bentuk JAM */
/* *** Kelompok Operator Aritmetika *** */
long Durasi (JAM JAw, JAM JAkh);
/* Mengirim JAkh-JAw dlm Detik, dengan kalkulasi */
/* Jika JAw > JAkh, maka JAkh adalah 1 hari setelah JAw */
