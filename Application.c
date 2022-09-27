/* 
 * File:   Application.c
 * Author: Kareem Taha Abdelfatah Mohammed
 * https://www.linkedin.com/in/kareem-taha-ba451621a/
 * Created on September 13, 2022, 9:10 PM
 */

#include "Application.h"

STD_ReturnType ret = E_OK;



ch_lcd_4bit_t lcd_1 = {
  .lcd_rs.port = PORTC_INDEX,
  .lcd_rs.pin = GPIO_PIN0,
  .lcd_rs.logic = GPIO_LOW,
  .lcd_rs.direction = GPIO_OUTPUT_DIRECTION,
  .lcd_en.port = PORTC_INDEX,
  .lcd_en.pin = GPIO_PIN1,
  .lcd_en.logic = GPIO_LOW,
  .lcd_en.direction = GPIO_OUTPUT_DIRECTION,
  .lcd_data_4_bit[0].port = PORTC_INDEX,
  .lcd_data_4_bit[0].pin = GPIO_PIN2,
  .lcd_data_4_bit[0].logic = GPIO_LOW,
  .lcd_data_4_bit[0].direction = GPIO_OUTPUT_DIRECTION,
  .lcd_data_4_bit[1].port = PORTC_INDEX,
  .lcd_data_4_bit[1].pin = GPIO_PIN3,
  .lcd_data_4_bit[1].logic = GPIO_LOW,
  .lcd_data_4_bit[1].direction = GPIO_OUTPUT_DIRECTION,
  .lcd_data_4_bit[2].port = PORTC_INDEX,
  .lcd_data_4_bit[2].pin = GPIO_PIN4,
  .lcd_data_4_bit[2].logic = GPIO_LOW,
  .lcd_data_4_bit[2].direction = GPIO_OUTPUT_DIRECTION,
  .lcd_data_4_bit[3].port = PORTC_INDEX,
  .lcd_data_4_bit[3].pin = GPIO_PIN5,
  .lcd_data_4_bit[3].logic = GPIO_LOW,
  .lcd_data_4_bit[3].direction = GPIO_OUTPUT_DIRECTION
};

/*
ch_lcd_8bit_t lcd_2 = {
  .lcd_rs.port = PORTC_INDEX,
  .lcd_rs.pin = GPIO_PIN6,
  .lcd_rs.logic = GPIO_LOW,
  .lcd_rs.direction = GPIO_OUTPUT_DIRECTION,
  .lcd_en.port = PORTC_INDEX,
  .lcd_en.pin = GPIO_PIN7,
  .lcd_en.logic = GPIO_LOW,
  .lcd_en.direction = GPIO_OUTPUT_DIRECTION,
  .lcd_data_8_bit[0].port = PORTD_INDEX,
  .lcd_data_8_bit[0].pin = GPIO_PIN0,
  .lcd_data_8_bit[0].logic = GPIO_LOW,
  .lcd_data_8_bit[0].direction = GPIO_OUTPUT_DIRECTION,
  .lcd_data_8_bit[1].port = PORTD_INDEX,
  .lcd_data_8_bit[1].pin = GPIO_PIN1,
  .lcd_data_8_bit[1].logic = GPIO_LOW,
  .lcd_data_8_bit[1].direction = GPIO_OUTPUT_DIRECTION,
  .lcd_data_8_bit[2].port = PORTD_INDEX,
  .lcd_data_8_bit[2].pin = GPIO_PIN2,
  .lcd_data_8_bit[2].logic = GPIO_LOW,
  .lcd_data_8_bit[2].direction = GPIO_OUTPUT_DIRECTION,
  .lcd_data_8_bit[3].port = PORTD_INDEX,
  .lcd_data_8_bit[3].pin = GPIO_PIN3,
  .lcd_data_8_bit[3].logic = GPIO_LOW,
  .lcd_data_8_bit[3].direction = GPIO_OUTPUT_DIRECTION,
  .lcd_data_8_bit[4].port = PORTD_INDEX,
  .lcd_data_8_bit[4].pin = GPIO_PIN4,
  .lcd_data_8_bit[4].logic = GPIO_LOW,
  .lcd_data_8_bit[4].direction = GPIO_OUTPUT_DIRECTION,
  .lcd_data_8_bit[5].port = PORTD_INDEX,
  .lcd_data_8_bit[5].pin = GPIO_PIN5,
  .lcd_data_8_bit[5].logic = GPIO_LOW,
  .lcd_data_8_bit[5].direction = GPIO_OUTPUT_DIRECTION,
  .lcd_data_8_bit[6].port = PORTD_INDEX,
  .lcd_data_8_bit[6].pin = GPIO_PIN6,
  .lcd_data_8_bit[6].logic = GPIO_LOW,
  .lcd_data_8_bit[6].direction = GPIO_OUTPUT_DIRECTION,
  .lcd_data_8_bit[7].port = PORTD_INDEX,
  .lcd_data_8_bit[7].pin = GPIO_PIN7,
  .lcd_data_8_bit[7].logic = GPIO_LOW,
  .lcd_data_8_bit[7].direction = GPIO_OUTPUT_DIRECTION
};*/


