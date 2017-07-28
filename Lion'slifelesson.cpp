#include<stdio.h>
#include<stdlib.h>
#include<GL/glut.h>
#include<string.h>
#include<math.h>

int d=0;

void drawText( float x, float y, int r, int g, int b,int d, const char *string ) 
{
	int j = strlen( string );
 
	glColor3f( r, g, b );
	glRasterPos2f( x, y );
	for( int i = 0; i < j; i++ ) {
		glutBitmapCharacter( GLUT_BITMAP_TIMES_ROMAN_24, string[i] );
		for(int k=d;k>0;k--){
			glFlush();
		}
	}
}

void circle(GLfloat x, GLfloat y, GLdouble radius){
	float x2, y2;
	float angle;
	glPointSize(2.0);
	glBegin(GL_TRIANGLE_FAN);
	for (angle = 0.0; angle < 6.3; angle += 0.01)
	{
		x2 = x + sin(angle)*radius;
		y2 = y + cos(angle)*radius;
		glVertex2f(x2, y2);
	}
	glEnd();
}

void arc(GLfloat x, GLfloat y, GLdouble radius, GLfloat i, GLfloat j){
	//i is intial angle,j is final angle of arc
	float x2, y2;
	float angle;
	glLineWidth(3.0);
	glBegin(GL_LINE_STRIP);
	for (angle = i; angle <= j; angle += 0.01)
	{
		x2 = x + sin(angle)*radius;
		y2 = y + cos(angle)*radius;
		glVertex2f(x2, y2);
	}
	glEnd();
}

void leaf(int x,int y,int r){
	glColor3ub(0,134,0);
	circle(x-35,y+100,r);
	circle(x-60,y+120,r);
	circle(x-38,y+150,r);
	circle(x+70,y+100,r);
	circle(x+65,y+150,r);
}

void tree(int x,int y){
	leaf(x,y+190,100);
	glColor3ub(204,154,31);//lower trunk
	glBegin(GL_POLYGON);
	glVertex2i(x-30,y-50);
	glVertex2i(x+60,y-50);
	glVertex2i(x+55,y+120);
	glVertex2i(x-20,y+120);
	glEnd();
	glBegin(GL_POLYGON);// right upper branch
	glVertex2i(x-20,y+120);
	glVertex2i(x+55,y+120);
	glVertex2i(x+65,y+250);
	glVertex2i(x+55,y+250);
	glEnd();
	glBegin(GL_POLYGON);//  left upper branch
	glVertex2i(x+55,y+120);
	glVertex2i(x-20,y+120);
	glVertex2i(x-45,y+220);
	glVertex2i(x-45,y+250);
	glEnd();
}

void tree2(int x,int y){
	leaf(x,y+300,160);
	glColor3ub(204,154,31);//lower trunk
	glBegin(GL_POLYGON);
	glVertex2i(x-30,y-50);
	glVertex2i(x+60,y-50);
	glVertex2i(x+55,y+300);
	glVertex2i(x-20,y+300);
	glEnd();
	glBegin(GL_POLYGON);// right upper branch
	glVertex2i(x-20,y+250);
	glVertex2i(x+55,y+250);
	glVertex2i(x+65,y+400);
	glVertex2i(x+55,y+400);
	glEnd();
	glBegin(GL_POLYGON);//  left upper branch
	glVertex2i(x+55,y+250);
	glVertex2i(x-20,y+250);
	glVertex2i(x-45,y+350);
	glVertex2i(x-45,y+400);
	glEnd();
}

void grass(int x, int y, int width, int height)
{
	int i = x;
	for (int l = 0; l<height; l++)
	{
		for (int k = 0; k<width; k++)
		{
			glBegin(GL_TRIANGLES);
			glVertex2f(x, y);
			glVertex2f(x + 10, y);
			glVertex2f(x + 5, y + 15);
			glVertex2f(x, y);
			glVertex2f(x + 12, y);
			glVertex2f(x - 5, y + 10);
			glVertex2f(x - 3, y);
			glVertex2f(x + 10, y);
			glVertex2f(x + 15, y + 10);
			glEnd();
			x += 16;
		}
		y += 8;
		x = i;
	}
}

void cloud(int x, int y, int r, int i)
{
	circle(x + i, y, r);
	circle(x + i, y, r);
	circle(x + 10 + i, y + 30, r - 10);
	circle(x + 55 + i, y + 20, r + 10);
	circle(x + 100 + i, y + 25, r - 5);
	circle(x + 90 + i, y, r + 10);
	circle(x + 120 + i, y + 15, r - 10);
}

void background8(){
	glColor3f(0.97,1.0,0.41);
	circle(1200,650,40);  //sun
	glColor3f(0.5,0.5,0.5);
	glBegin(GL_POLYGON);  //zoo floor
	glVertex2i(0.0,0.0);
	glVertex2i(0.0,150.0);
	glVertex2i(1500.0,150.0);
	glVertex2i(1500.0,0.0);
	glEnd();
}

void background6(){
	glColor3f(0.97, 1.0, 0.41);
	circle(1300, 700, 40);  //sun
	glColor3f(1,1,1);
	cloud(60,600,40,1);
	glColor3f(0.4, 1.0, 0.4);
	glBegin(GL_POLYGON);  //grass
	glVertex2i(0.0, 0.0);
	glVertex2i(0.0, 200.0);
	glVertex2i(1500.0, 200.0);
	glVertex2i(1500.0, 0.0);
	glEnd();
	glColor3f(0.7, 0.4, 0.4);
	glBegin(GL_POLYGON);  //rock
	glVertex2i(1250,100);
	glVertex2i(1250, 250);
	glVertex2i(1500, 250);
	glVertex2i(1500, 100);
	glEnd();
	circle(1250, 175, 75);
	glColor3f(0.5, 1.0, 0.1); //grass on rock
	grass(1300,120,1,1);
	grass(1400,140,1,1);
	grass(1200,160,1,1);
	grass(1450,180,1,1);
	grass(1350,200,1,1);
}

void background(){
	glColor3f(0.97,1.0,0.41);
	circle(550,500,40);  //sun
	glColor3f(1,1,1);
	cloud(300,550,40,1);
	cloud(1000,650,40,1);
	glColor3f(0.4,1.0,0.4);
	glBegin(GL_POLYGON);  //grass
	glVertex2i(0.0,0.0);
	glVertex2i(0.0,400.0);
	glVertex2i(1500.0,400.0);
	glVertex2i(1500.0,0.0);
	glEnd();
	glColor3f(0,0.7,0);
	/*grass(200,100,1,1);
	grass(100,150,1,1);
	grass(300,200,1,1);
	grass(50,250,1,1);
	grass(350,300,1,1);
	grass(100,100,1,1);
	grass(100,100,1,1);
	grass(100,100,1,1);
	grass(100,100,1,1);
	grass(100,100,1,1);*/
	glColor3f(0.75,0.5,0.25);
	glBegin(GL_POLYGON);  //right mountain
	glVertex2i(600.0,400.0);
	glVertex2i(1200.0,500.0);
	glVertex2i(1500.0,450.0);
	glVertex2i(1500.0,400.0);
	glEnd();
	glColor3f(0.6,0.4,0.2);
	glBegin(GL_POLYGON);   //left mountain
	glVertex2i(0.0,400.0);
	glVertex2i(0.0,450.0);
	glVertex2i(300.0,500.0);
	glVertex2i(1000.0,400.0);
	glEnd();
}

void tail(){
	glColor3f(0.75,0.5,0.25);
	glBegin(GL_POLYGON);  // upper tail
	glVertex2i(500.0,260.0);
	glVertex2i(500.0,280.0);
	glVertex2i(460.0,220.0);
	glVertex2i(460.0,200.0);
	glEnd();
	glBegin(GL_POLYGON); // lower tail
	glVertex2i(460.0,220.0);
	glVertex2i(460.0,200.0);
	glVertex2i(420.0,165.0);
	glVertex2i(420.0,175.0);
	glEnd();
	glColor3f(0.2,0.2,0.2);  //tail end
	glBegin(GL_POLYGON);
	glVertex2i(420.0,165.0);
	glVertex2i(420.0,175.0);
	glVertex2i(395.0,180.0);
	glVertex2i(375.0,160.0);
	glVertex2i(385.0,160.0);
	glVertex2i(405.0,155.0);
	glEnd();
}

