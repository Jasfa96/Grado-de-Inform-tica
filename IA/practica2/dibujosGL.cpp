 

#include "include/GL/glui.h"
#include <cstdlib>
#include <iostream>
#include "dibujosGL.h"
 

 using namespace std;

void drawCube(double x, double y, double z, double base, double alto)
{

    glShadeModel(GL_FLAT);
    //glColor3f(1.0f, 0.0f, 0.0f);
    glBegin(GL_QUADS);       //cara frontal
    glVertex3f( x-(base/2),  y,  z+(base/2));
    glVertex3f( x+(base/2),  y,  z+(base/2));
    glVertex3f( x+(base/2),  y+alto,  z+(base/2));
    glVertex3f( x-(base/2),  y+alto,  z+(base/2));
    glEnd();

    //glColor3f(1.0f, 1.0f, 1.0f);


    glBegin(GL_QUADS);       //cara trasera
    glVertex3f( x-(base/2),  y,  z-(base/2));
    glVertex3f( x+(base/2),  y,  z-(base/2));
    glVertex3f( x+(base/2),  y+alto,  z-(base/2));
    glVertex3f( x-(base/2),  y+alto,  z-(base/2));
    glEnd();

    //glColor3f(0.0f, 0.0f, 1.0f);
    glBegin(GL_QUADS);       //cara lateral izq
    glVertex3f( x-(base/2) ,y, z+(base/2));
    glVertex3f( x-(base/2) ,y, z-(base/2));
    glVertex3f( x-(base/2) ,y+alto, z-(base/2));
    glVertex3f( x-(base/2) ,y+alto, z+(base/2));
    glEnd();

    //glColor3f(1.0f, 1.0f, 0.0f);
    glBegin(GL_QUADS);       //cara lateral dcha
    glVertex3f( x+(base/2) ,y, z+(base/2));
    glVertex3f( x+(base/2) ,y, z-(base/2));
    glVertex3f( x+(base/2) ,y+alto, z-(base/2));
    glVertex3f( x+(base/2) ,y+alto, z+(base/2));
    glEnd(); 

    //glColor3f(0.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);       //cara arriba
    glVertex3f( x-(base/2), y+alto,  z+(base/2));
    glVertex3f( x-(base/2), y+alto,  z-(base/2));
    glVertex3f( x+(base/2), y+alto,  z-(base/2));
    glVertex3f( x+(base/2), y+alto,  z+(base/2));
    glEnd();
 
    //glColor3f(1.0f, 0.0f, 1.0f);
    glBegin(GL_QUADS);       //cara abajo
    glVertex3f( x-(base/2), y,  z+(base/2));
    glVertex3f( x-(base/2), y,  z-(base/2));
    glVertex3f( x+(base/2), y,  z-(base/2));
    glVertex3f( x+(base/2), y,  z+(base/2));
    glEnd();



    glColor3f(0,0,0);

    glBegin(GL_LINE_LOOP);       //cara frontal
    glVertex3f( x-(base/2),  y,  z+(base/2));
    glVertex3f( x+(base/2),  y,  z+(base/2));
    glVertex3f( x+(base/2),  y+alto,  z+(base/2));
    glVertex3f( x-(base/2),  y+alto,  z+(base/2));
    glEnd();

    //glColor3f(1.0f, 1.0f, 1.0f);


    // glBegin(GL_LINE_LOOP);       //cara trasera
    // glVertex3f( x-(base/2),  y,  z-(base/2));
    // glVertex3f( x+(base/2),  y,  z-(base/2));
    // glVertex3f( x+(base/2),  y+alto,  z-(base/2));
    // glVertex3f( x-(base/2),  y+alto,  z-(base/2));
    // glEnd();

    // //glColor3f(0.0f, 0.0f, 1.0f);
    glBegin(GL_LINE_LOOP);       //cara lateral izq
    glVertex3f( x-(base/2) ,y, z+(base/2));
    glVertex3f( x-(base/2) ,y, z-(base/2));
    glVertex3f( x-(base/2) ,y+alto, z-(base/2));
    glVertex3f( x-(base/2) ,y+alto, z+(base/2));
    glEnd();

    // //glColor3f(1.0f, 1.0f, 0.0f);
    glBegin(GL_LINE_LOOP);       //cara lateral dcha
    glVertex3f( x+(base/2) ,y, z+(base/2));
    glVertex3f( x+(base/2) ,y, z-(base/2));
    glVertex3f( x+(base/2) ,y+alto, z-(base/2));
    glVertex3f( x+(base/2) ,y+alto, z+(base/2));
    glEnd(); 

    // //glColor3f(0.0f, 1.0f, 1.0f);
    // glBegin(GL_LINE_LOOP);       //cara arriba
    // glVertex3f( x-(base/2), y+alto,  z+(base/2));
    // glVertex3f( x-(base/2), y+alto,  z-(base/2));
    // glVertex3f( x+(base/2), y+alto,  z-(base/2));
    // glVertex3f( x+(base/2), y+alto,  z+(base/2));
    // glEnd();
 
    // //glColor3f(1.0f, 0.0f, 1.0f);
    // glBegin(GL_LINE_LOOP);       //cara abajo
    // glVertex3f( x-(base/2), y,  z+(base/2));
    // glVertex3f( x-(base/2), y,  z-(base/2));
    // glVertex3f( x+(base/2), y,  z-(base/2));
    // glVertex3f( x+(base/2), y,  z+(base/2));
    // glEnd();


}


