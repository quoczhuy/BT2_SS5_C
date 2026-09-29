#include <stdio.h>

int main() {
    // 1. Khai bao mang du lieu va cac bien lien quan
    int tuoi_benh_nhan[4];
    int co_bao_hiem[4];
    int phi_kham[4];
    
    int tong_doanh_thu = 0;
    int so_ca_uu_tien = 0;
    const int PHI_KHAM_GOC = 200000;

    printf("--- HEO THONG TIEP NHAN BENH NHAN MEDCARE ---\n");

    // 2. Nhap du lieu cho 4 benh nhan
    for (int i = 0; i < 4; i++) {
        printf("\nNhap thong tin benh nhan thu %d:\n", i + 1);
        printf("- Tuoi: ");
        scanf("%d", &tuoi_benh_nhan[i]);
        printf("- Co BHYT (1: Co, 0: Khong): ");
        scanf("%d", &co_bao_hiem[i]);
    }

    // 3. Xu ly du lieu: Tinh toan va kiem tra sai sot
    for (int i = 0; i < 4; i++) {
        // Loi 1: Kiem tra do tuoi di biet
        if (tuoi_benh_nhan[i] <= 0 || tuoi_benh_nhan[i] > 120) {
            phi_kham[i] = 0; // Khong thu phi do du lieu loi
            // Khong cong vao so ca uu tien
        } 
        else {
            // Loi 2: Kiem tra trang thai BHYT sai quy chuan
            if (co_bao_hiem[i] != 0 && co_bao_hiem[i] != 1) {
                co_bao_hiem[i] = 0; // Ep ve mac dinh la Khong co BHYT
            }

            // Tinh phi kham theo BHYT
            if (co_bao_hiem[i] == 1) {
                phi_kham[i] = PHI_KHAM_GOC * 20 / 100; // Giam 80%, tra 20%
            } else {
                phi_kham[i] = PHI_KHAM_GOC; // Tra 100%
            }

            // Cong don doanh thu
            tong_doanh_thu += phi_kham[i];

            // Kiem tra luong uu tien (Tren 70 tuoi)
            if (tuoi_benh_nhan[i] > 70) {
                so_ca_uu_tien++;
            }
        }
    }

    // 4. Xuat bao cao tong hop
    printf("\n====================================================\n");
    printf("              BAO CAO CA KHAM SANG                  \n");
    printf("====================================================\n");
    
    for (int i = 0; i < 4; i++) {
        printf("Benh nhan %d | Tuoi: %3d | BHYT: %d | Phi: %6d VND | Luong: ", 
               i + 1, tuoi_benh_nhan[i], co_bao_hiem[i], phi_kham[i]);
        
        // Hien thi luong dua vao do tuoi
        if (tuoi_benh_nhan[i] <= 0 || tuoi_benh_nhan[i] > 120) {
            printf("LOI DU LIEU\n");
        } else if (tuoi_benh_nhan[i] > 70) {
            printf("UU TIEN\n");
        } else {
            printf("THUONG\n");
        }
    }
    
    printf("----------------------------------------------------\n");
    printf("Tong doanh thu ca sang: %d VND\n", tong_doanh_thu);
    printf("Tong so ca uu tien: %d ca\n", so_ca_uu_tien);
    printf("====================================================\n");

    return 0;
}