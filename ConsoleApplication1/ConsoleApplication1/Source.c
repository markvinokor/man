#include <stdio.h>  
#include <stdlib.h>  
#include <math.h>  
#include <glut.h>  
#include <stdbool.h>
//***********************מקשים לתכנית******************************
//ואז להשתמש בפקודות המקלדת r אם הפעלת את אחד התכניות של העכבר יש ללחוץ על ********************
//******************************************************************
//.......................q=הזזת רגל שמאל...........................
//.......................w=הזזת רגל ימין...........................
//.......................z=הזזת יד שמאל............................
//.......................x=הזזת יד ימין............................
//.......................s=לעצור טיימר.............................
//.......................r=אתחול התכנית להתחלה....................
//.................חץ למעלה=תנועה למעלה של כל הגוף...............
//.................חץ למטה=תנועה למטה של כל הגוף.................
//.................חץ ימינה=תנועה ימינה של כל הגוף...............
//.................חץ שמאלה=תנועה שמאלה של כל הגוף...............
//******************************************************************
//ואז להשתמש בפקודות העכבר r אם הפעלת את אחד התכניות של המקלדת יש ללחוץ על *************************
//******************************************************************
////.................כפתור שמאל בעכבר=תנועה שלום עם יד שמאל.....
////.................כפתור ימין בעכבר=תנועה שלום עם יד ימין.....
int a = 0;
int stop = 0;
int leftHandAngle = 180;
int rightHandAngle = 180;
int HandAngle = 180;
bool mouseLeftState = false;
bool mouseRightState = false;
int leftHandMove = 2;
int rightHandMove = 2;
int leftLegMove = 1;
int rightLegMove = 2;
int leftLegAngle = 90;
int rightLegAngle = 90;
float zMove = 0;
void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushMatrix(); //גוף 
	glColor3f(1.0, 0.0, 1.0);
	glTranslatef(0.0, 221, zMove);
	glRotatef(90, 1.0, 0.0, 0.0);
	GLUquadricObj* body = gluNewQuadric();
	gluQuadricDrawStyle(body, GLU_FILL);
	gluCylinder(body, 120, 120, 300, 30, 30);
	glPopMatrix();

	glPushMatrix(); //כתף שמאל
	glColor3f(0.0, 1.0, 0);
	glTranslatef(-80, 160, zMove);
	glRotatef(-90, 0.0, 0.0, 1.0);
	glRotatef(90, 1.0, 0.0, 0.0);
	GLUquadricObj* leftUpperArm = gluNewQuadric();
	gluQuadricDrawStyle(leftUpperArm, GLU_FILL);
	gluCylinder(leftUpperArm, 16, 16, 200, 30, 30);
	glPopMatrix();

	glPushMatrix(); //כתף ימין 
	glColor3f(0.0, 1.0, 0);
	glTranslatef(80, 160, zMove);
	glRotatef(90, 0.0, 0.0, 1.0);
	glRotatef(90, 1.0, 0.0, 0.0);
	GLUquadricObj* rightUpperArm = gluNewQuadric();
	gluQuadricDrawStyle(rightUpperArm, GLU_FILL);
	gluCylinder(rightUpperArm, 16, 16, 200, 30, 30);
	glPopMatrix();

	glPushMatrix(); // חיבור כתף שמאל לגוף
	glColor3f(1.0, 0.0, 0.0);
	glPushMatrix();
	glTranslatef(-80.0, 160, zMove);
	glutSolidSphere(16, 30, 30);
	glPopMatrix();

	glPushMatrix(); //יד שמאל
	glColor3f(0.0, 1.0, 0);
	glTranslatef(-280.5, 150, zMove);
	glRotatef((GLfloat)leftHandAngle, 0.0, 0.0, 1.0);
	glRotatef(90, 1.0, 0.0, 0.0);
	GLUquadricObj* leftLowerArm = gluNewQuadric();
	gluQuadricDrawStyle(leftLowerArm, GLU_FILL);
	gluCylinder(leftLowerArm, 16, 16, 200, 30, 30);
	glPopMatrix();

	glPushMatrix(); //יד ימין
	glColor3f(0.0, 1.0, 0);
	glTranslatef(280, 160, zMove);
	glRotatef((GLfloat)rightHandAngle, 0.0, 0.0, 1.0);
	glRotatef(90, 1.0, 0.0, 0.0);
	GLUquadricObj* rightLowerArm = gluNewQuadric();
	gluQuadricDrawStyle(rightLowerArm, GLU_FILL);
	gluCylinder(rightLowerArm, 16, 16, 200, 30, 30);
	glPopMatrix();


	glPushMatrix(); //רגל ימין
	glColor3f(0.0, 1.0, 0);
	glTranslatef(35, -20, zMove);
	glRotatef(15, 0.0, 0.0, 1.0);
	glRotatef((GLfloat)rightLegAngle, 1.0, 0.0, 0.0);
	GLUquadricObj* rightLeg = gluNewQuadric();
	gluQuadricDrawStyle(rightLeg, GLU_FILL);
	gluCylinder(rightLeg, 16, 16, 400, 30, 30);
	glPopMatrix();

	glPushMatrix(); // חיבור כתף שמאל ליד שמאל 
	glColor3f(1.0, 0.0, 0.0);
	glPushMatrix();
	glTranslatef(-280, 160, zMove);
	glutSolidSphere(16, 30, 30);
	glPopMatrix();



	glPushMatrix(); // חיבור כתף ימין וגוף
	glColor3f(1.0, 0.0, 0.0);
	glPushMatrix();
	glTranslatef(80, 160, zMove);
	glutSolidSphere(16, 30, 30);
	glPopMatrix();



	glPushMatrix(); // חיבור כתף ימין ליד ימין
	glColor3f(1.0, 0.0, 0.0);
	glPushMatrix();
	glTranslatef(280, 160, zMove);
	glutSolidSphere(16, 30, 30);
	glPopMatrix();

	glPushMatrix(); //רגל שמאל
	glColor3f(0.0, 1.0, 0);
	glTranslatef(-35, -20, zMove);
	glRotatef(-15, 0.0, 0.0, 1.0);
	glRotatef((GLfloat)leftLegAngle, 1.0, 0.0, 0.0);
	GLUquadricObj* leftLeg = gluNewQuadric();
	gluQuadricDrawStyle(leftLeg, GLU_FILL);
	gluCylinder(leftLeg, 16, 16, 400, 30, 30);
	glPopMatrix();

	glPushMatrix(); // רגל שמאל וחיבור גוף
	glColor3f(1.0, 0.0, 0.0);
	glPushMatrix();
	glTranslatef(-35, -20, zMove);
	glutSolidSphere(16, 30, 30);
	glPopMatrix();



	glPushMatrix(); // רגל ימין וחיבור גוף
	glColor3f(1.0, 0.0, 0.0);
	glPushMatrix();
	glTranslatef(35, -20, zMove);
	glutSolidSphere(16, 30, 30);
	glPopMatrix();

	glPushMatrix(); //צוואר
	glColor3f(0.0, 0.0, 0.5);
	glTranslatef(0.0, 251, zMove);
	glRotatef(90, 1.0, 0.0, 0.0);
	GLUquadricObj* neck = gluNewQuadric();
	gluQuadricDrawStyle(neck, GLU_FILL);
	gluCylinder(neck, 20, 20, 30, 30, 30);
	glPopMatrix();

	glPushMatrix(); // ראש
	glColor3f(0.0, 1.0, 1.0);
	glPushMatrix();
	glTranslatef(0.0, 350, zMove);
	glutSolidSphere(100, 30, 30);
	glPopMatrix();


	if (mouseRightState == true) {
		if (rightHandAngle >= 225) {
			rightHandMove = -rightHandMove;
		}
		else if (rightHandAngle <= 135) {
			rightHandMove = -rightHandMove;
		}
		rightHandAngle = (rightHandAngle + rightHandMove) % 360;
	}
	if (mouseLeftState == true) {
		if (leftHandAngle >= 225) {
			leftHandMove = -leftHandMove;
		}
		else if (leftHandAngle <= 135) {
			leftHandMove = -leftHandMove;
		}

		leftHandAngle = (leftHandAngle + leftHandMove) % 360;
	}
	if (a == 1 && stop == 0) {
		rightLegAngle = (rightLegAngle - rightLegMove) % 360;
	}
	if (a == 2 && stop == 0) {
		leftLegAngle = (leftLegAngle - leftLegMove) % 360;
	}
	if (a == 3 && stop == 0) {
		leftHandAngle = (leftHandAngle + leftHandMove) % 360;
	}
	if (a == 4 && stop == 0) {
		rightHandAngle = (rightHandAngle + rightHandMove) % 360;
	}
	glutSwapBuffers();
}


