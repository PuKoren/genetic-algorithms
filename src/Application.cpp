#include "Application.h"

Application::Application(){
    eyeX = 0;
    eyeZ = 0;
    radius = 5;
    relativeX = 0;
    turnSpeed = 0.5f;
    zoomSpeed = 0.5f;
}

Application::~Application(){

}

void Application::Init(){
    glEnable(GL_DEPTH_TEST);
}

void Application::Zoom(int direction){
    radius += direction*zoomSpeed;
}

void Application::Input(unsigned char key, int x, int y){
    if(key == 119){

    }else if(key == 27){
        glutLeaveMainLoop();
    }
}

void Application::Draw(){
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    //modify object model view matrice to rotate with eyeX and eyeZ values
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(eyeX, 3, eyeZ, 0, 0, 0, 0, 1, 0);

    glutSwapBuffers();
}

void Application::Update(double deltaTime){
    relativeX += (((float)deltaTime*turnSpeed))*M_PI;

    eyeX = radius*sin(relativeX);
    eyeZ = radius*cos(relativeX);

    glutPostRedisplay();
}
