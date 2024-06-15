#include <stdlib.h>
#include <stdio.h>

#include "vector.h"

#ifndef MESH_H
#define MESH_H

typedef struct s_mesh
{
  s_vector ** verticies;
  int size;
  int * triangles;
} s_mesh;

//Function that allow you to set verticies of a mesh
//Will free past verticies
void MeshSetVerticies(s_mesh * mesh, s_vector ** verticies, int size);

//Function that allow you to set triangles of a mesh
//Will free past triangles
void MeshSetTriangles(s_mesh * mesh, int * triangles);

//Function that initialize a mesh
s_mesh * MeshInit(void);

//Function that destroy a mesh
void MeshDestroy(s_mesh ** pointer_mesh);

//Prefab of a mesh
s_mesh * MeshCube(void);

#endif // !MESH_H
