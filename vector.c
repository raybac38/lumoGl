#include "vector.h"
#include "stdlib.h"
#include "stdio.h"

s_vector * LeafVectorInit(void)
{
  return malloc(sizeof(s_vector));
}

s_vector * LeafVectorAdd(s_vector * a, s_vector * b)
{
  s_vector * vector = LeafVectorInit();
  vector->x = a->x + b->x;
  vector->y = a->y + b->y;
  vector->z = a->z + b->z;
  return vector;
}

float LeafVectorDotProduct(s_vector *a, s_vector *b)
{
  return a->x * b-> x + a->y * b->y + a->z * b->z;
}

s_vector * LeafVectorScale(s_vector * a, float scaleFactor)
{
  s_vector * vector = LeafVectorInit();
  vector->x = a->x * scaleFactor;
  vector->y = a->y * scaleFactor;
  vector->z = a->z * scaleFactor;
  return vector;
}

s_vector * LeafVectorOne()
{
  s_vector * vector = LeafVectorInit();
  vector->x = 1.0;
  vector->y = 1.0;
  vector->z = 1.0;
  return vector;
}

void LeafVectorFree(s_vector **a)
{
  free(*a);
  *a = NULL;
  return;
}

void LeafVectorPrint(s_vector *a)
{
  float x = a->x;
  float y = a->y;
  float z = a->z;
  printf("leaf vector { %f, %f, %f}\n", x, y, z);
  return;
}

s_vector * LeafVectorSet(float x, float y, float z)
{
  s_vector * a = LeafVectorInit();
  a->x = x;
  a->y = y;
  a->z = z;
  return a;
}

float LeafVectorGetX(s_vector * a)
{
  return a->x;
}

float LeafVectorGetY(s_vector * a)
{
  return a->y;
}

float LeafVectorGetZ(s_vector * a)
{
  return a->z;
}
