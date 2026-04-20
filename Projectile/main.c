#include <stdio.h>
#include <math.h>
#ifdef _WIN32
    #include <windows.h>
#endif

#define PI 3.14159265358979323846

//Utility Functions
double to_radians(double angle){
    return angle * (PI / 180);
}

void print_separator() {
    printf("--------------------------------------------\n");
}


int main() {
#ifdef _WIN32
    SetConsoleOutputCP(65001);
#endif


    double v0, angle, gravity, deltaTime;

    printf("--- Projectile Simulator Configuration ---\n");

    do {
        printf("Launch Angle (deg): " );
        scanf("%lf", &angle);
    }while (angle < 0 || angle > 90);

    do {
        printf("Initial Speed(m/s): ");
        scanf("%lf", &v0);
    }while (v0 <= 0);

    do {
        printf("Gravity (m/s²): " );
        scanf("%lf", &gravity);
    }while (gravity <= 0);

    do {
        printf("Time Step (s): ");
        scanf("%lf", &deltaTime);
    }while (deltaTime <= 0);

    //Initial Calculations
    double rad = to_radians(angle);
    double v0x = v0 * cos(rad);
    double v0y = v0 * sin(rad);

    //Input review
    printf("\n-------------------INPUTS-------------------\n");
    printf("\nLaunch Angle (deg): %.0fº\n", angle);
    printf("Initial Speed(m/s): %.2f\n", v0);
    printf("Gravity (m/s²): %.2f\n", gravity);
    printf("Time Step (s): %.2f\n", deltaTime);

    //Simulation table
    printf("\n %-9s | %-12s | %-10s\n", "Time (s)", "Distance (m)", "Height (m)");
    print_separator();

    double t = 0.0;
    double posX, posY;

    do {
        posX = v0x * t;
        posY = (v0y * t) - (0.5 * gravity * t * t);

        if (posY < 0) posY = 0;

        printf(" %-10.2f | %-12.2f | %-10.2f\n", t, posX, posY);

        t += deltaTime;
    }while (posY > 0 || t <= deltaTime);

    //Formulas
    double totalTime = (2 * v0y) / gravity;
    double range = v0x * totalTime;
    double maxHeight = (v0y * v0y) / (2 * gravity);

    //Results
    printf("\n-------------ANALYTICAL RESULTS-------------\n");
    printf("Total range: %.2f (m)\n", range);
    printf("Total time: %.2f (s)\n", totalTime);
    printf("Max height: %.2f (m)\n", maxHeight);

return 0;
}

