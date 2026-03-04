#include <stdio.h>   // Untuk fungsi input/output seperti scanf dan printf
#include <limits.h>  // Untuk INT_MAX dan INT_MIN, nilai batas integer

int main() {
    int n;          // Variabel untuk menyimpan jumlah bilangan yang akan dibaca
    int num;        // Variabel untuk menyimpan setiap bilangan yang dibaca
    int min_val = INT_MAX; // Inisialisasi nilai terkecil dengan nilai integer maksimum
    int max_val = INT_MIN; // Inisialisasi nilai terbesar dengan nilai integer minimum
    int i;          // Variabel untuk perulangan

    // Membaca nilai 'n' dari input
    scanf("%d", &n);

    // Sebagai good practice (meskipun prompt tidak meminta validasi detail),
    // kita bisa memastikan n adalah positif.
    if (n <= 0) {
        // Jika n tidak valid, kita bisa menganggap tidak ada input yang diproses
        // atau memberikan pesan error jika diperlukan.
        // Untuk tujuan ini, kita akan keluar dari program.
        return 1; // Mengakhiri program dengan kode error
    }

    // Melakukan perulangan 'n' kali untuk membaca setiap bilangan
    for (i = 0; i < n; i++) {
        scanf("%d", &num); // Membaca bilangan berikutnya

        // Membandingkan dengan nilai terkecil yang sudah ditemukan
        // Jika 'num' lebih kecil dari 'min_val' saat ini, update 'min_val'
        if (num < min_val) {
            min_val = num;
        }

        // Membandingkan dengan nilai terbesar yang sudah ditemukan
        // Jika 'num' lebih besar dari 'max_val' saat ini, update 'max_val'
        if (num > max_val) {
            max_val = num;
        }
    }

    // Mencetak nilai terkecil ke konsol, diikuti dengan baris baru
    printf("%d\n", min_val);
    // Mencetak nilai terbesar ke konsol, diikuti dengan baris baru
    printf("%d\n", max_val);

    return 0; // Mengakhiri program
}
