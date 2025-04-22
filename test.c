#include <stdio.h>
#include <sys/time.h>
#include <unistd.h> // pour sleep

double get_time_seconds()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (double)tv.tv_sec + (double)tv.tv_usec / 1000000.0;
}

int main()
{
    double lastTime = get_time_seconds();
    double deltaTime;

    while (1)
	{
        double currentTime = get_time_seconds();
        deltaTime = currentTime - lastTime;
        lastTime = currentTime;

        printf("Delta time: %.6f secondes\n", deltaTime);

        // Simule un travail ou une frame à 60 FPS
        usleep(16000); // pause de ~16ms
    }

    return 0;
}