void drawTree(double x, double y, double z, double base, double alto)
{
  glColor3f(0,1,0);
  drawCube(x,y,z,base,0.1);
  glColor3f(0.4,0.15,0.15);
  drawCube(x,y,z,base/10,alto/2);
  glColor3f(0,1,0);
  drawCube(x,y+alto/2,z,base,alto/2);
}



void drawWall(double x, double y, double z, double base, double alto)
{
  glColor3f(0.45,0.25,0.13);
  drawCube(x,y,z,1,0.1);
  for (int i=0; i<10; i++){
      glColor3f(0.45,0.25,0.13);
      drawCube(x,y+0.1*i,z,1,0.1);
  }
}

void drawQuesitoDeFrente(double x, double y, double z){
      glColor3f(0,0,0);
      glBegin(GL_TRIANGLES);
      glVertex3f(x,    y+0.1, z+0.3);
      glVertex3f(x+0.3,y+0.1, z-0.3);
      glVertex3f(x-0.3,y+0.1, z-0.3);
      glEnd();

      glColor3f(1,0,0);
      glBegin(GL_TRIANGLES);
      glVertex3f(x,    y+0.2, z+0.3);
      glVertex3f(x+0.3,y+0.2, z-0.3);
      glVertex3f(x-0.3,y+0.2, z-0.3);
      glEnd();

      glBegin(GL_TRIANGLES);
      glVertex3f(x,    y+0.3, z+0.3);
      glVertex3f(x+0.3,y+0.3, z-0.3);
      glVertex3f(x-0.3,y+0.3, z-0.3);
      glEnd();


      glBegin(GL_QUADS);
      glVertex3f(x-0.3, y+0.3, z-0.3);
      glVertex3f(x-0.3, y+0.2, z-0.3);
      glVertex3f(x+0.3, y+0.2, z-0.3);
      glVertex3f(x+0.3, y+0.3, z-0.3);
      glEnd();

      glBegin(GL_QUADS);
      glVertex3f(x, y+0.3, z+0.3);
      glVertex3f(x, y+0.2, z+0.3);
      glVertex3f(x+0.3, y+0.2, z-0.3);
      glVertex3f(x+0.3, y+0.3, z-0.3);
      glEnd();

      glBegin(GL_QUADS);
      glVertex3f(x, y+0.3, z+0.3);
      glVertex3f(x, y+0.2, z+0.3);
      glVertex3f(x-0.3, y+0.2, z-0.3);
      glVertex3f(x-0.3, y+0.3, z-0.3);
      glEnd();



      // Perfilando los vertices
      glColor3f(0,0,0);
      // glBegin(GL_LINE_LOOP);
      // glVertex3f(x,    y+0.2, z+0.3);
      // glVertex3f(x+0.3,y+0.2, z-0.3);
      // glVertex3f(x-0.3,y+0.2, z-0.3);
      // glEnd();

      glBegin(GL_LINE_LOOP);
      glVertex3f(x,    y+0.3, z+0.3);
      glVertex3f(x+0.3,y+0.3, z-0.3);
      glVertex3f(x-0.3,y+0.3, z-0.3);
      glEnd();


      // glBegin(GL_LINE_LOOP);
      // glVertex3f(x-0.3, y+0.3, z-0.3);
      // glVertex3f(x-0.3, y+0.2, z-0.3);
      // glVertex3f(x+0.3, y+0.2, z-0.3);
      // glVertex3f(x+0.3, y+0.3, z-0.3);
      // glEnd();

      glBegin(GL_LINE_LOOP);
      glVertex3f(x, y+0.3, z+0.3);
      glVertex3f(x, y+0.2, z+0.3);
      glVertex3f(x+0.3, y+0.2, z-0.3);
      glVertex3f(x+0.3, y+0.3, z-0.3);
      glEnd();

      glBegin(GL_LINE_LOOP);
      glVertex3f(x, y+0.3, z+0.3);
      glVertex3f(x, y+0.2, z+0.3);
      glVertex3f(x-0.3, y+0.2, z-0.3);
      glVertex3f(x-0.3, y+0.3, z-0.3);
      glEnd();
}


