// Truong Xuan Thong 20220044
#include <stdio.h>
#include <stdlib.h>

void nhapMatran(int **mtr, int n){
for(int i = 0; i<n; i++){
    for(int j = 0; j<n; j++){
        scanf("%d", &mtr[i][j]);
    }
}
}

void xuatMatran(int** mtr, int n){
for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", mtr[i][j]);
        }
        printf("\n");
    }
}

int congMatran(int** mtr1, int** mtr2, int n){
int** ketqua = (int**)calloc(n, sizeof(int*));
    if (ketqua == NULL) {
        printf("Khong the cap phat bo nho.\n");
        exit(1);
    }
    for (int i = 0; i < n; i++) {
        ketqua[i] = (int*)calloc(n, sizeof(int));
        if (ketqua[i] == NULL) {
            printf("Khong the cap phat bo nho.\n");
            exit(1);
        }
        for (int j = 0; j < n; j++) {
            ketqua[i][j] = mtr1[i][j] + mtr2[i][j];
        }
    }
    return ketqua;
}

int nhanMatran(int** mtr1, int** mtr2, int n){
int** ketqua = (int**)calloc(n, sizeof(int*));
    if (ketqua == NULL) {
        printf("Khong the cap phat bo nho.\n");
        exit(1);
    }
    for (int i = 0; i < n; i++) {
        ketqua[i] = (int*)calloc(n, sizeof(int));
        if (ketqua[i] == NULL) {
            printf("Khong the cap phat bo nho.\n");
            exit(1);
        }
        for (int j = 0; j < n; j++) {
                ketqua[i][j] = 0;
                for(int k=0; k <n; k++){
            ketqua[i][j] += mtr1[i][k] * mtr2[k][j];
        }
        }
    }
    return ketqua;
}

void giaiphong(int** mtr, int n){
for(int i = 0; i <n; i++){
    free(mtr[i]);
}
free(mtr);
}



int main()
{
     int n;
    printf("Nhap kich thuoc n: ");
    scanf("%d", &n);

    int** mtr1 = (int**)calloc(n, sizeof(int*));
    int** mtr2 = (int**)calloc(n, sizeof(int*));
    if (mtr1 == NULL || mtr2 == NULL) {
        printf("Khong the cap phat bo nho.\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        mtr1[i] = (int*)calloc(n, sizeof(int));
        mtr2[i] = (int*)calloc(n, sizeof(int));
        if (mtr1[i] == NULL || mtr2[i] == NULL) {
            printf("Khong the cap phat bo nho.\n");
            return 1;
        }
    }

    printf("ma tran thu nhat:\n");
    nhapMatran(mtr1, n);

    printf("ma tran thu hai:\n");
    nhapMatran(mtr2, n);

    int** tong = congMatran(mtr1, mtr2, n);
    int** tich = nhanMatran(mtr1, mtr2, n);

    printf("Tong cua hai ma tran:\n");
    xuatMatran(tong, n);

    printf("Tich cua hai ma tran:\n");
    xuatMatran(tich, n);

    giaiphong(mtr1, n);
    giaiphong(mtr2, n);
    giaiphong(tong, n);
    giaiphong(tich, n);

    return 0;
}

