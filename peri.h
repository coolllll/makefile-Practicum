void intit_peripheral();
void set_led(uint8_t,uint8_t);
void set_led_value(uint8_t);
void clear_led();
#define IS_SWITCH_PRESS (!((PINC>>PC3)&1))
