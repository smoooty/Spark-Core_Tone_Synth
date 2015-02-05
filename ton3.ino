//square wave synth

int speakerPin = A0;    //Connect small speaker to analog pin A0
int pos = 0;    // variable to store the frequency 
int dur = 0;    // variable to store the duration 

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {10};

void setup() {
  
    //frequency
    Spark.function("setpos", setPosition);
    
    //duration
    Spark.function("setdur", setDuration);

}

void loop(){
    // iterate over the notes of the melody:
  for (int thisNote = 0; thisNote < 8; thisNote++) {

    // to calculate the note duration, take one second 
    // divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000/noteDurations[dur];
    tone(speakerPin, pos,noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    delay(250);
    
    // stop the tone playing:
    noTone(speakerPin);
  }
}

//frequency
int setPosition(String posValue) {
    pos = posValue.toInt();
    return 0;
}

//duration
int setDuration(String durValue) {
    dur = durValue.toInt();
    return 0;
}
