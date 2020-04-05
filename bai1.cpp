#include<stdio.h>
//
struct PS
{
    int tu,mau;
    float giatri;
    bool operator > (PS b)
    {
        return (giatri - b.giatri > 0);
    }
    bool operator < (PS b)
    {
        return (giatri - b.giatri < 0);
    }
};
//
void MaxHeap(PS A[], int i, int n);
void XuatMAX(PS A[], int n);
int gcd(int a, int b);
void XuatTongPS(PS A[], int n);
void XuatMAX(PS A[], int n);
void NhapMangPS(PS A[], int &n);
void XuatMangTangDan(PS A[], int n);
void swap(PS &a, PS &b);
void RunHeap(PS A[], int n);
PS TimMax(PS A[], int n);
int gcd(int a, int b);
void NhapPS(PS &x);
void MaxHeapSort(PS A[], int n);
PS TinhTongPS(PS A[] ,int n);
void XuatMIN(PS A[], int n);
PS TimMin(PS A[], int n);
void SuaHinhThuc(PS &x);
//
int main()
{
    PS A[51];
    int n;
    NhapMangPS(A,n);
    XuatTongPS(A,n);
    XuatMAX(A,n);
    XuatMIN(A,n);
    XuatMangTangDan(A,n);
    return 0;
}
void MaxHeap(PS A[], int i, int n)
{
    int root;
    int left=2*i;
    int right=2*i+1;
    if(left<=n && A[left]>A[i])
        root=left;
    else 
        root =i;
    if(right<=n && A[right]>A[root])
        root=right;
    if(root!=i)
    {
        swap(A[i],A[root]);
        MaxHeap(A,root,n);
    }
}
void swap(PS &a, PS &b)
{
    PS c;
    c=a;
    a=b;
    b=c;
}
void RunHeap(PS A[], int n)
{
    for(int i=n/2;i>=1;i--)
    {
        MaxHeap(A,i,n);
    }
}
void MaxHeapSort(PS A[], int n)
{
    int length = n;
    RunHeap(A,n);
    for(int i=n;i>=2;i--)
    {
        swap(A[1],A[i]);
        MaxHeap(A,1,--length);
    }
}
void XuatMangTangDan(PS A[], int n)
{
    MaxHeapSort(A,n);
    for(int i=1;i<=n;i++)
    {
        SuaHinhThuc(A[i]);
        if(A[i].tu==0||A[i].mau==1)
            printf("%d   ",A[i].tu);
        else
        printf("%d/%d   ",A[i].tu, A[i].mau);
    }
}
void XuatMIN(PS A[], int n)
{
    PS min;
    min=TimMin(A,n);
    if(min.tu==0||min.mau==1)
        printf("Min = %d\n",min.tu);
    else
    printf("Min = %d/%d\n",min.tu,min.mau);
}
PS TimMin(PS A[], int n)
{
    PS min=A[1];
    for(int i=2;i<=n;i++)
    {
        if(A[i]<min)
            min=A[i];
    }
    SuaHinhThuc(min);
    return min;
}
void XuatMAX(PS A[], int n)
{
    PS max;
    max=TimMax(A,n);
    if(max.tu==0||max.mau==1)
        printf("Max = %d\n",max.tu);
    else
    printf("Max = %d/%d\n",max.tu,max.mau);
}
PS TimMax(PS A[], int n)
{
    PS max=A[1];
    for(int i=2;i<=n;i++)
    {
        if(max<A[i])
            max=A[i];
    }
    SuaHinhThuc(max);
    return max;
}
void XuatTongPS(PS A[], int n)
{
    PS S;
    S=TinhTongPS(A,n);
    if(S.tu==0||S.mau==1)
        printf("Tong = %d\n",S.tu);
    else
    printf("Tong = %d/%d\n",S.tu,S.mau);
}
int gcd(int a, int b)
{
    if(b==0) return a;
    return gcd(b,a%b);
}
void SuaHinhThuc(PS &x)
{
    int GCD;
    GCD=gcd(x.tu,x.mau);
    x.tu=x.tu/GCD;
    x.mau=x.mau/GCD;
    if(x.mau<0)
    {
        x.tu=x.tu*-1;
        x.mau=x.mau*-1;
    }
}
PS TinhTongPS(PS A[] ,int n)
{
    PS psOG;
    psOG=A[1];
    for(int i=2;i<=n;i++)
    {
        psOG.tu=psOG.tu*A[i].mau+psOG.mau*A[i].tu;
        psOG.mau=psOG.mau*A[i].mau;
    }
    SuaHinhThuc(psOG);
    return psOG;
}
void NhapMangPS(PS A[], int &n)
{
    do
    {
        printf("Nhap so luong phan so : ");
        scanf("%d",&n);
    }while(n<=0);
    for(int i=1;i<=n;i++)
        NhapPS(A[i]);
}
void NhapPS(PS &x)
{
    int t,m;
    printf("Nhap phan so (tu mau) : ");
    scanf("%d%d",&t,&m);
    while(m==0)
    {
        printf("Error! \nNhap lai: ");
        scanf("%d",&m);
    }
    x.tu=t;
    x.mau=m;
    x.giatri=float(t)/m;
}