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

struct anggota{
    int id;
    string nama;
    string alamat;
    anggota *next;
};
anggota *headAnggota = nullptr;

struct peminjaman{
    int idAnggota;
    int idBuku;
    string tanggalPeminjaman;
    string tanggalKembali;
    peminjaman *next;
};
peminjaman *headPeminjaman = nullptr;

void tambahBuku(){
    buku *BukuBaru = new buku();
    cout<<"+========================================+"<<endl;
    cout<<"    TAMBAH BUKU BARU     "<<endl;
    cout<<"+========================================+"<<endl;
    cout<<"Masukkan ID buku: ";cin>>BukuBaru->id;
    cout<<"Masukkan Judul Buku: ";getline(cin >> ws, BukuBaru->judul);
    cout<<"Masukkan Penulis: ";getline(cin, BukuBaru->penulis);
    cout<<"Masukkan tahun terbit: ";cin>>BukuBaru->tahun;
    BukuBaru->tersedia = true;
    BukuBaru->next = nullptr;

    if(headBook == nullptr){
        headBook = BukuBaru;
    }else{
        buku *temp = headBook;
        while(temp->next != nullptr){
            temp = temp->next;
        }
        temp->next = BukuBaru;
    }
    cout<<"Buku baru berhasil ditambahkan"<<endl;
    
    cout << "Tekan Enter untuk kembali...";
    cin.ignore();
    cin.get();
}

void tampilBuku(){
    if(headBook == nullptr){
        cout<<"LIST BUKU KOSONG!"<<endl;
        cout<<"Silahkan tambahkan buku terlebih dahulu."<<endl;
        cout << "Tekan Enter untuk kembali...";
        cin.ignore();
        cin.get();
        system("cls");
        return;
    }

    cout<<"+========================================+"<<endl;
    cout<<"     DAFTAR BUKU     "<<endl;
    cout<<"+========================================+"<<endl;

    buku *temp = headBook;
    while(temp != nullptr){
        cout<<"ID: "<<temp->id<<endl;
        cout<<"Judul: "<<temp->judul<<endl;
        cout<<"Penulis: "<<temp->penulis<<endl;
        cout<<"Tahun: "<<temp->tahun<<endl;
        cout<<"Status: "<<(temp->tersedia ? "tersedia" : "Dipinjam")<<endl;
        cout<<"------------------------"<<temp->id<<endl;
        temp = temp->next;
    }
    cout << "Tekan Enter untuk kembali...";
    cin.ignore();
    cin.get();
    system("cls");
}

void hapusBuku(){
    int targetID;
    if(headBook == nullptr){
        cout<<"LIST BUKU KOSONG!"<<endl;
        cout<<"Silahkan tambahkan buku terlebih dahulu."<<endl;
        cout << "Tekan Enter untuk kembali...";
        cin.ignore();
        cin.get();
        system("cls");
        return;
    }

    cout<<"+========================================+"<<endl;
    cout<<"    HAPUS BUKU     "<<endl;
    cout<<"+========================================+"<<endl;

    cout<<"Masukkan ID buku yang ingin dihapus: ";cin>>targetID;
    buku *temp = headBook;
    buku *prev = nullptr;
    while(temp != nullptr && temp->id != targetID){
        prev = temp;
        temp = temp->next;
    }

    if(temp == nullptr){
        cout<<"Buku dengan ID tersebut tidak ditemukan."<<endl;
        return;
    }

    if(prev == nullptr){
        headBook = temp->next;
    }
    else
    {
        prev->next = temp->next;
    }
    delete temp;
    cout<<"Buku berhasil dihapus."<<endl;
}

void manajemenBuku(){
    int pilihan;
    do{
        cout<<"+========================================+"<<endl;
        cout<<"    MENU MANAJEMEN BUKU     "<<endl;
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
                tambahBuku();
                break;
            case 2:
                tampilBuku();
                break;
            case 3:
                hapusBuku();
                break;
            case 4:
                cout<<"Kembali ke menu Utama"<<endl;
                break;
            default:
                cout<<"Pilihan tidak valid" << endl;
        }
    }while(pilihan != 4);

}