void drawQuesitoDeEspaldas(double x, double y, double z){
      glColor3f(0,0,0);
      glBegin(GL_TRIANGLES);
      glVertex3f(x,    y+0.1, z-0.3);
      glVertex3f(x+0.3,y+0.1, z+0.3);
      glVertex3f(x-0.3,y+0.1, z+0.3);
      glEnd();

      glColor3f(1,0,0);
      glBegin(GL_TRIANGLES);
      glVertex3f(x,    y+0.2, z-0.3);
      glVertex3f(x+0.3,y+0.2, z+0.3);
      glVertex3f(x-0.3,y+0.2, z+0.3);
      glEnd();

      glBegin(GL_TRIANGLES);
      glVertex3f(x,    y+0.3, z-0.3);
      glVertex3f(x+0.3,y+0.3, z+0.3);
      glVertex3f(x-0.3,y+0.3, z+0.3);
      glEnd();


      glBegin(GL_QUADS);
      glVertex3f(x-0.3, y+0.3, z+0.3);
      glVertex3f(x-0.3, y+0.2, z+0.3);
      glVertex3f(x+0.3, y+0.2, z+0.3);
      glVertex3f(x+0.3, y+0.3, z+0.3);
      glEnd();

      glBegin(GL_QUADS);
      glVertex3f(x,     y+0.3, z-0.3);
      glVertex3f(x,     y+0.2, z-0.3);
      glVertex3f(x-0.3, y+0.2, z+0.3);
      glVertex3f(x-0.3, y+0.3, z+0.3);
      glEnd();

      glBegin(GL_QUADS);
      glVertex3f(x,     y+0.3, z-0.3);
      glVertex3f(x,     y+0.2, z-0.3);
      glVertex3f(x-0.3, y+0.2, z+0.3);
      glVertex3f(x-0.3, y+0.3, z+0.3);
      glEnd();



      // Perfilando los vertices
      glColor3f(0,0,0);
      // glBegin(GL_LINE_LOOP);
      // glVertex3f(x,    y+0.2, z-0.3);
      // glVertex3f(x+0.3,y+0.2, z+0.3);
      // glVertex3f(x-0.3,y+0.2, z+0.3);
      // glEnd();

      glBegin(GL_LINE_LOOP);
      glVertex3f(x,    y+0.3, z-0.3);
      glVertex3f(x+0.3,y+0.3, z+0.3);
      glVertex3f(x-0.3,y+0.3, z+0.3);
      glEnd();


      glBegin(GL_LINE_LOOP);
      glVertex3f(x-0.3, y+0.3, z+0.3);
      glVertex3f(x-0.3, y+0.2, z+0.3);
      glVertex3f(x+0.3, y+0.2, z+0.3);
      glVertex3f(x+0.3, y+0.3, z+0.3);
      glEnd();

      // glBegin(GL_LINE_LOOP);
      // glVertex3f(x,     y+0.3, z-0.3);
      // glVertex3f(x,     y+0.2, z-0.3);
      // glVertex3f(x-0.3, y+0.2, z+0.3);
      // glVertex3f(x-0.3, y+0.3, z+0.3);
      // glEnd();

      // glBegin(GL_LINE_LOOP);
      // glVertex3f(x,     y+0.3, z-0.3);
      // glVertex3f(x,     y+0.2, z-0.3);
      // glVertex3f(x-0.3, y+0.2, z+0.3);
      // glVertex3f(x-0.3, y+0.3, z+0.3);
      // glEnd();
}

