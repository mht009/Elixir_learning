#if defined(ESP32)
#include <WiFi.h>
#include <FirebaseESP32.h>
// #elif defined(ESP8266)
// #include <ESP8266WiFi.h>
// #include <FirebaseESP8266.h>
#endif

#define P

// Provide the token generation process info.
#include <addons/TokenHelper.h>

// Provide the RTDB payload printing info and other helper functions.
#include <addons/RTDBHelper.h>

/* 1. Define the WiFi credentials */
#define WIFI_SSID "mht009"
#define WIFI_PASSWORD "kmzr0000"

// For the following credentials, see examples/Authentications/SignInAsUser/EmailPassword/EmailPassword.ino

/* 2. Define the API Key */
#define API_KEY "AIzaSyDW9v98-UqTVEa4vtUa8wemnNndPdkWAjI"

/* 3. Define the RTDB URL */
#define DATABASE_URL "https://lab-automation-v1-default-rtdb.firebaseio.com" //<databaseName>.firebaseio.com or <databaseName>.<region>.firebasedatabase.app

// Define Firebase Data object
FirebaseData fbdo;

FirebaseAuth auth;
FirebaseConfig config;

int a, b, x, y;

// Declaring pins
// room1
#define R1_TL1 18 // r1_im1
#define R1_FN1 18 // r1_im2
#define R1_TL2 18 // r1_im3
#define R1_TL3 18 // r1_im4
#define R1_FN2 18 // r1_im5
#define R1_TL4 18 // r1_im6
#define R1_TL5 18 // r1_im7
#define R1_FN3 18 // r1_im8
#define R1_TL6 18 // r1_im9

// room2
#define R2_TL1 18 // r2_im1
#define R2_FN1 18 // r2_im2
#define R2_TL2 18 // r2_im3
#define R2_TL3 18 // r2_im4
#define R2_FN2 18 // r2_im5
#define R2_TL4 18 // r2_im6

// room2
#define R3_TL1 18 // r3_im1
#define R3_FN1 18 // r3_im2
#define R3_TL2 18 // r3_im3

// Defining variables to store firebase data
bool r1_im1;
bool r1_im2;
bool r1_im3;
bool r1_im4;
bool r1_im5;
bool r1_im6;
bool r1_im7;
bool r1_im8;
bool r1_im9;

bool r2_im1;
bool r2_im2;
bool r2_im3;
bool r2_im4;
bool r2_im5;
bool r2_im6;

bool r3_im1;
bool r3_im2;
bool r3_im3;

void setup()
{

    // Setting Wifi connection
    Serial.begin(115200);
    delay(2000);
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
    Serial.print("Connecting to Wi-Fi");
    while (WiFi.status() != WL_CONNECTED)
    {
        Serial.print(".");
        delay(300);
    }
    Serial.println();
    Serial.print("Connected with IP: ");
    Serial.println(WiFi.localIP());
    Serial.println();

    Serial.printf("Firebase Client v%s\n\n", FIREBASE_CLIENT_VERSION);

    /* Assign the api key (required) */
    config.api_key = API_KEY;

    config.database_url = DATABASE_URL;

    //////////////////////////////////////////////////////////////////////////////////////////////
    // Please make sure the device free Heap is not lower than 80 k for ESP32 and 10 k for ESP8266,
    // otherwise the SSL connection will fail.
    //////////////////////////////////////////////////////////////////////////////////////////////

    Firebase.begin(DATABASE_URL, API_KEY);

    // Comment or pass false value when WiFi reconnection will control by your code or third party library
    //  Firebase.reconnectWiFi(true);

    Firebase.setDoubleDigits(5);

    //  Setting pins
    // room1
    pinMode(R1_TL1, OUTPUT);
    pinMode(R1_FN1, OUTPUT);
    pinMode(R1_TL2, OUTPUT);
    pinMode(R1_TL3, OUTPUT);
    pinMode(R1_FN2, OUTPUT);
    pinMode(R1_TL4, OUTPUT);
    pinMode(R1_TL5, OUTPUT);
    pinMode(R1_FN3, OUTPUT);
    pinMode(R1_TL6, OUTPUT);

    // room2
    pinMode(R2_TL1, OUTPUT);
    pinMode(R2_FN1, OUTPUT);
    pinMode(R2_TL2, OUTPUT);
    pinMode(R2_TL3, OUTPUT);
    pinMode(R2_FN2, OUTPUT);
    pinMode(R2_TL4, OUTPUT);

    // room3
    pinMode(R3_TL1, OUTPUT);
    pinMode(R3_FN1, OUTPUT);
    pinMode(R3_TL2, OUTPUT);
}

