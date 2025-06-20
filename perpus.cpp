#include <iostream>
#include <string>
using namespace std;

void menuUtama ()
{
int pilihan;
    do{
        cout<<"+========================================+"<<endl;
        cout<<"\n    SISTEM PERPUSTAKAAN    "<<endl;
        cout<<"+========================================+"<<endl;
        cout<<"1. Manajemen Buku"<<endl;
        cout<<"2. Manajemen Anggota"<<endl;
        cout<<"3. Pinjam Buku"<<endl;
        cout<<"4. Kembalikan Buku"<<endl;
        cout<<"5. Riwayat Peminjaman"<<endl;
        cout<<"6. Keluar"<<endl;
        cout<<"Pilih menu: ";
        cin>>pilihan;
        
        system("cls");
        switch(pilihan){
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
        }
    }while(pilihan != 6);
}