void drawQuesitoDerecha(double x, double y, double z){
      glColor3f(0,0,0);
      glBegin(GL_TRIANGLES);
      glVertex3f(x-0.3, y+0.1, z+0.3);
      glVertex3f(x+0.3, y+0.1, z);
      glVertex3f(x-0.3, y+0.1, z-0.3);
      glEnd();

       glColor3f(1,0,0);
      glBegin(GL_TRIANGLES);
      glVertex3f(x-0.3, y+0.2, z+0.3);
      glVertex3f(x+0.3, y+0.2, z);
      glVertex3f(x-0.3, y+0.2, z-0.3);
      glEnd();

      glBegin(GL_TRIANGLES);
      glVertex3f(x-0.3, y+0.3, z+0.3);
      glVertex3f(x+0.3, y+0.3, z);
      glVertex3f(x-0.3, y+0.3, z-0.3);
      glEnd();


      glBegin(GL_QUADS);
      glVertex3f(x-0.3, y+0.3, z+0.3);
      glVertex3f(x-0.3, y+0.2, z+0.3);
      glVertex3f(x+0.3, y+0.2, z);
      glVertex3f(x+0.3, y+0.3, z);
      glEnd();

      glBegin(GL_QUADS);
      glVertex3f(x-0.3, y+0.3, z-0.3);
      glVertex3f(x-0.3, y+0.2, z-0.3);
      glVertex3f(x+0.3, y+0.2, z);
      glVertex3f(x+0.3, y+0.3, z);
      glEnd();

      glBegin(GL_QUADS);
      glVertex3f(x-0.3, y+0.3, z+0.3);
      glVertex3f(x-0.3, y+0.2, z+0.3);
      glVertex3f(x-0.3, y+0.2, z-0.3);
      glVertex3f(x-0.3, y+0.3, z-0.3);
      glEnd();



      // Perfilando los vertices
      glColor3f(0,0,0);

      glBegin(GL_LINE_LOOP);
      glVertex3f(x-0.3, y+0.3, z+0.3);
      glVertex3f(x-0.3, y+0.2, z+0.3);
      glVertex3f(x+0.3, y+0.2, z);
      glVertex3f(x+0.3, y+0.3, z);
      glEnd();

      glBegin(GL_LINE_LOOP);
      glVertex3f(x-0.3, y+0.3, z+0.3);
      glVertex3f(x-0.3, y+0.2, z+0.3);
      glVertex3f(x-0.3, y+0.2, z-0.3);
      glVertex3f(x-0.3, y+0.3, z-0.3);
      glEnd();
}



