#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<GL/glut.h>
#include<GL/gl.h>
#include<GL/glu.h>

int id; 

float fact(float d)
{
	if(d==0)
		return 1;
	else
		return d*fact(d-1);
}
void bezier(int a[][2])
{
	float deg=3;
	float n=fact(3);
	float t=0,j[4];
	float p[]={0,0};
	glBegin(GL_POINTS);
	while(t<=1)
	{

		p[0]=(a[0][0]*(1-t)*(1-t)*(1-t))+(a[1][0]*3*t*(1-t)*(1-t))+(a[2][0]*3*t*t*(1-t))+(a[3][0]*t*t*t);
		p[1]=(a[0][1]*(1-t)*(1-t)*(1-t))+(a[1][1]*3*t*(1-t)*(1-t))+(a[2][1]*3*t*t*(1-t))+(a[3][1]*t*t*t);
		glVertex2f(p[0],p[1]);		
		t+=0.001;
	}

	glEnd();
	glFlush();	
}
void blefunc(int a[][2])
{
	float deg=3;
	float n=fact(3);
	float t=0,j[4];
	float p[]={0,0};
	glBegin(GL_POINTS);
	while(t<=1)
	{

		p[0]=(a[0][0]*(1-t)*(1-t)*(1-t))+(a[1][0]*3*t*(1-t)*(1-t))+(a[2][0]*3*t*t*(1-t))+(a[3][0]*t*t*t);
		p[1]=(a[0][1]*(1-t)*(1-t)*(1-t))+(a[1][1]*3*t*(1-t)*(1-t))+(a[2][1]*3*t*t*(1-t))+(a[3][1]*t*t*t);
		glVertex2f(p[0],p[1]);
		glVertex2f(-1*p[0],p[1]);		
		t+=0.001;
	}

	glEnd();
	glFlush();	
}
void pen(void);
void display(void)
{
	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);

	glLoadIdentity();
	gluOrtho2D(-300.0, 300.0, -300.0, 300.0);
	glColor3f(1, 1, 1);
	int c[4][2]={{110,20},{60,50},{40,180},{20,90}};

	pen();
	glFlush();
}
void pen(void)					//drawing apple
{
	int d[][2]={{-50,150},{-20,140},{20,140},{50,150}};
	int e[][2]={{50,150},{100,200},{150,130},{190,100}};
	glColor3f(1,0,0);
	int f[][2]={{0,-110},{20,-110},{50,-150},{80,-130}};
	int g[][2]={{80,-130},{110,-110},{150,-50},{130,30}};
	int h[][2]={{130,30},{110,110},{60,80},{50,70}};
	int i[][2]={{50,70},{40,60},{20,50},{0,50}};
	int j[][2]={{-5,40},{-10,90},{20,110},{40,100}};
	int k[][2]={{2,40},{-8,90},{30,110},{40,90}};
	int l[][2]={{40,100},{42,95},{45,95},{40,90}};
	int m[][2]={{-10,40},{-30,30},{20,30},{7,40}};

	blefunc(g);
	blefunc(f);
	blefunc(h);
	blefunc(i);
	glColor3f(0.01,0.39,0.01);
	bezier(j);
	bezier(k);
	bezier(l);
	glColor3f(0.67,0.39,0.28);
	bezier(m);
	glFlush();
}
void myKeyboardFunc(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 27: // Escape key
		glutDestroyWindow(id);
		break;
	}
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(600, 600);
	id=glutCreateWindow("Bezier Curve");

	glutDisplayFunc(display);
	glutKeyboardFunc(myKeyboardFunc);
	glutMainLoop();

	return 0;
}
