#include <windows.h>
#include <MMSystem.h>
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <math.h>

static double time = 0;
static double time2 = 0;
static double time3 = 0;
static double time4 = 0;
static double time6 = 0;


GLfloat R_Arm_x = 0;
GLfloat R_Arm_y = 0;
GLfloat L_Arm_x = 0;
GLfloat L_Arm_y = 0;
GLfloat R_Leg_x = 0;
GLfloat R_Leg_y = 0;
GLfloat L_Leg_x = 0;
GLfloat L_Leg_y = 0;
GLfloat R = 0;
GLfloat R2 = 0;

GLUquadricObj* cyl;

int a = 0;
int b = 0;
int c = 0;


static int flag = 0;
static int key = 0;

#define EXIT 6

void glInit(void) {
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_NORMALIZE);
    glEnable(GL_SMOOTH);
    glEnable(GL_LIGHTING);
    GLfloat ambientLight[] = { 0.3f, 0.3f, 0.3f, 1.0f };
    GLfloat diffuseLight[] = { 0.7f, 0.7f, 0.7f, 1.0f };
    GLfloat specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    GLfloat specref[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    GLfloat position[] = { 400.0, 300.0, -700.0, 1.0 };
    glLightfv(GL_LIGHT0, GL_AMBIENT, ambientLight);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuseLight);
    glLightfv(GL_LIGHT0, GL_SPECULAR, specular);
    glLightfv(GL_LIGHT0, GL_POSITION, position);
    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
    glMateriali(GL_FRONT, GL_SHININESS, 128);
    glClearColor(1.0, 1.0, 1.0, 1.0); // 배경은 검은색
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0); // 가시 범위 설정
}

void Draw_Color(int i) {
    if (i == 1) {
        glColor3f(0.0, 1.0, 0.0);
    }
    else if (i == 2) {
        glColor3f(1.0, 1.0, 0.0);
    }
    else if (i == 3) {
        glColor3f(0.0, 1.0, 1.0);
    }

}

void Change_Wire_Or_Solid(int i) {
    if (flag == 1)
        gluQuadricDrawStyle(cyl, GLU_LINE);
    else
        gluQuadricDrawStyle(cyl, GLU_FILL);
}

void DrawL_Arm(int x, int a, int b, int c) {
    glPushMatrix();
    Draw_Color(key);
    cyl = gluNewQuadric();
    glRotatef(x, a, b, c);
    glRotatef(90.0, 1.0, 0.0, 0.0);
    glTranslatef(0.25, 0.0, 0.0);
    glRotatef(15.0, 0.0, 1.0, 0.0);
    Change_Wire_Or_Solid(flag);
    gluCylinder(cyl, 0.05, 0.05, 0.2, 50, 1);
}

void DrawL_Hand(int y, int a, int b, int c) {
    glPushMatrix();
    Draw_Color(key);
    cyl = gluNewQuadric();
    glTranslatef(0.0, 0.0, 0.22);
    glRotatef(y, a, b, c);
    Change_Wire_Or_Solid(flag);
    if (key == 4)
        gluCylinder(cyl, 0.05, 0.02, 0.2, 15, 1);
    else
        gluCylinder(cyl, 0.05, 0.05, 0.2, 15, 1);
    glPopMatrix();
}

void DrawL_HandRocket() {
    glPushMatrix();
    Draw_Color(key);
    cyl = gluNewQuadric();
    glTranslatef(0.0, 0.0, R);
    Change_Wire_Or_Solid(flag);
    gluCylinder(cyl, 0.05, 0.05, 0.2, 50, 1);
    glPopMatrix();
}

void DrawR_Arm(int x, int a, int b, int c) {
    glPushMatrix();
    Draw_Color(key);
    cyl = gluNewQuadric();
    glRotatef(x, a, b, c);
    glRotatef(90.0, 1.0, 0.0, 0.0);
    glTranslatef(-0.25, 0.0, 0.0);
    glRotatef(-15.0, 0.0, 1.0, 0.0);
    Change_Wire_Or_Solid(flag);
    gluCylinder(cyl, 0.05, 0.05, 0.2, 50, 1);
}