void tail2()
{
	glColor3f(0.75, 0.5, 0.25);
	glBegin(GL_POLYGON);  // upper tail
	glVertex2i(705.0, 260.0);
	glVertex2i(705.0, 280.0);
	glVertex2i(665.0, 220.0);
	glVertex2i(665.0, 200.0);
	glEnd();
	glBegin(GL_POLYGON); // lower tail
	glVertex2i(665.0, 220.0);
	glVertex2i(665.0, 200.0);
	glVertex2i(625.0, 165.0);
	glVertex2i(625.0, 175.0);
	glEnd();
	glColor3f(0.2, 0.2, 0.2);  //tail end
	glBegin(GL_POLYGON);
	glVertex2i(625.0, 165.0);
	glVertex2i(625.0, 175.0);
	glVertex2i(600.0, 180.0);
	glVertex2i(580.0, 160.0);
	glVertex2i(590.0, 160.0);
	glVertex2i(610.0, 155.0);
	glEnd();
}

void head6()
{
	glColor3f(0.6, 0.4, 0.2); //fur
	circle(890, 515, 40);
	circle(830, 575, 40);
	circle(770, 515, 40);
	circle(830, 455, 40);

	circle(873, 558, 40);
	circle(787, 558, 40);
	circle(787, 472, 40);
	circle(873, 472, 40);

	glColor3f(0.75, 0.5, 0.25);
	circle(830, 515, 55); //head

	circle(790, 555, 20); //ears 
	circle(870, 555, 20);

	glColor3f(0.2, 0.2, 0.2);
	arc(810.0, 545.0, 15, 2.2, 4.08); //eyes open
	arc(850.0, 545.0, 15, 2.2, 4.08);
	arc(810.0, 527.0, 15, -0.94, 0.94);
	arc(850.0, 527.0, 15, -0.94, 0.94);
	circle(810, 535, 5);
	circle(850, 535, 5);

	glBegin(GL_POLYGON);
	glVertex2i(850.0, 515.0);  //nose
	glVertex2i(810.0, 515.0);
	glVertex2i(830.0, 495.0);
	glEnd();

	arc(810.0, 495.0, 20, 1.57, 4); //mouth
	arc(850.0, 495.0, 20, 2.28, 4.71);

	glLineWidth(1);     // right wiskers 
	glBegin(GL_LINES);
	glVertex2i(850.0, 500.0);
	glVertex2i(890.0, 505.0);
	glEnd();
	glLineWidth(1);
	glBegin(GL_LINES);
	glVertex2i(850.0, 495.0);
	glVertex2i(890.0, 495.0);
	glEnd();
	glLineWidth(1);
	glBegin(GL_LINES);
	glVertex2i(850.0, 490.0);
	glVertex2i(890.0, 485.0);
	glEnd();

	glLineWidth(1);       //left wiskers
	glBegin(GL_LINES);
	glVertex2i(810.0, 500.0);
	glVertex2i(770.0, 505.0);
	glEnd();
	glLineWidth(1);
	glBegin(GL_LINES);
	glVertex2i(810.0, 495.0);
	glVertex2i(770.0, 495.0);
	glEnd();
	glLineWidth(1);
	glBegin(GL_LINES);
	glVertex2i(810.0, 490.0);
	glVertex2i(770.0, 485.0);
	glEnd();
}

void paw(int a,int b,int c,int d)
{
	glColor3f(0.6, 0.4, 0.2);
	glBegin(GL_POLYGON);
	glVertex2i(a, b);
	glVertex2i(a, d);
	glVertex2i(c, d);
	glVertex2i(c, b);
	glEnd();
	glLineWidth(2);
	int e = (c - a) / 3 + a;
	int f = e + (c - a) / 3;
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINES);
	glVertex2i(e, b);
	glVertex2i(e, b+((d-b)/2));
	glEnd();
	glBegin(GL_LINES);
	glVertex2i(f, b);
	glVertex2i(f, b+((d-b)/2));
	glEnd();
}

void body6()
{
	glColor3f(0.75, 0.5, 0.25);
	glBegin(GL_POLYGON); //middle body
	glVertex2i(690, 240);
	glVertex2i(970, 240);
	glVertex2i(830, 550);
	glEnd();
	circle(770,250,80);//hind leg 1
	circle(890,250,80);//hind leg 2
	tail2();
	glColor3f(0.6, 0.4, 0.2);
	paw(720,155,770,185); //paw 1
	paw(890, 155, 940, 185);//paw2
	paw(780, 155, 825, 185);//paw3
	paw(835, 155, 880, 185);//paw4
	glColor3f(0.0, 0.0, 0.0);
	arc(0,155,780,-4.93,-4.75);//arc for foreleg 1
	arc(1500, 155,630 ,4.77,5.0);//arc for foreleg 2
	glBegin(GL_LINES);//line for foreleg 1
	glVertex2i(820,190); 
	glVertex2i(830,330); 
	glEnd();
	glBegin(GL_LINES);//line for foreleg 2
	glVertex2i(840, 190);
	glVertex2i(830, 330);
	glEnd();
}

void head(){
	glColor3f(0.6,0.4,0.2); //fur
	circle(890,265,40);
	circle(830,325,40);
	circle(770,265,40);
	circle(830,205,40);

	circle(873,308,40);
	circle(787,308,40);
	circle(787,222,40);
	circle(873,222,40);

	glColor3f(0.75,0.5,0.25);
	circle(830,265,55); //head

	circle(790,305,20); //ears 
	circle(870,305,20);

	glColor3f(0.2,0.2,0.2);
	arc(810.0,295.0,15,2.2,4.08); //eyes
	arc(850.0,295.0,15,2.2,4.08);
	glBegin(GL_POLYGON);
	glVertex2i(850.0,265.0);  //nose
	glVertex2i(810.0,265.0);
	glVertex2i(830.0,245.0);
	glEnd();

	arc(810.0,245.0,20,1.57,4); //mouth
	arc(850.0,245.0,20,2.28,4.71);
	
	glLineWidth(1);     // right wiskers 
	glBegin(GL_LINES);
	glVertex2i(850.0,250.0);
	glVertex2i(890.0,255.0);
	glEnd();
	glLineWidth(1);
	glBegin(GL_LINES);
	glVertex2i(850.0,245.0);
	glVertex2i(890.0,245.0);
	glEnd();
	glLineWidth(1);
	glBegin(GL_LINES);
	glVertex2i(850.0,240.0);
	glVertex2i(890.0,235.0);
	glEnd();

	glLineWidth(1);       //left wiskers
	glBegin(GL_LINES);
	glVertex2i(810.0,250.0);
	glVertex2i(770.0,255.0);
	glEnd();
	glLineWidth(1);
	glBegin(GL_LINES);
	glVertex2i(810.0,245.0);
	glVertex2i(770.0,245.0);
	glEnd();
	glLineWidth(1);
	glBegin(GL_LINES);
	glVertex2i(810.0,240.0);
	glVertex2i(770.0,235.0);
	glEnd();
}

void lionawake(){
	glColor3f(0.1,0.1,0.1); 
	arc(810.0,295.0,15,2.2,4.08); //eyes open
	arc(850.0,295.0,15,2.2,4.08);
	arc(810.0,277.0,15,-0.94,0.94);
	arc(850.0,277.0,15,-0.94,0.94);
	circle(810,285,5);
	circle(850,285,5);

	glColor3f(0.75,0.5,0.25);
	arc(810.0,245.0,20,1.57,4); //mouth disapear
	arc(850.0,245.0,20,2.28,4.71);

	glColor3f(0.1,0.1,0.1); 
	glLineWidth(1);     // angry mouth
	glBegin(GL_LINES);
	glVertex2i(830.0,245.0);
	glVertex2i(830.0,235.0);
	glEnd();
	glBegin(GL_LINES);
	glVertex2i(830.0,235.0);
	glVertex2i(800.0,225.0);
	glEnd();
	glBegin(GL_LINES);
	glVertex2i(830.0,235.0);
	glVertex2i(860.0,225.0);
	glEnd();
}

