// The forst block/address of the dueFlashStorage is either 1 or 0.  
// If information is stored = 1, then the rest of the EEPROM values for that
// block are loaded into the global variable values.


void Load_EEPROM_Saved_Data() {

  #if defined(BOARD_MEGA)

message_out.println("Loading EEPROM / Settings");

  int Robot_Type_EEPROM = EEPROM.read(121);
  if (Robot_Type_EEPROM == 1) {
    Robot_Type = EEPROM.read(122); 
    message_out.print(F("EEPROM: Robot_Type: "));
    if (Robot_Type == 1) message_out.println(F("= Mower"));
    if (Robot_Type == 2) message_out.println(F("= Aerator"));
  }

  if (Robot_Type_EEPROM != 1) {
    if (Robot_Type == 1) message_out.println(F("Settings: Robot Type = Mower"));
    if (Robot_Type == 2) message_out.println(F("Settings: Robot Type = Aerator"));
  }


  int PCB_EEPROM = EEPROM.read(119);
  if (PCB_EEPROM == 1) {
    PCB = EEPROM.read(120); 
    message_out.print(F("EEPROM: PCB Enabled: "));
      if (PCB == 1) message_out.println(F("Enabled"));
      if (PCB == 0) message_out.println(F("Disabled"));
      }

  if (PCB_EEPROM != 1) {
    message_out.print(F("Settings: PCB Enabled: "));
      if (PCB == 1) message_out.println(F("Enabled"));
      if (PCB == 0) message_out.println(F("Disabled"));
      }

 
  int Alarm_1_Saved_EEPROM = EEPROM.read(1);
  
  if (Alarm_1_Saved_EEPROM == 1) {
    Alarm_1_Hour    = EEPROM.read(2);
    Alarm_1_Minute  = EEPROM.read(3);
    Alarm_1_ON      = EEPROM.read(4);
    Alarm_1_Action  = EEPROM.read(87);

    if (Alarm_1_Hour == 255)   {
      Alarm_1_Hour = 0;
      Alarm_1_ON = 0;
      }
    if (Alarm_1_Minute == 255) {
      Alarm_1_Minute = 0;
      Alarm_1_ON  = 0;
      }
    
    if (Alarm_1_ON == 0)  message_out.println("Alarm 1 : OFF");
 
    if (Alarm_1_ON == 1) {
      message_out.print(F("EEPROM Alarm 1 Active | Time Set:"));
      message_out.print(Alarm_1_Hour);
      message_out.print(F(":"));
      if (Alarm_1_Minute < 10) message_out.print("0");
      message_out.print(Alarm_1_Minute);
      message_out.print(" | Action :");
      if (Alarm_1_Action == 1) message_out.println("Exit Zone 1");
      if (Alarm_1_Action == 2) message_out.println("Exit Zone 2");
      if (Alarm_1_Action == 3) message_out.println("Mow the Line");
      if (Alarm_1_Action == 4) message_out.println("Quick Start");
      if (Alarm_1_Action == 5) message_out.println("Custom");
      }
    }
  if (Alarm_1_Saved_EEPROM != 1) {
    if (Alarm_1_ON == 1) {
      message_out.print(F("Settings: Alarm 1 Active | Time Set:"));
      message_out.print(Alarm_1_Hour);
      message_out.print(F(":"));
      if (Alarm_1_Minute < 10) message_out.print("0");
      message_out.print(Alarm_1_Minute);
      message_out.print(" | Action :");
      if (Alarm_1_Action == 1) message_out.println("Exit Zone 1");
      if (Alarm_1_Action == 2) message_out.println("Exit Zone 2");
      if (Alarm_1_Action == 3) message_out.println("Mow the Line");
      if (Alarm_1_Action == 4) message_out.println("Quick Start");
      if (Alarm_1_Action == 5) message_out.println("Custom");
      }
  }
    
  int Alarm_2_Saved_EEPROM = EEPROM.read(5);
  
  if (Alarm_2_Saved_EEPROM == 1) {
    Alarm_2_Hour    = EEPROM.read(6);
    Alarm_2_Minute  = EEPROM.read(7);
    Alarm_2_ON      = EEPROM.read(8);
    Alarm_2_Action  = EEPROM.read(88);
    
    if (Alarm_2_Hour == 255)   {
      Alarm_2_Hour = 0;
      Alarm_2_ON = 0;
      }
    if (Alarm_2_Minute == 255) {
      Alarm_2_Minute = 0;
      Alarm_2_ON  = 0;
      }
    
    if (Alarm_2_ON == 0) message_out.println("Alarm 2 : OFF:");
    
    if (Alarm_2_ON == 1) {
      message_out.print(F("Alarm 2 Active | Time Set:"));
      message_out.print(Alarm_2_Hour);
      message_out.print(F(":"));
      if (Alarm_2_Minute < 10) message_out.print("0");
      message_out.print(Alarm_2_Minute);  
      message_out.print(" | Action :");
      if (Alarm_2_Action == 1) message_out.println("Exit Zone 1");
      if (Alarm_2_Action == 2) message_out.println("Exit Zone 2");
      if (Alarm_2_Action == 3) message_out.println("Mow the Line");
      if (Alarm_2_Action == 4) message_out.println("Quick Start");
      if (Alarm_2_Action == 5) message_out.println("Custom");
      }

    }

  if (Alarm_2_Saved_EEPROM != 1) {
    if (Alarm_2_ON == 1) {
      message_out.print(F("Settings: Alarm 2 Active | Time Set:"));
      message_out.print(Alarm_2_Hour);
      message_out.print(F(":"));
      if (Alarm_2_Minute < 10) message_out.print("0");
      message_out.print(Alarm_2_Minute);
      message_out.print(" | Action :");
      if (Alarm_2_Action == 1) message_out.println("Exit Zone 1");
      if (Alarm_2_Action == 2) message_out.println("Exit Zone 2");
      if (Alarm_2_Action == 3) message_out.println("Mow the Line");
      if (Alarm_2_Action == 4) message_out.println("Quick Start");
      if (Alarm_2_Action == 5) message_out.println("Custom");
      }
  }


  int Alarm_3_Saved_EEPROM = EEPROM.read(9);
  
  if (Alarm_3_Saved_EEPROM == 1) {
    Alarm_3_Hour    = EEPROM.read(10);
    Alarm_3_Minute  = EEPROM.read(11);
    Alarm_3_ON      = EEPROM.read(12);
    Alarm_3_Action  = EEPROM.read(89);

    if (Alarm_3_Hour == 255)   {
      Alarm_3_Hour = 0;
      Alarm_3_ON = 0;
      }
    if (Alarm_3_Minute == 255) {
      Alarm_3_Minute = 0;
      Alarm_3_ON  = 0;
      }
    
    
    if (Alarm_3_ON == 0) message_out.println("Alarm 3 : OFF: ");
   
    if (Alarm_3_ON == 1) {
      message_out.print(F("Alarm 3 Active | Time Set:"));
      message_out.print(Alarm_3_Hour);
      message_out.print(F(":"));
      if (Alarm_3_Minute < 10) message_out.print("0");
      message_out.print(Alarm_3_Minute);
      message_out.print(" | Action :");
      if (Alarm_3_Action == 1) message_out.println("Exit Zone 1");
      if (Alarm_3_Action == 2) message_out.println("Exit Zone 2");
      if (Alarm_3_Action == 3) message_out.println("Mow the Line");
      if (Alarm_3_Action == 4) message_out.println("Quick Start");
      if (Alarm_3_Action == 5) message_out.println("Custom");  
      }

    }

  if (Alarm_3_Saved_EEPROM != 1) {
    if (Alarm_3_ON == 1) {
      message_out.print(F("Settings: Alarm 3 Active | Time Set:"));
      message_out.print(Alarm_3_Hour);
      message_out.print(F(":"));
      if (Alarm_3_Minute < 10) message_out.print("0");
      message_out.print(Alarm_3_Minute);
      message_out.print(" | Action :");
      if (Alarm_3_Action == 1) message_out.println("Exit Zone 1");
      if (Alarm_3_Action == 2) message_out.println("Exit Zone 2");
      if (Alarm_3_Action == 3) message_out.println("Mow the Line");
      if (Alarm_3_Action == 4) message_out.println("Quick Start");
      if (Alarm_3_Action == 5) message_out.println("Custom");
      }
  }
    

  int PWM_LEFT_EEPROM = EEPROM.read(13);
  if (PWM_LEFT_EEPROM == 1) {
    PWM_MaxSpeed_LH = EEPROM.read(14);
    message_out.print(F("EEPROM PWM Wheel Left value : "));
    message_out.println(PWM_MaxSpeed_LH);
  }

  if (PWM_LEFT_EEPROM != 1) {
    message_out.print(F("Settings: PWM Wheel Left value: "));
    message_out.println(PWM_MaxSpeed_LH);
    }

  int PWM_RIGHT_EEPROM = EEPROM.read(15);
  if (PWM_RIGHT_EEPROM == 1) {
    PWM_MaxSpeed_RH = EEPROM.read(16); 
    message_out.print(F("EEPROM: PWM Wheel Right value: ")); 
    message_out.println(PWM_MaxSpeed_RH);
  }

  if (PWM_RIGHT_EEPROM != 1) {
    message_out.print(F("Settings: PWM Wheel Right value: ")); 
    message_out.println(PWM_MaxSpeed_RH);
  }

  int PWM_LEFT_Slow_EEPROM = EEPROM.read(94);
  if (PWM_LEFT_Slow_EEPROM == 1) {
    PWM_Slow_Speed_LH = EEPROM.read(95);
    message_out.print(F("EEPROM: PWM Wheel Slow Left value: "));
    message_out.println(PWM_Slow_Speed_LH);
  }

  if (PWM_LEFT_Slow_EEPROM != 1) {
    message_out.print(F("Settings: PWM Wheel Slow Left value: "));
    message_out.println(PWM_Slow_Speed_LH);
  }

  int PWM_RIGHT_Slow_EEPROM = EEPROM.read(96);
  if (PWM_RIGHT_Slow_EEPROM == 1) {
    PWM_Slow_Speed_RH = EEPROM.read(97); 
    message_out.print(F("EEPROM: PWM Wheel Slow Right value: ")); 
    message_out.println(PWM_Slow_Speed_RH);
  }

  if (PWM_RIGHT_Slow_EEPROM != 1) {
    //PWM_Slow_Speed_RH = EEPROM.read(97);
    message_out.print(F("Settings: PWM Wheel Slow Right value: ")); 
    message_out.println(PWM_Slow_Speed_RH);
  }
  
  int Slow_Speed_MAG_EEPROM = EEPROM.read(98);
  if (Slow_Speed_MAG_EEPROM == 1) {
    Slow_Speed_MAG = EEPROM.read(99); 
    Slow_Speed_MAG = (Slow_Speed_MAG * -1 ) * 10;
    message_out.print(F("EEPROM: Slow Speed MAG: ")); 
    message_out.println(Slow_Speed_MAG);
  }

 if (Slow_Speed_MAG_EEPROM == 1) {
    message_out.print(F("Settings: Slow Speed MAG: ")); 
    message_out.println(Slow_Speed_MAG);
  }


  int PWM_BLADE_EEPROM = EEPROM.read(17);
  if (PWM_BLADE_EEPROM == 1) {
    PWM_Blade_Speed = EEPROM.read(18); 
    message_out.print(F("EEPROM: PWM Blade value: ")); 
    message_out.println(PWM_Blade_Speed);
  }

  if (PWM_BLADE_EEPROM != 1) {
    message_out.print(F("Settings: PWM Blade value: ")); 
    message_out.println(PWM_Blade_Speed);
  }


  int COMPASS_EEPROM = EEPROM.read(19);
  if (COMPASS_EEPROM == 1) {
    Compass_Activate = EEPROM.read(20);  
    message_out.print(F("EEPROM: Compass Activated: "));
    if (Compass_Activate == 0) message_out.println(F("OFF"));
    if (Compass_Activate == 1) message_out.println(F("ON"));
  }

  if (COMPASS_EEPROM != 1) {
    message_out.print(F("Settings: Compass Activated: "));
    if (Compass_Activate == 0) message_out.println(F("OFF"));
    if (Compass_Activate == 1) message_out.println(F("ON"));
  }

  int COMPASS_Setup_Mode_EEPROM = EEPROM.read(113);
  if (COMPASS_Setup_Mode_EEPROM == 1) {
    Compass_Setup_Mode = EEPROM.read(114);  
    message_out.print(F("EEPROM: Compass Setup Mode: "));
   if (Compass_Setup_Mode == 1) message_out.println(F("Setup DFRobot_QMC5883 Compass"));
   if (Compass_Setup_Mode == 2) message_out.println(F("Setup QMC5883_Manual Compass"));           
   if (Compass_Setup_Mode == 3) message_out.println(F("Setup QMC5883L Compass"));      
   }

  if (COMPASS_Setup_Mode_EEPROM != 1) {
    message_out.print(F("Settings: Compass Setup Mode: "));
   if (Compass_Setup_Mode == 1) message_out.println(F("Setup DFRobot_QMC5883 Compass"));
   if (Compass_Setup_Mode == 2) message_out.println(F("Setup QMC5883_Manual Compass"));           
   if (Compass_Setup_Mode == 3) message_out.println(F("Setup QMC5883L Compass"));      
   }

  int Compass_Heading_Hold_Enabled_EEPROM = EEPROM.read(59);
  if (Compass_Heading_Hold_Enabled_EEPROM == 1) {
    Compass_Heading_Hold_Enabled = EEPROM.read(60);  
    message_out.print(F("EEPROM: Compass Heading Hold: "));
    if (Compass_Heading_Hold_Enabled == 0) message_out.println(F("OFF"));
    if (Compass_Heading_Hold_Enabled == 1) message_out.println(F("ON"));
  }

  if (Compass_Heading_Hold_Enabled_EEPROM != 1) {
    message_out.print(F("Settings: Compass Heading Hold: "));
    if (Compass_Heading_Hold_Enabled == 0) message_out.println(F("OFF"));
    if (Compass_Heading_Hold_Enabled == 1) message_out.println(F("ON"));
  }

  int CPower_EEPROM = EEPROM.read(61);
  if (CPower_EEPROM == 1) {
    CPower = EEPROM.read(62); 
    CPower = CPower / 10; 
    message_out.print(F("EEPROM: Compass Power: "));
    message_out.println(CPower);
  }

  if (CPower_EEPROM != 1) {
    CPower = CPower; 
    message_out.print(F("Settings: Compass Power: "));
    message_out.println(CPower);
  }

  int Compass_Home_EEPROM = EEPROM.read(27);
  if (Compass_Home_EEPROM == 1) {
    Home_Wire_Compass_Heading = (EEPROM.read(28) * 10);    // *10 as value can be more than 255. Vaule is therefore stored as a tenth value
    message_out.print(F("EEPROM: Compass Home Degrees : ")); 
    message_out.println(Home_Wire_Compass_Heading);
  }

  if (Compass_Home_EEPROM != 1) {
    message_out.print(F("Settings: Compass Home Degrees : ")); 
    message_out.println(Home_Wire_Compass_Heading);
  }

 int Tracking_PID_P_EEPROM = EEPROM.read(21);
  if (Tracking_PID_P_EEPROM == 1) {
    P = EEPROM.read(22); 
    P = P / 100; 
    message_out.print(F("EEPROM: Traking PID P: "));
    message_out.println(P);
  }


  if (Tracking_PID_P_EEPROM != 1) {
    message_out.print(F("Settings: Traking PID P: "));
    message_out.println(P);
  }

  int Pattern_Mow_EEPROM = EEPROM.read(23);
  if (Pattern_Mow_EEPROM == 1) {
    Pattern_Mow = EEPROM.read(24);  
    //Pattern_Mow = 1;
    message_out.print(F("EEPROM: Pattern Mow Type: "));
    if (Pattern_Mow == 0) message_out.println(F("OFF"));
    if (Pattern_Mow == 1) message_out.println(F("ON Parallel"));
    if (Pattern_Mow == 2) message_out.println(F("ON Spiral"));
  }

  if (Pattern_Mow_EEPROM != 1) {
    message_out.print(F("Settings: Pattern Mow Type: "));
    if (Pattern_Mow == 0) message_out.println(F("OFF"));
    if (Pattern_Mow == 1) message_out.println(F("ON Parallel"));
    if (Pattern_Mow == 2) message_out.println(F("ON Spiral"));
  }


  int Minimum_Volt_EEPROM = EEPROM.read(25);
  if (Minimum_Volt_EEPROM == 1) {
    Battery_Min = EEPROM.read(26); 
    Battery_Min = Battery_Min / 10; 
    message_out.print(F("EEPROM: Minimum Battery Voltage: "));
    message_out.println(Battery_Min);
  }

  if (Minimum_Volt_EEPROM != 1) {
    message_out.print(F("Settings: Minimum Battery Voltage: "));
    message_out.println(Battery_Min);
  }


  int Angle_Sensor_Enabled_EEPROM = EEPROM.read(29);
  if (Angle_Sensor_Enabled_EEPROM == 1) {
    Angle_Sensor_Enabled = EEPROM.read(30);  
    message_out.print(F("EEPROM: Angle Sensor Enabled: "));
    if (Angle_Sensor_Enabled == 0) message_out.println(F("OFF"));
    if (Angle_Sensor_Enabled == 1) message_out.println(F("ON"));
  }

  if (Angle_Sensor_Enabled_EEPROM != 1) {
    message_out.print(F("Settings: Angle Sensor Enabled: "));
    if (Angle_Sensor_Enabled == 0) message_out.println(F("OFF"));
    if (Angle_Sensor_Enabled == 1) message_out.println(F("ON"));
  }


  int Tip_Over_Sensor_Enabled_EEPROM = EEPROM.read(92);
  if (Tip_Over_Sensor_Enabled_EEPROM == 1) {
    Tip_Over_Sensor_Enabled = EEPROM.read(93);  
    message_out.print(F("EEPROM Tip Sensor Enabled:  "));
    if (Tip_Over_Sensor_Enabled == 0) message_out.println(F("OFF"));
    if (Tip_Over_Sensor_Enabled == 1) message_out.println(F("ON"));
  }

  if (Tip_Over_Sensor_Enabled_EEPROM != 1) {
    message_out.print(F("Settings: Tip Sensor Enabled:  "));
    if (Tip_Over_Sensor_Enabled == 0) message_out.println(F("OFF"));
    if (Tip_Over_Sensor_Enabled == 1) message_out.println(F("ON"));
  }

  
  int Mower_Turn_Delay_Min_EEPROM = EEPROM.read(31);
  if (Mower_Turn_Delay_Min_EEPROM == 1) {
    Mower_Turn_Delay_Min = EEPROM.read(32);
    Mower_Turn_Delay_Min = Mower_Turn_Delay_Min * 100;
    message_out.print(F("EEPROM: Mower Turn Delay Min: "));
    message_out.println(Mower_Turn_Delay_Min);
  }

  if (Mower_Turn_Delay_Min_EEPROM != 1) {
    message_out.print(F("Settings: Mower Turn Delay Min: "));
    message_out.println(Mower_Turn_Delay_Min);
  }


  int Mower_Turn_Delay_Max_EEPROM = EEPROM.read(33);
  if (Mower_Turn_Delay_Max_EEPROM == 1) {
    Mower_Turn_Delay_Max = EEPROM.read(34);
    Mower_Turn_Delay_Max =  Mower_Turn_Delay_Max * 100; 
    message_out.print(F("EEPROM: Mower Turn Delay Max: "));
    message_out.println(Mower_Turn_Delay_Max);
  }


  if (Mower_Turn_Delay_Max_EEPROM != 1) {
    message_out.print(F("Settings: Mower Turn Delay Max: "));
    message_out.println(Mower_Turn_Delay_Max);
  }


  int Mower_Reverse_Delay_EEPROM = EEPROM.read(35);
  if (Mower_Reverse_Delay_EEPROM == 1) {
    Mower_Reverse_Delay = EEPROM.read(36);
    Mower_Reverse_Delay = (Mower_Reverse_Delay * 100);
    message_out.print(F("EEPROM: Mower Reverse Time Delay/ms: "));
    message_out.println(Mower_Reverse_Delay);
  }

  if (Mower_Reverse_Delay_EEPROM != 1) {
    message_out.print(F("Settings: Mower Reverse Time Delay/ms: "));
    message_out.println(Mower_Reverse_Delay);
  }



  int Track_Wire_Zone_1_Cycles_EEPROM = EEPROM.read(43);
  if (Track_Wire_Zone_1_Cycles_EEPROM == 1) {
    Track_Wire_Zone_1_Cycles = EEPROM.read(44);
    Track_Wire_Zone_1_Cycles = (Track_Wire_Zone_1_Cycles * 100);
    message_out.print(F("EEPROM: Zone 1 Tracking Cycles "));
    message_out.println(Track_Wire_Zone_1_Cycles);
  }

  if (Track_Wire_Zone_1_Cycles_EEPROM != 1) {
    message_out.print(F("Settings: Zone 1 Tracking Cycles "));
    message_out.println(Track_Wire_Zone_1_Cycles);
  }

  int Track_Wire_Zone_2_Cycles_EEPROM = EEPROM.read(45);
  if (Track_Wire_Zone_2_Cycles_EEPROM == 1) {
    Track_Wire_Zone_2_Cycles = EEPROM.read(46);
    Track_Wire_Zone_2_Cycles = (Track_Wire_Zone_2_Cycles * 100);
    message_out.print(F("EEPROM: Zone 2 Tracking Cycles "));
    message_out.println(Track_Wire_Zone_2_Cycles);
  }

  if (Track_Wire_Zone_2_Cycles_EEPROM != 1) {
    message_out.print(F("Settings: Zone 2 Tracking Cycles "));
    message_out.println(Track_Wire_Zone_2_Cycles);
  }


  int Use_Charging_Station_EEPROM = EEPROM.read(47);
  if (Use_Charging_Station_EEPROM == 1) {
    Use_Charging_Station = EEPROM.read(48);  
    message_out.print(F("EEPROM: Charge Station: "));
    if (Use_Charging_Station == 0) message_out.println(F("OFF"));
    if (Use_Charging_Station == 1) message_out.println(F("ON"));
  }

  if (Use_Charging_Station_EEPROM != 1) {
    message_out.print(F("Settings: Charge Station: "));
    if (Use_Charging_Station == 0) message_out.println(F("OFF"));
    if (Use_Charging_Station == 1) message_out.println(F("ON"));
  }


  int CW_Tracking_To_Charge_EEPROM = EEPROM.read(49);
  if (CW_Tracking_To_Charge_EEPROM == 1) {
    CW_Tracking_To_Charge = EEPROM.read(50);  
    message_out.print(F("EEPROM: Tracking Direction to Charge : "));
    if (CW_Tracking_To_Charge == 1) message_out.println(F("CW"));
    if (CW_Tracking_To_Charge == 0) message_out.println(F("OFF"));
  }


  if (CW_Tracking_To_Charge_EEPROM != 1) {
    message_out.print(F("Settings: Tracking Direction to Charge : "));
    if (CW_Tracking_To_Charge == 1) message_out.println(F("CW"));
    if (CW_Tracking_To_Charge == 0) message_out.println(F("OFF"));
  }

  int CCW_Tracking_To_Charge_EEPROM = EEPROM.read(51);
  if (CCW_Tracking_To_Charge_EEPROM == 1) {
    CCW_Tracking_To_Charge = EEPROM.read(52);  
    message_out.print(F("EEPROM Tracking Direction to Charge : "));
    if (CCW_Tracking_To_Charge == 1) message_out.println(F("CCW"));
    if (CCW_Tracking_To_Charge == 0) message_out.println(F("OFF"));
  }

  if (CCW_Tracking_To_Charge_EEPROM != 1) {
    message_out.print(F("Settings: Tracking Direction to Charge : "));
    if (CCW_Tracking_To_Charge == 1) message_out.println(F("CCW"));
    if (CCW_Tracking_To_Charge == 0) message_out.println(F("OFF"));
  }


  int CW_Tracking_To_Start_EEPROM = EEPROM.read(53);
  if (CW_Tracking_To_Start_EEPROM == 1) {
    CW_Tracking_To_Start = EEPROM.read(54);  
    message_out.print(F("EEPROM: Tracking Direction to Start : "));
    if (CW_Tracking_To_Start == 1) message_out.println(F("CW"));
    if (CW_Tracking_To_Start == 0) message_out.println(F("OFF"));
  }

  if (CW_Tracking_To_Start_EEPROM != 1) {
    message_out.print(F("Settings: Tracking Direction to Start : "));
    if (CW_Tracking_To_Start == 1) message_out.println(F("CW"));
    if (CW_Tracking_To_Start == 0) message_out.println(F("OFF"));
  }


  int CCW_Tracking_To_Start_EEPROM = EEPROM.read(55);
  if (CCW_Tracking_To_Start_EEPROM == 1) {
    CCW_Tracking_To_Start = EEPROM.read(56);  
    message_out.print(F("EERPOM: Tracking Direction to Start : "));
    if (CCW_Tracking_To_Start == 1) message_out.println(F("CCW"));
    if (CCW_Tracking_To_Start == 0) message_out.println(F("OFF"));
  }

  if (CCW_Tracking_To_Start_EEPROM != 1) {
    message_out.print(F("Settings: Tracking Direction to Start : "));
    if (CCW_Tracking_To_Start == 1) message_out.println(F("CCW"));
    if (CCW_Tracking_To_Start == 0) message_out.println(F("OFF"));
  }

  int Max_Cycles_Straight_EEPROM = EEPROM.read(57);
  if (Max_Cycles_Straight_EEPROM == 1) {
    Max_Cycles_Straight = EEPROM.read(58);
    Max_Cycles_Straight = (Max_Cycles_Straight * 10);
    message_out.print(F("EEPROM: Straight Line Cycles before turn: "));
    message_out.println(Max_Cycles_Straight);
  }

  if (Max_Cycles_Straight_EEPROM != 1) {
    message_out.print(F("Settings: Straight Line Cycles before turn: "));
    message_out.println(Max_Cycles_Straight);
  }

  int Sonar_1_Activate_EEPROM = EEPROM.read(37);
  if (Sonar_1_Activate_EEPROM == 1) {
    Sonar_1_Activate = EEPROM.read(38);
    message_out.print(F("EEPROM: Sonar 1 Activated: "));
    message_out.println(Sonar_1_Activate);
  }

  if (Sonar_1_Activate_EEPROM != 1) {
    message_out.print(F("Settings: Sonar 1 Activated: "));
    message_out.println(Sonar_1_Activate);
  }

  int Sonar_2_Activate_EEPROM = EEPROM.read(39);
  if (Sonar_2_Activate_EEPROM == 1) {
    Sonar_2_Activate = EEPROM.read(40);
    message_out.print(F("EEPROM: Sonar 2 Activated: "));
    message_out.println(Sonar_2_Activate);
  }

  if (Sonar_2_Activate_EEPROM != 1) {
    message_out.print(F("Settings: Sonar 2 Activated: "));
    message_out.println(Sonar_2_Activate);
  }

  int Sonar_3_Activate_EEPROM = EEPROM.read(41);
  if (Sonar_3_Activate_EEPROM == 1) {
    Sonar_3_Activate = EEPROM.read(42);
    message_out.print(F("EEPROM: Sonar 3 Activated: "));
    message_out.println(Sonar_3_Activate);
  }

  if (Sonar_3_Activate_EEPROM != 1) {
    message_out.print(F("Settings: Sonar 3 Activated: "));
    message_out.println(Sonar_3_Activate);
  }

  int Max_Sonar_Hit_EEPROM = EEPROM.read(63);
  if (Max_Sonar_Hit_EEPROM == 1) {
    Max_Sonar_Hit = EEPROM.read(64); 
    message_out.print(F("EEPROM: Sonar Sensitivity: "));
    message_out.println(Max_Sonar_Hit);
  }

  if (Max_Sonar_Hit_EEPROM != 1) {
    message_out.print(F("Settings: Sonar Sensitivity: "));
    message_out.println(Max_Sonar_Hit);
  }

  int maxdistancesonar_EEPROM = EEPROM.read(65);
  if (maxdistancesonar_EEPROM == 1) {
    maxdistancesonar = EEPROM.read(66); 
    message_out.print(F("EEPROM: Sonar Activation Distance: "));
    message_out.println(maxdistancesonar);
  }

  if (maxdistancesonar_EEPROM != 1) {
    message_out.print(F("Settings: Sonar Activation Distance: "));
    message_out.println(maxdistancesonar);
  }

  int Perimeter_Wire_Enabled_EEPROM = EEPROM.read(67);
  if (Perimeter_Wire_Enabled_EEPROM == 1) {
    Perimeter_Wire_Enabled = EEPROM.read(68);  
    message_out.print(F("EEPROM: Wire Module ON/OFF: "));
    if (Perimeter_Wire_Enabled == 0) message_out.println(F("OFF"));
    if (Perimeter_Wire_Enabled == 1) message_out.println(F("ON"));
  }

  if (Perimeter_Wire_Enabled_EEPROM != 1) {
    message_out.print(F("Settings: Wire Module ON/OFF: "));
    if (Perimeter_Wire_Enabled == 0) message_out.println(F("OFF"));
    if (Perimeter_Wire_Enabled == 1) message_out.println(F("ON"));
  }


  int Max_Cycle_Wire_Find_EEPROM = EEPROM.read(69);
  if (Max_Cycle_Wire_Find_EEPROM == 1) {
    Max_Cycle_Wire_Find = EEPROM.read(70);
    Max_Cycle_Wire_Find = (Max_Cycle_Wire_Find * 10);
    message_out.print(F("EEPROM: Track Cycles Forwards to find Wire "));
    message_out.println(Max_Cycle_Wire_Find);
  }


  if (Max_Cycle_Wire_Find_EEPROM != 1) {
    message_out.print(F("Settings: Track Cycles Forwards to find Wire "));
    message_out.println(Max_Cycle_Wire_Find);
  }


  int Max_Cycle_Wire_Find_Back_EEPROM = EEPROM.read(71);
  if (Max_Cycle_Wire_Find_Back_EEPROM == 1) {
    Max_Cycle_Wire_Find_Back = EEPROM.read(72);
    Max_Cycle_Wire_Find_Back = (Max_Cycle_Wire_Find_Back * 10);
    message_out.print(F("EEPROM: Track Cycles Back to find Wire "));
    message_out.println(Max_Cycle_Wire_Find_Back);
  }


  if (Max_Cycle_Wire_Find_Back_EEPROM != 1) {
    message_out.print(F("Settings: Track Cycles Back to find Wire "));
    message_out.println(Max_Cycle_Wire_Find_Back);
  }


  int Max_Tracking_Turn_Right_EEPROM = EEPROM.read(73);
  if (Max_Tracking_Turn_Right_EEPROM == 1) {
    Max_Tracking_Turn_Right = EEPROM.read(74);
    Max_Tracking_Turn_Right = (Max_Tracking_Turn_Right * 10);
    message_out.print(F("EEPROM: Wheel RH Cycles before restart "));
    message_out.println(Max_Tracking_Turn_Right);
  }

  if (Max_Tracking_Turn_Right_EEPROM != 1) {
    message_out.print(F("Settings: Wheel RH Cycles before restart "));
    message_out.println(Max_Tracking_Turn_Right);
  }



  int Max_Tracking_Turn_Left_EEPROM = EEPROM.read(75);
  if (Max_Tracking_Turn_Left_EEPROM == 1) {
    Max_Tracking_Turn_Left = EEPROM.read(76);
    Max_Tracking_Turn_Left = (Max_Tracking_Turn_Left * 10);
    message_out.print(F("EEPROM: Wheel LH Cycles before restart "));
    message_out.println(Max_Tracking_Turn_Left);
  }


  if (Max_Tracking_Turn_Left_EEPROM != 1) {
    message_out.print(F("Settings: Wheel LH Cycles before restart "));
    message_out.println(Max_Tracking_Turn_Left);
  }


  int Rain_Sensor_Installed_EEPROM = EEPROM.read(77);
  if (Rain_Sensor_Installed_EEPROM == 1) {
    Rain_Sensor_Installed = EEPROM.read(78);  
    message_out.print(F("EEPROM: Rain Sensor ON/OFF:  "));
    if (Rain_Sensor_Installed == 0) message_out.println(F("OFF"));
    if (Rain_Sensor_Installed == 1) message_out.println(F("ON"));
  }


  if (Rain_Sensor_Installed_EEPROM != 1) {
    message_out.print(F("Settings: Rain Sensor ON/OFF: "));
    if (Rain_Sensor_Installed == 0) message_out.println(F("OFF"));
    if (Rain_Sensor_Installed == 1) message_out.println(F("ON"));
  }


  int Rain_Total_Hits_Go_Home_EEPROM = EEPROM.read(79);
  if (Rain_Total_Hits_Go_Home_EEPROM == 1) {
    Rain_Total_Hits_Go_Home = EEPROM.read(80); 
    message_out.print(F("Settings: Rain Sensitivity: "));
    message_out.println(Rain_Total_Hits_Go_Home);
  }

  if (Rain_Total_Hits_Go_Home_EEPROM != 1) {
    message_out.print(F("Settings: Rain Sensitivity: "));
    message_out.println(Rain_Total_Hits_Go_Home);
  }

  int WIFI_Enabled_EEPROM = EEPROM.read(81);
  if (WIFI_Enabled_EEPROM == 1) {
    WIFI_Enabled = EEPROM.read(82);  
    message_out.print(F("EEPROM: WIFI Enabled: "));
    if (WIFI_Enabled == 0) message_out.println(F("OFF"));
    if (WIFI_Enabled == 1) message_out.println(F("ON"));
  }

  if (WIFI_Enabled_EEPROM != 1) {
    message_out.print(F("Settings: WIFI Enabled: "));
    if (WIFI_Enabled == 0) message_out.println(F("OFF"));
    if (WIFI_Enabled == 1) message_out.println(F("ON"));
  }

  int Cutting_Blades_Activate_EEPROM = EEPROM.read(83);
  if (Cutting_Blades_Activate_EEPROM == 1) {
    Cutting_Blades_Activate = EEPROM.read(84);  
    message_out.print(F("EEPROM: CUTTING BLADE Motor SET TO : "));
    if (Cutting_Blades_Activate == 0) message_out.println(F("OFF"));
    if (Cutting_Blades_Activate == 1) message_out.println(F("ON"));
  }


  if (Cutting_Blades_Activate_EEPROM != 1) {
    message_out.print(F("Settings: CUTTING BLADE Motor SET TO : "));
    if (Cutting_Blades_Activate == 0) message_out.println(F("OFF"));
    if (Cutting_Blades_Activate == 1) message_out.println(F("ON"));
  }

  int Low_Battery_Instances_Chg_EEPROM = EEPROM.read(85);
  if (Low_Battery_Instances_Chg_EEPROM == 1) {
    Low_Battery_Instances_Chg = EEPROM.read(86); 
    message_out.print(F("EEPROM: Battery to Charge Sensitivity: "));
    message_out.println(Low_Battery_Instances_Chg);
  }

  if (Low_Battery_Instances_Chg_EEPROM != 1) {
    message_out.print(F("Settings: Battery to Charge Sensitivity: "));
    message_out.println(Low_Battery_Instances_Chg);
  }


  int Bumper_Activate_Frnt_EEPROM = EEPROM.read(90);
  if (Bumper_Activate_Frnt_EEPROM == 1) {
    Bumper_Activate_Frnt = EEPROM.read(91);  
    message_out.print(F("EEPROM: Bumper Bar Enabled: "));
    if (Bumper_Activate_Frnt == 0) message_out.println(F("OFF"));
    if (Bumper_Activate_Frnt == 1) message_out.println(F("ON"));
  }

  if (Bumper_Activate_Frnt_EEPROM != 1) {
    message_out.print(F("Settings: Bumper Bar Enabled: "));
    if (Bumper_Activate_Frnt == 0) message_out.println(F("OFF"));
    if (Bumper_Activate_Frnt == 1) message_out.println(F("ON"));
  }


  int Turn_90_Delay_LH_EEPROM = EEPROM.read(101);
  if (Turn_90_Delay_LH_EEPROM == 1) {
    Turn_90_Delay_LH = EEPROM.read(102);  
    Turn_90_Delay_LH = Turn_90_Delay_LH * 10;
    message_out.print(F("EEPROM: Turn_90_Delay_LH Enabled: "));
    message_out.println(Turn_90_Delay_LH);
  }

  if (Turn_90_Delay_LH_EEPROM != 1) {
    message_out.print(F("Settings: Turn_90_Delay_LH Enabled: "));
    message_out.println(Turn_90_Delay_LH);
  }


  int Turn_90_Delay_RH_EEPROM = EEPROM.read(103);
  if (Turn_90_Delay_RH_EEPROM == 1) {
    Turn_90_Delay_RH = EEPROM.read(104);  
    Turn_90_Delay_RH = Turn_90_Delay_RH * 10;
    message_out.print(F("EEPROM: Turn_90_Delay_RH Enabled: "));
    message_out.println(Turn_90_Delay_RH);
  }

  if (Turn_90_Delay_RH_EEPROM != 1) {
    message_out.print(F("Settings: Turn_90_Delay_RH Enabled: "));
    message_out.println(Turn_90_Delay_RH);
  }


  int Line_Length_Cycles_EEPROM = EEPROM.read(105);
  if (Line_Length_Cycles_EEPROM == 1) {
    Line_Length_Cycles = EEPROM.read(106);  
    Line_Length_Cycles = Line_Length_Cycles * 10;
    message_out.print(F("EEPROM: Line_Length_Cycles Enabled: "));
    message_out.println(Line_Length_Cycles);
  }


  if (Line_Length_Cycles_EEPROM != 1) {
    message_out.print(F("Settings: Line_Length_Cycles Enabled: "));
    message_out.println(Line_Length_Cycles);
  }



  int GPS_Enabled_EEPROM = EEPROM.read(107);
  if (GPS_Enabled_EEPROM == 1) {
    GPS_Enabled = EEPROM.read(108);  
    message_out.print(F("EEPROM: GPS: "));
    if (GPS_Enabled == 0) message_out.println(F("Disabled"));
    if (GPS_Enabled == 1) message_out.println(F("Enabled"));
  }

  if (GPS_Enabled_EEPROM != 1) {
    message_out.print(F("Settings: GPS: "));
    if (GPS_Enabled == 0) message_out.println(F("Disabled"));
    if (GPS_Enabled == 1) message_out.println(F("Enabled"));
  }

 int GPS_Type_EEPROM = EEPROM.read(125);
  if (GPS_Type_EEPROM == 1) {
    GPS_Type = EEPROM.read(126);  
    message_out.print(F("EEPROM: GPS_Type: "));
    if (GPS_Type == 1) message_out.println(F("ReP_AL"));
    if (GPS_Type == 2) message_out.println(F("PIXHAWK"));
    if (GPS_Type == 3) message_out.println(F("SPARE"));
  }

  if (GPS_Type_EEPROM != 1) {
    message_out.print(F("Settings: GPS_Type: "));
    if (GPS_Type == 1) message_out.println(F("ReP_AL"));
    if (GPS_Type == 2) message_out.println(F("PIXHAWK"));
    if (GPS_Type == 3) message_out.println(F("SPARE"));
  }

  int GYRO_Enabled_EEPROM = EEPROM.read(109);
  if (GYRO_Enabled_EEPROM == 1) {
    GYRO_Enabled = EEPROM.read(110);  
    message_out.print(F("EEPROM: GYRO Enabled: "));
    if (GYRO_Enabled == 0) message_out.println(F("Disabled"));
    if (GYRO_Enabled == 1) message_out.println(F("Enabled"));
  }

  if (GYRO_Enabled_EEPROM != 1) {
    message_out.print(F("Settings: GYRO Enabled: "));
    if (GYRO_Enabled == 0) message_out.println(F("Disabled"));
    if (GYRO_Enabled == 1) message_out.println(F("Enabled"));
  }

  
  int GPower_EEPROM = EEPROM.read(111);
  if (GPower_EEPROM == 1) {
    GPower = EEPROM.read(112); 
    GPower = GPower / 10; 
    message_out.print(F("EEPROM: GYRO PID : "));
    message_out.println(GPower);
  }

  if (GPower_EEPROM != 1) {
    message_out.print(F("Settings: GYRO PID : "));
    message_out.println(GPower);
  }

  int Wheel_Amp_Sensor_ON_Enabled_EEPROM = EEPROM.read(115);
  if (Wheel_Amp_Sensor_ON_Enabled_EEPROM == 1) {
    Wheel_Amp_Sensor_ON = EEPROM.read(116);  
    message_out.print(F("EEPROM: Wheel Block Amp Sensor Enabled: "));
    if (Wheel_Amp_Sensor_ON == 0) message_out.println(F("Disabled"));
    if (Wheel_Amp_Sensor_ON == 1) message_out.println(F("Enabled"));
  }


  if (Wheel_Amp_Sensor_ON_Enabled_EEPROM != 1) {
    message_out.print(F("Settings: Wheel Block Amp Sensor Enabled: "));
    if (Wheel_Amp_Sensor_ON == 0) message_out.println(F("Disabled"));
    if (Wheel_Amp_Sensor_ON == 1) message_out.println(F("Enabled"));
  }

  
  int Max_Wheel_Amps_EEPROM = EEPROM.read(117);
  if (Max_Wheel_Amps_EEPROM == 1) {
    Max_Wheel_Amps = EEPROM.read(118); 
    Max_Wheel_Amps = Max_Wheel_Amps / 10; 
    message_out.print(F("EEPROM: Wheel Block Amps: "));
    message_out.println(Max_Wheel_Amps);
  }

  if (Max_Wheel_Amps_EEPROM != 1) {
    Max_Wheel_Amps = Max_Wheel_Amps; 
    message_out.print(F("Settings: Wheel Block Amps: "));
    message_out.println(Max_Wheel_Amps);
  }

  int Wheels_Enabled_EEPROM = EEPROM.read(123);
  if (Wheels_Enabled_EEPROM == 1) {
	Wheels_Activate = EEPROM.read(124);
    message_out.print(F("Wheels Enabled from EEPROM : "));
      if (Wheels_Activate == 1) message_out.println(F("Enabled"));
      if (Wheels_Activate == 0) message_out.println(F("Disabled"));
  }
  
  if (Wheels_Enabled_EEPROM != 1) {
    message_out.print(F("Wheels Enabled from EEPROM : "));
      if (Wheels_Activate == 1) message_out.println(F("Enabled"));
      if (Wheels_Activate == 0) message_out.println(F("Disabled"));
  }
  
  if (Boost_Turn == 1) {
    message_out.println(F("Settings: Boost Turn Activated"));
    message_out.print(F("Min Track PWM = "));
    message_out.println(Min_Track_PWM);
    message_out.print(F("Boost Time = "));
    message_out.println(Hard_Track_Turn_Delay);
        
  }
  if (Boost_Turn == 0) message_out.print(F("Settings: Boost Turn OFF"));

  message_out.println(F(""));






message_out.println(F("*********** DONE **************"));
 delay(500);

#endif
}


