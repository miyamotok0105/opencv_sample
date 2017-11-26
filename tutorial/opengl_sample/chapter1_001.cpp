#include <GLUT/glut.h>
#include <stdlib.h>

//g++ -o chapter1_001 chapter1_001.cpp -framework GLUT -framework OpenGL -w

void display(void)				/*画面描画時に呼ばれる*/
{
   static GLfloat spin = 0.0;
   spin = spin + 1.0;				/*spinを増加*/
   if (spin > 360.0)
      spin = spin - 360.0;
   glClear(GL_COLOR_BUFFER_BIT);		/*バッファのクリア*/
   glPushMatrix();				/*行列をプッシュ*/
   glRotatef(spin, 0.0, 0.0, 1.0);		/*spin[度]回転*/
   glColor3f(1.0, 1.0, 1.0);			/*白色に設定*/
   glRectf(-25.0, -25.0, 25.0, 25.0);		/*正方形を描画*/
   glPopMatrix();				/*行列をポップ*/

   glFlush();					/*描画*/
   glutSwapBuffers();				/*バッファを交換*/
}

void init(void) 
{
   glClearColor (0.0, 0.0, 0.0, 0.0);		/*黒で画面クリア*/
   glShadeModel (GL_FLAT);			/*フラットシェーディング*/
}

void reshape(int w, int h)			/*画面サイズ変更時に呼ばれる*/
{
   glViewport(0, 0, (GLsizei) w, (GLsizei) h);	/*画面の出る範囲*/
   glMatrixMode(GL_PROJECTION);			/*視界変換宣言*/
   glLoadIdentity();				/*単位行列代入*/
   glOrtho(-50.0, 50.0, -50.0, 50.0, -1.0, 1.0);/*視体積の設定*/
   glMatrixMode(GL_MODELVIEW);			/*モデル変換宣言*/
   glLoadIdentity();				/*単位行列代入*/
}

int main(int argc, char** argv)
{
   glutInit(&argc, argv);			/*GLUT初期化*/
   glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);/*表示モード設定*/
   glutInitWindowSize (250, 250);		/*画面の大きさ設定*/
   glutInitWindowPosition (100, 100);		/*画面の位置設定*/
   glutCreateWindow (argv[0]);			/*引数の名前のウインドウ作成*/
   init ();					
   glutIdleFunc(display);			/*アイドル時に呼ぶ関数*/
   glutDisplayFunc(display);			/*表示時に呼ぶ関数*/
   glutReshapeFunc(reshape);			/*画面サイズ変更時に呼ぶ関数*/
   glutMainLoop();				/*描画開始*/
   return 0;					
}