void head3(){
	glColor3f(0.6,0.4,0.2); //fur
	circle(1000,400,100);
	circle(800,600,100);
	circle(600,400,100);
	circle(800,200,100);

	circle(940,540,100);
	circle(660,540,100);
	circle(660,260,100);
	circle(940,260,100);

	glColor3f(0.75,0.5,0.25); 
	circle(800,400,160);  //head

	circle(670,530,50); //ears 
	circle(930,530,50);

	glColor3f(0.2,0.2,0.2);
	glBegin(GL_POLYGON);
	glVertex2i(850.0,400.0);  //nose
	glVertex2i(750.0,400.0);
	glVertex2i(800.0,350.0);
	glEnd();
	
	glLineWidth(2);     // right wiskers 
	glBegin(GL_LINES);
	glVertex2i(850.0,360.0);
	glVertex2i(950.0,370.0);
	glEnd();
	glBegin(GL_LINES);
	glVertex2i(850.0,350.0);
	glVertex2i(950.0,350.0);
	glEnd();
	glBegin(GL_LINES);
	glVertex2i(850.0,340.0);
	glVertex2i(950.0,330.0);
	glEnd();

	glBegin(GL_LINES);      //left wiskers
	glVertex2i(750.0,360.0);
	glVertex2i(650.0,370.0);
	glEnd();
	glBegin(GL_LINES);
	glVertex2i(750.0,350.0);
	glVertex2i(650.0,350.0);
	glEnd();
	glBegin(GL_LINES);
	glVertex2i(750.0,340.0);
	glVertex2i(650.0,330.0);
	glEnd();

	glColor3f(0.1,0.1,0.1); 
	arc(750.0,468.0,30,2.2,4.08); //eyes open
	arc(850.0,468.0,30,2.2,4.08);
	arc(750.0,430.0,30,-0.94,0.94);
	arc(850.0,430.0,30,-0.94,0.94);
	circle(742,448,10);
	circle(842,448,10);

	arc(750.0,345.0,50,1.57,4); //mouth
	arc(850.0,345.0,50,2.28,4.71);
}

void head2(){
	glColor3f(0.6,0.4,0.2); //fur
	circle(1000,400,100);
	circle(800,600,100);
	circle(600,400,100);
	circle(800,200,100);

	circle(940,540,100);
	circle(660,540,100);
	circle(660,260,100);
	circle(940,260,100);

	glColor3f(0.75,0.5,0.25); 
	circle(800,400,160);  //head

	circle(670,530,50); //ears 
	circle(930,530,50);

	glColor3f(0.2,0.2,0.2);
	glBegin(GL_POLYGON);
	glVertex2i(850.0,400.0);  //nose
	glVertex2i(750.0,400.0);
	glVertex2i(800.0,350.0);
	glEnd();
	
	glLineWidth(2);     // right wiskers 
	glBegin(GL_LINES);
	glVertex2i(850.0,360.0);
	glVertex2i(950.0,370.0);
	glEnd();
	glBegin(GL_LINES);
	glVertex2i(850.0,350.0);
	glVertex2i(950.0,350.0);
	glEnd();
	glBegin(GL_LINES);
	glVertex2i(850.0,340.0);
	glVertex2i(950.0,330.0);
	glEnd();

	glBegin(GL_LINES);      //left wiskers
	glVertex2i(750.0,360.0);
	glVertex2i(650.0,370.0);
	glEnd();
	glBegin(GL_LINES);
	glVertex2i(750.0,350.0);
	glVertex2i(650.0,350.0);
	glEnd();
	glBegin(GL_LINES);
	glVertex2i(750.0,340.0);
	glVertex2i(650.0,330.0);
	glEnd();

	glColor3f(0.1,0.1,0.1); 
	arc(750.0,468.0,30,2.2,4.08); //eyes open
	arc(850.0,468.0,30,2.2,4.08);
	arc(750.0,430.0,30,-0.94,0.94);
	arc(850.0,430.0,30,-0.94,0.94);
	circle(742,448,10);
	circle(842,448,10);

	glLineWidth(1);     // angry mouth
	glBegin(GL_LINES);
	glVertex2i(800.0,350.0);
	glVertex2i(800.0,325.0);
	glEnd();
	glBegin(GL_LINES);
	glVertex2i(800.0,325.0);
	glVertex2i(720.0,300.0);
	glEnd();
	glBegin(GL_LINES);
	glVertex2i(800.0,325.0);
	glVertex2i(880.0,300.0);
	glEnd();
}

void lion8(int x,int y){
	glColor3f(0.75,0.5,0.25);//body
	glBegin(GL_POLYGON);
	glVertex2i(x+550.0,y+150.0);
	glVertex2i(x+550.0,y+300.0);
	glVertex2i(x+800.0,y+305.0);
	glVertex2i(x+800.0,y+150.0);
	glEnd();
	circle(x+560,y+210,90);
	circle(x+780,y+200,70);
	
	glColor3f(0.75,0.5,0.25);  
	glBegin(GL_POLYGON);         // back leg
	glVertex2i(x+550.0,y+120.0);
	glVertex2i(x+650.0,y+115.0);
	glVertex2i(x+650.0,y+190.0);
	glVertex2i(x+550.0,y+195.0);
	glEnd();
	circle(x+650,y+135,20);
	glBegin(GL_POLYGON);      // front leg
	glVertex2i(x+770.0,y+130.0);
	glVertex2i(x+850.0,y+130.0);
	glVertex2i(x+850.0,y+190.0);
	glVertex2i(x+770.0,y+195.0);
	glEnd();
	circle(x+850,y+150,20);

	glLineWidth(1);       //leg outline
	glColor3f(0.2,0.2,0.2);
	glBegin(GL_LINES);
	glVertex2i(x+580.0,y+155.0);
	glVertex2i(x+665.0,y+150.0);
	glEnd();
	glColor3f(0.2,0.2,0.2);  //nails back
	glBegin(GL_LINES);
	glVertex2i(x+640.0,y+141.0);
	glVertex2i(x+670.0,y+140.0);
	glEnd();
	glColor3f(0.2,0.2,0.2);
	glBegin(GL_LINES);
	glVertex2i(x+640.0,y+131.0);
	glVertex2i(x+670.0,y+130.0);
	glEnd();
	glColor3f(0.2,0.2,0.2);  // nails front
	glBegin(GL_LINES);
	glVertex2i(x+840.0,y+156.0);
	glVertex2i(x+870.0,y+155.0);
	glEnd();
	glColor3f(0.2,0.2,0.2);
	glBegin(GL_LINES);
	glVertex2i(x+840.0,y+146.0);
	glVertex2i(x+870.0,y+145.0);
	glEnd();

	glColor3f(0.6,0.4,0.2); //fur
	circle(x+890,y+265,40);
	circle(x+830,y+325,40);
	circle(x+770,y+265,40);
	circle(x+830,y+205,40);

	circle(x+873,y+308,40);
	circle(x+787,y+308,40);
	circle(x+787,y+222,40);
	circle(x+873,y+222,40);

	glColor3f(0.75,0.5,0.25);
	circle(x+830,y+265,55); //head

	circle(x+790,y+305,20); //ears 
	circle(x+870,y+305,20);

	glColor3f(0.2,0.2,0.2);
	arc(x+810.0,y+295.0,15,2.2,4.08); //eyes
	arc(x+850.0,y+295.0,15,2.2,4.08);
	glBegin(GL_POLYGON);
	glVertex2i(x+850.0,y+265.0);  //nose
	glVertex2i(x+810.0,y+265.0);
	glVertex2i(x+830.0,y+245.0);
	glEnd();

	arc(x+810.0,y+245.0,20,1.57,4); //mouth
	arc(x+850.0,y+245.0,20,2.28,4.71);
	
	glLineWidth(1);     // right wiskers 
	glBegin(GL_LINES);
	glVertex2i(x+850.0,y+250.0);
	glVertex2i(x+890.0,y+255.0);
	glEnd();
	glLineWidth(1);
	glBegin(GL_LINES);
	glVertex2i(x+850.0,y+245.0);
	glVertex2i(x+890.0,y+245.0);
	glEnd();
	glLineWidth(1);
	glBegin(GL_LINES);
	glVertex2i(x+850.0,y+240.0);
	glVertex2i(x+890.0,y+235.0);
	glEnd();

	glLineWidth(1);       //left wiskers
	glBegin(GL_LINES);
	glVertex2i(x+810.0,y+250.0);
	glVertex2i(x+770.0,y+255.0);
	glEnd();
	glLineWidth(1);
	glBegin(GL_LINES);
	glVertex2i(x+810.0,y+245.0);
	glVertex2i(x+770.0,y+245.0);
	glEnd();
	glLineWidth(1);
	glBegin(GL_LINES);
	glVertex2i(x+810.0,y+240.0);
	glVertex2i(x+770.0,y+235.0);
	glEnd();

	glColor3f(0.75,0.5,0.25);
	glBegin(GL_POLYGON);  // upper tail
	glVertex2i(x+500.0,y+260.0);
	glVertex2i(x+500.0,y+280.0);
	glVertex2i(x+460.0,y+220.0);
	glVertex2i(x+460.0,y+200.0);
	glEnd();
	glBegin(GL_POLYGON); // lower tail
	glVertex2i(x+460.0,y+220.0);
	glVertex2i(x+460.0,y+200.0);
	glVertex2i(x+420.0,y+165.0);
	glVertex2i(x+420.0,y+175.0);
	glEnd();
	glColor3f(0.2,0.2,0.2);  //tail end
	glBegin(GL_POLYGON);
	glVertex2i(x+420.0,y+165.0);
	glVertex2i(x+420.0,y+175.0);
	glVertex2i(x+395.0,y+180.0);
	glVertex2i(x+375.0,y+160.0);
	glVertex2i(x+385.0,y+160.0);
	glVertex2i(x+405.0,y+155.0);
	glEnd();
	glColor3f(0.1,0.1,0.1); 
	arc(x+810.0,y+295.0,15,2.2,4.08); //eyes open
	arc(x+850.0,y+295.0,15,2.2,4.08);
	arc(x+810.0,y+277.0,15,-0.94,0.94);
	arc(x+850.0,y+277.0,15,-0.94,0.94);
	circle(x+810,y+285,5);
	circle(x+850,y+285,5);

	glColor3f(0.75,0.5,0.25);
	arc(x+810.0,y+245.0,20,1.57,4); //mouth disapear
	arc(x+850.0,y+245.0,20,2.28,4.71);

	glColor3f(0.1,0.1,0.1); 
	glLineWidth(1);     // angry mouth
	glBegin(GL_LINES);
	glVertex2i(x+830.0,y+245.0);
	glVertex2i(x+830.0,y+235.0);
	glEnd();
	glBegin(GL_LINES);
	glVertex2i(x+830.0,y+235.0);
	glVertex2i(x+800.0,y+225.0);
	glEnd();
	glBegin(GL_LINES);
	glVertex2i(x+830.0,y+235.0);
	glVertex2i(x+860.0,y+225.0);
	glEnd();
}

