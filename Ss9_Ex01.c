#include <stdio.h>

int main() {
    int mang[100];
    int soPhanTu, gtriPhanTuThem, vtriThemPhanTu;
    printf("Nhap so phan tu cua mang: ");
    scanf("%d", &soPhanTu);
    if (soPhanTu < 0 || soPhanTu > 100) {
        printf("So phan tu khong hop le.");
        return 1;
    }
    for (int i = 0; i < soPhanTu; i++) {
        printf("mang[%d] = ", i);
        scanf("%d", &mang[i]);
    }
    printf("Nhap gia tri muon them vao mang: ");
    scanf("%d", &gtriPhanTuThem);
    printf("Nhap vi tri de chen gia tri: ");
    scanf("%d", &vtriThemPhanTu);
    if (vtriThemPhanTu < 0 || vtriThemPhanTu > soPhanTu) {
        printf("Vi tri chen khong hop le.");
        return 1;
    }
    for (int i = soPhanTu; i >= vtriThemPhanTu; i--) {
        mang[i] = mang[i - 1];
    }
    mang[vtriThemPhanTu] = gtriPhanTuThem;
    soPhanTu++;
    printf("Mang sau khi them: ");
    for (int i = 0; i < soPhanTu; i++) {
        printf("%d ", mang[i]);
    }
    return 0;
}
