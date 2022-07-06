#include "mbed.h"
#include "LCD.h"

// Bitte aufpassen, MF-Shield bentzt dieses PIN, also MF-Shield nicht benutzen
// wenn Sie MF-Shield brauchen, dann PC_2, oder PC_03 benutzen
AnalogIn alkohol_sensor(PA_0);

lcd my_lcd;

//Direkte prinft(), werden an Serial-angezeigt, z.B. mithilfe der Putty COM??, 9600


int main()
{
    printf("------------------------------\n");
    printf("Alkohol Tester v1.0\n");
    printf("------------------------------\n");
    printf("Blutalkohol bisch 0,25 ischt gut, aber dannoch ischt koin spoß mehr\n");
    printf("------------------------------\n\n\n");


    float akzeptiert_alkohol = 0.25f;
    float alkohol = 0.0f;
    bool ist_besoffen = false;
    my_lcd.clear();
    while (true) {
        alkohol = alkohol_sensor.read();
        printf("Blutalkohol ist %.2f\n", alkohol);
        my_lcd.cursorpos(0);
        my_lcd.printf("Alkohol: %.2f", alkohol);

        if(alkohol <= akzeptiert_alkohol){    
            printf("Es geht schon\n");
            my_lcd.cursorpos(64);
            my_lcd.printf("Es geht schon   ");
        } else {
            printf("Du b15cht v011 bes0f3n\n");
            my_lcd.cursorpos(64);
            my_lcd.printf("du b15 beS50ffen");
        }

        ThisThread::sleep_for(1000ms);
    }

}