void loop()
{
    if (Firebase.ready())
    {
        //    fetching data from database
        // Room1
        Firebase.getBool(fbdo, "/Room1/im1/state") ? r1_im1 = fbdo.to<bool>() : Serial.println(fbdo.errorReason().c_str());
        Firebase.getBool(fbdo, "/Room1/im2/state") ? r1_im2 = fbdo.to<bool>() : Serial.println(fbdo.errorReason().c_str());
        Firebase.getBool(fbdo, "/Room1/im3/state") ? r1_im3 = fbdo.to<bool>() : Serial.println(fbdo.errorReason().c_str());
        Firebase.getBool(fbdo, "/Room1/im4/state") ? r1_im4 = fbdo.to<bool>() : Serial.println(fbdo.errorReason().c_str());
        Firebase.getBool(fbdo, "/Room1/im5/state") ? r1_im5 = fbdo.to<bool>() : Serial.println(fbdo.errorReason().c_str());
        Firebase.getBool(fbdo, "/Room1/im6/state") ? r1_im6 = fbdo.to<bool>() : Serial.println(fbdo.errorReason().c_str());
        Firebase.getBool(fbdo, "/Room1/im7/state") ? r1_im7 = fbdo.to<bool>() : Serial.println(fbdo.errorReason().c_str());
        Firebase.getBool(fbdo, "/Room1/im8/state") ? r1_im8 = fbdo.to<bool>() : Serial.println(fbdo.errorReason().c_str());
        Firebase.getBool(fbdo, "/Room1/im9/state") ? r1_im9 = fbdo.to<bool>() : Serial.println(fbdo.errorReason().c_str());

        // Room2
        Firebase.getBool(fbdo, "/Room2/im1/state") ? r2_im1 = fbdo.to<bool>() : Serial.println(fbdo.errorReason().c_str());
        Firebase.getBool(fbdo, "/Room2/im2/state") ? r2_im2 = fbdo.to<bool>() : Serial.println(fbdo.errorReason().c_str());
        Firebase.getBool(fbdo, "/Room2/im3/state") ? r2_im3 = fbdo.to<bool>() : Serial.println(fbdo.errorReason().c_str());
        Firebase.getBool(fbdo, "/Room2/im4/state") ? r2_im4 = fbdo.to<bool>() : Serial.println(fbdo.errorReason().c_str());
        Firebase.getBool(fbdo, "/Room2/im5/state") ? r2_im5 = fbdo.to<bool>() : Serial.println(fbdo.errorReason().c_str());
        Firebase.getBool(fbdo, "/Room2/im6/state") ? r2_im6 = fbdo.to<bool>() : Serial.println(fbdo.errorReason().c_str());

        // Room3
        Firebase.getBool(fbdo, "/Room3/im1/state") ? r3_im1 = fbdo.to<bool>() : Serial.println(fbdo.errorReason().c_str());
        Firebase.getBool(fbdo, "/Room3/im2/state") ? r3_im2 = fbdo.to<bool>() : Serial.println(fbdo.errorReason().c_str());
        Firebase.getBool(fbdo, "/Room3/im3/state") ? r3_im3 = fbdo.to<bool>() : Serial.println(fbdo.errorReason().c_str());

        Serial.print("r1_im1: ");
        Serial.print(r1_im1);
        Serial.print(" | ");

        Serial.print("r1_im2: ");
        Serial.print(r1_im2);
        Serial.print(" | ");

        Serial.print("r1_im3: ");
        Serial.print(r1_im3);
        Serial.print(" | ");

        Serial.print("r1_im4: ");
        Serial.print(r1_im4);
        Serial.print(" | ");

        Serial.print("r1_im5: ");
        Serial.print(r1_im5);
        Serial.print(" | ");

        Serial.print("r1_im6: ");
        Serial.print(r1_im6);
        Serial.print(" | ");

        Serial.print("r1_im7: ");
        Serial.print(r1_im7);
        Serial.print(" | ");

        Serial.print("r1_im8: ");
        Serial.print(r1_im8);
        Serial.print(" | ");

        Serial.print("r1_im9: ");
        Serial.print(r1_im9);
        Serial.print(" | ");

        Serial.print("r2_im1: ");
        Serial.print(r2_im1);
        Serial.print(" | ");

        Serial.print("r2_im2: ");
        Serial.print(r2_im2);
        Serial.print(" | ");

        Serial.print("r2_im3: ");
        Serial.print(r2_im3);
        Serial.print(" | ");

        Serial.print("r2_im4: ");
        Serial.print(r2_im4);
        Serial.print(" | ");

        Serial.print("r2_im5: ");
        Serial.print(r2_im5);
        Serial.print(" | ");

        Serial.print("r2_im6: ");
        Serial.print(r2_im6);
        Serial.print(" | ");

        Serial.print("r3_im1: ");
        Serial.print(r3_im1);
        Serial.print(" | ");

        Serial.print("r3_im2: ");
        Serial.print(r3_im2);
        Serial.print(" | ");

        Serial.print("r3_im3: ");
        Serial.print(r3_im3);
        Serial.print(" | ");

        Serial.println();
        Serial.println("------------------");
    }
}

void changeState(bool state, int pinNo)
{
    if (state)
    {
        digitalWrite(pinNo, HIGH);
    }
    else
    {
        digitalWrite(pinNo, LOW);
    }
}