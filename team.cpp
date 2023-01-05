#include "team.h"
#include "anggota.h"
#include <climits>

void createListTeam(List_Team &L) { first(L) = nil; }

adrTeam alokasiTeam(string ID, string nama) {
  adrTeam P;
  P = new elmTeam;
  infotype_team Q;
  Q.idTeam = ID;
  Q.namaTeam = nama;
  info(P) = Q;
  next(P) = nil;
  createAnggota(child(P));
  return P;
}

void insertFirstTeam(List_Team &L, adrTeam P) {
  if (first(L) == nil) {
    first(L) = P;
  } else {
    next(P) = first(L);
    first(L) = P;
  }
}

void insertLastTeam(List_Team &L, adrTeam P) {
  adrTeam Q = first(L);
  if (first(L) == nil) {
    insertFirstTeam(L, P);
  } else {
    while (next(Q) != nil) {
      Q = next(Q);
      next(Q) = P;
    }
  }
}

void insertAfterTeam(List_Team &L, adrTeam Prec, adrTeam P) {
  adrTeam Q = first(L);
  if (first(L) == nil) {
    insertFirstTeam(L, P);
  } else {
    while (Q != Prec) {
      Q = next(Q);
    }
    next(P) = next(Prec);
    next(Prec) = P;
  }
}

void deleteFirstTeam(List_Team &L, adrTeam &P) {
  if (first(L) == nil) {
    cout << "List Team Tidak Tersedia";
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

void deleteLastTeam(List_Team &L, adrTeam &P) {
  if (first(L) == nil) {
    cout << "List Team Tidak Tersedia";
  } else {
    adrTeam Q = first(L);
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

void deleteAfterTeam(List_Team &L, adrTeam Prec, adrTeam &P) {
  if (Prec == nil) {
    cout << "List Team Tidak Tersedia";
  } else if (next(Prec) == nil) {
    // Elemen Prec adalah elemen terakhir dalam list, tidak ada elemen
    // setelahnya
  } else {
    P = next(Prec);
    next(Prec) = next(P);
    next(P) = nil;
  }
}

adrTeam findTeambyID(List_Team L, string ID) {
  adrTeam P, findT;
  P = new elmTeam;
  infotype_team Q;
  Q.idTeam = ID;
  info(P) = Q;
  if (first(L) == nil) {
    cout << "List Team Tidak Tersedia" << endl;
    return nil;
  } else {
    findT = first(L);
    while (findT != nil) {
      if (info(findT).idTeam == ID) {
        return findT;
      }
      findT = next(findT);
    }
    return nil;
  }
}

void countAllAnggota(List_Team L) {
  adrTeam P;
  adranggota C;
  int count, temp;
  count = 0;
  if (first(L) == nil) {
    cout << "List Team Tidak Tersedia" << endl;
  } else {
    P = first(L);
    while (P != nil) {
      if (P != nil) {
        C = first(child(P));
        temp = 0;
        while (C != nil) {
          temp++;
          C = next(C);
        }
        count += temp;
      }
      P = next(P);
    }
    cout << "Jumlah anggota di semua tim: " << count << endl;
  }
}

void countMinAnggota(List_Team L) {
  int minAnggota = INT_MAX;
  string namaTim = "";
  adrTeam currentTeam = first(L);
  while (currentTeam != nil) {
    int count = 0;
    adranggota currentAnggota = first(child(currentTeam));
    while (currentAnggota != nil) {
      count++;
      currentAnggota = next(currentAnggota);
    }

    if (count < minAnggota) {
      minAnggota = count;
      namaTim = info(currentTeam).namaTeam;
    }

    currentTeam = next(currentTeam);
  }
  cout << "Tim dengan jumlah anggota paling sedikit: " << namaTim << endl;
  cout << "Dengan jumlah anggota: " << minAnggota << endl;
}

void countMaxAnggota(List_Team L) {
  int maxAnggota = 0;
  string namaTim = "";
  adrTeam currentTeam = first(L);
  while (currentTeam != nil) {
    int count = 0;
    adranggota currentAnggota = first(child(currentTeam));
    while (currentAnggota != nil) {
      count++;
      currentAnggota = next(currentAnggota);
    }

    if (count > maxAnggota) {
      maxAnggota = count;
      namaTim = info(currentTeam).namaTeam;
    }

    currentTeam = next(currentTeam);
  }
  cout << "Tim dengan jumlah anggota paling banyak: " << namaTim << endl;
  cout << "Dengan jumlah anggota: " << maxAnggota << endl;
}

void printInfoTeam(List_Team L) {
  if (first(L) == nil) {
    cout << "List Team Tidak Tersedia" << endl;
  } else {
    adrTeam P = first(L);
    cout << "------------------List Team------------------" << endl;
    while (P != nil) {
      cout << "ID Team      :" << info(P).idTeam << endl;
      cout << "Nama Team    :" << info(P).namaTeam << endl;
      printInfoAnggota(child(P));
      P = next(P);
      cout << endl;
    }
    cout << "----------------End List Team----------------" << endl;
  }
}

int selectmenu() {
  cout << "1. Menambah data pada parent dan child" << endl;
  cout << "2. Mencari data pada parent dan child" << endl;
  cout << "3. Menampilkan data pada parent dan child" << endl;
  cout << "4. Menambah data pada parent dan child" << endl;
  cout << "5. Menghapus data (parent) beserta relasinya (child nya)" << endl;
  cout << "6. Menghitung jumlah data pada parent dan child nya" << endl;
  cout << "7. Menampilkan jumlah data paling banyak" << endl;
  cout << "8. Menampikan jumlah data paling sedikit" << endl;
  cout << "0. Keluar Program" << endl;

  cout << "Pilih Menu : ";

  int input = 0;
  cin >> input;
  return input;
}
