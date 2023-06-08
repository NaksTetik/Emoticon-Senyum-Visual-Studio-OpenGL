#include <gl/glut.h>
#include <math.h>
#include <GL/gl.h>

bool isRightEyeOpen = true;  // flag to control the right eye blink

// gambar lingkaran menggunakan segitiga
void drawCircle(float cx, float cy, float r, int num_segments) {
    glBegin(GL_TRIANGLE_FAN);
    for (int i = 0; i < num_segments; i++) {
        float theta = 2.0f * 3.1415926f * float(i) / float(num_segments);
        float x = r * cosf(theta);
        float y = r * sinf(theta);
        glVertex2f(x + cx, y + cy);
    }
    glEnd();
}

void blinkRightEye(int value) {
    isRightEyeOpen = !isRightEyeOpen;  // Toggle the state of the right eye
    glutPostRedisplay();  // Request redrawing of the scene
    glutTimerFunc(1000, blinkRightEye, 0);  // Schedule the next blink after 1 second
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // kuningan wajah
    glColor3f(1.0f, 1.0f, 0.0f);
    drawCircle(0.0f, 0.0f, 0.8f, 360);

    // mata kiri
    glColor3f(0.0f, 0.0f, 0.0f);

    drawCircle(-0.3f, 0.3f, 0.1f, 360);

    // Mata Kanan
    if (isRightEyeOpen) {
        drawCircle(0.3f, 0.3f, 0.1f, 360);
    }

    // Draw the rosy cheeks
    glColor3f(1.0f, 0.6f, 0.6f);
    drawCircle(-0.5f, -0.4f, 0.15f, 360);
    drawCircle(0.5f, -0.4f, 0.15f, 360);

    glutSwapBuffers();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 800);
    glutCreateWindow("Emot Terdiam");
    glutDisplayFunc(display);

    // mata kanan kedip
    glutTimerFunc(1000, blinkRightEye, 0);

    glutMainLoop();
    return 0;
}
