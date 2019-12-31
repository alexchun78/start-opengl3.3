#include "Class Files\glfwFunc.h"

int main(int argc, char** argv)
{
	glfwFunc glfwFunc(SCR_WIDTH, SCR_WIDTH, "DEMO");

	// glad 설정
	glfwFunc.GladInit();

	// viewport 설정
	bool bRtn = glfwFunc.SetViewPortWithFrameBufferSize();
	if (bRtn == false) return -1;
	
	// rendering loop 설정
	while (glfwFunc.WindowTerminate()== false)
	{
		// 종료 버튼 클릭시 종료 
		bRtn = glfwFunc.CloseKeyPress();
		if (bRtn == false) return -1;	

		// TODO : rendering command
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		// buffer swap & poll event
		bRtn = glfwFunc.PostProcessInRendingLoop();
		if (bRtn == false) return -1;
	}

	glfwFunc.TerminateGLFW();

	return 0;
}