void Read_Serial1_Nano() {

  if (Mower_PIXHAWK == 0) {

	byte recvBuff [11] = {0};

	if (SerialCom1.update ())
	{
	  byte length = SerialCom1.getLength ();
	  if (length > sizeof (recvBuff)) length = sizeof (recvBuff);
	  memcpy (&recvBuff, SerialCom1.getData (), length);

	  if (recvBuff[0] == 10) {
		  //message_out.print(F("|NANOserIn:OK|"));
		  RawValueAmp =   recvBuff[1] | recvBuff[2] << 8;
		  RawValueVolt =  recvBuff[3] | recvBuff[4] << 8;
		  Rain_Detected = recvBuff[5] | recvBuff[6] << 8;
		  RawWheelAmp =   recvBuff[7] | recvBuff[8] << 8;
		  RawDrillAmp =   recvBuff[9] | recvBuff[10] << 8;
	  }
	}  // end if something received

  //message_out.print("WAmpRaw: ");
  //message_out.print(RawWheelAmp);
  //message_out.print(" |");

  //message_out.print("DAMpRaw: ");
  //message_out.print(RawDrillAmp);
  //message_out.print(" |");

  Calculate_Volt_Amp_Charge();

  }
}
