// TeaPot3D.cpp - Isabel H. Manssour
// Um programa OpenGL que exemplifica a visualiza??o
// de objetos 3D.

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdio.h>
#include <stdlib.h>

GLfloat angle, fAspect, rotX, rotY;
GLdouble obsX, obsY, obsZ;

GLint especMaterial;

float r, g, b;
float x, y, z;

// Fun��o respons�vel pela especifica��o dos par�metros de ilumina��o
void DefineIluminacao (void)
{
GLfloat luzAmbiente[4]={0.2,0.2,0.2,1.0};
GLfloat luzDifusa[4]={0.7,0.7,0.7,1.0}; // "cor"
GLfloat luzEspecular[4]={r, g, b, 1.0};// "brilho"
GLfloat posicaoLuz[4]={0.0, 50.0, 50.0, 1.0};
GLfloat posicaoLuz1[4]={x, y, z, 1.0};
// Capacidade de brilho do material
GLfloat especularidade[4]={1.0,1.0,1.0,1.0};
// Define a reflet�ncia do material
glMaterialfv(GL_FRONT,GL_SPECULAR, especularidade);
// Define a concentra��o do brilho
glMateriali(GL_FRONT,GL_SHININESS,especMaterial);
// Ativa o uso da luz ambiente
glLightModelfv(GL_LIGHT_MODEL_AMBIENT, luzAmbiente);
// Define os par�metros da luz de n�mero 0
glLightfv(GL_LIGHT0, GL_AMBIENT, luzAmbiente);
glLightfv(GL_LIGHT0, GL_DIFFUSE, luzDifusa );
glLightfv(GL_LIGHT0, GL_SPECULAR, luzEspecular );
glLightfv(GL_LIGHT0, GL_POSITION, posicaoLuz );

glLightfv(GL_LIGHT1, GL_AMBIENT, luzAmbiente);
glLightfv(GL_LIGHT1, GL_DIFFUSE, luzDifusa );
glLightfv(GL_LIGHT1, GL_SPECULAR, luzEspecular );
glLightfv(GL_LIGHT1, GL_POSITION, posicaoLuz1 );
}

// Fun??o callback chamada para fazer o desenho
void Desenha(void)
{
	// Limpa a janela de visualiza??o com a cor
	// de fundo definida previamente
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	DefineIluminacao();
	// Troca cor corrente para azul
	glColor3f(0.0f, 0.0f, 1.0f);

	// Desenha um cubo
	glBegin(GL_TRIANGLE_STRIP); // Face posterior
		glNormal3f(0,0,1); // Normal da face
		glVertex3f(50.0, 50.0, 50.0);
		glVertex3f(-50.0, 50.0, 50.0);
		glVertex3f(-50.0, -50.0, 50.0);
		glVertex3f(50.0, -50.0, 50.0);
		glVertex3f(50.0, 50.0, 50.0);
	glEnd();
	glBegin(GL_TRIANGLE_STRIP); // Face frontal
		glNormal3f(0,0,-1); // Normal da face
		glVertex3f(50.0, 50.0, -50.0);
		glVertex3f(50.0, -50.0, -50.0);
		glVertex3f(-50.0, -50.0, -50.0);
		glVertex3f(-50.0, 50.0, -50.0);
		glVertex3f(50.0, 50.0, -50.0);
	glEnd();
	glBegin(GL_TRIANGLE_STRIP); // Face lateral esquerda
		glNormal3f(-1,0,0); // Normal da face
		glVertex3f(-50.0, 50.0, 50.0);
		glVertex3f(-50.0, 50.0, -50.0);
		glVertex3f(-50.0, -50.0, -50.0);
		glVertex3f(-50.0, -50.0, 50.0);
		glVertex3f(-50.0, 50.0, 50.0);
	glEnd();
	glBegin(GL_TRIANGLE_STRIP); // Face lateral direita
		glNormal3f(1,0,0); // Normal da face
		glVertex3f(50.0, 50.0, 50.0);
		glVertex3f(50.0, -50.0, 50.0);
		glVertex3f(50.0, -50.0, -50.0);
		glVertex3f(50.0, 50.0, -50.0);
		glVertex3f(50.0, 50.0, 50.0);
	glEnd();
	glBegin(GL_TRIANGLE_STRIP); // Face superior
		glNormal3f(0,1,0); // Normal da face
		glVertex3f(-50.0, 50.0, -50.0);
		glVertex3f(-50.0, 50.0, 50.0);
		glVertex3f(50.0, 50.0, 50.0);
		glVertex3f(50.0, 50.0, -50.0);
		glVertex3f(-50.0, 50.0, -50.0);
	glEnd();
	glBegin(GL_TRIANGLE_STRIP); // Face inferior
		glNormal3f(0,-1,0); // Normal da face
		glVertex3f(-50.0, -50.0, -50.0);
		glVertex3f(50.0, -50.0, -50.0);
		glVertex3f(50.0, -50.0, 50.0);
		glVertex3f(-50.0, -50.0, 50.0);
		glVertex3f(-50.0, -50.0, -50.0);
	glEnd();


	// Execu??o dos comandos de desenho
	glutSwapBuffers();
}


