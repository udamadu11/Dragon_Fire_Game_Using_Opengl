#include <GL/glut.h>
#include <GL/gl.h>
#include <stdio.h>

float x=500,y=400;
float p=0,q=0.4;
float kx=20,ky=40;
int shoot=0,choice=0,point=0;
char starts[]="Click to Start !!!";
char scores[]="HighScore";
char difficulty[]="Play";
char go[] ="Game Over !!";
int level=3;
int window=1;
int point1,point2;
int attempt=8;
char instruction[]="Press N for New Game , Q to Quit";
char ins[] ="Press P-pause S-Shoot Esc-Back";
char attempts[]="Attempt left";
//
void gameover(){

	//Game Over
	glColor3f(0,0,0);
	glRasterPos3f(350,500,0); 
	for(int i=0;go[i]!='\0';i++){
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,go[i]);	
	}
	
	//Instruction
	glRasterPos3f(300,450,0);
	for(int i=0;instruction[i]!='\0';i++){
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,instruction[i]);
	}

	//Score
	glRasterPos3f(25,400,0);
	for(int i=0;scores[i]!='\0';i++){
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,scores[i]);	
	}

	//First 0 point
	glRasterPos3f(100,400,0);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,point1+48);

	//Second 0 point
	glRasterPos3f(115,400,0);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,point2+48);
	
}

void instruction_window(){
	glColor3f(0,0,0);
	glRasterPos3f(100,600,0);
	for(int i=0;ins[i]!='\0';i++){
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,ins[i]);
	}
}

void update(int msec) 
{ 
 
        glutPostRedisplay();
        glutTimerFunc(1000, update, 3);
}

//Level of Window
void level_func(){
	glColor3f(0,0,0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(80,520);
	glVertex2f(80,480);
	glVertex2f(220,480);
	glVertex2f(220,520);
	glEnd();

	glRasterPos3f(100,500,0);
	for(int i=0;difficulty[i]!='\0';i++){
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,difficulty[i]);	
	}
}

//Pause Function

// | | - pause icon

void pause(){
	glColor3f(1,0,0);
	glBegin(GL_QUADS);
	glVertex2f(100,800);
	glVertex2f(100,775);
	glVertex2f(120,775);
	glVertex2f(120,800);

	glVertex2f(130,800);
	glVertex2f(130,775);
	glVertex2f(150,775);
	glVertex2f(150,800);
	glEnd();
}

//Game Score Function
void score(){
	glColor3f(0,0,1);
	glRasterPos3f(80,700,0);
	for(int i=4;scores[i]!='\0';i++){
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,scores[i]);
	}
	
	point1 = point/10;
	point2 = point%10;
	glRasterPos3f(150,700,0);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,point1+48);
	glRasterPos3f(165,700,0);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,point2+48);

	glRasterPos3f(80,650,0);
	for(int i=0;attempts[i]!='\0';i++){
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,attempts[i]);	
	}
	
	glRasterPos3f(80,600,0);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,attempt+49);
}

void start(){
	glColor3f(0,0,1);
	glBegin(GL_LINE_LOOP);
	glVertex2f(80,520);
	glVertex2f(80,480);
	glVertex2f(300,480);
	glVertex2f(300,520);
	glEnd();

	glRasterPos3f(100,500,0);
	for(int i=0;starts[i]!='\0';i++)
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,starts[i]);
}

