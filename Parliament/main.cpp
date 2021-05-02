#include <cstdio>
#include <cstdio>
#include<GL/gl.h>
#include <GL/glut.h>
#include<math.h>
#include<windows.h>
#include<GL/glut.h>
#include<stdlib.h>
#include <iostream>
#include<stdio.h>
#include<string.h>
# define PI           3.14159265358979323846

using namespace std;

GLfloat position1 = 0.0f;
GLfloat position2 = 0.0f;
GLfloat speed = 2;
GLfloat speed2 = 2;
float xn=0;
float yq;
float xm;
float yp;
float s,t;
float c,v;
float m,n;
float k,l,q,w;
float _rain = 0.0;
bool rainday = false;

//timer update start
void update(int value){
    if(position1 > 1200)
        position1 = -5;
    position1 += speed;
    if(position2 > 1200)
        position2 = -5;
    position2 += speed2;
	glutPostRedisplay();
	glutTimerFunc(100, update, 0);
}
//timer update end

void day(int x, int y){
    //sky day start
    glBegin(GL_QUADS);
	glColor3ub(102, 102, 255);
	glVertex2i(q+0,w+400);
	glVertex2i(q+0,w+700);
	glVertex2i(q+1200,w+700);
	glVertex2i(q+1200,w+400);
	glEnd();
	//sky day end

    //sun start
	int i7;
    GLint x7= 1050;
    GLint y7= 640;
    GLfloat radius7 =30;
    int triangleAmount7 = 30;
    GLfloat twicePi7 = 2.0f * PI;
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 102, 102);
    glVertex2f(q+x7, w+y7);
    for(i7 = 0; i7 <= triangleAmount7; i7++){
        glVertex2f(
            q+x7 + (radius7 * cos(i7 *  twicePi7 / triangleAmount7)),
            w+y7 + (radius7 * sin(i7 * twicePi7 / triangleAmount7))
        );
    }
    glEnd();
    //sun end
}

//Road divider function start
void roaddevider(GLint x1,GLint x2,GLint x3,GLint x4){
    glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);
    glVertex2i(x1,155);
	glVertex2i(x2,145);
	glVertex2i(x3,145);
	glVertex2i(x4,155);
	glEnd();
}
//road divider function end

//wheel function start
void wheel (int a, int b){
    int i;
    GLint x= a+20;
    GLint y= b+65;
    GLfloat radius =12;
    int triangleAmount = 10;

    GLfloat twicePi = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(0, 0, 0);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++)
    {
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();
}
//wheel function end

//Car Function start
void car1(int a, int b)
{
    glBegin(GL_QUADS);
    glColor3f(0.50, 1, 0.50);
    glVertex2i(a+300, b+90);
    glVertex2i(a+450, b+90);
    glVertex2i(a+450, b+120);
    glVertex2i(a+300, b+120);

    glVertex2i(a+300, b+120);
    glVertex2i(a+340, b+145);
    glVertex2i(a+380, b+145);
    glVertex2i(a+410, b+120);

    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2i(a+302, b+122);
    glVertex2i(a+342, b+143);
    glVertex2i(a+378, b+143);
    glVertex2i(a+406, b+122);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(0.50, 0.0, 0.0);
    glVertex2i(a+360, b+120);
    glVertex2i(a+360, b+145);
    glVertex2i(a+355, b+145);
    glVertex2i(a+355, b+120);
    glEnd();

}

void car2(int a, int b)
{
    glBegin(GL_QUADS);
    glColor3f(1, 1, 0);
    glVertex2i(a+300, b+90);
    glVertex2i(a+450, b+90);
    glVertex2i(a+450, b+120);
    glVertex2i(a+300, b+120);

    glVertex2i(a+300, b+120);
    glVertex2i(a+340, b+145);
    glVertex2i(a+380, b+145);
    glVertex2i(a+410, b+120);

    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2i(a+302, b+122);
    glVertex2i(a+342, b+143);
    glVertex2i(a+378, b+143);
    glVertex2i(a+406, b+122);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(245.0, 242.0, 108.0);
    glVertex2i(a+360, b+120);
    glVertex2i(a+360, b+145);
    glVertex2i(a+355, b+145);
    glVertex2i(a+355, b+120);
    glEnd();

}

void car3(int a, int b)
{
    glBegin(GL_QUADS);
    glColor3f(1, 0, 0);
    glVertex2i(a-300, b+90);
    glVertex2i(a-450, b+90);
    glVertex2i(a-450, b+120);
    glVertex2i(a-300, b+120);

    glVertex2i(a-300, b+120);
    glVertex2i(a-340, b+145);
    glVertex2i(a-380, b+145);
    glVertex2i(a-410, b+120);

    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2i(a-302, b+122);
    glVertex2i(a-342, b+143);
    glVertex2i(a-378, b+143);
    glVertex2i(a-406, b+122);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(245.0, 242.0, 108.0);
    glVertex2i(a-360, b+120);
    glVertex2i(a-360, b+145);
    glVertex2i(a-355, b+145);
    glVertex2i(a-355, b+120);
    glEnd();

}

void car4(int a, int b)
{
    glBegin(GL_QUADS);
    glColor3f(0, 0, 1);
    glVertex2i(a-300, b+90);
    glVertex2i(a-450, b+90);
    glVertex2i(a-450, b+120);
    glVertex2i(a-300, b+120);

    glVertex2i(a-300, b+120);
    glVertex2i(a-340, b+145);
    glVertex2i(a-380, b+145);
    glVertex2i(a-410, b+120);


    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2i(a-302, b+122);
    glVertex2i(a-342, b+143);
    glVertex2i(a-378, b+143);
    glVertex2i(a-406, b+122);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(245.0, 242.0, 108.0);
    glVertex2i(a-360, b+120);
    glVertex2i(a-360, b+145);
    glVertex2i(a-355, b+145);
    glVertex2i(a-355, b+120);
    glEnd();

}

void car5(int a, int b)
{
    glBegin(GL_QUADS);
    glColor3f(0.6, 0.6, 0.6);
    glVertex2i(a+300, b+90);
    glVertex2i(a+450, b+90);
    glVertex2i(a+450, b+120);
    glVertex2i(a+300, b+120);

    glVertex2i(a+300, b+120);
    glVertex2i(a+340, b+145);
    glVertex2i(a+380, b+145);
    glVertex2i(a+410, b+120);

    glEnd();
    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2i(a+302, b+122);
    glVertex2i(a+342, b+143);
    glVertex2i(a+378, b+143);
    glVertex2i(a+406, b+122);
    glEnd();

    glBegin(GL_QUADS);
    glColor3f(245.0, 242.0, 108.0);
    glVertex2i(a+360, b+120);
    glVertex2i(a+360, b+145);
    glVertex2i(a+355, b+145);
    glVertex2i(a+355, b+120);
    glEnd();
}

//Lamp function Day start
void lamp(int a, int b){
    int i15;
    GLint x15= 915;
    GLint y15= 370;
    GLfloat radius15 =15;
    int triangleAmount15 = 30;
    GLfloat twicePi15 = 2.0f * PI;
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(96, 96, 96);
    glVertex2f(a+x15, b+y15);
    for(i15 = 0; i15 <= triangleAmount15; i15++)
    {
        glVertex2f(
            a+x15 + (radius15 * cos(i15*  twicePi15 / triangleAmount15)),
            b+y15 + (radius15 * sin(i15 * twicePi15 / triangleAmount15))
        );
    }
    glEnd();

    int i13;
    GLint x13= 515;
    GLint y13= 370;
    GLfloat radius13 =15;
    int triangleAmount13 = 30;
    GLfloat twicePi13 = 2.0f * PI;
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(96, 96, 96);
    glVertex2f(a+x13, b+y13);
    for(i13 = 0; i13 <= triangleAmount13; i13++)
    {
        glVertex2f(
            a+x13 + (radius13 * cos(i13 *  twicePi13 / triangleAmount13)),
            b+y13 + (radius13 * sin(i13 * twicePi13 / triangleAmount13))
        );
    }
    glEnd();

	int i14;
    GLint x14= 715;
    GLint y14= 370;
    GLfloat radius14 =15;
    int triangleAmount14 = 30;
    GLfloat twicePi14 = 2.0f * PI;
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(96, 96, 96);
    glVertex2f(a+x14, b+y14);
    for(i14 = 0; i14 <= triangleAmount14; i14++)
    {
        glVertex2f(
            a+x14 + (radius14 * cos(i14 *  twicePi14 / triangleAmount14)),
            b+y14 + (radius14 * sin(i14 * twicePi14 / triangleAmount14))
        );
    }
    glEnd();

    int i12;
    GLint x12= 315;
    GLint y12= 370;
    GLfloat radius12 =15;
    int triangleAmount12 = 30;
    GLfloat twicePi12 = 2.0f * PI;
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(96, 96, 96);
    glVertex2f(a+x12, b+y12);
    for(i12 = 0; i12 <= triangleAmount12; i12++)
    {
        glVertex2f(
            a+x12 + (radius12 * cos(i12 *  twicePi12 / triangleAmount12)),
            b+y12 + (radius12 * sin(i12 * twicePi12 / triangleAmount12))
        );
    }
    glEnd();

    int i11;
    GLint x11= 115;
    GLint y11= 370;
    GLfloat radius11 =15;
    int triangleAmount11 = 30;
    GLfloat twicePi11 = 2.0f * PI;
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(96, 96, 96);
    glVertex2f(a+x11, b+y11);
    for(i11 = 0; i11 <= triangleAmount11; i11++)
    {
        glVertex2f(
            a+x11 + (radius11 * cos(i11 *  twicePi11 / triangleAmount11)),
            b+y11 + (radius11 * sin(i11 * twicePi11 / triangleAmount11))
        );
    }
    glEnd();

    int i16;
    GLint x16= 1115;
    GLint y16= 370;
    GLfloat radius16 =15;
    int triangleAmount16 = 30;
    GLfloat twicePi16 = 2.0f * PI;
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(96, 96, 96);
    glVertex2f(a+x16, b+y16);
    for(i16 = 0; i16 <= triangleAmount16; i16++)
    {
        glVertex2f(
            a+x16 + (radius16 * cos(i16 *  twicePi16 / triangleAmount16)),
            b+y16 + (radius16 * sin(i16 * twicePi16 / triangleAmount16))
        );
    }
    glEnd();

    int i17;
    GLint x17= 115;
    GLint y17= 70;
    GLfloat radius17 =15;
    int triangleAmount17 = 30;
    GLfloat twicePi17 = 2.0f * PI;
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(96, 96, 96);
    glVertex2f(a+x17, b+y17);
    for(i17 = 0; i17 <= triangleAmount17; i17++)
    {
        glVertex2f(
            a+x17 + (radius17 * cos(i17 *  twicePi17 / triangleAmount17)),
            b+y17 + (radius17 * sin(i17 * twicePi17 / triangleAmount17))
        );
    }
    glEnd();

    int i18;
    GLint x18= 315;
    GLint y18= 70;
    GLfloat radius18 =15;
    int triangleAmount18 = 30;
    GLfloat twicePi18 = 2.0f * PI;
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(96, 96, 96);
    glVertex2f(a+x18, b+y18);
    for(i18 = 0; i18 <= triangleAmount18; i18++)
    {
        glVertex2f(
            a+x18 + (radius18 * cos(i18 *  twicePi18 / triangleAmount18)),
            b+y18 + (radius18 * sin(i18 * twicePi18 / triangleAmount18))
        );
    }
    glEnd();

    int i19;
    GLint x19= 515;
    GLint y19= 70;
    GLfloat radius19 =15;
    int triangleAmount19 = 30;
    GLfloat twicePi19 = 2.0f * PI;
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(96, 96, 96);
    glVertex2f(a+x19, b+y19);
    for(i19 = 0; i19 <= triangleAmount19; i19++)
    {
        glVertex2f(
            a+x19 + (radius19 * cos(i19 *  twicePi19 / triangleAmount19)),
            b+y19 + (radius19 * sin(i19 * twicePi19 / triangleAmount19))
        );
    }
    glEnd();

    int i20;
    GLint x20= 715;
    GLint y20= 70;
    GLfloat radius20 =15;
    int triangleAmount20 = 30;
    GLfloat twicePi20 = 2.0f * PI;
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(96, 96, 96);
    glVertex2f(a+x20, b+y20);
    for(i20 = 0; i20 <= triangleAmount20; i20++)
    {
        glVertex2f(
            a+x20 + (radius20 * cos(i20 *  twicePi20 / triangleAmount20)),
            b+y20 + (radius20 * sin(i20 * twicePi20 / triangleAmount20))
        );
    }
    glEnd();

    int i21;
    GLint x21= 915;
    GLint y21= 70;
    GLfloat radius21 =15;
    int triangleAmount21 = 30;
    GLfloat twicePi21 = 2.0f * PI;
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(96, 96, 96);
    glVertex2f(a+x21, b+y21);
    for(i21 = 0; i21 <= triangleAmount21; i21++)
    {
        glVertex2f(
            a+x21 + (radius21 * cos(i21 *  twicePi21 / triangleAmount21)),
            b+y21 + (radius21 * sin(i21 * twicePi21 / triangleAmount21))
        );
    }
    glEnd();

    int i22;
    GLint x22= 1115;
    GLint y22= 70;
    GLfloat radius22 =15;
    int triangleAmount22 = 30;
    GLfloat twicePi22 = 2.0f * PI;
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(96, 96, 96);
    glVertex2f(a+x22, b+y22);
    for(i22 = 0; i22 <= triangleAmount22; i22++)
    {
        glVertex2f(
            a+x22 + (radius22 * cos(i22 *  twicePi22 / triangleAmount22)),
            b+y22 + (radius22 * sin(i22 * twicePi22 / triangleAmount22))
        );
    }
    glEnd();
}
//lamp function day end

