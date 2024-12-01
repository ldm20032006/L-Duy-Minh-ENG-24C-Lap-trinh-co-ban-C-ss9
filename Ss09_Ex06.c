#include <stdio.h>
int main(){
    int nguoiDungNhap, check = 0;
    int mang2chieu[100][100], row, col;
    while(1){
        printf("\nMENU\n");
        printf("1. Nhap kich kich co va gia tri cac phan tu cua mang\n");
        printf("2. In gia tri cac phan tu cua mang theo ma tran\n");
        printf("3. In gia tri cac phan tu la le va tinh tong\n");
        printf("4. In cac phan tu nam tren duong bien va tinh tich\n");
        printf("5. In cac phan tu nam tren duong cheo chinh\n");
        printf("6. In cac phan tu nam tren duong cheo phu\n");
        printf("7. In ra dong co tong gia tri cac phan tu la lon nhat\n");
        printf("8. Thoat\n");
        printf("Nhap lua chon: ");
        scanf("%d", &nguoiDungNhap);

        switch (nguoiDungNhap){
            
            case 1: //Nhap kich kich co va gia tri cac phan tu cua mang
            check = 1;
            printf("-Nhap so hang cua mang: ");
            scanf("%d", &row);
            if (row < 0 || row > 100){
                printf("-hang cua mang khong hop le");
                break;
            }
            printf("-Nhap so cot cua mang: ");
            scanf("%d", &col);
            if (col < 0 || col > 100){
                printf("-cot cua mang khong hop le");
                break;
            }
            for (int r = 0; r < row; r++){
                for(int c = 0; c < col; c++){
                    printf("-mang2chieu[%d][%d]= ", r, c);
                    scanf("%d", &mang2chieu[r][c]);
                }
            }
            break;
            
            case 2: //In gia tri cac phan tu cua mang theo ma tran
            if(check == 0){
                printf("-chua nhap mang");
                break;
            }
            for(int r = 0; r < row; r++){
                for(int c = 0; c < col; c++){
                    printf("%d ", mang2chieu[r][c]);
                }
                printf("\n");
            }
            break;
            
            case 3: //In gia tri cac phan tu la le va tinh tong
            if(check == 0){
                printf("-chua nhap mang");
                break;
            }
            int tongPhanTuLe = 0;
            printf("-cac phan tu le trong mang la: ");
            for(int r = 0; r < row; r++){
                for(int c = 0; c < col; c++){
                    if(mang2chieu[r][c] % 2 != 0){
                        printf("%d ", mang2chieu[r][c]);
                        tongPhanTuLe += mang2chieu[r][c];
                    }
                }
            }
            if (tongPhanTuLe == 0){
                printf("-khong co so le");
            } else {
                printf("\n-tong cac so le la: %d", tongPhanTuLe);
            }
            break;

            case 4: // In cac phan tu nam tren duong bien va tinh tich
            if(check == 0){
                printf("-chua nhap mang\n");
                break;
            }
            int tich = 1;
            printf("-cac phan tu nam tren duong bien la: \n");
            for (int c = 0; c < col; c++) {
                printf("%d ", mang2chieu[0][c]);
                tich *= mang2chieu[0][c];
            }
            if (row > 1) {
                for (int c = 0; c < col; c++) {
                    printf("%d ", mang2chieu[row - 1][c]);
                    tich *= mang2chieu[row - 1][c];
                }
            }
            for (int r = 1; r < row - 1; r++) {
                printf("%d ", mang2chieu[r][0]);
                tich *= mang2chieu[r][0];
                if (col > 1) {
                    printf("%d ", mang2chieu[r][col - 1]);
                    tich *= mang2chieu[r][col - 1];
                }
            }
            printf("\n-tich cac phan tu tren duong bien la: %d\n", tich);
            break;

            case 5: //In cac phan tu nam tren duong cheo chinh
            if(check == 0){
                printf("-chua nhap mang\n");
                break;
            }
            if (row != col){
            printf("-khong phai ma tran vuong");
            break;
            }
            int c;
            printf("-cac phan tu tren duong cheo chinh la: \n");
            for(int r = 0; r < row; r++){
                printf("%d ", mang2chieu[r][r]);
            }
            break;

            case 6: //In cac phan tu nam tren duong cheo phu
            if(check == 0){
                printf("-chua nhap mang\n");
                break;
            }
            if (row != col){
            printf("-khong phai ma tran vuong");
            break;
            }
            printf("-cac phan tu tren duong cheo phu la: ");
            for(int r = 0; r < row; r++){
                printf("%d ", mang2chieu[r][row - r - 1]);
            }
            break;
            
            case 7: // In ra dong co tong gia tri cac phan tu la lon nhat
            if (check == 0) {
                printf("-chua nhap mang\n");
                break;
            }
            int maxTong = 0;
            int dongMax = 0;
            for (int r = 0; r < row; r++) {
                int tongDong = 0; 
                for (int c = 0; c < col; c++) {
                    tongDong += mang2chieu[r][c];
                }
                if (tongDong > maxTong) {
                    maxTong = tongDong;
                    dongMax = r;
                }
            }
            printf("-dong co tong gia tri cac phan tu lon nhat la dong %d\n", dongMax);
            printf("-cac phan tu tren dong nay la: ");
            for (int c = 0; c < col; c++) {
                printf("%d ", mang2chieu[dongMax][c]);
            }
            printf("\n");
            printf("-tong cua dong nay la: %d\n", maxTong);
            break;
            
            case 8: //thoat
            return 0;

            default:
            printf("-Lua chon khong hop le, vui long nhap lai");
        }   
    }
}