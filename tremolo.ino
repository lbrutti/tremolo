void setup() {
  pinMode(10, OUTPUT);//to LED
  pinMode(11, OUTPUT);//to Optocupler
  pinMode(A0, INPUT);//peek bias
  pinMode(A1, INPUT);//waveform
  pinMode(A2, INPUT);//rate
  //Serial.begin(9600);
}

double delayTime = 2;
double rise_bias = 14;
double fall_bias = 14;
 
void loop() {
  for (double i = 0; i <= 255; i+= rise_bias) { 
    checkInterupts();
    delay(delayTime);   
    double waveform = toWaveForm(i);
    analogWrite(10, waveform);
    analogWrite(11, waveform);
    
       //Serial.print(waveform);
       //Serial.print(",");
       //Serial.print(delayTime);
       //Serial.print(",");
       //Serial.print(analogRead(A0));
       //Serial.print(",");
       //Serial.print(rise_bias);
       //Serial.print(",");
       //Serial.println(fall_bias);
  }
  for (double i = 255; i >= 0; i-= fall_bias) {
    checkInterupts() ;
    delay(delayTime);    
    double waveform = toWaveForm(i);
    analogWrite(10,waveform);
    analogWrite(11, waveform);

      //Serial.print(waveform);
       //Serial.print(",");
       //Serial.print(delayTime);
       //Serial.print(",");
       //Serial.print(analogRead(A0));
       //Serial.print(",");
       //Serial.print(rise_bias);
       //Serial.print(",");
       //Serial.println(fall_bias);
  }
}

double toWaveForm(double tryangle_wave) {
  //set shape shifting multiplier 0-3
  double wave_form_multiplier = ((0.0000019073486 * pow((analogRead(A1)-20), 2)) + (0.0009765625 * (analogRead(A1)-20)));//20 is potensiometer offset!
   //Serial.print(wave_form_multiplier);
   //Serial.print(",");

  float sine_wave = ((((cos((tryangle_wave/255)*3.141592653589+3.141592653589))/2)+0.5)*255);
  if (wave_form_multiplier <= 1){
    float difference = tryangle_wave - sine_wave;
    difference = difference * wave_form_multiplier;
    return (tryangle_wave - difference);
  }else{//wave clipping
    double new_sine_wave = (((sine_wave) * wave_form_multiplier));
    new_sine_wave = new_sine_wave - ((wave_form_multiplier - 1) * 127.5);
    if(new_sine_wave > 255){
      new_sine_wave = 255;
    }else if(new_sine_wave < 0){
      new_sine_wave = 0;
    }
    return new_sine_wave;
  }
}

void checkInterupts(){
  //set delay time
  delayTime = (((double)analogRead(A2)-40)/20);//40 is potensiometer offset
  if(delayTime<0){
    delayTime = 0;
  }


  //set peek bias
  rise_bias = (((analogRead(A0)-30)/40.96)+2.5);//0-28//1.5-26.5 //30 is potensiometer offset!
  if(rise_bias < 0.01){
    rise_bias = 0.01;
  }
  fall_bias = 30 - rise_bias; 

}
