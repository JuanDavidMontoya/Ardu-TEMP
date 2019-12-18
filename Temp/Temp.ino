#include <SoftwareSerial.h> 
SoftwareSerial BT(10,11); //10 RX, 11 TX.
int val;
int temppin = 1;
char cadena[255];
int i=0;

void setup() {
  Serial.begin(9600);
  BT.begin(9600);

}

void loop() {

 float Temperatura = Temp ();


 if(BT.available())
  {
    char dato=BT.read(); //Guarda los datos carácter a carácter en la variable "dato"
 
    cadena[i++]=dato; //Vamos colocando cada carácter recibido en el array "cadena"
 
    //Cuando reciba una nueva línea (al pulsar enter en la app) entra en la función
    if(dato=='\n')
    {
      Serial.print(cadena); //Visualizamos el comando recibido en el Monitor Serial
 
      //GREEN LED
      if(strstr(cadena,"t")!=0)
      {
        BT.write("Hola mundo");
        Temperatura = Temp();
        Serial.print(Temperatura);
        BT.write(Temperatura);
      }
      
 
      BT.write(Temperatura); //Enviamos un retorno de carro de la app. La app ya crea una línea nueva
      clean();
    }
  }
 
  


  
}

float Temp (){
  val = analogRead (temppin);
  float mv = (val/1024.0)*5000.0;
  float centi = mv/10; 
  return centi;
  
}

void clean()
{
  for (int cl=0; cl<=i; cl++)
  {
    cadena[cl]=0;
  }
  i=0;
}
