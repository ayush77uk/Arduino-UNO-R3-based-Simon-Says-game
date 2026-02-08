# Simon Says Game – Arduino UNO

## Overview

This project is a memory-based Simon Says game built using an Arduino Uno, four LEDs, four push buttons, and a buzzer. The system generates a random sequence of colors and sounds. The player must repeat the sequence correctly using the buttons. With each successful round, the sequence grows longer and the score increases. If the player makes a mistake, the game ends with a short failure melody and restarts.

## Features

* Randomly generated color sequence
* Increasing difficulty each round
* Sound feedback for every LED press
* Score tracking via Serial Monitor
* Game over melody on failure
* Supports four colors:

  * Blue
  * Red
  * Yellow
  * Green

## Components Required

* Arduino Uno
* 4 LEDs (Blue, Red, Yellow, Green)
* 4 Push buttons
* 4 Current-limiting resistors (220–330Ω recommended)
* Buzzer
* Jumper wires
* Breadboard
* Arduino IDE (Or any Arduino supportive environment)
* UART->USB cable

## Pin Configuration

### LEDs

* Blue LED → Pin 12
* Red LED → Pin 13
* Yellow LED → Pin 3
* Green LED → Pin 4

### Buttons (using INPUT_PULLUP)

* Blue Button → Pin 6
* Red Button → Pin 7
* Yellow Button → Pin 9
* Green Button → Pin 10

### Sound

* Buzzer → Pin 11

## How It Works

1. The Arduino generates a random color and adds it to the sequence.
2. The sequence is shown using LEDs and matching tones.
3. The player repeats the sequence by pressing the corresponding buttons.
4. If correct:

   * The score increases
   * A new color is added
   * A longer sequence is played next round
5. If incorrect:

   * A game over melody plays
   * The sequence resets
   * A new game begins

## Controls

Each button corresponds to one LED and sound:

* Blue button → Blue LED + tone
* Red button → Red LED + tone
* Yellow button → Yellow LED + tone
* Green button → Green LED + tone

Buttons use the internal pull-up resistors, so:

* Pressed = LOW
* Released = HIGH

## Serial Monitor Output

The Serial Monitor displays:

* "Game Over !" when the player makes a mistake
* "Score : X" after each successful round
* "New Game Starts..." when the game resets

Set baud rate to **9600**.

## Game Logic Summary

* A random number (0–3) represents a color.
* Each round adds one new number to the sequence.
* The player must match the entire sequence in order.
* Score increases for every correctly completed round.