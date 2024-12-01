#include <stdio.h>
int main(){
    int vtriCanSua, gtriSua, mang[5]={1, 2, 3, 4, 5};
    printf("vi tri can sua trong mang la: ");
    scanf("%d", &vtriCanSua);
    if ( vtriCanSua < 0 || vtriCanSua >= 5){
        printf("vi tri sua khong hop le");
        return 1;
    }
    printf("gia tri moi sau khi sua la: ");
    scanf("%d", &gtriSua);
    mang[vtriCanSua] = gtriSua;
    for(int i = 0; i < 5; i++){
        printf("mang[%d]= %d ", i, mang[i]);
    }
    return 0;
}