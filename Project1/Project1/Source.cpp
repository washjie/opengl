#include <iostream>
#include <glad\glad.h>
#include <GLFW\glfw3.h>

void framebuffer_size_callback(GLFWwindow* window, int width, int height);

int main()
{
	/*glfw initialization*/
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	/*window creation*/
	GLFWwindow * window = glfwCreateWindow(800, 600, "opengl", NULL, NULL);
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);


	/*glad initialization*/
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return -1;
	}

	/*
	tell opengl the size of the rendering window, so that opengl knows how 
	we want to display the data and coordinates with respect to the window
	*/
	glViewport(0, 0, 800, 600);
	/*
	window's callback function must be registered 
	after the creation of the window and
	before the game loop
	*/
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	/*our rendering loop*/
	while(!glfwWindowShouldClose(window))
	{
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	
	return 0;
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}