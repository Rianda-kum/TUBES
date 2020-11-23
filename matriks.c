// Nama file : matriks.c
// Nama : Rianda Kumala Dewi
// NIM : 10119048
// Tanggal : 22 September 2020

#include "boolean.h"
#include "matriks.h"
#include <stdio.h>
#include <stdlib.h>

/* ********** DEFINISI PROTOTIPE PRIMITIF ********** */              
/* *** Konstruktor membentuk MATRIKS *** */
void MakeMATRIKS (int NB, int NK, MATRIKS * M){
  NBrsEff(*M) = NB;
  NKolEff(*M) = NK;
}
/* Membentuk sebuah MATRIKS "kosong" yang siap diisi berukuran NB x NK di "ujung kiri" memori */
/* I.S. NB dan NK adalah valid untuk memori matriks yang dibuat */
/* F.S. Matriks M sesuai dengan definisi di atas terbentuk */

/* *** Selektor *** */
#define NBrsEff(M) (M).NBrsEff
#define NKolEff(M) (M).NKolEff
#define Elmt(M,i,j) (M).Mem[(i)][(j)]

/* *** Selektor "DUNIA MATRIKS" *** */
boolean IsIdxValid (int i, int j){
  return ((i>=BrsMin)&&(i<=BrsMax)&&(j>=KolMin)&&(j<=KolMax));
}
/* Mengirimkan true jika i, j adalah indeks yang valid untuk matriks apa pun */

/* *** Selektor: Untuk sebuah matriks M yang terdefinisi: *** */
indeks GetFirstIdxBrs (MATRIKS M){
  return BrsMin;
}
/* Mengirimkan indeks baris terkecil M */
indeks GetFirstIdxKol (MATRIKS M){
  return KolMin;
}
/* Mengirimkan indeks kolom terkecil M */
indeks GetLastIdxBrs (MATRIKS M){
  return BrsMax;
}
/* Mengirimkan indeks baris terbesar M */
indeks GetLastIdxKol (MATRIKS M){
  return KolMax;
}
/* Mengirimkan indeks kolom terbesar M */
boolean IsIdxEff (MATRIKS M, indeks i, indeks j){
  return ((i>=BrsMin)&&(i<=NBrsEff(M))&&(j>=KolMin)&&(j<=NKolEff(M)));
}
/* Mengirimkan true jika i, j adalah indeks efektif bagi M */
ElType GetElmtDiagonal (MATRIKS M, indeks i){
  return Elmt(M,i,i);
}
/* Mengirimkan elemen M(i,i) */

/* ********** Assignment  MATRIKS ********** */
void CopyMATRIKS (MATRIKS MIn, MATRIKS * MHsl){
  MakeMATRIKS(NBrsEff(MIn), NKolEff(MIn), MHsl);
  for (int i = 0;i<NBrsEff(MIn);i++){
    for(int j = 0;j<NKolEff(MIn);j++){
      Elmt(*MHsl,i,j) = Elmt(MIn,i,j);
    }
  }
}
/* Melakukan assignment MHsl  MIn */

/* ********** KELOMPOK BACA/TULIS ********** */ 
void BacaMATRIKS (MATRIKS * M, char NB, char NK){
  if (IsIdxValid(NB,NK)){
    MakeMATRIKS(NB,NK,M);
    for(int i = 0;i<NB;i++){
      for(int j = 0;j<NK;j++){
        ElType elemen;
        scanf("%c",&elemen);
        Elmt(*M,i,j) = elemen;
      }
    }
  }

}
/* I.S. IsIdxValid(NB,NK) */ 
/* F.S. M terdefinisi nilai elemen efektifnya, berukuran NB x NK */
/* Proses: Melakukan MakeMATRIKS(M,NB,NK) dan mengisi nilai efektifnya */
/* Selanjutnya membaca nilai elemen per baris dan kolom */
/* Contoh: Jika NB = 3 dan NK = 3, maka contoh cara membaca isi matriks :
1 2 3
4 5 6
8 9 10 
*/
void TulisMATRIKS (MATRIKS M){
  for (int i = 0;i<NBrsEff(M);i++){
    for (int j = 0; j<NKolEff(M);j++){
      printf("%c ", Elmt(M,i,j));
    } printf("\n");
  }
}
/* I.S. M terdefinisi */
/* F.S. Nilai M(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris 
   dipisahkan sebuah spasi */
/* Proses: Menulis nilai setiap elemen M ke layar dengan traversal per baris dan per kolom */
/* Contoh: menulis matriks 3x3 (ingat di akhir tiap baris, tidak ada spasi)
1 2 3
4 5 6
8 9 10
*/

