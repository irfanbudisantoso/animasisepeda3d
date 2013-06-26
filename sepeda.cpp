#include "sepeda.h" 
void updateScene() 
{ 
   GLfloat xDelta, zDelta; 
   GLfloat rotation; 
   GLfloat sin_stir, cos_stir; 
   if (-PLUS_SPID < spid && spid < PLUS_SPID) return; 

   if(spid < 0.0f) 
         sudutpedal = spid = 0.0f; 

   xDelta = spid*cos(radians(direction + stir)); 
   zDelta = spid*sin(radians(direction + stir)); 
   xpos += xDelta; 
   zpos -= zDelta; 
   sudutpedal = degrees(angleSum(radians(sudutpedal), spid/DMT_RODA)); 
   sin_stir = sin(radians(stir)); 
   cos_stir = cos(radians(stir)); 
   rotation = atan2(spid * sin_stir, PJG_SPD + spid * cos_stir); 
   direction = degrees(angleSum(radians(direction),rotation)); 
} 
GLfloat Abs(GLfloat a) 
{ 
   if(a < 0.0f) 
      return -a; 
   else 
      return a; 
} 
GLfloat degrees(GLfloat a) 
{ 
   return a*180.0f/PI; 
} 
GLfloat radians(GLfloat a) 
{ 
   return a*PI/180.0f; 
} 

void tutuplas() 
{ 
   glPushMatrix(); 
   glColor3f(1.0f,0.0f,0.0f); 
glScalef(0.025f,0.025f,0.025f); 
glRotatef(90.0f,0.0f,90.0f,0.0f); 
glutSolidSphere(2.0, 2.0, 100.0);
   glPopMatrix(); 
} 
void rantai() 
{ 
   GLfloat depth; 
   static int mode=0; 

   glColor3f(0.0f,1.0f,0.0f); 
   glEnable(GL_LINE_STIPPLE); 
   mode=(mode+1)%2; 
    
   if(mode==0 && spid>0) 
      glLineStipple(1,0x1c47); 
   else if(mode==1 && spid>0) 
      glLineStipple(1,0x00FF); 
    
   glBegin(GL_LINES); 
   for(depth=0.06f;depth<=0.12f;depth+=0.01f) 
   { 
      glVertex3f(-1.6f,0.15f,DMT_ROD); 
      glVertex3f(0.0f,0.3f,depth); 
       
      glVertex3f(-1.6f,-0.15f,DMT_ROD); 
      glVertex3f(0.0f,-0.3f,depth); 
   } 
   glEnd(); 
   glDisable(GL_LINE_STIPPLE); 
} 

