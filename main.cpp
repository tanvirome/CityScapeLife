#include<iostream>
using namespace std;
#include<cstdio>
#include <GL/gl.h>
#include <GL/glut.h>
#include <vector>
#include <cstdlib>
#include<windows.h>
#define PI 3.1416
#include<math.h>

GLboolean DayMode = true;
GLboolean NightMode = false;
GLboolean RainMode = false;
GLboolean TrafficLightGreen = true;
GLboolean TrafficLightRed = false;
GLboolean TrafficLightYellow = false;


GLbyte r = 99, g = 156, b = 177; ///building windows color
GLbyte r1 = 99, g1 = 156, b1 = 177; ///building windows color
GLbyte sr = 51, sg = 204, sb = 255; ///Sky color
GLbyte trr = 0, trg = 0, trb = 0; ///traffic Light red Color
GLbyte tyr = 0, tyg = 0, tyb = 0; ///traffic Light yellow Color
GLbyte tgr = 25, tgg = 255, tgb = 2; ///traffic Light green Color
GLbyte slr = 202, slg = 202, slb = 202; ///Street Light color


void PointLight(const float x, const float y, const float z, const float amb, const float diff, const float spec)
{
  glEnable(GL_LIGHTING);
  GLfloat light_ambient[] = { amb,amb,amb, 1.0 };
  GLfloat light_position[] = {-0.9,.9,0, 0.0 };
  glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
  glLightfv(GL_LIGHT0, GL_POSITION, light_position);
  glEnable(GL_LIGHT0); ///enable the light after setting the properties
}

void TrafficGreenLightColor()
{
    trr = 0, trg = 0, trb = 0; ///traffic Light red Color
    tyr = 0, tyg = 0, tyb = 0; ///traffic Light yellow Color
    tgr = 25, tgg = 255, tgb = 2; ///traffic Light green Color
}

void TrafficRedLightColor()
{
    trr = 226, trg = 0, trb = 0; ///traffic Light red Color
    tyr = 0, tyg = 0, tyb = 0; ///traffic Light yellow Color
    tgr = 0, tgg = 0, tgb = 0; ///traffic Light green Color
}

void TrafficYellowLightColor()
{
    trr = 0, trg = 0, trb = 0; ///traffic Light red Color
    tyr = 243, tyg = 255, tyb = 0; ///traffic Light yellow Color
    tgr = 0, tgg = 0, tgb = 0; ///traffic Light green Color
}

void DayColorChange()
{
    if(DayMode)
    {
        sr = 51, sg = 204, sb = 255; ///Sky Color
        slr = 202, slg = 202, slb = 202; ///Street Light Color
        r = 99, g = 156, b = 177;  ///Building Windows Color
        r1 = 99, g1 = 156, b1 = 177;  ///Building Windows Color
    }
}

void NightColorChange()
{
    if(NightMode)
    {
        sr = 0; sg = 51; sb = 204;  ///Sky Color
        slr = 255, slg = 249, slb = 69;  ///Street Light Color 255, 247, 0 255, 249, 69
        r = 201, g = 217, b = 0;  ///Building Windows Color
        r1 = 180, g1 = 186, b1 = 181;  ///Building Windows Color
    }
}

GLfloat HelicopterPositionX = 0.0f;
GLfloat HelicopterPositionY = 0.0f;
GLfloat HelicopterSpeed = 0.0011f;
GLboolean StopHeli = false;
int KeyH = 0;
void MoveHelicopter(int value)
{
    if(DayMode)
    {
        if(StopHeli == false)
        {
            if(HelicopterPositionY < 0.1f)
            {
                HelicopterPositionY += HelicopterSpeed;
            }
            else if(HelicopterPositionX < -1.3f)
            {
                HelicopterPositionX = 1.3f;
            }
            else
            {
                HelicopterPositionX -= HelicopterSpeed;
            }

            glutPostRedisplay();
            glutTimerFunc(23, MoveHelicopter, 0);
        }
    }
}


GLfloat Boat1PositionX = 0.0f;
GLfloat Boat1Speed = 0.003f;
GLboolean StopBoat1 = false;
int KeyB = 1;
void MoveBoat1(int value)
{
    if(StopBoat1 == false)
    {
        if(Boat1PositionX > 1.7f)
        {
            Boat1PositionX = -1.1f;
        }
        else
        {
            Boat1PositionX += Boat1Speed;
        }
        glutPostRedisplay();
        glutTimerFunc(27, MoveBoat1, 0);
    }
}


GLfloat Boat2PositionX = 0.0f;
GLfloat Boat2Speed = 0.004f;
GLboolean StopBoat2 = false;
int KeyV = 1;
void MoveBoat2(int value)
{
    if(StopBoat2 == false)
    {
        if(Boat2PositionX < -1.75f)
        {
            Boat2PositionX = 1.0f;
        }
        else
        {
            Boat2PositionX -= Boat2Speed;
        }
        glutPostRedisplay();
        glutTimerFunc(25, MoveBoat2, 0);
    }
}


GLfloat Cloud1PositionX = 0.0f;
GLfloat Cloud1Speed = 0.003f;
GLboolean StopCloud1 = false;
int KeyC = 1;
void MoveCloud1(int value)
{
    if(StopCloud1 == false)
    {
        if(Cloud1PositionX > 1.0f)
        {
            Cloud1PositionX = -1.6f;
        }
        else
        {
            Cloud1PositionX += Cloud1Speed;
        }
        glutPostRedisplay();
        glutTimerFunc(25, MoveCloud1, 0);
    }
}

GLfloat Cloud2PositionX = 0.0f;
GLfloat Cloud2Speed = 0.0033f;
GLboolean StopCloud2 = false;
int KeyX = 1;
void MoveCloud2(int value)
{
    if(StopCloud2 == false)
    {
        if(Cloud2PositionX > 1.7f)
        {
            Cloud2PositionX = -0.7f;
        }
        else
        {
            Cloud2PositionX += Cloud2Speed;
        }
        glutPostRedisplay();
        glutTimerFunc(22, MoveCloud2, 0);
    }
}


GLfloat TrainPositionX = 0.0f;
GLfloat TrainSpeed = 0.003f;
GLboolean MoveForward = false;
void MoveTrainForward(int value)
{
    if(MoveForward)
    {
        if(TrainPositionX > 2.0f)
        {
            TrainPositionX = -1.8f;
        }
        else
        {
            TrainPositionX += TrainSpeed;
        }
        glutPostRedisplay();
        glutTimerFunc(25, MoveTrainForward, 0);
    }
}

GLboolean MoveBackward = false;
void MoveTrainBackward(int value)
{
    if(MoveBackward)
    {
        if(TrainPositionX < -1.0f)
        {
            TrainPositionX = 1.99f;
        }
        else
        {
            TrainPositionX -= TrainSpeed;
        }
        glutPostRedisplay();
        glutTimerFunc(25, MoveTrainBackward, 0);
    }
}

GLfloat BirdPositionX = -0.5f;
GLfloat BirdPositionY = -0.2f;
GLfloat BirdSpeed = 0.005f;
GLboolean StopBird = false;
int KeyZ = 1;
void MoveBird(int value)
{
    if(StopBird == false)
    {
        if(BirdPositionY > .25f)
        {
            BirdPositionX = -0.5f;
            BirdPositionY = -0.2f;
        }
        else
        {
            BirdPositionX += BirdSpeed;
            BirdPositionY += (BirdSpeed/4);
        }
        glutPostRedisplay();
        glutTimerFunc(50, MoveBird, 0);
    }
}


GLfloat Car1PositionX = 0.0f;
GLfloat Car1Speed = 0.003f;
void MoveCar1(int value)
{
    if(TrafficLightGreen == true)
    {
        Car1Speed = 0.003f;
        if(Car1PositionX > 1.5f)
        {
            Car1PositionX = -0.9f;
        }
        else
        {
            Car1PositionX += Car1Speed;
        }
    }
    else if(TrafficLightRed == true)
    {
        if(Car1PositionX > 1.5f)
        {
            Car1PositionX = -0.9f;
        }
        if(Car1PositionX > 0.38f && Car1PositionX < 0.4f)
        {
            Car1Speed = 0.0f;
            Car1PositionX += Car1Speed;
        }
        else
        {
            Car1Speed = 0.003f;
            Car1PositionX += Car1Speed;
        }
    }
    else if(TrafficLightYellow == true)
    {
        if(Car1PositionX > 1.5f)
        {
            Car1PositionX = -0.9f;
        }
        if(Car1PositionX < 0.4 && Car1PositionX > 0.0f)
        {
            Car1Speed = 0.0005f;
            Car1PositionX += Car1Speed;
        }
        else
        {
            Car1Speed = 0.003f;
            Car1PositionX += Car1Speed;
        }
    }
    glutPostRedisplay();
    glutTimerFunc(25, MoveCar1, 0);
}


GLfloat Car2PositionX = 0.0f;
GLfloat Car2Speed = 0.004f;
void MoveCar2(int value)
{
    if(TrafficLightGreen == true)
    {
        Car2Speed = 0.004f;
        if(Car2PositionX > 1.3f)
        {
            Car2PositionX = -1.3f;
        }
        else
        {
            Car2PositionX += Car2Speed;
        }
    }
    else if(TrafficLightRed == true)
    {
        if(Car2PositionX > 1.3f)
        {
            Car2PositionX = -1.3f;
        }
        if(Car2PositionX > -0.02f && Car2PositionX < 0.0f)
        {
            Car2Speed = 0.0f;
            Car2PositionX += Car2Speed;
        }
        else
        {
            Car2Speed = 0.004f;
            Car2PositionX += Car2Speed;
        }
    }
    else if(TrafficLightYellow == true)
    {
        if(Car2PositionX > 1.3f)
        {
            Car2PositionX = -1.3f;
        }
        if(Car2PositionX < 0.0 && Car2PositionX > -0.12f)
        {
            Car2Speed = 0.0006f;
            Car2PositionX += Car2Speed;
        }
        else
        {
            Car2Speed = 0.004f;
            Car2PositionX += Car2Speed;
        }
    }
    glutPostRedisplay();
    glutTimerFunc(25, MoveCar2, 0);
}


