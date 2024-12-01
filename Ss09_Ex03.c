#include <stdio.h>
int main() {
    int mang[100];
    int soPhanTu;

    printf("nhap so phan tu cua mang: ");
    scanf("%d", &soPhanTu);
    if ( soPhanTu < 0 || soPhanTu > 100){
        printf("so phan tu khong hop le");
        return 1;
    }
    printf("nhap cac phan tu cua mang: \n");
    for(int i = 0; i < soPhanTu; i++){
        printf("mang[%d]: ", i);
        scanf("%d", &mang[i]);
    }

    printf("nhap vi tri can xoa: ");
    int vtriCanXoa;
    scanf("%d", &vtriCanXoa);
    if ( vtriCanXoa < 0 || vtriCanXoa >= soPhanTu){
        printf("vi tri can xoa khong hop le");
        return 1;
    }
    
    for (int i = vtriCanXoa; i < soPhanTu - 1; i++) {
        mang[i] = mang[i + 1];
    }
    soPhanTu--;
    for (int i = 0; i < soPhanTu; i++) {
        printf("%d ", mang[i]);
    }
    return 0;
}
