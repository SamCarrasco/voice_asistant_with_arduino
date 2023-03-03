#include <SoftwareSerial.h>


SoftwareSerial BT(10, 11); //TX, RX respetively
String state;// string to store incoming message from bluetooth
//Variables globales:
int pin_luces[] = {6,7,5,3,2,1};    //pines de los focos

void setup() {
 BT.begin(9600);// bluetooth serial communication will happen on pin 10 and 11
 Serial.begin(9600); // serial communication to check the data on serial monitor
  pinMode(13, OUTPUT); // LED connected to 13th pin




}
//-----------------------------------------------------------------------//  
void encendertodaslasluces(){
  int n = 0;
  
  while(n < sizeof(pin_luces) ){//cantidad de focos
    digitalWrite(pin_luces[n],HIGH);
    n++;
  }

}
void apagartodaslasluces(){
  int n = 0;
  while(n < sizeof(pin_luces) ){//cantidad de focos
    digitalWrite(pin_luces[n],LOW);
    n++;
  }
}

void serviragua(){
  //poner pin de la bomba
  digitalWrite(200,HIGH);
  delay(2000); // Sirve agua por 2 segundos(cambiar luego de la prueba)
  digitalWrite(200,LOW)
}

void ver_hayalguien_puerta(){
  //falta ver si se va a implementar
}
void loop() {
  while (BT.available()){  //Check if there is an available byte to read
  delay(10); //Delay added to make thing stable 
  char c = BT.read(); //Conduct a serial read
  state += c; //build the string- either "On" or "off"
  }  
  if (state.length() > 0) {
    Serial.println(state); 


  // if(state == "angelica prende la luz") 
  // {
  //   digitalWrite(13, HIGH);
    
  //     } 
  
  // else if(state == "angelica apaga la luz") 
  // {
  //   digitalWrite(13, LOW);
  // }
  switch(state)
  {
    case "angelica prende la luz de la cocina" : digitalWrite(7,HIGH);
    break;
    case "angelica apaga la luz de la cocina" : digitalWrite(7,LOW);
    break;
    case "angelica prende la luz de la sala":digitalWrite(5,HIGH);
    break;
    case "angelica apaga la luz de la sala":digitalWrite(5,LOW);
    break;
    case "angelica sirveme un vaso de agua":  serviragua();
    break;
    case "angelica enciende todas las luces": encendertodaslasluces();
    break;
    case "angelica apaga todas las luces": apagartodaslasluces();
    break;
   
  }

  
  
state ="";}} //Resetea la variable