void Clear_EERPOM_Data() {

  #if defined(BOARD_MEGA)

  message_out.println(F(""));
  message_out.println(F("CLEARING EEPROM Data"));
  message_out.println(F(""));
  
  EEPROM.write(1,0);      // Clear Alarm 1
  EEPROM.write(5,0);      // Clear Alarm 2
  EEPROM.write(9,0);      // Clear Alarm 3
  EEPROM.write(13,0);     // Clear PWM Left Wheel
  EEPROM.write(15,0);     // Clear PWM Right Wheel
  EEPROM.write(17,0);     // Clear PWM Blade
  EEPROM.write(19,0);     // Clear Compass Setting EEPROM
  EEPROM.write(21,0);     // Clear PID Setting
  EEPROM.write(23,0);     // Clear Pattern Mow
  EEPROM.write(25,0);     // Clear Volt Minimum
  EEPROM.write(27,0);     // Clear Compass Home
  EEPROM.write(29,0);     // Clear Tilt Tip Safety
  EEPROM.write(31,0);     // Clear Turn Time Min
  EEPROM.write(33,0);     // Clear Turn Time Max
  EEPROM.write(35,0);     // Clear Reverse Time
  EEPROM.write(37,0);     // Clear Sonar 1
  EEPROM.write(39,0);     // Clear Sonar 2
  EEPROM.write(41,0);     // Clear Sonar 3
  EEPROM.write(43,0);     // Clear Zone 1 Cycles
  EEPROM.write(45,0);     // Clear Zone 2 Cycles
  EEPROM.write(47,0);     // Clear Charging Station Options
  EEPROM.write(49,0);     // Reset CW and CCW Exit and Dock Directions
  EEPROM.write(51,0);     //  CW CCW Tracking
  EEPROM.write(53,0);     //  CW CCW Tracking
  EEPROM.write(55,0);     //  CW CCW Tracking
  EEPROM.write(57,0);     // Max Cycle Straight
  EEPROM.write(59,0);     // Compass Heading HOld ON/OFF
  EEPROM.write(61,0);     // Compass PID reset.
  EEPROM.write(63,0);     // Sonar sensitivity.
  EEPROM.write(65,0);      // MAx distance sonar reset.
  EEPROM.write(67,0);     // Wire Sensor ON/OFF
  EEPROM.write(69,0);     // Track cycles Forwards
  EEPROM.write(71,0);     // Track Cycles Back
  EEPROM.write(73,0);     // RH Cycles to restart
  EEPROM.write(75,0);     // LH Cycles to restart
  EEPROM.write(77,0);     // Rain ON/OFF
  EEPROM.write(79,0);     // Rain sensitivity
  EEPROM.write(81,0);     // WIFI ON/OFF
  EEPROM.write(83,0);     // Cutting Blades ON/OFF
  EEPROM.write(85,0);     // Batt sensitivity;
  EEPROM.write(87,0);     // Alarm Actions 1-3
  EEPROM.write(88,0);
  EEPROM.write(89,0);
  EEPROM.write(90,0);     // Bumper Bar
  EEPROM.write(92,0);     // Tip Over sensor
  EEPROM.write(94,0);     // Wheel Slow Speed LH
  EEPROM.write(96,0);     // Wheel Slow Speed RH
  EEPROM.write(98,0);     // Slow MAG Point
  EEPROM.write(102,0);    // Turn_90_Delay_LH 
  EEPROM.write(104,0);    // Turn_90_Delay_RH
  EEPROM.write(106,0);    // Line_Length_Cycles
  EEPROM.write(107,0);    // GPS Enabled
  EEPROM.write(109,0);    // GYRO Enabled
  EEPROM.write(111,0);    // GYRO Power
  EEPROM.write(113,0);    // Compass Setup Mode
  EEPROM.write(115,0);    // Wheel amp sensor 
  EEPROM.write(117,0);    // Wheel amp sensor value
  EEPROM.write(119,0);    // PCB
  EEPROM.write(121,0);    // Robot Type
  EEPROM.write(123,0);    // Wheel ON/OFF
  EEPROM.write(125,0);    // GPS_Type
  
  message_out.println(F(""));
  message_out.println(F("EEPROM CLEARED"));
  message_out.println(F(""));
  
  #endif
  
}
