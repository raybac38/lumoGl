#include "./mesh.h"
#include <cstdio>
#include <cstdlib>

void MeshRemoveVerticies(s_mesh * mesh);
void MeshRemoveTriangles(s_mesh * mesh);


void MeshRemoveTriangles(s_mesh * mesh)
{
  free(mesh->triangles);
  return;
}

void MeshSetVerticies(s_mesh * mesh, s_vector ** verticies, int size)
{
  if(mesh->verticies != NULL)
  {
    MeshRemoveVerticies(mesh);
  }
  mesh->verticies = verticies;
  mesh->size = size;
}

void MeshRemoveVerticies(s_mesh * mesh)
{
  s_vector ** pointer = mesh->verticies;
  for (int i = 0; i < mesh->size; i++) {
    free(*pointer);
    pointer ++;
  }
  mesh->verticies = NULL;
  return;
}

void MeshSetTriangles(s_mesh * mesh, int * triangles)
{
  if(mesh->triangles != NULL)
  {
    MeshRemoveTriangles(mesh);
  }
  mesh->triangles = triangles;
}

s_mesh * MeshInit()
{
  s_mesh * mesh = malloc(sizeof(s_mesh));
  mesh->triangles = NULL;
  mesh->verticies = NULL;
  mesh->size = 0;
  return mesh;
}

void MeshDestroy(s_mesh ** pointer_mesh)
{
  s_mesh * mesh = * pointer_mesh;
  
  if(mesh->triangles != NULL)
  {
    MeshRemoveTriangles(mesh);
  }
  if(mesh->verticies != NULL)
  {
    MeshRemoveVerticies(mesh);
  }
  free(mesh);
  *pointer_mesh = NULL;
  return;
}

s_mesh * MeshCube()
{
  s_mesh * mesh = MeshInit();

  s_vector ** vectors = malloc(sizeof(s_vector *) * 8);

  if(vectors == NULL)
  {
    printf(stderr, "Unable to allocate memory\n");
    exit(EXIT_FAILURE);
  }


  vectors[0] = LeafVectorSet(0, 0, 0);
  vectors[1] = LeafVectorSet(1, 0, 0);
  vectors[2] = LeafVectorSet(1, 1, 0);
  vectors[3] = LeafVectorSet(0, 1, 0);
  vectors[4] = LeafVectorSet(0, 0, 1);
  vectors[5] = LeafVectorSet(1, 0, 1);
  vectors[6] = LeafVectorSet(1, 1, 1);
  vectors[7] = LeafVectorSet(0, 1, 1);

  MeshSetVerticies(mesh, vectors, 8);

  int triangles[36] = {
    0, 1, 2, 0, 2, 3,
    4, 5, 6, 4, 6, 7,
    0, 3, 7, 0, 7, 4,
    1, 5, 6, 1, 6, 2,
    3, 2, 6, 3, 6, 7,
    0, 1, 5, 0, 5, 4
  };

  int * index_triangle = malloc(sizeof(int) * 36);

  if(index_triangle == NULL)
  {
    printf(stderr, "Unable to allocate memory\n");
    exit(EXIT_FAILURE);
  }

  for (int i = 0; i < 36; i++) {
    index_triangle[i] = triangles[i];  
  }

  MeshSetTriangles(mesh, index_triangle);

  return mesh;
}
