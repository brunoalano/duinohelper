// Copyright (C) Appzlab
// Copyright (C) Bruno Alano Medina
// Use, modification and distribution are subject to the
// MIT License, Version 1.0. (See accompanying file
// LICENSE)
#include "helper_4511.h"

/*
 * Prints in 7 segmenet display
 *
 * @param value   unsigned int      a value to print to the display (0 to 9)
 * @param pins    controller_pins   structure that contains the input pins of controller
 */
void print_to_segment(unsigned int value, controller_pins pins)
{
  /*
   * Convert the decimal value to binary, using method
   * provided by Renato Utsch
   */
  unsigned int bit1 = value & 0x1;
  unsigned int bit2 = (value & 0x2) >> 1;
  unsigned int bit3 = (value & 0x4) >> 2;
  unsigned int bit4 = (value & 0x8) >> 3;

  // DEBUG:
  // printf("%d = %d%d%d%d\n", value, bit4, bit3, bit2, bit1);

  /*
   * Change the status of each pin in
   * controller to display the number
   */
  digitalWrite(pins.input_d2, bit4);
  digitalWrite(pins.input_d3, bit3);
  digitalWrite(pins.input_d4, bit2);
  digitalWrite(pins.input_d1, bit1);
}