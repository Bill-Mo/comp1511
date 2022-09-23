//zID is z5305298
#include <stdio.h>

void sort3(double *x, double *y, double *z);

int main(int argc, char *argv[]) {
  double x, y, z;
  
  scanf("%lf %lf %lf", &x, &y, &z);
  sort3(&x, &y, &z);
  printf("%lf %lf %lf\n", x, y, z);
  
  return 0;
}

void sort3(double *x, double *y, double *z) {
    double max, mid, min;
    if (*x <= *y) {
        if (*x <= *z) {
            min = *x;
            if (*y <= *z) {
                mid = *y;
                max = *z;
            } else {
                mid = *z;
                max = *y;
            }
        } else {
            min = *z;
            mid = *x;
            max = *y;
        }
    } else {
        if (*y <= *z) {
            min = *y;
            if (*z <= *x) {
                mid = *z;
                max = *x;
            } else {
                mid = *x;
                max = *z;
            }
        } else {
            min = *z;
            mid = *y;
            max = *x;
        }
    }
    *x = min;
    *y = mid;
    *z = max;
}
