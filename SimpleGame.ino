#define red 10
#define yellow 9
#define green 8

int WartoscP; //wartosc ustawiona na zadajniku
String PodanaLiczba; //liczba wprowadzona przez gracza

void setup() 
{

  Serial.begin(9600);  
  pinMode(2, INPUT_PULLUP); //Przycisk
  pinMode(red, OUTPUT); //Dioda czerwona
  pinMode(yellow, OUTPUT); //Dioda żółta
  pinMode(green, OUTPUT); //Dioda zielona

    WartoscP=analogRead(A4);
     Serial.println(WartoscP);
}

void loop() 
{
  WartoscP=analogRead(A4);
  int MaxP=WartoscP+50;
  int MinP=WartoscP-50;
  bool SzansaPierwsza;

  
  if(digitalRead(2)==LOW)
  {
    Serial.println(" Podaj liczbe: ");
    delay(1000);

  }

 if(Serial.available() > 0)
 {
   PodanaLiczba=Serial.readStringUntil('\n'); 
   int Losowa = PodanaLiczba.toInt();
 
   
  if((Losowa<=MaxP)&&(Losowa>=MinP)) 

  {
    digitalWrite(red,LOW);
    digitalWrite(yellow,LOW);
    digitalWrite(green,HIGH);
    delay(3000);
    digitalWrite(green,LOW);
    delay(3000);
    Serial.println("Brawo wygrałes");

  }

  else if (digitalRead(yellow)==LOW)
  {
    digitalWrite(yellow, HIGH);
    Serial.println("Masz jeszzcze 1 szanse");
   
  }

  else
  {
    digitalWrite(yellow,LOW);
    Serial.println("Przegrales !");
    digitalWrite(red,HIGH);
    delay(3000);
    digitalWrite(red,LOW);
  }
  }

 }

  
