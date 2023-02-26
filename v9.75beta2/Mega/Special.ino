void Special_Cut_Under_Trampoline_Function() {
  //Enter Code Here
}



// after wire tracking the code to bering the mower to a sensible position away from the wire
// This poart of the code should eb modified to fit your garden needs
void Special_Move_Into_Garden_Zone_X() {
    message_out.println(F(""));
    message_out.println(F("Arrived at Exit Zone"));
    message_out.println(F("Moving into Garden"));
    Motor_Action_Stop_Motors();                                     // Stop the wheel motors
    if (CCW_Tracking_To_Start == 1) SetPins_ToTurnLeft();           // Turn left
    if (CW_Tracking_To_Start == 1) SetPins_ToTurnRight();           // Turn Right    
    Motor_Action_Go_Full_Speed();                                       
    delay(400);                                                     // Turn left for 0.7seconds
    Motor_Action_Stop_Motors();                                     // Stop the wheel motors.
    SetPins_ToGoForwards();                                         // Get ready to move off
    }

void Manouver_Exit_From_Docking_Station(){
    #if defined(LCD_KEYPAD)
    lcd.clear();
    lcd.print(F("Exiting Garage"));
    #endif

    message_out.println(F("Exiting Docking Garage"));
    delay(2000);
    SetPins_ToGoBackwards();                                        // Prepare motors pins to go Backwards
    Motor_Action_GoFullSpeed_Out_Garage();                          // Turn the wheels
    message_out.print(F("Left Wheel PWM:"));
    message_out.print(PWM_MaxSpeed_LH);
    message_out.print("|");
    message_out.print(F("Right Wheel PWM:"));
    message_out.println(PWM_MaxSpeed_RH);   
    delay (4000);                                             // Backwards time
    Motor_Action_Stop_Motors();                                       // Stop

    if (CCW_Tracking_To_Start == 1) {
        SetPins_ToTurnLeft();                                           // Prepare motors to turn left
        Motor_Action_Turn_Speed();                                      // Turn the wheels
        delay(500);                                                    // Turn time
        Motor_Action_Stop_Motors();                                       // Stop
        SetPins_ToGoBackwards();                                        // Set again to go backwards
        Motor_Action_Go_Full_Speed();                                   // Turn the wheels
        delay (500);                                                    // Backwards Time
        SetPins_ToTurnLeft();                                           // Set to go left             
        Motor_Action_Turn_Speed();                                      // Turn the wheels
        delay(200);                                                     // Turning time
        Motor_Action_Stop_Motors();                                     // Stop
        }
    if (CW_Tracking_To_Start == 1) {
        SetPins_ToTurnRight();                                           // Prepare motors to turn left
        Motor_Action_Turn_Speed();                                      // Turn the wheels
        delay(500);                                                    // Turn time
        Motor_Action_Stop_Motors();                                       // Stop
        SetPins_ToGoBackwards();                                        // Set again to go backwards
        Motor_Action_Go_Full_Speed();                                   // Turn the wheels
        delay (500);                                                    // Backwards Time
        SetPins_ToTurnRight();                                           // Set to go left             
        Motor_Action_Turn_Speed();                                      // Turn the wheels
        delay(200);                                                     // Turning time
        Motor_Action_Stop_Motors();                                     // Stop
        }
    SetPins_ToGoForwards();                                         // Set to go wheel motor pins to go forwards
    Motor_Action_Stop_Motors();                                     // Stop / Park the mower here

    if ((GPS_Enabled == true) && (GPS_Type == 2) && (Run_PIXHAWK_Mission_At_Exit == true)) {
      message_out.println("");
      message_out.println(F("Mower set to PIXHAWK Mode"));
      message_out.println("");
      Mower_Docked = 0;
      Mower_PIXHAWK = 1;
      message_out.println("");
      message_out.println("ARMED");
      message_out.println("");
      Command_long_ARM();
      message_out.println("");
      message_out.println("AUTO MODE");
      message_out.println("");
      Auto_Mode();
      }

    #if defined(LCD_KEYPAD)
    lcd.clear();                                                    // Clears the LCD display
    lcd.print("Garage Clear");                                      // Prints to the LCD screen       
    delay(500);
    lcd.clear();
    #endif
    
    }