void jok() 
{ 
   glBegin(GL_POLYGON); 
      glVertex3f(-0.1f, 1.0f, -0.5f); 
      glVertex3f(   1.0f, 1.0f, -0.3f); 
      glVertex3f( 1.0f, 1.0f,  0.3f); 
      glVertex3f(-0.1f, 1.0f,  0.5f); 
      glVertex3f(-0.5f, 1.0f,  1.0f); 
      glVertex3f(-1.0f, 1.0f,  1.0f); 
      glVertex3f(-1.0f, 1.0f, -1.0f); 
      glVertex3f(-0.5f, 1.0f, -1.0f); 
   glEnd(); 
   glBegin(GL_POLYGON); 
      glVertex3f(-0.1f, -1.0f, -0.5f); 
      glVertex3f(   1.0f, -1.0f, -0.3f); 
      glVertex3f( 1.0f, -1.0f,  0.3f); 
      glVertex3f(-0.1f, -1.0f,  0.5f); 
      glVertex3f(-0.5f, -1.0f,  1.0f); 
      glVertex3f(-1.0f, -1.0f,  1.0f); 
      glVertex3f(-1.0f, -1.0f, -1.0f); 
      glVertex3f(-0.5f, -1.0f, -1.0f); 
   glEnd(); 
   glBegin(GL_QUADS); 
      glVertex3f(1.0f,1.0f,-0.3f); 
      glVertex3f(1.0f,1.0f,0.3f); 
      glVertex3f(1.0f,-1.0f,0.3f); 
      glVertex3f(1.0f,-1.0f,-0.3f); 

      glVertex3f(1.0f,1.0f,0.3f); 
      glVertex3f(-0.1f,1.0f,0.5f); 
      glVertex3f(-0.1f,-1.0f,0.5f); 
      glVertex3f(1.0f,-1.0f,0.3f); 

      glVertex3f(1.0f,1.0f,-0.3f); 
      glVertex3f(-0.1f,1.0f,-0.5f); 
      glVertex3f(-0.1f,-1.0f,-0.5f); 
      glVertex3f(1.0f,-1.0f,-0.3f); 

      glVertex3f(-0.1f,1.0f,0.5f); 
      glVertex3f(-0.5f,1.0f,1.0f); 
      glVertex3f(-0.5f,-1.0f,1.0f); 
      glVertex3f(-0.1f,-1.0f,0.5f); 

      glVertex3f(-0.1f,1.0f,-0.5f); 
      glVertex3f(-0.5f,1.0f,-1.0f); 
      glVertex3f(-0.5f,-1.0f,-1.0f); 
      glVertex3f(-0.1f,-1.0f,-0.5f); 

      glVertex3f(-0.5f,1.0f,1.0f); 
      glVertex3f(-1.0f,1.0f,1.0f); 
      glVertex3f(-1.0f,-1.0f,1.0f); 
      glVertex3f(-0.5f,-1.0f,1.0f); 

      glVertex3f(-0.5f,1.0f,-1.0f); 
      glVertex3f(-1.0f,1.0f,-1.0f); 
      glVertex3f(-1.0f,-1.0f,-1.0f); 
      glVertex3f(-0.5f,-1.0f,-1.0f); 

      glVertex3f(-1.0f,1.0f,1.0f); 
      glVertex3f(-1.0f,1.0f,-1.0f); 
      glVertex3f(-1.0f,-1.0f,-1.0f); 
      glVertex3f(-1.0f,-1.0f,1.0f); 

   glEnd();
} 
void pedal() 
{ 
   glColor3f(0.0f,0.0f,1.0f); 
   glPushMatrix(); 
      glTranslatef(0.0f,0.0f,0.105f); 
      glRotatef(-sudutpedal,0.0f,0.0f,1.0f); 
      glTranslatef(0.25f,0.0f,0.0f); 
      glPushMatrix(); 
         glScalef(0.5f,0.1f,0.1f); 
         glutSolidCube(1.0f); 
      glPopMatrix(); 
      glPushMatrix(); 
         glTranslatef(0.25f,0.0f,0.15f); 
         glRotatef(sudutpedal,0.0f,0.0f,1.0f); 
         glScalef(0.2f,0.02f,0.3f); 
         glutSolidCube(1.0f); 
      glPopMatrix(); 

   glPopMatrix(); 
   glPushMatrix(); 
      glTranslatef(0.0f,0.0f,-0.23f); 
      glRotatef(180.0f-sudutpedal,0.0f,0.0f,1.0f); 
      glTranslatef(0.25f,0.0f,0.0f);  
      glPushMatrix(); 
         glScalef(0.5f,0.1f,0.1f); 
         glutSolidCube(1.0f); 
      glPopMatrix(); 
      glPushMatrix(); 
         glTranslatef(0.25f,0.0f,-0.15f); 
         glRotatef(sudutpedal-180.0f,0.0f,0.0f,1.0f); 
         glScalef(0.2f,0.02f,0.3f); 
         glutSolidCube(1.0f); 
      glPopMatrix(); 

   glPopMatrix(); 

   glColor3f(1.0f,0.0f,0.0f); 
} 
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
void ban(void) 
{ 
   int i; 
   //   Pelek 
   glColor3f(0.5f,1.0f,1.0f); 
   glutSolidTorus(0.06f,0.92f,4,30); 
   //   Silinder tengah
   glColor3f(1.0f,1.0f,0.5f); 
   glPushMatrix(); 
      glTranslatef(0.0f,0.0f,-0.06f); 
      Silinder1(0.02f,0.12f); 
   glPopMatrix(); 
   glutSolidTorus(0.02f,0.02f,3,20); 

   //   Jari Jari 
   glColor3f(1.0f,1.0f,1.0f); 
   for(i=0;i<JML_JARI2;++i) 
   { 
      glPushMatrix(); 
         glRotatef(i*SUDUT_JARI2,0.0f,0.0f,1.0f); 
         glBegin(GL_LINES); 
            glVertex3f(0.0f,0.02f,0.0f); 
            glVertex3f(0.0f,0.86f,0.0f); 
         glEnd(); 
      glPopMatrix(); 
   } 

   //   BAN 
   glColor3f(0.0f,0.0f,0.5f); 
   glutSolidTorus(LB_BAN-0.03,DMT_RODA,10,30); 
   glColor3f(1.0f,0.0f,0.0f); 
} 

