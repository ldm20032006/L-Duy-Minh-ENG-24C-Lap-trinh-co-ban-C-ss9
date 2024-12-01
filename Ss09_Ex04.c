#include <stdio.h>

int main() {
    int nguoiDungNhap, check = 0;
    int mang[100], soPhanTuMang = 0;

    while (1) {
        printf("MENU\n");
        printf("1. Nhap vao mang\n");
        printf("2. Hien thi mang\n");
        printf("3. Them phan tu\n");
        printf("4. Sua phan tu\n");
        printf("5. Xoa phan tu\n");
        printf("6. Thoat\n");
        printf("Nhap lua chon: ");
        scanf("%d", &nguoiDungNhap);

        switch (nguoiDungNhap) {
        case 1: // Nhập vào mảng
            check = 1;
            printf("Nhap so phan tu mang: ");
            scanf("%d", &soPhanTuMang);
            if (soPhanTuMang < 0 || soPhanTuMang > 100) {
                printf("So phan tu khong hop le.\n");
                soPhanTuMang = 0;
                break;
            }
            for (int i = 0; i < soPhanTuMang; i++) {
                printf("mang[%d]: ", i);
                scanf("%d", &mang[i]);
            }
            break;

        case 2: // Hiển thị mảng
            if (check == 0) {
                printf("Chua nhap mang.\n");
                break;
            }
            printf("Mang hien tai:\n");
            for (int i = 0; i < soPhanTuMang; i++) {
                printf("mang[%d]: %d\n", i, mang[i]);
            }
            break;

        case 3: // Thêm phần tử
            if (check == 0) {
                printf("Chua nhap mang.\n");
                break;
            }
            int vtriThemPhanTu, phanTuThem;
            printf("Vi tri them phan tu: ");
            scanf("%d", &vtriThemPhanTu);
            if (vtriThemPhanTu < 0 || vtriThemPhanTu > soPhanTuMang) {
                printf("Vi tri them phan tu khong hop le.\n");
                break;
            }
            printf("Nhap gia tri phan tu them: ");
            scanf("%d", &phanTuThem);
            for (int i = soPhanTuMang; i > vtriThemPhanTu; i--) {
                mang[i] = mang[i - 1];
            }
            mang[vtriThemPhanTu] = phanTuThem;
            soPhanTuMang++;
            printf("Da them phan tu.\n");
            break;

        case 4: // Sửa phần tử
            if (check == 0) {
                printf("Chua nhap mang.\n");
                break;
            }
            int vtriSuaPhanTu, gtriSua;
            printf("Nhap vi tri can sua: ");
            scanf("%d", &vtriSuaPhanTu);
            if (vtriSuaPhanTu < 0 || vtriSuaPhanTu >= soPhanTuMang) {
                printf("Vi tri sua khong hop le.\n");
                break;
            }
            printf("Nhap gia tri moi: ");
            scanf("%d", &gtriSua);
            mang[vtriSuaPhanTu] = gtriSua;
            printf("Da sua phan tu.\n");
            break;

        case 5: // Xóa phần tử
            if (check == 0) {
                printf("Chua nhap mang.\n");
                break;
            }
            int vtriXoaPhanTu;
            printf("Nhap vi tri can xoa phan tu: ");
            scanf("%d", &vtriXoaPhanTu);
            if (vtriXoaPhanTu < 0 || vtriXoaPhanTu >= soPhanTuMang) {
                printf("Vi tri xoa khong hop le.\n");
                break;
            }
            for (int i = vtriXoaPhanTu; i < soPhanTuMang - 1; i++) {
                mang[i] = mang[i + 1];
            }
            soPhanTuMang--;
            printf("Da xoa phan tu.\n");
            break;

        case 6: // Thoát
            return 0;

        default:
            printf("Lua chon khong hop le, vui long nhap lai.\n");
        }
    }
}
