/* londo_hw3.c
 * Laura Londo
 * 24 February 2014
 * HW #3
 *
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <GL/glut.h>
#include <time.h>
#include <string.h>

float WINDOW_SIZE = 700;
int numIters = 2;
float vertices[][3] = {{-0.2,0.2,0.2},	//front outer
						{0.2,0.2,0.2},
						{0.2,-0.2,0.2},
						{-0.2,-0.2,0.2},

						{-0.1,0.1,0.2}, //front inner
						{0.1,0.1,0.2},
						{0.1,-0.1,0.2},
						{-0.1,-0.1,0.2},

						{-0.1,0.1,0.1}, //front inner inner
						{0.1,0.1,0.1},
						{0.1,-0.1,0.1},
						{-0.1,-0.1,0.1}, 	//11

						{-0.2, 0.2,-0.2}, 	//12
						{-0.2,-0.2,-0.2}, 	//13

						{-0.2,0.1,0.1},		//14
						{-0.2,0.1,-0.1},	//15
						{-0.2,-0.1,-0.1},	//16
						{-0.2,-0.1,0.1},	//17

						{0.2,0.2,-0.2},
						{0.2,-0.2,-0.2},

						{0.1,0.1,-0.2},		//20
						{0.1,-0.1,-0.2},
						{-0.1,-0.1,-0.2},
						{-0.1,0.1,-0.2},	//23

						{0.2,0.1,-0.1},		//24
						{0.2,0.1,0.1},		//25
						{0.2,-0.1,0.1},		//26
						{0.2,-0.1,-0.1},	//27

						{0.1,0.1,-0.1},
						{-0.1,0.1,-0.1},
						{-0.1,-0.1,-0.1},
						{0.1,-0.1,-0.1},	//31

						{-0.1,-0.2,-0.1},	//32
						{0.1,-0.2,-0.1},
						{0.1,-0.2,0.1},
						{-0.1,-0.2,0.1},	//35

						{0.1,0.2,0.1},
						{0.1,0.2,-0.1},
						{-0.1,0.2,-0.1},
						{-0.1,0.2,0.1}		//39
						};


//Draw a face as a colored polygon
void face4(int a, int b, int c, int d) {
 	glBegin(GL_POLYGON);
	glVertex3fv(vertices[a]);
	glVertex3fv(vertices[b]);
	glVertex3fv(vertices[c]);
	glVertex3fv(vertices[d]);
	glEnd();
}

//creates a cube-shaped thing
void shape(void) {
	glColor3f(1,0.5,0.5);
	face4(0,4,5,1);
	face4(1,5,6,2);
	face4(6,7,3,2);
	face4(4,0,3,7);

	glColor3f(0.5,1,0.5);
	face4(0,14,17,3);
	face4(0,12,15,14);
	face4(15,12,13,16);
	face4(16,13,3,17);

	glColor3f(0.5,1,1);
	face4(12,23,22,13);
	face4(12,18,20,23);
	face4(20,18,19,21);
	face4(21,19,13,22);

	glColor3f(0.5,0.5,1);
	face4(18,1,25,24);
	face4(1,2,26,25);
	face4(2,19,27,26);
	face4(27,19,18,24);

	glColor3f(1,0.5,1);
	face4(1,36,39,0);
	face4(0,39,38,12);
	face4(12,38,37,18);
	face4(18,37,36,1);

	glColor3f(1,1,0.5);
	face4(32,35,3,13);
	face4(32,13,19,33);
	face4(19,2,34,33);
	face4(2,3,35,34);

	glColor3f(0.9,0.4,0.4);
	face4(5,9,10,6);
	glColor3f(0.7,0.3,0.3);
	face4(6,10,11,7);
	glColor3f(0.5,0.2,0.2);
	face4(7,11,8,4);
	glColor3f(0.3,0.1,0.1);
	face4(4,8,9,5);

	glColor3f(0.4,0.4,0.9);
	face4(26,27,31,10);
	glColor3f(0.3,0.3,0.7);
	face4(27,24,28,31);
	glColor3f(0.2,0.2,0.5);
	face4(28,24,25,9);
	glColor3f(0.1,0.1,0.3);
	face4(25,26,10,9);

	glColor3f(0.4,0.9,0.9);
	face4(21,22,30,31);
	glColor3f(0.3,0.7,0.7);
	face4(22,23,29,30);
	glColor3f(0.2,0.5,0.5);
	face4(23,20,28,29);
	glColor3f(0.1,0.3,0.3);
	face4(28,20,21,31);

	glColor3f(0.4,0.9,0.4);
	face4(30,16,17,11);
	glColor3f(0.3,0.7,0.3);
	face4(30,29,15,16);
	glColor3f(0.2,0.5,0.2);
	face4(15,29,8,14);
	glColor3f(0.1,0.3,0.1);
	face4(14,8,11,17);

	glColor3f(0.9,0.9,0.4);
	face4(10,34,35,11);
	glColor3f(0.7,0.7,0.3);
	face4(11,35,32,30);
	glColor3f(0.5,0.5,0.2);
	face4(32,33,31,30);
	glColor3f(0.3,0.3,0.1);
	face4(34,10,31,33);

	glColor3f(0.9,0.4,0.9);
	face4(39,36,9,8);
	glColor3f(0.7,0.3,0.7);
	face4(39,8,29,38);
	glColor3f(0.5,0.2,0.5);
	face4(29,28,37,38);
	glColor3f(0.3,0.1,0.3);
	face4(36,37,28,9);
}


void display(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	float div = 2.0/(numIters+1);
	float s = 0.3/numIters;
	for (int i=0; i<numIters; i++){
		for(int j=0; j<numIters; j++) {
			glPushMatrix();			//save original position

			//moves the object to the specified coordinates
			glTranslatef((div*(j+1))-1.0, (div*numIters - div*(i))-1.0,0.0);

			glRotatef(i*35,0,1,0);	//rotate on y axis
			glRotatef(j*35,1,0,0);	//rotate on x axis

			float scale = 0.1 + (s*(i+1)) + s*(j+1);	//scale ammount
			glScalef(scale, scale, scale);				//scale object

			shape();				//draw shape
			glPopMatrix();			//pop original position
 		}
 	}
	glutSwapBuffers();
}


//mouse callback.
void mouse(int butt, int state, int x, int y) {
	if (state == GLUT_DOWN   &&   butt == GLUT_LEFT_BUTTON) {	//left click
		numIters ++; //increase number of rows and columns
		if(numIters == 5) numIters = 2;
		glutPostRedisplay();
	}
}

//The keyboard callback
void keyboard(char key, int x, int y) {
	int k = (int)key;
	if (k == 27)					//if the user types ESC
		exit(0);					//exit the program
}

//reshape callback. adjusts both the clipping box and viewport. keeps proportions unchanged
void reshape(int w, int h) {
	float aspectRatio = (float)h / (float)w; 	//Compute the aspect ratio of the resized window
	glViewport(0, 0, w, h); 					//adjust the viewport
	// Adjust the clipping box
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	if (h >= w)
		glOrtho(-1.0, 1.0, -aspectRatio, aspectRatio, -1.0, 1.0);
	else
		glOrtho(-1.0/aspectRatio, 1.0/aspectRatio, -1.0, 1.0, -1.0, 1.0);
	//gluPerspective(60.0, 1.0, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
}


int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA | GLUT_ALPHA);

	glutInitWindowPosition(0,0);					//window position
	glutInitWindowSize(WINDOW_SIZE, WINDOW_SIZE);	//window size
	glutCreateWindow ("circles!!!");				//window name
	glClearColor(0.0, 0.0, 0.0, 0.0);				//background color
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();								// load identity matrix

	glEnable(GL_DEPTH_TEST);						//to remove hidden faces
	glutDisplayFunc(display);
	glutMouseFunc(mouse);
	glutKeyboardFunc(keyboard);
	glutReshapeFunc(reshape);

	glutMainLoop();
  	return 0;
}
