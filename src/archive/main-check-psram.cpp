#include "esp_err.h"
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include <inttypes.h>
#include <stdio.h>
#if CONFIG_SPIRAM
#include "esp_psram.h"
#endif

static const char *TAG = "MAIN";

extern "C" void app_main() {
#if CONFIG_SPIRAM
    size_t psram_size = esp_psram_get_size();
    ESP_LOGI(TAG, "PSRAM size: %d bytes", psram_size);
#endif
    ESP_LOGI(TAG, "MALLOC_CAP_SPIRAM: %d bytes",
             heap_caps_get_free_size(MALLOC_CAP_SPIRAM));
    ESP_LOGI(TAG, "Free heap size: %" PRIu32, esp_get_free_heap_size());
}