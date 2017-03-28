// ZKDTB March 17 2017
// Hydroclopse
// This build will implmenet button classes and font handling and maybe hide console.

#include <iostream>

#include "../glad/glad.h"
#include "../GLFW/glfw3.h"
#include "../linmath/linmath.h"

#include <stdlib.h>
#include <stdio.h>

#include "../src/states.hpp"
#include "../src/buttons.hpp"
#include "../src/images.hpp"

bool stateTracker = false;

static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
  if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
    glfwSetWindowShouldClose(window, GLFW_TRUE);
}

void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
{
  if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS)
  {
    stateTracker = (stateTracker) ? false : true;
  }
}

int main(void)
{
  GLFWwindow* window;

  /* Initialize the library */
  if (!glfwInit())
    return -1;
  std::cout << "Library loaded.\n";

  /* Create a windowed mode window and its OpenGL context */
  window = glfwCreateWindow(640, 480, "ZKDTB317", NULL, NULL);
  if (!window)
  {
    glfwTerminate();
    return -1;
  }
  std::cout << "Window created!\n";

  glfwSetKeyCallback(window, key_callback); //Establish the defined callback.
  glfwSetMouseButtonCallback(window, mouse_button_callback); //Mouseclicky!

  /* Make the window's context current */
  glfwMakeContextCurrent(window);
  std::cout << "I demand that you look at the window!\n";

  gladLoadGLLoader((GLADloadproc)glfwGetProcAddress); //Glad does something here.

  glfwSwapInterval(1); //Vsync lol

  /* Loop until the user closes the window AKA main loop.*/
  while (!glfwWindowShouldClose(window))
  {
    if (stateTracker) 
    {
      glClearColor(.25, .25, .25, 1); 
    }
    else 
    {
      glClearColor(.75, .75, .75, 1);
    }

    /* Render here */
    glClear(GL_COLOR_BUFFER_BIT);

    /* Swap front and back buffers */
    glfwSwapBuffers(window);

    /* Poll for and process events */
    glfwPollEvents();
  }

  /*Remove the window object*/
  glfwDestroyWindow(window);
  std::cout << "Destroying window.\n";

  /*Stop the api*/
  glfwTerminate();
  std::cout << "Closing down the API\n";

  system("Pause");

  return 0;
}