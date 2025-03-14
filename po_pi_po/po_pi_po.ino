/* 
  Hatsune Miku, Po Pi Po

  Connect a piezo buzzer or speaker to pin 11 or select a new pin.

  Original program is by https://github.com/robsoncouto/arduino-songs.
  I've just used his sketch to add my own songs.


  https://github.com/fuzzyloops :)
*/
#define NOTE_G4 392
#define NOTE_C5 523.25
#define NOTE_D5 587.33
#define NOTE_G5 783.99
#define NOTE_B5 987.77
#define NOTE_B4 493.88
#define NOTE_E5 659.255
#define NOTE_E4 329.628
#define NOTE_F4 349.23
#define NOTE_A5 880
#define NOTE_C4 261.626
#define NOTE_A4 440
#define NOTE_D4 293.665


#define REST      0


// change this to make the song slower or faster
int tempo = 150;

// change this to whichever pin you want to use
int buzzer = 11;

int longN = 5;
int xLong = 3;
int xxLong = 1;
int shortN = 9;


// notes of the moledy followed by the duration.
// a 4 means a quarter note, 8 an eighteenth , 16 sixteenth, so on
// !!negative numbers are used to represent dotted notes,
// so -4 means a dotted quarter note, that is, a quarter plus an eighteenth!!
int melody[] = {
  
  NOTE_C5,longN, NOTE_G4,shortN, NOTE_C5,longN, NOTE_G4,shortN, NOTE_C5,longN, NOTE_D5,longN, NOTE_G5,longN, NOTE_D5,xLong, REST,shortN,///First block
  NOTE_C5,longN, NOTE_G4,shortN, NOTE_C5,longN, NOTE_G4,shortN, NOTE_C5,longN, NOTE_D5,longN, NOTE_G5,longN, NOTE_D5,xLong, REST,shortN,///Repeat first four times
  NOTE_C5,longN, NOTE_G4,shortN, NOTE_C5,longN, NOTE_G4,shortN, NOTE_C5,longN, NOTE_D5,longN, NOTE_G5,longN, NOTE_D5,xLong, REST,shortN,
  NOTE_C5,longN, NOTE_G4,shortN, NOTE_C5,longN, NOTE_G4,shortN, NOTE_C5,longN, NOTE_D5,longN, NOTE_G5,longN, REST,longN, ///Begin po pi po
  NOTE_C5,longN, NOTE_C5,longN, NOTE_C5,longN, NOTE_C5,longN, NOTE_B4,shortN, NOTE_G4,longN, REST,longN, NOTE_D5,longN, ///Repeat constant C5
  NOTE_C5,longN, NOTE_C5,longN, NOTE_C5,longN, NOTE_C5,longN, NOTE_B4,shortN, NOTE_C5,longN, NOTE_D5,shortN, REST,shortN, NOTE_E5,longN,
  NOTE_C5,longN, NOTE_C5,longN, NOTE_C5,longN, NOTE_C5,longN, NOTE_B4,shortN, NOTE_G4,longN, REST,longN, NOTE_D5,longN,
  NOTE_C5,longN, NOTE_C5,longN, NOTE_C5,longN, NOTE_C5,longN, NOTE_B4,shortN, NOTE_C5,longN, NOTE_D5,shortN, REST,shortN, NOTE_E5,longN,
  NOTE_E4,longN, REST,shortN, NOTE_E4,shortN, REST,shortN, NOTE_E4,shortN, NOTE_E4,shortN, NOTE_F4,shortN, NOTE_G4,shortN, NOTE_A4,shortN,
  NOTE_G4,shortN, NOTE_G4,shortN, REST,longN, NOTE_F4,longN, NOTE_E4,longN, NOTE_F4,longN, NOTE_E4,longN, NOTE_F4,longN, NOTE_E4,xLong, 
  REST,longN, NOTE_F4,longN, NOTE_F4,longN, NOTE_F4,longN, NOTE_G4,longN, NOTE_A4,shortN, NOTE_B5,longN, NOTE_A4,shortN, REST,longN,
  NOTE_G4,longN, NOTE_F4,longN, NOTE_G4,longN, NOTE_F4,longN, REST,shortN, NOTE_C4,longN, REST,xLong, NOTE_C4,longN, NOTE_E4,longN, ///the weird part
  REST,longN, NOTE_F4,longN, NOTE_G4,longN, NOTE_A4,shortN, NOTE_G4,shortN, REST,shortN, /**/ NOTE_F4,longN, NOTE_E4,longN, NOTE_F4,longN, NOTE_E4,longN,
  NOTE_F4,longN, NOTE_E4,xLong, REST,longN, NOTE_E4,longN, NOTE_E4,longN, NOTE_E4,longN, NOTE_F4,longN, NOTE_G4,longN, NOTE_C5,longN, NOTE_B5,longN, NOTE_C5,xxLong,
  NOTE_C5,longN, NOTE_C5,longN, NOTE_C5,shortN, NOTE_C5,shortN, NOTE_C5,shortN, NOTE_C5,shortN, NOTE_C5,longN, NOTE_C5,longN, NOTE_C5,longN, NOTE_C5,longN, NOTE_B4,shortN,
  NOTE_G4,longN, REST,longN, /*Look through this area*/ NOTE_D5,longN, NOTE_C4,longN, NOTE_C4,longN, NOTE_C4,longN, NOTE_C4,longN, NOTE_B4,shortN, NOTE_C4,longN, NOTE_D5,shortN, REST,shortN,
  NOTE_E5,longN, /**/ NOTE_C5,longN, NOTE_C5,longN, NOTE_C5,longN, NOTE_C5,longN, NOTE_B5,shortN, NOTE_G4,longN, REST,longN, NOTE_D5,longN, NOTE_C5,longN,
  NOTE_C5,longN, NOTE_C5,longN, NOTE_C5,longN, NOTE_B5,shortN, NOTE_C5,longN, NOTE_D5,shortN, NOTE_E5,longN, NOTE_E4,xxLong, REST,longN, NOTE_D4,longN, NOTE_G4,longN,
  /**/ REST,shortN, NOTE_F4,longN, NOTE_E4,longN, NOTE_F4,longN, NOTE_E4,longN, NOTE_F4,longN, NOTE_E4,xLong, REST,longN, NOTE_E4,xLong, REST,longN, NOTE_D4,longN,
  NOTE_G4,xLong, NOTE_F4,longN, NOTE_E4,longN, NOTE_F4,longN, NOTE_E4,longN, NOTE_F4,longN, NOTE_E4,xLong,


};

