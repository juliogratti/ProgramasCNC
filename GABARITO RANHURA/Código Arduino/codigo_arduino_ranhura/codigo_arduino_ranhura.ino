/* Sketch de exemplo para controlar um motor de passo com driver de motor de passo TB6600, biblioteca AccelStepper e Arduino: aceleração e desaceleração. */

// Include the AccelStepper library:
#include <AccelStepper.h>

// Defina as conexões do motor de passo e o tipo de interface do motor. O tipo de interface do motor deve ser definido como 1 ao usar um driver:
#define dirPinCharge 2
#define stepPinCharge 3
#define dirPinPasso 4
#define stepPinPasso 5
#define motorInterfaceType 1

// Crie uma nova instância da classe AccelStepper:
AccelStepper stepperCharge = AccelStepper(motorInterfaceType, stepPinCharge, dirPinCharge);
AccelStepper stepperPasso = AccelStepper(motorInterfaceType, stepPinPasso, dirPinPasso);

void setup() {
  // Defina a velocidade e aceleração máximas:
  stepperCharge.setMaxSpeed(15000);
  stepperCharge.setAcceleration(10000);

  stepperPasso.setMaxSpeed(7000);
  stepperPasso.setAcceleration(3000);
}

void loop() {
  
  stepperCharge.moveTo(24000); // cada passo equivale a 0,00633mm
  stepperCharge.runToPosition();

  delay(10);

  stepperPasso.move(1000);
  stepperPasso.runToPosition();

  delay(10);

  stepperCharge.moveTo(0);
  stepperCharge.runToPosition();

  delay(10);

  stepperPasso.move(800);
  stepperPasso.runToPosition();
  
  delay(10);

}
