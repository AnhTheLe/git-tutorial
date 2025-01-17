#include<stdio.h>
#include <stdlib.h>
#include<cstring>
#include<conio.h>
#define MAX 1000
struct sinhvien
{
    float hd,pb,hd1,hd2,hd3,giua_ky,cuoi_ky;
    char mssv[10];
    char ho_ten[100];
};
sinhvien sv[MAX];
int soluong;
// CHUỖI HÀM NHẬP THÔNG TIN SINH VIEN
bool kiemtra_tensv(sinhvien &sv)
{
    int dem=0;
    for(int i=0;i<strlen(sv.ho_ten);i++)
    {
        if(sv.ho_ten[i]==' ') dem++;
    }
    if(dem!=0) return true;
    else return false;
}

void nhap_sv(sinhvien &sv)
{
    do{
        printf("Nhap ten sv ( Ten phai chua dau cach! ): ");
        fflush(stdin);
        gets(sv.ho_ten);
    }while(kiemtra_tensv(sv)==false);


    do{
        printf("Nhap mssv ( MSSV KO DC TRUNG NHAU! ): ");
        scanf("%s",sv.mssv);
    }while(strlen(sv.mssv)>5);

    do
    {
        printf("Nhap diem huong dan: ");
        scanf("%f",&sv.hd);
    } while (sv.hd>10||sv.hd<0);


    do
    {
        printf("Nhap diem phan bien: ");
        scanf("%f",&sv.pb);
    } while (sv.pb>10||sv.pb<0);

   do
   {
        printf("Nhap diem hoi dong 1: ");
        scanf("%f",&sv.hd1);
   } while (sv.hd1>10||sv.hd1<0);

   do
   {
        printf("Nhap diem hoi dong 2: ");
        scanf("%f",&sv.hd2);
   } while (sv.hd2>10||sv.hd2<0);

   do
   {
        printf("Nhap diem hoi dong 3: ");
        scanf("%f",&sv.hd3);
   } while (sv.hd3>10||sv.hd3<0);

    if((sv.hd > 5.5) && (sv.pb > 5.5)) sv.giua_ky = (sv.hd+sv.pb)/2;
    else sv.giua_ky=0;
    if((sv.hd1 > 5.5) && (sv.hd2 > 5.5) && (sv.hd3 > 5.5)) sv.cuoi_ky = (sv.hd1 + sv.hd2 + sv.hd3)/3;
    else sv.cuoi_ky=0;
}
void nhap_danhsach()
{
    for(int i=0;i<soluong;i++)
    {
        printf("Moi ban nhap du lieu cua sinh vien thu %d\n ",i+1);
        nhap_sv(sv[i]);
    }
}

void in_thong_tin(sinhvien &sv)
{
    printf("%-13s%-13s%-13.1f%-13.1f%-13.1f%-13.1f%-13.1f%-13.1f%-13.1f\n",sv.mssv,sv.ho_ten,sv.hd,sv.pb,sv.hd1,sv.hd2,sv.hd3,sv.giua_ky,sv.cuoi_ky);
}

void in_danhsach_sv()
{
    printf("%-13s%-13s%-13s%-13s%-13s%-13s%-13s%-13s%-13s\n","MSSV","HO TEN","HD","PB","HD1","HD2","HD3","GIUA KY","CUOI KY");
    for(int i=0;i<soluong;i++){
        printf("%-13s%-13s%-13.1f%-13.1f%-13.1f%-13.1f%-13.1f%-13.1f%-13.1f\n",sv[i].mssv,sv[i].ho_ten,sv[i].hd,sv[i].pb,sv[i].hd1,sv[i].hd2,sv[i].hd3,sv[i].giua_ky,sv[i].cuoi_ky);
    }
}
//----------------------------------------------------------------------------------------------------------------------------------------------------------
void xuat_danhsach_baove_thanhcong()
{
    printf("Danh sach sinh vien bao ve thanh cong!!\n");
    for(int i=0;i<soluong;i++)
    {
        if(sv[i].cuoi_ky!=0 && sv[i].giua_ky!=0) in_thong_tin(sv[i]);
    }
}
// chuỗi hàm xắp xếp sinh viên theo tên từ a-z--------------------------------------------------------------------
char  *timten(char hoten[]) // Giả thiết họ tên là xâu không rỗng và không có kí tự trắng thừa
{
    int i;
    i = strlen(hoten)-1;
    // tìm kí tự trắng cuối cùng trong xâu /
    while (i < 0 && hoten[i] != ' ') i--;
    return hoten + i + 1;
}
void sapxepten()
{       
	char cname[20];
		for(int i=0;i<soluong;i++){
			for(int j=strlen(sv[i].ho_ten)-1;j>=0;j++){
				if(sv[i].ho_ten[j]==' '){
					cname[i] = sv[i].ho_ten[j+1];
                    break;
				}
			}
		}
		for(int i=0;i<soluong-1;i++){
			for(int j=i+1;j<soluong;j++){
				if(cname[i]>cname[j]){
					sinhvien tmp;
					tmp = sv[i];sv[i]=sv[j];sv[j]=tmp;
				}
			}
		}
}
//--------------------------------------------------------------------------------------------------------------------------------
bool kiemtraTrungmssv(sinhvien sv[],int i)
{
    static int count=0;
    for(int j=0;j<i;j++)
    {
        if(strcmp(sv[i].mssv,sv[j].mssv)==0) count++;
    }
    if(count!=0) return true;
    else return false;
}


