#include "glfwFunc.h"


glfwFunc::glfwFunc()
{
	m_pWindow = nullptr;
	m_uiWidth = 0;
	m_uiHeight = 0;
}

glfwFunc::glfwFunc(unsigned int width, unsigned int height, const char* windowName)
{
	// glfw 초기화
	Internal_GlfwInit();

	// window 객체 생성
	m_uiWidth = width;
	m_uiHeight = height;
	Internal_CreateGlfwWindow(windowName);
}

glfwFunc::~glfwFunc()
{
}

void glfwFunc::Internal_GlfwInit()
{
	// glfw 초기화
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

void glfwFunc::Internal_CreateGlfwWindow(const char* windowName)
{
	// window 객체 생성
	m_pWindow = glfwCreateWindow(m_uiWidth, m_uiHeight, windowName, nullptr, nullptr);
	if (m_pWindow == nullptr)
	{
		std::cout << "failed to create GLFW window" << std::endl;
		glfwTerminate();
		return;
	}
	glfwMakeContextCurrent(m_pWindow);
}

void glfwFunc::GladInit()
{
	//glad 초기화 
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "failed to initialize GLAD" << std::endl;
		return;
	}
}

bool glfwFunc::CloseKeyPress()
{
	if (m_pWindow == nullptr)
		return false;

	if (glfwGetKey(m_pWindow, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(m_pWindow, true);

	return true;
}

bool glfwFunc::SetViewPortWithFrameBufferSize()
{
	if (m_pWindow == nullptr)
		return false;

	glfwSetFramebufferSizeCallback(m_pWindow, framebuffer_size_callback);

	return true;
}

bool glfwFunc::WindowTerminate()
{
	if (m_pWindow == nullptr)
		return true; // 예외일 경우, 윈도우를 닫아야 하므로 true임.

	if (glfwWindowShouldClose(m_pWindow) == true)
		return true;

	return false;
}

bool glfwFunc::PostProcessInRendingLoop()
{
	if (m_pWindow == nullptr)
		return false;

	// 이벤트 확인하고 버퍼 교체
	glfwPollEvents();
	glfwSwapBuffers(m_pWindow);
	return true;
}

void glfwFunc::TerminateGLFW()
{
	glfwTerminate();
}