keypad_t kaypad_1 = {
    .keypad_row_pins[0].pin = GPIO_PIN0,
    .keypad_row_pins[1].pin = GPIO_PIN1,
    .keypad_row_pins[2].pin = GPIO_PIN2,
    .keypad_row_pins[3].pin = GPIO_PIN3,
    .keypad_row_pins[0].port = PORTD_INDEX,
    .keypad_row_pins[1].port = PORTD_INDEX,
    .keypad_row_pins[2].port = PORTD_INDEX,
    .keypad_row_pins[3].port = PORTD_INDEX,
    .keypad_row_pins[0].logic = GPIO_LOW,
    .keypad_row_pins[1].logic = GPIO_LOW,
    .keypad_row_pins[2].logic = GPIO_LOW,
    .keypad_row_pins[3].logic = GPIO_LOW,
    .keypad_row_pins[0].direction = GPIO_OUTPUT_DIRECTION,
    .keypad_row_pins[1].direction = GPIO_OUTPUT_DIRECTION,
    .keypad_row_pins[2].direction = GPIO_OUTPUT_DIRECTION,
    .keypad_row_pins[3].direction = GPIO_OUTPUT_DIRECTION,
    .keypad_colomns_pins[0].pin = GPIO_PIN4,
    .keypad_colomns_pins[1].pin = GPIO_PIN5,
    .keypad_colomns_pins[2].pin = GPIO_PIN6,
    .keypad_colomns_pins[3].pin = GPIO_PIN7,
    .keypad_colomns_pins[0].port = PORTD_INDEX,
    .keypad_colomns_pins[1].port = PORTD_INDEX,
    .keypad_colomns_pins[2].port = PORTD_INDEX,
    .keypad_colomns_pins[3].port = PORTD_INDEX,
    .keypad_colomns_pins[0].logic = GPIO_LOW,
    .keypad_colomns_pins[1].logic = GPIO_LOW,
    .keypad_colomns_pins[2].logic = GPIO_LOW,
    .keypad_colomns_pins[3].logic = GPIO_LOW,
    .keypad_colomns_pins[0].direction = GPIO_INPUT_DIRECTION,
    .keypad_colomns_pins[1].direction = GPIO_INPUT_DIRECTION,
    .keypad_colomns_pins[2].direction = GPIO_INPUT_DIRECTION,
    .keypad_colomns_pins[3].direction = GPIO_INPUT_DIRECTION,
};

void welcome_massege(void){
    for(int i = 1; i <= 6; i++){
        lcd_4_bit_send_string_pos(&lcd_1, 1, i, "Hello All");
        lcd_4_bit_send_string_pos(&lcd_1, 2, 5, "!Calculator!");
        _delay(250000);
        lcd_4_bit_send_string_pos(&lcd_1, 1, i, " ");
    }
    lcd_4_bit_send_string_pos(&lcd_1, 1, 1, "                  ");
    lcd_4_bit_send_string_pos(&lcd_1, 1, 6, "Hello All");
}

