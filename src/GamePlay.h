#include <GLFW/glfw3.h>
#include <math.h>
#include <iostream>
#include <chrono>
#include <thread>

double xGlobal = 0.00, yGlobal = 0.00;
bool turn = 0;
bool select[9] = { 0,0,0,0,0,0,0,0,0 };
int check[9] = { 0,0,0,0,0,0,0,0,0 };
int win[9] = { 0,0,0,0,0,0,0,0,0 };
int result;


inline void drawLine(float, float, float, float, float, float, float, float, float, float, float, float);
float* rightTopRet(float*);
float* centerTopRet(float*);
float* leftTopRet(float*);
float* rightMidRet(float*);
float* centerMidRet(float*);
float* leftMidRet(float*);
float* rightDownRet(float*);
float* centerDownRet(float*);
float* leftDownRet(float*);
void DrawCross(float*);
void DrawCircle(float, float);
void drawCircle(float cx, float cy);
void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
void whoWin();
void time_delay_intro();


GLFWwindow* window;


int Game(void)
{
    float CoOrdinates[24];


    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(800, 800, "TIC TAC TOE", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }


    /* Make the window's context current */
    glfwMakeContextCurrent(window);




    // Set the mouse button callback function
    glfwSetMouseButtonCallback(window, mouse_button_callback);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        if (result == 3)
        {
        glClear(GL_COLOR_BUFFER_BIT);
        result = 4;
        }


        /*For two vertical lines of box*/
        drawLine(-0.33f, 1.0f, -0.32f, 1.0f, -0.33f, -1.0f, -0.33f, -1.0f, -0.32f, -1.0f, -0.32f, 1.0f);
        drawLine(0.33f, 1.0f, 0.32f, 1.0f, 0.33f, -1.0f, 0.33f, -1.0f, 0.32f, -1.0f, 0.32f, 1.0f);

        /*For two horizontal lines of box*/
        drawLine(1.0f, 0.33f, 1.0f, 0.32f, -1.0f, 0.33f, 1.0f, 0.32f, -1.0f, 0.32f, -1.0f, 0.33f);
        drawLine(1.0f, -0.33f, 1.0f, -0.32f, -1.0f, -0.33f, 1.0f, -0.32f, -1.0f, -0.32f, -1.0f, -0.33f);

        whoWin();

        if (xGlobal < 266 && yGlobal < 266 && xGlobal > 0.0 && yGlobal > 0.0)
        {
            if (check[0] == 0)
            {
                select[0] = turn;
                check[0]++;
            }
            //topLeft
            if (select[0] == 0)
            {
                drawCircle(-0.66f, 0.66f);
                win[0] = 1;
            }
            else
            {
                DrawCross(leftTopRet(CoOrdinates));
                win[0] = 2;
            }
        }
        if (xGlobal < 533 && yGlobal < 266 && xGlobal > 266 && yGlobal > 0.0)
        {
            if (check[1] == 0)
            {
                select[1] = turn;
                check[1]++;

            }
            //topCenter
            if (select[1] == 0)
            {
                drawCircle(0.0f, 0.66f);
                win[1] = 1;
            }
            else
            {
                DrawCross(centerTopRet(CoOrdinates));
                win[1] = 2;

            }
        }
        if (xGlobal < 800 && yGlobal < 266 && xGlobal > 533 && yGlobal > 0.0)
        {
            if (check[2] == 0)
            {
                select[2] = turn;
                check[2]++;

            }
            //centRight
            if (select[2] == 0)
            {
                drawCircle(0.66f, 0.66f);
                win[2] = 1;
            }
            else
            {
                DrawCross(rightTopRet(CoOrdinates));
                win[2] = 2;

            }



        }
        if (xGlobal < 266 && yGlobal < 533 && xGlobal > 0 && yGlobal > 266)
        {
            if (check[3] == 0)
            {
                select[3] = turn;
                check[3]++;

            }
            //MidLeft
            if (select[3] == 0)
            {
                drawCircle(-0.66f, 0.0f);
                win[3] = 1;
            }
            else
            {
                DrawCross(leftMidRet(CoOrdinates));
                win[3] = 2;

            }


        }
        if (xGlobal < 533 && yGlobal < 533 && xGlobal > 266 && yGlobal > 266)
        {
            if (check[4] == 0)
            {
                select[4] = turn;
                check[4]++;

            }
            //MidCenter
            if (select[4] == 0)
            {
                drawCircle(0.0f, 0.0f);
                win[4] = 1;
            }
            else
            {
                DrawCross(centerMidRet(CoOrdinates));
                win[4] = 2;

            }


        }
        if (xGlobal < 800 && yGlobal < 533 && xGlobal > 533 && yGlobal > 266)
        {
            if (check[5] == 0)
            {
                select[5] = turn;
                check[5]++;

            }
            //MidRight
            if (select[5] == 0)
            {
                drawCircle(0.66f, 0.0f);
                win[5] = 1;
            }
            else
            {
                DrawCross(rightMidRet(CoOrdinates));
                win[5] = 2;

            }



        }
        if (xGlobal < 266 && yGlobal < 800 && xGlobal > 0 && yGlobal > 533)
        {
            if (check[6] == 0)
            {
                select[6] = turn;
                check[6]++;


            }
            //DownLeft
            if (select[6] == 0)
            {
                drawCircle(-0.66f, -0.66f);
                win[6] = 1;
            }
            else
            {
                DrawCross(leftDownRet(CoOrdinates));
                win[6] = 2;

            }


        }
        if (xGlobal < 533 && yGlobal < 800 && xGlobal > 266 && yGlobal > 533)
        {
            if (check[7] == 0)
            {
                select[7] = turn;
                check[7]++;


            }
            //DownCenter
            if (select[7] == 0)
            {
                drawCircle(0.0f, -0.66f);
                win[7] = 1;
            }
            else
            {
                DrawCross(centerDownRet(CoOrdinates));
                win[7] = 2;

            }


        }
        if (xGlobal < 800 && yGlobal < 800 && xGlobal > 533 && yGlobal > 533)
        {
            if (check[8] == 0)
            {
                select[8] = turn;
                check[8]++;


            }
            //DownRight
            if (select[8] == 0)
            {
                drawCircle(0.66f, -0.66f);
                win[8] = 1;
            }

            else
            {
                DrawCross(rightDownRet(CoOrdinates));
                win[8] = 2;

            }


        }



        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}