void DrawR_Hand(int y, int a, int b, int c) {
    glPushMatrix();
    Draw_Color(key);
    cyl = gluNewQuadric();
    glTranslatef(0.0, 0.0, 0.22);
    glRotatef(y, a, b, c);
    Change_Wire_Or_Solid(flag);
    if (key == 4)
        gluCylinder(cyl, 0.05, 0.02, 0.2, 50, 1);
    else
        gluCylinder(cyl, 0.05, 0.05, 0.2, 50, 1);
    glPopMatrix();
}

void DrawR_HandRocket() {
    glPushMatrix();
    Draw_Color(key);
    cyl = gluNewQuadric();
    glTranslatef(0.0, 0.0, R2);
    Change_Wire_Or_Solid(flag);
    gluCylinder(cyl, 0.05, 0.05, 0.2, 50, 1);
    glPopMatrix();
}

void DrawBody(int x, int a, int b, int c) {
    glPushMatrix();
    Draw_Color(key);
    cyl = gluNewQuadric();
    glRotatef(90.0, 1.0, 0.0, 0.0);
    glRotatef(x, a, b, c);
    Change_Wire_Or_Solid(flag);
    gluCylinder(cyl, 0.2, 0.2, 0.45, 50, 1);
    glPopMatrix();
}

void DrawL_Legs(int x, int a, int b, int c) {
    glPushMatrix();
    Draw_Color(key);
    cyl = gluNewQuadric();
    glRotatef(90.0, 1.0, 0.0, 0.0);
    glTranslatef(0.1, 0.0, 0.42);
    glRotatef(x, a, b, c);
    Change_Wire_Or_Solid(flag);
    gluCylinder(cyl, 0.05, 0.05, 0.15, 50, 1);
}

void DrawL_foot(int y, int a, int b, int c) {
    glPushMatrix();
    Draw_Color(key);
    cyl = gluNewQuadric();
    glTranslatef(0.0, 0.0, 0.18);
    glRotatef(y, a, b, c);
    Change_Wire_Or_Solid(flag);
    if (key == 4)
        gluCylinder(cyl, 0.05, 0.03, 0.2, 50, 1);
    else
        gluCylinder(cyl, 0.05, 0.05, 0.2, 50, 1);
    glPopMatrix();
}

void DrawR_Legs(int x, int a, int b, int c) {
    glPushMatrix();
    Draw_Color(key);
    cyl = gluNewQuadric();
    glRotatef(90.0, 1.0, 0.0, 0.0);
    glTranslatef(-0.1, 0.0, 0.42);
    glRotatef(x, a, b, c);
    Change_Wire_Or_Solid(flag);
    gluCylinder(cyl, 0.05, 0.05, 0.15, 50, 1);
}

void DrawR_foot(int y, int a, int b, int c) {
    glPushMatrix();
    Draw_Color(key);
    cyl = gluNewQuadric();
    glTranslatef(0.0, 0.0, 0.18);
    glRotatef(y, a, b, c);
    Change_Wire_Or_Solid(flag);
    if (key == 4)
        gluCylinder(cyl, 0.05, 0.03, 0.2, 15, 1);
    else
        gluCylinder(cyl, 0.05, 0.05, 0.2, 15, 1);
    glPopMatrix();
}