void lion(){
	glColor3f(0.75,0.5,0.25);//body
	glBegin(GL_POLYGON);
	glVertex2i(550.0,150.0);
	glVertex2i(550.0,300.0);
	glVertex2i(800.0,305.0);
	glVertex2i(800.0,150.0);
	glEnd();
	circle(560,210,90);
	circle(780,200,70);
	
	glColor3f(0.75,0.5,0.25);  
	glBegin(GL_POLYGON);         // back leg
	glVertex2i(550.0,120.0);
	glVertex2i(650.0,115.0);
	glVertex2i(650.0,190.0);
	glVertex2i(550.0,195.0);
	glEnd();
	circle(650,135,20);
	glBegin(GL_POLYGON);      // front leg
	glVertex2i(770.0,130.0);
	glVertex2i(850.0,130.0);
	glVertex2i(850.0,190.0);
	glVertex2i(770.0,195.0);
	glEnd();
	circle(850,150,20);

	glLineWidth(1);       //leg outline
	glColor3f(0.2,0.2,0.2);
	glBegin(GL_LINES);
	glVertex2i(580.0,155.0);
	glVertex2i(665.0,150.0);
	glEnd();
	glColor3f(0.2,0.2,0.2);  //nails back
	glBegin(GL_LINES);
	glVertex2i(640.0,141.0);
	glVertex2i(670.0,140.0);
	glEnd();
	glColor3f(0.2,0.2,0.2);
	glBegin(GL_LINES);
	glVertex2i(640.0,131.0);
	glVertex2i(670.0,130.0);
	glEnd();
	glColor3f(0.2,0.2,0.2);  // nails front
	glBegin(GL_LINES);
	glVertex2i(840.0,156.0);
	glVertex2i(870.0,155.0);
	glEnd();
	glColor3f(0.2,0.2,0.2);
	glBegin(GL_LINES);
	glVertex2i(840.0,146.0);
	glVertex2i(870.0,145.0);
	glEnd();

	head();
	tail();
}

void lion2(){
	glColor3f(0.75,0.5,0.25);//body
	glBegin(GL_POLYGON);
	glVertex2i(900.0,50.0);
	glVertex2i(900.0,510.0);
	glVertex2i(1500.0,500.0);
	glVertex2i(1500.0,50.0);
	glEnd();
	circle(1000,220,210);

	glColor3f(0.75,0.5,0.25);  
	glBegin(GL_POLYGON);         // front leg
	glVertex2i(1000.0,90.0);
	glVertex2i(1000.0,10.0);
	glVertex2i(700.0,10.0);
	glVertex2i(700.0,90.0);
	glEnd();
	circle(690,50,40);
	glColor3f(0.2,0.2,0.2);  //nails back
	glBegin(GL_LINES);
	glVertex2i(700.0,65.0);
	glVertex2i(655.0,65.0);
	glEnd();
	glColor3f(0.2,0.2,0.2);
	glBegin(GL_LINES);
	glVertex2i(700.0,35.0);
	glVertex2i(655.0,35.0);
	glEnd();

	glColor3f(0.75,0.5,0.25);
	glBegin(GL_POLYGON);         // front arm
	glVertex2i(1000.0,280.0);
	glVertex2i(1000.0,350.0);
	glVertex2i(500.0,200.0);
	glVertex2i(500.0,120.0);
	glEnd();
	glBegin(GL_POLYGON);         
	glVertex2i(420.0,200.0);
	glVertex2i(420.0,280.0);
	glVertex2i(500.0,200.0);
	glVertex2i(500.0,120.0);
	glEnd();

	glBegin(GL_POLYGON);         // paw
	glVertex2i(420.0,290.0);
	glVertex2i(420.0,200.0);
	glVertex2i(360.0,200.0);
	glVertex2i(360.0,290.0);
	glEnd();
	glColor3f(0.2,0.2,0.2);  
	glBegin(GL_LINE_LOOP);
	glVertex2i(360.0,260.0);
	glVertex2i(360.0,290.0);
	glVertex2i(420.0,290.0);
	glVertex2i(420.0,260.0);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glVertex2i(360.0,260.0);
	glVertex2i(360.0,230.0);
	glVertex2i(420.0,230.0);
	glVertex2i(420.0,260.0);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glVertex2i(360.0,200.0);
	glVertex2i(360.0,230.0);
	glVertex2i(420.0,230.0);
	glVertex2i(420.0,200.0);
	glEnd();


	head2();
}

void lion3(){
	glColor3f(0.75,0.5,0.25);//body
	glBegin(GL_POLYGON);
	glVertex2i(900.0,50.0);
	glVertex2i(900.0,510.0);
	glVertex2i(1500.0,500.0);
	glVertex2i(1500.0,50.0);
	glEnd();
	circle(1000,220,210);

	glColor3f(0.75,0.5,0.25);  
	glBegin(GL_POLYGON);         // front leg
	glVertex2i(1000.0,90.0);
	glVertex2i(1000.0,10.0);
	glVertex2i(700.0,10.0);
	glVertex2i(700.0,90.0);
	glEnd();
	circle(690,50,40);
	glColor3f(0.2,0.2,0.2);  //nails back
	glBegin(GL_LINES);
	glVertex2i(700.0,65.0);
	glVertex2i(655.0,65.0);
	glEnd();
	glColor3f(0.2,0.2,0.2);
	glBegin(GL_LINES);
	glVertex2i(700.0,35.0);
	glVertex2i(655.0,35.0);
	glEnd();

	glColor3f(0.75,0.5,0.25);
	glBegin(GL_POLYGON);         // front arm
	glVertex2i(1000.0,280.0);
	glVertex2i(1000.0,350.0);
	glVertex2i(500.0,200.0);
	glVertex2i(500.0,120.0);
	glEnd();
	glBegin(GL_POLYGON);         
	glVertex2i(420.0,200.0);
	glVertex2i(420.0,280.0);
	glVertex2i(500.0,200.0);
	glVertex2i(500.0,120.0);
	glEnd();

	glBegin(GL_POLYGON);         // paw
	glVertex2i(420.0,290.0);
	glVertex2i(420.0,200.0);
	glVertex2i(360.0,200.0);
	glVertex2i(360.0,290.0);
	glEnd();
	glColor3f(0.2,0.2,0.2);  
	glBegin(GL_LINE_LOOP);
	glVertex2i(360.0,260.0);
	glVertex2i(360.0,290.0);
	glVertex2i(420.0,290.0);
	glVertex2i(420.0,260.0);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glVertex2i(360.0,260.0);
	glVertex2i(360.0,230.0);
	glVertex2i(420.0,230.0);
	glVertex2i(420.0,260.0);
	glEnd();
	glBegin(GL_LINE_LOOP);
	glVertex2i(360.0,200.0);
	glVertex2i(360.0,230.0);
	glVertex2i(420.0,230.0);
	glVertex2i(420.0,200.0);
	glEnd();


	head3();
}