void tambahAnggota(){
    anggota *anggotaBaru = new anggota();
    cout<<"+========================================+"<<endl;
    cout<<"    TAMBAH ANGGOTA BARU     "<<endl;
    cout<<"+========================================+"<<endl;
    cout<<"Masukkan ID anggota: ";cin>>anggotaBaru->id;
    cout<<"Masukkan nama: ";getline(cin>>ws, anggotaBaru->nama);
    cout<<"masukkan alamat: ";getline(cin, anggotaBaru->alamat);
    anggotaBaru->next = nullptr;

    if(headAnggota == nullptr){
        headAnggota = anggotaBaru;
    }else{
        anggota *temp = headAnggota;
        while(temp->next != nullptr){
            temp = temp->next;
        }
        temp->next = anggotaBaru;
    }
    cout<<"ANGGOTA BERHASIL DITAMBAHKAN!" << endl;
    cout << "Tekan Enter untuk kembali...";
    cin.get();
    system ("cls");
}

void tampilAnggota(){
    if(headAnggota == nullptr){
        cout<<"TIDAK ADA ANGGOTA !"<<endl;
        cout<<"Silahkan tambahkan anggota terlebih dahulu."<<endl;
        cout<<"Tekan Enter untuk kembali..."<< endl;
        cin.ignore();
        cin.get();
        system("cls");
        return;
    }
    
    cout<<"+========================================+"<<endl;
    cout<<"    Daftar Anggota    "<<endl;
    cout<<"+========================================+"<<endl;
    anggota *temp = headAnggota;
    while(temp != nullptr){
        cout<<"ID: "<<temp->id<<endl;
        cout<<"Nama: "<<temp->nama<<endl;
        cout<<"Alamat: "<<temp->alamat<<endl;
        cout<<"--------------------"<<temp->id<<endl;
        temp = temp->next;
    }
    cout << "Tekan Enter untuk kembali..."<< endl;
    cin.ignore();
    cin.get();
    system("cls");
}

void hapusAnggota(){
    int targetID;
    if(headAnggota == nullptr){
        cout<<"TIDAK ADA ANGGOTA !"<<endl;
        cout<<"Silahkan tambahkan anggota terlebih dahulu."<<endl;
        cout << "Tekan Enter untuk kembali..."<< endl;
        cin.ignore();
        cin.get();
        system("cls");
        return;
    }
    cout<<"+========================================+"<<endl;
    cout<<"    HAPUS ANGGOTA    "<<endl;
    cout<<"+========================================+"<<endl;
    cout<<"Masukkan ID anggota yang ingin dihapus: ";cin>>targetID;
    anggota *temp = headAnggota;
    anggota *prev = nullptr;
    while(temp != nullptr && temp->id != targetID){
        prev = temp;
        temp = temp->next;
    }
    if(headAnggota == nullptr){
        cout<<"Anggota yang dimaksud tidak ada!";
        return;
    }
    if(prev == nullptr){
        headAnggota = temp->next;
    }else{
        prev->next = temp->next;
    }
    delete temp;
    cout<<"Anggota telah dihapus."<<endl;
    cout << "Tekan Enter untuk kembali..."<< endl;
    cin.ignore();
    cin.get();
    system("cls");
}

void manajemenAnggota(){
    int pilihan;
    do {
        cout << "+========================================+" << endl;
        cout << "    MENU MANAJEMEN ANGGOTA   " << endl;
        cout << "+========================================+" << endl;
        cout << ""<< endl;
        cout << "1. Tambah Anggota" << endl;
        cout << "2. Tampilkan Daftar Anggota" << endl;
        cout << "3. Hapus Anggota" << endl;
        cout << "4. Kembali ke Menu Utama" << endl;
        cout << "Pilih: ";
        cin >> pilihan;
        system ("cls");

        switch (pilihan) {
            case 1:
                tambahAnggota();
                break;
            case 2:
                tampilAnggota();
                break;
            case 3:
                hapusAnggota();
                break;
            case 4:
                cout << "Kembali ke menu utama..." << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihan!=4);
}


void menuUtama(){
    int pilihan;
    do{
        cout<<"+========================================+"<<endl;
        cout<<"    SISTEM PERPUSTAKAAN    "<<endl;
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
                manajemenAnggota();
                system ("cls");
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


int main(){
    menuUtama();
    return 0;
}