#ifndef GLOBALS_H
#define GLOBALS_H

//Globals

// Zalo key pad logic
// https://github.com/Zal0
extern BYTE keys;
extern UBYTE previous_keys;

// frequencies
extern UWORD sweep_freq;
extern UWORD square_freq;
extern UWORD wave_freq;
extern UBYTE noise_freq;

// volumes
extern int sweep_volume;
extern int square_volume;
extern int wave_volume;
extern int noise_volume;

// notes
extern int sweep_note;  
extern int square_note;
extern int wave_note;
extern int noise_note;

extern int current_channel;

// duty
extern int duty_sweep;
extern int duty_square;
extern int duty_wave; // sample index nums

struct fader {
  UINT8 x;
  UINT8 y;
  UINT8 upper_bound;
  UINT8 lower_bound;
  UINT8 step;
  UINT8 fader_position;
};

extern struct fader fader_group[4];
extern struct fader duty_fader_group[4];

extern int frequency_mode;

struct NoiseyStruct {
  //NR43 0xFF22
  int dividing_ratio  ;//: 3;
  int counter_step ;//: 1;
  int clock_freq ;//: 4 bits;
} ;

extern struct NoiseyStruct noiseStruct;

extern UINT8 num_control_pages;
extern int active_control_page;
extern int credit_page;
const enum notes {
  C0, Cd0, D0, Dd0, E0, F0, Fd0, G0, Gd0, A0, Ad0, B0,
  C1, Cd1, D1, Dd1, E1, F1, Fd1, G1, Gd1, A1, Ad1, B1,
  C2, Cd2, D2, Dd2, E2, F2, Fd2, G2, Gd2, A2, Ad2, B2,
  C3, Cd3, D3, Dd3, E3, F3, Fd3, G3, Gd3, A3, Ad3, B3,
  C4, Cd4, D4, Dd4, E4, F4, Fd4, G4, Gd4, A4, Ad4, B4,
  C5, Cd5, D5, Dd5, E5, F5, Fd5, G5, Gd5, A5, Ad5, B5
};
extern const char noteNames[72][5];
extern const UWORD frequencies[72];
extern const UBYTE samples[80];
extern const UBYTE noiseNotesFrequencies[6]; // this is the UBYTE for FF22 - NR43 - Polynomial Counter
extern const int noiseNoteNameIndex[6]; // this is the index in noteNames
extern const UBYTE volumeFaderPosition[16];

// Macro marker
struct MacroStatus {
  int sweep;
  int square;
  int wave;
  int noise;
};

extern struct MacroStatus volumeMacroStatus;
extern struct MacroStatus dutyMacroStatus;
extern struct MacroStatus freqMacroStatus;
extern int domacro;

#endif