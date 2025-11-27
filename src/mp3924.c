#include "freertos/FreeRTOS.h"

#include "esp_log.h"

#include "driver/i2c_master.h"

#include "mp3924.h"

static const char *TAG = "MP3924";

const i2c_master_bus_config_t i2c_mst_config = 
{
    .clk_source = LP_I2C_SCLK_DEFAULT,
    .i2c_port = LP_I2C_NUM_0,
    .sda_io_num = 6,
    .scl_io_num = 7,
    .glitch_ignore_cnt = 7,
    .flags.enable_internal_pullup = false
};

const i2c_device_config_t mp3924_conf = 
{
    .dev_addr_length = I2C_ADDR_BIT_LEN_7,
    .device_address = 0b00101111,
    .scl_speed_hz = 100000
};

i2c_master_dev_handle_t mp3924_handle;

void init_mp3924_port()
{
    const TickType_t xDelay = 1000 / portTICK_PERIOD_MS;
    vTaskDelay(xDelay);

    i2c_master_bus_handle_t bus_handle;
    ESP_ERROR_CHECK(i2c_new_master_bus(&i2c_mst_config, &bus_handle));

    // Probe so the MP3924 knows we're here?
    i2c_master_probe(bus_handle, 0b00101111, 50);

    ESP_ERROR_CHECK(i2c_master_bus_add_device(bus_handle, &mp3924_conf, &mp3924_handle));

    ESP_LOGI(TAG, "MP3924 I2C connection established.");
}

uint16_t get_register_value(mp3924_register reg) {
    ESP_LOGI(TAG, "MP3924 I2C connection established.");
    
    uint16_t return_value = 0;
    uint8_t write_buffer[1] = {reg.register_start};
    uint8_t read_buffer[1] = {0};
    i2c_master_transmit_receive(mp3924_handle, write_buffer, 1, read_buffer, 1, 50);
}