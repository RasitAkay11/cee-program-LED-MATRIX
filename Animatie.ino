// sources to create this code :
// https://create.arduino.cc/projecthub/SAnwandter1/programming-8x8-led-matrix-23475a
// https://www.instructables.com/id/Scrolling-Text-on-a-8x8-LED-Matrix-Using-an-Arduin/


//Definiëren van de uitganspinnen
const int shiftClockPin = 3;  //SH
const int latchClockPin = 4;  //ST
const int serialInputPin = 5; //DS

//R1 R2 K2 R8 K4 R3 R5 K1 K5 K3 K6 R4 K8 R6 R7 K7
//                  1228435153648677
//                  RRKRKRRKKKKRKRRK
word bericht1_1 = 0b0101011100010110;
word bericht1_2 = 0b0111011000010110;
word bericht1_3 = 0b0101011001010110;
word bericht1_4 = 0b0101111000010110;
word bericht1_5 = 0b0101011010010110;
word bericht1_6 = 0b0101011000110110;
word bericht1_7 = 0b0101011000010111;
word bericht1_8 = 0b0101011000011110;

//R1 R2 K2 R8 K4 R3 R5 K1 K5 K3 K6 R4 K8 R6 R7 K7
//                  1228435153648677
//                  RRKRKRRKKKKRKRRK
word bericht2_1 = 0b1001011100010110;
word bericht2_2 = 0b1011011000010110;
word bericht2_3 = 0b1001011001010110;
word bericht2_4 = 0b1001111000010110;
word bericht2_5 = 0b1001011010010110;
word bericht2_6 = 0b1001011000110110;
word bericht2_7 = 0b1001011000010111;
word bericht2_8 = 0b1001011000011110;

//R1 R2 K2 R8 K4 R3 R5 K1 K5 K3 K6 R4 K8 R6 R7 K7
//                  1228435153648677
//                  RRKRKRRKKKKRKRRK
word bericht3_1 = 0b1101001100010110;
word bericht3_2 = 0b1111001000010110;
word bericht3_3 = 0b1101001001010110;
word bericht3_4 = 0b1101101000010110;
word bericht3_5 = 0b1101001010010110;
word bericht3_6 = 0b1101001000110110;
word bericht3_7 = 0b1101001000010111;
word bericht3_8 = 0b1101001000011110;

//R1 R2 K2 R8 K4 R3 R5 K1 K5 K3 K6 R4 K8 R6 R7 K7
//                  1228435153648677
//                  RRKRKRRKKKKRKRRK
word bericht4_1 = 0b1101011100000110;
word bericht4_2 = 0b1111011000000110;
word bericht4_3 = 0b1101011001000110;
word bericht4_4 = 0b1101111000000110;
word bericht4_5 = 0b1101011010000110;
word bericht4_6 = 0b1101011000100110;
word bericht4_7 = 0b1101011000000111;
word bericht4_8 = 0b1101011000001110;

//R1 R2 K2 R8 K4 R3 R5 K1 K5 K3 K6 R4 K8 R6 R7 K7
//                  1228435153648677
//                  RRKRKRRKKKKRKRRK
word bericht5_1 = 0b1101010100010110;
word bericht5_2 = 0b1111010000010110;
word bericht5_3 = 0b1101010001010110;
word bericht5_4 = 0b1101110000010110;
word bericht5_5 = 0b1101010010010110;
word bericht5_6 = 0b1101010000110110;
word bericht5_7 = 0b1101010000010111;
word bericht5_8 = 0b1101010000011110;

//R1 R2 K2 R8 K4 R3 R5 K1 K5 K3 K6 R4 K8 R6 R7 K7
//                  1228435153648677
//                  RRKRKRRKKKKRKRRK
word bericht6_1 = 0b1101011100010010;
word bericht6_2 = 0b1111011000010010;
word bericht6_3 = 0b1101011001010010;
word bericht6_4 = 0b1101111000010010;
word bericht6_5 = 0b1101011010010010;
word bericht6_6 = 0b1101011000110010;
word bericht6_7 = 0b1101011000010011;
word bericht6_8 = 0b1101011000011010;

//R1 R2 K2 R8 K4 R3 R5 K1 K5 K3 K6 R4 K8 R6 R7 K7
//                  1228435153648677
//                  RRKRKRRKKKKRKRRK
word bericht7_1 = 0b1101011100010100;
word bericht7_2 = 0b1111011000010100;
word bericht7_3 = 0b1101011001010100;
word bericht7_4 = 0b1101111000010100;
word bericht7_5 = 0b1101011010010100;
word bericht7_6 = 0b1101011000110100;
word bericht7_7 = 0b1101011000010101;
word bericht7_8 = 0b1101011000011100;

//R1 R2 K2 R8 K4 R3 R5 K1 K5 K3 K6 R4 K8 R6 R7 K7
//                  1228435153648677
//                  RRKRKRRKKKKRKRRK
word bericht8_1 = 0b1100011100010110;
word bericht8_2 = 0b1110011000010110;
word bericht8_3 = 0b1100011001010110;
word bericht8_4 = 0b1100111000010110;
word bericht8_5 = 0b1100011010010110;
word bericht8_6 = 0b1100011000110110;
word bericht8_7 = 0b1100011000010111;
word bericht8_8 = 0b1100011000011110;



