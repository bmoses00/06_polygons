#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "gmath.h"
#include "matrix.h"
#include "ml6.h"


//vector functions
//normalize vetor, should modify the parameter
void normalize( double *vector ) {
}

//Return the dot porduct of a . b
double dot_product( double *a, double *b ) {
  return a[0] * b[0] + a[1] * b[1] + a[2] * b[2];
}


//Calculate the surface normal for the triangle whose first
//point is located at index i in polygons
double *calculate_normal(struct matrix *polygons, int i) {

  double * new_normal = calloc(100, 1);

  double a[3];
  double b[3];

  a[0] = polygons->m[0][i+1] - polygons->m[0][i+0];
  a[1] = polygons->m[1][i+1] - polygons->m[1][i+0];
  a[2] = polygons->m[2][i+1] - polygons->m[2][i+0];

  b[0] = polygons->m[0][i+2] - polygons->m[0][i+0];
  b[1] = polygons->m[1][i+2] - polygons->m[1][i+0];
  b[2] = polygons->m[2][i+2] - polygons->m[2][i+0];

  new_normal[0] = a[1]*b[2] - a[2]*b[1];
  new_normal[1] = a[2]*b[0] - a[0]*b[2];
  new_normal[2] = a[0]*b[1] - a[1]*b[0];

  return new_normal;
}
