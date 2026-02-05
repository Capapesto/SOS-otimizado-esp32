#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

void pisca_led(int tempo, int vezes, int pino){
 gpio_set_direction(pino, GPIO_MODE_OUTPUT);   
    for (int i = 0; i < vezes; i++)
    {
         gpio_set_level(pino,1);
     vTaskDelay(tempo / portTICK_PERIOD_MS);
     gpio_set_level(pino,0);
     vTaskDelay(200 / portTICK_PERIOD_MS);
      
  
}
    }
void S(){
     pisca_led(100, 3, 23);
}
void O(){
     pisca_led(500, 3, 5);
}
void app_main() {
 
  while (true) {
    S();
    O();
    S();
     vTaskDelay(2000 / portTICK_PERIOD_MS);
  }
 
  
}