/* ********** KELOMPOK OPERASI ARITMATIKA TERHADAP TYPE ********** */                                  
MATRIKS TambahMATRIKS (MATRIKS M1, MATRIKS M2){
  for (int i=0; i<NBrsEff(M1);i++){
    for (int j=0; j<NKolEff(M1);j++){
      Elmt(M1,i,j) += Elmt(M2,i,j);
    }
  }
  return M1;
}
/* Prekondisi : M1  berukuran sama dengan M2 */
/* Mengirim hasil penjumlahan matriks: M1 + M2 */ 
MATRIKS KurangMATRIKS (MATRIKS M1, MATRIKS M2){
  for (int i=0; i<NBrsEff(M1);i++){
    for (int j=0; j<NKolEff(M1);j++){
      Elmt(M1,i,j) -= Elmt(M2,i,j);
    }
  }
  return M2;
}
/* Prekondisi : M berukuran sama dengan M */
/* Mengirim hasil pengurangan matriks: salinan M1 – M2 */ 
MATRIKS KaliMATRIKS (MATRIKS M1, MATRIKS M2){
  MATRIKS M3;
  MakeMATRIKS(NBrsEff(M1), NKolEff(M2), &M3);
  for (int i=0; i<NBrsEff(M1);i++){
    for (int j=0; j<NKolEff(M2);j++){
      for (int k=0; k<NBrsEff(M2);k++){
        Elmt(M3,i,j) += Elmt(M1,i,k)*Elmt(M2,k,j);
      }
    }
  }
  return M3;
}
/* Prekondisi : Ukuran kolom efektif M1 = ukuran baris efektif M2 */
/* Mengirim hasil perkalian matriks: salinan M1 * M2 */
MATRIKS KaliKons (MATRIKS M, ElType X){
  for (int i=0; i<NBrsEff(M);i++){
    for (int j=0; j<NKolEff(M);j++){
      Elmt(M,i,j) = Elmt(M,i,j)*X;
    }
  }
  return M;
}
/* Mengirim hasil perkalian setiap elemen M dengan X */
void PKaliKons (MATRIKS * M, ElType K){
  for (int i=0; i<NBrsEff(*M);i++){
    for (int j=0; j<NKolEff(*M);j++){
      Elmt(*M,i,j) = Elmt(*M,i,j)*K;
    }
  }
}
/* I.S. M terdefinisi, K terdefinisi */
/* F.S. Mengalikan setiap elemen M dengan K */

/* ********** KELOMPOK OPERASI RELASIONAL TERHADAP MATRIKS ********** */
boolean equal (MATRIKS M1, MATRIKS M2){
  if ((NBrsEff(M1)!=NBrsEff(M2))||(NKolEff(M1))!=NKolEff(M2)){
    return false;
  }
  for (int i=0;i<NBrsEff(M1);i++){
    for (int j=0;j<NKolEff(M1);j++){
      if (Elmt(M1,i,j)!=Elmt(M2,i,j)){
        return false;
      }
    }
  }
  return true;
}
/* Mengirimkan true jika M1 = M2, yaitu NBElmt(M1) = NBElmt(M2) dan */
/* untuk setiap i,j yang merupakan indeks baris dan kolom M1(i,j) = M2(i,j) */
/* Juga merupakan strong EQ karena GetFirstIdxBrs(M1) = GetFirstIdxBrs(M2) 
   dan GetLastIdxKol(M1) = GetLastIdxKol(M2) */
boolean Nequal (MATRIKS M1, MATRIKS M2){
  if ((NBrsEff(M1)!=NBrsEff(M2))||(NKolEff(M1))!=NKolEff(M2)){
    return true;
  }
  for (int i=0;i<NBrsEff(M1);i++){
    for (int j=0;j<NKolEff(M1);j++){
      if (Elmt(M1,i,j)!=Elmt(M2,i,j)){
        return true;
      }
    }
  }
  return false;
}
/* Mengirimkan true jika M1 tidak sama dengan M2 */
boolean EQSize (MATRIKS M1, MATRIKS M2){
  return ((NBrsEff(M1)==NBrsEff(M2)) && (NKolEff(M1)==NKolEff(M2)));
}
/* Mengirimkan true jika ukuran efektif matriks M1 sama dengan ukuran efektif M2 */
/* yaitu GetBrsEff(M1) = GetNBrsEff (M2) dan GetNKolEff (M1) = GetNKolEff (M2) */

