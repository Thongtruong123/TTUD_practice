#include<stdio.h>
#include<string.h>

#define MAX_SV 300
#define MAX_LENGTH 30
char **DanhsachSV = NULL;
int so_sv = 0;
int volume_pointer = 30;

// mo rong volume
void MoRong_Dachsach(){
volume_pointer += 10;
DanhsachSV= (char**)realloc(DanhsachSV, volume_pointer * sizeof(char *));
if( DanhsachSV == NULL){
    printf(" Loi cap phat memory. \n");
    exit(1);
}
}

// bo sung sinh vien
void add_sv(){
char ten[MAX_LENGTH];
while(so_sv < MAX_SV){
    printf("Nhap Ho va Ten cua sinh vien: (nhan moi phim enter neu muon dung):");
    fgets(ten, MAX_LENGTH, stdin);
    if(ten[strlen(ten)-1] == '\n'){
        ten[strlen(ten)-1] = '\0';
    }
    if ( strlen(ten) == 0) break;
    if ( so_sv >= volume_pointer) MoRong_Dachsach();

    DanhsachSV[so_sv] = (char *)calloc(strlen(ten) + 1, sizeof(char)); // Sử dụng calloc
        if (DanhsachSV[so_sv] == NULL) {
            printf("Loi cap phat memory.\n");
            exit(1);
        }

    strcpy(DanhsachSV[so_sv], ten);
    so_sv ++;
}
}

// sap xep sinh vien theo thu tu alphabet
void sort_sv(){
    if(so_sv == 0){
        printf(" Chua co sinh vien nao trong danh sach. \n");
        return;
    }
    printf("Danh sach Sinh vien sau khi duoc sap xep:\n");
for (int i =0; i< so_sv - 1; i ++){
    for(int j = i + 1; j<= so_sv -1; j++){
        if(strcmp(DanhsachSV[i], DanhsachSV[j]) > 0){
            char *temp[MAX_LENGTH];
            strcpy(temp, DanhsachSV[i]);
            strcpy(DanhsachSV[i], DanhsachSV[j]);
            strcpy(DanhsachSV[j], temp);
        }
    }
}
for (int i = 0; i < so_sv; i++) {
            printf("%d. %s\n", i + 1, DanhsachSV[i]);
        }
}

//in danh sach
void print_sv(){
if( so_sv == 0){
    printf("Hien khong ton tai sinh vien nao trong danh sach. \n");
}
else{
    printf("Danh sach Sinh vien:\n");
        for (int i = 0; i < so_sv; i++) {
            printf("%d. %s\n", i + 1, DanhsachSV[i]);
        }
    }
}


//Dừng chương trình
void Stop() {
    printf("Exit\n");

    for(int i = 0; i< so_sv; i++){
        free(DanhsachSV[i]);
    }
    free(DanhsachSV);
}

void return_menu() {
    char s;
    do {
        printf("Enter '#' de tro ve menu: ");
        scanf(" %c", &s);
        getchar();
    } while (s != '#');
}


int main() {
    DanhsachSV = (char **)calloc(30, sizeof(char*));
    if(DanhsachSV == NULL){
        printf("Loi cap phat bo nho. \n");
        exit(1);
    };
    int chon;
    while (1) {

        printf("\n--- Chuong trinh quan ly sinh vien ---\n");
        printf("1. Them sinh vien \n");
        printf("2. Sap xep sinh vien \n");
        printf("3. In ra danh sach sinh vien \n");
        printf("4. Exit \n");
        printf("Vui long chon option: ");
        scanf("%d", &chon);
        getchar();

        switch (chon) {
            case 1:
                add_sv();
                return_menu();
                break;
            case 2:
                sort_sv();
                return_menu();
                break;
            case 3:
                print_sv();
                return_menu();
                break;
            case 4:
                Stop();
                return 0;
            default:
                printf("Lựa chọn không hợp lệ. Vui lòng chọn lựa chọn khác. \n");
        }
    }

    return 0;
}