//Big Tree Function start
void tree(int x, int y){
    glColor3f(0, 0.8, 0.2);
    glBegin(GL_TRIANGLES);
    glVertex2i(x+445, y+340);
    glVertex2i(x+492, y+440);
	glVertex2i(x+540, y+340);
	glEnd();

    glColor3f(0, 0.8, 0.5);
	glBegin(GL_TRIANGLES);
    glVertex2i(x+445, y+360);
    glVertex2i(x+492, y+460);
	glVertex2i(x+540, y+360);
	glEnd();

	glColor3f(0.4, 0.5, 0.0);
	glBegin(GL_QUADS);
    glVertex2i(x+497, y+340);
    glVertex2i(x+486, y+340);
    glVertex2i(x+486, y+250);
    glVertex2i(x+497, y+250);
    glEnd();
}
//Big tree function end

//car moving start
void carmove(){
    	if(xn>1200.0){
            xn= -850.0;
        }
        xn+=0.0001;

        if(xm<-600.0){
            xm=900.0;
        }
        xm-=0.0001;

        if(m>15.0){
            m= 0.0;
        }
        m+=0.0001;
}
//car moving end

//grass function start
void grass(int a, int b)
{
    glBegin(GL_POLYGON);
    glColor3f(0.0,0.90,0.0);
    glVertex2i(a+50, b+0);
    glVertex2i(a+50, b+30);
    glVertex2i(a+35, b+5);
    glVertex2i(a+25, b+35);
    glVertex2i(a+15, b+6);
    glVertex2i(a+15, b+32);
    glVertex2i(a+10, b+0);
    glVertex2i(a+10, b+35);
    glVertex2i(a+0, b+0);
    glEnd();
}
//grass function end

