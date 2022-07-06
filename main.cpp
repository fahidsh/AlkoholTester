#include "mbed.h"

float pi = 3.14f;
/* Serial Verbindung an 9600, anstatt 115200 */
int main()
{
    printf("Comman Zahlen in Mbed ausdrucken\n");
    printf("------------------------------\n");
    printf("bitte beachten Sie die datei: mbed_app.json\n");
    printf("------------------------------\n");
    printf("Wert von PI ist %.4f\n", pi);
    printf("Wert von 17/3 ist %.4f\n", 17.0/3.0);

    float rand_zahl = 0.0f;
    
    while (true) {
        rand_zahl = rand()/3.14;
        printf("Zufallzahl: %.4f\n", ((float)rand_zahl/3.14));
        ThisThread::sleep_for(1000ms);
    }

}