void drawQuesitoIzquierda(double x, double y, double z){
      glColor3f(0,0,0);
      glBegin(GL_TRIANGLES);
      glVertex3f(x+0.3, y+0.1, z+0.3);
      glVertex3f(x-0.3, y+0.1, z);
      glVertex3f(x+0.3, y+0.1, z-0.3);
      glEnd();

       glColor3f(1,0,0);
      glBegin(GL_TRIANGLES);
      glVertex3f(x+0.3, y+0.2, z+0.3);
      glVertex3f(x-0.3, y+0.2, z);
      glVertex3f(x+0.3, y+0.2, z-0.3);
      glEnd();

      glBegin(GL_TRIANGLES);
      glVertex3f(x+0.3, y+0.3, z+0.3);
      glVertex3f(x-0.3, y+0.3, z);
      glVertex3f(x+0.3, y+0.3, z-0.3);
      glEnd();


      glBegin(GL_QUADS);
      glVertex3f(x+0.3, y+0.3, z+0.3);
      glVertex3f(x+0.3, y+0.2, z+0.3);
      glVertex3f(x-0.3, y+0.2, z);
      glVertex3f(x-0.3, y+0.3, z);
      glEnd();

      glBegin(GL_QUADS);
      glVertex3f(x+0.3, y+0.3, z-0.3);
      glVertex3f(x+0.3, y+0.2, z-0.3);
      glVertex3f(x-0.3, y+0.2, z);
      glVertex3f(x-0.3, y+0.3, z);
      glEnd();

      glBegin(GL_QUADS);
      glVertex3f(x+0.3, y+0.3, z+0.3);
      glVertex3f(x+0.3, y+0.2, z+0.3);
      glVertex3f(x+0.3, y+0.2, z-0.3);
      glVertex3f(x+0.3, y+0.3, z-0.3);
      glEnd();



      // Perfilando los vertices
      glColor3f(0,0,0);
      glBegin(GL_LINE_LOOP);
      glVertex3f(x+0.3, y+0.3, z+0.3);
      glVertex3f(x+0.3, y+0.2, z+0.3);
      glVertex3f(x-0.3, y+0.2, z);
      glVertex3f(x-0.3, y+0.3, z);
      glEnd();


      glBegin(GL_LINE_LOOP);
      glVertex3f(x+0.3, y+0.3, z+0.3);
      glVertex3f(x+0.3, y+0.2, z+0.3);
      glVertex3f(x+0.3, y+0.2, z-0.3);
      glVertex3f(x+0.3, y+0.3, z-0.3);
      glEnd();

}


