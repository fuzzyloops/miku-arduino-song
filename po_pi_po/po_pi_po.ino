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
#define NOTE_A6 1760
#define NOTE_B6 1975.53
#define NOTE_C6 1046.502
#define NOTE_F5 698.46 


#define REST      0


// change this to make the song slower or faster
int tempo = 150;

// change this to whichever pin you want to use
int buzzer = 11;

int longN = 5; //long note
int xLong = 3; //Extra long note
int xxLong = 1; //Extra extra long note
int shortN = 9; //Short note
int xShort = 14; //Extra short note


// notes of the moledy followed by the duration.
// a 4 means a quarter note, 8 an eighteenth , 16 sixteenth, so on
// !!negative numbers are used to represent dotted notes,
// so -4 means a dotted quarter note, that is, a quarter plus an eighteenth!!
int melody[] = {
  /* most of the comments in this block are just me reminding myself what to do and where to look :)*/
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
  REST,longN, NOTE_F4,longN, NOTE_F4,longN, NOTE_F4,longN, NOTE_G4,longN, NOTE_A4,shortN, NOTE_B4,longN, NOTE_A4,shortN, REST,longN,
  NOTE_G4,longN, NOTE_F4,longN, NOTE_G4,longN, NOTE_F4,longN, REST,shortN, NOTE_C4,longN, REST,xLong, NOTE_C4,longN, NOTE_E4,longN, ///the weird part
  REST,longN, NOTE_F4,longN, NOTE_G4,longN, NOTE_A4,shortN, NOTE_G4,shortN, REST,shortN, /**/ NOTE_F4,longN, NOTE_E4,longN, NOTE_F4,longN, NOTE_E4,longN,
  NOTE_F4,longN, NOTE_E4,xLong, REST,longN, NOTE_E4,longN, NOTE_E4,longN, NOTE_E4,longN, NOTE_F4,longN, NOTE_G4,longN, NOTE_C5,longN, NOTE_B4,longN, NOTE_C5,xxLong,
  NOTE_C5,longN, NOTE_C5,longN, NOTE_C5,shortN, NOTE_C5,shortN, NOTE_C5,shortN, NOTE_C5,shortN, NOTE_C5,longN, NOTE_C5,longN, NOTE_C5,longN, NOTE_C5,longN, NOTE_B4,shortN,
  NOTE_G4,longN, REST,longN, /*Look through this area*/ NOTE_D5,longN, NOTE_C4,longN, NOTE_C4,longN, NOTE_C4,longN, NOTE_C4,longN, NOTE_B4,shortN, NOTE_C4,longN, NOTE_D5,shortN, REST,shortN,
  NOTE_E5,longN, /**/ NOTE_C5,longN, NOTE_C5,longN, NOTE_C5,longN, NOTE_C5,longN, NOTE_B4,shortN, NOTE_G4,longN, REST,longN, NOTE_D5,longN, NOTE_C5,longN,
  NOTE_C5,longN, NOTE_C5,longN, NOTE_C5,longN, NOTE_B4,shortN, NOTE_C5,longN, NOTE_D5,shortN, NOTE_E5,longN, NOTE_E4,xxLong, REST,longN, NOTE_D4,longN, NOTE_G4,longN,
  /**/ REST,shortN, NOTE_F4,longN, NOTE_E4,longN, NOTE_F4,longN, NOTE_E4,longN, NOTE_F4,longN, NOTE_E4,xLong, REST,longN, NOTE_E4,xLong, REST,longN, NOTE_D4,longN,
  NOTE_G4,xLong, NOTE_F4,longN, NOTE_E4,longN, NOTE_F4,longN, NOTE_E4,longN, NOTE_F4,longN, NOTE_E4,xLong, /**/ REST,longN, NOTE_C4,longN, REST,shortN, NOTE_C5,xLong,
  NOTE_B4,longN, NOTE_G4,xLong, NOTE_F4,longN, NOTE_E4,longN, NOTE_F4,longN, NOTE_E4,longN, NOTE_F4,longN, NOTE_E4,xLong, NOTE_C4,xLong, REST,longN,
  NOTE_E4,longN, NOTE_F4,longN, NOTE_G4,longN, NOTE_C5,longN, NOTE_B4,longN, REST,longN, NOTE_C5,xShort, NOTE_D5,xShort, NOTE_E5,xShort, NOTE_F5,xShort, NOTE_G5,xShort,
  NOTE_A5,xShort, NOTE_B5,xShort, NOTE_C6,xShort, NOTE_C6,xLong, /* <-- weird part might need changes in hz*/ NOTE_C5,longN, NOTE_G4,shortN, NOTE_C5,longN, NOTE_G4,shortN, NOTE_C5,longN,
  NOTE_D5,longN, NOTE_G5,longN, NOTE_D5,xLong, NOTE_C5,longN, NOTE_G4,shortN, NOTE_C5,longN, NOTE_G4,shortN, NOTE_C5,longN, NOTE_G4,shortN, NOTE_D5,longN, NOTE_G5,longN, NOTE_D5,xLong,
  NOTE_B4,xLong, NOTE_C5,xLong, NOTE_D5,longN, NOTE_C5,longN, NOTE_B5,longN, NOTE_G4,longN, NOTE_C5,longN, NOTE_C5,shortN, NOTE_C5,shortN, REST,shortN, NOTE_C5,shortN, NOTE_C5,longN, NOTE_C5,longN,
  NOTE_C5,longN, NOTE_C5,shortN, NOTE_C5,shortN, NOTE_C5,longN, NOTE_C5,longN, NOTE_G4,shortN, NOTE_C5,longN, NOTE_G4,shortN, NOTE_C5,longN, NOTE_D5,longN, NOTE_G5,longN, NOTE_D5,xLong,
  NOTE_C5,longN, NOTE_G4,shortN, NOTE_C5,longN, NOTE_G4,shortN, NOTE_C5,longN, NOTE_D5,longN, NOTE_G5,longN, NOTE_D5,xLong, NOTE_E4,xLong, NOTE_C5,longN, NOTE_D5,longN, NOTE_C5,longN, NOTE_B5,longN, 
  NOTE_G4,longN, NOTE_C5,longN, NOTE_C5,shortN, NOTE_C5,shortN, REST,shortN, NOTE_C5,shortN, NOTE_C5,longN, NOTE_C5,longN, NOTE_C5,longN, NOTE_C5,shortN, NOTE_C5,shortN, NOTE_C5,longN, NOTE_C5,longN,
  NOTE_G4,shortN, NOTE_C5,longN, NOTE_G4,shortN, NOTE_C5,longN, NOTE_D5,longN, NOTE_G5,longN, NOTE_D5,xLong, NOTE_C5,longN, NOTE_G4,longN, NOTE_C5,longN, NOTE_G4,longN, NOTE_C5,longN, NOTE_D5,longN,
  NOTE_G5,longN, NOTE_D5,xLong, NOTE_B4,xLong, NOTE_C5,xLong, NOTE_D5,longN, NOTE_C5,longN, NOTE_B5,longN, NOTE_G4,longN, NOTE_C5,longN, NOTE_C5,shortN, NOTE_C5,shortN, REST,shortN, NOTE_C5,shortN,
  NOTE_C5,longN, NOTE_C5,longN, NOTE_C5,longN, NOTE_C5,shortN, NOTE_C5,shortN, NOTE_C5,longN, NOTE_C5,longN, NOTE_G4,shortN, NOTE_C5,longN, NOTE_G4,shortN, NOTE_C5,longN, NOTE_D5,longN, NOTE_G5,longN,
  NOTE_D5,xLong, NOTE_C5,longN, NOTE_G4,shortN, NOTE_C5,longN, NOTE_G4,shortN, NOTE_C5,longN, NOTE_D5,longN, NOTE_G5,longN, NOTE_D5,xLong, NOTE_C5,xLong, NOTE_D5,xLong, NOTE_E5,xLong, NOTE_F5,xLong, NOTE_G5,longN,
  NOTE_F5,shortN, NOTE_E5,xLong, NOTE_D5,longN, NOTE_C5,shortN, NOTE_B5,longN, NOTE_D5,longN, NOTE_C5,xxLong,



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