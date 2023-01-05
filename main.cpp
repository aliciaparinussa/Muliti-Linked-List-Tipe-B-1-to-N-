#include <iostream>
#include "team.h"
#include "anggota.h"

using namespace std;

List_Team LP;
List_Anggota LC;

int main()
{
    adrTeam P;
    adranggota C;

    createListTeam(LP);

    /*insert parent*/

    P = alokasiTeam("DBC01", "Djarum Badminton Club");
    insertFirstTeam(LP, P);
    P = alokasiTeam("JRC02", "Jaya Raya Club");
    insertFirstTeam(LP, P);
    P = alokasiTeam("SNC03", "Suryanaga Club");
    insertFirstTeam(LP, P);
    P = alokasiTeam("HJR04", "HJS Raharjo");
    insertFirstTeam(LP, P);

    printInfoTeam(LP);


    /*insert child*/
    P = findTeambyID(LP, "DBC01");
    C = alokasiAnggota("YR01", "Yarits Rengganingtyas", 16, "Jawa Tengah");
    insertFirstAnggota(child(P),C);

    P = findTeambyID(LP, "DBC01");
    C = alokasiAnggota("RB02", "Radithya Bayu", 14, "Jawa Tengah");
    insertFirstAnggota(child(P),C);

    P = findTeambyID(LP, "DBC01");
    C = alokasiAnggota("NA03", "Nazwan Abdillah", 14, "Jawa Tengah");
    insertFirstAnggota(child(P),C);

    P = findTeambyID(LP, "JRC02");
    C = alokasiAnggota("GY01", "Glen Yosua", 14, "DKI Jakarta");
    insertFirstAnggota(child(P),C);

    P = findTeambyID(LP, "HJR04");
    C = alokasiAnggota("EE01", "Erlangga Elang", 15, "Surabaya");
    insertFirstAnggota(child(P),C);

    P = findTeambyID(LP, "HJR04");
    C = alokasiAnggota("DH02", "David Hadinata", 15, "Surabaya");
    insertFirstAnggota(child(P),C);
//
    cout<<"\n";
    cout<<"\n";
    cout<<"========List parent setelah diisi child========"<<endl;
    cout<<"\n";
    printInfoTeam(LP);

    cout<<"\n";
    cout << "=============Count All Anggota=============" << endl;
    countAllAnggota(LP);

    cout<<"\n";
    cout << "=======Menampilkan anggota paling sedikit=======" << endl;
    countMinAnggota(LP);

    cout<<"\n";
    cout << "=======Menampilkan anggota paling banyak=======" << endl;
    countMaxAnggota(LP);
    return 0;
}
