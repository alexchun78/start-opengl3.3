#include "Class Files\glfwFunc.h"

int main(int argc, char** argv)
{
	glfwFunc glfwFunc(SCR_WIDTH, SCR_WIDTH, "DEMO");

	// glad ����
	glfwFunc.GladInit();

	// viewport ����
	bool bRtn = glfwFunc.SetViewPortWithFrameBufferSize();
	if (bRtn == false) return -1;
	
	// rendering loop ����
	while (glfwFunc.WindowTerminate()== false)
	{
		// ���� ��ư Ŭ���� ���� 
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