void myDisplay(void)
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
    glColor3ub(255, 255, 255);
    glPointSize(5.0);

    //moon
	int i8;
    GLint x8= 100;
    GLint y8= 640;
    GLfloat radius8 =30;
    int triangleAmount8 = 30;
    GLfloat twicePi8 = 2.0f * PI;
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(224, 224, 224);
    glVertex2f(x8, y8);
    for(i8 = 0; i8 <= triangleAmount8; i8++)
    {
        glVertex2f(
            x8 + (radius8 * cos(i8 *  twicePi8 / triangleAmount8)),
            y8 + (radius8 * sin(i8 * twicePi8 / triangleAmount8))
        );
    }
    glEnd();

    day(q,w);
	//background green start
	glBegin(GL_QUADS);
	glColor3f(0.1f, 0.1f, 0.1f);
	glVertex2i(0,450);
	glVertex2i(0,300);
	glVertex2i(1200,300);
	glVertex2i(1200,450);
	glEnd();
	//background green end

	//cloud start
	//cloud1
	glPushMatrix();
    glTranslatef(position1,0.0f, 0.0f);
	int i;
    GLint x= 50;
    GLint y= 640;
    GLfloat radius =30;
    int triangleAmount = 30;
    GLfloat twicePi = 2.0f * PI;
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(224, 224, 224);
    glVertex2f(x, y);
    for(i = 0; i <= triangleAmount; i++){
        glVertex2f(
            x + (radius * cos(i *  twicePi / triangleAmount)),
            y + (radius * sin(i * twicePi / triangleAmount))
        );
    }
    glEnd();

    //cloud2
	glPushMatrix();
    glTranslatef(position1,0.0f, 0.0f);
	int i7;
    GLint x7= 60;
    GLint y7= 740;
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(224, 224, 224);
    glVertex2f(x7, y7);
    for(i7 = 0; i7 <= triangleAmount; i7++){
        glVertex2f(
            x7 + (radius * cos(x7 *  twicePi / triangleAmount)),
            y7 + (radius * sin(x7 * twicePi / triangleAmount))
        );
    }
    glEnd();

    //cloud3
	glPushMatrix();
    glTranslatef(position1,0.0f, 0.0f);
	int i77;
    GLint x77= 70;
    GLint y77= 840;
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(224, 224, 224);
    glVertex2f(x77, y77);
    for(i77 = 0; i77 <= triangleAmount; i77++){
        glVertex2f(
            x77 + (radius * cos(x77 *  twicePi / triangleAmount)),
            y77 + (radius * sin(x77 * twicePi / triangleAmount))
        );
    }
    glEnd();

    int i3;
    GLint x3= 90;
    GLint y3= 660;
    GLfloat radius3 =30;
    int triangleAmount3 = 30;
    GLfloat twicePi3 = 2.0f * PI;
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(224, 224, 224);
    glVertex2f(x3, y3);
    for(i3 = 0; i3 <= triangleAmount; i3++){
        glVertex2f(
            x3 + (radius3 * cos(i3 *  twicePi3 / triangleAmount3)),
            y3 + (radius3 * sin(i3 * twicePi3 / triangleAmount3))
        );
    }
    glEnd();

    int i4;
    GLint x4= 140;
    GLint y4= 660;
    GLfloat radius4 =30;
    int triangleAmount4 = 30;
    GLfloat twicePi4 = 2.0f * PI;
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(224, 224, 224);
    glVertex2f(x4, y4);
    for(i4 = 0; i4 <= triangleAmount4; i4++){
        glVertex2f(
            x4 + (radius4 * cos(i4 *  twicePi4 / triangleAmount4)),
            y4 + (radius4 * sin(i4 * twicePi4 / triangleAmount4))
        );
    }
    glEnd();

    int i5;
    GLint x5= 90;
    GLint y5= 620;
    GLfloat radius5 =30;
    int triangleAmount5 = 30;
    GLfloat twicePi5 = 2.0f * PI;
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(224, 224, 224);
    glVertex2f(x5, y5);
    for(i5 = 0; i5 <= triangleAmount5; i5++){
        glVertex2f(
            x5 + (radius5 * cos(i5 *  twicePi5 / triangleAmount5)),
            y5 + (radius5 * sin(i5 * twicePi5 / triangleAmount5))
        );
    }
    glEnd();

    int i6;
    GLint x6= 130;
    GLint y6= 630;
    GLfloat radius6 =30;
    int triangleAmount6 = 30;
    GLfloat twicePi6 = 2.0f * PI;
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(224, 224, 224);
    glVertex2f(x6, y6);
    for(i6 = 0; i6 <= triangleAmount6; i6++){
        glVertex2f(
            x6 + (radius6 * cos(i6 *  twicePi6 / triangleAmount6)),
            y6 + (radius6 * sin(i6 * twicePi6 / triangleAmount6))
        );
    }
    glEnd();
    glPopMatrix();

    //cloud
	glPushMatrix();
    glTranslatef(position1,0.0f, 0.0f);
	int i69;
    GLint x69= 50;
    GLint y69= 640;
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(224, 224, 224);
    glVertex2f(x69, y6);
    for(i69 = 0; i69 <= triangleAmount; i69++){
        glVertex2f(
            x69 + (radius * cos(k *  twicePi / triangleAmount)),
            y69 + (radius * sin(k * twicePi / triangleAmount))
        );
    }
    glEnd();

    GLint x93= 90;
    GLint y93= 660;
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(224, 224, 224);
    glVertex2f(x93, y93);
    for(i3 = 0; i3 <= triangleAmount; i3++){
        glVertex2f(
            x3 + (radius3 * cos(i3 *  twicePi3 / triangleAmount3)),
            y3 + (radius3 * sin(i3 * twicePi3 / triangleAmount3))
        );
    }
    glEnd();

    int i44;
    GLint x44= 140;
    GLint y44= 660;
    GLfloat radius44 =30;
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(224, 224, 224);
    glVertex2f(x44, y44);
    for(i44 = 0; i44 <= triangleAmount4; i44++){
        glVertex2f(
            x44 + (radius44 * cos(i44 *  twicePi4 / triangleAmount4)),
            y44 + (radius44 * sin(i44 * twicePi4 / triangleAmount4))
        );
    }
    glEnd();

    int i55;
    GLint x55= 90;
    GLint y55= 620;
    GLfloat radius55 =30;
    int triangleAmount55 = 30;
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(224, 224, 224);
    glVertex2f(x55, y55);
    for(i55 = 0; i55 <= triangleAmount55; i55++){
        glVertex2f(
            x55 + (radius55 * cos(i55 *  twicePi5 / triangleAmount5)),
            y55 + (radius55 * sin(i55 * twicePi5 / triangleAmount5))
        );
    }
    glEnd();

    //cloud3
	glPushMatrix();
    glTranslatef(position1,0.0f, 0.0f);
	int i690;
    GLint x690= 60;
    GLint y690= 740;
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(222, 222, 222);
    glVertex2f(x690, y690);
    for(i690 = 0; i690 <= triangleAmount; i690++){
        glVertex2f(
            x690 + (radius * cos(i690 *  twicePi / triangleAmount)),
            y690 + (radius * sin(i690 * twicePi / triangleAmount))
        );
    }
    glEnd();

    int i931;
    GLint x931= 90;
    GLint y931= 660;
    GLfloat twicePi931 = 2.0f * PI;
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(224, 224, 224);
    glVertex2f(x931, y931);
    for(i931 = 0; i931 <= triangleAmount; i931++){
        glVertex2f(
            x3 + (radius3 * cos(i931 *  twicePi931 / triangleAmount3)),
            y3 + (radius3 * sin(i931 * twicePi931 / triangleAmount3))
        );
    }
    glEnd();
    //cloud3
    int i444;
    GLint x444= 140;
    GLint y444= 660;
    GLfloat radius444 =30;
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(224, 224, 224);
    glVertex2f(x444, y444);
    for(i444 = 0; i444 <= triangleAmount4; i444++){
        glVertex2f(
            x444 + (radius444 * cos(i444 *  twicePi4 / triangleAmount4)),
            y444 + (radius444 * sin(i444 * twicePi4 / triangleAmount4))
        );
    }
    glEnd();

    int i555;
    GLint x555= 90;
    GLint y555= 620;
    GLfloat radius555 =30;
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(224, 224, 224);
    glVertex2f(x555, y555);
    for(i555 = 0; i555 <= triangleAmount55; i555++){
        glVertex2f(
            x555 + (radius555 * cos(i555 *  twicePi5 / triangleAmount5)),
            y555 + (radius555 * sin(i555 * twicePi5 / triangleAmount5))
        );
    }
    glEnd();


    glPopMatrix();
    //cloud end

    //column 9 start
	glBegin(GL_QUADS);
	glColor3ub(192, 192, 192);
	glVertex2i(550,590);
	glVertex2i(550,390);
	glVertex2i(450,390);
	glVertex2i(450,590);
	glEnd();

    glBegin(GL_LINES);
	glColor3ub(255, 255, 255);
    glVertex2i(550, 570);
    glVertex2i(450, 570);
    glEnd();

    glBegin(GL_LINES);
	glColor3ub(255, 255, 255);
    glVertex2i(550, 555);
    glVertex2i(450, 555);
    glEnd();

    glBegin(GL_LINES);
	glColor3ub(255, 255, 255);
    glVertex2i(550, 540);
    glVertex2i(450, 540);
    glEnd();

    glBegin(GL_LINES);
	glColor3ub(255, 255, 255);
    glVertex2i(550, 525);
    glVertex2i(450, 525);
    glEnd();

    glBegin(GL_LINES);
	glColor3ub(255, 255, 255);
    glVertex2i(550, 510);
    glVertex2i(450, 510);
    glEnd();

    glBegin(GL_LINES);
	glColor3ub(255, 255, 255);
    glVertex2i(550, 495);
    glVertex2i(450, 495);
    glEnd();

    glBegin(GL_LINES);
	glColor3ub(255, 255, 255);
    glVertex2i(550, 480);
    glVertex2i(450, 480);
    glEnd();

    glBegin(GL_LINES);
	glColor3ub(255, 255, 255);
    glVertex2i(550, 465);
    glVertex2i(450, 465);
    glEnd();

    glBegin(GL_LINES);
	glColor3ub(255, 255, 255);
    glVertex2i(550, 450);
    glVertex2i(450, 450);
    glEnd();

    glBegin(GL_LINES);
	glColor3ub(255, 255, 255);
    glVertex2i(550, 435);
    glVertex2i(450, 435);
    glEnd();

    glBegin(GL_LINES);
	glColor3ub(255, 255, 255);
    glVertex2i(550, 420);
    glVertex2i(450, 420);
    glEnd();

    glBegin(GL_LINES);
	glColor3ub(255, 255, 255);
    glVertex2i(510, 590);
    glVertex2i(510, 390);
    glEnd();

    glBegin(GL_LINES);
	glColor3ub(255, 255, 255);
    glVertex2i(550, 405);
    glVertex2i(450, 405);
    glEnd();
    //column 9 end

	//column 11 start
	glBegin(GL_QUADS);
	glColor3ub(192, 192, 192);
	glVertex2i(610,590);
	glVertex2i(610,390);
	glVertex2i(710,390);
	glVertex2i(710,590);
	glEnd();

    glBegin(GL_LINES);
	glColor3ub(255, 255, 255);
    glVertex2i(610, 570);
    glVertex2i(710, 570);
    glEnd();

    glBegin(GL_LINES);
	glColor3ub(255, 255, 255);
    glVertex2i(610, 555);
    glVertex2i(710, 555);
    glEnd();

    glBegin(GL_LINES);
	glColor3ub(255, 255, 255);
    glVertex2i(610, 540);
    glVertex2i(710, 540);
    glEnd();

    glBegin(GL_LINES);
	glColor3ub(255, 255, 255);
    glVertex2i(610, 525);
    glVertex2i(710, 525);
    glEnd();

    glBegin(GL_LINES);
	glColor3ub(255, 255, 255);
    glVertex2i(610, 510);
    glVertex2i(710, 510);
    glEnd();

    glBegin(GL_LINES);
	glColor3ub(255, 255, 255);
    glVertex2i(610, 495);
    glVertex2i(710, 495);
    glEnd();

    glBegin(GL_LINES);
	glColor3ub(255, 255, 255);
    glVertex2i(610, 480);
    glVertex2i(710, 480);
    glEnd();

    glBegin(GL_LINES);
	glColor3ub(255, 255, 255);
    glVertex2i(610, 465);
    glVertex2i(710, 465);
    glEnd();

    glBegin(GL_LINES);
	glColor3ub(255, 255, 255);
    glVertex2i(610, 450);
    glVertex2i(710, 450);
    glEnd();

    glBegin(GL_LINES);
	glColor3ub(255, 255, 255);
    glVertex2i(610, 435);
    glVertex2i(710, 435);
    glEnd();

    glBegin(GL_LINES);
	glColor3ub(255, 255, 255);
    glVertex2i(610, 420);
    glVertex2i(710, 420);
    glEnd();

    glBegin(GL_LINES);
	glColor3ub(255, 255, 255);
    glVertex2i(610, 405);
    glVertex2i(710, 405);
    glEnd();

    glBegin(GL_LINES);
	glColor3ub(255, 255, 255);
    glVertex2i(650, 590);
    glVertex2i(650, 390);
    glEnd();
    //column 11 end

    //column 10 start
    glBegin(GL_QUADS);
	glColor3ub(192, 192, 192);
	glVertex2i(610,570);
	glVertex2i(610,390);
	glVertex2i(550,390);
	glVertex2i(550,570);
	glEnd();

    glBegin(GL_LINES);
	glColor3ub(255, 255, 255);
    glVertex2i(550, 570);
    glVertex2i(610, 570);
    glEnd();

    glBegin(GL_LINES);
	glColor3ub(255, 255, 255);
    glVertex2i(550, 555);
    glVertex2i(610, 555);
    glEnd();

    glBegin(GL_LINES);
	glColor3ub(255, 255, 255);
    glVertex2i(550, 540);
    glVertex2i(610, 540);
    glEnd();

    glBegin(GL_LINES);
	glColor3ub(255, 255, 255);
    glVertex2i(550, 525);
    glVertex2i(610, 525);
    glEnd();

    glBegin(GL_LINES);
	glColor3ub(255, 255, 255);
    glVertex2i(550, 510);
    glVertex2i(610, 510);
    glEnd();

    glBegin(GL_LINES);
	glColor3ub(255, 255, 255);
    glVertex2i(550, 495);
    glVertex2i(610, 495);
    glEnd();

    glBegin(GL_LINES);
	glColor3ub(255, 255, 255);
    glVertex2i(550, 480);
    glVertex2i(610, 480);
    glEnd();

    glBegin(GL_LINES);
	glColor3ub(255, 255, 255);
    glVertex2i(550, 465);
    glVertex2i(610, 465);
    glEnd();

    glBegin(GL_LINES);
	glColor3ub(255, 255, 255);
    glVertex2i(550, 450);
    glVertex2i(610, 450);
    glEnd();

    glBegin(GL_LINES);
	glColor3ub(255, 255, 255);
    glVertex2i(550, 435);
    glVertex2i(610, 435);
    glEnd();

    glBegin(GL_LINES);
	glColor3ub(255, 255, 255);
    glVertex2i(550, 420);
    glVertex2i(610, 420);
    glEnd();

    glBegin(GL_LINES);
	glColor3ub(255, 255, 255);
    glVertex2i(550, 405);
    glVertex2i(610, 405);
    glEnd();

    glBegin(GL_QUADS);
	glColor3ub(160, 160, 160);
	glVertex2i(550,570);
	glVertex2i(555,570);
	glVertex2i(555,390);
	glVertex2i(550,390);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(160, 160, 160);
	glVertex2i(605,570);
	glVertex2i(610,570);
	glVertex2i(610,390);
	glVertex2i(605,390);
	glEnd();
    //column 10 end

	//column 13 start
	glBegin(GL_QUADS);
	glColor3ub(192, 192, 192);
	glVertex2i(710,560);
	glVertex2i(790,570);
	glVertex2i(790,390);
	glVertex2i(710,390);
	glEnd();

    glBegin(GL_LINES);
	glColor3ub(255, 255, 255);
    glVertex2i(790, 565);
    glVertex2i(710, 555);
    glEnd();

    glBegin(GL_LINES);
	glColor3ub(255, 255, 255);
    glVertex2i(790, 550);
    glVertex2i(710, 540);
    glEnd();

    glBegin(GL_LINES);
	glColor3ub(255, 255, 255);
    glVertex2i(790, 535);
    glVertex2i(710, 525);
    glEnd();

    glBegin(GL_LINES);
	glColor3ub(255, 255, 255);
    glVertex2i(790, 520);
    glVertex2i(710, 510);
    glEnd();

    glBegin(GL_LINES);
	glColor3ub(255, 255, 255);
    glVertex2i(790, 505);
    glVertex2i(710, 495);
    glEnd();

    glBegin(GL_LINES);
	glColor3ub(255, 255, 255);
    glVertex2i(790, 490);
    glVertex2i(710, 480);
    glEnd();

    glBegin(GL_LINES);
	glColor3ub(255, 255, 255);
    glVertex2i(790, 475);
    glVertex2i(710, 465);
    glEnd();

    glBegin(GL_LINES);
	glColor3ub(255, 255, 255);
    glVertex2i(790, 460);
    glVertex2i(710, 450);
    glEnd();

    glBegin(GL_LINES);
	glColor3ub(255, 255, 255);
    glVertex2i(790, 445);
    glVertex2i(710, 435);
    glEnd();

    glBegin(GL_LINES);
	glColor3ub(255, 255, 255);
    glVertex2i(790, 430);
    glVertex2i(710, 420);
    glEnd();

    glBegin(GL_LINES);
	glColor3ub(255, 255, 255);
    glVertex2i(790, 415);
    glVertex2i(710, 405);
    glEnd();

    //circle right start
    int i9;
    GLint x9= 750;
    GLint y9= 470;
    GLfloat radius9 =30;
    int triangleAmount9 = 30;

    GLfloat twicePi9 = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(128, 128, 128);
    glVertex2f(x9, y9);
    for(i9 = 0; i9 <= triangleAmount9; i9++)
    {
        glVertex2f(
            x9 + (radius9 * cos(i9 *  twicePi9 / triangleAmount9)),
            y9 + (radius9 * sin(i9 * twicePi9 / triangleAmount9))
        );
    }
    glEnd();
    //circle right end
    //column 13 end

    //column 12 start
    glBegin(GL_QUADS);
	glColor3ub(160, 160, 160);
	glVertex2i(710,560);
	glVertex2i(715,560);
	glVertex2i(715,390);
	glVertex2i(710,390);
	glEnd();
    //column 12 end

	//column 15 start
	glBegin(GL_QUADS);
	glColor3ub(192, 192, 192);
	glVertex2i(790,570);
	glVertex2i(870,560);
	glVertex2i(870,390);
	glVertex2i(790,390);
	glEnd();

    glBegin(GL_LINES);
	glColor3ub(255, 255, 255);
    glVertex2i(790, 565);
    glVertex2i(870, 555);
    glEnd();

    glBegin(GL_LINES);
	glColor3ub(255, 255, 255);
    glVertex2i(790, 550);
    glVertex2i(870, 540);
    glEnd();

    glBegin(GL_LINES);
	glColor3ub(255, 255, 255);
    glVertex2i(790, 535);
    glVertex2i(870, 525);
    glEnd();

    glBegin(GL_LINES);
	glColor3ub(255, 255, 255);
    glVertex2i(790, 520);
    glVertex2i(870, 510);
    glEnd();

    glBegin(GL_LINES);
	glColor3ub(255, 255, 255);
    glVertex2i(790, 505);
    glVertex2i(870, 495);
    glEnd();

    glBegin(GL_LINES);
	glColor3ub(255, 255, 255);
    glVertex2i(790, 490);
    glVertex2i(870, 480);
    glEnd();

    glBegin(GL_LINES);
	glColor3ub(255, 255, 255);
    glVertex2i(790, 475);
    glVertex2i(870, 465);
    glEnd();

    glBegin(GL_LINES);
	glColor3ub(255, 255, 255);
    glVertex2i(790, 460);
    glVertex2i(870, 450);
    glEnd();

    glBegin(GL_LINES);
	glColor3ub(255, 255, 255);
    glVertex2i(790, 445);
    glVertex2i(870, 435);
    glEnd();

    glBegin(GL_LINES);
	glColor3ub(255, 255, 255);
    glVertex2i(790, 430);
    glVertex2i(870, 420);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(128, 128, 128);
    glVertex2i(800, 440);
    glVertex2i(825, 550);
    glVertex2i(850, 440);
    glEnd();

    glBegin(GL_QUADS);
	glColor3ub(128, 128, 128);
	glVertex2i(800,420);
	glVertex2i(850,420);
	glVertex2i(850,390);
	glVertex2i(800,390);
	glEnd();
	//column 15 end

    //column 14 start
    glBegin(GL_QUADS);
	glColor3ub(160, 160, 160);
	glVertex2i(790,570);
	glVertex2i(795,570);
	glVertex2i(795,390);
	glVertex2i(790,390);
	glEnd();
	//column 14 end

    //column 16 start
    glBegin(GL_QUADS);
	glColor3ub(160, 160, 160);
	glVertex2i(870,560);
	glVertex2i(880,560);
	glVertex2i(880,390);
	glVertex2i(870,390);
	glEnd();
	//column 16 end

	//column 17 start
	glBegin(GL_QUADS);
	glColor3ub(192, 192, 192);
	glVertex2i(880,560);
	glVertex2i(960,550);
	glVertex2i(960,390);
	glVertex2i(880,390);
	glEnd();

    glBegin(GL_LINES);
	glColor3ub(255, 255, 255);
    glVertex2i(960, 545);
    glVertex2i(880, 555);
    glEnd();

    glBegin(GL_LINES);
	glColor3ub(255, 255, 255);
    glVertex2i(960, 530);
    glVertex2i(880, 540);
    glEnd();

    glBegin(GL_LINES);
	glColor3ub(255, 255, 255);
    glVertex2i(960, 515);
    glVertex2i(880, 525);
    glEnd();

    glBegin(GL_LINES);
	glColor3ub(255, 255, 255);
    glVertex2i(960, 500);
    glVertex2i(880, 510);
    glEnd();

    glBegin(GL_LINES);
	glColor3ub(255, 255, 255);
    glVertex2i(960, 485);
    glVertex2i(880, 495);
    glEnd();

    glBegin(GL_LINES);
	glColor3ub(255, 255, 255);
    glVertex2i(960, 470);
    glVertex2i(880, 480);
    glEnd();

    glBegin(GL_LINES);
	glColor3ub(255, 255, 255);
    glVertex2i(960, 455);
    glVertex2i(880, 465);
    glEnd();

    glBegin(GL_LINES);
	glColor3ub(255, 255, 255);
    glVertex2i(960, 440);
    glVertex2i(880, 450);
    glEnd();

    glBegin(GL_LINES);
	glColor3ub(255, 255, 255);
    glVertex2i(960, 425);
    glVertex2i(880, 435);
    glEnd();

    glBegin(GL_LINES);
	glColor3ub(255, 255, 255);
    glVertex2i(960, 410);
    glVertex2i(880, 420);
    glEnd();

	glBegin(GL_TRIANGLES);
    glColor3ub(128, 128, 128);
    glVertex2i(890, 440);
    glVertex2i(915, 550);
    glVertex2i(940, 440);
    glEnd();

    glBegin(GL_QUADS);
	glColor3ub(128, 128, 128);
	glVertex2i(890,420);
	glVertex2i(940,420);
	glVertex2i(940,390);
	glVertex2i(890,390);
	glEnd();
    //column 17 end

	//column 18 start
	glBegin(GL_QUADS);
	glColor3ub(160, 160, 160);
	glVertex2i(960,540);
	glVertex2i(970,540);
	glVertex2i(970,390);
	glVertex2i(960,390);
	glEnd();
	//column 18 end

	//column 19 start
	glBegin(GL_QUADS);
	glColor3ub(192, 192, 192);
	glVertex2i(970,540);
	glVertex2i(1050,540);
	glVertex2i(1050,390);
	glVertex2i(970,390);
	glEnd();

    glBegin(GL_LINES);
	glColor3ub(255, 255, 255);
    glVertex2i(970, 530);
    glVertex2i(1050, 530);
    glEnd();

    glBegin(GL_LINES);
	glColor3ub(255, 255, 255);
    glVertex2i(970, 515);
    glVertex2i(1050, 515);
    glEnd();

    glBegin(GL_LINES);
	glColor3ub(255, 255, 255);
    glVertex2i(970, 500);
    glVertex2i(1050, 500);
    glEnd();

    glBegin(GL_LINES);
	glColor3ub(255, 255, 255);
    glVertex2i(970, 485);
    glVertex2i(1050, 485);
    glEnd();

    glBegin(GL_LINES);
	glColor3ub(255, 255, 255);
    glVertex2i(970, 470);
    glVertex2i(1050, 470);
    glEnd();

    glBegin(GL_LINES);
	glColor3ub(255, 255, 255);
    glVertex2i(970, 455);
    glVertex2i(1050, 455);
    glEnd();

    glBegin(GL_LINES);
	glColor3ub(255, 255, 255);
    glVertex2i(970, 440);
    glVertex2i(1050, 440);
    glEnd();

    glBegin(GL_LINES);
	glColor3ub(255, 255, 255);
    glVertex2i(970, 425);
    glVertex2i(1050, 425);
    glEnd();

    glBegin(GL_LINES);
	glColor3ub(255, 255, 255);
    glVertex2i(970, 410);
    glVertex2i(1050, 410);
    glEnd();

    glBegin(GL_LINES);
	glColor3ub(255, 255, 255);
    glVertex2i(1005, 540);
    glVertex2i(1005, 390);
    glEnd();
    //column 19 end

    //column 7 start
	glBegin(GL_QUADS);
	glColor3ub(192, 192, 192);
	glVertex2i(450,560);
	glVertex2i(450,390);
	glVertex2i(370,390);
	glVertex2i(370,570);
	glEnd();

    glBegin(GL_LINES);
	glColor3ub(255, 255, 255);
    glVertex2i(370, 565);
    glVertex2i(445, 555);
    glEnd();

    glBegin(GL_LINES);
	glColor3ub(255, 255, 255);
    glVertex2i(370, 550);
    glVertex2i(445, 540);
    glEnd();

    glBegin(GL_LINES);
	glColor3ub(255, 255, 255);
    glVertex2i(370, 535);
    glVertex2i(445, 525);
    glEnd();

    glBegin(GL_LINES);
	glColor3ub(255, 255, 255);
    glVertex2i(370, 520);
    glVertex2i(445, 510);
    glEnd();

    glBegin(GL_LINES);
	glColor3ub(255, 255, 255);
    glVertex2i(370, 505);
    glVertex2i(445, 495);
    glEnd();

    glBegin(GL_LINES);
	glColor3ub(255, 255, 255);
    glVertex2i(370, 490);
    glVertex2i(445, 480);
    glEnd();

    glBegin(GL_LINES);
	glColor3ub(255, 255, 255);
    glVertex2i(370, 475);
    glVertex2i(445, 465);
    glEnd();

    glBegin(GL_LINES);
	glColor3ub(255, 255, 255);
    glVertex2i(370, 460);
    glVertex2i(445, 450);
    glEnd();

    glBegin(GL_LINES);
	glColor3ub(255, 255, 255);
    glVertex2i(370, 445);
    glVertex2i(445, 435);
    glEnd();

    glBegin(GL_LINES);
	glColor3ub(255, 255, 255);
    glVertex2i(370, 430);
    glVertex2i(445, 420);
    glEnd();

    glBegin(GL_LINES);
	glColor3ub(255, 255, 255);
    glVertex2i(370, 415);
    glVertex2i(445, 405);
    glEnd();

    //circle left start
    int i10;
    GLint x10= 410;
    GLint y10= 470;
    GLfloat radius10 =30;
    int triangleAmount10 = 30;

    GLfloat twicePi10 = 3.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(128, 128, 128);
    glVertex2f(x10, y10);
    for(i10 = 0; i10 <= triangleAmount10; i10++)
    {
        glVertex2f(
            x10 + (radius10 * cos(i10 *  twicePi10 / triangleAmount10)),
            y10 + (radius10 * sin(i10 * twicePi10 / triangleAmount10))
        );
    }
    glEnd();
    //circle left end
    //column 7 end

    //column 8 start
    glBegin(GL_QUADS);
	glColor3ub(160, 160, 160);
	glVertex2i(450,560);
	glVertex2i(445,560);
	glVertex2i(445,390);
	glVertex2i(450,390);
	glEnd();
	//column 8 end


    //column 5 start
	glBegin(GL_QUADS);
	glColor3ub(192, 192, 192);
	glVertex2i(370,570);
	glVertex2i(370,390);
	glVertex2i(290,390);
	glVertex2i(290,560);
	glEnd();

    glBegin(GL_LINES);
	glColor3ub(255, 255, 255);
    glVertex2i(365, 565);
    glVertex2i(290, 555);
    glEnd();

    glBegin(GL_LINES);
	glColor3ub(255, 255, 255);
    glVertex2i(365, 550);
    glVertex2i(290, 540);
    glEnd();

    glBegin(GL_LINES);
	glColor3ub(255, 255, 255);
    glVertex2i(365, 535);
    glVertex2i(290, 525);
    glEnd();

    glBegin(GL_LINES);
	glColor3ub(255, 255, 255);
    glVertex2i(365, 520);
    glVertex2i(290, 510);
    glEnd();

    glBegin(GL_LINES);
	glColor3ub(255, 255, 255);
    glVertex2i(365, 505);
    glVertex2i(290, 495);
    glEnd();

    glBegin(GL_LINES);
	glColor3ub(255, 255, 255);
    glVertex2i(365, 490);
    glVertex2i(290, 480);
    glEnd();

    glBegin(GL_LINES);
	glColor3ub(255, 255, 255);
    glVertex2i(365, 475);
    glVertex2i(290, 465);
    glEnd();

    glBegin(GL_LINES);
	glColor3ub(255, 255, 255);
    glVertex2i(365, 460);
    glVertex2i(290, 450);
    glEnd();

    glBegin(GL_LINES);
	glColor3ub(255, 255, 255);
    glVertex2i(365, 445);
    glVertex2i(290, 435);
    glEnd();

    glBegin(GL_LINES);
	glColor3ub(255, 255, 255);
    glVertex2i(365, 430);
    glVertex2i(290, 420);
    glEnd();

	glBegin(GL_TRIANGLES);
    glColor3ub(128, 128, 128);
    glVertex2i(305, 440);
    glVertex2i(330, 550);
    glVertex2i(355, 440);
    glEnd();

    glBegin(GL_QUADS);
	glColor3ub(128, 128, 128);
	glVertex2i(305,420);
	glVertex2i(355,420);
	glVertex2i(355,390);
	glVertex2i(305,390);
	glEnd();
	//column 5 end


    //column 6 start
    glBegin(GL_QUADS);
	glColor3ub(160, 160, 160);
	glVertex2i(370,570);
	glVertex2i(365,570);
	glVertex2i(365,390);
	glVertex2i(370,390);
	glEnd();
	//column 6 end


    //column 4 start
    glBegin(GL_QUADS);
	glColor3ub(160, 160, 160);
	glVertex2i(280,560);
	glVertex2i(290,560);
	glVertex2i(290,390);
	glVertex2i(280,390);
	glEnd();
    //column 4 end

    //column 3 start
	glBegin(GL_QUADS);
	glColor3ub(192, 192, 192);
	glVertex2i(280,560);
	glVertex2i(280,390);
	glVertex2i(200,390);
	glVertex2i(200,550);
	glEnd();

    glBegin(GL_LINES);
	glColor3ub(255, 255, 255);
    glVertex2i(200, 545);
    glVertex2i(280, 555);
    glEnd();

    glBegin(GL_LINES);
	glColor3ub(255, 255, 255);
    glVertex2i(200, 530);
    glVertex2i(280, 540);
    glEnd();

    glBegin(GL_LINES);
	glColor3ub(255, 255, 255);
    glVertex2i(200, 515);
    glVertex2i(280, 525);
    glEnd();

    glBegin(GL_LINES);
	glColor3ub(255, 255, 255);
    glVertex2i(200, 500);
    glVertex2i(280, 510);
    glEnd();

    glBegin(GL_LINES);
	glColor3ub(255, 255, 255);
    glVertex2i(200, 485);
    glVertex2i(280, 495);
    glEnd();

    glBegin(GL_LINES);
	glColor3ub(255, 255, 255);
    glVertex2i(200, 470);
    glVertex2i(280, 480);
    glEnd();

    glBegin(GL_LINES);
	glColor3ub(255, 255, 255);
    glVertex2i(200, 455);
    glVertex2i(280, 465);
    glEnd();

    glBegin(GL_LINES);
	glColor3ub(255, 255, 255);
    glVertex2i(200, 440);
    glVertex2i(280, 450);
    glEnd();

    glBegin(GL_LINES);
	glColor3ub(255, 255, 255);
    glVertex2i(200, 425);
    glVertex2i(280, 435);
    glEnd();

    glBegin(GL_LINES);
	glColor3ub(255, 255, 255);
    glVertex2i(200, 410);
    glVertex2i(280, 420);
    glEnd();

	glBegin(GL_TRIANGLES);
    glColor3ub(128, 128, 128);
    glVertex2i(210, 440);
    glVertex2i(235, 550);
    glVertex2i(260, 440);
    glEnd();

    glBegin(GL_QUADS);
	glColor3ub(128, 128, 128);
	glVertex2i(210,420);
	glVertex2i(260,420);
	glVertex2i(260,390);
	glVertex2i(210,390);
	glEnd();
	//column 3 end

    //column 2 start
    glBegin(GL_QUADS);
	glColor3ub(160, 160, 160);
	glVertex2i(190,540);
	glVertex2i(200,540);
	glVertex2i(200,390);
	glVertex2i(190,390);
	glEnd();
	//column 2 end

    //column 1 start
	glBegin(GL_QUADS);
	glColor3ub(192, 192, 192);
	glVertex2i(190,540);
	glVertex2i(190,390);
	glVertex2i(110,390);
	glVertex2i(110,540);
	glEnd();

    glBegin(GL_LINES);
	glColor3ub(255, 255, 255);
    glVertex2i(110, 530);
    glVertex2i(190, 530);
    glEnd();

    glBegin(GL_LINES);
	glColor3ub(255, 255, 255);
    glVertex2i(110, 515);
    glVertex2i(190, 515);
    glEnd();

    glBegin(GL_LINES);
	glColor3ub(255, 255, 255);
    glVertex2i(110, 500);
    glVertex2i(190, 500);
    glEnd();

    glBegin(GL_LINES);
	glColor3ub(255, 255, 255);
    glVertex2i(110, 485);
    glVertex2i(190, 485);
    glEnd();

    glBegin(GL_LINES);
	glColor3ub(255, 255, 255);
    glVertex2i(110, 470);
    glVertex2i(190, 470);
    glEnd();

    glBegin(GL_LINES);
	glColor3ub(255, 255, 255);
    glVertex2i(110, 455);
    glVertex2i(190, 455);
    glEnd();

    glBegin(GL_LINES);
	glColor3ub(255, 255, 255);
    glVertex2i(110, 440);
    glVertex2i(190, 440);
    glEnd();

    glBegin(GL_LINES);
	glColor3ub(255, 255, 255);
    glVertex2i(110, 425);
    glVertex2i(190, 425);
    glEnd();

    glBegin(GL_LINES);
	glColor3ub(255, 255, 255);
    glVertex2i(110, 410);
    glVertex2i(190, 410);
    glEnd();

    glBegin(GL_LINES);
	glColor3ub(255, 255, 255);
    glVertex2i(155, 540);
    glVertex2i(155, 390);
    glEnd();
    //column 1 end


    //left stair start
    glBegin(GL_QUADS);
	glColor3ub(165,42,42);
	glVertex2i(360,380);
	glVertex2i(110,380);
	glVertex2i(110,390);
	glVertex2i(360,390);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(165,42,42);
	glVertex2i(340,370);
	glVertex2i(100,370);
	glVertex2i(100,380);
	glVertex2i(340,380);
	glEnd();

    glBegin(GL_QUADS);
	glColor3ub(165,42,42);
	glVertex2i(320,360);
	glVertex2i(90,360);
	glVertex2i(90,370);
	glVertex2i(320,370);
	glEnd();

    glBegin(GL_QUADS);
	glColor3ub(165,42,42);
	glVertex2i(300,350);
	glVertex2i(80,350);
	glVertex2i(80,360);
	glVertex2i(300,360);
	glEnd();

    glBegin(GL_QUADS);
	glColor3ub(165,42,42);
	glVertex2i(280,340);
	glVertex2i(70,340);
	glVertex2i(70,350);
	glVertex2i(280,350);
	glEnd();

    glBegin(GL_QUADS);
	glColor3ub(165,42,42);
	glVertex2i(260,330);
	glVertex2i(60,330);
	glVertex2i(60,340);
	glVertex2i(260,340);
	glEnd();

    glBegin(GL_QUADS);
	glColor3ub(165,42,42);
	glVertex2i(240,320);
	glVertex2i(50,320);
	glVertex2i(50,330);
	glVertex2i(240,330);
	glEnd();

    glBegin(GL_QUADS);
	glColor3ub(163,42,42);
	glVertex2i(220,310);
	glVertex2i(30,310);
	glVertex2i(30,320);
	glVertex2i(220,320);
	glEnd();

	glBegin(GL_LINES);
	glColor3ub(32, 32, 32);
    glVertex2i(110, 390);
    glVertex2i(360, 390);
    glEnd();

	glBegin(GL_LINES);
	glColor3ub(32, 32, 32);
    glVertex2i(100, 380);
    glVertex2i(340, 380);
    glEnd();

	glBegin(GL_LINES);
	glColor3ub(32, 32, 32);
    glVertex2i(90, 370);
    glVertex2i(320, 370);
    glEnd();

	glBegin(GL_LINES);
	glColor3ub(32, 32, 32);
    glVertex2i(80, 360);
    glVertex2i(300, 360);
    glEnd();

	glBegin(GL_LINES);
	glColor3ub(32, 32, 32);
    glVertex2i(70, 350);
    glVertex2i(280, 350);
    glEnd();

	glBegin(GL_LINES);
	glColor3ub(32, 32, 32);
    glVertex2i(60, 340);
    glVertex2i(260, 340);
    glEnd();

	glBegin(GL_LINES);
	glColor3ub(32, 32, 32);
    glVertex2i(50, 330);
    glVertex2i(240, 330);
    glEnd();

	glBegin(GL_LINES);
	glColor3ub(32, 32, 32);
    glVertex2i(30, 320);
    glVertex2i(220, 320);
    glEnd();
    //Left stair end

    //middle stair start
    glBegin(GL_QUADS);
	glColor3ub(165,42,42);
	glVertex2i(370,380);
	glVertex2i(790,380);
	glVertex2i(790,390);
	glVertex2i(370,390);
	glEnd();

    glBegin(GL_QUADS);
	glColor3ub(165,42,42);
	glVertex2i(350,370);
	glVertex2i(810,370);
	glVertex2i(810,380);
	glVertex2i(350,380);
	glEnd();

    glBegin(GL_QUADS);
	glColor3ub(165,42,42);
	glVertex2i(330,360);
	glVertex2i(830,360);
	glVertex2i(830,370);
	glVertex2i(330,370);
	glEnd();

    glBegin(GL_QUADS);
	glColor3ub(165,42,42);
	glVertex2i(310,350);
	glVertex2i(850,350);
	glVertex2i(850,360);
	glVertex2i(310,360);
	glEnd();

    glBegin(GL_QUADS);
	glColor3ub(165,42,42);
	glVertex2i(290,340);
	glVertex2i(870,340);
	glVertex2i(870,350);
	glVertex2i(290,350);
	glEnd();

    glBegin(GL_QUADS);
	glColor3ub(165,42,42);
	glVertex2i(270,330);
	glVertex2i(890,330);
	glVertex2i(890,340);
	glVertex2i(270,340);
	glEnd();

    glBegin(GL_QUADS);
	glColor3ub(165,42,42);
	glVertex2i(250,320);
	glVertex2i(910,320);
	glVertex2i(910,330);
	glVertex2i(250,330);
	glEnd();

    glBegin(GL_QUADS);
	glColor3ub(165,42,42);
	glVertex2i(230,310);
	glVertex2i(930,310);
	glVertex2i(930,320);
	glVertex2i(230,320);
	glEnd();

	glBegin(GL_LINES);
	glColor3ub(32, 32, 32);
    glVertex2i(370, 390);
    glVertex2i(790, 390);
    glEnd();

	glBegin(GL_LINES);
	glColor3ub(32, 32, 32);
    glVertex2i(350, 380);
    glVertex2i(810, 380);
    glEnd();

	glBegin(GL_LINES);
	glColor3ub(32, 32, 32);
    glVertex2i(330, 370);
    glVertex2i(830, 370);
    glEnd();

	glBegin(GL_LINES);
	glColor3ub(32, 32, 32);
    glVertex2i(310, 360);
    glVertex2i(850, 360);
    glEnd();

	glBegin(GL_LINES);
	glColor3ub(32, 32, 32);
    glVertex2i(290, 350);
    glVertex2i(870, 350);
    glEnd();

	glBegin(GL_LINES);
	glColor3ub(32, 32, 32);
    glVertex2i(270, 340);
    glVertex2i(890, 340);
    glEnd();

	glBegin(GL_LINES);
	glColor3ub(32, 32, 32);
    glVertex2i(250, 330);
    glVertex2i(910, 330);
    glEnd();

	glBegin(GL_LINES);
	glColor3ub(32, 32, 32);
    glVertex2i(230, 320);
    glVertex2i(930, 320);
    glEnd();
    //middle stair end

    //right stair start
    glBegin(GL_QUADS);
	glColor3ub(165,42,42);
	glVertex2i(800,380);
	glVertex2i(1050,380);
	glVertex2i(1050,390);
	glVertex2i(800,390);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(165,42,42);
	glVertex2i(820,370);
	glVertex2i(1060,370);
	glVertex2i(1060,380);
	glVertex2i(820,380);
	glEnd();

    glBegin(GL_QUADS);
	glColor3ub(165,42,42);
	glVertex2i(840,360);
	glVertex2i(1070,360);
	glVertex2i(1070,370);
	glVertex2i(840,370);
	glEnd();

    glBegin(GL_QUADS);
	glColor3ub(165,42,42);
	glVertex2i(860,350);
	glVertex2i(1080,350);
	glVertex2i(1080,360);
	glVertex2i(860,360);
	glEnd();

    glBegin(GL_QUADS);
	glColor3ub(165,42,42);
	glVertex2i(880,340);
	glVertex2i(1090,340);
	glVertex2i(1090,350);
	glVertex2i(880,350);
	glEnd();

    glBegin(GL_QUADS);
	glColor3ub(165,42,42);
	glVertex2i(900,330);
	glVertex2i(1100,330);
	glVertex2i(1100,340);
	glVertex2i(900,340);
	glEnd();

    glBegin(GL_QUADS);
	glColor3ub(165,42,42);
	glVertex2i(920,320);
	glVertex2i(1110,320);
	glVertex2i(1110,330);
	glVertex2i(920,330);
	glEnd();

    glBegin(GL_QUADS);
	glColor3ub(163,42,42);
	glVertex2i(940,310);
	glVertex2i(1120,310);
	glVertex2i(1120,320);
	glVertex2i(940,320);
	glEnd();

	glBegin(GL_LINES);
	glColor3ub(32, 32, 32);
    glVertex2i(800, 390);
    glVertex2i(1050, 390);
    glEnd();

	glBegin(GL_LINES);
	glColor3ub(32, 32, 32);
    glVertex2i(1060, 380);
    glVertex2i(820, 380);
    glEnd();

	glBegin(GL_LINES);
	glColor3ub(32, 32, 32);
    glVertex2i(840, 370);
    glVertex2i(1070, 370);
    glEnd();

	glBegin(GL_LINES);
	glColor3ub(32, 32, 32);
    glVertex2i(860, 360);
    glVertex2i(1080, 360);
    glEnd();

	glBegin(GL_LINES);
	glColor3ub(32, 32, 32);
    glVertex2i(1090, 350);
    glVertex2i(880, 350);
    glEnd();

	glBegin(GL_LINES);
	glColor3ub(32, 32, 32);
    glVertex2i(900, 340);
    glVertex2i(1100, 340);
    glEnd();

	glBegin(GL_LINES);
	glColor3ub(32, 32, 32);
    glVertex2i(920, 330);
    glVertex2i(1110, 330);
    glEnd();

	glBegin(GL_LINES);
	glColor3ub(32, 32, 32);
    glVertex2i(940, 320);
    glVertex2i(1120, 320);
    glEnd();
    //right stair end

	//flag square start
	glBegin(GL_QUADS);
	glColor3ub(32, 32, 32);
	glVertex2i(565,400);
	glVertex2i(595,400);
	glVertex2i(595,390);
	glVertex2i(565,390);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(204, 255, 204);
	glVertex2i(578,400);
	glVertex2i(578,510);
	glVertex2i(583,510);
	glVertex2i(583,400);
	glEnd();

	glBegin(GL_QUADS);
	glColor3ub(0, 255, 0);
	glVertex2i(583,510);
	glVertex2i(630,510);
	glVertex2i(630,470);
	glVertex2i(583,470);
	glEnd();
	//flag square end

	//Flag circle start
	int i2;
    GLint x2= 604;
    GLint y2= 490;
    GLfloat radius2 =10;
    int triangleAmount2 = 30;

    GLfloat twicePi2 = 2.0f * PI;

    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(255, 0, 0);
    glVertex2f(x2, y2);
    for(i2 = 0; i2 <= triangleAmount2; i2++)
    {
        glVertex2f(
            x2 + (radius2 * cos(i2 *  twicePi2 / triangleAmount2)),
            y2 + (radius2 * sin(i2 * twicePi2 / triangleAmount2))
        );
    }
    glEnd();
    //Flag circle end

    //Small tree start
    //tree
    glBegin(GL_TRIANGLES);
    glColor3ub(0, 153, 0);
    glVertex2i(50, 350);
    glVertex2i(70, 380);
    glVertex2i(90, 350);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(0, 153, 0);
    glVertex2i(50, 340);
    glVertex2i(70, 370);
    glVertex2i(90, 340);
    glEnd();

    glBegin(GL_QUADS);
	glColor3ub(224, 224, 224);
	glVertex2i(65,340);
	glVertex2i(75,340);
	glVertex2i(75,310);
	glVertex2i(65,310);
	glEnd();

	//tree2
    glBegin(GL_TRIANGLES);
    glColor3ub(0, 153, 0);
    glVertex2i(250, 350);
    glVertex2i(270, 380);
    glVertex2i(290, 350);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(0, 153, 0);
    glVertex2i(250, 340);
    glVertex2i(270, 370);
    glVertex2i(290, 340);
    glEnd();

    glBegin(GL_QUADS);
	glColor3ub(224, 224, 224);
	glVertex2i(265,340);
	glVertex2i(275,340);
	glVertex2i(275,310);
	glVertex2i(265,310);
	glEnd();

	//tree3
    glBegin(GL_TRIANGLES);
    glColor3ub(0, 153, 0);
    glVertex2i(450, 350);
    glVertex2i(470, 380);
    glVertex2i(490, 350);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(0, 153, 0);
    glVertex2i(450, 340);
    glVertex2i(470, 370);
    glVertex2i(490, 340);
    glEnd();

    glBegin(GL_QUADS);
	glColor3ub(224, 224, 224);
	glVertex2i(465,340);
	glVertex2i(475,340);
	glVertex2i(475,310);
	glVertex2i(465,310);
	glEnd();

	//tree4
    glBegin(GL_TRIANGLES);
    glColor3ub(0, 153, 0);
    glVertex2i(650, 350);
    glVertex2i(670, 380);
    glVertex2i(690, 350);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(0, 153, 0);
    glVertex2i(650, 340);
    glVertex2i(670, 370);
    glVertex2i(690, 340);
    glEnd();

    glBegin(GL_QUADS);
	glColor3ub(224, 224, 224);
	glVertex2i(665,340);
	glVertex2i(675,340);
	glVertex2i(675,310);
	glVertex2i(665,310);
	glEnd();

	//tree5
    glBegin(GL_TRIANGLES);
    glColor3ub(0, 153, 0);
    glVertex2i(850, 350);
    glVertex2i(870, 380);
    glVertex2i(890, 350);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(0, 153, 0);
    glVertex2i(850, 340);
    glVertex2i(870, 370);
    glVertex2i(890, 340);
    glEnd();

    glBegin(GL_QUADS);
	glColor3ub(224, 224, 224);
	glVertex2i(865,340);
	glVertex2i(875,340);
	glVertex2i(875,310);
	glVertex2i(865,310);
	glEnd();

	//tree 6
	glBegin(GL_TRIANGLES);
    glColor3ub(0, 153, 0);
    glVertex2i(1050, 350);
    glVertex2i(1070, 380);
    glVertex2i(1090, 350);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(0, 153, 0);
    glVertex2i(1050, 340);
    glVertex2i(1070, 370);
    glVertex2i(1090, 340);
    glEnd();

    glBegin(GL_QUADS);
	glColor3ub(224, 224, 224);
	glVertex2i(1065,340);
	glVertex2i(1075,340);
	glVertex2i(1075,310);
	glVertex2i(1065,310);
	glEnd();
	//Small tree end

	//lamp start
	//lamp1
	glBegin(GL_QUADS);
	glColor3ub(32, 32, 32);
	glVertex2i(110,360);
	glVertex2i(120,360);
	glVertex2i(120,310);
	glVertex2i(110,310);
	glEnd();

	//lamp2
	glBegin(GL_QUADS);
	glColor3ub(32, 32, 32);
	glVertex2i(310,360);
	glVertex2i(320,360);
	glVertex2i(320,310);
	glVertex2i(310,310);
	glEnd();

	//lamp3
	glBegin(GL_QUADS);
	glColor3ub(34, 34, 34);
	glVertex2i(510,360);
	glVertex2i(520,360);
	glVertex2i(520,310);
	glVertex2i(510,310);
	glEnd();

	//lamp4
	glBegin(GL_QUADS);
	glColor3ub(34, 34, 34);
	glVertex2i(710,360);
	glVertex2i(720,360);
	glVertex2i(720,310);
	glVertex2i(710,310);
	glEnd();

	//lamp5
	glBegin(GL_QUADS);
	glColor3ub(34, 34, 34);
	glVertex2i(910,360);
	glVertex2i(920,360);
	glVertex2i(920,310);
	glVertex2i(910,310);
	glEnd();

	//lamp6
	glBegin(GL_QUADS);
	glColor3ub(34, 34, 34);
	glVertex2i(1110,360);
	glVertex2i(1120,360);
	glVertex2i(1120,310);
	glVertex2i(1110,310);
	glEnd();
	//Lamp end

	//light On start
    int i11;
    GLint x11= 115;
    GLint y11= 370;
    GLfloat radius11 =15;
    int triangleAmount11 = 30;
    GLfloat twicePi11 = 2.0f * PI;
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(173,255,47);
    glVertex2f(x11, y11);
    for(i11 = 0; i11 <= triangleAmount11; i11++)
    {
        glVertex2f(
            x11 + (radius11 * cos(i11 *  twicePi11 / triangleAmount11)),
            y11 + (radius11 * sin(i11 * twicePi11 / triangleAmount11))
        );
    }
    glEnd();

	int i12;
    GLint x12= 315;
    GLint y12= 370;
    GLfloat radius12 =15;
    int triangleAmount12 = 30;
    GLfloat twicePi12 = 2.0f * PI;
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(173,255,47);
    glVertex2f(x12, y12);
    for(i12 = 0; i12 <= triangleAmount12; i12++)
    {
        glVertex2f(
            x12 + (radius12 * cos(i12 *  twicePi12 / triangleAmount12)),
            y12 + (radius12 * sin(i12 * twicePi12 / triangleAmount12))
        );
    }
    glEnd();

	int i13;
    GLint x13= 515;
    GLint y13= 370;
    GLfloat radius13 =15;
    int triangleAmount13 = 30;
    GLfloat twicePi13 = 2.0f * PI;
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(173,255,47);
    glVertex2f(x13, y13);
    for(i13 = 0; i13 <= triangleAmount13; i13++)
    {
        glVertex2f(
            x13 + (radius13 * cos(i13 *  twicePi13 / triangleAmount13)),
            y13 + (radius13 * sin(i13 * twicePi13 / triangleAmount13))
        );
    }
    glEnd();

	int i14;
    GLint x14= 715;
    GLint y14= 370;
    GLfloat radius14 =15;
    int triangleAmount14 = 30;
    GLfloat twicePi14 = 2.0f * PI;
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(173,255,47);
    glVertex2f(x14, y14);
    for(i14 = 0; i14 <= triangleAmount14; i14++)
    {
        glVertex2f(
            x14 + (radius14 * cos(i14 *  twicePi14 / triangleAmount14)),
            y14 + (radius14 * sin(i14 * twicePi14 / triangleAmount14))
        );
    }
    glEnd();

    int i15;
    GLint x15= 915;
    GLint y15= 370;
    GLfloat radius15 =15;
    int triangleAmount15 = 30;
    GLfloat twicePi15 = 2.0f * PI;
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(173,255,47);
    glVertex2f(x15, y15);
    for(i15 = 0; i15 <= triangleAmount15; i15++)
    {
        glVertex2f(
            x15 + (radius15 * cos(i15 *  twicePi15 / triangleAmount15)),
            y15 + (radius15 * sin(i15 * twicePi15 / triangleAmount15))
        );
    }
    glEnd();

    int i16;
    GLint x16= 1115;
    GLint y16= 370;
    GLfloat radius16 =15;
    int triangleAmount16 = 30;
    GLfloat twicePi16 = 2.0f * PI;
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(173,255,47);
    glVertex2f(x16, y16);
    for(i16 = 0; i16 <= triangleAmount16; i16++)
    {
        glVertex2f(
            x16 + (radius16 * cos(i16 *  twicePi16 / triangleAmount16)),
            y16 + (radius16 * sin(i16 * twicePi16 / triangleAmount16))
        );
    }
    glEnd();
    //Light on End

	//road start
    glBegin(GL_QUADS);
	glColor3ub(106, 108, 109);
	glVertex2i(0,310);
	glVertex2i(0,0);
	glVertex2i(1200,0);
	glVertex2i(1200,310);
	glEnd();

    glBegin(GL_QUADS);
	glColor3ub(0, 0, 0);
	glVertex2i(0,300);
	glVertex2i(0,290);
	glVertex2i(1200,290);
	glVertex2i(1200,300);
	glEnd();

    glBegin(GL_QUADS);
	glColor3ub(0, 0, 0);
	glVertex2i(0,45);
	glVertex2i(0,35);
	glVertex2i(1200,35);
	glVertex2i(1200,45);
	glEnd();
    //road end

	//white border start
    glBegin(GL_QUADS);
	glColor3ub(255, 255, 255);
    //low bar white start
    glVertex2i(0,45);
	glVertex2i(0,35);
	glVertex2i(50,35);
	glVertex2i(50,45);

    glVertex2i(100,45);
	glVertex2i(100,35);
	glVertex2i(150,35);
	glVertex2i(150,45);

    glVertex2i(200,45);
	glVertex2i(200,35);
	glVertex2i(250,35);
	glVertex2i(250,45);

    glVertex2i(300,45);
	glVertex2i(300,35);
	glVertex2i(350,35);
	glVertex2i(350,45);

    glVertex2i(400,45);
	glVertex2i(400,35);
	glVertex2i(450,35);
	glVertex2i(450,45);

	glVertex2i(500,45);
	glVertex2i(500,35);
	glVertex2i(550,35);
	glVertex2i(550,45);

	glVertex2i(600,45);
	glVertex2i(600,35);
	glVertex2i(650,35);
	glVertex2i(650,45);

	glVertex2i(700,45);
	glVertex2i(700,35);
	glVertex2i(750,35);
	glVertex2i(750,45);

	glVertex2i(800,45);
	glVertex2i(800,35);
	glVertex2i(850,35);
	glVertex2i(850,45);

	glVertex2i(900,45);
	glVertex2i(900,35);
	glVertex2i(950,35);
	glVertex2i(950,45);

	glVertex2i(1000,45);
	glVertex2i(1000,35);
	glVertex2i(1050,35);
	glVertex2i(1050,45);

	glVertex2i(1100,45);
	glVertex2i(1100,35);
	glVertex2i(1150,35);
	glVertex2i(1150,45);
    //low bar white end

    //upper bar black start
    glVertex2i(0,300);
	glVertex2i(0,290);
	glVertex2i(50,290);
	glVertex2i(50,300);

    glVertex2i(100,300);
	glVertex2i(100,290);
	glVertex2i(150,290);
	glVertex2i(150,300);

    glVertex2i(200,300);
	glVertex2i(200,290);
	glVertex2i(250,290);
	glVertex2i(250,300);

    glVertex2i(300,300);
	glVertex2i(300,290);
	glVertex2i(350,290);
	glVertex2i(350,300);

    glVertex2i(400,300);
	glVertex2i(400,290);
	glVertex2i(450,290);
	glVertex2i(450,300);

	glVertex2i(500,300);
	glVertex2i(500,290);
	glVertex2i(550,290);
	glVertex2i(550,300);

	glVertex2i(600,300);
	glVertex2i(600,290);
	glVertex2i(650,290);
	glVertex2i(650,300);

	glVertex2i(700,300);
	glVertex2i(700,290);
	glVertex2i(750,290);
	glVertex2i(750,300);

	glVertex2i(800,300);
	glVertex2i(800,290);
	glVertex2i(850,290);
	glVertex2i(850,300);

	glVertex2i(900,300);
	glVertex2i(900,290);
	glVertex2i(950,290);
	glVertex2i(950,300);

	glVertex2i(1000,300);
	glVertex2i(1000,290);
	glVertex2i(1050,290);
	glVertex2i(1050,300);

	glVertex2i(1100,300);
	glVertex2i(1100,290);
	glVertex2i(1150,290);
	glVertex2i(1150,300);
	glEnd();
    //uper bar black End
	//white border end

    GLint xx;
        for (xx = 0; xx <= 1200; xx += 50){
            roaddevider(xx,xx,xx+30,xx+30);
        }

    //calling the car & wheel function start
    car1(xn,yq);
    wheel(xn+320,yq+30);
    wheel(xn+400,yq+30);

    car2(xn+400,yq-30);
    wheel(xn+720,yq);
    wheel(xn+800,yq);

    car3(xm+800,yp+90);
    wheel(xm+365,yp+120);
    wheel(xm+445,yp+120);

    car4(xm+450,yp+110);
    wheel(xm+15,yp+140);
    wheel(xm+95,yp+140);

    car5(xn-500,yq-39);
    wheel(xn-100,yq-10);
    wheel(xn-180,yq-10);
    //calling the car & wheel function end

    //Big Tree start
    tree(s-440,t+150);
    tree(s+610,t+150);
    tree(s+670,t+150);
    //Big tree end

    //lamp down start
    //lamp7
	glBegin(GL_QUADS);
	glColor3ub(32, 32, 32);
	glVertex2i(110,60);
	glVertex2i(120,60);
	glVertex2i(120,10);
	glVertex2i(110,10);
	glEnd();

	//lamp8
	glBegin(GL_QUADS);
	glColor3ub(32, 32, 32);
	glVertex2i(310,60);
	glVertex2i(320,60);
	glVertex2i(320,10);
	glVertex2i(310,10);
	glEnd();

	//lamp9
	glBegin(GL_QUADS);
	glColor3ub(34, 34, 34);
	glVertex2i(510,60);
	glVertex2i(520,60);
	glVertex2i(520,10);
	glVertex2i(510,10);
	glEnd();

	//lamp10
	glBegin(GL_QUADS);
	glColor3ub(34, 34, 34);
	glVertex2i(710,60);
	glVertex2i(720,60);
	glVertex2i(720,10);
	glVertex2i(710,10);
	glEnd();

	//lamp11
	glBegin(GL_QUADS);
	glColor3ub(34, 34, 34);
	glVertex2i(910,60);
	glVertex2i(920,60);
	glVertex2i(920,10);
	glVertex2i(910,10);
	glEnd();

	//lamp12
	glBegin(GL_QUADS);
	glColor3ub(34, 34, 34);
	glVertex2i(1110,60);
	glVertex2i(1120,60);
	glVertex2i(1120,10);
	glVertex2i(1110,10);
	glEnd();
	//lamp down end

	//lamp down on start
	int i17;
    GLint x17= 115;
    GLint y17= 70;
    GLfloat radius17 =15;
    int triangleAmount17 = 30;
    GLfloat twicePi17 = 2.0f * PI;
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(173,255,47);
    glVertex2f(x17, y17);
    for(i17 = 0; i17 <= triangleAmount17; i17++)
    {
        glVertex2f(
            x17 + (radius17 * cos(i17 *  twicePi17 / triangleAmount17)),
            y17 + (radius17 * sin(i17 * twicePi17 / triangleAmount17))
        );
    }
    glEnd();

    int i18;
    GLint x18= 315;
    GLint y18= 70;
    GLfloat radius18 =15;
    int triangleAmount18 = 30;
    GLfloat twicePi18 = 2.0f * PI;
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(173,255,47);
    glVertex2f(x18, y18);
    for(i18 = 0; i18 <= triangleAmount18; i18++)
    {
        glVertex2f(
            x18 + (radius18 * cos(i18 *  twicePi18 / triangleAmount18)),
            y18 + (radius18 * sin(i18 * twicePi18 / triangleAmount18))
        );
    }
    glEnd();

    int i19;
    GLint x19= 515;
    GLint y19= 70;
    GLfloat radius19 =15;
    int triangleAmount19 = 30;
    GLfloat twicePi19 = 2.0f * PI;
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(173,255,47);
    glVertex2f(x19, y19);
    for(i19 = 0; i19 <= triangleAmount19; i19++)
    {
        glVertex2f(
            x19 + (radius19 * cos(i19 *  twicePi19 / triangleAmount19)),
            y19 + (radius19 * sin(i19 * twicePi19 / triangleAmount19))
        );
    }
    glEnd();

    int i20;
    GLint x20= 715;
    GLint y20= 70;
    GLfloat radius20 =15;
    int triangleAmount20 = 30;
    GLfloat twicePi20 = 2.0f * PI;
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(173,255,47);
    glVertex2f(x20, y20);
    for(i20 = 0; i20 <= triangleAmount20; i20++)
    {
        glVertex2f(
            x20 + (radius20 * cos(i20 *  twicePi20 / triangleAmount20)),
            y20 + (radius20 * sin(i20 * twicePi20 / triangleAmount20))
        );
    }
    glEnd();

    int i21;
    GLint x21= 915;
    GLint y21= 70;
    GLfloat radius21 =15;
    int triangleAmount21 = 30;
    GLfloat twicePi21 = 2.0f * PI;
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(173,255,47);
    glVertex2f(x21, y21);
    for(i21 = 0; i21 <= triangleAmount21; i21++)
    {
        glVertex2f(
            x21 + (radius21 * cos(i21 *  twicePi21 / triangleAmount21)),
            y21 + (radius21 * sin(i21 * twicePi21 / triangleAmount21))
        );
    }
    glEnd();

    int i22;
    GLint x22= 1115;
    GLint y22= 70;
    GLfloat radius22 =15;
    int triangleAmount22 = 30;
    GLfloat twicePi22 = 2.0f * PI;
    glBegin(GL_TRIANGLE_FAN);
    glColor3ub(173,255,47);
    glVertex2f(x22, y22);
    for(i22 = 0; i22 <= triangleAmount22; i22++)
    {
        glVertex2f(
            x22 + (radius22 * cos(i22 *  twicePi22 / triangleAmount22)),
            y22 + (radius22 * sin(i22 * twicePi22 / triangleAmount22))
        );
    }
    glEnd();
	//lamp down on end

    //grass start
    for (c=0; c<=1200; c+=40){
        grass(c,v);
    }
    //grass end

    //night calling
    lamp(q,w);

    glFlush ();
}

