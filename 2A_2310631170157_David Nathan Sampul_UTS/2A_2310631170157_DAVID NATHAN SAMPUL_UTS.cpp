#include <iostream>
#include <string>

using namespace std;

// Membuat struct untuk menyimpan nilai dan mata pelajaran
struct nilai {
    string mp; // Mata pelajaran
    float score; // Nilai
    nilai* next; // Pointer ke node berikutnya dalam linked list
};

int main() {
    char nama[50], nis[50], kelas[50];
    string huruf;
    nilai* head = NULL; // Pointer ke node pertama dalam linked list
    nilai* tail = NULL; // Pointer ke node terakhir dalam linked list
    string mp[6] = {"B.Inggris", "B.Jepang", "B.Indonesia", "Matematika", "Kewarganegaraan", "Ilmu Fisika"};

    // Membuat array of pointers
    nilai* arr[6];

    // Meminta input dari user
    cout << "\nE-Raport Siswa \n\nInput Nama Siswa\t: ";
    cin.getline(nama, 50);
    cout << "Input Nomor Induk\t: ";
    cin >> nis;
    cin.ignore();
    cout << "Input Kelas\t\t: ";
    cin.getline(kelas, 50);

    cout << endl << "Masukkan Nilai : \n" << endl;

    // Memasukkan nilai ke linked list dan array of pointers
    for (int i = 0 ; i < 6; i++) {
        nilai* newNilai = new nilai; // Membuat node baru
        newNilai->mp = mp[i]; // Menyimpan mata pelajaran
        cout << newNilai->mp << "\t: ";
        cin >> newNilai->score; // Menyimpan nilai
        newNilai->next = NULL; // Menunjuk ke NULL karena ini adalah node terakhir
        arr[i] = newNilai; // Menyimpan pointer ke node baru di array of pointers
        if (head == NULL) {
            head = newNilai; // Jika ini adalah node pertama, update head
            tail = newNilai; // Update tail
        } else {
            tail->next = newNilai; // Menambahkan node baru setelah tail
            tail = newNilai; // Update tail
        }
    }

    int choice;
    do {
        cout << "\nMenu:\n1. Lihat Rapor\n2. Edit Nilai\n3. Keluar\nPilihan: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: { // Lihat rapor
                cout << "\nResult :" << endl;
                cout << "Nama\t: " << nama << endl;
                cout << "NIS\t: " << nis << endl;
                cout << "Kelas\t: " << kelas << endl << endl;

                cout << "No\tMatPel\t\t\tNilai\tKeterangan\n";
                for (int i = 0; i < 6; i++) { // Loop sampai akhir array of pointers
                    cout << i + 1 << "\t" << arr[i]->mp << "\t\t" << arr[i]->score << "\t";
                    if (arr[i]->score >= 85 && arr[i]->score <= 100) {
                        cout << "Sangat Baik" << endl;
                    } else if (arr[i]->score >= 65 && arr[i]->score <= 84) {
                        cout << "Baik" << endl;
                    } else if (arr[i]->score <= 64) {
                        cout << "Kurang" << endl;
                    }
                }

                // Menghitung rata-rata
                float jumlah = 0;
                for (int i = 0; i < 6; i++) { // Loop sampai akhir array of pointers
                    jumlah += arr[i]->score; // Menambahkan nilai ke jumlah
                }

                float avr = jumlah / 6; // Menghitung rata-rata

                // Menentukan keterangan berdasarkan rata-rata
                if (avr >= 85 && avr <= 100) {
                    huruf = "Sangat Baik";
                }
                if (avr >= 65 && avr <= 84) {
                    huruf = "Baik";
                }
                if (avr <= 64) {
                    huruf = "Kurang";
                }
                
                // Menampilkan rata-rata dan keterangan
                cout << "\n\nAverage -- >> " << avr << " (" << huruf <<")" << endl;
                break;
            }
            case 2: { // Edit nilai
                string editMp;
                cout << "\nMasukkan mata pelajaran yang ingin diubah nilainya: ";
                getline(cin, editMp);
                for (int i = 0; i < 6; i++) { // Loop sampai akhir array of pointers
                    if (arr[i]->mp == editMp) {
                        cout << "Masukkan nilai baru: ";
                        cin >> arr[i]->score;
                        cin.ignore();
                        cout << "Nilai berhasil diubah.\n";
                        break;
                    }
                }
                break;
            }
            case 3: // Keluar
                cout << "\nTerima kasih telat menggunakan program ini!" << endl;
                cout << "\nProgram dibuat oleh David Nathan Sampul" << endl;
                break;
            default:
                cout << "Pilihan tidak valid.\n";
        }
    } while (choice != 3);
}
