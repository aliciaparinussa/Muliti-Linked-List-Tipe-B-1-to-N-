#include "anggota.h"

void createAnggota(List_Anggota &L) {
    first(L) = nil;
}

adranggota alokasiAnggota(string id, string nama, int umur, string asal) {
    adranggota P;
    P = new elmtAnggota;
    infotype_anggota Q;
    Q.id_anggota = id;
    Q.nama = nama;
    Q.umur = umur;
    Q.asal = asal;
    info(P) = Q;
    next(P) = nil;
    return P;
}

void insertFirstAnggota(List_Anggota &L, adranggota P) {
    if(first(L) == nil) {
        first(L) = P;
        next(P) = nil;
    } else {
        next(P) = first(L);
        first(L) = P;
    }
}

void insertLastAnggota(List_Anggota &L, adranggota P) {
    if(first(L) == nil) {
        insertFirstAnggota(L,P);
    } else {
        adranggota Q = first(L);
        while(next(Q) != nil) {
            Q = next(Q);
        }
        next(Q) = P;
        next(P) = nil;
    }
}

void insertAfterAnggota(List_Anggota &L, adranggota Prec, adranggota P) {
    if(first(L) == nil) {
        insertFirstAnggota(L,P);
    } else {
        adranggota Q = first(L);
        while(Q != Prec) {
            Q = next(Q);
        }
        next(P) = next(Prec);
        next(Prec) = P;
    }
}

void deleteFirstAnggota(List_Anggota &L, adranggota &P) {
    if (first(L) == nil) {
        cout << "List Anggota Tidak Tersedia";
  } else {
    P = first(L);
    if (next(first(L)) == nil) {
      // Jika list hanya memiliki satu elemen
      first(L) = nil;
    } else {
      // Jika list memiliki lebih dari satu elemen
      first(L) = next(P);
      next(P) = nil;
    }
  }
}

void deleteLastAnggota(List_Anggota &L, adranggota &P) {
    if (first(L) == nil) {
        cout << "List Anggota Tidak Tersedia";
  } else {
    adranggota Q = first(L);
    if (next(Q) == nil) {
      // Jika list hanya memiliki satu elemen
      P = Q;
      first(L) = nil;
    } else {
      // Jika list memiliki lebih dari satu elemen
      while (next(next(Q)) != nil) {
        Q = next(Q);
      }
      P = next(Q);
      next(Q) = nil;
    }
  }
}

void deleteAfterAnggota(List_Anggota &L, adranggota Prec, adranggota &P) {
    if (Prec == nil) {
    cout << "List Anggota Tidak Tersedia";
  } else if (next(Prec) == nil) {
    // Elemen Prec adalah elemen terakhir dalam list, tidak ada elemen setelahnya
  } else {
    P = next(Prec);
    next(Prec) = next(P);
    next(P) = nil;
  }
}

adranggota findAnggota(List_Anggota L, infotype_anggota x) {
    adranggota findA;
    if(first(L) == nil) {
        cout << "List Anggota Tidak Tersedia" << endl;
        return nil;
    } else {
        findA = first(L);
        while(findA != nil) {
            if(info(findA).id_anggota == x.id_anggota) {
                return findA;
            }
            findA = next(findA);
        }
        return nil;
    }
}

void printInfoAnggota(List_Anggota L) {
    if (first(L) == nil) {
    cout << "List Anggota Tidak Tersedia" << endl;
  } else {
    adranggota P = first(L);
    cout << "----------------List Anggota----------------" <<endl;
    while (P != nil) {
      cout << "ID Anggota: " << info(P).id_anggota << endl;
      cout << "Nama Anggota: " << info(P).nama << endl;
      cout << "Umur: " << info(P).umur << endl;
      cout << "Asal: " << info(P).asal << endl;
      P = next(P);
      cout<<"\n";
    }
    cout << "--------------End List Anggota--------------" << endl;
  }
}
