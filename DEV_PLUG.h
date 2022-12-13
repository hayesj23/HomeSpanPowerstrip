
////////////////////////////////////
//   DEVICE-SPECIFIC LED SERVICES //
////////////////////////////////////

// HERE'S WHERE WE DEFINE OUR NEW OUTLET SERVICE

struct DEV_PLUG : Service::Outlet {               // First we create a derived class from the HomeSpan Outlet Service

  int plugPin;                                       // this variable stores the pin number defined for this plug
  SpanCharacteristic *power;                        // here we create a generic pointer to a SpanCharacteristic named "power" that we will use below

  // Next we define the constructor for DEV_PLUG.  Note that it takes one argument, plugPin,
  // which specifies the pin by which the plug is controlled.
  
  DEV_PLUG(int plugPin) : Service::Outlet(){

    power=new Characteristic::On();                 
    new Characteristic::OutletInUse();
    this->plugPin=plugPin;                            // don't forget to store plugPin...
    pinMode(plugPin,OUTPUT);                         // ...and set the mode for plugPin to be an OUTPUT (standard Arduino function)
    
  } // end constructor

  // Finally, we over-ride the default update() method with instructions that actually turn on/off the outlet.  Note update() returns type boolean

  boolean update(){            

    digitalWrite(plugPin,power->getNewVal());        // use a standard Arduino function to turn on/off plugPin based on the return of a call to power->getNewVal() (see below for more info)
   
    return(true);                                   
  
  } // update
};
      
