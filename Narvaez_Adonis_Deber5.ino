int i=0;
int cont=0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()>0){
    String palabra=Serial.readString();
    int lon=palabra.length();
    for(i=0;i<lon;i++){
      if(palabra.charAt(i)=='A' || palabra.charAt(i)=='E'||palabra.charAt(i)=='I'||palabra.charAt(i)=='O'||palabra.charAt(i)=='U'){
      cont++;
    }
    }
    Serial.println(cont);
    delay(200);
    cont=0;
  }
}
