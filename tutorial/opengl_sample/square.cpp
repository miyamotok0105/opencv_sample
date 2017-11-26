#include <GLUT/glut.h>

#define WIDTH 640
#define HEIGHT 480

//g++ -o Square Square.cpp -framework GLUT -framework OpenGL -w

//描画関数：始点x,y、終点x,y,サイズ
void Square2D(int x1,int y1,int x2, int y2,float size){
    glLineWidth(size);
    glBegin(GL_LINE_LOOP);
    glVertex2i(x1,y1);
    glVertex2i(x2,y1);
    glVertex2i(x2,y2);
    glVertex2i(x1,y2);
    glEnd();
}
//描画関数：各点を指定、サイズ
void Square2D(int x1,int y1,int x2, int y2,int x3,int y3,int x4,int y4,float size){
    glLineWidth(size);
    glBegin(GL_LINE_LOOP);
    glVertex2i(x1,y1);
    glVertex2i(x2,y2);
    glVertex2i(x3,y3);
    glVertex2i(x4,y4);
    glEnd();
}
//描画関数：塗りつぶし、始点x,y、終点x,y,サイズ
void SquareFill2D(int x1,int y1,int x2, int y2){
    glBegin(GL_QUADS);
    glVertex2i(x1,y1);
    glVertex2i(x2,y1);
    glVertex2i(x2,y2);
    glVertex2i(x1,y2);
    glEnd();
}
//描画関数：塗りつぶし、各点を指定、サイズ
void SquareFill2D(int x1,int y1,int x2, int y2,int x3,int y3,int x4,int y4){
    glBegin(GL_QUADS);
    glVertex2i(x1,y1);
    glVertex2i(x2,y2);
    glVertex2i(x3,y3);
    glVertex2i(x4,y4);
    glEnd();
}

void display(void){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    //1
    glColor4f(1.0f,0.0f,1.0f,1.0f);
    Square2D(30,20,200,120,1.0f);
    //2
    glColor4f(0.0f,0.0f,1.0f,1.0f);
    Square2D(300,20,400,60,500,120,250,100,3.0f);
    //3
    glColor4f(0.0f,0.5f,0.0f,1.0f);
    SquareFill2D(30,250,500,400);
    //4
    glColor4f(1.0f,0.5f,0.0f,1.0f);
    SquareFill2D(350,170,500,150,480,200,370,220);
    glFlush();
}

void Init(){
    //背景色を黒に設定
    //glClearColor(1.0, 1.0, 1.0, 1.0);
    glClearColor(0.0, 0.0, 0.0, 1.0);   
    glOrtho(0, WIDTH, HEIGHT, 0, -1, 1);
}

int main(int argc, char *argv[])
{
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA);
    glutCreateWindow("四角形を描画");
    glutDisplayFunc(display);
    Init();
    glutMainLoop();
    return 0;
}