boolean shiftLeftRight = false;

void setup() {
  //Instelen van de uitgangspinnen
  pinMode(shiftClockPin, OUTPUT);
  pinMode(latchClockPin, OUTPUT);
  pinMode(serialInputPin, OUTPUT);
}

void loop(){


for(int a = 0; a < 20; a++){
displayData(bericht1_4);
displayData(bericht1_5);
displayData(bericht2_3);
displayData(bericht2_4);
displayData(bericht2_8);
displayData(bericht3_2);
displayData(bericht3_3);
displayData(bericht3_7);
displayData(bericht3_8);
displayData(bericht4_1);
displayData(bericht4_2);
displayData(bericht4_6);
displayData(bericht4_7);
displayData(bericht5_1);
displayData(bericht5_2);
displayData(bericht5_6);
displayData(bericht5_7);
displayData(bericht6_2);
displayData(bericht6_3);
displayData(bericht6_7);
displayData(bericht6_8);
displayData(bericht7_3);
displayData(bericht7_4);
displayData(bericht7_8);
displayData(bericht8_4);
displayData(bericht8_5);
}

for(int a = 0; a < 20; a++){
displayData(bericht1_3);
displayData(bericht1_4);
displayData(bericht1_8);
displayData(bericht2_2);
displayData(bericht2_3);
displayData(bericht2_7);
displayData(bericht2_8);
displayData(bericht3_1);
displayData(bericht3_2);
displayData(bericht3_6);
displayData(bericht3_7);
displayData(bericht4_1);
displayData(bericht4_5);
displayData(bericht4_6);
displayData(bericht5_1);
displayData(bericht5_5);
displayData(bericht5_6);
displayData(bericht6_1);
displayData(bericht6_2);
displayData(bericht6_6);
displayData(bericht6_7);
displayData(bericht7_2);
displayData(bericht7_3);
displayData(bericht7_7);
displayData(bericht7_8);
displayData(bericht8_3);
displayData(bericht8_4);
displayData(bericht8_8);
}

for(int a = 0; a < 20; a++){
displayData(bericht1_2);
displayData(bericht1_3);
displayData(bericht1_7);
displayData(bericht1_8);
displayData(bericht2_1);
displayData(bericht2_2);
displayData(bericht2_6);
displayData(bericht2_7);
displayData(bericht3_1);
displayData(bericht3_5);
displayData(bericht3_6);
displayData(bericht4_4);
displayData(bericht4_5);
displayData(bericht5_4);
displayData(bericht5_5);
displayData(bericht6_1);
displayData(bericht6_5);
displayData(bericht6_6);
displayData(bericht7_1);
displayData(bericht7_2);
displayData(bericht7_6);
displayData(bericht7_7);
displayData(bericht8_2);
displayData(bericht8_3);
displayData(bericht8_7);
displayData(bericht8_8);
}

for(int a = 0; a < 20; a++){
displayData(bericht1_1);
displayData(bericht1_2);
displayData(bericht1_6);
displayData(bericht1_7);
displayData(bericht2_1);
displayData(bericht2_5);
displayData(bericht2_6);
displayData(bericht3_4);
displayData(bericht3_5);
displayData(bericht4_3);
displayData(bericht4_4);
displayData(bericht4_8);
displayData(bericht5_3);
displayData(bericht5_4);
displayData(bericht5_8);
displayData(bericht6_4);
displayData(bericht6_5);
displayData(bericht7_1);
displayData(bericht7_5);
displayData(bericht7_6);
displayData(bericht8_1);
displayData(bericht8_2);
displayData(bericht8_6);
displayData(bericht8_7);
}

for(int a = 0; a < 20; a++){
displayData(bericht1_1);
displayData(bericht1_5);
displayData(bericht1_6);
displayData(bericht2_4);
displayData(bericht2_5);
displayData(bericht3_3);
displayData(bericht3_4);
displayData(bericht3_8);
displayData(bericht4_2);
displayData(bericht4_3);
displayData(bericht4_7);
displayData(bericht4_8);
displayData(bericht5_2);
displayData(bericht5_3);
displayData(bericht5_7);
displayData(bericht5_8);
displayData(bericht6_3);
displayData(bericht6_4);
displayData(bericht6_8);
displayData(bericht7_4);
displayData(bericht7_5);
displayData(bericht8_1);
displayData(bericht8_5);
displayData(bericht8_6);
}

}

void displayData(word message) {
  // put your main code here, to run repeatedly:
  for (int i = 0; i <= 15; i++) {
    digitalWrite(serialInputPin, bitRead(message, i));
    digitalWrite(shiftClockPin, HIGH);
    digitalWrite(shiftClockPin, LOW);
  }
  digitalWrite(latchClockPin, HIGH);
  digitalWrite(latchClockPin, LOW);

}
