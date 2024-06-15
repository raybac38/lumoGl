
#ifndef VECTOR_H
#define VECTOR_H

typedef struct s_vector
{
  float x;
  float y;
  float z;
}s_vector;

s_vector * LeafVectorAdd(s_vector * a, s_vector * b);

float LeafVectorDotProduct(s_vector * a, s_vector * b);

s_vector * LeafVectorScale(s_vector * a, float scaleFactor);

s_vector * LeafVectorOne(void);

s_vector * LeafVectorInit(void);

void LeafVectorFree(s_vector ** a);

void LeafVectorPrint(s_vector * a);

s_vector * LeafVectorSet(float x, float y, float z);

float LeafVectorGetX(s_vector * a);
float LeafVectorGetY(s_vector * a);
float LeafVectorGetZ(s_vector * a);

#endif
