#if (defined(__AVR__))
#include <avr\pgmspace.h>
#else
#include <pgmspace.h>
#endif

#include <SPI.h>
#include "Arduino.h"
//#include "DFRobotDFPlayerMini.h"
#include <SoftwareSerial.h>



/*

 * This is a MFRC522 library example; for further details and other examples see: https://github.com/miguelbalboa/rfid
 * 
 * When the Arduino and the MFRC522 module are connected (see the pin layout below), load this sketch into Arduino IDE
 * then verify/compile and upload it. To see the output: use Tools, Serial Monitor of the IDE (hit Ctrl+Shft+M). When
 * you present a PICC (that is: a RFID Tag or Card) at reading distance of the MFRC522 Reader/PCD, the serial output
 * will show the type, and the NUID if a new card has been detected. Note: you may see "Timeout in communication" messages
 * when removing the PICC from reading distance too early.
 * 
 * @license Released into the public domain.
 * 
 * Typical pin layout used:
 * -----------------------------------------------------------------------------------------
 *             MFRC522      Arduino       Arduino   Arduino    Arduino          Arduino
 *             Reader/PCD   Uno/101       Mega      Nano v3    Leonardo/Micro   Pro Micro
 * Signal      Pin          Pin           Pin       Pin        Pin              Pin
 * -----------------------------------------------------------------------------------------
 * RST/Reset   RST          9             5         D9         RESET/ICSP-5     RST
 * SPI SS      SDA(SS)      10            53        D10        10               10
 * SPI MOSI    MOSI         11 / ICSP-4   51        D11        ICSP-4           16
 * SPI MISO    MISO         12 / ICSP-1   50        D12        ICSP-1           14
 * SPI SCK     SCK          13 / ICSP-3   52        D13        ICSP-3           15
 */


#define TIME_STEP 500
#define SONG_LENGTH 24

#define KNIGHT_PIN     8

#define SS_PIN 10
#define RST_PIN 9

/* Song data */
//const unsigned char PROGMEM songData[SONG_LENGTH_16] =
//  {0x8F,0x00,0x34,0xC3,0x28,0x00,0xEC,0x24};

const unsigned char songData[SONG_LENGTH] =
  {1,1,1,1,1,1,1,0,
   0,0,0,0,0,1,0,1,
   0,0,1,1,0,0,1,1};


//SoftwareSerial mySoftwareSerial(6, 7); // RX, TX
//DFRobotDFPlayerMini myDFPlayer;




void setup()
{

  pinMode(KNIGHT_PIN, OUTPUT);
  //pinMode(7, OUTPUT);

  //digitalWrite(7, HIGH);

  //SPI.begin(); // Init SPI bus



  Serial.begin(9600);



 // mySoftwareSerial.begin(9600);
//  delay(2000);

  //Serial.println();
//  Serial.println(F("DFRobot DFPlayer Mini Demo"));
//  Serial.println(F("Initializing DFPlayer ... (May take 3~5 seconds)"));

  //if (!myDFPlayer.begin(mySoftwareSerial)) {  //Use softwareSerial to communicate with mp3.
  //  Serial.println(F("Unable to begin:"));
  //  Serial.println(F("1.Please recheck the connection!"));
  //  Serial.println(F("2.Please insert the SD card!"));
  //  while(true);
 // }
 // Serial.println(F("DFPlayer Mini online."));

//  myDFPlayer.volume(15);  //Set volume value. From 0 to 30
}


void play_song()
{
  for(int i = 0; i < SONG_LENGTH; i++)
  {
    //Serial.println("I");
    //for(int j = 0; j < 8; j++)
    {
      if (songData[i] > 0)
      {
        digitalWrite(KNIGHT_PIN, HIGH);
        Serial.println("HIGH");
      }
      else
      {
        digitalWrite(KNIGHT_PIN, LOW);
        Serial.println("LOW");
      }
      delay(TIME_STEP);
    }
  }
  digitalWrite(KNIGHT_PIN, LOW);
  Serial.println("LOW");
  
}



//unsigned int track_num_current = 0;

void loop()
{
  

  play_song();

  delay(5000);


  
  //if(myDFPlayer.readCurrentFileNumber() == 0) //read current play file number
  //  digitalWrite(RECORD_PIN, LOW);

  // myDFPlayer.playMp3Folder(matched_character);

  //    if (myDFPlayer.available()) 
  //    {
  //      printDetail(myDFPlayer.readType(), myDFPlayer.read()); //Print the detail message from DFPlayer to handle different errors and states.
  //    } 



  //Serial.println(myDFPlayer.readState()); //read mp3 state
  //Serial.println(myDFPlayer.readCurrentFileNumber()); //read current play file number
  



  
}



/*********************************************************************************************************
  END FILE
*********************************************************************************************************/
