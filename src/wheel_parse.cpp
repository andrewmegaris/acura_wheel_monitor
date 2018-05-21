      uint8_t FL1 = (input.data[0]);
      uint8_t FL2 = (input.data[1]);
      uint8_t FR1 = (input.data[1]);
      uint8_t FR2 = (input.data[2]);
      uint8_t FR3 = (input.data[3]);
      uint8_t RL1 = (input.data[3]);
      uint8_t RL2 = (input.data[4]);
      uint8_t RL3 = (input.data[5]);
      uint8_t RR1 = (input.data[5]);
      uint8_t RR2 = (input.data[6]);
      uint8_t RR3 = (input.data[7]);
      
      wheel_sensor.FL_speed = float( (int16_t) ( (FL1) + (FL2)         ) );
      wheel_sensor.FR_speed = float( (int16_t) ( (FR1) + (FR2) + (FR3) ) );
      wheel_sensor.RL_speed = float( (int16_t) ( (RL1) + (RL2) + (RL3) ) );
      wheel_sensor.RR_speed = float( (int16_t) ( (RR1) + (RR2) + (RR3) ) );
