#include <stdio.h>
#include <stdlib.h>
#include <GL/glew.h>
#include <GL/freeglut.h>

GLuint VBO, VAO, EBO;

GLfloat verticies[] = {
	-1.0f, -1.0f, 0.0f,
	1.0f, -1.0f, 0.0f,
	0.0f, 1.0f, 0.0f,
};

GLuint triangles[] = 
  {
    0, 1, 2
  };

void UpdateVerticies(void)
{
 verticies[0] += 0.05f;
  printf("mouvement \n");
  glBindBuffer(GL_ARRAY_BUFFER, VBO);
  glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(verticies), verticies);
}


void display() {
	glClearColor(0, 0, 0, 1);
	glClear( GL_COLOR_BUFFER_BIT );
  
  UpdateVerticies();

  glBindVertexArray(VAO);
  glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
  glutSwapBuffers(); 
}

void init()
{
  glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);

    // Generate and bind Vertex Buffer Objec_
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(verticies), verticies, GL_STATIC_DRAW);

    // Generate and bind Element Buffer Object
    glGenBuffers(1, &EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(triangles), triangles, GL_STATIC_DRAW);

    // Define the layout of the vertex data
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
}

void idle()
{
  glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(512, 512);
    //glutInitContextVersion(4, 3);
    //glutInitContextProfile(GLUT_CORE_PROFILE);
    glutCreateWindow("Leaf");

    if (glewInit() != GLEW_OK) {
        fprintf(stderr, "Unable to initialize GLEW ... exiting\n");
        exit(EXIT_FAILURE);
    }

  init();

  glutDisplayFunc(display);
  glutIdleFunc(idle);
  glutMainLoop();

  printf("Clean up\n");

  glDeleteVertexArrays(1, &VAO);
  glDeleteBuffers(1, &VBO);
  glDeleteBuffers(1, &EBO);

    return 0;
}