void drawPersonaje(double x, double y, double z, bool deCara, int colorPelo, int colorCamisa, int colorPantalon){
  //Sombra
  glColor3f(0,0,0);
  drawCube(x,y+0.1,z,0.25,0);

  // Cabeza
  switch (colorPelo){
    case 0: // Negro
            glColor3f(0,0,0);
            break;
    case 1: // Blanco
            glColor3f(1,1,1);
            break;
    case 2: // Rubio
            glColor3f(0.95,0.66,0);
            break;
    case 3: // Pelirrojo
            glColor3f(0.68,0.17,0.12);
            break;
    case 4: // Azul
            glColor3f(0.01,0.22,0.44);
            break;
    case 5: // Rosa
            glColor3f(0.85,0.3,0.54);
            break;
  }
  drawCube(x,y+0.5,z,0.14,0.14);



  // Cara
  if (deCara){
    glColor3f(0.65,0.37,0.18);
    drawCube(x,y+0.47,z,0.14,0.14);
    // Ojo izquierdo
    glColor3f(0,0,0);
    glBegin(GL_QUADS);
      glVertex3f(x-0.03,y+0.57,z+0.08);
      glVertex3f(x-0.03,y+0.58,z+0.08);
      glVertex3f(x-0.02,y+0.58,z+0.08);
      glVertex3f(x-0.02,y+0.57,z+0.08);
    glEnd();

    // Ojo derecho
    glColor3f(0,0,0);
    glBegin(GL_QUADS);
      glVertex3f(x+0.03,y+0.57,z+0.08);
      glVertex3f(x+0.03,y+0.58,z+0.08);
      glVertex3f(x+0.02,y+0.58,z+0.08);
      glVertex3f(x+0.02,y+0.57,z+0.08);
    glEnd();

    // Boca
    glColor3f(0.63,0.14,0.11);
    glBegin(GL_QUADS);
      glVertex3f(x+0.03,y+0.53,z+0.08);
      glVertex3f(x+0.03,y+0.54,z+0.08);
      glVertex3f(x-0.03,y+0.54,z+0.08);
      glVertex3f(x-0.03,y+0.53,z+0.08);
    glEnd();
  }


  switch (colorCamisa){
    case 0: // Negro
            // Pecho
            glColor3f(0,0,0);
            drawCube(x,y+0.35,z,0.16,0.15);
            // Brazo izquierdo
            glColor3f(0,0,0);
            drawCube(x-0.1,y+0.35,z,0.05,0.15);
            // Brazo derecho
            glColor3f(0,0,0);
            drawCube(x+0.1,y+0.35,z,0.05,0.15);
            break;
    case 1: // Blanco
            // Pecho
            glColor3f(1,1,1);
            drawCube(x,y+0.35,z,0.16,0.15);
            // Brazo izquierdo
            glColor3f(1,1,1);
            drawCube(x-0.1,y+0.35,z,0.05,0.15);
            // Brazo derecho
            glColor3f(1,1,1);
            drawCube(x+0.1,y+0.35,z,0.05,0.15);
            break;
    case 2: // Rubio
            // Pecho
            glColor3f(0.95,0.66,0);
            drawCube(x,y+0.35,z,0.16,0.15);
            // Brazo izquierdo
            glColor3f(0.95,0.66,0);
            drawCube(x-0.1,y+0.35,z,0.05,0.15);
            // Brazo derecho
            glColor3f(0.95,0.66,0);
            drawCube(x+0.1,y+0.35,z,0.05,0.15);
            break;
    case 3: // Pelirrojo
            // Pecho
            glColor3f(0.68,0.17,0.12);
            drawCube(x,y+0.35,z,0.16,0.15);
            // Brazo izquierdo
            glColor3f(0.68,0.17,0.12);
            drawCube(x-0.1,y+0.35,z,0.05,0.15);
            // Brazo derecho
            glColor3f(0.68,0.17,0.12);
            drawCube(x+0.1,y+0.35,z,0.05,0.15);
            break;
    case 4: // Azul
            // Pecho
            glColor3f(0.01,0.22,0.44);
            drawCube(x,y+0.35,z,0.16,0.15);
            // Brazo izquierdo
            glColor3f(0.01,0.22,0.44);
            drawCube(x-0.1,y+0.35,z,0.05,0.15);
            // Brazo derecho
            glColor3f(0.01,0.22,0.44);
            drawCube(x+0.1,y+0.35,z,0.05,0.15);
            break;
    case 5: // Rosa
            // Pecho
            glColor3f(0.85,0.3,0.54);
            drawCube(x,y+0.35,z,0.16,0.15);
            // Brazo izquierdo
            glColor3f(0.85,0.3,0.54);
            drawCube(x-0.1,y+0.35,z,0.05,0.15);
            // Brazo derecho
            glColor3f(0.85,0.3,0.54);
            drawCube(x+0.1,y+0.35,z,0.05,0.15);
            break;
  }
  // Mano izquierda
  glColor3f(0.65,0.37,0.18);
  drawCube(x-0.1,y+0.30,z,0.045,0.05);  
  // Mano derecha
  glColor3f(0.65,0.37,0.18);
  drawCube(x+0.1,y+0.30,z,0.045,0.05);  

  switch(colorPantalon){
    case 0: // Negro
            // Cintura
            glColor3f(0,0,0);
            drawCube(x,y+0.25,z,0.16,0.1);
            // Pierna izquierda
            glColor3f(0,0,0);
            drawCube(x-0.045,y+0.11,z,0.08,0.15);
            // Pierna derecha
            glColor3f(0,0,0);
            drawCube(x+0.045,y+0.11,z,0.08,0.15);
            break;
    case 1: // Blanco
            // Cintura
            glColor3f(1,1,1);
            drawCube(x,y+0.25,z,0.16,0.1);
            // Pierna izquierda
            glColor3f(1,1,1);
            drawCube(x-0.045,y+0.11,z,0.08,0.15);
            // Pierna derecha
            glColor3f(1,1,1);
            drawCube(x+0.045,y+0.11,z,0.08,0.15);
            break;
    case 2: // Rubio
            // Cintura
            glColor3f(0.95,0.66,0);
            drawCube(x,y+0.25,z,0.16,0.1);
            // Pierna izquierda
            glColor3f(0.95,0.66,0);
            drawCube(x-0.045,y+0.11,z,0.08,0.15);
            // Pierna derecha
            glColor3f(0.95,0.66,0);
            drawCube(x+0.045,y+0.11,z,0.08,0.15);
            break;
    case 3: // Pelirrojo
            // Cintura
            glColor3f(0.68,0.17,0.12);
            drawCube(x,y+0.25,z,0.16,0.1);
            // Pierna izquierda
            glColor3f(0.68,0.17,0.12);
            drawCube(x-0.045,y+0.11,z,0.08,0.15);
            // Pierna derecha
            glColor3f(0.68,0.17,0.12);
            drawCube(x+0.045,y+0.11,z,0.08,0.15);
            break;    
    case 4: // Azul vaquero
            // Cintura
            glColor3f(0.01,0.22,0.44);
            drawCube(x,y+0.25,z,0.16,0.1);
            // Pierna izquierda
            glColor3f(0.01,0.22,0.44);
            drawCube(x-0.045,y+0.11,z,0.08,0.15);
            // Pierna derecha
            glColor3f(0.01,0.22,0.44);
            drawCube(x+0.045,y+0.11,z,0.08,0.15);
            break;    
    case 5: // Rosa
            // Cintura
            glColor3f(0.85,0.3,0.54);
            drawCube(x,y+0.25,z,0.16,0.1);
            // Pierna izquierda
            glColor3f(0.85,0.3,0.54);
            drawCube(x-0.045,y+0.11,z,0.08,0.15);
            // Pierna derecha
            glColor3f(0.85,0.3,0.54);
            drawCube(x+0.045,y+0.11,z,0.08,0.15);
            break;    
  }
  // Pie izquierdo
  glColor3f(0.15,0.15,0.15);
  drawCube(x-0.045,y+0.1,z,0.08,0.01);
  // Pie derecho
  glColor3f(0.15,0.15,0.15);
  drawCube(x+0.045,y+0.1,z,0.08,0.01);

}


