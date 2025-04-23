#include <stdio.h>
#include <stdlib.h>

int main() {
    int *dizi;
    int boyut, yeniBoyut;

    printf("Dizinin eleman sayisini giriniz: ");
    scanf("%d", &boyut);

    // malloc ile dinamik dizi oluþturma
    dizi = (int *)malloc(boyut * sizeof(int));

    if (dizi == NULL) {
        printf("Bellek tahsisi basarisiz!\n");
        return 1;
    }

    for (int i = 0; i < boyut; i++) {
        dizi[i] = i * 10;
    }

    printf("Ilk dizi:\n");
    for (int i = 0; i < boyut; i++) {
        printf("%d ", dizi[i]);
    }
    printf("\n");

    // realloc ile boyutu artýr
    printf("Yeni eleman sayisi: ");
    scanf("%d", &yeniBoyut);

    int *yenidizi = (int *)realloc(dizi, yeniBoyut * sizeof(int));

    if (yenidizi == NULL) {
        printf("Bellek yeniden tahsisi basarisiz!\n");
        free(dizi); // eskiyi temizle
        return 1;
    }

    dizi = yenidizi;

    for (int i = boyut; i < yeniBoyut; i++) {
        dizi[i] = i * 10;
    }

    printf("Guncellenmis dizi:\n");
    for (int i = 0; i < yeniBoyut; i++) {
        printf("%d ", dizi[i]);
    }
    printf("\n");

    // belleði serbest býrak
    free(dizi);

    return 0;
}
