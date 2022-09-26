#include <stdlib.h>
#include <glut/glut.h>
#include <cmath>
#define c 3e8
#define pi 3.1416
#define WINDOW_WIDTH 700
#define WINDOW_HEIGHT 700
#define WINDOW_POS_X 500
#define WINDOW_POS_Y 100

//double F3(float theta, float phi);
/*double F2(float phi, double lambda, float D, int N);*/

void display();

int main(int argc, char** argv)
{
// 	int N = 8;
// 	float D = 0.3;
// 	double frequence = 5e8;
// 	double lambda = c / frequence;


	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	glutInitWindowPosition(WINDOW_POS_X, WINDOW_POS_Y);
	glutCreateWindow("Diagram");
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-100, 100, -100, 100, 100, 2000);
	glMatrixMode(GL_MODELVIEW);
	//glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
	glTranslatef(-50, 50, -400);
	glRotatef(340, 1, 1, 0);
	glutDisplayFunc(display);
	glutMainLoop();

	return 0;
}


// double F3(float theta, float phi)
// {
// 	return 
// }

// double F2(float phi, double lambda, float D, int N)
// {
// 	return sin(N*pi / lambda*D*sin(phi))/(pi / lambda*D*sin(phi));
// }


void display()
{
	int N = 8;
	float D = 0.3;
	double frequence = 5e8;
	double lambda = c / frequence;

	glClear(GL_COLOR_BUFFER_BIT);

	for (float x = -500; x < 500; x += 10)
	{
		glBegin(GL_LINE_STRIP);
		glColor3f(0.0, 0.0, 0.0);
		for (float y = -500; y < 500; y += 10)
			glVertex3f(x, y, sin(N*D*pi / lambda*sin(x)*cos(y)) / (D*pi / lambda*sin(x)*cos(y))*sin(N*D*pi / lambda*cos(x)*sin(y)) / (D*pi / lambda*cos(x)*sin(y)));
		glEnd();
	}

	for (float y = -500; y < 500; y += 10)
	{
		glBegin(GL_LINE_STRIP);
		glColor3f(0.0, 0.0, 0.0);
		for (float x = -500; x < 500; x += 10)
			glVertex3f(x, y, sin(N*D*pi / lambda*sin(x)*cos(y)) / (D*pi / lambda*sin(x)*cos(y))*sin(N*D*pi / lambda*cos(x)*sin(y)) / (D*pi / lambda*cos(x)*sin(y)));
		glEnd();
	}

// 	glBegin(GL_LINE_LOOP);
// 	glColor3f(0.0, 0.0, 0.0);
// 
// 	for (float phi = -1.0; phi <= 1.0; phi += 0.01)
// 	{
// 		glColor3f(0.0, 0.0, 0.0);
// 		glVertex2d(phi, sin(N*pi / lambda*D*sin(phi)) / (pi / lambda*D*sin(phi))/8);
// 	}
// 	
// 	glEnd();

	glutSwapBuffers();
}