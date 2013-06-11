#include "sepeda.h" 
GLfloat angleSum(GLfloat a, GLfloat b) 
{ 
  a += b; 
  if (a < 0) return a+2*PI; 
  else if (a > 2*PI) return a-2*PI; 
  else return a; 
} 
void Silinder1(GLfloat radius,GLfloat length) 
{ 
   GLUquadricObj *cylinder; 
   cylinder=gluNewQuadric(); 
   glPushMatrix();    
      glTranslatef(0.0f,0.0f,0.0f); 
      gluCylinder(cylinder,radius,radius,length,15,5); 
   glPopMatrix(); 
} 
void Silinder2(GLfloat radius,GLfloat length) 
{ 
   glPushMatrix(); 
      glRotatef(90.0f,0.0f,1.0f,0.0f); 
      Silinder1(radius,length); 
   glPopMatrix(); 
} 
void rangka() 
{ 
   glColor3f(1.0f,0.0f,0.0f); 
   glPushMatrix();
   glPushMatrix(); 
   glColor3f(0.2f,0.7f,0.2f); 
   glPushMatrix(); 
            glTranslatef(0.0f,0.0f,0.06f); 
            glRotatef(-2*sudutpedal,0.0f,0.0f,1.0f); 
            gear(0.08f,0.3f,0.03f,30,0.03f); 
         glPopMatrix(); 
		 glColor3f(1.0f,0.0f,0.0f);  
         glTranslatef(0.0f,0.0f,-0.2f); 
         Silinder1(0.08f,0.32f); 
      glPopMatrix(); 
	    glPushMatrix(); 
         glTranslatef(0.0f,0.0f,-OFSET_RODA); 
         Silinder2(DMT_ROD,LEN_RODA); 
      glPopMatrix(); 
      glPopMatrix();   
   glPopMatrix(); 
} 
void gear( GLfloat inner_radius, GLfloat outer_radius, GLfloat width, 
        GLint teeth, GLfloat tooth_depth ) 
{ 
    GLint i; 
    GLfloat r0, r1, r2; 
    GLfloat angle, da; 
    GLfloat u, v, len; 
    const double pi = 3.14159264; 
    r0 = inner_radius; 
    r1 = outer_radius - tooth_depth/2.0; 
    r2 = outer_radius + tooth_depth/2.0; 
    da = 2.0*pi / teeth / 4.0; 
    glShadeModel( GL_FLAT ); 
    glNormal3f( 0.0, 0.0, 1.0 ); 
    glBegin( GL_QUAD_STRIP ); 
    for (i=0;i<=teeth;i++) { 
   angle = i * 2.0*pi / teeth; 
   glVertex3f( r0*cos(angle), r0*sin(angle), width*0.5 ); 
   glVertex3f( r1*cos(angle), r1*sin(angle), width*0.5 ); 
   glVertex3f( r0*cos(angle), r0*sin(angle), width*0.5 ); 
   glVertex3f( r1*cos(angle+3*da), r1*sin(angle+3*da), width*0.5 ); 
    } 
    glEnd(); 
    glBegin( GL_QUADS ); 
    da = 2.0*pi / teeth / 4.0; 
    for (i=0;i<teeth;i++) { 
   angle = i * 2.0*pi / teeth; 
   glVertex3f( r1*cos(angle),      r1*sin(angle),     width*0.5 ); 
   glVertex3f( r2*cos(angle+da),   r2*sin(angle+da),     width*0.5 ); 
   glVertex3f( r2*cos(angle+2*da), r2*sin(angle+2*da), width*0.5 ); 
   glVertex3f( r1*cos(angle+3*da), r1*sin(angle+3*da), width*0.5 ); 
    } 
    glEnd(); 
    glNormal3f( 0.0, 0.0, -1.0 ); 
    glBegin( GL_QUAD_STRIP ); 
    for (i=0;i<=teeth;i++) { 
   angle = i * 2.0*pi / teeth; 
   glVertex3f( r1*cos(angle), r1*sin(angle), -width*0.5 ); 
   glVertex3f( r0*cos(angle), r0*sin(angle), -width*0.5 ); 
   glVertex3f( r1*cos(angle+3*da), r1*sin(angle+3*da), -width*0.5 ); 
   glVertex3f( r0*cos(angle), r0*sin(angle), -width*0.5 ); 
    } 
    glEnd(); 
    glBegin( GL_QUADS ); 
    da = 2.0*pi / teeth / 4.0; 
    for (i=0;i<teeth;i++) { 
   angle = i * 2.0*pi / teeth; 
   glVertex3f( r1*cos(angle+3*da), r1*sin(angle+3*da), -width*0.5 ); 
   glVertex3f( r2*cos(angle+2*da), r2*sin(angle+2*da), -width*0.5 ); 
   glVertex3f( r2*cos(angle+da),   r2*sin(angle+da),     -width*0.5 ); 
   glVertex3f( r1*cos(angle),      r1*sin(angle),     -width*0.5 ); 
    } 
    glEnd(); 
    glBegin( GL_QUAD_STRIP ); 
    for (i=0;i<teeth;i++) { 
   angle = i * 2.0*pi / teeth; 
   glVertex3f( r1*cos(angle),      r1*sin(angle),      width*0.5 ); 
   glVertex3f( r1*cos(angle),      r1*sin(angle),     -width*0.5 ); 
   u = r2*cos(angle+da) - r1*cos(angle); 
   v = r2*sin(angle+da) - r1*sin(angle); 
   len = sqrt( u*u + v*v ); 
   u /= len; 
   v /= len; 
   glNormal3f( v, -u, 0.0 ); 
   glVertex3f( r2*cos(angle+da),   r2*sin(angle+da),      width*0.5 ); 
   glVertex3f( r2*cos(angle+da),   r2*sin(angle+da),     -width*0.5 ); 
   glNormal3f( cos(angle), sin(angle), 0.0 ); 
   glVertex3f( r2*cos(angle+2*da), r2*sin(angle+2*da),  width*0.5 ); 
   glVertex3f( r2*cos(angle+2*da), r2*sin(angle+2*da), -width*0.5 ); 
   u = r1*cos(angle+3*da) - r2*cos(angle+2*da); 
   v = r1*sin(angle+3*da) - r2*sin(angle+2*da); 
   glNormal3f( v, -u, 0.0 ); 
   glVertex3f( r1*cos(angle+3*da), r1*sin(angle+3*da),  width*0.5 ); 
   glVertex3f( r1*cos(angle+3*da), r1*sin(angle+3*da), -width*0.5 ); 
   glNormal3f( cos(angle), sin(angle), 0.0 ); 
    } 
    glVertex3f( r1*cos(0.0), r1*sin(0.0), width*0.5 ); 
    glVertex3f( r1*cos(0.0), r1*sin(0.0), -width*0.5 ); 
    glEnd(); 
    glShadeModel( GL_SMOOTH ); 
    glBegin( GL_QUAD_STRIP ); 
    for (i=0;i<=teeth;i++) { 
   angle = i * 2.0*pi / teeth; 
   glNormal3f( -cos(angle), -sin(angle), 0.0 ); 
   glVertex3f( r0*cos(angle), r0*sin(angle), -width*0.5 ); 
   glVertex3f( r0*cos(angle), r0*sin(angle), width*0.5 ); 
    } 
    glEnd(); 
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
//main CODE

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