inline void drawLine(float FX1, float FY1, float FX2, float FY2, float FX3, float FY3, float SX1, float SY1, float SX2, float SY2, float SX3, float SY3)
{
    /*This function takes co-ordinates and draw a line using two triangles.*/
    glBegin(GL_TRIANGLES);
    glColor3f(1.f, 1.f, 1.f);
    glVertex2f(FX1, FY1);
    glVertex2f(FX2, FY2);
    glVertex2f(FX3, FY3);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(1.f, 1.f, 1.f);
    glVertex2f(SX1, SY1);
    glVertex2f(SX2, SY2);
    glVertex2f(SX3, SY3);
    glEnd();
}


float* rightTopRet(float Arr[24])
{
    float x = 0.66f, y = 0.66f;

    Arr[0] = 0.2f + x;
    Arr[1] = 0.24f + y;
    Arr[2] = 0.24f + x;
    Arr[3] = 0.2f + y;
    Arr[4] = -0.2f + x;
    Arr[5] = -0.24f + y;
    Arr[6] = -0.24f + x;
    Arr[7] = -0.2f + y;
    Arr[8] = -0.2f + x;
    Arr[9] = -0.24f + y;
    Arr[10] = 0.2f + x;
    Arr[11] = 0.24f + y;

    Arr[12] = -0.2f + x;
    Arr[13] = 0.24f + y;
    Arr[14] = -0.24f + x;
    Arr[15] = 0.2f + y;
    Arr[16] = 0.2f + x;
    Arr[17] = -0.24f + y;
    Arr[18] = 0.24f + x;
    Arr[19] = -0.2f + y;
    Arr[20] = 0.2f + x;
    Arr[21] = -0.24f + y;
    Arr[22] = -0.2f + x;
    Arr[23] = 0.24f + y;
    return Arr;

}
float* centerTopRet(float Arr[24])
{
    float x = 0.0f, y = 0.66f;

    Arr[0] = 0.2f + x;
    Arr[1] = 0.24f + y;
    Arr[2] = 0.24f + x;
    Arr[3] = 0.2f + y;
    Arr[4] = -0.2f + x;
    Arr[5] = -0.24f + y;
    Arr[6] = -0.24f + x;
    Arr[7] = -0.2f + y;
    Arr[8] = -0.2f + x;
    Arr[9] = -0.24f + y;
    Arr[10] = 0.2f + x;
    Arr[11] = 0.24f + y;

    Arr[12] = -0.2f + x;
    Arr[13] = 0.24f + y;
    Arr[14] = -0.24f + x;
    Arr[15] = 0.2f + y;
    Arr[16] = 0.2f + x;
    Arr[17] = -0.24f + y;
    Arr[18] = 0.24f + x;
    Arr[19] = -0.2f + y;
    Arr[20] = 0.2f + x;
    Arr[21] = -0.24f + y;
    Arr[22] = -0.2f + x;
    Arr[23] = 0.24f + y;
    return Arr;
}
float* leftTopRet(float Arr[24])
{
    float x = -0.66f, y = 0.66f;

    Arr[0] = 0.2f + x;
    Arr[1] = 0.24f + y;
    Arr[2] = 0.24f + x;
    Arr[3] = 0.2f + y;
    Arr[4] = -0.2f + x;
    Arr[5] = -0.24f + y;
    Arr[6] = -0.24f + x;
    Arr[7] = -0.2f + y;
    Arr[8] = -0.2f + x;
    Arr[9] = -0.24f + y;
    Arr[10] = 0.2f + x;
    Arr[11] = 0.24f + y;

    Arr[12] = -0.2f + x;
    Arr[13] = 0.24f + y;
    Arr[14] = -0.24f + x;
    Arr[15] = 0.2f + y;
    Arr[16] = 0.2f + x;
    Arr[17] = -0.24f + y;
    Arr[18] = 0.24f + x;
    Arr[19] = -0.2f + y;
    Arr[20] = 0.2f + x;
    Arr[21] = -0.24f + y;
    Arr[22] = -0.2f + x;
    Arr[23] = 0.24f + y;
    return Arr;
}
float* rightMidRet(float Arr[24])
{
    float x = 0.66f, y = 0.0f;

    Arr[0] = 0.2f + x;
    Arr[1] = 0.24f + y;
    Arr[2] = 0.24f + x;
    Arr[3] = 0.2f + y;
    Arr[4] = -0.2f + x;
    Arr[5] = -0.24f + y;
    Arr[6] = -0.24f + x;
    Arr[7] = -0.2f + y;
    Arr[8] = -0.2f + x;
    Arr[9] = -0.24f + y;
    Arr[10] = 0.2f + x;
    Arr[11] = 0.24f + y;

    Arr[12] = -0.2f + x;
    Arr[13] = 0.24f + y;
    Arr[14] = -0.24f + x;
    Arr[15] = 0.2f + y;
    Arr[16] = 0.2f + x;
    Arr[17] = -0.24f + y;
    Arr[18] = 0.24f + x;
    Arr[19] = -0.2f + y;
    Arr[20] = 0.2f + x;
    Arr[21] = -0.24f + y;
    Arr[22] = -0.2f + x;
    Arr[23] = 0.24f + y;
    return Arr;
}


