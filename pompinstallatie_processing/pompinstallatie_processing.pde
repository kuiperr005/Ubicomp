import processing.serial.*;
Serial myPort;  // Create object from Serial class
String val;     // Data received from the serial port
PImage bg;  // Declare variable "bg" of type PImage
PFont markerFeltLarge;
PFont markerFeltSmall;
boolean dataComing = false;
String cleanMeters = "25000";

void setup() {
  size(1280, 800);
  // The image file must be in the data folder of the current sketch 
  // to load successfully
  bg = loadImage("achtergrondafbeelding.jpg");  // Load the image into the program
  
  String portName = Serial.list()[2]; //change the 0 to a 1 or 2 etc. to match your port
  myPort = new Serial(this, portName, 9600);   
  markerFeltLarge = loadFont("MarkerFelt-Wide-200.vlw");
  markerFeltSmall = loadFont("MarkerFelt-Wide-40.vlw");
}

void draw() {
  // Displays the image at its actual size at point (0,0)
  background(bg);
  if ( myPort.available() > 0)   {  // If data is available,
  val = myPort.readStringUntil('\n');         // read it and store it in val
  }
 if (val != null) {
       cleanMeters = trim(val);
       int meters = Integer.parseInt(cleanMeters);
       int walked = 25000 - meters;
       String walkedString = str(walked);
       textFont(markerFeltLarge, 100);
       textAlign(CENTER);
       fill(0); 
       text(cleanMeters, 530, 310); //print aantal meters nog te lopen
       textFont(markerFeltSmall, 40);
       textAlign(CENTER);
       fill(198,85,23);
       text(walkedString, 630, 400); // print aantal gelopen meters
 } else {
   if (cleanMeters == "25000") {
     textFont(markerFeltLarge, 100);
     textAlign(CENTER);
     fill(0); 
     text("25000", 530, 310); //print aantal meters nog te lopen
     textFont(markerFeltSmall, 40);
     textAlign(CENTER);
     fill(198,85,23);
     text("0", 630, 400); // print aantal gelopen meters
   }  
 }
}
