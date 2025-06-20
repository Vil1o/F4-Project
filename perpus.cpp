#include <iostream>
#include <string>
using namespace std;


struct buku{
    int id;
    string judul;
    string penulis;
    int tahun;
    bool tersedia;
    buku *next;
};
buku *headBook = nullptr;

void manajemenBuku();
void menuUtama(){
    int pilihan;
    do{
        cout<<"+========================================+"<<endl;
        cout<<"\n    SISTEM PERPUSTAKAAN    "<<endl;
        cout<<"+========================================+"<<endl;
        cout<<""<<endl;

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
                manajemenBuku();
                system ("cls");
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

void manajemenBuku(){

    int pilihan;

    do{
        cout<<"+========================================+"<<endl;
        cout<<"\n    MENU MANAJEMEN BUKU     "<<endl;
        cout<<"+========================================+"<<endl;
        cout<<""<<endl;

        cout<<"1. Tambah Buku"<<endl;
        cout<<"2. Tampilkan Daftar Buku"<<endl;
        cout<<"3. Hapus Buku"<<endl;
        cout<<"4. Kembali ke menu Utama"<<endl;
        cout<<"Pilih: ";
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
                cout<<"Kembali ke menu Utama"<<endl;
                break;

            default:
                cout<<"Pilihan tidak valid";

        }

    }while(pilihan!=4);

}