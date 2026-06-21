#include <stdio.h>
#include <math.h>

#define PI 3.14159265

int main() {
    printf("=== MOTEUR DE TRANSFORMATION AFFINE ===\n\n");
    
    float cible_x = 500.0;
    float cible_y = 500.0;
    float angle_derive_deg;

    printf("[IMU] Entrez la derive angulaire detectee (en degres) : ");
    scanf("%f", &angle_derive_deg);

    // 1. Conversion mathématique
    float angle_rad = angle_derive_deg * (PI / 180.0);
    
    // 2. Calcul de la matrice de rotation inverse
    float cos_inv = cos(-angle_rad);
    float sin_inv = sin(-angle_rad);

    printf("\n--- CALCUL MATRICIEL EN COURS ---\n");
    printf("Matrice [ %f   %f ]\n", cos_inv, -sin_inv);
    printf("        [ %f   %f ]\n", sin_inv, cos_inv);

    // 3. Application de la transformation
    float correction_x = (cible_x * cos_inv) - (cible_y * sin_inv);
    float correction_y = (cible_x * sin_inv) + (cible_y * cos_inv);

    printf("\n--- RESULTAT DE LA CORRECTION OPTIQUE ---\n");
    printf("Coordonnees brutes : X = %.2f | Y = %.2f\n", cible_x, cible_y);
    printf("Coordonnees cibles : X = %.2f | Y = %.2f\n", correction_x, correction_y);
    printf("\n[OK] Stabilisation logicielle terminee.\n");

    return 0;
}
