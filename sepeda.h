#include<GL/glut.h> 
#include <GL/glu.h>
#include<stdio.h> 
#include<stdlib.h> 
#include<math.h>
#define ENGSEL_ROD      0.7f 
#define ENGSEL_RODS      1.12f 
#define SUDUT_ENGSEL      8.0f 
#define PI           3.14159 
#define LEBAR      600 
#define TINGGI     600    
#define PJG_SPD   3.3f 
#define DMT_ROD     0.05f 
#define JML_JARI2      20 
#define SUDUT_JARI2      18 
#define DMT_RODA   1.0f 
#define LB_BAN      0.08f 
#define KANAN_ROD      1.6f  //
#define SUDUT_KANAN      48.0f 
#define TENGAH_ROD      1.7f 
#define SUDUT_TENGAH   106.0f 
#define PHB_B   0.5f 
#define SUDUT_KIRI      50.0f 
#define OFSET_RODA   0.11f 
#define LEN_RODA      1.1f 
#define LEN_ATAS         1.5f 
#define HANDEL_ROD      1.2f 
#define FRONT_INCLINE   70.0f  //
#define BTS_HENDEL   70.0f 
#define PLUS_STIR   2.0f 
#define PLUS_SPID      0.05f 
   
GLfloat sudutpedal, spid, stir; 
GLfloat camx,camy,camz; 
GLfloat anglex,angley,anglez; 
 
int prevx,prevy; 
GLenum Mouse; 
 
GLfloat Abs(GLfloat); 
GLfloat degrees(GLfloat); 
GLfloat radians(GLfloat); 
GLfloat angleSum(GLfloat, GLfloat);
GLfloat xpos,zpos,direction; 

void init(void); 
void display(void); 
void reshape(int w,int h); 
void glSetupFuncs(void);
void reset(void);
void gear( GLfloat inner_radius, GLfloat outer_radius, GLfloat width,GLint teeth, GLfloat tooth_depth ); 
void silinder1(GLfloat radius,GLfloat length); 
void silinder2(GLfloat radius,GLfloat length); 
void help(void); 
void pedal(void);  
void jok(void);
void rantai(void);

