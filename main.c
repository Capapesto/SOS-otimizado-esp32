#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

void pisca_ponto(){
     gpio_set_level(2,1);
     printf(".");
     vTaskDelay(300 / portTICK_PERIOD_MS);
     gpio_set_level(2,0);
     vTaskDelay(300 / portTICK_PERIOD_MS);
}

void pisca_traco(){
     gpio_set_level(2,1);
     printf("-");
     vTaskDelay(700 / portTICK_PERIOD_MS);
     gpio_set_level(2,0);
     vTaskDelay(500 / portTICK_PERIOD_MS);
}

void app_main() {
  gpio_set_direction(2,GPIO_MODE_OUTPUT);
  
  //mensagem
  while (true) {
      gpio_set_direction(2,GPIO_MODE_OUTPUT);
     pisca_ponto();
     pisca_ponto();
     pisca_ponto();
     
     pisca_traco();
     pisca_traco();
     pisca_traco();

     pisca_ponto();
     pisca_ponto();
     pisca_ponto();
     vTaskDelay(2000 / portTICK_PERIOD_MS);
  }
}