// Inicializa��o
void Inicializa(void)
{

	r = 1.0;
	g = 1.0;
	b = 1.0;

	x=0;
	y=0;
	z=0;

	especMaterial = 60;

	// Define a cor de fundo da janela de visualiza��o como branca
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	// Habilita a defini��o da cor do material a partir da cor corrente
	glEnable(GL_COLOR_MATERIAL);
	//Habilita o uso de ilumina��o
	glEnable(GL_LIGHTING);
	// Habilita a luz de n�mero 0
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
	// Habilita o depth-buffering
	glEnable(GL_DEPTH_TEST);
	// Habilita o modelo de coloriza��o de Gouraud
	glShadeModel(GL_SMOOTH);
	// Inicializa a vari�vel que especifica o �ngulo da proje��o
	// perspectiva
	angle=50;
	// Inicializa as vari�veis usadas para alterar a posi��o do
	// observador virtual
	rotX = 30;
	rotY = 0;
	obsZ = 180;
}


// Fun??o usada para especificar a posi??o do observador virtual
void PosicionaObservador(void)
{
	// Especifica sistema de coordenadas do modelo
	glMatrixMode(GL_MODELVIEW);
	// Inicializa sistema de coordenadas do modelo
	glLoadIdentity();
	DefineIluminacao();
	// Especifica posi??o do observador e do alvo
	glTranslatef(0,0,-obsZ);
	glRotatef(rotX,1,0,0);
	glRotatef(rotY,0,1,0);
}


// Fun??o usada para especificar o volume de visualiza??o
void EspecificaParametrosVisualizacao(void)
{
	// Especifica sistema de coordenadas de proje??o
	glMatrixMode(GL_PROJECTION);
	// Inicializa sistema de coordenadas de proje??o
	glLoadIdentity();

	// Especifica a proje??o perspectiva(angulo,aspecto,zMin,zMax)
	gluPerspective(angle,fAspect,0.5,500);

	PosicionaObservador();
}


// Fun??o callback chamada quando o tamanho da janela ? alterado
void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{
	// Para previnir uma divis?o por zero
	if ( h == 0 ) h = 1;

	// Especifica as dimens?es da viewport
	glViewport(0, 0, w, h);

	// Calcula a corre??o de aspecto
	fAspect = (GLfloat)w/(GLfloat)h;

	EspecificaParametrosVisualizacao();
}


// Callback para gerenciar eventos do mouse
void GerenciaMouse(int button, int state, int x, int y)
{
	if (button == GLUT_LEFT_BUTTON)
		if (state == GLUT_DOWN) {
			// Zoom-in
			if (angle >= 10)
				angle -= 5;
		}
	if (button == GLUT_RIGHT_BUTTON)
		if (state == GLUT_DOWN) {
			// Zoom-out
			if (angle <= 130)
				angle += 5;
		}
	EspecificaParametrosVisualizacao();
	glutPostRedisplay();
}


// Fun??o callback chamada para gerenciar eventos de teclas especiais (F1,PgDn,...)
void TeclasEspeciais (int tecla, int x, int y)
{
	switch (tecla)
	{
		case GLUT_KEY_LEFT:	rotY--;
							break;
		case GLUT_KEY_RIGHT:rotY++;
							break;
		case GLUT_KEY_UP:	rotX++;
							break;
		case GLUT_KEY_DOWN:	rotX--;
							break;
		case GLUT_KEY_HOME:	obsZ++;
							break;
		case GLUT_KEY_END:	obsZ--;
							break;
		case GLUT_KEY_F1:	if(especMaterial+5 < 160) especMaterial += 5;
							else especMaterial = 160;
							break;
		case GLUT_KEY_F2:	if(especMaterial-5 > 0) especMaterial -= 5;
							else especMaterial = 0;
							break;
	}
	PosicionaObservador();
	glutPostRedisplay();
}


// Programa Principal
int main()
{
	int argc = 0;
	char *argv[] = { (char *)"gl", 0 };

	glutInit(&argc,argv);

	// Define do modo de operacao da GLUT
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

	// Especifica a posi??o inicial da janela GLUT
    glutInitWindowPosition(5,5);

	// Especifica o tamanho inicial em pixels da janela GLUT
	glutInitWindowSize(400,400);

	// Cria a janela passando como argumento o titulo da mesma
	glutCreateWindow("Desenho de um teapot com ilumina??o");

	// Registra a funcao callback de redesenho da janela de visualizacao
	glutDisplayFunc(Desenha);
	// Registra a funcao callback para tratamento das teclas especiais
	glutSpecialFunc(TeclasEspeciais);
	// Registra a funcao callback para tratamento do redimensionamento da janela
    glutReshapeFunc(AlteraTamanhoJanela);
	// Registra a funcao callback para tratamento do mouse
	glutMouseFunc(GerenciaMouse);

	Inicializa();
	glutMainLoop();
}

