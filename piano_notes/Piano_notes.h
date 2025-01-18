/*!
 * @file Piano_notes.h
 *
 * @mainpage Yuhan68 Piano_Notes Library
 *
 * @section intro_sec Introduction
 *
 * This is a library for defining piano notes, adding easier functionality
 * , and reducing clutter for people reading my piano project. 
 * 
 *

 * @section author Author
 *
 * Written by Yuhan Cruz
 * Updated by Yuhan Cruz
 *
 * @section license License
 *
 * BSD license, all text above must be included in any redistribution
 */

#ifndef PIANO_NOTES_H
#define PIANO_NOTES_H

#include <Arduino.h>

#define a0 27.50f
#define a_sharp0 29.14f
#define b0 30.87f

#define c1 32.70f
#define c_sharp1 34.65f
#define d1 36.71f
#define d_sharp1 38.89f
#define e1 41.20f
#define f1 43.65f
#define f_sharp1 46.25f
#define g1 49.00f
#define g_sharp1 51.91f
#define a1 55.00f
#define a_sharp1 58.27f
#define b1 61.74f

#define c2 65.41f
#define c_sharp2 69.30f
#define d2 73.42f
#define d_sharp2 77.78f
#define e2 82.41f
#define f2 87.31f
#define f_sharp2 92.50f
#define g2 98.00f
#define g_sharp2 103.83f
#define a2 110.00f
#define a_sharp2 116.54f
#define b2 123.47f

#define c3 130.81f
#define c_sharp3 138.59f
#define d3 146.83f
#define d_sharp3 155.56f
#define e3 164.81f
#define f3 174.61f
#define f_sharp3 185.00f
#define g3 196.00f
#define g_sharp3 207.65f
#define a3 220.00f
#define a_sharp3 233.08f
#define b3 246.94f

#define c4 261.63f
#define c_sharp4 277.18f
#define d4 293.66f
#define d_sharp4 311.13f
#define e4 329.63f
#define f4 349.23f
#define f_sharp4 369.99f
#define g4 392.00f
#define g_sharp4 415.30f
#define a4 440.00f
#define a_sharp4 466.16f
#define b4 493.88f

#define c5 523.25f
#define c_sharp5 554.37f
#define d5 587.33f
#define d_sharp5 622.25f
#define e5 659.26f
#define f5 698.46f
#define f_sharp5 739.99f
#define g5 783.99f
#define g_sharp5 830.61f
#define a5 880.00f
#define a_sharp5 932.33f
#define b5 987.77f

#define c6 1046.50f
#define c_sharp6 1108.73f
#define d6 1174.66f
#define d_sharp6 1244.51f
#define e6 1318.51f
#define f6 1396.91f
#define f_sharp6 1479.98f
#define g6 1567.98f
#define g_sharp6 1661.22f
#define a6 1760.00f
#define a_sharp6 1864.66f
#define b6 1975.53f

#define c7 2093.00f
#define c_sharp7 2217.46f
#define d7 2349.32f
#define d_sharp7 2489.02f
#define e7 2637.02f
#define f7 2793.83f
#define f_sharp7 2959.96f
#define g7 3135.96f
#define g_sharp7 3322.44f
#define a7 3520.00f
#define a_sharp7 3729.31f
#define b7 3951.07f

#define c8 4186.01f



// Global variable to hold beat duration
void setBPM(int bpm);
int whole();
int half();
int quarter();
int eighth();
int sixteenth();

//changing the octave
extern int O; //the default ocatave
void octave_down(int button);
void octave_up(int button);

#endif