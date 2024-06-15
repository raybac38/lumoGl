#include "./mesh.h"

#ifndef SCENE_H
#define SCENE_H

typedef struct s_mesh_node
{
  struct s_mesh_node * next;
  s_mesh * mesh;
}s_mesh_node;

typedef struct s_scene
{
  struct s_mesh_node * meshs;
  int mesh_number;
}s_scene;

//Initialize a scene
s_scene * SceneInit(void);

//Add a mesh to the scene
void SceneAddMesh(s_scene * scene, s_mesh * mesh);

#endif // !SCENE_H
