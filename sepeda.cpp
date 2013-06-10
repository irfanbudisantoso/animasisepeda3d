#include "sepeda.h" 
void Silinder1(GLfloat radius,GLfloat length) 
{ 
   GLUquadricObj *cylinder; 
   cylinder=gluNewQuadric(); 
   glPushMatrix();   
      glTranslatef(0.0f,0.0f,0.0f); 
      gluCylinder(cylinder,radius,radius,length,15,5); 
   glPopMatrix(); 
} 
void rangka() 
{ 
   glColor3f(1.0f,0.0f,0.0f); 
   glPushMatrix();
   glPushMatrix(); 
   glColor3f(0.2f,0.7f,0.2f); 
  	 glColor3f(0.3f,0.8f,0.2f);  
         glTranslatef(0.0f,0.0f,-0.2f); 
         Silinder1(0.08f,0.32f); 
      glPopMatrix(); 
      glPopMatrix();   
   glPopMatrix(); 
} 
void init() 
{ 
   GLfloat mat_specular[]={1.0,1.0,1.0,1.0}; 
   GLfloat mat_shininess[]={100.0}; 
   GLfloat light_directional[]={1.0,1.0,1.0,1.0}; 
   GLfloat light_positional[]={1.0,1.0,1.0,0.0}; 
   GLfloat light_diffuse[]={1.0,1.0,1.0}; 
   reset(); 
   glShadeModel(GL_SMOOTH);    
   glEnable(GL_NORMALIZE);
   glEnable(GL_LIGHTING); 
   glEnable(GL_LIGHT0); 
   glEnable(GL_COLOR_MATERIAL); 
   glEnable(GL_DEPTH_TEST); 
}  
void display(void) 
{ 
   glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
   glEnable(GL_NORMALIZE); 

   glPushMatrix();    
      glRotatef(angley,1.0f,0.0f,0.0f); 
      glRotatef(anglex,0.0f,1.0f,0.0f); 
      glRotatef(anglez,0.0f,0.0f,1.0f); 
      glPushMatrix(); 
         glTranslatef(xpos,0.0f,zpos); 
         glRotatef(direction,0.0f,1.0f,0.0f); 
         rangka();    
      glPopMatrix(); 
   glPopMatrix(); 
   glMatrixMode(GL_MODELVIEW); 
   glLoadIdentity(); 
   gluLookAt(camx,camy,camz,  camx,0.0,0.0,  0.0,1.0,0.0); 
   glutSwapBuffers(); 
} 
void special(int key,int x,int y) 
{ 
   switch(key) 
   { 
      case GLUT_KEY_UP: 
         camz -= 0.1f; 
         break; 
      case GLUT_KEY_DOWN: 
         camz += 0.1f; 
         break; 
      case GLUT_KEY_LEFT: 
         camx -= 0.1f; 
         break; 
      case GLUT_KEY_RIGHT: 
         camx += 0.1f; 
         break; 
   } 
   glutPostRedisplay(); 
} 
void reset() 
{ 
   anglex=angley=anglez=0.0f; 
   Mouse=GLUT_UP; 
   camx=camy=1.0f; 
   camz=5.0f; 
   xpos=zpos=0.0f; 
   direction=-10.0f; 
} 
void reshape(int w,int h) 
{ 
   glViewport(0,0,(GLsizei)w,(GLsizei)h); 
   glMatrixMode(GL_PROJECTION); 
   glLoadIdentity(); 
   gluPerspective(60.0,(GLfloat)w/(GLfloat)h,0.1,100.0); 
   glMatrixMode(GL_MODELVIEW); 
   glLoadIdentity(); 
   gluLookAt(camx,camy,camz,  0.0,0.0,0.0,  0.0,1.0,0.0); 
} 

void glSetupFuncs(void) 
{ 
   glutDisplayFunc(display); 
   glutReshapeFunc(reshape); 
   glutSpecialFunc(special); 
   glutSetCursor(GLUT_CURSOR_CROSSHAIR); 
} 

void help(void) 
{ 
   printf("ANIMASI SEPEDA 3D\n"); 
   printf("IF17K - KOMPUTER GRAFIKA\n");  
  
} 
void main(int argc,char *argv[]) 
{ 
   help(); 
   glutInit(&argc,argv); 
   glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB); 
   glutInitWindowPosition(100,100); 
   glutInitWindowSize(LEBAR,TINGGI); 
   glutCreateWindow("ANIMASI SEPEDA 3D"); 
   init(); 
   glSetupFuncs(); 
   glutMainLoop(); 
}
