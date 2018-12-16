#include <stdio.h>
#include <string.h>
#include <math.h>
#include<GL/glut.h>
#include<GL/gl.h>
#include<GL/glu.h>

float xa,ya,xb,yb;
int id;

void linebrsnm(float xi, float yi, float xf, float yf)
{
	float dx = (xf - xi), dy = (yf - yi);
	float slope = dy / dx;
	float x, y, xlast, ylast;


	glBegin(GL_POINTS);
	float p = 2 * dy - dx;
	float q = -(2 * dx + dy);

	if(dx==0)			//lines parallel to y-axis
	{
		if(yi<yf)
		{
			y=yi;
			x=xi;
			glColor3f(0,0,1);
			for(int i=0;i<abs(dy);i++)
			{
				glVertex2f(x, y);
				y++;
			}
		}
		else
		{
			y=yf;
			x=xf;
			glColor3f(0,0,1);
			for(int i=0;i<abs(dy);i++)
			{
				glVertex2f(x, y);
				y++;
			}
		}
	}
	else if(dy==0)			//lines parallel to x-axis
	{
		if(xi<xf)
		{
			y=yi;
			x=xi;
			glColor3f(0,0,1);
			for(int i=0;i<abs(dx);i++)
			{
				glVertex2f(x, y);
				x++;
			}
		}
		else
		{
			y=yf;
			x=xf;
			glColor3f(0,1,0);
			for(int i=0;i<abs(dx);i++)
			{
				glVertex2f(x, y);
				x++;
			}
		}
	}
	else if(abs(dx)>abs(dy))
	{
		if(xi<xf)
		{
			x=xi;
        		y=yi;
			xlast=xf;
			if(yi<yf)			//octant 1
			{
				glColor3f(1,0,0);
        			glVertex2f(x, y);
        			while(x<xlast)
        			{
         			 	x++;
          			 	if(p<0)
           			 		p+=2*dy;
         			 	else
          				{
           				 	y++;
            				 	p+=2*(dy-dx);
          				}
          				glVertex2f(x, y);
       			 	}	
			}
			else				//octant 8
			{
				glColor3f(1,1,0);
        			glVertex2f(x, y);
        			while(x<xlast)
        			{
         			 	x++;
          			 	if(p<0)
           			 		//p+=2*(dy+dx);
						p-=2*dy;
         			 	else
          				{
           				 	y--;
            				 	//p+=2*dy;
						p-=2*(dy+dx);
          				}
          				glVertex2f(x, y);
       			 	}
			}
		}
		else
		{
			x=xf;
        		y=yf;
			xlast=xi;
			if(yi<yf)			//octant 4
			{
				glColor3f(0,1,1);
        			glVertex2f(x, y);
        			while(x<xlast)
        			{
         			 	x++;
          			 	if(p<0)
           			 		p+=2*dy;
         			 	else
          				{
           				 	y--;
            				 	p+=2*(dy+dx);
          				}
          				glVertex2f(x, y);
       			 	}	
			}
			else				//octant 5
			{
				glColor3f(1,0,1);
        			glVertex2f(x, y);
        			while(x<xlast)
        			{
         			 	x++;
          			 	if(p<0)
           			 		//p-=2*(dy-dx);
						p-=2*dy;
         			 	else
          				{
           				 	y++;
            				 	//p-=2*dy;
						p-=2*(dy-dx);
          				}
          				glVertex2f(x, y);
       			 	}
			}
		}
	}
	else
	{
		if(yi<yf)
		{
			x=xi;
        		y=yi;
			ylast=yf;
			if(xi<xf)			//octant 2
			{
				glColor3f(0.5,0,1);
        			glVertex2f(x, y);
        			while(y<ylast)
        			{
         			 	y++;
          			 	if(q<0)
           			 		q+=2*dx;
         			 	else
          				{
           				 	x++;
            				 	q+=2*(dx-dy);
          				}
          				glVertex2f(x, y);
       			 	}	
			}
			else				//octant 3
			{
				glColor3f(1,0.5,0);
        			glVertex2f(x, y);
        			while(y<ylast)
        			{
         			 	y++;
          			 	if(q<0)
           			 		//q+=2*(dy+dx);
						q-=2*dx;
         			 	else
          				{
           				 	x--;
            				 	//q+=2*dx;
						q-=2*(dy+dx);
          				}
          				glVertex2f(x, y);
       			 	}
			}
		}
		else
		{
			x=xf;
        		y=yf;
			ylast=yi;
			if(xi<xf)			//octant 7
			{
				glColor3f(0.5,0.5,0);
        			glVertex2f(x, y);
        			while(y<ylast)
        			{
         			 	y++;
          			 	if(q<0)
           			 		q+=2*dx;
         			 	else
          				{
           				 	x--;
            				 	q+=2*(dy+dx);
          				}
          				glVertex2f(x, y);
       			 	}	
			}
			else				//octant 6
			{
				glColor3f(0,0.5,0.5);
        			glVertex2f(x, y);
        			while(y<ylast)
        			{
         			 	y++;
          			 	if(q<0)
						q-=2*dx;
         			 	else
          				{
           				 	x++;
						q-=2*(dx-dy);
          				}
          				glVertex2f(x, y);
       			 	}
			}
		}
	}

	glEnd();
	glFlush();
}


void drawBitmapText(char *menu, int o, int p)
{
	glRasterPos2i(o, p);
	for (int i = 0; i < strlen(menu); ++i)
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, menu[i]);
	}
	glFlush();
}

void myMouseFunc(int button, int state, int x, int y)
{
	if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		xa = x-300;
		ya = 300-y;
	}
	else if(button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
		xb = x-300;
		yb = 300-y;
	        linebrsnm(xa,ya,xb,yb);	
	}
	
}

void myKeyboardFunc(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 27: // Escape key
		glutDestroyWindow(id);
		//exit(0);
		break;
	}
}

void line(void)
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
	glEnd();

	glColor3f(1, 1, 1);
	glBegin(GL_LINES);
	glVertex2f(200, 0);
	glVertex2f(-200, 0);
	glEnd();
	glFlush();
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(600, 600);
	id = glutCreateWindow("Bresenham's");

	glutDisplayFunc(line);
	glutMouseFunc(myMouseFunc);
	glutKeyboardFunc(myKeyboardFunc);
	glutMainLoop();

	return 0;
}
