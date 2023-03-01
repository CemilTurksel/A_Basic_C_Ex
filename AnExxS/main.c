#include <stdio.h>
#include <stdlib.h>
struct ogrenci{
    char adsoyad[30];
    char ders[20];
    int vize1,vize2,finalnotu;
};
int main()
{
    FILE *dosya;
    int N;
    float ort;
    printf("Please enter the number of the student:\n");
    scanf("%d",&N);
    struct ogrenci ogr[N];
    dosya=fopen("dersler.txt","w");
    if(dosya==NULL){
        perror("Error creating");
        return -1;
    }
    else{
        for(int i=0;i<N;i++){
            fflush(stdin);
            printf("Name Surname:\n");
            gets(ogr[i].adsoyad);
            printf("Name of the lecture:\n");
            gets(ogr[i].ders);
            printf("Enter the first exam note:\n");
            scanf("%d",&ogr[i].vize1);
            printf("Enter the second exam note:\n");
            scanf("%d",&ogr[i].vize2);
            printf("Final exam:\n");
            scanf("%d",&ogr[i].finalnotu);
            ort=(float)ogr[i].vize1*0.2+(float)ogr[i].vize2*0.2+(float)ogr[i].finalnotu*0.6;
            fprintf(dosya,"%s\t %s\t %d\t %d\t %d\t %.2f\n",ogr[i].adsoyad,ogr[i].ders,ogr[i].vize1,ogr[i].vize2,ogr[i].finalnotu,ort);
        }
        fclose(dosya);
    }
    return 0;
}
