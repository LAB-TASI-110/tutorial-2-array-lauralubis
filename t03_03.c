#include <stdio.h>   // Untuk fungsi input/output seperti scanf dan printf
#include <limits.h>  // Untuk INT_MAX dan INT_MIN
#include <float.h>   // Untuk DBL_MAX dan DBL_MIN, nilai batas untuk double

int main() {
    int n;          // Variabel untuk menyimpan jumlah bilangan yang akan dibaca
    int num;        // Variabel untuk menyimpan setiap bilangan yang dibaca (current_num)
    int prev_num = 0; // Variabel untuk menyimpan bilangan sebelumnya, diinisialisasi untuk menghindari warning
    int min_val = INT_MAX; // Inisialisasi nilai terkecil dengan nilai integer maksimum
    int max_val = INT_MIN; // Inisialisasi nilai terbesar dengan nilai integer minimum
    
    double min_avg = DBL_MAX; // Inisialisasi rata-rata terendah dengan nilai double maksimum
    double max_avg = DBL_MIN; // Inisialisasi rata-rata tertinggi dengan nilai double minimum
    
    double current_avg; // Variabel untuk menyimpan rata-rata pasangan saat ini
    int i;          // Variabel untuk perulangan
    int has_pair = 0; // Flag untuk menandakan apakah ada setidaknya satu pasangan yang diproses

    // Membaca nilai 'n' dari input
    scanf("%d", &n);

    // Validasi dasar untuk 'n'. 'n' harus bilangan bulat positif.
    if (n <= 0) {
        printf("Input 'n' harus bilangan bulat positif.\n");
        return 1; // Mengakhiri program dengan kode error
    }

    // Melakukan perulangan 'n' kali untuk membaca setiap bilangan
    for (i = 0; i < n; i++) {
        scanf("%d", &num); // Membaca bilangan berikutnya

        // Membandingkan untuk mencari nilai terkecil
        if (num < min_val) {
            min_val = num;
        }

        // Membandingkan untuk mencari nilai terbesar
        if (num > max_val) {
            max_val = num;
        }

        // Jika ini bukan bilangan pertama (i > 0), kita bisa menghitung rata-rata pasangan
        if (i > 0) {
            // Hitung rata-rata dari bilangan sebelumnya (prev_num) dan bilangan saat ini (num)
            // Penting: gunakan (double) untuk memastikan perhitungan floating point
            current_avg = (double)(prev_num + num) / 2.0;

            // Membandingkan dengan rata-rata terendah yang sudah ditemukan
            if (current_avg < min_avg) {
                min_avg = current_avg;
            }
            
            // Membandingkan dengan rata-rata tertinggi yang sudah ditemukan
            if (current_avg > max_avg) {
                max_avg = current_avg;
            }
            has_pair = 1; // Set flag bahwa setidaknya satu pasangan telah diproses
        }

        // Setelah memproses bilangan saat ini, simpan sebagai bilangan sebelumnya untuk iterasi berikutnya
        prev_num = num;
    }

    // Mencetak output sesuai format dan urutan yang diminta
    printf("%d\n", min_val);
    printf("%d\n", max_val);

    // Mencetak rata-rata terendah dan tertinggi. Hanya jika ada setidaknya satu pasangan yang dihitung.
    if (has_pair) {
        printf("%.2f\n", min_avg);
        printf("%.2f\n", max_avg);
    } else {
        // Jika tidak ada pasangan (yaitu, n < 2), tampilkan N/A
        printf("N/A\n");
        printf("N/A\n");
    }

    return 0; // Mengakhiri program dengan sukses
}