/* ********** Operasi lain ********** */
int NBElmt (MATRIKS M){
  return (NBrsEff(M)*NKolEff(M));
}
/* Mengirimkan banyaknya elemen M */

/* ********** KELOMPOK TEST TERHADAP MATRIKS ********** */
boolean IsBujurSangkar (MATRIKS M){
  return (NBrsEff(M)==NKolEff(M));
}
/* Mengirimkan true jika M adalah matriks dg ukuran baris dan kolom sama */
boolean IsSimetri (MATRIKS M){
  if (!IsBujurSangkar(M)){
    return false;
  }
  for (int i=0; i<NBrsEff(M);i++){
    for (int j=0; j<NKolEff(M);j++){
      if (Elmt(M,i,j)!=Elmt(M,j,i)){
        return false;
      }
    }
  }
  return true;
}
/* Mengirimkan true jika M adalah matriks simetri : IsBujurSangkar(M) 
   dan untuk setiap elemen M, M(i,j)=M(j,i) */
boolean IsSatuan (MATRIKS M){
  if (!IsBujurSangkar(M)){
    return false;
  }
  for (int i=0; i<NBrsEff(M);i++){
    for (int j=0; i<NKolEff(M);j++){
      if (i==j){
        if (Elmt(M,i,i)!=1){
          return false;
        }
      } else {
        if (Elmt(M,i,j != 0)){
          return false;
        }
      }
    }
  }
  return true;
}
/* Mengirimkan true jika M adalah matriks satuan: IsBujurSangkar(M) dan 
   setiap elemen diagonal M bernilai 1 dan elemen yang bukan diagonal bernilai 0 */ 
boolean IsSparse (MATRIKS M){
  int count=0;
  for (int i=0; i<NBrsEff(M);i++){
    for (int j=0; j<NKolEff(M);j++){
      if (Elmt(M,i,j)!=0){
        count += 1;
      }
    }
  }
  return (count <= 0.05*NBrsEff(M)*NKolEff(M));
}
/* Mengirimkan true jika M adalah matriks sparse: mariks “jarang” dengan definisi: 
   hanya maksimal 5% dari memori matriks yang efektif bukan bernilai 0 */ 
MATRIKS Inverse1 (MATRIKS M){
  for (int i=0;i<NBrsEff(M);i++){
    for (int j=0;j<NKolEff(M);j++){
      Elmt(M,i,j) = -1*Elmt(M,i,j);
    }
  }
  return (M);
}
/* Menghasilkan salinan M dengan setiap elemen "di-invers", yaitu dinegasikan (dikalikan -1) */
float Determinan (MATRIKS M){
  int Minor[100][100];
  int c1,c2,n;
  int det = 0;
  int c[100];
  int O=1;

  if(n == 2){
    det = Elmt(M,0,0)*Elmt(M,1,1)-Elmt(M,0,1)*Elmt(M,1,0);
    return det;
  } else {
    for(int i = 0 ; i < n ; i++) {
      c1 = 0, c2 = 0;
      for(int j = 0 ; j < n ; j++) {
        for(int k = 0 ; k < n ; k++) {
          if(j != 0 && k != i) {
            Minor[c1][c2] = Elmt(M,j,k);
            c2++;
            if(c2>n-2) {
              c1++;
              c2=0;
            }
          }
        }
      }
      det = det + O*Elmt(M,0,i)*det;
      O=-1*O;
    }
  }
  return det;
}
/* Prekondisi: IsBujurSangkar(M) */
/* Menghitung nilai determinan M */
void PInverse1 (MATRIKS * M){
  for (int i=0;i<NBrsEff(*M);i++){
    for (int j=0;j<NKolEff(*M);j++){
      Elmt(*M,i,j) = -1*Elmt(*M,i,j);
    }
  }
}
/* I.S. M terdefinisi */
/* F.S. M di-invers, yaitu setiap elemennya dinegasikan (dikalikan -1) */
void Transpose (MATRIKS * M){
	for(int i = GetFirstIdxBrs(*M); i <= GetLastIdxBrs(*M); i++){
		for(int j = i+1; j <= GetLastIdxKol(*M); j++){
			int temp;
      temp = Elmt(*M,i,j);
      Elmt(*M,i,j) = Elmt(*M,j,i);
      Elmt(*M,j,i) = temp;
		}
	}
}
/* I.S. M terdefinisi dan IsBujursangkar(M) */
/* F.S. M "di-transpose", yaitu setiap elemen M(i,j) ditukar nilainya dengan elemen M(j,i) */