#include<stdio.h>
//
struct NP
{
    int HienThi[50];
    int size;
};
//
void DoiNhiPhanMang(NP A[] ,int n);
void XuatNhiPhan(NP x);
void XuatNhiPhanMang(NP A[], int n);
void DoiNhiPhan(NP &x, int nX);
void Nhap(int &n);
//
int main()
{
    int n;
    NP A[50];
    Nhap(n);
    DoiNhiPhanMang(A,n);
    XuatNhiPhanMang(A,n);
    return 0;
}
void DoiNhiPhanMang(NP A[] ,int n)
{
    for(int i=0;i<=n;i++)
    {
        DoiNhiPhan(A[i],i);
    }
}
void XuatNhiPhan(NP x)
{
    for(int i=x.size;i>=0;i--)
    {
        printf("%d",x.HienThi[i]);
    }
}
void XuatNhiPhanMang(NP A[], int n)
{
    for(int i=0;i<=n;i++)
    {
        XuatNhiPhan(A[i]);
        printf("    ");
    }
}
void DoiNhiPhan(NP &x, int nX)
{
    int i=0;
    if(nX==0)
    {
        x.HienThi[i]=nX;
        i++;
    }
    while(nX>0)
    {
        x.HienThi[i]=nX%2;
        nX=nX/2;
        i++;
    }
    x.size=i-1;
}
void Nhap(int &n)
{
    do
    {
        printf("Nhap n: ");
        scanf("%d",&n);
    }while(n<0);
}