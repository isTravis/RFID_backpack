
int ledPin = 13;   // select the pin for the LED
int val = 0;       // variable to store the data from the serial port

// 2-dimensional array of row pin numbers:
const int rownum[8] = {
10,12,15,17,2,4,6,8 };
// 2-dimensional array of column pin numbers:
const int colnum[8] = {
11,14,16,18,3,5,7,9  };

int laptop = 2;
int hasLaptop = 0;
int phone = 3;
int hasPhone = 0;
int tablet = 4;
int hasTablet = 0;

float timeCount = 0;


int smile[8][8] = {
{0,0,0,0,0,0,0,0},
{0,0,1,1,1,1,0,0},
{0,1,0,0,0,0,1,0},
{0,0,0,0,0,0,0,0},
{0,1,1,0,0,1,1,0},
{0,1,1,0,0,1,1,0},
{0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0}};



int frown[8][8] = {
{0,0,0,0,0,0,0,0},
{0,1,0,0,0,0,1,0},
{0,0,1,1,1,1,0,0},
{0,0,0,0,0,0,0,0},
{0,1,1,0,0,1,1,0},
{0,1,1,0,0,1,1,0},
{0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0}};

int meh[8][8] = {
{0,0,0,0,0,0,0,0},
{0,1,1,1,1,1,1,0},
{0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0},
{0,1,1,0,0,1,1,0},
{0,1,1,0,0,1,1,0},
{0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0}
};

int meh2[8][8] = {
{0,0,0,0,0,0,0,0},
{0,1,1,1,1,1,0,0},
{0,0,0,0,0,0,1,0},
{0,0,0,0,0,0,0,0},
{0,1,1,0,0,1,1,0},
{0,1,1,0,0,1,1,0},
{0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0}
};

int wink[8][8] = {
{0,0,0,0,0,0,0,0},
{0,0,1,1,1,1,0,0},
{0,1,0,0,0,0,1,0},
{0,0,0,0,0,0,0,0},
{0,1,1,0,0,1,1,0},
{0,1,1,0,0,0,0,0},
{0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0}
};

int blank[8][8] = {
{0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0}};

void setup() {
  pinMode(ledPin,OUTPUT);    // declare the LED's pin as output
  Serial.begin(9600);        // connect to the serial port
  
  // iterate over the pins:
  for (int thisPin = 0; thisPin < 8; thisPin++) {
  // initialize the output pins:
  pinMode(colnum[thisPin], OUTPUT);
  pinMode(rownum[thisPin], OUTPUT);
  // take the col pins (i.e. the cathodes) high to ensure that
  // the LEDS are off:
  digitalWrite(colnum[thisPin], LOW);
  digitalWrite(rownum[thisPin], HIGH);
}
}

void loop () {
  if(Serial.available()){
    val = Serial.read();      // read the serial port
  }
  if (val == '2'){
   hasLaptop = 1; 
   Serial.println("Got the Laptop! Wee! :D");
  }
  if (val == '3'){
   hasPhone = 1; 
   Serial.println("Got the Phone! Wee! :D");
  }
  if (val == '4'){
   hasTablet = 1; 
   Serial.println("Got the Tablet! Wee! :D");
  }
  
//  timeCount+=1;
//  
//  if(timeCount<1000){
//    drawScreen(meh);
//  }else if(timeCount <2000){
//    drawScreen(smile);
//  }else if(timeCount<2500){
//    drawScreen(wink);
//  }else if(timeCount<3500){
//    drawScreen(smile);
//  }else{
//    timeCount=0;
//  }

//Serial.println("Tablet:");
//Serial.println(hasTablet);
//Serial.println("Phone:");
//Serial.println(hasPhone);
//Serial.println("Laptop:");
//Serial.println(hasLaptop+hasPhone+hasTablet);

  if (hasLaptop+hasPhone+hasTablet == 0){
    drawScreen(frown);
  }else if(hasLaptop+hasPhone+hasTablet == 1){
    drawScreen(meh);
    //Serial.println("Trying to draw :");
  }else if(hasLaptop+hasPhone+hasTablet == 2){
    drawScreen(meh2);
  }else if(hasLaptop+hasPhone+hasTablet == 3){
    drawScreen(smile);
  }else{
    drawScreen(wink);
  }
    
  
  
 val = 0;
  
}


int row(int i) {
  if(i == 1) {
  return 10;
  } else if (i == 2) {
  return 12;
  } else if (i == 3) {
  return 15;
  } else if (i == 4) {
  return 17;
  } else if (i == 5) {
  return 2;
  } else if (i == 6) {
  return 4;
  } else if (i == 7) {
  return 6;
  } else if (i == 8) {
  return 8;
  }
}

int col(int i) {
if(i == 1) {
return 11;
} else if (i == 2) {
return 14;
} else if (i == 3) {
return 16;
} else if (i == 4) {
return 18;
} else if (i == 5) {
return 3;
} else if (i == 6) {
return 5;
} else if (i == 7) {
return 7;
} else if (i == 8) {
return 9;
}
}

void drawScreen(int character[8][8]) {
for(int j = 0; j < 8; j++) {
// Turn the row on
int rowNumber = j + 1;
digitalWrite(row(rowNumber), LOW);
for (int k = 0; k < 8; k++) {
// draw some letter bits
int columnNumber = k + 1;
if(character[j][k] == 1) {
digitalWrite(col(columnNumber), HIGH);
}

digitalWrite(col(columnNumber), LOW);
}
digitalWrite(row(rowNumber), HIGH);
}
}