float* centerMidRet(float Arr[24])
{
    Arr[0] = 0.2f;
    Arr[1] = 0.24f;
    Arr[2] = 0.24f;
    Arr[3] = 0.2f;
    Arr[4] = -0.2f;
    Arr[5] = -0.24f;
    Arr[6] = -0.24f;
    Arr[7] = -0.2f;
    Arr[8] = -0.2f;
    Arr[9] = -0.24f;
    Arr[10] = 0.2f;
    Arr[11] = 0.24f;

    Arr[12] = -0.2f;
    Arr[13] = 0.24f;
    Arr[14] = -0.24f;
    Arr[15] = 0.2f;
    Arr[16] = 0.2f;
    Arr[17] = -0.24f;
    Arr[18] = 0.24f;
    Arr[19] = -0.2f;
    Arr[20] = 0.2f;
    Arr[21] = -0.24f;
    Arr[22] = -0.2f;
    Arr[23] = 0.24f;
    return Arr;
}

float* leftMidRet(float Arr[24])
{
    float x = -0.66f, y = 0.0f;

    Arr[0] = 0.2f + x;
    Arr[1] = 0.24f + y;
    Arr[2] = 0.24f + x;
    Arr[3] = 0.2f + y;
    Arr[4] = -0.2f + x;
    Arr[5] = -0.24f + y;
    Arr[6] = -0.24f + x;
    Arr[7] = -0.2f + y;
    Arr[8] = -0.2f + x;
    Arr[9] = -0.24f + y;
    Arr[10] = 0.2f + x;
    Arr[11] = 0.24f + y;

    Arr[12] = -0.2f + x;
    Arr[13] = 0.24f + y;
    Arr[14] = -0.24f + x;
    Arr[15] = 0.2f + y;
    Arr[16] = 0.2f + x;
    Arr[17] = -0.24f + y;
    Arr[18] = 0.24f + x;
    Arr[19] = -0.2f + y;
    Arr[20] = 0.2f + x;
    Arr[21] = -0.24f + y;
    Arr[22] = -0.2f + x;
    Arr[23] = 0.24f + y;
    return Arr;
}
float* rightDownRet(float Arr[24])
{
    float x = 0.66f, y = -0.66f;

    Arr[0] = 0.2f + x;
    Arr[1] = 0.24f + y;
    Arr[2] = 0.24f + x;
    Arr[3] = 0.2f + y;
    Arr[4] = -0.2f + x;
    Arr[5] = -0.24f + y;
    Arr[6] = -0.24f + x;
    Arr[7] = -0.2f + y;
    Arr[8] = -0.2f + x;
    Arr[9] = -0.24f + y;
    Arr[10] = 0.2f + x;
    Arr[11] = 0.24f + y;

    Arr[12] = -0.2f + x;
    Arr[13] = 0.24f + y;
    Arr[14] = -0.24f + x;
    Arr[15] = 0.2f + y;
    Arr[16] = 0.2f + x;
    Arr[17] = -0.24f + y;
    Arr[18] = 0.24f + x;
    Arr[19] = -0.2f + y;
    Arr[20] = 0.2f + x;
    Arr[21] = -0.24f + y;
    Arr[22] = -0.2f + x;
    Arr[23] = 0.24f + y;
    return Arr;
}
float* centerDownRet(float Arr[24])
{
    float x = 0.0f, y = -0.66f;

    Arr[0] = 0.2f + x;
    Arr[1] = 0.24f + y;
    Arr[2] = 0.24f + x;
    Arr[3] = 0.2f + y;
    Arr[4] = -0.2f + x;
    Arr[5] = -0.24f + y;
    Arr[6] = -0.24f + x;
    Arr[7] = -0.2f + y;
    Arr[8] = -0.2f + x;
    Arr[9] = -0.24f + y;
    Arr[10] = 0.2f + x;
    Arr[11] = 0.24f + y;

    Arr[12] = -0.2f + x;
    Arr[13] = 0.24f + y;
    Arr[14] = -0.24f + x;
    Arr[15] = 0.2f + y;
    Arr[16] = 0.2f + x;
    Arr[17] = -0.24f + y;
    Arr[18] = 0.24f + x;
    Arr[19] = -0.2f + y;
    Arr[20] = 0.2f + x;
    Arr[21] = -0.24f + y;
    Arr[22] = -0.2f + x;
    Arr[23] = 0.24f + y;
    return Arr;
}
float* leftDownRet(float Arr[24])
{
    float x = -0.66f, y = -0.66f;

    Arr[0] = 0.2f + x;
    Arr[1] = 0.24f + y;
    Arr[2] = 0.24f + x;
    Arr[3] = 0.2f + y;
    Arr[4] = -0.2f + x;
    Arr[5] = -0.24f + y;
    Arr[6] = -0.24f + x;
    Arr[7] = -0.2f + y;
    Arr[8] = -0.2f + x;
    Arr[9] = -0.24f + y;
    Arr[10] = 0.2f + x;
    Arr[11] = 0.24f + y;

    Arr[12] = -0.2f + x;
    Arr[13] = 0.24f + y;
    Arr[14] = -0.24f + x;
    Arr[15] = 0.2f + y;
    Arr[16] = 0.2f + x;
    Arr[17] = -0.24f + y;
    Arr[18] = 0.24f + x;
    Arr[19] = -0.2f + y;
    Arr[20] = 0.2f + x;
    Arr[21] = -0.24f + y;
    Arr[22] = -0.2f + x;
    Arr[23] = 0.24f + y;
    return Arr;
}


