 void CC(){
if (Serial1.available()) {  //check if serial port has data input
      if(Serial1.read() == HEADER) {  //assess data package frame header 0x59
        uart[0]=HEADER;
        if (Serial1.read() == HEADER) { //assess data package frame header 0x59
          uart[1] = HEADER;
          for (i = 2; i < 9; i++) { //save data in array
            uart[i] = Serial1.read();
          }
          check = uart[0] + uart[1] + uart[2] + uart[3] + uart[4] + uart[5] + uart[6] + uart[7];
          if (uart[8] == (check & 0xff)){ //verify the received data as per protocol
            dist = uart[2] + uart[3] * 256;     //calculate distance value
            Serial.print("BBdist = ");
            Serial.print(dist); //output measure distance value of LiDAR
            Serial.print('\n');
          }
        }
      }
    }
 }