void DrawNeck() {
    glPushMatrix();
    glColor3f(1.0, 1.0, 1.0);
    cyl = gluNewQuadric();
    glRotatef(90.0, 1.0, 0.0, 0.0);
    glTranslatef(0.0, 0.0, -0.045);
    Change_Wire_Or_Solid(flag);
    gluCylinder(cyl, 0.02, 0.02, 0.025, 100, 1);
    glPopMatrix();
}
void DrawBaseballBat(int y, int a, int b, int c) {

    glPushMatrix();
    glRotatef(y, a, b, c);

    glRotatef(20, 1, 0, 0);
    glColor3f(0.8f, 0.5f, 0.2f);


    cyl = gluNewQuadric();
    glRotatef(90.0, 1.0, 0.0, 0.0); 
    glRotatef(180, 0.0, 0.0, 1.0);
    glTranslatef(0.0, -0.5, 0.2);  
    Change_Wire_Or_Solid(flag);    
    gluCylinder(cyl, 0.03, 0.02, 0.5, 50, 50);


    glPushMatrix();
    glTranslatef(0.0, 0.0, 0.5); 
    glColor3f(0.6f, 0.3f, 0.0f); 
    gluCylinder(cyl, 0.02, 0.02, 0.1, 50, 50); 
    glPopMatrix();

  
    glPushMatrix();
    glTranslatef(0.0, 0.0, 0.0); 
    glColor3f(0.7f, 0.4f, 0.1f); 
    gluDisk(cyl, 0.0, 0.03, 50, 1); 
    glPopMatrix();
}


void DrawGround() {
    Draw_Color(flag);
    glTranslatef(0.0, -2.73, 0.0);
    glRotatef(45.0, 0, 1, 0);
    glRotatef(15, 0.0, 0.0, 1);
    Change_Wire_Or_Solid(flag);
    gluSphere(cyl, 2.5, 30, 90);
}
void DrawHead() {
    glTranslatef(0.0, 0.02, 0.0);
    glPushMatrix();
    cyl = gluNewQuadric();
    Change_Wire_Or_Solid(flag);
    Draw_Color(key);
    gluSphere(cyl, 0.20, 30, 10);

    glRotatef(90.0, 1.0, 0.0, 0.0);

    glTranslatef(-0.16, 0.0, -0.22);
    glRotatef(35.0, 0.0, 1.0, 0.0);
    gluCylinder(cyl, 0.005, 0.008, 0.1, 3, 1);
    glPopMatrix();
    glPushMatrix();


    glRotatef(90.0, 1.0, 0.0, 0.0);

    glTranslatef(0.16, 0.0, -0.22);
    glRotatef(-35.0, 0.0, 1.0, 0.0);
    gluCylinder(cyl, 0.005, 0.008, 0.1, 3, 1);
    glPopMatrix();
    glPushMatrix();

  
    glTranslatef(-0.1, 0.1, 0.13);
    glColor3f(0.0, 0.0, 0.0);
    gluSphere(cyl, 0.03, 10, 10);
    glPopMatrix();
    glPushMatrix();

 
    glTranslatef(0.1, 0.1, 0.13);
    gluSphere(cyl, 0.03, 10, 10);
    glPopMatrix();
}

void DrawAndroid() {
    DrawBody(0, 0, 0, 0);
    DrawNeck();
    DrawHead();
    DrawR_Arm(R_Arm_x, 1, 0, 0);
    DrawR_Hand(R_Arm_y, 1, 0, 0);
    DrawL_Arm(L_Arm_x, 1, 0, 0);
    DrawL_Hand(L_Arm_y, 1, 0, 0);
    DrawL_Legs(L_Leg_x, 1, 0, 0);
    DrawL_foot(L_Leg_y, 1, 0, 0);
    DrawR_Legs(R_Leg_x, 1, 0, 0);
    DrawR_foot(R_Leg_y, 1, 0, 0);

}


void MyKeyboard(unsigned char KeyPressed, int x, int y) {
    switch (KeyPressed) {
    case 'w':
        flag = 1;
        break;
    case 's':
        flag = 0;
        break;
    case 'q':
        key = EXIT;
        break;
    }
}




