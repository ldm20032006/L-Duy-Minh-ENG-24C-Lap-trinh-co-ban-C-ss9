#include <stdio.h>
int main(){
    int nguoiDungNhap, check = 0;
    int mang[100], soPhanTuMang = 0;
    while (1){
        printf("\nMENU\n");
        printf("1. Nhap so phan tu va gia tri cac phan tu\n");
        printf("2. In ra cac phan tu  dang quan ly\n");
        printf("3. In ra gia tri cac phan tu chan va tinh tong\n");
        printf("4. In ra gia tri lon nhat va nho nhat trong mang\n");
        printf("5. In ra cac phan tu la so nguyen to trong mang va tinh tong\n");
        printf("6. Nhap vao mot so va thong ke trong mang co bao nhieu phan tu do\n");
        printf("7. Them mot phan tu vao vi tri chi dinh\n");
        printf("8. Thoat\n");
        printf("Nhap lua chon: ");
        scanf("%d", &nguoiDungNhap);

        switch (nguoiDungNhap){
        case 1: //Nhap so phan tu va gtri cac phan tu
            check = 1;
            printf("-Nhap so phan tu cua mang: ");
            scanf("%d", &soPhanTuMang);
            if ( soPhanTuMang < 0 || soPhanTuMang > 100){
                printf("-So phan tu mang khong hop le");
                break;
            }
            for (int i = 0; i < soPhanTuMang; i++){
                printf("-mang[%d]: ", i);
                scanf("%d", &mang[i]);
            }
            break;
        case 2: //In ra cac phan tu dang quan ly
        	if(check == 0){
        		printf("--chua co mang--");
        		break;
			}
            for(int i = 0; i < soPhanTuMang; i++){
                printf("-mang[%d]= %d\n", i, mang[i]);
            }
            break;
        
        case 3: //In ra gia tri cac phan tu chan va tinh tong
            if(check == 0){
        		printf("--chua co mang--");
        		break;
			}
            int tongSoChan = 0;
            printf("-Cac phan tu chan la: ");
            for(int i = 0; i < soPhanTuMang; i++){
                if(mang[i] % 2 == 0){
                    printf("%d ", mang[i]);
                    tongSoChan += mang[i];
                }
            }
            if (tongSoChan == 0){
                printf("\n-khong co so chan");
            } else {
                printf("\n-tong cac so chan la: %d", tongSoChan);
            }
            break;

        case 4: //In ra gia tri lon nhat va nho nhat trong mang
            if(check == 0){
        		printf("--chua co mang--");
        		break;
			}
			int max = mang[0];
			int min = mang[0];
            printf("-gia tri lon nhat trong mang la: ");
            for (int i = 0; i < soPhanTuMang; i++){
                if (max < mang[i]){
                    max = mang[i];
                }
            }
            printf("%d\n-gia tri nho nhat trong mang la: ", max);
            for (int i = 0; i < soPhanTuMang; i++){
                if(min > mang[i]){
                    min = mang[i];
                }
            }
            printf("%d", min);
            break;
        case 5: //In ra cac phan tu la so nguyen to trong mang va tinh tong
            if(check == 0){
        		printf("--chua co mang--");
        		break;
			}
            printf("-Cac so nguyen to trong mang la: ");
            int tongSoNguyenTo = 0;
            int coSoNguyenTo = 0;
            for (int i = 0; i < soPhanTuMang; i++){
                int soNguyento = mang[i];
                int checkSoNguyenTo = 1;
                if (soNguyento < 2){
                    checkSoNguyenTo = 0;
                } else {
                    for (int j = 2; j * j <= soNguyento; j++){
                        if (soNguyento % j == 0){
                            checkSoNguyenTo = 0;
                            break;
                        }
                    }
                }
                if (checkSoNguyenTo == 1){
                    printf("%d ", soNguyento);
                    tongSoNguyenTo += soNguyento;
                    coSoNguyenTo = 1;
                }
            }
            if(coSoNguyenTo == 0){
                printf("-khong co so nguyen to");
            } else {
                printf("\n-tong cac so nguyen to la: %d", tongSoNguyenTo);
            }
            break;
        case 6: //Nhap vao mot so va thong ke trong mang co bao nhieu phan tu do
            if(check == 0){
        		printf("--chua co mang--");
        		break;
			}
			int timSo;
			int demTu = 0;
            printf("-nhap mot so de thong ke trong mang: ");
            scanf("%d", &timSo);
            for(int i = 0; i < soPhanTuMang; i++){
                if(timSo == mang[i]){
                    demTu++;
                }
            }
            if (demTu > 0){
                printf("-trong mang co %d phan tu do", demTu);
            } else {
                printf("-trong mang khong co phan tu do");
            }
            break;
        case 7: //Them mot phan tu vao vi tri chi dinh
        	if(check == 0){
        		printf("--chua co mang--");
        		break;
			}
            int gtriPhanTuThem, vtriThemPhanTu;
            printf("-nhap vi tri ban muon them: ");
            scanf("%d", &vtriThemPhanTu);
            if(vtriThemPhanTu < 0|| vtriThemPhanTu > soPhanTuMang){
                printf("-vi tri chen khong hop le");
                break;
            }
            printf("-nhap gia tri muon them vao mang: ");
            scanf("%d", &gtriPhanTuThem);
            for (int i = soPhanTuMang; i >= vtriThemPhanTu; i--){
                mang[i] = mang[i - 1];
            }
            mang[vtriThemPhanTu] = gtriPhanTuThem;
            soPhanTuMang++;
            break;
        case 8: //thoat
            return 0;
        default: 
            printf("Lua chon khong hop le, vui long nhap lai");
        }
    }
}