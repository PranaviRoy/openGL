#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<GL/glut.h>
#include<GL/gl.h>
#include<GL/glu.h>

int id,l,n=0,len,l2,xi,yi;

void drawo(float x1,float y1,float x2,float y2);
void draw5(float a[],float b[])
{
	glBegin(GL_LINE_STRIP);
	glColor3f(0.38+(0.0001*n),0.11+(0.0001*n),0.89-(0.0001*n));

	for(int i=0;i<6;i++)
	{

		glVertex2f(a[i],b[i]);
	}
	glEnd();

	if(l>21)
	{

		for(int i=0;i<5;i++)
		{
			drawo(a[i],b[i],a[i+1],b[i+1]);
			drawo(a[i+1],b[i+1],a[i],b[i]);
		}
	}
	glFlush();
}

void drawo(float x1,float y1,float x2,float y2)
{
	n++;
	if(y1==y2)
	{
		if(x2>x1)
			l=x2-x1;
		else
			l=x1-x2;
		float nl=l/3;
		if(x2>x1)
		{
			float hx[]={x1,x1+nl,x1+nl,x2-nl,x2-nl,x2};
			float hy[]={y1,y1,y1+nl,y2+nl,y2,y2};
	
			draw5(hx,hy);
		}
		else
		{
			float hx[]={x1,x1-nl,x1-nl,x2+nl,x2+nl,x2};
			float hy[]={y1,y1,y1-nl,y2-nl,y2,y2};
	
			draw5(hx,hy);
		}
	}
	else
	{	
		if(y2>y1)
			l=y2-y1;
		else
			l=y1-y2;
		float nl=l/3;

		if(y1<y2)
		{
			float hx[]={x1,x1,x1-nl,x2-nl,x2,x2};
			float hy[]={y1,y1+nl,y1+nl,y2-nl,y2-nl,y2};

			draw5(hx,hy);
		}
		else
		{
			float hx[]={x1,x1,x1+nl,x2+nl,x2,x2};
			float hy[]={y1,y1-nl,y1-nl,y2+nl,y2+nl,y2};

			draw5(hx,hy);
		}			
	
	}
//	drawo(x2,y2,x1,y1);
	glFlush();

}

void display(void)
{
	glClearColor(0, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);

	glLoadIdentity();
	gluOrtho2D(-300.0, 300.0, -300.0, 300.0);
	glColor3f(1, 1, 1);
	l2=len/2;
	glBegin(GL_LINE_LOOP);
	glVertex2f(l2,l2);
	glVertex2f(l2,-l2);
	glVertex2f(-l2,-l2);
	glVertex2f(-l2,l2);
	glEnd();
		drawo(l2,l2,l2,-l2);
		drawo(l2,-l2,-l2,-l2);
		drawo(-l2,-l2,-l2,l2);
		drawo(-l2,l2,l2,l2);
		drawo(l2,-l2,l2,l2);
		drawo(-l2,-l2,l2,-l2);
		drawo(-l2,l2,-l2,-l2);
		drawo(l2,l2,-l2,l2);
	glFlush();
}

void myKeyboardFunc(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 27: // Escape key
		glutDestroyWindow(id);
		break;
/*	case 102: //ascii value of f
		drawo(l2,l2,l2,-l2);
		drawo(l2,-l2,-l2,-l2);
		drawo(-l2,-l2,-l2,l2);
		drawo(-l2,l2,l2,l2);
		drawo(l2,-l2,l2,l2);
		drawo(-l2,-l2,l2,-l2);
		drawo(-l2,l2,-l2,-l2);
		drawo(l2,l2,-l2,l2);
		glFlush();
		break; 		*/
	}
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(600, 600);
	id=glutCreateWindow("Fractals");

	printf("Enter the length of the square.(<300)");
	scanf("%d",&len);
	glutDisplayFunc(display);
	glutKeyboardFunc(myKeyboardFunc);
	glutMainLoop();

	return 0;
}
