void shift_init(void);
void shift_output_enable(bool enable);
void shift_clear_set(uint16_t clear_bits, uint16_t set_bits);
#define shift_clear_set_wait(clear_bits, set_bits) shift_clear_set(clear_bits, set_bits)