void mouse(int x,int y){
	glColor3f(0.5,0.5,0.5);  //mouse body
	glBegin(GL_POLYGON);
	glVertex2i(x+660.0,y+280.0);
	glVertex2i(x+700.0,y+280.0);
	glVertex2i(x+680.0,y+320.0);
	glEnd();

	glColor3f(0.4,0.4,0.4);  //mouse head
	glBegin(GL_POLYGON);
	glVertex2i(x+670.0,y+330.0);
	glVertex2i(x+690.0,y+330.0);
	glVertex2i(x+680.0,y+310.0);
	glEnd();

	glColor3f(0.3,0.3,0.3);  //mouse ears
	circle(x+670.0,y+330.0,4);
	circle(x+690.0,y+330.0,4);

	glColor3f(0.4,0.4,0.4);  //mouse hands
	circle(x+670.0,y+305.0,5);
	circle(x+690.0,y+305.0,5);

	circle(x+670.0,y+280.0,5);  //mouse feet
	circle(x+690.0,y+280.0,5);

	glColor3f(0.1,0.1,0.1);  //mouse eyes
	circle(x+676.0,y+321.0,2);
	circle(x+684.0,y+321.0,2);
}

void bars(int x){
	glColor3f(0.4,0.4,0.4);
	glBegin(GL_POLYGON);  //base
	glVertex2i(x+400.0,550.0);
	glVertex2i(x+410.0,550.0);
	glVertex2i(x+410.0,120.0);
	glVertex2i(x+400.0,120.0);
	glEnd();
}

void prison(){
	glColor3f(0.2,0.2,0.2);
	glBegin(GL_POLYGON);  //base
	glVertex2i(360.0,80.0);
	glVertex2i(1050.0,80.0);
	glVertex2i(1050.0,120.0);
	glVertex2i(360.0,120.0);
	glEnd();
	glBegin(GL_POLYGON);//left wall
	glVertex2i(360.0,80.0);
	glVertex2i(380.0,80.0);
	glVertex2i(380.0,550.0);
	glVertex2i(360.0,550.0);
	glEnd();
	glBegin(GL_POLYGON);//right wall
	glVertex2i(1050.0,80.0);
	glVertex2i(1030.0,80.0);
	glVertex2i(1030.0,550.0);
	glVertex2i(1050.0,550.0);
	glEnd();
	glBegin(GL_POLYGON);//top
	glVertex2i(360.0,550.0);
	glVertex2i(1050.0,550.0);
	glVertex2i(1050.0,570.0);
	glVertex2i(360.0,570.0);
	glEnd();
	bars(0);
	bars(100);
	bars(200);
	bars(300);
	bars(400);
	bars(500);
	bars(600);
}

void nline(int x,int y,int a,int b,int c){
	glLineWidth(4);
	glBegin(GL_LINES);
	glVertex2i(x+450.0,a+y+100.0);
	glVertex2i(c+x+480.0,b+y+320.0);
	glEnd();
}

void hline(int x,int y,int a,int b){
	glLineWidth(3);
	glBegin(GL_LINES);
	glVertex2i(a+x+480.0,y+290.0);
	glVertex2i(b+x+925.0,y+300.0);
	glEnd();
}

void net(){
	glColor3f(0.2,0.2,0.2);
	nline(-40,0,30,-30,40);
	nline(0,0,30,-30,0);
	nline(40,0,20,-20,0);
	nline(80,0,0,0,0);
	nline(120,0,0,0,0);
	nline(160,0,0,0,0);
	nline(200,0,0,0,0);
	nline(240,0,10,0,0);
	nline(280,0,15,30,0);
	nline(320,0,20,50,0);
	nline(360,0,20,60,0);
	nline(400,0,20,40,0);
	nline(440,0,20,20,0);
	nline(500,0,20,20,-60);

	hline(0,0,0,0);
	hline(0,-40,-20,10);
	hline(0,-80,-35,15);
	hline(0,-120,-50,20);
	hline(0,-160,-65,25);
	hline(0,40,255,-5);

	glBegin(GL_LINE_LOOP);
	glVertex2i(480,290);
	glVertex2i(520,300);
	glVertex2i(560,320);
	glVertex2i(600,320);
	glVertex2i(640,320);
	glVertex2i(680,320);
	glVertex2i(720,320);
	glVertex2i(760,350);
	glVertex2i(800,370);
	glVertex2i(840,380);
	glVertex2i(880,360);
	glVertex2i(920,340);
	glVertex2i(925,300);
	glEnd();

	int r=6;
	circle(410,130,r);
	circle(450,130,r);
	circle(490,120,r);
	circle(530,100,r);
	circle(570,100,r);
	circle(610,100,r);
	circle(650,100,r);
	circle(690,110,r);
	circle(730,115,r);
	circle(770,120,r);
	circle(810,120,r);
	circle(850,120,r);
	circle(890,120,r);
	circle(930,120,r);
	circle(950,120,r);
	circle(970,120,r);
}

void win1(){
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	background();
	tree(700,250);
	lion();
	glFlush();
	for(int i=-700;i<=0;i++){  //mouse appears
			glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
			background();
			tree(700,250);
			lion();
			mouse(i,-200);
			glFlush();
	}
	for(i=-300;i<=0;i++){    //pause
			glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
			background();
			tree(700,250);
			lion();
			mouse(0,-200);
			glFlush();
	}
	for(i=-200;i<=-150;i++){  //mouse jump up
			glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
			background();
			tree(700,250);
			lion();
			mouse(0,i);
			glFlush();
	}
	for(i=-150;i>=-200;i--){  //mouse jump down
			glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
			background();
			tree(700,250);
			lion();
			mouse(0,i);
			glFlush();
	}
	for(i=-100;i<=0;i++){    //pause
			glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
			background();
			tree(700,250);
			lion();
			mouse(0,-200);
			glFlush();
	}
	for(i=-200;i<=-150;i++){  //mouse jump up
			glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
			background();
			tree(700,250);
			lion();
			mouse(0,i);
			glFlush();
	}
	for(i=-150;i>=-200;i--){  //mouse jump down
			glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
			background();
			tree(700,250);
			lion();
			mouse(0,i);
			glFlush();
	}
	for(i=-100;i<=0;i++){    //pause
			glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
			background();
			tree(700,250);
			lion();
			mouse(0,-200);
			glFlush();
	}
	for(i=-200;i<=0;i++){  //mouse climbs
			glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
			background();
			tree(700,250);
			lion();
			mouse(0,i);
			glFlush();
	}
	for(i=-200;i<=0;i++){    //pause
			glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
			background();
			tree(700,250);
			lion();
			mouse(0,0);
			glFlush();
	}
	for(i=0;i<=50;i++){  //mouse jump up
			glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
			background();
			tree(700,250);
			lion();
			mouse(0,i);
			glFlush();
	}
	for(i=50;i>=0;i--){  //mouse jump down
			glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
			background();
			tree(700,250);
			lion();
			mouse(0,i);
			glFlush();
	}
	for(i=-100;i<=0;i++){    //pause
			glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
			background();
			tree(700,250);
			lion();
			mouse(0,0);
			glFlush();
	}
	for(i=0;i<=50;i++){  //mouse jump up
			glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
			background();
			tree(700,250);
			lion();
			mouse(0,i);
			glFlush();
	}
	for(i=50;i>=0;i--){  //mouse jump down
			glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
			background();
			tree(700,250);
			lion();
			mouse(0,i);
			glFlush();
	}
	for(i=-100;i<=0;i++){    //pause
			glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
			background();
			tree(700,250);
			lion();
			mouse(0,0);
			glFlush();
	}
	for(i=0;i<=50;i++){  //mouse jump up
			glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
			background();
			tree(700,250);
			lion();
			mouse(0,i);
			glFlush();
	}
	for(i=50;i>=0;i--){  //mouse jump down
			glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
			background();
			tree(700,250);
			lion();
			mouse(0,i);
			glFlush();
	}
	for(i=-100;i<=0;i++){    //pause
			glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
			background();
			tree(700,250);
			lion();
			mouse(0,0);
			glFlush();
	}
	lionawake();
	glFlush();
	for(i=-300;i<=0;i++){    //pause
			glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
			background();
			tree(700,250);
			lion();
			mouse(0,0);
			lionawake();
			glFlush();
	}
	drawText(1000,550,0,1,0,30,"PRESS '2' FOR NEXT SLIDE");
	glFlush();
}