void keyboard(unsigned char key, int x, int y) {
	if (key == 27) // exit when user hits <esc>  
		exit(EXIT_SUCCESS);

	if (key == 'w') {
		a = 1;
		stop = 0;
	}
	if (key == 's') {
		stop = 1;
	}
	if (key == 'q') {
		a = 2;
		stop = 0;
	}
	if (key == 'r') {
		leftLegAngle = 90;
		rightLegAngle = 90;
		leftHandAngle = 180;
		rightHandAngle = 180;
		a = 0;
		stop = 0;
		HandAngle = 180;
		mouseLeftState = false;
		mouseRightState = false;
		leftHandMove = 2;
		rightHandMove = 2;
		leftLegMove = 1;
		rightLegMove = 2;
		zMove = 0;
	}
	if (key == 'z') {
		a = 3;
		stop = 0;
	}
	if (key == 'x') {
		a = 4;
		stop = 0;
	}

	glutPostRedisplay();

}
void rotate(int key, int x, int y)
{
	if (key == GLUT_KEY_LEFT) {
		glRotatef(-1, 0.0, 1.0, 0.0);
		glutPostRedisplay();
	}
	if (key == GLUT_KEY_RIGHT) {

		glRotatef(1, 0.0, 1.0, 0.0);
		glutPostRedisplay();
	}
	if (key == GLUT_KEY_UP) {
		glRotatef(1, 1.0, 0.0, 0.0);
		glutPostRedisplay();
	}
	if (key == GLUT_KEY_DOWN) {
		glRotatef(-1, 1.0, 0.0, 0.0);
		glutPostRedisplay();
	}

}


void mouse(int button, int state, int x, int y) {
	if (GLUT_LEFT_BUTTON == button && state == GLUT_DOWN && mouseLeftState == false) {
		mouseLeftState = true;
	}
	else if (GLUT_LEFT_BUTTON == button && state == GLUT_DOWN && mouseLeftState == true) {
		mouseLeftState = false;
	}
	else if (GLUT_RIGHT_BUTTON == button && state == GLUT_DOWN && mouseRightState == false) {
		mouseRightState = true;
	}
	else if (GLUT_RIGHT_BUTTON == button && state == GLUT_DOWN && mouseRightState == true) {
		mouseRightState = false;
	}
}
void timer(int notUsed)
{
	glutPostRedisplay();
	glutTimerFunc(10, timer, 0);
}


int main(int argc, char *argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

	glutInitWindowSize(1200, 700);
	glutCreateWindow(argv[0]);
	glClearColor(0.2, 0.5, 0.6, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-750.0, 750.0, -500.0, 500.0, -500.0, 500.0);
	glutDisplayFunc(display);
	glutSpecialFunc(rotate);
	glutKeyboardFunc(keyboard);
	glutMouseFunc(mouse);
	timer(0);
	glutMainLoop();
	return EXIT_SUCCESS;
}