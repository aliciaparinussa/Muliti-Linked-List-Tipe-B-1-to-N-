#ifndef TEAM_H_INCLUDED
#define TEAM_H_INCLUDED
#include <iostream>
#include "anggota.h"

using namespace std;

#define first(L) L.first
#define next(P) P->next
#define info(P) P->info
#define child(P) P->child
#define nil NULL

struct infotype_team {
    string idTeam;
    string namaTeam;
};

typedef struct elmTeam *adrTeam;

struct elmTeam {
    infotype_team info;
    adrTeam next;
    List_Anggota child;
};

struct List_Team {
    adrTeam first;
};

void createListTeam(List_Team &L);
adrTeam alokasiTeam(string x, string y);
void insertFirstTeam(List_Team &L, adrTeam P);
void insertLastTeam(List_Team &L, adrTeam P);
void deleteFirstTeam(List_Team &L, adrTeam &P);
void deleteLastTeam(List_Team &L, adrTeam &P);
void deleteAfterTeam(List_Team &L, adrTeam Prec, adrTeam &P);

adrTeam findTeambyID(List_Team L, string ID);
void countAllAnggota(List_Team L);
void countMinAnggota(List_Team L);
void countMaxAnggota(List_Team L);
void printInfoTeam(List_Team L);
int selectmenu();

#endif // TEAM_H_INCLUDE