void giggles(){
	for(int i=-300;i<=0;i++){  //pause
			glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
			glColor3f(0.4,1.0,0.4);
			glBegin(GL_POLYGON);  //grass
			glVertex2i(0.0,0.0);
			glVertex2i(0.0,750.0);
			glVertex2i(1500.0,750.0);
			glVertex2i(1500.0,0.0);
			glEnd();
			tree2(0,250);
			mouse(-290,0);
			lion2();
			glFlush();
	}
	for(i=-10;i<=10;i++){  //mouse jiggles right
			glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
			glColor3f(0.4,1.0,0.4);
			glBegin(GL_POLYGON);  //grass
			glVertex2i(0.0,0.0);
			glVertex2i(0.0,750.0);
			glVertex2i(1500.0,750.0);
			glVertex2i(1500.0,0.0);
			glEnd();
			tree2(0,250);
			mouse(-290+i,0);
			lion2();
			glFlush();
	}
	for(i=-10;i<=10;i++){  //mouse jiggles left
			glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
			glColor3f(0.4,1.0,0.4);
			glBegin(GL_POLYGON);  //grass
			glVertex2i(0.0,0.0);
			glVertex2i(0.0,750.0);
			glVertex2i(1500.0,750.0);
			glVertex2i(1500.0,0.0);
			glEnd();
			tree2(0,250);
			mouse(-290-i,0);
			lion2();
			glFlush();
	}
	for(i=-10;i<=10;i++){  //mouse jiggles right
			glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
			glColor3f(0.4,1.0,0.4);
			glBegin(GL_POLYGON);  //grass
			glVertex2i(0.0,0.0);
			glVertex2i(0.0,750.0);
			glVertex2i(1500.0,750.0);
			glVertex2i(1500.0,0.0);
			glEnd();
			tree2(0,250);
			mouse(-290+i,0);
			lion2();
			glFlush();
	}
	for(i=-10;i<=10;i++){  //mouse jiggles left
			glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
			glColor3f(0.4,1.0,0.4);
			glBegin(GL_POLYGON);  //grass
			glVertex2i(0.0,0.0);
			glVertex2i(0.0,750.0);
			glVertex2i(1500.0,750.0);
			glVertex2i(1500.0,0.0);
			glEnd();
			tree2(0,250);
			mouse(-290-i,0);
			lion2();
			glFlush();
	}
	for(i=-10;i<=10;i++){  //mouse jiggles right
			glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
			glColor3f(0.4,1.0,0.4);
			glBegin(GL_POLYGON);  //grass
			glVertex2i(0.0,0.0);
			glVertex2i(0.0,750.0);
			glVertex2i(1500.0,750.0);
			glVertex2i(1500.0,0.0);
			glEnd();
			tree2(0,250);
			mouse(-290+i,0);
			lion2();
			glFlush();
	}
	for(i=-10;i<=10;i++){  //mouse jiggles left
			glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
			glColor3f(0.4,1.0,0.4);
			glBegin(GL_POLYGON);  //grass
			glVertex2i(0.0,0.0);
			glVertex2i(0.0,750.0);
			glVertex2i(1500.0,750.0);
			glVertex2i(1500.0,0.0);
			glEnd();
			tree2(0,250);
			mouse(-290-i,0);
			lion2();
			glFlush();
	}
	for(i=-10;i<=0;i++){  //mouse jiggles right
			glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
			glColor3f(0.4,1.0,0.4);
			glBegin(GL_POLYGON);  //grass
			glVertex2i(0.0,0.0);
			glVertex2i(0.0,750.0);
			glVertex2i(1500.0,750.0);
			glVertex2i(1500.0,0.0);
			glEnd();
			tree2(0,250);
			mouse(-290+i,0);
			lion2();
			glFlush();
	}
}

void win2(){
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glColor3f(0.4,1.0,0.4);
	glBegin(GL_POLYGON);  //grass
	glVertex2i(0.0,0.0);
	glVertex2i(0.0,750.0);
	glVertex2i(1500.0,750.0);
	glVertex2i(1500.0,0.0);
	glEnd();
	tree2(0,250);
	mouse(-290,0);
	lion2();
	glFlush();
	giggles();
	giggles();
	giggles();
	drawText(250,720,1,0,0,30,"MOUSE :   Dear Majesty Lion, Ruler of jungle, Pardon me for this act !");
	drawText(300,690,1,0,0,30,"If you let me go, I will repay this debt");
	drawText(300,660,1,0,0,30,"and will help you in future.");
	drawText(300,660,1,0,0,50,"and will help you in future.");
	drawText(300,620,0,0,1,30,"PRESS '3' FOR NEXT SLIDE");
	glFlush();
}

void win3(){
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glColor3f(0.4,1.0,0.4);
	glBegin(GL_POLYGON);  //grass
	glVertex2i(0.0,0.0);
	glVertex2i(0.0,750.0);
	glVertex2i(1500.0,750.0);
	glVertex2i(1500.0,0.0);
	glEnd();
	tree2(0,250);
	mouse(-290,0);
	lion3();
	drawText(250,720,1,0,0,30,"LION:   HA! HA! HA! , How will a small creature like you will help me!!");
	drawText(300,690,1,0,0,30,"You can't even help yourself");
	drawText(300,660,1,0,0,30,"I forgive you ,Go away!");
	drawText(300,690,1,0,0,50,"You can't even help yourself");
	mouse(-290,0);
	for(int i=0;i<=200;i++){  //mouse comes down
			glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
			glColor3f(0.4,1.0,0.4);
			glBegin(GL_POLYGON);  //grass
			glVertex2i(0.0,0.0);
			glVertex2i(0.0,750.0);
			glVertex2i(1500.0,750.0);
			glVertex2i(1500.0,0.0);
			glEnd();
			tree2(0,250);
			lion3();
			drawText(250,720,1,0,0,0,"LION:   HA! HA! HA! , How will a small creature like you will help me!!");
			drawText(300,690,1,0,0,0,"You can't even help yourself");
			drawText(300,660,1,0,0,0,"I forgive you ,Go away!");
			mouse(-290,-i);
			glFlush();
	}
	for(i=0;i<=500;i++){  //pause
			glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
			glColor3f(0.4,1.0,0.4);
			glBegin(GL_POLYGON);  //grass
			glVertex2i(0.0,0.0);
			glVertex2i(0.0,750.0);
			glVertex2i(1500.0,750.0);
			glVertex2i(1500.0,0.0);
			glEnd();
			tree2(0,250);
			lion3();
			drawText(250,720,1,0,0,0,"LION:   HA! HA! HA! , How will a small creature like you will help me!!");
			drawText(300,690,1,0,0,0,"You can't even help yourself");
			drawText(300,660,1,0,0,0,"I forgive you ,Go away!");
			mouse(-290,-200);
			glFlush();
	}
	for(i=0;i<=450;i++){  //mouse left
			glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
			glColor3f(0.4,1.0,0.4);
			glBegin(GL_POLYGON);  //grass
			glVertex2i(0.0,0.0);
			glVertex2i(0.0,750.0);
			glVertex2i(1500.0,750.0);
			glVertex2i(1500.0,0.0);
			glEnd();
			tree2(0,250);
			lion3();
			drawText(250,720,1,0,0,0,"LION:   HA! HA! HA! , How will a small creature like you will help me!!");
			drawText(300,690,1,0,0,0,"You can't even help yourself");
			drawText(300,660,1,0,0,0,"I forgive you ,Go away!");
			mouse(-290-i,-200);
			glFlush();
	}
	glFlush();
	drawText(300,690,1,0,0,50,"You can't even help yourself");
	drawText(300,620,0,0,1,30,"PRESS '4' FOR NEXT SLIDE");
	glFlush();
}

void win4(){
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glColor3f(0.4,1.0,0.4);
	glBegin(GL_POLYGON);  //grass
	glVertex2i(0.0,0.0);
	glVertex2i(0.0,400.0);
	glVertex2i(1500.0,400.0);
	glVertex2i(1500.0,0.0);
	glEnd();
	glColor3f(0.97,1.0,0.41);
	circle(950,700,40);  //sun
	glColor3f(1,1,1);
	cloud(300,650,50,1);
	cloud(900,620,40,1);
	tree2(50,250);
	tree2(1200,300);
	glColor3f(0.4,0.4,0.4);
	nline(480,0,20,0,-50);
	nline(520,0,20,0,-100);
	lion8(0,0);
	net();
	drawText(300,720,1,0,0,30,"FEW DAYS LATER !!");
	glFlush();
	for(int i=0;i<=800;i++){  //mouse appers
			glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
			glColor3f(0.4,1.0,0.4);
			glBegin(GL_POLYGON);  //grass
			glVertex2i(0.0,0.0);
			glVertex2i(0.0,400.0);
			glVertex2i(1500.0,400.0);
			glVertex2i(1500.0,0.0);
			glEnd();
			glColor3f(0.97,1.0,0.41);
			circle(950,700,40);  //sun
			glColor3f(1,1,1);
			cloud(300,650,50,1);
			cloud(900,620,40,1);
			tree2(50,250);
			tree2(1200,300);
			glColor3f(0.4,0.4,0.4);
			nline(480,0,20,0,-50);
			nline(520,0,20,0,-100);
			lion8(0,0);
			net();
			drawText(300,720,1,0,0,0,"FEW DAYS LATER !!");
			mouse(1200-i,-200);
			glFlush();
	}
	drawText(300,720,1,0,0,70,"FEW DAYS LATER !!");
	drawText(350,690,1,0,0,30,"MOUSE:   What happend!  let me help you!");
	drawText(350,690,1,0,0,50,"MOUSE:   What happend!  let me help you!");
	drawText(350,660,1,0,0,30,"LION: How a small creature like you can help me.");
	drawText(350,660,1,0,0,50,"LION: How a small creature like you can help me.");
	drawText(350,620,0,1,0,30,"PRESS '5' FOR NEXT SLIDE");
	glFlush();
}