void Ball() {
    glLoadIdentity();
    cyl = gluNewQuadric();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);

    R_Arm_x = -50; 
    R_Arm_y = -40;
    L_Arm_x = -30; 
    L_Arm_y = 0; 
    GLfloat L_Arm_z = -40; 
    R_Leg_x = 0;
    R_Leg_y = 0;
    L_Leg_x = 0;
    L_Leg_y = 0;
    float an = sin(time) * 10 - 5;

    glPushMatrix();
    glColor3f(0.0, 1.0, 0.0);
    glTranslatef(0.0, -2.73, 0.0);
    glRotatef(45.0, 0, 1, 0);
    glRotatef(15, 0.0, 0.0, 1);
    Change_Wire_Or_Solid(flag);
    gluSphere(cyl, 2.5, 30, 90);
    glPopMatrix();

    glLoadIdentity();
    glRotatef(-160, 0, 1, 0);


    glTranslatef(0.0, 0, 0);
    glTranslatef(0.0, 0.5, 0.0);

    glPushMatrix();
    glRotatef(-an * 3, 0.0, 1.0, 0.0);
    DrawBody(0, 0, 0, 0);
    glPopMatrix();
    glPushMatrix();

    DrawNeck();
    glPopMatrix();

    
    glPushMatrix();
    glRotatef(an, 0.0, 1.0, 0.0);
    glRotatef(45.0, 0.0, 1.0, 0.0); 
    DrawHead(); 
    glPopMatrix();


    glPushMatrix();
    glRotatef(abs(an * 4), 0.0, 1.0, 0.0);

    DrawR_Arm(R_Arm_x, 1, 0, 0); 

    glRotatef(abs(an*4), 0.0, 1.0, 0.0);
    DrawR_Hand(R_Arm_y, 1, 0, 0); 
    glPopMatrix();

 
    glPushMatrix();
    glRotatef(L_Arm_x, 1, 0, 0);
    glRotatef(-an * 3, 0, 0, 1); 
    glTranslatef(-0.2, 0.0, 0.0);
    DrawL_Arm(L_Arm_x, 1, 0, 0);
    glRotatef(-60, 0, 1, 0);
    glTranslatef(0.2, 0, 0);
    DrawL_Hand(L_Arm_y, 1, 0, 0);
    glPopMatrix();

    glPushMatrix();
    DrawL_Legs(L_Leg_x, 1, 0, 0);
    DrawL_foot(L_Leg_y, 1, 0, 0);
    glPopMatrix();
    glPushMatrix();
    DrawR_Legs(R_Leg_x, 1, 0, 0);
    DrawR_foot(R_Leg_y, 1, 0, 0);
    glPopMatrix();

    glPushMatrix();
    
    
    glTranslatef(-0.1, 0.7, 0.1);
    glRotatef(-an*0.8, 0, 0, 1);
    glRotatef(an*0.1, 1, 0, 0);
    glRotatef(-an*1.5, 0, 1, 0); 
    DrawBaseballBat(an, 0, 1, 0); 
    glPopMatrix();

    glutSwapBuffers();
}

void Jump() {
    glLoadIdentity();
    float ch = sin(time);

    float jumpH= (ch > 0 ? ch * 0.1 : -abs(ch * 0.1));

    L_Arm_x = sin(time) * 90;
    R_Arm_x = L_Arm_x;


    R_Leg_y = abs(-sin(time) * 30 - 30);
    L_Leg_y = R_Leg_y;
    R_Leg_x = abs(-sin(time) * 30 - 30);
    L_Leg_x = R_Leg_x;

    cyl = gluNewQuadric();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    DrawGround();
    glLoadIdentity();
    glRotatef(-220, 0, 1, 0);


    glPushMatrix();
    glTranslatef(0.0, jumpH, 0);
    glTranslatef(0.0, 0.5, 0.0);
    DrawAndroid();
    glutSwapBuffers();
}

