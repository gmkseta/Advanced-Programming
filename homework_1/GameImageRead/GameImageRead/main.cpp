#include "GL\glut.h"
#include <GL\GL.h>
#include <GL\GLU.h>
#include <glaux.h>    //텍스쳐 파일 불러오는데 필요한 라이브러리
#pragma comment(lib, "glaux.lib")

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

	glutInitWindowSize(600, 700);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("1945 OpenGL");
	glClearColor(0.0, 0.0, 0.0, 1.0);

	//OpenGL 셋팅
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 60.0, 0.0, 70.0, -30.0, 30.0);

	glClearDepth(1.0f);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);

	glEnable(GL_TEXTURE_2D);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	glutDisplayFunc(Render);
	glutKeyboardFunc(MyKeyboard);
	glutIdleFunc(FrameMove);

	glutMainLoop();

	return 0;
}


출처: http://pros2.tistory.com/85 [ProS2]