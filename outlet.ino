/*********************************************************************************
 *  Jimi Hayes
 *  
 *  Following open source code used with expressly given consent by the writers
 *  
 *  https://github.com/HomeSpan/HomeSpan
 *  
 *  
 ********************************************************************************/
 


#include "HomeSpan.h"         
#include "DEV_PLUG.h"

void setup() {                
 
  Serial.begin(115200);       // Start a serial connection so you can receive HomeSpan diagnostics and control the device using HomeSpan's Command-Line Interface (CLI)

  homeSpan.begin(Category::Lighting,"IOT Powerstrip");   // initializes a HomeSpan device named "IOT Powerstrip" with Category set to Lighting

  new SpanAccessory();                            // This first Accessory is a "Bridge" Accessory.  It contains no functional Services, just the Accessory Information Service
    new Service::AccessoryInformation();
      new Characteristic::Identify();
  
  new SpanAccessory();                             

    new Service::AccessoryInformation();            // HAP requires every Accessory to implement an AccessoryInformation Service  
      new Characteristic::Identify();               // Create the required Identify Characteristic      
      new Characteristic::Name("Plug 1");
    new DEV_PLUG(13);                               //creates a new plug object named plug 1 controlled by pin 13

  new SpanAccessory();                              

    new Service::AccessoryInformation();            // HAP requires every Accessory to implement an AccessoryInformation Service  
      new Characteristic::Identify();               // Create the required Identify Characteristic      
      new Characteristic::Name("Plug 2");           //creates a new plug object named plug 2 controlled by pin 4
    new DEV_PLUG(4);

} // end of setup()

//////////////////////////////////////

void loop(){
  
  homeSpan.poll();         
  
} // end of loop()