GLfloat RainPositionY = 0.0f;
GLfloat RainSpeed = 0.0055f;
GLboolean StopRain = true;
int KeyE = 1;
void MoveRain(int value)
{
    if(StopRain == false)
    {
        if(RainPositionY < -1.0)
        {
            RainPositionY = 0.0f;
        }
        else
            RainPositionY -= RainSpeed;
        glutPostRedisplay();
        glutTimerFunc(15, MoveRain, 0);
    }
}

void DrawCircle(GLfloat x, GLfloat y, GLfloat radius, int triangleAmount)
{
    int i;
	GLfloat twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);       /// center of circle
    for(i = 0; i <= triangleAmount;i++)
        {
            glVertex2f(
                        x + (radius * cos(i *  twicePi / triangleAmount)),
                        y + (radius * sin(i * twicePi / triangleAmount)));
		}
	glEnd();
}

void DrawCircle1(GLfloat x, GLfloat y, GLfloat radius, int triangleAmount)
{
    int i;
	GLfloat twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);       /// center of circle
    for(i = 0; i <= triangleAmount/2;i++)
        {
            glVertex2f(
                       x + (radius * cos(i *  twicePi / triangleAmount)),
                       y + (radius * sin(i * twicePi / triangleAmount)));
		}
	glEnd();
}

void DrawCircle2(GLfloat x, GLfloat y, GLfloat radius, int triangleAmount)
{
    int i;
	GLfloat twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x, y);           /// center of circle
    for(i = 0; i <= triangleAmount/4;i++)
        {
            glVertex2f(
                       x + (radius * sin(i *  twicePi / triangleAmount)),
                       y + (radius * cos(i * twicePi / triangleAmount)));
		}
	glEnd();
}


void sky()
{
    glBegin(GL_QUADS);
    glColor3ub(sr, sg, sb);
	glVertex2f(-1.0f, 0.38f);
	glVertex2f(1.0f, 0.38f);
    glVertex2f(1.0f, 1.0f);
	glVertex2f(-1.0f, 1.0f);
    glEnd();
}

void cloud1()
{
	GLfloat x = 0.45f; GLfloat y = 0.83f; GLfloat radius = 0.05f;
	GLfloat x1 = 0.5f; GLfloat y1 = 0.8f;
	GLfloat x2 = 0.4f; GLfloat y2 = 0.8f;
	GLfloat x3 = 0.47f; GLfloat y3 = 0.77f;
	GLfloat x4 = 0.55f; GLfloat y4 = 0.79f;
	int triangleAmount = 20;

    glColor3ub(255, 217, 255);
    DrawCircle(x,y,radius,triangleAmount);
    DrawCircle(x1,y1,radius,triangleAmount);
    DrawCircle(x2,y2,radius,triangleAmount);
    DrawCircle(x3,y3,radius,triangleAmount);
    DrawCircle(x4,y4,radius,triangleAmount);
}

void cloud2()
{
	GLfloat x = -0.60f; GLfloat y = 0.91f; GLfloat radius = 0.05f;
    GLfloat x1 = -0.65f; GLfloat y1 = 0.88f;
	GLfloat x2 = -0.55f; GLfloat y2 = 0.88f;
	GLfloat x3 = -0.62f; GLfloat y3 = 0.85f;
	GLfloat x4 = -0.67f; GLfloat y4 = 0.87f;
	int triangleAmount = 20;



	glColor3ub(255, 217, 255);
    DrawCircle(x,y,radius,triangleAmount);
    DrawCircle(x1,y1,radius,triangleAmount);
    DrawCircle(x2,y2,radius,triangleAmount);
    DrawCircle(x3,y3,radius,triangleAmount);
    DrawCircle(x4,y4,radius,triangleAmount);
}

void stars()
{
    glPointSize( 2.5 );
    glBegin(GL_POINTS);
    glColor3ub(255, 255, 255);
    glVertex2f(0.8f,0.95f);
    glVertex2f(0.9f,0.9f);
    glVertex2f(0.95f,0.7f);
    glVertex2f(0.8f,0.8f);
    glVertex2f(0.7f,0.9f);
    glVertex2f(0.6f,0.8f);
    glVertex2f(0.5f,0.75f);
    glVertex2f(0.4f,0.9f);
    glVertex2f(0.3f,0.7f);
    glVertex2f(0.25f,0.9f);
    glVertex2f(0.25f,0.7f);
    glVertex2f(0.1f,0.9f);
    glVertex2f(0.15f,0.75f);
    glVertex2f(0.0f,0.8f);
    glVertex2f(-0.7f,0.9f);
    glVertex2f(-0.8f,0.95f);
    glVertex2f(-0.4f,0.8f);
    glVertex2f(-0.8f,0.95f);
    glVertex2f(-0.9f,0.9f);
    glVertex2f(-0.95f,0.7f);
    glVertex2f(-0.8f,0.8f);
    glVertex2f(-0.7f,0.9f);
    glVertex2f(-0.6f,0.8f);
    glVertex2f(-0.5f,0.75f);
    glVertex2f(-0.4f,0.9f);
    glVertex2f(-0.3f,0.7f);
    glVertex2f(-0.25f,0.9f);
    glVertex2f(-0.25f,0.7f);
    glVertex2f(-0.15f,0.75f);
    glVertex2f(-0.1f,0.9f);
    glEnd();

}

void sun()
{
    GLfloat x=0.3f; GLfloat y=0.9f; GLfloat radius =0.06f;
	int triangleAmount = 20;
    glColor3ub(255, 204, 0);
    DrawCircle(x,y,radius,triangleAmount);
}

void moon()
{
    GLfloat x=-0.436f; GLfloat y=0.9f; GLfloat radius =0.06f;
    GLfloat x1=-0.442f; GLfloat y1=0.915f; GLfloat radius1 =0.06f;
    int triangleAmount = 20;

    glColor3ub(242, 242, 242);
    DrawCircle(x,y,radius,triangleAmount);

    glColor3ub(0, 51, 204);
    DrawCircle(x1,y1,radius1,triangleAmount);
}