void loading(void){
    lcd_4_bit_send_string_pos(&lcd_1, 1, 1, "Loading");
    for(int i = 8; i <= 15; i++){
        lcd_4_bit_send_char_data_pos(&lcd_1, 1, i, '.');
        _delay(250000);
    }
}

void tostring(char [], long int);

uint32 val = 1; 

char key_val = 'A';

uint8 flag = 0;

char str1[32] = ""; 
char str2[32] = ""; 
char process;
long int n1 = 0;
long int n2 = 0;
long int res = 0;

char res_lcd[64] = "";

uint8 val_text[4];

const uint8 customChar[] = {
  0x0E,
  0x0A,
  0x11,
  0x11,
  0x11,
  0x11,
  0x1F,
  0x00
};

int main() { 
    Application_initialize();
    welcome_massege();
    lcd_4_bit_send_command(&lcd_1, LCD_CLEAR);
    lcd_4_bit_send_command(&lcd_1, LCD_CURSOR_ON_BLINK_OFF);
    loading();
    lcd_4_bit_send_command(&lcd_1, LCD_CLEAR);
    while(1){
        keypad_get_value(&kaypad_1, &key_val);
        _delay(100000);
        if(key_val != 'A' && flag == 0){
            if(key_val == '#'){
                lcd_4_bit_send_command(&lcd_1, LCD_CLEAR);
                flag = 0;
                memset(str1, '\0', 32); 
                memset(str2, '\0', 32); 
                process = NULL;
                n1 = 0;
                n2 = 0;
                res = 0;
                memset(res_lcd, '\0', 64);
                key_val = 'A';
                _delay(100000);
            }
            else if(key_val == '*' || key_val == '-' || key_val == '+' || key_val == '/'){
                lcd_4_bit_send_char_data(&lcd_1, key_val);
                process = key_val;
                _delay(100000);
                key_val = 'A';
                _delay(100000);
                flag = 1;
            }
            else{
                strncat(str1, &key_val, 1);
                lcd_4_bit_send_char_data(&lcd_1, key_val);
                _delay(100000);
                key_val = 'A';
                _delay(100000);
            }
        }
        else if(key_val != 'A' && flag == 1){
            if(key_val == '#'){
                lcd_4_bit_send_command(&lcd_1, LCD_CLEAR);
                flag = 0;
                memset(str1, '\0', 32);
                memset(str2, '\0', 32);
                process = NULL;
                n1 = 0;
                n2 = 0;
                res = 0;
                memset(res_lcd, '\0', 64);
                key_val = 'A';
                _delay(100000);
            }
            else if(key_val == '='){
                lcd_4_bit_send_char_data(&lcd_1, key_val);
                _delay(100000);
                n1 = atoi(str1);
                n2 = atoi(str2);
                if(process == '+') res = n1 + n2;
                else if(process == '-') res = n1 - n2;
                else if(process == '*') res = n1 * n2;
                else if(process == '/') res = n1 / n2;
                if(res == 0) lcd_4_bit_send_char_data(&lcd_1, '0');
                else {
                    memset(res_lcd, '\0', 64);
                    tostring(res_lcd, res);
                    lcd_4_bit_send_string(&lcd_1, res_lcd);
                }
                _delay(100000);
                key_val = 'A';
                _delay(100000);
            }
            else {
                strncat(str2, &key_val, 1);
                lcd_4_bit_send_char_data(&lcd_1, key_val);
                _delay(100000);
                key_val = 'A';
                _delay(100000);
            }
        }
        //convert_byte_to_string(key_val, val_text);
        //lcd_4_bit_send_string_pos(&lcd_1, 1, 10, val_text);
    }
    return (EXIT_SUCCESS);
}

/* initialize any pin with direction & logic */
void Application_initialize(void){
   lcd_4_bit_initialize(&lcd_1);
   keypad_initialize(&kaypad_1);
}


void tostring(char str[], long int num)
{
    long int i, rem, len = 0, n;
 
    n = num;
    while (n != 0)
    {
        len++;
        n /= 10;
    }
    for (i = 0; i < len; i++)
    {
        rem = num % 10;
        num = num / 10;
        str[len - (i + 1)] = rem + '0';
    }
    str[len] = '\0';
}