#define diodaPIN 3

int wypelnienie = 0;
int zmiana = 5;
bool wypelnione;

void setup() {
  pinMode(diodaPIN, OUTPUT);//Konfiguracja pinu jako wyjścia 
  Serial.begin(9600);
}

void loop() {
  analogWrite(diodaPIN, wypelnienie); //Generujemy sygnał o zadanym wypełnieniu

  if ((wypelnienie < 255)&& (wypelnione==false))
  { //Jeśli wypełnienie mniejsze od 100%
    wypelnienie = wypelnienie + zmiana; //Zwiększamy wypełnienie
 

  } 
  else if(wypelnienie==0)
  {
    wypelnione=false;
  }
  
  else if (wypelnione=true)

  {
    wypelnienie = wypelnienie - zmiana;
  }
    else if (wypelnienie==255)
  
  {
   
    wypelnione=true;
  }
 
  
 
  delay(100); //Małe opóźnienie, aby efekt był widoczny
  Serial.println(wypelnienie);

}