void rangka() 
{ 
   glColor3f(1.0f,0.0f,0.0f); 
   glPushMatrix();  
      glPushMatrix(); 
         glColor3f(0.0f,1.0f,0.0f); 
         glPushMatrix(); 
            glTranslatef(0.0f,0.0f,0.06f); 
            glRotatef(-2*sudutpedal,0.0f,0.0f,1.0f); 
            gear(0.08f,0.3f,0.03f,30,0.03f); 
         glPopMatrix(); 
         glColor3f(1.0f,0.0f,0.0f); //warna rumah 
         glTranslatef(0.0f,0.0f,-0.2f); 
         Silinder1(0.08f,0.32f); 
      glPopMatrix(); 
//sambungan  fork belakang edit lagi 
	  glPushMatrix(); 
	 glColor3f(1.0f,0.0f,0.0f);
         glTranslatef(-0.87f,0.85f,-0.16f); 
         Silinder1(0.05f,0.32f); 
      glPopMatrix();
//TUTUP LAS SAMBUNGAN belakang kanan
glPushMatrix();
glTranslatef(-0.87f, 0.85f, 0.16f);
tutuplas();
glPopMatrix();

//TUTUP LAS SAMBUNGAN belakang kiri
glPushMatrix();
glTranslatef(-0.87f, 0.85f, -0.16f);
tutuplas();
glPopMatrix();
//rekaan sambungan  fork belakang tengah 
glPushMatrix(); 
glColor3f(1.0f,0.0f,0.0f); 
glTranslatef(-0.475f,0.0f,-0.16f); 
Silinder1(0.05f,0.32f); 
glPopMatrix();
//TUTUP LAS fork belakang tengah  kanan
glPushMatrix();
glTranslatef(-0.475f,0.0f,-0.16f);
tutuplas();
glPopMatrix();
//TUTUP LAS fork belakang tengah  kiri
	  glPushMatrix();
glTranslatef(-0.475f,0.0f,0.16f);
tutuplas();
glPopMatrix();
//TUTUP LAS dekat pedal kiri
	  glPushMatrix();
glTranslatef(0.0f,0.0f,-0.2f);
glScalef(0.04f,0.04f,0.04f); 
glRotatef(90.0f,0.0f,90.0f,0.0f); 
glutSolidSphere(2.0, 2.0, 100.0);
glPopMatrix();
//TUTUP LAS dekat pedal kanan
	  glPushMatrix();
glTranslatef(0.0f,0.0f,0.1f);
glScalef(0.04f,0.04f,0.04f); 
glRotatef(90.0f,0.0f,90.0f,0.0f); 
glutSolidSphere(2.0, 2.0, 100.0);
glPopMatrix();
glRotatef(SUDUT_KANAN,0.0f,0.0f,1.0f); 
Silinder2(DMT_ROD,1.67f); //rangka ubahan
glRotatef(SUDUT_TENGAH-SUDUT_KANAN,0.0f,0.0f,1.0f); 
Silinder2(DMT_ROD,TENGAH_ROD); 
      glColor3f(1.0f,1.0f,0.0f); 
      glTranslatef(TENGAH_ROD,0.0f,0.0f); 
      glRotatef(-SUDUT_TENGAH,0.0f,0.0f,1.0f); 
      glScalef(0.3f,DMT_ROD,0.25f); 
      jok(); 
      glColor3f(1.0f,0.0f,0.0f); 
   glPopMatrix(); 
   glPushMatrix(); 
      glRotatef(-180.0f,0.0f,1.0f,0.0f); 
      Silinder2(DMT_ROD,PHB_B); 
      glPushMatrix(); 
         glTranslatef(0.5f,0.0f,OFSET_RODA); 
         Silinder2(DMT_ROD,DMT_RODA+LB_BAN); 
      glPopMatrix(); 
      glPushMatrix(); 
         glTranslatef(0.5f,0.0f,-OFSET_RODA); 
         Silinder2(DMT_ROD,DMT_RODA+LB_BAN); 
      glPopMatrix(); 
   glPopMatrix(); 
   glPushMatrix(); 
      glTranslatef(-(PHB_B+DMT_RODA+LB_BAN),0.0f,0.0f); 
      glPushMatrix(); 
         glRotatef(-2*sudutpedal,0.0f,0.0f,1.0f); 
         ban(); 
         glColor3f(0.0f,1.0f,0.0f); 
            gear(0.03f,0.15f,0.03f,20,0.03f); 
         glColor3f(1.0f,0.0f,0.0f); 
      glPopMatrix(); 
      glRotatef(SUDUT_KIRI,0.0f,0.0f,1.0f); 
      glPushMatrix(); 
         glTranslatef(0.0f,0.0f,-OFSET_RODA); 
         Silinder2(DMT_ROD,LEN_RODA); 
      glPopMatrix(); 
      glPushMatrix(); 
         glTranslatef(0.0f,0.0f,OFSET_RODA); 
         Silinder2(DMT_ROD,LEN_RODA); 
      glPopMatrix(); 
      glTranslatef(LEN_RODA,0.0f,0.0f); 
      Silinder2(DMT_ROD,ENGSEL_ROD); 
       glTranslatef(ENGSEL_ROD,0.0f,0.0f); 
      glRotatef(-SUDUT_KIRI,0.0f,0.0f,1.0f); 
      Silinder2(DMT_ROD,LEN_ATAS); 
      glTranslatef(LEN_ATAS,0.0f,0.0f); 
      glRotatef(-FRONT_INCLINE,0.0f,0.0f,1.0f); 
      glPushMatrix(); 
         glTranslatef(-0.1f,0.0f,0.0f); 
         Silinder2(DMT_ROD,0.45f); 
      glPopMatrix(); 
      glPushMatrix(); 
         glRotatef(-stir,1.0f,0.0f,0.0f); 
         glTranslatef(-0.3f,0.0f,0.0f); 
         glPushMatrix(); 
            glRotatef(FRONT_INCLINE,0.0f,0.0f,1.0f); 

            glPushMatrix(); 
               glTranslatef(0.0f,0.0f,-HANDEL_ROD/2); 
               Silinder1(DMT_ROD,HANDEL_ROD); 
            glPopMatrix(); 

            glPushMatrix(); 
               glColor3f(1.0f,1.0f,0.0f); 
               glTranslatef(0.0f,0.0f,-HANDEL_ROD/2); 
               Silinder1(0.07f,HANDEL_ROD/4); 
               glTranslatef(0.0f,0.0f,HANDEL_ROD*3/4); 
               Silinder1(0.07f,HANDEL_ROD/4); 
               glColor3f(1.0f,0.0f,0.0f); 
            glPopMatrix(); 
         glPopMatrix(); 
         glPushMatrix(); 
            Silinder2(DMT_ROD,ENGSEL_ROD); 
            glTranslatef(ENGSEL_ROD,0.0f,0.0f); 
            glRotatef(SUDUT_ENGSEL,0.0f,0.0f,1.0f); 
            glPushMatrix(); 
               glTranslatef(0.0f,0.0f,OFSET_RODA); 
               Silinder2(DMT_ROD,ENGSEL_RODS); 
            glPopMatrix(); 
            glPushMatrix(); 
               glTranslatef(0.0f,0.0f,-OFSET_RODA); 
               Silinder2(DMT_ROD,ENGSEL_RODS); 
            glPopMatrix();
//rekaan tutup fork depan
glPushMatrix(); 
glColor3f(1.0f,0.0f,0.0f); 
glTranslatef(0.0f,0.0f,-0.16f); 
Silinder1(0.05f,0.32f); 
glPopMatrix();
//TUTUP LAS SAMBUNGAN FORK KIRI
	  glPushMatrix();
glTranslatef(0.0f, 0.0f, -0.16f);
tutuplas();
glPopMatrix();
//TUTUP LAS SAMBUNGAN FORK KANAN
	  glPushMatrix();
glTranslatef(0.0f, 0.0f, 0.16f);
tutuplas();
glPopMatrix();

//tTUTUP LAS handle kiri
	  glPushMatrix();
glTranslatef(-0.7f,0.09f,0.6f);
glScalef(0.03f,0.04f,0.04f); 
glRotatef(90.0f,0.0f,90.0f,0.0f); 
glutSolidSphere(2.0, 2.0, 100.0);
glPopMatrix();
//TUTUP LAS handle kiri
	  glPushMatrix();
glTranslatef(-0.7f,0.09f,-0.6f);
glScalef(0.03f,0.04f,0.04f); 
glRotatef(90.0f,0.0f,90.0f,0.0f); 
glutSolidSphere(2.0, 2.0, 100.0);
glPopMatrix();
            glTranslatef(ENGSEL_RODS,0.0f,0.0f); 
            glRotatef(-2*sudutpedal,0.0f,0.0f,1.0f); 
            ban(); 

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
		  rantai(); 
         pedal();
      glPopMatrix(); 
   glPopMatrix(); 
   glMatrixMode(GL_MODELVIEW); 
   glLoadIdentity(); 
   gluLookAt(camx,camy,camz,  camx,0.0,0.0,  0.0,1.0,0.0); 
   glutSwapBuffers(); 
}
 void idle(void) 
{ 
   updateScene(); 
   glutPostRedisplay(); 
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
void keyboard(unsigned char key,int x,int y) 
{ 
   GLfloat r=0.0f; 

   switch(key) 
   { 
      case 'r': 
         reset(); 
         break; 
      case 'a': 
         if(stir < BTS_HENDEL) 
               stir += PLUS_STIR; 
         break; 
      case 'd': 
         if(stir > -BTS_HENDEL) 
            stir -= PLUS_STIR; 
         break; 
      case '+': 
         spid += PLUS_SPID; 
         break; 
      case '-': 
         spid -= PLUS_SPID; 
         break;    
      case 27: 
         exit(1); 
   } 
    
   sudutpedal += spid; 
   if(spid < 0.0f) 
      spid = 0.0f; 
   if(sudutpedal < 0.0f) 
      sudutpedal = 0.0f; 
   if(sudutpedal >= 360.0f) 
      sudutpedal -= 360.0f; 

   glutPostRedisplay(); 
} 
void mouse(int button,int state,int x,int y) 
{ 
   switch(button) 
   { 
      case GLUT_LEFT_BUTTON: 
         if(state==GLUT_DOWN) 
         { 
            Mouse=GLUT_DOWN; 
            prevx=x; 
            prevy=y; 
         } 
         if(state==GLUT_UP) 
         { 
            Mouse=GLUT_UP; 
         } 
         break; 
      case GLUT_RIGHT_BUTTON: 
         break; 
   } 
   glutPostRedisplay(); 
} 

void passive(int x,int y) 
{ 
} 

void gerak(int x,int y) 
{ 
   if(Mouse==GLUT_DOWN)    
   { 
      int deltax,deltay; 
      deltax=prevx-x; 
      deltay=prevy-y; 
      anglex += 0.5*deltax; 
      angley += 0.5*deltay; 
      if(deltax!=0 && deltay!=0) 
         anglez += 0.5*sqrt(deltax*deltax + deltay*deltay); 

      if(anglex < 0) 
         anglex+=360.0; 
      if(angley < 0) 
         angley+=360.0; 
      if(anglez < 0) 
         anglez += 360.0; 

      if(anglex > 360.0) 
         anglex-=360.0; 
      if(angley > 360.0) 
         angley-=360.0; 
      if(anglez > 360.0) 
         anglez-=360.0; 
   } 
   else 
   { 
      Mouse=GLUT_UP; 
   } 
   prevx=x; 
   prevy=y; 
   glutPostRedisplay();    
} 
void glSetupFuncs(void) 
{ 
   glutDisplayFunc(display); 
   glutReshapeFunc(reshape); 
   glutIdleFunc(idle); 
   glutSpecialFunc(special); 
   glutKeyboardFunc(keyboard); 
   glutMouseFunc(mouse); 
   glutMotionFunc(gerak); 
   glutPassiveMotionFunc(passive); 
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