void drawDog(double x, double y, double z){
  // sombra


  glColor3f(0,0,0);
  drawCube(x, y+0.1, z, 0.5, 0.0);

  // tronco
  glColor3f(0.76,0.68,0.47);
  drawCube(x, y+0.25, z-0.45, 0.30, 0.15);

  glColor3f(0.76,0.68,0.47);
  drawCube(x, y+0.25, z-0.15, 0.30, 0.15);

  glColor3f(0.76,0.68,0.47);
  drawCube(x, y+0.25, z+0.15, 0.30, 0.15);



  // patas

  glColor3f(0.76,0.68,0.47);
  drawCube(x-0.10, y+0.1, z-0.55, 0.1, 0.15);

  glColor3f(0.76,0.68,0.47);
  drawCube(x+0.10, y+0.1, z-0.55, 0.1, 0.15);

  glColor3f(0.76,0.68,0.47);
  drawCube(x-0.10, y+0.1, z+0.25, 0.1, 0.15);

  glColor3f(0.76,0.68,0.47);
  drawCube(x+0.10, y+0.1, z+0.25, 0.1, 0.15);

  // cabeza

  glColor3f(0.76,0.68,0.47);
  drawCube(x, y+0.4, z+0.25, 0.15, 0.15);

    // Ojo izquierdo
    glColor3f(0,0,0);
    glBegin(GL_QUADS);
      glVertex3f(x-0.03,y+0.50,z+0.05);
      glVertex3f(x-0.03,y+0.52,z+0.05);
      glVertex3f(x-0.02,y+0.52,z+0.05);
      glVertex3f(x-0.02,y+0.50,z+0.05);
    glEnd();

    // Ojo derecho
    glColor3f(0,0,0);
    glBegin(GL_QUADS);
      glVertex3f(x+0.03,y+0.50,z+0.05);
      glVertex3f(x+0.03,y+0.52,z+0.05);
      glVertex3f(x+0.02,y+0.52,z+0.05);
      glVertex3f(x+0.02,y+0.50,z+0.05);
    glEnd();

  glColor3f(0,0,0);
  drawCube(x, y+0.42, z+0.32, 0.05, 0.05);



}




void drawPlayer(double x, double y, double z, char pos){
  switch(pos){
    case '0':
        drawQuesitoDeFrente(x,y,z);
        break;
    case '1':
        drawQuesitoDeEspaldas(x,y,z);
        break;
    case '2':
        drawQuesitoIzquierda(x,y,z);
        break;
    case '3':
        drawQuesitoDerecha(x,y,z);
        break;
  }
}

void drawGenericObject(double x, double y, double z){
  // Objeto generico
  glColor3f(0,0,0);
  drawCube(x,y+0.101,z,0.2,0);

  glColor3f(0.85,0.3,0.54); 
  drawCube(x,y+0.4, z,0.2,0.1);
}

