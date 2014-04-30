// Copyright (C) Appzlab
// Copyright (C) Bruno Alano Medina
// Use, modification and distribution are subject to the
// MIT License, Version 1.0. (See accompanying file
// LICENSE)
#ifndef __HELPER_4511_H
#define __HELPER_4511_H

// Add Arduino library
#include "Arduino.h"

/*
 * Safaty mix C and C++
 */
#ifdef  __cplusplus
extern "C" {
#endif

/*
 * Creates the pins structure to the 4511
 * microcontroller
 *
 * based on datasheet of NXP 74HC/HCT4511
 * see: http://www.nxp.com/documents/data_sheet/74HC_HCT4511_CNV.pdf
 */
typedef struct
{
  unsigned int input_d2 : 4;
  unsigned int input_d3 : 4;
  unsigned int input_d4 : 4;
  unsigned int input_d1 : 4;
} controller_pins;

/*
 * Prints in 7 segmenet display
 *
 * @param value   unsigned int      a value to print to the display (0 to 9)
 * @param pins    controller_pins   structure that contains the input pins of controller
 */
void print_to_segment(unsigned int value, controller_pins pins);

#endif /* __HELPER_4511_H */