void win5(){
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glColor3f(0.4,1.0,0.4);
	glBegin(GL_POLYGON);  //grass
	glVertex2i(0.0,0.0);
	glVertex2i(0.0,400.0);
	glVertex2i(1500.0,400.0);
	glVertex2i(1500.0,0.0);
	glEnd();
	glColor3f(0.97,1.0,0.41);
	circle(950,700,40);  //sun
	glColor3f(1,1,1);
	cloud(300,650,50,1);
	cloud(900,620,40,1);
	tree2(50,250);
	tree2(1200,300);
	glColor3f(0.4,0.4,0.4);
	nline(480,0,20,0,-50);
	nline(520,0,20,0,-100);
	lion8(0,0);
	net();
	mouse(400,-200);
	glFlush();
	for(int i=0;i<400;i++){    //pause
		glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
		glColor3f(0.4,1.0,0.4);
		glBegin(GL_POLYGON);  //grass
		glVertex2i(0.0,0.0);
		glVertex2i(0.0,400.0);
		glVertex2i(1500.0,400.0);
		glVertex2i(1500.0,0.0);
		glEnd();
		glColor3f(0.97,1.0,0.41);
		circle(950,700,40);  //sun
		glColor3f(1,1,1);
		cloud(300,650,50,1);
		cloud(900,620,40,1);
		tree2(50,250);
		tree2(1200,300);
		glColor3f(0.4,0.4,0.4);
		nline(480,0,20,0,-50);
		nline(520,0,20,0,-100);
		lion8(0,0);
		net();
		mouse(400,-200);
		glFlush();
	}
	for(i=0;i<400;i++){			//mouse moves left
		glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
		glColor3f(0.4,1.0,0.4);
		glBegin(GL_POLYGON);  //grass
		glVertex2i(0.0,0.0);
		glVertex2i(0.0,400.0);
		glVertex2i(1500.0,400.0);
		glVertex2i(1500.0,0.0);
		glEnd();
		glColor3f(0.97,1.0,0.41);
		circle(950,700,40);  //sun
		glColor3f(1,1,1);
		cloud(300,650,50,1);
		cloud(900,620,40,1);
		tree2(50,250);
		tree2(1200,300);
		glColor3f(0.4,0.4,0.4);
		nline(480,0,20,0,-50);
		nline(520,0,20,0,-100);
		lion8(0,0);
		net();
		mouse(400-i,-200);
		glFlush();
	}
	for(i=0;i<200;i++){			//pause
		glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
		glColor3f(0.4,1.0,0.4);
		glBegin(GL_POLYGON);  //grass
		glVertex2i(0.0,0.0);
		glVertex2i(0.0,400.0);
		glVertex2i(1500.0,400.0);
		glVertex2i(1500.0,0.0);
		glEnd();
		glColor3f(0.97,1.0,0.41);
		circle(950,700,40);  //sun
		glColor3f(1,1,1);
		cloud(300,650,50,1);
		cloud(900,620,40,1);
		tree2(50,250);
		tree2(1200,300);
		glColor3f(0.4,0.4,0.4);
		nline(480,0,20,0,-50);
		nline(520,0,20,0,-100);
		lion8(0,0);
		net();
		mouse(0,-200);
		glFlush();
	}
	for(i=0;i<300;i++){			//mouse cuts 1
		glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
		glColor3f(0.4,1.0,0.4);
		glBegin(GL_POLYGON);  //grass
		glVertex2i(0.0,0.0);
		glVertex2i(0.0,400.0);
		glVertex2i(1500.0,400.0);
		glVertex2i(1500.0,0.0);
		glEnd();
		glColor3f(0.97,1.0,0.41);
		circle(950,700,40);  //sun
		glColor3f(1,1,1);
		cloud(300,650,50,1);
		cloud(900,620,40,1);
		tree2(50,250);
		tree2(1200,300);
		glColor3f(0.4,0.4,0.4);
		nline(480,0,20,0,-50);
		nline(520,0,20,0,-100);
		lion8(0,0);
		net();
		mouse(20,-120);
		glFlush();
	}
	for(i=0;i<300;i++){			//mouse cuts 2
		glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
		glColor3f(0.4,1.0,0.4);
		glBegin(GL_POLYGON);  //grass
		glVertex2i(0.0,0.0);
		glVertex2i(0.0,400.0);
		glVertex2i(1500.0,400.0);
		glVertex2i(1500.0,0.0);
		glEnd();
		glColor3f(0.97,1.0,0.41);
		circle(950,700,40);  //sun
		glColor3f(1,1,1);
		cloud(300,650,50,1);
		cloud(900,620,40,1);
		tree2(50,250);
		tree2(1200,300);
		glColor3f(0.4,0.4,0.4);
		nline(480,0,20,0,-50);
		nline(520,0,20,0,-100);
		lion8(0,0);
		net();
		glColor3f(0.75,0.5,0.25);
		circle(700,180,20);
		mouse(-100,-80);
		glFlush();
	}
	for(i=0;i<300;i++){			//mouse cuts 3
		glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
		glColor3f(0.4,1.0,0.4);
		glBegin(GL_POLYGON);  //grass
		glVertex2i(0.0,0.0);
		glVertex2i(0.0,400.0);
		glVertex2i(1500.0,400.0);
		glVertex2i(1500.0,0.0);
		glEnd();
		glColor3f(0.97,1.0,0.41);
		circle(950,700,40);  //sun
		glColor3f(1,1,1);
		cloud(300,650,50,1);
		cloud(900,620,40,1);
		tree2(50,250);
		tree2(1200,300);
		glColor3f(0.4,0.4,0.4);
		nline(480,0,20,0,-50);
		nline(520,0,20,0,-100);
		lion8(0,0);
		net();
		glColor3f(0.75,0.5,0.25);
		circle(700,180,20);
		circle(580,220,20);
		mouse(-20,-30);
		glFlush();
	}
	for(i=0;i<300;i++){			//mouse cuts 4
		glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
		glColor3f(0.4,1.0,0.4);
		glBegin(GL_POLYGON);  //grass
		glVertex2i(0.0,0.0);
		glVertex2i(0.0,400.0);
		glVertex2i(1500.0,400.0);
		glVertex2i(1500.0,0.0);
		glEnd();
		glColor3f(0.97,1.0,0.41);
		circle(950,700,40);  //sun
		glColor3f(1,1,1);
		cloud(300,650,50,1);
		cloud(900,620,40,1);
		tree2(50,250);
		tree2(1200,300);
		glColor3f(0.4,0.4,0.4);
		nline(480,0,20,0,-50);
		nline(520,0,20,0,-100);
		lion8(0,0);
		net();
		glColor3f(0.75,0.5,0.25);
		circle(700,180,20);
		circle(580,220,20);
		circle(660,270,20);
		mouse(-160,-30);
		glFlush();
	}
	for(i=0;i<300;i++){			//mouse cuts 5
		glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
		glColor3f(0.4,1.0,0.4);
		glBegin(GL_POLYGON);  //grass
		glVertex2i(0.0,0.0);
		glVertex2i(0.0,400.0);
		glVertex2i(1500.0,400.0);
		glVertex2i(1500.0,0.0);
		glEnd();
		glColor3f(0.97,1.0,0.41);
		circle(950,700,40);  //sun
		glColor3f(1,1,1);
		cloud(300,650,50,1);
		cloud(900,620,40,1);
		tree2(50,250);
		tree2(1200,300);
		glColor3f(0.4,0.4,0.4);
		nline(480,0,20,0,-50);
		nline(520,0,20,0,-100);
		lion8(0,0);
		net();
		glColor3f(0.75,0.5,0.25);
		circle(700,180,20);
		circle(580,220,20);
		circle(660,270,20);
		circle(520,270,20);
		mouse(-160,-120);
		glFlush();
	}
	for(i=0;i<300;i++){			//mouse cuts 6
		glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
		glColor3f(0.4,1.0,0.4);
		glBegin(GL_POLYGON);  //grass
		glVertex2i(0.0,0.0);
		glVertex2i(0.0,400.0);
		glVertex2i(1500.0,400.0);
		glVertex2i(1500.0,0.0);
		glEnd();
		glColor3f(0.97,1.0,0.41);
		circle(950,700,40);  //sun
		glColor3f(1,1,1);
		cloud(300,650,50,1);
		cloud(900,620,40,1);
		tree2(50,250);
		tree2(1200,300);
		glColor3f(0.4,0.4,0.4);
		nline(480,0,20,0,-50);
		nline(520,0,20,0,-100);
		lion8(0,0);
		net();
		glColor3f(0.75,0.5,0.25);
		circle(700,180,20);
		circle(580,220,20);
		circle(660,270,20);
		circle(520,270,20);
		circle(520,180,20);
		mouse(150,20);
		glFlush();
	}
	for(i=0;i<300;i++){			//mouse cuts complete
		glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
		glColor3f(0.4,1.0,0.4);
		glBegin(GL_POLYGON);  //grass
		glVertex2i(0.0,0.0);
		glVertex2i(0.0,400.0);
		glVertex2i(1500.0,400.0);
		glVertex2i(1500.0,0.0);
		glEnd();
		glColor3f(0.97,1.0,0.41);
		circle(950,700,40);  //sun
		glColor3f(1,1,1);
		cloud(300,650,50,1);
		cloud(900,620,40,1);
		tree2(50,250);
		tree2(1200,300);
		lion();
		glColor3f(0.1,0.1,0.1); 
		arc(810.0,295.0,15,2.2,4.08); //eyes open
		arc(850.0,295.0,15,2.2,4.08);
		arc(810.0,277.0,15,-0.94,0.94);
		arc(850.0,277.0,15,-0.94,0.94);
		circle(810,285,5);
		circle(850,285,5);
		mouse(0,-200);
		glFlush();
	}
	drawText(350,500,0,1,0,30,"PRESS '6' FOR NEXT SLIDE");
	glFlush();
}