void bo_sungsv()
{
    int x;
    do{
        printf("Moi ban nhap so luong sinh vien can bo sung:");
        scanf("%d",&x);
    }while(soluong+x > 20);
                
    for(int i=soluong;i<soluong+x;i++)
    {
        
        printf("Moi ban nhap du lieu cua sinh vien thu %d\n ",i+1);
        do{    
            nhap_sv(sv[i]);
        }while (kiemtraTrungmssv(sv,i)==true);
        
    }
    soluong=soluong+x;
}
//--------------------------------------------------------------------------------------------------------------------------
void sapxepTheoDCK() {
    //Sap xep theo DTB tang dan
    sinhvien tmp;
    for(int i = 0;i < soluong;i++){
        for(int j = i+1; j < soluong;j++){
            if(sv[i].cuoi_ky < sv[j].cuoi_ky){
                tmp = sv[i];
                sv[i] = sv[j];
                sv[j] = tmp;
            }
        }
    }
}
//-------------------------------------------------------------------------------------------------------------------------------
int main()
{
    int key;
    int x;
    bool daNhap = false;

    do{
        printf("Moi ban nhap so luong sinh vien:");
        scanf("%d",&soluong);
    }while((soluong > 0)&&(soluong > 20));
    nhap_danhsach();
    in_danhsach_sv();

//
    while(true){
        system("cls");
        printf("******************************************************\n");
        printf("**        CHUONG TRINH QUAN LY SINH VIEN            **\n");
        printf("**      1. Bo sung sinh vien                        **\n");
        printf("**      2. Danh sach sv da bao ve thanh cong        **\n");
        printf("**      3. Sap xep sinh vien theo ten               **\n");
        printf("**      4. Sap xep sinh vien theo diem cuoi ki      **\n");
        printf("**      0. Thoat                                    **\n");
        printf("******************************************************\n");
        printf("**       Nhap lua chon cua ban !                    **\n");
        scanf("%d",&key);
        switch(key)
        {
            case 1:
                printf("\nBan da chon bo sung DS sinh vien!\n");
                //bổ sung them thông tin sinh viên
                printf("So luong sinh vien toi da la 20\n Hien tai ban da nhap %d sinh vien!\nSo sinh vien co the nhap them la:%d\n",soluong,20-soluong);
                int x;
                bo_sungsv();
                printf("\nBan da nhap thanh cong!");
                printf("\nBam phim bat ky de tiep tuc!");
                getch();
                break;
            case 2:
                printf("\nBan da chon xuat DS sinh vien da bao ve thanh cong!\n");
                printf("Danh sach sinh vien bao ve thanh cong!!\n\n");
                printf("%-13s%-13s%-13s%-13s%-13s%-13s%-13s%-13s%-13s\n","MSSV","HO TEN","HD","PB","HD1","HD2","HD3","GIUA KY","CUOI KY");
                for(int i=0;i<soluong;i++)
                {
                    if(sv[i].cuoi_ky!=0 && sv[i].giua_ky!=0) in_thong_tin(sv[i]);
                }
                printf("\nBam phim bat ky de tiep tuc!");
                getch();
                break;
            case 3:
                printf("\nBan da chon Sap xep sinh vien theo ten !\n");
                sapxepten();
                in_danhsach_sv();
                printf("\nBam phim bat ky de tiep tuc!");
                getch();
                break;

            case 4:
                printf("\nSap xep sinh vien theo diem cuoi ki!");
                sapxepTheoDCK(); 
                in_danhsach_sv();   
            case 0:
                printf("\nBan da chon thoat chuong trinh!");
                printf("\nBam phim bat ky de tiep tuc!");
                getch();
                break;
            default:
                printf("\nKhong co chuc nang nay!");
                printf("\nBam phim bat ky de tiep tuc!");
                getch();
                break;
        }
    }
      return 0;
}
    

  
