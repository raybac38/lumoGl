#include <stdio.h>
#include <stdlib.h>
#include "../vector.h"

int main(int argc, char ** argv)
{
  printf("Lancement de la phase de teste du module vector\n");

  if(argc != 7)
  {
    //nombre d'argument invalide
    //
    printf("Nombre d'argument invalide\n");
    printf("Ax Ay Az Bx By Bz\n");
    
    exit(EXIT_FAILURE);
  }

  s_vector * a = LeafVectorSet(
    atof(argv[1]), 
    atof(argv[2]), 
    atof(argv[3])
  );
  s_vector * b = LeafVectorSet(
    atof(argv[4]),
    atof(argv[5]),
    atof(argv[6])
  );

  printf("Les deux vecteurs sont :\na ");
  LeafVectorPrint(a);
  printf("b ");
  LeafVectorPrint(b);

  s_vector * c = LeafVectorAdd(a, b);
  printf("La somme vaut : ");
  LeafVectorPrint(c);
  LeafVectorFree(&c);

  printf("Bx * a : ");
  c = LeafVectorScale(a, atof(argv[4]));
  LeafVectorPrint(c);
  LeafVectorFree(&c);


  printf("Le produit scalaire de a : %f \n", LeafVectorDotProduct(a, b));

  LeafVectorFree(&a);

  LeafVectorFree(&b);
}