void bird3()
{
    int i;

    GLfloat radiusmmm = 0.01f;
	GLfloat mm=0.182f; GLfloat nn=.801f;
	GLfloat mmm=0.062f; GLfloat nnn=.801f;
	int triangleAmount = 20;
	GLfloat twicePi = 2.0f * PI;

	glBegin(GL_TRIANGLE_FAN);
    glColor3ub(225, 225, 208);
    glVertex2f(mm, nn);             /// center of circle
    for(i = 0; i <= triangleAmount;i++)
        {
            glVertex2f(
                       mm + (radiusmmm * cos(i *  twicePi / triangleAmount)),
                       nn + (radiusmmm * sin(i * twicePi / triangleAmount)));
		}
	glEnd();
    glBegin(GL_POLYGON);
    glColor3ub(225, 225, 208 );
    glVertex2f(0.1f,0.8f);
    glVertex2f(0.11f,0.79f);
    glVertex2f(0.12f,0.78f);
    glVertex2f(0.16f,0.77f);
    glVertex2f(0.19f,0.79f);
    glVertex2f(0.201f,0.8f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(217, 217, 217);
    glVertex2f(0.175f,0.8f);
    glVertex2f(0.15f,0.8f);
    glVertex2f(0.14f,0.84f);
    glEnd();


    glBegin(GL_TRIANGLES);
    glColor3ub(242, 242, 242 );
    glVertex2f(0.175f,0.8f);
    glVertex2f(0.144f,0.8f);
    glVertex2f(0.12f,0.83f);
    glEnd();

	///2nd bird///

	glBegin(GL_POLYGON);
    glColor3ub(225, 225, 208 );
    glVertex2f(-0.02f,0.8f);
    glVertex2f(-0.01f,0.79f);
    glVertex2f(0.0f,0.78f);
    glVertex2f(0.04f,0.77f);
    glVertex2f(0.07f,0.79f);
    glVertex2f(0.081f,0.8f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(217, 217, 217);
    glVertex2f(0.055f,0.8f);
    glVertex2f(0.03f,0.8f);
    glVertex2f(0.02f,0.84f);
    glEnd();


    glBegin(GL_TRIANGLES);
    glColor3ub(242, 242, 242 );
    glVertex2f(0.055f,0.8f);
    glVertex2f(0.024f,0.8f);
    glVertex2f(0.0f,0.83f);
    glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glColor3ub(225, 225, 208);
    glVertex2f(mmm, nnn);           /// center of circle
    for(i = 0; i <= triangleAmount;i++)
        {
            glVertex2f(
                       mmm + (radiusmmm * cos(i *  twicePi / triangleAmount)),
                       nnn + (radiusmmm * sin(i * twicePi / triangleAmount))
			);
		}
	glEnd();
}

void bird1()
{
	GLfloat x = -0.638f; GLfloat y= 0.801f;
	GLfloat radius = 0.01f;
	int triangleAmount = 20;

	glBegin(GL_POLYGON);
    glColor3ub(74, 74, 74);
    glVertex2f(-0.72f,0.8f);
    glVertex2f(-0.71f,0.79f);
    glVertex2f(-0.7f,0.78f);
    glVertex2f(-0.66f,0.77f);
    glVertex2f(-0.63f,0.79f);
    glVertex2f(-0.619f,0.8f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(74, 74, 74);
    glVertex2f(-0.645f,0.8f);
    glVertex2f(-0.67f,0.8f);
    glVertex2f(-0.68f,0.84f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(74, 74, 74);
    glVertex2f(-0.645f,0.8f);
    glVertex2f(-0.676f,0.8f);
    glVertex2f(-0.7f,0.83f);
    glEnd();

    glColor3ub(74, 74, 74);
    DrawCircle(x, y, radius, triangleAmount);
}

void bird2()
{
    GLfloat x= -0.518f; GLfloat y= 0.801f;
	GLfloat radius = 0.01f;
	int triangleAmount = 20;

    glBegin(GL_POLYGON);
    glColor3ub(74, 74, 74);
    glVertex2f(-0.6f,0.8f);
    glVertex2f(-0.59f,0.79f);
    glVertex2f(-0.58f,0.78f);
    glVertex2f(-0.54f,0.77f);
    glVertex2f(-0.51f,0.79f);
    glVertex2f(-0.499f,0.8f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3ub(74, 74, 74);
    glVertex2f(-0.525f,0.8f);
    glVertex2f(-0.55f,0.8f);
    glVertex2f(-0.56f,0.84f);
    glEnd();


    glBegin(GL_TRIANGLES);
    glColor3ub(74, 74, 74);
    glVertex2f(-0.525f,0.8f);
    glVertex2f(-0.556f,0.8f);
    glVertex2f(-0.58f,0.83f);
    glEnd();

    glColor3ub(74, 74, 74);
    DrawCircle(x, y, radius, triangleAmount);
}

void river()
{
    glBegin(GL_QUADS);
    glColor3ub(38, 154, 214);
	glVertex2f(-1.0f, -0.6276f);
	glVertex2f(-1.0f, -1.0f);
	glVertex2f( 1.0f, -1.0f);
    glVertex2f( 1.0f,-0.6276f);
    glEnd();
}

void riverBridge()
{
    ///wall///
    glBegin(GL_QUADS);
	glColor3ub(131, 74, 16);
	glVertex2f(-1.0f, -0.335f);
	glVertex2f(-1.0f, -0.6276f);
	glVertex2f( 1.0f, -0.6276f);
    glVertex2f( 1.0f,-0.335f);
    glEnd();

    GLfloat x=-0.5f, y= -0.6276f, radius =0.22f;
    int triangleAmount = 20;

    glColor3ub(135, 98, 61);
    DrawCircle1(x,y,radius,triangleAmount);

    glColor3ub(38, 154, 214);
    radius = 0.25f;
    y = -0.75f;
    DrawCircle1(x,y,radius,triangleAmount);

    x= 0.5f, y= -0.6276f, radius = 0.22f;

    glColor3ub(135, 98, 61);
    DrawCircle1(x,y,radius,triangleAmount);

    glColor3ub(38, 154, 214);
    radius = 0.25f;
    y = -0.75f;
    DrawCircle1(x,y,radius,triangleAmount);
}

void boat1()
{
    ///bottom part
    glBegin(GL_QUADS);
    glColor3ub(93,20,4);
	glVertex2f( -0.072f, -0.734f);
	glVertex2f( -0.392f, -0.734f);
	glVertex2f( -0.432f, -0.8005f);
	glVertex2f( -0.112f, -0.8005f);
	glEnd();
    glBegin(GL_QUADS);
    glColor3ub(132,47,29);
    glVertex2f( -0.752f, -0.8005f);
    glVertex2f( -0.672f, -0.9335f);
    glVertex2f( -0.192f,-0.9335f);
    glVertex2f( -0.112f, -0.8005f);
    glEnd();

    ///middle part
    glBegin(GL_POLYGON);
    glColor3ub(65,8,164);
	glVertex2f( -0.392f, -0.734f);
	glVertex2f( -0.352f, -0.734f);
	glVertex2f( -0.352f, -0.6542f);
	glVertex2f( -0.672f, -0.6542f);
	glVertex2f( -0.672f, -0.8005f);
	glVertex2f( -0.432f, -0.8005f);
	glEnd();

	///middle middle part
	glBegin(GL_QUADS);
	glColor3ub(247,245,237);
    glVertex2f( -0.56f, -0.77f);
    glVertex2f( -0.56f, -0.685f);
    glVertex2f( -0.66f, -0.685f);
    glVertex2f( -0.66f, -0.77f);
    glEnd();

    glBegin(GL_QUADS);
	glColor3ub(247,245,237);
    glVertex2f( -0.55f, -0.77f);
    glVertex2f( -0.55f, -0.685f);
    glVertex2f( -0.455f, -0.685f);
    glVertex2f( -0.455f, -0.77f);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(247,245,237);
	glVertex2f( -0.392f, -0.734f);
	glVertex2f( -0.368f, -0.734f);
	glVertex2f( -0.368f, -0.685f);
    glVertex2f( -0.445f, -0.685f);
	glVertex2f( -0.445f, -0.77f);
	glVertex2f( -0.416f, -0.77f);
	glEnd();

    glBegin(GL_QUADS);
	glColor3ub(0, 15, 252);
    glVertex2f( -0.352f, -0.6542f);
    glVertex2f( -0.368f, -0.601f);
    glVertex2f( -0.664f, -0.601f);
    glVertex2f( -0.664f, -0.6542f);
    glEnd();

    ///bottom line
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex2f(-0.408f, -0.7606f);
    glVertex2f(-0.088f, -0.7606f);

    glVertex2f(-0.712f, -0.867f);
    glVertex2f(-0.152f, -0.867f);
    glEnd();
}

void boat2()
{
    glBegin(GL_POLYGON);
    glColor3ub(209, 213, 208);
    glVertex2f(0.8f, -0.8803f);
    glVertex2f(0.8f, -0.8271f);
    glVertex2f(0.448f, -0.72f);
    glVertex2f(0.384f, -0.7739f);
    glVertex2f(0.448f, -0.8404f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(114, 218, 227);
    glVertex2f(0.648f, -0.78f);
    glVertex2f(0.665f, -0.69f);
    glVertex2f(0.504f, -0.681f);
    glVertex2f(0.48f, -0.73f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(247, 245, 237);
    glVertex2f(0.57f, -0.7569f);
    glVertex2f(0.58f, -0.7f);
    glVertex2f(0.515f, -0.6943f);
    glVertex2f(0.5f, -0.7358f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(247, 245, 237);
    glVertex2f(0.635f, -0.778f);
    glVertex2f(0.649f, -0.70f);
    glVertex2f(0.595f, -0.7f);
    glVertex2f(0.582f, -0.765f);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex2f(0.792f, -0.8803f);
    glVertex2f(0.792f, -0.8537f);


    glVertex2f(0.384f, -0.7739f);
    glVertex2f(0.792f, -0.8537f);

    glEnd();
}

void fence()
{
    GLfloat x1 = -0.944f,x2 = -0.944f,x3 = -1.0f,x4 = -1.0f,y1 = -0.335f,y2 = -0.2818f,y3 = -0.2818f,y4 = -0.335f;
    GLfloat x = 0.08f;


    for(int i =0; i<25; i++)
    {
        if(x1 <= 1.0)
        {
            glLineWidth(3);
            glColor3ub(77, 72, 72);
            glBegin(GL_LINE_LOOP);
            glVertex2f(x1,y1);
            glVertex2f(x2,y2);
            glVertex2f(x3,y3);
            glVertex2f(x4,y4);
            glEnd();

            x1 += x;
            x2 += x;
            x4 += x;
            x3 += x;
        }
        else
        {
            break;
        }
    }
}

void footpath1()
{
    GLfloat x1 = 1.0f,x2 = 1.0f,x3 = -1.0f,x4 = -1.0f,y1 = -0.2685f,y2 = -0.2286f,y3 = -0.2286f,y4 = -0.2685f;

    glBegin(GL_QUADS);
    glColor3ub(229,153,108);
    glVertex2f(x1,y1);
    glVertex2f(x2,y2);
    glVertex2f(x3,y3);
    glVertex2f(x4,y4);
    glEnd();


    glBegin(GL_QUADS);
    glColor3ub(229,153,108);
    glVertex2f( 1.0f, -0.335);
    glVertex2f( 1.0f, -0.2685f);
    glVertex2f(-1.0f, -0.2685f);
    glVertex2f(-1.0f, -0.335);
    glEnd();

    glLineWidth(1);
    glColor3ub(77, 72, 72);
    glBegin(GL_LINES);
    glVertex2f(x4,y4);
    glVertex2f(x1,y1);
    glEnd();
}

void footpath2()
{
    glBegin(GL_QUADS);
    glColor3ub(229,153,108);
    glVertex2f( 1.0f, 0.2261f);
    glVertex2f( 1.0f, 0.33f);
    glVertex2f(-1.0f, 0.33f);
    glVertex2f(-1.0f, 0.2261f);
    glEnd();
}

void road1()
{
    GLfloat x1 = -0.88f,x2 = -0.88f,x3 = -1.0f,x4 = -1.0f,y1 = -0.0291f,y2 = -0.0025f,y3 = -0.0025f,y4 = -0.0291f;
    GLfloat x = 0.2f;

    ///Road///
    glBegin(GL_QUADS);
    glColor3ub(100, 99, 97);
    glVertex2f( 1.0f,-0.2286f);
    glVertex2f( 1.0f, 0.2261f);
    glVertex2f(-1.0f, 0.2261f);
    glVertex2f(-1.0f,-0.2286f);
    glEnd();

    ///Divider Of Road
    for(int i =0; i<13; i++)
    {
        if(x1 <= 1.0)
        {
            glBegin(GL_QUADS);
            glColor3ub(225, 223, 221);
            glVertex2f(x1,y1);
            glVertex2f(x2,y2);
            glVertex2f(x3,y3);
            glVertex2f(x4,y4);
            glEnd();

            x1 += x;
            x2 += x;
            x4 += x;
            x3 += x;
        }
        else
        {
            break;
        }
    }

    glBegin(GL_QUADS);
    glColor3ub(100, 99, 97);
    glVertex2f(0.52f,y1);
    glVertex2f(0.52f,y2);
    glVertex2f(0.4f,y3);
    glVertex2f(0.4f,y4);
    glEnd();

    ///Zebra Crossing///
    x1 = 0.576f,x2 = 0.573f,x3 = 0.345f,x4 = 0.34f,y1 = -0.1995f,y2 = -0.1596f;
    GLfloat y = 0.0665f;
    GLfloat cx1 = 0.003f;
    GLfloat cx2 = 0.005f;

    for(int i =0; i<8; i++)
    {
        if(y2 <= 0.2261)
        {
            glBegin(GL_QUADS);
            glColor3ub(255, 255, 255);
            glVertex2f(x1,y1);
            glVertex2f(x2,y2);
            glVertex2f(x3,y2);
            glVertex2f(x4,y1);
            glEnd();

            x1 -= cx1;    y1 += y;
            x2 -= cx1;    y2 += y;
            x3 += cx2;    x4 += cx2;
        }
        else
        {
            break;
        }
    }

    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2f(0.558f,0.1995f);
    glVertex2f(0.555f,0.2258f);
    glVertex2f(0.375f,0.2258f);
    glVertex2f(0.370f,0.1995f);
    glEnd();
}

void helicopter()
{
    GLfloat x = 0.16f; GLfloat y = 0.67f; GLfloat radius = 0.038f;
	int triangleAmount = 20;


    glBegin(GL_QUADS);
    glColor3ub( 79, 96, 12 );
    glVertex2f((x+0.14f), (y+0.005f));
    glVertex2f((x+0.02f), (y+0.031f));
    glVertex2f((x+0.02f), (y-0.031f));
    glVertex2f((x+0.14f), (y-0.005f));
    glEnd();

    glColor3ub(180, 218, 240);
    DrawCircle(x,y,radius,triangleAmount);

    glBegin(GL_QUADS);
    glColor3ub(192, 185, 191);
    glVertex2f((x+0.14f), (y+0.02f));
    glVertex2f((x+0.14f), y);
    glVertex2f((x+0.16f), (y+0.005));
    glVertex2f((x+0.16f), (y+0.025f));
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(192, 185, 191);
    glVertex2f((x+0.14f), (y-0.02f));
    glVertex2f((x+0.14f), y);
    glVertex2f((x+0.16f), (y-0.005));
    glVertex2f((x+0.16f), (y-0.025f));
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex2f((x-0.038f), y);
    glVertex2f((x+0.038f), y);


    glVertex2f(x, y);
    glVertex2f(x, (y+0.049f));


    glVertex2f((x-0.058f), (y+0.049f));
    glVertex2f((x+0.058f), (y+0.049f));

    glVertex2f((x-0.04f), (y-0.058f));
    glVertex2f((x+0.04f), (y-0.058f));

    glVertex2f((x-0.015f), (y-0.058f));
    glVertex2f((x-0.015f), (y-0.038f));

    glVertex2f((x+0.015f), (y-0.058f));
    glVertex2f((x+0.015f), (y-0.038f));
    glEnd();
}


void TrainLine1()
{
    ///Train Line
    glLineWidth(2);
    glColor3ub(156, 154, 154);
    glBegin(GL_LINES);
    glVertex2f(-1.0f, 0.4414f);
    glVertex2f( 1.0f, 0.4414f);

    glVertex2f(-1.0f, 0.4614f);
    glVertex2f( 1.0f, 0.4614f);
    glEnd();


    ///shade
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);

    glVertex2f(-0.088f, 0.4614f);
    glVertex2f(-0.032f, 0.611f);
    glVertex2f(-0.312f, 0.611f);
    glVertex2f(-0.368f, 0.4614f);
    glEnd();


    glLineWidth(3);
    glColor3ub(0, 0, 0);
    glBegin(GL_LINES);
    glVertex2f(-0.176f, 0.611f);
    glVertex2f(-0.232f, 0.4614f);
    glEnd();

    glLineWidth(3);
    glColor3ub(0, 0, 0);
    glBegin(GL_LINES);
    glVertex2f(-0.312f, 0.611f);
    glVertex2f(-0.368f, 0.4614f);

    glVertex2f(-0.312f, 0.611f);
    glVertex2f(-0.032f, 0.611f);
    glEnd();


    ///Train Line
    GLfloat y1 = 0.4414f, y2 = 0.4614f;
    GLfloat x1 = -1.0f, x2 = -0.984f;
    GLfloat x = 0.032f;

    for(int i = 0; i<70; i++)
    {
        if(x2 <= 1)
        {
            glLineWidth(2);
            glColor3ub(156, 154, 154);
            glBegin(GL_LINES);
            glVertex2f( x1, y1);
            glVertex2f( x2, y2);
            glEnd();

            x1 += x;
            x2 += x;
        }
        else
        {
            break;
        }
    }
}

void train()
{
    ///Train
    glBegin(GL_QUADS);
    glColor3ub(255, 51, 51);
    glVertex2f(-0.76f, 0.4514f);
    glVertex2f(-0.76f, 0.5578f);
    glVertex2f(-0.936f, 0.5578f);
    glVertex2f(-1.0f, 0.4514f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 51, 51);
    glVertex2f(-0.584f, 0.4514f);
    glVertex2f(-0.584f, 0.5578f);
    glVertex2f(-0.744f, 0.5578f);
    glVertex2f(-0.744f, 0.4514f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 51, 51);
    glVertex2f(-0.328f, 0.4514f);
    glVertex2f(-0.392f, 0.5578f);
    glVertex2f(-0.568f, 0.5578f);
    glVertex2f(-0.568f, 0.4514f);
    glEnd();

    //Inside Train
    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2f(-0.776f, 0.478f);
    glVertex2f(-0.776f, 0.5445f);
    glVertex2f(-0.928f, 0.5445f);
    glVertex2f(-0.972f, 0.478f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2f(-0.592f, 0.478f);
    glVertex2f(-0.592f, 0.5445f);
    glVertex2f(-0.728f, 0.5445f);
    glVertex2f(-0.728f, 0.478f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2f(-0.36f, 0.478f);
    glVertex2f(-0.4f, 0.5445f);
    glVertex2f(-0.552f, 0.5445f);
    glVertex2f(-0.552f, 0.478f);
    glEnd();


    ///Middle Train Lines
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex2f(-0.552f, 0.5445f);
    glVertex2f(-0.514f, 0.478f);

    glVertex2f(-0.514f, 0.5445f);
    glVertex2f(-0.476f, 0.478f);

    glVertex2f(-0.476f, 0.5445f);
    glVertex2f(-0.438f, 0.478f);

    glVertex2f(-0.438f, 0.5445f);
    glVertex2f(-0.4f, 0.478f);

    glVertex2f(-0.70f, 0.5445f);
    glVertex2f(-0.70f, 0.476f);

    glVertex2f(-0.662f, 0.5445f);
    glVertex2f(-0.662f, 0.476f);

    glVertex2f(-0.624f, 0.5445f);
    glVertex2f(-0.624f, 0.476f);

    glVertex2f(-0.814f, 0.478f);
    glVertex2f(-0.776f, 0.5445f);

    glVertex2f(-0.852f, 0.478f);
    glVertex2f(-0.814f, 0.5445f);

    glVertex2f(-0.890f, 0.478f);
    glVertex2f(-0.852f, 0.5445f);

    glVertex2f(-0.928f, 0.478f);
    glVertex2f(-0.890f, 0.5445f);
    glEnd();

    glLineWidth(1);
    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex2f(-0.76f, 0.48f);
    glVertex2f(-0.744f, 0.48f);

    glVertex2f(-0.760f, 0.51f);
    glVertex2f(-0.744f, 0.51f);


    glVertex2f(-0.584f, 0.48f);
    glVertex2f(-0.568f, 0.48f);

    glVertex2f(-0.584f, 0.51f);
    glVertex2f(-0.568f, 0.51f);
    glEnd();
}

void TrainLine2()
{
    ///shade
    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 0);

    glVertex2f( 0.024f, 0.4414f);
    glVertex2f(-0.032f, 0.611f);
    glVertex2f(-0.312f, 0.611f);
    glVertex2f(-0.256f, 0.4414f);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(0, 0, 0);
    glVertex2f(-0.176f, 0.611f);
    glVertex2f(-0.12f, 0.4414f);

    glVertex2f(-0.032f, 0.611f);
    glVertex2f( 0.024f, 0.4414f);

    glVertex2f(-0.312f, 0.611f);
    glVertex2f(-0.256f, 0.4414f);

    glVertex2f(-0.256f, 0.4414f);
    glVertex2f( 0.024f, 0.4414f);
    glEnd();
}

void car1()
{
    glBegin(GL_QUADS);
    glColor3ub(225, 229, 150);
    glVertex2f(-0.28f, -0.133f);
    glVertex2f(-0.28f,  0.03f);
    glVertex2f(-0.504f,  0.03f);
    glVertex2f(-0.504f, -0.133f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(225, 229, 150);
    glVertex2f(-0.504f, -0.133f);
    glVertex2f(-0.504f,  0.03f);
    glVertex2f(-0.520f, 0.0034f);
    glVertex2f(-0.520f, -0.1197f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(202, 174, 46);
    glVertex2f(-0.232f,  -0.133f);
    glVertex2f(-0.232f,  -0.048f);
    glVertex2f(-0.28f, -0.048f);
    glVertex2f(-0.28f, -0.133f);
    glEnd();

    GLfloat x= -0.28f; GLfloat y= -0.133f; GLfloat radius =0.085f;
    int triangleAmount = 20;

    glColor3ub(202, 174, 46);
    DrawCircle2(x,y,radius,triangleAmount);

    x = -0.28f; y = -0.048f; radius = 0.048f;
    glColor3ub(255, 228, 108);
    DrawCircle2(x,y,radius,triangleAmount);

    x = -0.27f; y = -0.133f; radius = 0.026f;
    glColor3ub(11, 11, 11);
    DrawCircle(x,y,radius,triangleAmount);

    x = -0.45f; y = -0.133f; radius = 0.026f;
    glColor3ub(11, 11, 11);
    DrawCircle(x,y,radius,triangleAmount);

}


void car2()
{
    glBegin(GL_QUADS);
    glColor3ub(171, 0, 0);
    glVertex2f( 0.22f, 0.13f);
    glVertex2f( 0.22f,  0.18f);
    glVertex2f( -0.08f, 0.18f);
    glVertex2f( -0.08f,  0.13f);

    glVertex2f( 0.17f, 0.18f);
    glVertex2f( 0.11f, 0.25f);
    glVertex2f(-0.02f, 0.25f);
    glVertex2f(-0.08f, 0.18f);


    glColor3ub(180, 218, 240);
    glVertex2f( 0.15f, 0.18f);
    glVertex2f( 0.10f, 0.23f);
    glVertex2f(-0.01f, 0.23f);
    glVertex2f(-0.06f, 0.18f);
    glEnd();

    glColor3ub(97, 97, 97);
    glBegin(GL_LINE_LOOP);
    glVertex2f( 0.15f, 0.18f);
    glVertex2f( 0.10f, 0.23f);
    glVertex2f(-0.01f, 0.23f);
    glVertex2f(-0.06f, 0.18f);
    glEnd();

    glBegin(GL_LINES);
    glVertex2f(-0.01f, 0.23f);
    glVertex2f(-0.01f, 0.18f);

    glVertex2f( 0.10f, 0.23f);
    glVertex2f( 0.10f, 0.18f);

    glVertex2f( 0.05f, 0.23f);
    glVertex2f( 0.05f, 0.18f);
    glEnd();

    GLfloat x = 0.15f, y = 0.13f, radius = 0.026f;
    int triangleAmount = 20;
    glColor3ub(11, 11, 11);
    DrawCircle(x,y,radius,triangleAmount);

    x = -0.0f; y = 0.13f; radius = 0.026f;
    glColor3ub(11, 11, 11);
    DrawCircle(x,y,radius,triangleAmount);
}


void TrafficLight()
{
    ///glVertex2f(0.375f,0.2258f);
    glBegin(GL_LINES);
    glColor3ub(0,0,0);
    glVertex2f(0.365f,0.2258f);
    glVertex2f(0.365f,0.30f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0, 0, 0);
    glVertex2f(0.39f,0.30f);
    glVertex2f(0.39f,0.45f);
    glVertex2f(0.34f,0.45f);
    glVertex2f(0.34f,0.30f);
    glEnd();

    GLfloat x= 0.365f; GLfloat y=0.425f; GLfloat radius =0.015f;
    int triangleAmount = 20;
    glColor3ub(trr, trg, trb);
    DrawCircle(x,y,radius,triangleAmount);

    y=0.38f;
    glColor3ub(tyr, tyg, tyb);
    DrawCircle(x,y,radius,triangleAmount);

    y=0.335f;
    glColor3ub(tgr, tgg, tgb);
    DrawCircle(x,y,radius,triangleAmount);
}

void StreetLight()
{
    glBegin(GL_LINES);
    glColor3ub(0,0,0);

    glVertex2f(-0.82f, -0.2486f);
    glVertex2f(-0.82f,  0.35f);

    glVertex2f(-0.89f,  0.35f);
    glVertex2f(-0.75f,  0.35f);

    glVertex2f(-0.32f, -0.2486f);
    glVertex2f(-0.32f,  0.35f);

    glVertex2f(-0.39f,  0.35f);
    glVertex2f(-0.25f,  0.35f);

    glVertex2f( 0.22f, -0.2486f);
    glVertex2f( 0.22f,  0.35f);

    glVertex2f( 0.15f,  0.35f);
    glVertex2f( 0.29f,  0.35f);

    glVertex2f( 0.78f, -0.2486f);
    glVertex2f( 0.78f,  0.35f);

    glVertex2f( 0.71f,  0.35f);
    glVertex2f( 0.85f,  0.35f);

    glVertex2f(-0.59f,  0.34f);
    glVertex2f(-0.59f,  0.24f);

    glVertex2f(-0.19f,  0.34f);
    glVertex2f(-0.19f,  0.24f);

    glVertex2f( 0.10f,  0.34f);
    glVertex2f( 0.10f,  0.24f);

    glVertex2f( 0.49f,  0.34f);
    glVertex2f( 0.49f,  0.24f);

    glVertex2f( 0.90f,  0.34f);
    glVertex2f( 0.90f,  0.24f);
    glEnd();

    GLfloat x= -0.59f; GLfloat y= 0.34f; GLfloat radius =0.02f;
	int triangleAmount = 20;

    glColor3ub(slr, slg, slb);
    DrawCircle(x,y,radius,triangleAmount);
    x = -0.19f;
    DrawCircle(x,y,radius,triangleAmount);
    x = 0.10f;
    DrawCircle(x,y,radius,triangleAmount);
    x = 0.49f;
    DrawCircle(x,y,radius,triangleAmount);
    x = 0.90f;
    DrawCircle(x,y,radius,triangleAmount);

    glBegin(GL_QUADS);
    glColor3ub(slr, slg, slb);
    glVertex2f(-0.87f,  0.34f);
    glVertex2f(-0.87f,  0.35f);
    glVertex2f(-0.89f,  0.35f);
    glVertex2f(-0.89f,  0.34f);

    glVertex2f(-0.75f,  0.34f);
    glVertex2f(-0.75f,  0.35f);
    glVertex2f(-0.77f,  0.35f);
    glVertex2f(-0.77f,  0.34f);

    glVertex2f(-0.25f,  0.34f);
    glVertex2f(-0.25f,  0.35f);
    glVertex2f(-0.27f,  0.35f);
    glVertex2f(-0.27f,  0.34f);

    glVertex2f(-0.37f,  0.34f);
    glVertex2f(-0.37f,  0.35f);
    glVertex2f(-0.39f,  0.35f);
    glVertex2f(-0.39f,  0.34f);

    glVertex2f( 0.15f,  0.34f);
    glVertex2f( 0.15f,  0.35f);
    glVertex2f( 0.17f,  0.35f);
    glVertex2f( 0.17f,  0.34f);

    glVertex2f( 0.27f,  0.34f);
    glVertex2f( 0.27f,  0.35f);
    glVertex2f( 0.29f,  0.35f);
    glVertex2f( 0.29f,  0.34f);

    glVertex2f( 0.71f,  0.34f);
    glVertex2f( 0.71f,  0.35f);
    glVertex2f( 0.73f,  0.35f);
    glVertex2f( 0.73f,  0.34f);

    glVertex2f( 0.83f,  0.34f);
    glVertex2f( 0.83f,  0.35f);
    glVertex2f( 0.85f,  0.35f);
    glVertex2f( 0.85f,  0.34f);
    glEnd();
}

void tree1(GLfloat vx)
{
    glBegin(GL_QUADS);
    glColor3ub(80, 2, 0);
    glVertex2f((-0.91f + vx), 0.29f);
    glVertex2f((-0.91f + vx), 0.40f);
    glVertex2f((-0.92f + vx), 0.40f);
    glVertex2f((-0.92f + vx), 0.29f);
    glEnd();

    GLfloat x = (-0.915f + vx); GLfloat y = 0.42f; GLfloat radius = 0.03f;
	int triangleAmount = 20;
    glColor3ub(14, 129, 0);
    DrawCircle(x,y,radius,triangleAmount);
    x = (-0.885f + vx); y = 0.43f;
    DrawCircle(x,y,radius,triangleAmount);
    x = (-0.915f + vx); y = 0.44f;
    DrawCircle(x,y,radius,triangleAmount);
    x = (-0.945f + vx); y = 0.43f;
    DrawCircle(x,y,radius,triangleAmount);
}

void Tree()
{
    tree1(0.0f);
    tree1(0.35f);
    tree1(0.93f);
    tree1(0.06f);
    tree1(1.36f);
    tree1(1.70f);
}

void building17()
{
    glBegin(GL_QUADS);
    glColor3ub(191, 0, 60);
    glVertex2f(-0.246f, 0.33f);
    glVertex2f(-0.246f, 0.70f);
    glVertex2f(-0.156f, 0.70f);
    glVertex2f(-0.156f, 0.33f);
    glEnd();
}

void building18()
{
    glBegin(GL_QUADS);
    glColor3ub(159, 112, 194);
    glVertex2f(-0.140f, 0.33f);
    glVertex2f(-0.140f, 0.68f);
    glVertex2f( 0.112f, 0.68f);
    glVertex2f( 0.112f, 0.33f);
    glEnd();
}

void building16()
{
    glBegin(GL_QUADS);
    glColor3ub(157, 58, 36);
    glVertex2f(-0.85f, 0.33f);
    glVertex2f(-0.85f, 0.48f);
    glVertex2f(-0.73f, 0.48f);
    glVertex2f(-0.73f, 0.33f);
    glEnd();
}

void building15()
{
    glBegin(GL_QUADS);
    glColor3ub(0, 158, 136);
    glVertex2f(-0.95f, 0.33f);
    glVertex2f(-0.95f, 0.58f);
    glVertex2f(-0.85f, 0.58f);
    glVertex2f(-0.85f, 0.33f);
    glEnd();
}

void building1()
{
    ///main building
    glBegin(GL_QUADS);
    glColor3ub(173, 82, 54);
    glVertex2f(-0.92f, 0.33f);
    glVertex2f(-0.92f, 0.52f);
    glVertex2f(-1.0f, 0.52f);
    glVertex2f(-1.0f, 0.33f);
    glEnd();

    ///Window
    glColor3ub(r,g,b);
    glBegin(GL_QUADS);
    glVertex2f(-0.935f, 0.44f);
    glVertex2f(-0.935f, 0.49f);
    glVertex2f(-0.99f, 0.49f);
    glVertex2f(-0.99f, 0.44f);
    glEnd();


    glBegin(GL_QUADS);
    glVertex2f(-0.935f, 0.36f);
    glVertex2f(-0.935f, 0.41f);
    glVertex2f(-0.99f, 0.41f);
    glVertex2f(-0.99f, 0.36f);
    glEnd();
}

void building2()
{
    glBegin(GL_QUADS);
    glColor3ub(125, 142, 255);
    glVertex2f(-0.76f, 0.33f);
    glVertex2f(-0.76f, 0.64f);
    glVertex2f(-0.88f, 0.64f);
    glVertex2f(-0.88f, 0.33f);
    glEnd();

    ///Window
    glColor3ub(r,g,b);
    glBegin(GL_QUADS);
    glVertex2f(-0.83f, 0.55f);
    glVertex2f(-0.83f, 0.61f);
    glVertex2f(-0.87f, 0.61f);
    glVertex2f(-0.87f, 0.55f);
    glEnd();


    glBegin(GL_QUADS);
    glVertex2f(-0.77f, 0.55f);
    glVertex2f(-0.77f, 0.61f);
    glVertex2f(-0.812f, 0.61f);
    glVertex2f(-0.812f, 0.55f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(-0.83f, 0.46f);
    glVertex2f(-0.83f, 0.52f);
    glVertex2f(-0.87f, 0.52f);
    glVertex2f(-0.87f, 0.46f);
    glEnd();


    glBegin(GL_QUADS);
    glVertex2f(-0.77f, 0.46f);
    glVertex2f(-0.77f, 0.52f);
    glVertex2f(-0.812f, 0.52f);
    glVertex2f(-0.812f, 0.46f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(-0.83f, 0.37f);
    glVertex2f(-0.83f, 0.43f);
    glVertex2f(-0.87f, 0.43f);
    glVertex2f(-0.87f, 0.37f);
    glEnd();


    glBegin(GL_QUADS);
    glVertex2f(-0.77f, 0.37f);
    glVertex2f(-0.77f, 0.43f);
    glVertex2f(-0.812f, 0.43f);
    glVertex2f(-0.812f, 0.37f);
    glEnd();
}

void building3()
{
    glBegin(GL_QUADS);
    glColor3ub(132, 255, 112);
    glVertex2f(-0.6f, 0.33f);
    glVertex2f(-0.6f, 0.62f);
    glVertex2f(-0.736f, 0.62f);
    glVertex2f(-0.736f, 0.33f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(35, 255, 0);
    glVertex2f(-0.61f, 0.62f);
    glVertex2f(-0.61f, 0.70f);
    glVertex2f(-0.73f, 0.66f);
    glVertex2f(-0.73f, 0.62f);
    glEnd();

    ///Windows
    glColor3ub(r,g,b);
    glBegin(GL_QUADS);
    glVertex2f(-0.726f, 0.54f);
    glVertex2f(-0.726f, 0.59f);
    glVertex2f(-0.67f, 0.59f);
    glVertex2f(-0.67f, 0.54f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(-0.61f, 0.54f);
    glVertex2f(-0.61f, 0.59f);
    glVertex2f(-0.66f, 0.59f);
    glVertex2f(-0.66f, 0.54f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(-0.726f, 0.46f);
    glVertex2f(-0.726f, 0.51f);
    glVertex2f(-0.67f, 0.51f);
    glVertex2f(-0.67f, 0.46f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(-0.61f, 0.46f);
    glVertex2f(-0.61f, 0.51f);
    glVertex2f(-0.66f, 0.51f);
    glVertex2f(-0.66f, 0.46f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(-0.726f, 0.37f);
    glVertex2f(-0.726f, 0.43f);
    glVertex2f(-0.67f, 0.43f);
    glVertex2f(-0.67f, 0.37f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(-0.61f, 0.37f);
    glVertex2f(-0.61f, 0.43f);
    glVertex2f(-0.66f, 0.43f);
    glVertex2f(-0.66f, 0.37f);
    glEnd();
}

void building4()
{
    glBegin(GL_QUADS);
    glColor3ub(94, 65, 133);
    glVertex2f(-0.472f, 0.33f);
    glVertex2f(-0.472f, 0.64f);
    glVertex2f(-0.576f, 0.64f);
    glVertex2f(-0.576f, 0.33f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(99, 156, 177);
    glVertex2f(-0.48f, 0.33f);
    glVertex2f(-0.48f, 0.62f);
    glVertex2f(-0.568f, 0.62f);
    glVertex2f(-0.568f, 0.33f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(112, 95, 135);
    glVertex2f(-0.478f, 0.64f);
    glVertex2f(-0.478f, 0.68f);
    glVertex2f(-0.570f, 0.68f);
    glVertex2f(-0.570f, 0.64f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(112, 95, 135);
    glVertex2f(-0.498f, 0.68f);
    glVertex2f(-0.498f, 0.73f);
    glVertex2f(-0.550f, 0.73f);
    glVertex2f(-0.550f, 0.68f);
    glEnd();

    glBegin(GL_LINES);
    glColor3ub(11,11,11);
    glVertex2f(-0.524f, 0.73f);
    glVertex2f(-0.524f, 0.80f);

    glVertex2f(-0.508f, 0.615f);
    glVertex2f(-0.508f, 0.33f);

    glVertex2f(-0.538f, 0.615f);
    glVertex2f(-0.538f, 0.33f);
    glEnd();
}

void building5()
{
    glBegin(GL_QUADS);
    glColor3ub(255, 72, 0);
    glVertex2f(-0.216f, 0.33f);
    glVertex2f(-0.216f, 0.55f);
    glVertex2f(-0.416f, 0.55f);
    glVertex2f(-0.416f, 0.33f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2f(-0.24f, 0.4934f);
    glVertex2f(-0.24f, 0.52f);
    glVertex2f(-0.39f, 0.52f);
    glVertex2f(-0.39f, 0.4934f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 255, 255);
    glVertex2f(-0.24f, 0.55f);
    glVertex2f(-0.24f, 0.58f);
    glVertex2f(-0.39f, 0.58f);
    glVertex2f(-0.39f, 0.55f);
    glEnd();

    GLfloat x= -0.315f; GLfloat y= 0.58f; GLfloat radius =0.088f;
    int triangleAmount = 20;

    glColor3ub(255, 72, 0 );
    DrawCircle1(x,y,radius,triangleAmount);

    ///Windows
    glBegin(GL_QUADS);
    glColor3ub(r,g,b);
    glVertex2f(-0.33f, 0.4634f);
    glVertex2f(-0.33f, 0.38f);
    glVertex2f(-0.40f, 0.38f);
    glVertex2f(-0.40f, 0.4634f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f(-0.23f, 0.4634f);
    glVertex2f(-0.23f, 0.38f);
    glVertex2f(-0.31f, 0.38f);
    glVertex2f(-0.31f, 0.4634f);
    glEnd();
}

void building6()
{
    glBegin(GL_QUADS);
    glColor3ub(124, 0, 191);
    glVertex2f( 0.048f, 0.33f);
    glVertex2f( 0.048f, 0.58f);
    glVertex2f(-0.192f, 0.58f);
    glVertex2f(-0.192f, 0.33f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(199, 156, 177);
    glVertex2f( 0.028f, 0.52f);
    glVertex2f( 0.028f, 0.55f);
    glVertex2f(-0.175f, 0.55f);
    glVertex2f(-0.175f, 0.52f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(199, 156, 177);
    glVertex2f( 0.028f, 0.46f);
    glVertex2f( 0.028f, 0.49f);
    glVertex2f(-0.175f, 0.49f);
    glVertex2f(-0.175f, 0.46f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(199, 156, 177);
    glVertex2f( 0.028f, 0.40f);
    glVertex2f( 0.028f, 0.43f);
    glVertex2f(-0.175f, 0.43f);
    glVertex2f(-0.175f, 0.40f);
    glEnd();

    ///windows
    glColor3ub(r,g,b);
    glBegin(GL_QUADS);
    glVertex2f( 0.028f, 0.52f);
    glVertex2f( 0.028f, 0.55f);
    glVertex2f(-0.175f, 0.55f);
    glVertex2f(-0.175f, 0.52f);

    glVertex2f( 0.028f, 0.46f);
    glVertex2f( 0.028f, 0.49f);
    glVertex2f(-0.175f, 0.49f);
    glVertex2f(-0.175f, 0.46f);

    glVertex2f( 0.028f, 0.40f);
    glVertex2f( 0.028f, 0.43f);
    glVertex2f(-0.175f, 0.43f);
    glVertex2f(-0.175f, 0.40f);
    glEnd();
}

void building7()
{
    glBegin(GL_QUADS);
    glColor3ub(213, 200, 101);
    glVertex2f( 0.312f, 0.33f);
    glVertex2f( 0.312f, 0.58f);
    glVertex2f( 0.072f, 0.58f);
    glVertex2f( 0.072f, 0.33f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(135, 61, 61);
    glVertex2f( 0.312f, 0.58f);
    glVertex2f( 0.292f, 0.64f);
    glVertex2f( 0.093f, 0.64f);
    glVertex2f( 0.072f, 0.58f);
    glEnd();

    ///Windows
    glBegin(GL_QUADS);
    glColor3ub(r1,g1,b1);
    glVertex2f( 0.182f, 0.47f);
    glVertex2f( 0.182f, 0.55f);
    glVertex2f( 0.082f, 0.55f);
    glVertex2f( 0.082f, 0.47f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f( 0.302f, 0.47f);
    glVertex2f( 0.302f, 0.55f);
    glVertex2f( 0.202f, 0.55f);
    glVertex2f( 0.202f, 0.47f);
    glEnd();


    glBegin(GL_QUADS);
    glVertex2f( 0.182f, 0.35f);
    glVertex2f( 0.182f, 0.43f);
    glVertex2f( 0.082f, 0.43f);
    glVertex2f( 0.082f, 0.35f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f( 0.302f, 0.35f);
    glVertex2f( 0.302f, 0.43f);
    glVertex2f( 0.202f, 0.43f);
    glVertex2f( 0.202f, 0.35f);
    glEnd();
}

void building8()
{
    glBegin(GL_QUADS);
    glColor3ub(152, 4, 85);
    glVertex2f( 0.568f, 0.33f);
    glVertex2f( 0.568f, 0.54f);
    glVertex2f( 0.336f, 0.54f);
    glVertex2f( 0.336f, 0.33f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 0, 216);
    glVertex2f( 0.568f, 0.54f);
    glVertex2f( 0.578f, 0.58f);
    glVertex2f( 0.352f, 0.58f);
    glVertex2f( 0.336f, 0.54f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(255, 0, 216);
    glVertex2f( 0.578f, 0.33f);
    glVertex2f( 0.578f, 0.58f);
    glVertex2f( 0.568f, 0.54f);
    glVertex2f( 0.568f, 0.33f);
    glEnd();

    ///Windows
    glColor3ub(r,g,b);
    glBegin(GL_QUADS);
    glVertex2f( 0.436f, 0.45f);
    glVertex2f( 0.436f, 0.51f);
    glVertex2f( 0.346f, 0.51f);
    glVertex2f( 0.346f, 0.45f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f( 0.556f, 0.45f);
    glVertex2f( 0.556f, 0.51f);
    glVertex2f( 0.466f, 0.51f);
    glVertex2f( 0.466f, 0.45f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f( 0.436f, 0.35f);
    glVertex2f( 0.436f, 0.41f);
    glVertex2f( 0.346f, 0.41f);
    glVertex2f( 0.346f, 0.35f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f( 0.556f, 0.35f);
    glVertex2f( 0.556f, 0.41f);
    glVertex2f( 0.466f, 0.41f);
    glVertex2f( 0.466f, 0.35f);
    glEnd();
}

void building9()
{
    glBegin(GL_QUADS);
    glColor3ub(132, 255, 112);
    glVertex2f( 0.792f, 0.33f);
    glVertex2f( 0.792f, 0.64f);
    glVertex2f( 0.688f, 0.64f);
    glVertex2f( 0.688f, 0.33f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(99, 156, 177);
    glVertex2f( 0.784f, 0.33f);
    glVertex2f( 0.784f, 0.62f);
    glVertex2f( 0.696f, 0.62f);
    glVertex2f( 0.696f, 0.33f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(35, 255, 0);
    glVertex2f( 0.786f, 0.64f);
    glVertex2f( 0.786f, 0.68f);
    glVertex2f( 0.694f, 0.68f);
    glVertex2f( 0.694f, 0.64f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(35, 255, 0);
    glVertex2f( 0.766f, 0.68f);
    glVertex2f( 0.766f, 0.73f);
    glVertex2f( 0.714f, 0.73f);
    glVertex2f( 0.714f, 0.68f);
    glEnd();


    glBegin(GL_LINES);
    glColor3ub(11,11,11);
    glVertex2f( 0.725f, 0.615f);
    glVertex2f( 0.725f, 0.33f);

    glVertex2f( 0.754f, 0.615f);
    glVertex2f( 0.754f, 0.33f);
    glEnd();
}

void building10()
{
    glBegin(GL_QUADS);
    glColor3ub(0, 132, 255);
    glVertex2f( 0.856f, 0.33f);
    glVertex2f( 0.856f, 0.61f);
    glVertex2f( 0.816f, 0.64f);
    glVertex2f( 0.816f, 0.33f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0, 132, 255);
    glVertex2f( 1.0f, 0.33f);
    glVertex2f( 1.0f, 0.61f);
    glVertex2f( 0.856f, 0.61f);
    glVertex2f( 0.856f, 0.33f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(0, 132, 255);
    glVertex2f( 1.0f, 0.61f);
    glVertex2f( 1.0f, 0.64f);
    glVertex2f( 0.816f, 0.64f);
    glVertex2f( 0.856f, 0.61f);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 102);
    glVertex2f( 0.856f, 0.33f);
    glVertex2f( 0.856f, 0.61f);
    glVertex2f( 0.816f, 0.64f);
    glVertex2f( 0.816f, 0.33f);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 102);
    glVertex2f( 1.0f, 0.33f);
    glVertex2f( 1.0f, 0.61f);
    glVertex2f( 0.856f, 0.61f);
    glVertex2f( 0.856f, 0.33f);
    glEnd();

    glBegin(GL_LINE_LOOP);
    glColor3ub(0, 0, 102);
    glVertex2f( 1.0f, 0.61f);
    glVertex2f( 1.0f, 0.64f);
    glVertex2f( 0.816f, 0.64f);
    glVertex2f( 0.856f, 0.61f);
    glEnd();

    ///Windows
    glColor3ub(r,g,b);
    glBegin(GL_QUADS);
    glVertex2f( 0.98f, 0.48f);
    glVertex2f( 0.98f, 0.56f);
    glVertex2f( 0.886f, 0.56f);
    glVertex2f( 0.886f, 0.48f);
    glEnd();

    glBegin(GL_QUADS);
    glVertex2f( 0.98f, 0.36f);
    glVertex2f( 0.98f, 0.44f);
    glVertex2f( 0.886f, 0.44f);
    glVertex2f( 0.886f, 0.36f);
    glEnd();
}

void building11()
{
    glBegin(GL_QUADS);
    glColor3ub(6, 145, 113);
    glVertex2f( 0.578f, 0.58f);
    glVertex2f( 0.578f, 0.72f);
    glVertex2f( 0.478f, 0.72f);
    glVertex2f( 0.478f, 0.58f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(3, 99, 29);
    glVertex2f( 0.578f, 0.72f);
    glVertex2f( 0.585f, 0.75f);
    glVertex2f( 0.485f, 0.75f);
    glVertex2f( 0.478f, 0.72f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(3, 99, 29);
    glVertex2f( 0.585f, 0.33f);
    glVertex2f( 0.585f, 0.75f);
    glVertex2f( 0.578f, 0.72f);
    glVertex2f( 0.578f, 0.33f);
    glEnd();
}

void building12()
{
    glBegin(GL_QUADS);
    glColor3ub(224, 0, 29);
    glVertex2f( 0.688f, 0.33f);
    glVertex2f( 0.688f, 0.59f);
    glVertex2f( 0.648f, 0.56f);
    glVertex2f( 0.648f, 0.33f);
    glEnd();
}

void building13()
{
    glBegin(GL_QUADS);
    glColor3ub(87, 0, 0);
    glVertex2f( 0.648f, 0.33f);
    glVertex2f( 0.648f, 0.68f);
    glVertex2f( 0.630f, 0.66f);
    glVertex2f( 0.630f, 0.33f);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(224, 0, 0);
    glVertex2f( 0.696f, 0.56f);
    glVertex2f( 0.696f, 0.68f);
    glVertex2f( 0.648f, 0.68f);
    glVertex2f( 0.648f, 0.56f);
    glEnd();
}

void building14()
{
    glBegin(GL_QUADS);
    glColor3ub(192, 192, 0);
    glVertex2f( 0.856f, 0.33f);
    glVertex2f( 0.856f, 0.71f);
    glVertex2f( 0.766f, 0.71f);
    glVertex2f( 0.766f, 0.33f);
    glEnd();
}

void Buildings()
{
    glBegin(GL_QUADS);
    glColor3ub(0, 255, 35);
    glVertex2f( 1.0f, 0.33f);
    glVertex2f( 1.0f, 0.38f);
    glVertex2f(-1.0f, 0.38f);
    glVertex2f(-1.0f, 0.33f);
    glEnd();

    building18();
    building17();
    building16();
    building15();
    building13();
    building11();
    building12();
    building14();
    building1();
    building2();
    building3();
    building4();
    building5();
    building6();
    building7();
    building8();
    building9();
    building10();
}

void Rain()
{
    int f= 0;
    GLfloat x = -1.0, y = 1.99;
    for(int j= 0; j<70; j++)
    {
        for(int i = 0; i<90; i++)
        {
            glLineWidth(3);
            glBegin(GL_LINES);
            glPointSize(15);
            glColor3ub(225, 225, 225);
            glVertex2f(x,y);
            glVertex2f(x-0.005, y - 0.015);
            glEnd();
            x += .08;
        }
        y -= 0.05;
        if(f==0)
        {
            x = -0.96;
            f=1;
        }
        else if(f==1)
        {
            x = -1.0;
            f=0;
        }
    }
}

void DayDisplay()
{
    if(DayMode)
    {
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
        glColorMaterial ( GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE ) ;
        glEnable(GL_COLOR_MATERIAL);
        glLoadIdentity();

        PointLight(1,1,0, 0.8, 0.8, 0.7);

        sky();
        sun();

        glPushMatrix();
        glTranslatef(Cloud1PositionX, 0.0f, 0.0f);
        cloud1();
        glPopMatrix();


        glPushMatrix();
        glTranslatef(Cloud2PositionX, 0.0f, 0.0f);
        cloud2();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(BirdPositionX, BirdPositionY, 0.0f);
        bird1();
        bird2();
        glPopMatrix();
        river();
        riverBridge();
        glPushMatrix();
        glTranslatef(Boat2PositionX, 0.0f, 0.0f);
        boat2();
        glPopMatrix();
        glPushMatrix();
        glTranslatef(Boat1PositionX, 0.0f, 0.0f);
        boat1();
        glPopMatrix();
        footpath1();
        footpath2();
        fence();
        road1();
        Buildings();
        Tree();
        TrafficLight();

        glPushMatrix();
        glTranslatef(HelicopterPositionX, HelicopterPositionY, 0.0f);
        helicopter();
        glPopMatrix();

        TrainLine1();
        glPushMatrix();
        glTranslatef(TrainPositionX, 0.0f, 0.0f);
        train();
        glPopMatrix();
        TrainLine2();

        glPushMatrix();
        glTranslatef(Car2PositionX, 0.0f, 0.0f);
        car2();
        glPopMatrix();

        glPushMatrix();
        glTranslatef(Car1PositionX, 0.0f, 0.0f);
        car1();
        glPopMatrix();

        StreetLight();
        if(RainMode == true)
        {
            glPushMatrix();
            glTranslatef(0.0f,RainPositionY, 0.0f);
            Rain();
            glPopMatrix();
        }

        glFlush();
    }

}

void NightDisplay()
{
    if(NightMode)
    {
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
        glLoadIdentity();
        PointLight(0,0,1, 0.5, 1, 1);
        glColorMaterial ( GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE ) ;
        glEnable(GL_COLOR_MATERIAL);
        glColor4f(1.0f, 0.0f, 0.0f, 0.0f);

        glLoadIdentity();

        sky();
        moon();

        glPushMatrix();
        glTranslatef(Cloud1PositionX, 0.0f, 0.0f);
        cloud1();
        glPopMatrix();


        glPushMatrix();
        glTranslatef(Cloud2PositionX, 0.0f, 0.0f);
        cloud2();
        glPopMatrix();
        stars();
        river();
        riverBridge();
        glPushMatrix();
        glTranslatef(Boat2PositionX, 0.0f, 0.0f);
        boat2();
        glPopMatrix();
        glPushMatrix();
        glTranslatef(Boat1PositionX, 0.0f, 0.0f);
        boat1();
        glPopMatrix();
        footpath1();
        footpath2();
        fence();
        road1();
        Buildings();
        Tree();
        TrafficLight();
        helicopter();
        TrainLine1();
        glPushMatrix();
        glTranslatef(TrainPositionX, 0.0f, 0.0f);
        train();
        glPopMatrix();
        TrainLine2();
        glPushMatrix();
        glTranslatef(Car2PositionX, 0.0f, 0.0f);
        car2();
        glPopMatrix();
        glPushMatrix();
        glTranslatef(Car1PositionX, 0.0f, 0.0f);
        car1();
        glPopMatrix();
        StreetLight();
        if(RainMode == true)
        {
            glPushMatrix();
            glTranslatef(0.0f,RainPositionY, 0.0f);
            Rain();
            glPopMatrix();
        }
        glFlush();
    }
}

void DayModePositionReset()
{
    if(DayMode)
    {
        HelicopterPositionX = 0.0f;
        HelicopterPositionY = 0.0f;

        BirdPositionX = -0.5f;
        BirdPositionY = -0.2f;
    }
}

void MainDisplay()
{
    if(DayMode)
    {
        DayDisplay();
    }
    else if(NightMode)
    {
        NightDisplay();
    }
}


void init() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void handleKeypress(unsigned char key, int x, int y)
{
	switch (key)
	{
        case 'N':
        case 'n':
            DayMode = false;
            NightMode = true;
            NightColorChange();
            MainDisplay();
            break;
	    case 'D':
        case 'd':
            DayMode = true;
            NightMode = false;
            DayModePositionReset();
            DayColorChange();
            MainDisplay();
            break;
        case 'H':
        case 'h':
            if(KeyH == 0)
            {
                KeyH = 1;
                StopHeli = false;
                MoveHelicopter(HelicopterSpeed);
            }
            else if(KeyH == 1)
            {
                StopHeli = true;
                MoveHelicopter(HelicopterSpeed);
                KeyH = 0;
            }
            break;
        case 'B':
        case 'b':
            if(KeyB == 0)
            {
                StopBoat1 = false;
                MoveBoat1(Boat1Speed);
                KeyB = 1;
            }
            else if(KeyB == 1)
            {
                StopBoat1 = true;
                MoveBoat1(Boat1Speed);
                KeyB = 0;
            }
            break;
        case 'V':
        case 'v':
            if(KeyV == 0)
            {
                StopBoat2 = false;
                MoveBoat2(Boat2Speed);
                KeyV = 1;
            }
            else if(KeyV == 1)
            {
                StopBoat2 = true;
                MoveBoat2(Boat2Speed);
                KeyV = 0;
            }
            break;
        case 'C':
        case 'c':
            if(KeyC == 0)
            {
                StopCloud1 = false;
                MoveCloud1(Cloud1Speed);
                KeyC = 1;
            }
            else if(KeyC == 1)
            {
                StopCloud1 = true;
                MoveCloud1(Cloud1Speed);
                KeyC = 0;
            }
            break;
        case 'X':
        case 'x':
            if(KeyX == 0)
            {
                StopCloud2 = false;
                MoveCloud2(Cloud2Speed);
                KeyX = 1;
            }
            else if(KeyX == 1)
            {
                StopCloud2 = true;
                MoveCloud2(Cloud2Speed);
                KeyX = 0;
            }
            break;
        case 'W':
        case 'w':
            MoveForward = true;
            MoveBackward = false;
            MoveTrainForward(TrainSpeed);
            break;
        case 'A':
        case 'a':
            MoveForward = false;
            MoveBackward = true;
            MoveTrainBackward(TrainSpeed);
            break;
        case 'S':
        case 's':
            MoveForward = false;
            MoveBackward = false;
            break;
        case 'Z':
        case 'z':
            if(KeyZ == 0)
            {
                StopBird = false;
                MoveBird(BirdSpeed);
                KeyZ = 1;
            }
            else if(KeyZ == 1)
            {
                StopBird = true;
                MoveBird(BirdSpeed);
                KeyZ = 0;
            }
            break;
        case 'R':
        case 'r':
            TrafficLightGreen = false;
            TrafficLightRed = true;
            TrafficLightYellow = false;
            TrafficRedLightColor();
            break;
        case 'G':
        case 'g':
            TrafficLightGreen = true;
            TrafficLightRed = false;
            TrafficLightYellow = false;
            TrafficGreenLightColor();
            break;
        case 'Y':
        case 'y':
            TrafficLightGreen = false;
            TrafficLightRed = false;
            TrafficLightYellow = true;
            TrafficYellowLightColor();
            break;
        case 'E':
        case 'e':
            MoveRain(RainSpeed);
            if(KeyE == 1)
            {
                RainMode = true;
                StopRain = false;
                ///MainDisplay();
                MoveRain(RainSpeed);
                KeyE = 0;
            }
            else if(KeyE == 0)
            {
                RainMode = false;
                StopRain = true;
                ///MainDisplay();
                MoveRain(RainSpeed);
                KeyE = 1;
            }
            break;

        case 27:     // ESC key
            exit(0);
            break;

        default:
            break;



        glutPostRedisplay();
	}
}







int main(int argc, char** argv) {
    cout << endl << "*********** CityScape Life ********************" << endl << endl;

    cout << "Press D : For Day Mode" << endl << endl;
    cout << "Press N : For Night Mode" << endl << endl;
    cout << "Press R : For Red Traffic Light" << endl << endl;
    cout << "Press G : For Green Traffic Light" << endl << endl;
    cout << "Press Y : For Yellow Traffic Light" << endl << endl;
    cout << "Press W : To Move Train Forward" << endl << endl;
    cout << "Press A : To Move Train Backward" << endl << endl;
    cout << "Press S : To Stop Train" << endl << endl;
    cout << "Press Z : For Control Birds" << endl << endl;
    cout << "Press C : For Move Right Side Cloud" << endl << endl;
    cout << "Press X : For Move Left Side Cloud" << endl << endl;
    cout << "Press B : For Move Left Side Boat" << endl << endl;
    cout << "Press V : For Move Right Side Boat" << endl << endl;


    glutInit(&argc, argv);
    glutInitWindowSize(1050, 650);
    glutInitWindowPosition(50, 50);
    glutCreateWindow("CityScape Life");
    glutDisplayFunc(MainDisplay);
    init();
    glutKeyboardFunc(handleKeypress);
    glutTimerFunc(25, MoveBoat1, 0);
    glutTimerFunc(25, MoveBoat2, 0);
    glutTimerFunc(50, MoveBird, 0);
    glutTimerFunc(25, MoveCar1, 0);
    glutTimerFunc(25, MoveCar2, 0);
    glutTimerFunc(25, MoveCloud1, 0);
    glutTimerFunc(22, MoveCloud2, 0);
    glutMainLoop();
    return 0;
}
