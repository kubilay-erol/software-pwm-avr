
#define MY_DDRB   *(reinterpret_cast<volatile unsigned char*>(0x24))
#define MY_PORTB   *(reinterpret_cast<volatile unsigned char*>(0x25))


void tiny_delay(uint16_t count) {
    for (volatile uint16_t i = 0; i < count; i++);
}

int main(void) {
    
    MY_DDRB |= 0x08; 

    uint16_t brightness = 0;
    int16_t direction = 1;
    const uint16_t period = 1000;

    while (1) {

        if (brightness > 0) {
            MY_PORTB |= 0x08; 
            tiny_delay(brightness); 
        }

        if (brightness < period) {
            MY_PORTB &= ~(0x08); 
            tiny_delay(period - brightness); 
        }

        brightness += direction;

        if (brightness >= period || brightness <= 0) {
            direction = -direction; 
        }
    }

}
