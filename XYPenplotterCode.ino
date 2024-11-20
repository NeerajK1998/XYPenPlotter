#include <Arduino.h>
#include <stdint.h>
#include "SCMD.h"
#include "SCMD_config.h" //Contains #defines for common SCMD register names and values
#include "Wire.h"

SCMD myMotorDriver; //This creates the main object of one motor driver and connected peripherals.

void setup()
{
  pinMode(8, INPUT_PULLUP); //Use to halt motor movement (ground)

  Serial.begin(9600);
  Serial.println("Starting sketch.");

  //***** Configure the Motor Driver's Settings *****//
  //  .commInter face is I2C_MODE 
  myMotorDriver.settings.commInterface = I2C_MODE;

  //  set address if I2C configuration selected with the config jumpers
  myMotorDriver.settings.I2CAddress = 0x5D; //config pattern is "1000" (default) on board for address 0x5D

  //  set chip select if SPI selected with the config jumpers
  myMotorDriver.settings.chipSelectPin = 10;

  //*****initialize the driver get wait for idle*****//
  while ( myMotorDriver.begin() != 0xA9 ) //Wait until a valid ID word is returned
  {
    Serial.println( "ID mismatch, trying again" );
    delay(500);
  }
  Serial.println( "ID matches 0xA9" );

  //  Check to make sure the driver is done looking for peripherals before beginning
  Serial.print("Waiting for enumeration...");
  while ( myMotorDriver.ready() == false );
  Serial.println("Done.");
  Serial.println();

  

  //Uncomment code for motor 0 inversion
  //while( myMotorDriver.busy() );
  //myMotorDriver.inversionMode(0, 1); //invert motor 0

  //Uncomment code for motor 1 inversion
  //while ( myMotorDriver.busy() ); //Waits until the SCMD is available.
  //myMotorDriver.inversionMode(1, 1); //invert motor 1

  while ( myMotorDriver.busy() );
  myMotorDriver.enable(); //Enables the output driver hardware

}

#define LEFT_MOTOR 0
#define RIGHT_MOTOR 1
void loop()
{
  
   for (int i = 0; i < 256; i++) //Line 1
    {
    myMotorDriver.setDrive( LEFT_MOTOR, 0, i);
    myMotorDriver.setDrive( RIGHT_MOTOR, 0,i);
    delay(2);
    }
  for (int i = 255; i >= 0; i--)
    {
    myMotorDriver.setDrive( LEFT_MOTOR, 0,i );
    myMotorDriver.setDrive( RIGHT_MOTOR,0, i );
    delay(2);
    }
  for (int i = 0; i < 256; i++) //Line 2
    {
    myMotorDriver.setDrive( LEFT_MOTOR, 1, i);
    myMotorDriver.setDrive( RIGHT_MOTOR, 0,i);
    delay(3);
    }
  for (int i = 255; i >= 0; i--)
    {
    myMotorDriver.setDrive( LEFT_MOTOR, 1,i );
    myMotorDriver.setDrive( RIGHT_MOTOR,0,i );
    delay(3);
    }
  for (int i = 0; i < 256; i++) //Line 3
    {
    myMotorDriver.setDrive( LEFT_MOTOR, 1, i);
    myMotorDriver.setDrive( RIGHT_MOTOR, 1,i);
    delay(2);
    }
  for (int i = 255; i >= 0; i--)
    {
    myMotorDriver.setDrive( LEFT_MOTOR, 1,i );
    myMotorDriver.setDrive( RIGHT_MOTOR,1, i );
    delay(2);
    }
  for (int i = 0; i < 256; i++) //Line 4
    {
    myMotorDriver.setDrive( LEFT_MOTOR, 0, i);
    myMotorDriver.setDrive( RIGHT_MOTOR, 1,i);
    delay(3);
    }
  for (int i = 255; i >= 0; i--)
    {
    myMotorDriver.setDrive( LEFT_MOTOR, 0,i );
    myMotorDriver.setDrive( RIGHT_MOTOR,1, i );
    delay(3);
    }
  for (int i = 0; i < 256; i++) //Line 5
    {
    myMotorDriver.setDrive( LEFT_MOTOR, 1,0);
    myMotorDriver.setDrive( RIGHT_MOTOR, 0,i);
    delay(5);
    }
  for (int i = 255; i >= 0; i--)
    {
    myMotorDriver.setDrive( LEFT_MOTOR, 1,0 );
    myMotorDriver.setDrive( RIGHT_MOTOR,0, i );
    delay(5);
    }
  for (int i = 0; i < 256; i++) //Line 6
    {
    myMotorDriver.setDrive( LEFT_MOTOR, 0,i);
    myMotorDriver.setDrive( RIGHT_MOTOR, 1,0);
    delay(3.5);
    }
  for (int i = 255; i >= 0; i--)
    {
    myMotorDriver.setDrive( LEFT_MOTOR, 0,i);
    myMotorDriver.setDrive( RIGHT_MOTOR,0, 0 );
    delay(3.5);
    }
  for (int i = 0; i < 256; i++) //Line 7
    {
    myMotorDriver.setDrive( LEFT_MOTOR, 0,0);
    myMotorDriver.setDrive( RIGHT_MOTOR, 1,i);
    delay(2.5);
    }
  for (int i = 255; i >= 0; i--)
    {
    myMotorDriver.setDrive( LEFT_MOTOR, 0,0 );
    myMotorDriver.setDrive( RIGHT_MOTOR,1, i );
    delay(2.5);
    }
  for (int i = 0; i < 256; i++) //Line 8
    {
    myMotorDriver.setDrive( LEFT_MOTOR, 1,i);
    myMotorDriver.setDrive( RIGHT_MOTOR, 0,0);
    delay(5);
    }
  for (int i = 255; i >= 0; i--)
    {
    myMotorDriver.setDrive( LEFT_MOTOR, 1,i );
    myMotorDriver.setDrive( RIGHT_MOTOR,0, 0 );
    delay(5);
    }
  for (int i = 0; i < 256; i++) //Line 2
    {
    myMotorDriver.setDrive( LEFT_MOTOR, 1, i);
    myMotorDriver.setDrive( RIGHT_MOTOR, 0,i);
    delay(2);
    }
  
    
  for (int i = 0; i < 256; i++) //Line 2
    {
    myMotorDriver.setDrive( LEFT_MOTOR, 0, i);
    myMotorDriver.setDrive( RIGHT_MOTOR, 0,i);
    delay(10);
    }
  
}
  

