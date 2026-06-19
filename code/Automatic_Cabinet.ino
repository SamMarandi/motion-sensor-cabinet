#include <ESP32Servo.h>

const int TRIG_PIN = 5;
const int ECHO_PIN = 18;
const int SERVO_PIN = 19;

Servo myServo;

const float DETECT_DISTANCE = 10.0; // cm

bool isOpen = false;
unsigned long detectStart = 0;
bool timingDetection = false;

float getDistanceCM()
{
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);

    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);

    digitalWrite(TRIG_PIN, LOW);

    long duration = pulseIn(ECHO_PIN, HIGH, 30000);

    if (duration == 0)
        return 999;

    return duration * 0.0343 / 2.0;
}

void openServo()
{
    myServo.write(180);      // clockwise
    delay(300);
    myServo.write(90);       // stop

    isOpen = true;

    Serial.println("OPEN");
}

void closeServo()
{
    myServo.write(0);        // counterclockwise
    delay(500);
    myServo.write(90);       // stop

    isOpen = false;

    Serial.println("CLOSED");
}

void setup()
{
    Serial.begin(115200);

    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);

    myServo.attach(SERVO_PIN);

    myServo.write(90); // stop servo
}

void loop()
{
    float distance = getDistanceCM();

    Serial.print("Distance: ");
    Serial.println(distance);

    if (!isOpen)
    {
        if (distance <= DETECT_DISTANCE)
        {
            if (!timingDetection)
            {
                detectStart = millis();
                timingDetection = true;
            }

            if (millis() - detectStart >= 2000)
            {
                openServo();
                timingDetection = false;
            }
        }
        else
        {
            timingDetection = false;
        }
    }
    else
    {
        while (true)
        {
            distance = getDistanceCM();

            if (distance <= DETECT_DISTANCE)
            {
                delay(100);
                continue;
            }

            unsigned long leaveStart = millis();

            while (millis() - leaveStart < 2000)
            {
                distance = getDistanceCM();

                if (distance <= DETECT_DISTANCE)
                {
                    leaveStart = millis();
                }

                delay(100);
            }

            closeServo();
            break;
        }
    }

    delay(100);
}