void Specials_Find_Wire_Track()  {

  message_out.println(F(""));
  message_out.println(F("Lost Mower - find wire Track"));
  
  #if defined(LCD_KEYPAD)
  lcd.clear();
  lcd.print("Finding Wire...  ");
  #endif
  
#if defined(WDT)
  wdt_disable(); // disable WDT because of a lot of delay() used or reset WDT after each delay() ???
#endif // -(WDT)-

  Motor_Action_Stop_Spin_Blades();
  delay(5);
  Abort_Wire_Find = 0;
  //No_Wire_Found = 0;
  Running_Test_for_Boundary_Wire();                                                                   // Check to see that the wire is on.

  for (int i = 0; i <= 1; i++) {
    message_out.print(F("Position Try = "));
    message_out.println(i);
    ADCMan.run();
    UpdateWireSensor();
    delay(20);
    ADCMan.run();
    UpdateWireSensor();
    delay(20);
    PrintBoundaryWireStatus();
    //No_Wire_Found = 0;
    Wire_Find_Attempt = 0;  

    // First go backwards if the mower is outside the wire
    if ( inside == false) {                                    // If the mower is outside the wire then run the following code.
      message_out.println("Reversing to find the wire");
      ADCMan.run();
      UpdateWireSensor();
      PrintBoundaryWireStatus();
      Motor_Action_Stop_Motors();                                                           // Stop all wheel motion
      Loop_Cycle_Mowing = 0;
      if ((WIFI_Enabled == 1) && (Manuel_Mode == 0)) Get_WIFI_Commands();    
      delay(1000);
      SetPins_ToGoBackwards();                                                              // Set the mower to back up
      delay(100);
      
      #if defined(LCD_KEYPAD)
      lcd.clear();
      lcd.print("Backwards Try...  ");
      lcd.setCursor(0,1);
      lcd.print("Finding Wire  ");
      delay(100);
      #endif
      
      // While the mower is still outside the boundary wire run this code unless andabort signal from the APP comes or it runs out of tries.
      while (( inside != true) && (Wire_Find_Attempt < 100) ){
        Motor_Action_Go_Full_Speed();                                                       // Go full speed (in this case backwards)
        UpdateWireSensor();                                                                 // Read the wire sensor and see of the mower is now  or outside the wire
        ADCMan.run();
        PrintBoundaryWireStatus();                                                          // Prints of the status of the wire sensor readings.
        message_out.println(F(""));
        Wire_Find_Attempt = Wire_Find_Attempt + 1;                                                      // Counts how many loops have passed to find the wire.
        message_out.print(F("No Wire Count Backwards:"));
        message_out.print(Wire_Find_Attempt);
        message_out.print("|");
        }
      
      }
      
      Motor_Action_Stop_Motors();
      Loop_Cycle_Mowing = 999;
      if (Manuel_Mode == 0) Get_WIFI_Commands();  
      delay(5);
      }
    
    Wire_Find_Attempt = 0; 
    // Code to go forwards until the mower is outside/ON the wire
    if ( inside == true) {             // If the Mower is situated  the wire then run the following code.
        message_out.println(F("Moving Forwards to find the wire"));
        ADCMan.run();
        UpdateWireSensor();
        message_out.println(F("CODE POSITION - MOTOR FORWARDS LOOP:  If statements"));
        PrintBoundaryWireStatus();
        Motor_Action_Stop_Motors();
        Loop_Cycle_Mowing = 999;
        if (Manuel_Mode == 0) Get_WIFI_Commands();  
        delay(1000);  
        SetPins_ToGoForwards();                                                             // Set the motors to move the mower forwards
        delay(100);
        
        #if defined(LCD_KEYPAD)
        lcd.clear();
        lcd.print(F("Forward Try...  "));
        lcd.setCursor(0,1);
        lcd.print(F("Finding Wire  "));
        delay(100);    
        #endif
        
        // resets the cycles
        while (( inside != false) && (Wire_Find_Attempt < 100)) {                               // Move the mower forward until mower is outisde/ON the wire fence or 500 cycles have passed
          Motor_Action_Go_Full_Speed();                                                     // Go full speed (in this case forwards)
          UpdateWireSensor();                                                               // Read the wire sensor and see of the mower is now  or outside the wire
          ADCMan.run();
          PrintBoundaryWireStatus();                                                        // Prints of the status of the wire sensor readings.
          message_out.println(F(""));
          Wire_Find_Attempt = Wire_Find_Attempt + 1;                                                    // Counts how many loops have passed to find the wire.
          message_out.print("No Wire Count Forwards:");
          message_out.print(Wire_Find_Attempt);
          message_out.print("|");
          }
      }
      Motor_Action_Stop_Motors();
      Loop_Cycle_Mowing = 0;
      if (Manuel_Mode == 0) Get_WIFI_Commands();  
      delay(5);
    }
  
