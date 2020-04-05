#include<stdio.h>
#include<math.h>
//
void Xuat(float Kq);
float TinhE(int x, int n);
int TinhGiaiThua(int n);
void Nhap(int &x, int &n);
//
int main()
{
    int x,n;
    Nhap(x,n);
    float Kq=TinhE(x,n);
    Xuat(Kq);
    return 0;
}
void Xuat(float Kq)
{
    printf("E = %.2f",Kq);
}
float TinhE(int x, int n)
{
    if(n==0) return 0;
    return TinhE(x,n-1)+pow(x,n)/TinhGiaiThua(n);
}
int TinhGiaiThua(int n)
{
    if(n==1) return 0;
    return TinhGiaiThua(n-1)*n;
}
void Nhap(int &x, int &n)
{
    printf("Nhap x: ");
    scanf("%d",&x);
    do
    {
        printf("Nhap n: ");
        scanf("%d",&n);
    }while(n<0);
}