void DrawCross(float* Arr)
{
    /*This function takes co-ordinates and draw a line using two triangles.*/
    glBegin(GL_TRIANGLES);
    glColor3f(1.f, 0.f, 0.f);
    glVertex2f(Arr[0], Arr[1]);
    glVertex2f(Arr[2], Arr[3]);
    glVertex2f(Arr[4], Arr[5]);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(1.f, 0.f, 0.f);
    glVertex2f(Arr[6], Arr[7]);
    glVertex2f(Arr[8], Arr[9]);
    glVertex2f(Arr[10], Arr[11]);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(1.f, 0.f, 0.f);
    glVertex2f(Arr[12], Arr[13]);
    glVertex2f(Arr[14], Arr[15]);
    glVertex2f(Arr[16], Arr[17]);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(1.f, 0.f, 0.f);
    glVertex2f(Arr[18], Arr[19]);
    glVertex2f(Arr[20], Arr[21]);
    glVertex2f(Arr[22], Arr[23]);
    glEnd();

    turn = 0;

}

void drawCircle(float cx, float cy)
{
    float r = 0.24f;
    int numSegments = 100;
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.2f, 0.2f, 1.0f);
    for (int i = 0; i <= numSegments; i++) {
        float theta = 2.0f * 3.1415926f * float(i) / float(numSegments);
        float x = r * cosf(theta);
        float y = r * sinf(theta);
        glVertex2f(cx + x, cy + y);
    }
    glEnd();
    r = 0.20f;
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(0.f, 0.f, 0.f);
    for (int i = 0; i <= numSegments; i++)
    {
        float theta = 2.0f * 3.1415926f * float(i) / float(numSegments);
        float x = r * cosf(theta);
        float y = r * sinf(theta);
        glVertex2f(cx + x, cy + y);
    }
    glEnd();

    turn = 1;
}