void happy(){
	for(int i=0;i<60;i++){   //jumps up
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		background6();
		tree(300, 250);
		body6();
		head6();
		mouse(600,-35+i);
		drawText(500,700,0,1,0,0,"They become good friends and lived happily after!");
		glFlush();
	}
	for(i=60;i>0;i--){		//jumps down
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		background6();
		tree(300, 250);
		body6();
		head6();
		mouse(600,-35+i);
		drawText(500,700,0,1,0,0,"They become good friends and lived happily after!");
		glFlush();
	}
	for(i=0;i<300;i++){		//pause
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		background6();
		tree(300, 250);
		body6();
		head6();
		if(i<80){
		glColor3f(0.75,0.5,0.25); 
		arc(810.0,527.0,15,-0.94,0.94); //eyes close
		arc(850.0,527.0,15,-0.94,0.94);
		circle(810,535,5);
		circle(850,535,5);
		}
		mouse(600,-35);
		drawText(500,700,0,1,0,0,"They become good friends and lived happily after!");
		glFlush();
	}
}

void win6(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	background6();
	tree(300, 250);
	body6();
	head6();
	mouse(600,-35);
	drawText(500,700,0,1,0,30,"They become good friends and lived happily after!");
	drawText(500,700,0,1,0,30,"They become good friends and lived happily after!");
	happy();
	happy();
	happy();
	drawText(500,660,1,0,0,30,"PRESS '7' FOR NEXT SLIDE");
	glFlush();
}

void win7(){
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glColor3f(0.2,0.2,0.2);
	glBegin(GL_POLYGON);  //background
	glVertex2i(0.0,0.0);
	glVertex2i(0.0,750.0);
	glVertex2i(1500.0,750.0);
	glVertex2i(1500.0,0.0);
	glEnd();
	drawText(500,600,1,1,1,30,"This happend long ago but now time have changed");
	drawText(510,530,1,1,1,30,"Lets see what happened in morden time(Kalyug).");
	drawText(510,530,1,1,1,50,"Lets see what happened in morden time(Kalyug).");
	drawText(600,400,1,0,0,30,"PRESS '8' FOR NEXT SLIDE");
	glFlush();
}

void win8(){
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glColor3f(0.4,1.0,0.4);
	glBegin(GL_POLYGON);  //grass
	glVertex2i(0.0,0.0);
	glVertex2i(0.0,750.0);
	glVertex2i(1500.0,750.0);
	glVertex2i(1500.0,0.0);
	glEnd();
	tree2(0,250);
	mouse(-290,0);
	lion2();
	glColor3f(1,0,0);
	for(int i=0;i<3000;i++){
		circle(395,305-i/50,3);
		circle(385,300-i/50,3);
		circle(370,290-i/50,4);
		circle(405,290-i/50,2);
		circle(409,290-i/50,2);
		glFlush();
	}
	drawText(250,720,1,0,0,30,"In the same previous scenario,lion killed the mouse instead.");
	drawText(250,720,1,0,0,30,"In the same previous scenario,lion killed the mouse instead.");
	drawText(300,650,0,0,1,30,"PRESS '9' FOR NEXT SLIDE");
	glFlush();
}

void win9(){
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	background8();
	lion8(50,0);
	prison();
	drawText(250,700,1,0,0,30,"hence the mouse was not there to cut the net");
	drawText(250,670,1,0,0,30,"and the lion ended up in the zoo instead.");
	drawText(250,670,1,0,0,50,"and the lion ended up in the zoo instead.");
	drawText(250,620,0,1,0,30,"PRESS '0' FOR FINAL SLIDE");
	glFlush();
}

void win0(){
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glColor3f(0.2,0.2,0.2);
	glBegin(GL_POLYGON);  //background
	glVertex2i(0.0,0.0);
	glVertex2i(0.0,750.0);
	glVertex2i(1500.0,750.0);
	glVertex2i(1500.0,0.0);
	glEnd();
	drawText(560,600,1,0,0,30,"Moral of the story is that:");
	drawText(500,550,1,1,1,30,"Never underestimate the small things");
	drawText(510,500,1,1,1,30,"It can have huge impact on our life");
	drawText(410,450,1,1,1,30,"It also shows that the world has greatly changed over time");
	drawText(450,400,1,1,1,30,"And we sometimes destroy our future oppertunities");
	drawText(500,350,1,1,1,30,"by making wrong and immoral choices!");
	drawText(500,350,1,1,1,30,"by making wrong and immoral choices!");
	drawText(580,280,0,0,0,30,"PRESS 'e' TO EXIT");
	glFlush();
}

void display(){
	glClearColor(0.0,0.5,2.0,0.0);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	
	drawText(500,650,1,1,1,d,"PROJECT TITLE:");
	drawText(700,650,1,1,0,d,"LION'S LIFE LESSON");

	drawText(500,600,1,1,1,d,"Developed By:");
	
	drawText(600,550,0,1,0,d,"MAYANK  GOYAL");
	drawText(600,520,1,1,1,d,"(1DS14CS722)");

	drawText(300,480,0,1,0,d,"OMKAR  SINHA");
	drawText(300,450,1,1,1,d,"(1DS14CS729)");

	drawText(900,480,0,1,0,d,"AJIT  KUMAR KESHARI");
	drawText(900,450,1,1,1,d,"(1DS14CS702)");

	drawText(500.0,380.0,1,1,1,d,"UNDER THE GUIDENCE OF");
	drawText(500.0,340.0,1,1,0,d,"Prof.Shasidhar B");
	
	drawText(500.0,300.0,1,1,0,d,"Assistant Professor, Dept of CSE");
	drawText(500.0,260,1,1,0,d,"DSCE, Bangalore");

	drawText(500,150,0,1,0,d,"PRESS '1' TO START");
	glFlush();
}

void Normalkey(unsigned char k,int x,int y)
{
	switch(k)
	{
		case '1':win1();
			     break;

		case '2':win2();
				 break;

		case '3':win3();
				 break;

		case '4':win4();
				 break;

		case '5':win5();
				 break;

		case '6':win6();
				 break;

		case '7':win7();
				 break;

		case '8':win8();
			     break;

		case '9':win9();
				 break;

		case '0':win0();
				 break;

		case 'd':d=20;
				 display();
				 break;

		case 'e':exit(0);
	}
}

void main(int argc,char **argv){
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB|GLUT_DEPTH|GLUT_SINGLE);
	glutInitWindowSize(1500,750);
	glutCreateWindow("title");
	glClearColor(0.50,0.88,0.96,0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,1500,0,750);
	glutDisplayFunc(display);
	glutKeyboardFunc(Normalkey);
	glutMainLoop();
}