void Rain(int value){
    if(rainday){
        _rain += 0.01f;
        glBegin(GL_POINTS);
        for(int i=1;i<=1200;i++){
            int x=rand(),y=rand();
            x%=1200; y%=1000;
            glBegin(GL_LINES);
            glColor3f(1.0, 1.0, 1.0);
            glVertex2d(x,y);
            glVertex2d(x+5,y+5);
            glEnd();
        }
	glutTimerFunc(5, Rain, 0);
    glFlush();
    }
}

void handleKeypress(unsigned char key, int x, int y) {
    if (key == 'n'){
        q=2000;
        glutPostRedisplay();
    }
    else if (key == 'd'){
        q=0;
        glutPostRedisplay();
    }
    if (key == 'r'){
            rainday = true;
            Rain(_rain);
            glutPostRedisplay();
    }
    else if (key == 's'){
            rainday = false;
            glutPostRedisplay();
    }
}

void myInit (){
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 1200.0, 0.0, 700.0);
}

int main(int argc, char** argv){
    cout << endl << "Bangladesh National parliament" << endl << endl;
    cout << "Press R : For Rain " << endl << endl;
    cout << "Press S : For Stop Rain" << endl << endl;
    cout << "Press N : For Night " << endl << endl;
    cout << "Press D : For Day" << endl << endl;

    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (1200, 700);
    glutInitWindowPosition (500, 300);
    glutCreateWindow ("Parliament");
    glutDisplayFunc(myDisplay);
    glutKeyboardFunc(handleKeypress);
    glutIdleFunc(carmove);
    glutTimerFunc(1000, update, 0);
    myInit ();
    glutMainLoop();
}