void mouse_button_callback(GLFWwindow* window, int button, int action, int mods)

{
    if (action == GLFW_PRESS) {
        glfwGetCursorPos(window, &xGlobal, &yGlobal);
        //std::cout << "Mouse clicked at position: (" << xGlobal << ", " << yGlobal << ")" << std::endl;
    }
}

void whoWin()
{
    if (
        win[0] == 1 && win[1] == 1 && win[2] == 1 ||
        win[3] == 1 && win[4] == 1 && win[5] == 1 ||
        win[6] == 1 && win[7] == 1 && win[8] == 1 ||
        win[0] == 1 && win[3] == 1 && win[6] == 1 ||
        win[1] == 1 && win[4] == 1 && win[7] == 1 ||
        win[2] == 1 && win[5] == 1 && win[8] == 1 ||
        win[0] == 1 && win[4] == 1 && win[8] == 1 ||
        win[2] == 1 && win[4] == 1 && win[6] == 1
        )
    {
        result = 1;
        //std::cout << "Player 1 Win" << std::endl;

        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
    else if (
        win[0] == 2 && win[1] == 2 && win[2] == 2 ||
        win[3] == 2 && win[4] == 2 && win[5] == 2 ||
        win[6] == 2 && win[7] == 2 && win[8] == 2 ||
        win[0] == 2 && win[3] == 2 && win[6] == 2 ||
        win[1] == 2 && win[4] == 2 && win[7] == 2 ||
        win[2] == 2 && win[5] == 2 && win[8] == 2 ||
        win[0] == 2 && win[4] == 2 && win[8] == 2 ||
        win[2] == 2 && win[4] == 2 && win[6] == 2
        )
    {
        result = 2;
        //std::cout << "Player 2 Win" << std::endl;

        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }
    else if (
        win[0] != 0 && win[1] != 0 && win[2] != 0 &&
        win[3] != 0 && win[4] != 0 && win[5] != 0 &&
        win[6] != 0 && win[7] != 0 && win[8] != 0
        )
    {
        result = 3;
        //std::cout << "It's a tie." << std::endl;
        glfwSetWindowShouldClose(window, GLFW_TRUE);

        win[0] = 0;
        win[1] = 0;
        win[2] = 0;
        win[3] = 0;
        win[4] = 0;
        win[5] = 0;
        win[6] = 0;
        win[7] = 0;
        win[8] = 0;

        check[0] = 0;
        check[1] = 0;
        check[2] = 0;
        check[3] = 0;
        check[4] = 0;
        check[5] = 0;
        check[6] = 0;
        check[7] = 0;
        check[8] = 0;

        xGlobal = 0.00, yGlobal = 0.00;
        turn = 0;
    }
}
void time_delay_intro()

{
    using namespace std::literals::chrono_literals;
    std::string idea = "\tHello Fellas!!\n\tWelcome to a game created by our team...\n\tThank you for opening the program.\n\tPlease Enjoy\n\n";

    int len = idea.length();
    for (int i = 0; i < len; i++) {
        std::cout << idea[i];
        std::this_thread::sleep_for(0.08s);
    }
    std::this_thread::sleep_for(1s);
    //system("cls");
}