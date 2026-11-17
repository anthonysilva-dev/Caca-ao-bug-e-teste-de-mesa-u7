#include <stdio.h>
#include <math.h>

struct ponto {
    double x, y;
};

int main(void) {
    struct ponto a, b;
    double dist;

    scanf("%lf %lf %lf %lf", &a.x, &a.y, &b.x, &b.y);
    dist = sqrt((b.x - a.x) * (b.x - a.x) + (b.y - a.y) * (b.y - a.y));
    printf("Distancia = %.2f\n", dist);

    return 0;
}