void dragon(){
	//body
	
	glBegin(GL_POLYGON);
	glColor3f(0.3,0.1,0.05);
	glVertex2i(600,50);
	glVertex2i(700,200);
	glVertex2i(600,300);
	
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.3,0.1,0.05);
	glVertex2i(600,50);
	glVertex2i(500,200);
	glVertex2i(600,300);
	
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.3,0.1,0.05);
	glVertex2i(500,200);
	glVertex2i(550,300);
	glVertex2i(600,300);
	
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.3,0.1,0.05);
	glVertex2i(600,300);
	glVertex2i(650,300);
	glVertex2i(700,200);
	
	glEnd();
	//wings up

	glBegin(GL_POLYGON);
	glColor3f(0.4, 0.13, 0.08);
	glVertex2i(700,200);
	glVertex2i(650,300);
	glVertex2i(800,350);
	
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.4, 0.13, 0.08);
	glVertex2i(500,200);
	glVertex2i(550,300);
	glVertex2i(350,300);
	
	glEnd();

	//down wings

	glBegin(GL_POLYGON);
	glColor3f(0.4, 0.13, 0.08);
	glVertex2i(630,120);
	glVertex2i(675,170);
	glVertex2i(730,50);
	
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.4, 0.13, 0.08);
	glVertex2i(570,120);
	glVertex2i(525,170);
	glVertex2i(430,50);
	
	glEnd();

	//head
	
	glBegin(GL_POLYGON);
	glColor3f(0.4,0.19,0.09);
	glVertex2i(550,300);
	glVertex2i(620,450);
	glVertex2i(650,300);
	
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.14,0.04,0.02);
	glVertex2i(620,450);
	glVertex2i(400,450);
	glVertex2i(550,300);
	
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.2,0.08,0.05);
	glVertex2i(400,350);
	glVertex2i(550,450);
	glVertex2i(600,350);
	
	glEnd();
	
	glBegin(GL_POLYGON);
	glColor3f(0.6,0.19,0.12);
	glVertex2i(500,450);
	glVertex2i(620,450);
	glVertex2i(750,600);
	
	glEnd();

	//eye
	glBegin(GL_POLYGON);
	glColor3f(0.7,0.24,0.157);
	glVertex2i(550,400);
	glVertex2i(525,400);
	glVertex2i(550,420);
	
	glEnd();

}
void fire(){
	glColor3f(1,0.9,0.1);
	if(p-x>-0.8)
	{
		p=0.0;
	    shoot=0;
		attempt--;
		printf("%d\n",attempt);
	}

	glTranslated(-p,-q,0);
	glBegin(GL_POLYGON);
	glColor3f(0.6,0.20,0.150);
	glVertex2f(400,400);
	glVertex2f(300,350);
	glVertex2f(350,400);
	glVertex2f(300,450);
	glEnd();
	glFlush();
	glLoadIdentity();
}
void enemy(){
	if(ky>=400)
	ky=0;
	ky+=0.4*level;
	glTranslated(kx,ky,0);
	glColor3f(1,0,0);
	glBegin(GL_QUADS);
	glColor3f(0.7,0.24,0.157);
	glVertex2f(0,0);
	glVertex2f(0,50);
	glVertex2f(50,50);
	glVertex2f(50,0);
	glEnd();
	glColor3f(0,0,0);
	glLineWidth(2.0);
	glFlush();
	glLoadIdentity();
	glutPostRedisplay();
}

void display2(){
	enemy();
	dragon();
	pause();
	if(p>=10 &&(ky>20 && ky<30) && (attempt))
	{
		point+=level;
		p=0;
		shoot=0;

	}
	if(shoot==1)
	{
	fire();
	p+=0.70*level;
	}
}

void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	glViewport(0,0,800,800);
	switch(window){
	case 1:
		level_func();
		break;
	
	case 2:
		if(!choice)
		start();
		break;
	
	case 3: 
		if(attempt+1){
		display2();
		score();
		}
		else
		gameover();
		glLoadIdentity();
		break;
	case 4:
	instruction_window();
	break;
	
	default:  exit(0);	
	}
	glLoadIdentity();
	glutSwapBuffers();

}
//Keyboard option

void keys(unsigned char key,int x,int y){
	if(key=='s'||key=='S')
	{
	shoot=1;
	display();
	}

	else if(key=='p'||key=='P')
	{
		printf("keyboard func");
		window=4;
		display();
	}


	else if(key=='N' || key=='n')
	{
		window=3;
		attempt=8;
		point=0;
		display();
	}

	if(key=='q' || key=='Q')
		exit(0);

}

//choose option 

void mouse(int btn,int state,int x,int y){
	
	if(btn==GLUT_LEFT_BUTTON && state==GLUT_DOWN && window==1)
	if((y>=300 && y<=450) && (x>100 && x<580))
	{
		if(x>=50 && x<=130)
		{
			level=3;
			window=2;
		}
		
		display();

	}


	if(btn==GLUT_LEFT_BUTTON && state==GLUT_DOWN && window==2)
	if((y>300 && y<450) && (x>100 && x<580))
	{
		choice=0;
		window=3;
		display();
	}
}

//main function
int main(int argc,char **argv)
{

	glutInit(&argc,argv);
	
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
	glutInitWindowPosition(0,0);
	glutInitWindowSize(800,800);
	glutCreateWindow("Dragon_fire");
	glutKeyboardFunc(keys);
	glutMouseFunc(mouse);
	glutDisplayFunc(display);

	glClearColor(1,0.995,0.995,0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();	
	gluOrtho2D(0,800,0,800);
	glMatrixMode(GL_MODELVIEW);
    
	
	glutMainLoop();
}

