void Check_Serial_Input_PIXHAWK() {

  // send data only when you receive data:
  if (Serial.available() > 0) {
    // read the incoming byte:
    int Command_Last = Command;
    Command = Serial.read();
    if (Command == 10) Command = Command_Last;

    // Print Comamnd to Serial Monitor
    if (Command != 0) {
        message_out.print(F(""));
        message_out.print(F(""));
        message_out.println(Command);
        }
  }

Execute_Serial_Command_PIXHAWK();
}


void Execute_Serial_Command_PIXHAWK() {

if (Command == 104) {                   // letter h
    Command = 0;
    message_out.println(F("  "));
    message_out.println(F("  "));
    message_out.println(F("      PIXHAWK HELP MENU"));
    message_out.println(F("      Enter the following letter"));
    message_out.println(F("  -----------------------------"));
    message_out.println(F("  a = ARM"));           //97
    message_out.println(F("  b = AUTO MODE"));       //98
    message_out.println(F("  c = ")); //99
    message_out.println(F("  d = DIS-ARM"));         //100
    message_out.println(F("  e = "));             //101
    message_out.println(F("  f = Follow Mode"));           //102
    message_out.println(F("  g = Guided Mode"));
    message_out.println(F("  h = "));             //104
    message_out.println(F("  i = "));          //105
    message_out.println(F("  j = "));
    message_out.println(F("  k = "));      //107
    message_out.println(F("  l = "));           //108
    message_out.println(F("  m = MANUAL Mode"));
    message_out.println(F("  n = ACRO Mode"));
    message_out.println(F("  o = "));             //111
    message_out.println(F("  p = "));      //112
    message_out.println(F("  q = Quit PIXHAWK Mode"));     //113
    message_out.println(F("  r = "));    //114
    message_out.println(F("  s = "));      //115
    message_out.println(F("  t = "));
    message_out.println(F("  u = "));
    message_out.println(F("  v = "));       //118
    message_out.println(F("  w = "));     //119
    message_out.println(F("  x = "));       //120
    message_out.println(F("  y = "));
    message_out.println(F("  z = "));    //122"));
    message_out.println(F("  "));
    message_out.println(F("  "));


    delay(7000);
    }

if (Command == 97) {                   // letter a
    Command = 0;
    message_out.println("");
    message_out.println("ARMED");
    message_out.println("");
    Command_long_ARM();
    }

if (Command == 100) {                   // letter d
    Command = 0;
    message_out.println("");
    message_out.println("DIS-ARM");
    message_out.println("");
    Command_long_Disarm();
    }

if (Command == 98) {                   // letter b
    Command = 0;
    message_out.println("");
    message_out.println("AUTO MODE");
    message_out.println("");
    Auto_Mode();
    }

if (Command == 102) {                   // letter f
    Command = 0;
    message_out.println("");
    message_out.println("Follow MODE");
    message_out.println("");
    Follow_Mode();
    }

if (Command == 103) {                   // letter f
    Command = 0;
    message_out.println("");
    message_out.println("Guided MODE");
    message_out.println("");
    Guided_Mode();
    }

if (Command == 109) {                   // letter m
    Command = 0;
    message_out.println("");
    message_out.println("Manual MODE");
    message_out.println("");
    Manual_Mode();
    }

if (Command == 110) {                   // letter n
    Command = 0;
    message_out.println("");
    message_out.println("ACRO Mode");
    message_out.println("");
    Acro_Mode();
    }

if (Command == 113) {                   // letter q
    Command = 0;
      message_out.println("");
      message_out.println("Mower set to ReP_AL Mode");
      message_out.println("");
      Mower_Docked = 1;
      Mower_PIXHAWK = 0;
      }

}
