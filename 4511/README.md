4511 Module
=========

This helper is intended to control the microprocessor 4511 family, as the models below:

- 74HC/HCT4511
- CD54HC4511
- CD74HC4511
- CD74HCT4511

## Datasheet
The datasheet of reference is provided by the company NXP, but can be used with any other, since you are sure the data ports (4 ports, their order is important)

[NXP 74HC - HTC4511 Datasheet](http://www.nxp.com/documents/data_sheet/74HC_HCT4511_CNV.pdf)

## Important
If the numbers are not appearing as they should, verify that the ports used are in the correct order based on the schedule provided by the datasheet of reference for this project.

## How to Use
In this project we use a data structure for the pins we store data, so we can keep their order. For this, we use the model of Bitfield struct, each field has a capacity of 4 bits. 

The definition of the data structure is:

```
typedef struct
{
  unsigned int input_d2 : 4;
  unsigned int input_d3 : 4;
  unsigned int input_d4 : 4;
  unsigned int input_d1 : 4;
} controller_pins;
```

Example:

```
controller_pins MyProcessor1;
MyProcessor1.input_d2 = 3;
MyProcessor1.input_d3 = 4;
MyProcessor1.input_d4 = 5;
MyProcessor1.input_d1 = 6;
```

Now we can call the print method:

```
print_to_segment(6, MyProcessor1);
delay(1000);
print_to_segment(5, MyProcessor1);
delay(1000);
print_to_segment(4, MyProcessor1);
```

The definition of this functions:

```
void print_to_segment(unsigned int value, controller_pins pins);
```