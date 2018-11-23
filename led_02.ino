int tempsDePause = 1000;        // Initialisation du temps de pose à 1s

void setup() {
  pinMode(13, OUTPUT);          // Initialisation de la pin 13 comme sortie
  Serial.begin(9600);           // Initialisation de la console série
  Serial.println("Début du programme");
}

void loop() {
  blink();

  tempsDePause -= 50;           // On décrémente le tempsDePause de 50 millisecondes

  if (tempsDePause < 50) {
    Serial.println("Stop");     // On se calme et on bascule en clignotement régulier
    tempsDePause = 1000;        // 1 fois par seconde
    while (true) {              // Indéfiniement
      blink();
    }
  }
}

void blink() {
  Serial.println(tempsDePause); // Affichage du temps de pose dans la console série
  digitalWrite(13, HIGH);       // Etat haut = led allumée
  delay(tempsDePause);          // Pause
  digitalWrite(13, LOW);        // Etat bas = led éteinte
  delay(tempsDePause);          // Pause
}
