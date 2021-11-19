#include <stdio.h>
#include <math.h>

float readWeight() {
    float w;
    printf("Kilogramy: ");
    if (scanf("%f", &w) == 0 || w < 20 || w > 199 || getchar() != 0x0a) { // NOLINT(cert-err34-c)
        printf("Chyba!\n");
        return 1;
    }
    return w;
}

float readHeight() {
    float h;
    printf("Metry: ");
    if (scanf("%f", &h) == 0 || h < 1 || h > 2.4 || getchar() != 0x0a) { // NOLINT(cert-err34-c)
        printf("Chyba!\n");
        return 1;
    }
    return h;
}

float computeBMI() {
    float w = readWeight(), h = readHeight();
    float bmi = w / powf(h, 2);
    return bmi;
}

int main(void) {
    float bmi = computeBMI();

    if (bmi < 18.5) printf("Mas podvahu!");
    else if (18.5 <= bmi && bmi <= 25) printf("Jsi OK!");
    else printf("Mas nadvahu!");
    printf(" (BMI = %.2f)\n", bmi);

    return 0;
}