void Run() {
    glLoadIdentity();
    float titi = time * time / 8;
    float jumpH = 0;

    if (fmod(titi, 220.0) > 190.0) {
        time -= 30;
    }

    if (fmod(titi, 220.0) < 150.0) {
        L_Arm_x = sin(titi) * 80;
        R_Arm_x = -L_Arm_x;
        R_Arm_y = -abs(sin(titi) * 60 + 50);

        L_Arm_y = -abs(-sin(titi) * 60 + 50);
        R_Leg_y = abs(-sin(titi) * 30 - 30);
        L_Leg_y = abs(sin(titi) * 30 - 30);
        R_Leg_x = sin(titi) * 60;
        L_Leg_x = -R_Leg_x;

        cyl = gluNewQuadric();
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glMatrixMode(GL_MODELVIEW);
        Draw_Color(flag);
        glTranslatef(0.0, -2.73, 0.0);
        glRotatef(45.0, 0, 1, 0);
        glRotatef(0.0 + titi * 2.5, 0.0, 0.0, 1);
        Change_Wire_Or_Solid(flag);
        gluSphere(cyl, 2.5, 30, 90);
        glLoadIdentity();
        glRotatef(-230.0, 0, 1, 0);
        glRotatef(abs(sin(titi) * 16), 1, 0, 0);
        glRotatef(sin(titi) * 16, 0, 1, 0);

        float i = 0;
        i = abs(sin(titi) * 0.08);
        glPushMatrix();
        glTranslatef(0.0, i + jumpH, 0);
        glTranslatef(0.0, 0.5, 0.0);
        DrawAndroid();
        glutSwapBuffers();
    }
    else if(fmod(titi, 220.0)>180.0)
    {
        cyl = gluNewQuadric();
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glMatrixMode(GL_MODELVIEW);
        Draw_Color(flag);
        glTranslatef(0.0, -2.73, 0.0);
        glRotatef(45.0, 0, 1, 0);
        glRotatef(0.0 + titi * 2.5, 0.0, 0.0, 1);
        Change_Wire_Or_Solid(flag);
        gluSphere(cyl, 2.5, 30, 90);
        glLoadIdentity();
        glRotatef(-230.0, 0, 1, 0);
        glRotatef(abs(sin(titi) * 16), 1, 0, 0);
        glRotatef(sin(titi) * 16, 0, 1, 0);

        float i = 0;
        i = abs(sin(titi) * 0.08);
        glPushMatrix();
        glTranslatef(0.0, i + jumpH, 0);
        glTranslatef(0.0, 0.5, 0.0);
        DrawAndroid();
        glutSwapBuffers();
    }
    else{
        jumpH = fabs(sin(time) * 0.3);

        L_Arm_x = -abs(sin(time) * 30 - 21);
        R_Arm_x = L_Arm_x;


        R_Leg_y = -abs(sin(time) * 30 - 21);
        L_Leg_y = R_Leg_y;
        R_Leg_x = -abs(sin(time) * 30 - 21);
        L_Leg_x = R_Leg_x;

        cyl = gluNewQuadric();
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glMatrixMode(GL_MODELVIEW);
        Draw_Color(flag);
        glTranslatef(0.0, -2.73, 0.0);
        glRotatef(45.0, 0, 1, 0);
        glRotatef(0.0 + titi * 2.5, 0.0, 0.0, 1);

        Change_Wire_Or_Solid(flag);
        gluSphere(cyl, 2.5, 30, 90);
        glLoadIdentity();
        glRotatef(-230.0, 0, 1, 0);
        glRotatef(40, 1, 0, 0);

        glPushMatrix();
        glTranslatef(0.0, jumpH, 0);
        glTranslatef(0.0, 0.5, 0.0);
        DrawAndroid();
        glutSwapBuffers();
    }


}


void MyDisplay() {
    if (key == 1) {
        Jump();
        glPopMatrix();
    }
    else if (key == 2) {
        Ball();
        glPopMatrix();
    }
    else if (key == 3) {
        Run();
        glPopMatrix();
    }

}

void MyTimer(int Value) {
    time = time + 0.1;

    time2 = time2 + 0.5;
    time3 = time3 + 0.01;
    time4 = time4 + 1.0;
    glutPostRedisplay();
    glutTimerFunc(40, MyTimer, 1);
}

void MyMainMenu(int entryID) {
    key = entryID;
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Catch Me If You Can");
    glInit();
    GLint MyMainMenuID = glutCreateMenu(MyMainMenu);
    glutAddMenuEntry("1", 1);
    glutAddMenuEntry("2", 2);
    glutAddMenuEntry("3", 3);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    glutKeyboardFunc(MyKeyboard);
    glutTimerFunc(40, MyTimer, 1);
    glutDisplayFunc(MyDisplay);
    glutMainLoop();
    return 0;
}
