#include <stdlib.h>
#include <stdio.h>

#include "./scene.h"

s_scene * SceneInit()
{
  s_scene * scene = malloc(sizeof(s_scene));
  if(scene == NULL)
  {
    printf(stderr, "Unable to allocate memory\n");
    exit(EXIT_FAILURE);
  }
  scene->meshs = NULL;

  return scene;
}

void SceneAddMesh(s_scene * scene, s_mesh * mesh)
{
  s_mesh_node * node = malloc(sizeof(s_mesh_node));
  if(node == NULL)
  {
    printf(stderr, "Unable to allocate memory\n");
    exit(EXIT_FAILURE);
  }

  node->mesh = mesh;
  node->next = scene->meshs;
  scene->meshs = node;

  return;
}



