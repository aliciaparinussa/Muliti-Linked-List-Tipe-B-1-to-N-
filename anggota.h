#ifndef ANGGOTA_H_INCLUDED
#define ANGGOTA_H_INCLUDED

#include <iostream>

using namespace std;
#define next(P) P->next
#define first(L) L.first
#define info(P) P->info
#define nil NULL

struct infotype_anggota {
  string id_anggota, nama, asal;
  int umur;
};

typedef struct elmtAnggota *adranggota;

struct elmtAnggota {
  infotype_anggota info;
  adranggota next;
};

struct List_Anggota {
  adranggota first;
};

void createAnggota(List_Anggota &L);
adranggota alokasiAnggota(string id, string nama, int umur, string asal);
void insertFirstAnggota(List_Anggota &L, adranggota P);
void insertLastAnggota(List_Anggota &L, adranggota P);
void insertAfterAnggota(List_Anggota &L, adranggota Prec, adranggota P);
void deleteFirstAnggota(List_Anggota &L, adranggota &P);
void deleteLastAnggota(List_Anggota &L, adranggota &P);
void deleteAfterAnggota(List_Anggota &L, adranggota Prec, adranggota &P);
adranggota findAnggota(List_Anggota L, infotype_anggota x);
void printInfoAnggota(List_Anggota L);

#endif // ANGGOTA_H_INCLUDED