// sizeof gives the number of bytes, each int value is composed of two bytes (16 bits)
// there are two values per note (pitch and duration), so for each note there are four bytes
int notes = sizeof(melody) / sizeof(melody[0]) / 2;

// this calculates the duration of a whole note in ms
int wholenote = (60000 * 4) / tempo;

int divider = 0, noteDuration = 0;

void setup() {
  // iterate over the notes of the melody.
  // Remember, the array is twice the number of notes (notes + durations)
  for (int thisNote = 0; thisNote < notes * 2; thisNote = thisNote + 2) {

    // calculates the duration of each note
    divider = melody[thisNote + 1];
    if (divider > 0) {
      // regular note, just proceed
      noteDuration = (wholenote) / divider;
    } else if (divider < 0) {
      // dotted notes are represented with negative durations!!
      noteDuration = (wholenote) / abs(divider);
      noteDuration *= 1.5; // increases the duration in half for dotted notes
    }

    // we only play the note for 90% of the duration, leaving 10% as a pause
    tone(buzzer, melody[thisNote], noteDuration * 0.9);

    // Wait for the specief duration before playing the next note.
    delay(noteDuration);

    // stop the waveform generation before the next note.
    noTone(buzzer);
  }
}

void loop() {
  // no need to repeat the melody.
}