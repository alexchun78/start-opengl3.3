#pragma once
#include "..\Header Files\Config.h"

class glfwFunc
{
public:
	glfwFunc();
	glfwFunc(unsigned int width, unsigned int height, const char* windowName);
	~glfwFunc();

	void GladInit();
	bool CloseKeyPress();
	bool SetViewPortWithFrameBufferSize();
	bool WindowTerminate();
	bool PostProcessInRendingLoop();
	void TerminateGLFW();

protected:
	void Internal_GlfwInit();
	void Internal_CreateGlfwWindow(const char* windowName);

public:
	GLFWwindow* m_pWindow;

private:
	unsigned int m_uiWidth, m_uiHeight;
};

static void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
}