#include <stdio.h>
#include <string.h>
#include <math.h>
#include<GL/glut.h>
#include<GL/gl.h>
#include<GL/glu.h>

float xmin,ymin,xmax,ymax;

float max(float c,float d)
{
	if(c>d)
	{	return c;}
	else
	{	return d;}
}

float min(float c,float d)
{
	if(c<d)
	{	return c;}
	else
	{	return d;}
}

void lbalgo(float xi,float yi,float xf,float yf)
{
	float x1=xi,y1=yi,x2=xf,y2=yf;
	float dx=x2-x1, dy=y2-y1;
	float t1=0,t2=1;
	float xa,ya,xb,yb,xc,yc,xd,yd;
	
	float p[]={(-1)*dx,dx,(-1)*dy,dy};
	float q[]={x1-xmin,xmax-x1,y1-ymin,ymax-y1};
	float r[]={0,0,0,0};
	glBegin(GL_LINES);

	for(int i=0;i<4;i++)
	{
		r[i]=q[i]/p[i];
	}

	for(int i=0;i<4;i++)
	{
		if(p[i]<0)
		{
			t1=max(r[i],t1);		
		}
		if(p[i]>0)
		{
			t2=min(r[i],t2);
		}
	}

			
	xa=x1+(dx*t1);	
	ya=y1+(dy*t1);	
	xb=x1+(dx*t2);
	yb=y1+(dy*t2);	
	if((p[0]!=0)&&(p[2]!=0))
	{
		glVertex2f(xa,ya);
		glVertex2f(xb,yb);
	}
	if(p[0]==0)
	{
		if(q[0]>0)
		{			
			glVertex2f(q[0]-10,ya);
			glVertex2f(q[0]-10,yb);
		}
	}	
	if(p[2]==0)
	{
		if(q[2]>0)
		{
			glVertex2f(xa,q[2]-10);
			glVertex2f(xb,q[2]-10);
		}
	}

	glEnd();
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
	glBegin(GL_LINES);
	glVertex2f(0, -200);
	glVertex2f(0, 200);

	glVertex2f(200, 0);
	glVertex2f(-200, 0);

	glVertex2f(100, -20);
	glVertex2f(-200, 80);

	glVertex2f(-20,-20);
	glVertex2f(40, 80);

	glVertex2f(-20,80);
	glVertex2f(-20,-20);

	glVertex2f(40,40);
	glVertex2f(100,40);
	glVertex2f(40,40);
	glVertex2f(40,80);
	glVertex2f(40,25);
	glVertex2f(85,25);

	glColor3f(1, 0, 1);
	glVertex2f(xmax, ymax);
	glVertex2f(xmax, ymin);

	glVertex2f(xmax, ymax);
	glVertex2f(xmin, ymax);

	glVertex2f(xmin, ymin);
	glVertex2f(xmax, ymin);

	glVertex2f(xmin, ymin);
	glVertex2f(xmin, ymax);	
	glEnd();

	glColor3f(0,1,1);
	lbalgo(-20,-20,40,80);
	lbalgo(-200,80,100,-20);
	lbalgo(-20,80,-20,-20);
	lbalgo(40,40,100,40);
	lbalgo(40,40,40,80);
	lbalgo(40,25,85,25);
	glFlush();
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(600, 600);
	glutCreateWindow("Liang-Barsky Algorithm");
	printf("Enter (x,y)min for the clipping window");
	scanf("%f",&xmin);
	scanf("%f",&ymin);
	printf("Enter (x,y)max for the clipping window");
	scanf("%f",&xmax);
	scanf("%f",&ymax);
	glutDisplayFunc(display);
	glutMainLoop();

	return 0;
}
