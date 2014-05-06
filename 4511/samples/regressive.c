/*
 * Trabalho de Robotica
 *
 * A biblioteca utilizada foi desenvolvida por Bruno Alano Medina,
 * no endereco: https://github.com/brunoalano/duinohelper/tree/master/4511
 *
 * Grupo:
 *  - Bruno Alano
 *  - Augusto Rutter
 *  - Evelin Krutzsch
 *  - Ricardo Affonso
 *  - Lucas Emanuel
 */

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

/*
 * Arduino Setup
 */
void setup(void)
{
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
}

/*
 * Arduino Runtime Loop
 */
void loop(void)
{
  // Definimos o processador
  controller_pins MyProcessor1;
  
  // Defino os pinos
  MyProcessor1.input_d2 = 3;
  MyProcessor1.input_d3 = 4;
  MyProcessor1.input_d4 = 5;
  MyProcessor1.input_d1 = 2;
  
  // Loop
  for (int i = 10; i > 0; i--)
    {
      // Printamos
      print_to_segment(i, MyProcessor1);
    
      // Delay
      delay(1000);
    }
}

/*
 * Prints in 7 segmenet display
 *
 * @param value   unsigned int      a value to print to the display (0 to 9)
 * @param pins    controller_pins   structure that contains the input pins of controller
 */
void print_to_segment(unsigned int value, controller_pins pins)
{
  /*
   * Convert the decimal value to binary
   */
  unsigned int bit1 = value & 0x1;
  unsigned int bit2 = (value & 0x2) >> 1;
  unsigned int bit3 = (value & 0x4) >> 2;
  unsigned int bit4 = (value & 0x8) >> 3;
  
  /*
   * Change the status of each pin in
   * controller to display the number
   */
  digitalWrite(pins.input_d1, bit1); // 1 Bit
  digitalWrite(pins.input_d4, bit4); // 4 Bit
  digitalWrite(pins.input_d3, bit3); // 3 Bit
  digitalWrite(pins.input_d2, bit2); // 2 Bit
}
