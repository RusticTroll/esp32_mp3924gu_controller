#include "freertos/FreeRTOS.h"

#include "esp_log.h"

#include "driver/i2c_master.h"

#include "mp3924.h"

static const char *TAG = "MP3924";

#pragma region Registers

#pragma region Interrupts

const mp3924_register INTERRUPT = {
    .register_start = 0x00,
    .register_size = 1
};

const mp3924_register INTERRUPT_MASK = {
    .register_start = 0x01,
    .register_size = 1
};

const mp3924_register INTERRUPT_PRIORITY = {
    .register_start = 0x02,
    .register_size = 1
};

const uint8_t VIN_FAILURE = BIT7;
const uint8_t STARTUP_FAILURE = BIT6;
const uint8_t OVERCURRENT_PROTECTION = BIT5;
const uint8_t CLASSIFICATION_COMPLETION = BIT4;
const uint8_t DETECTION_COMPLETION = BIT3;
const uint8_t DC_DISCONNECTION = BIT2;
const uint8_t POWER_GOOD_CHANGE = BIT1;
const uint8_t POWER_ENABLE_CHANGE = BIT0;

#pragma endregion

#pragma region Configuration Registers

const mp3924_register MODE_SETTING = {
    .register_start = 0x03,
    .register_size = 1
};

const uint8_t MODE_4 = BIT7 | BIT6;
const uint8_t MODE_3 = BIT5 | BIT4;
const uint8_t MODE_2 = BIT3 | BIT2;
const uint8_t MODE_1 = BIT1 | BIT0;

const mp3924_register MIDSPAN_SETTING = {
    .register_start = 0x04,
    .register_size = 1
};

const uint8_t MIDSPAN_4 = BIT3;
const uint8_t MIDSPAN_3 = BIT2;
const uint8_t MIDSPAN_2 = BIT1;
const uint8_t MIDSPAN_1 = BIT0;

const mp3924_register PORT_ENABLE = {
    .register_start = 0x05,
    .register_size = 1
};

const uint8_t ENAL = BIT4;
const uint8_t EN4 = BIT3;
const uint8_t EN3 = BIT2;
const uint8_t EN2 = BIT1;
const uint8_t EN1 = BIT0;

const mp3924_register DET_CLS_ENABLE = {
    .register_start = 0x06,
    .register_size = 1
};

const uint8_t CLSEN4 = BIT7;
const uint8_t CLSEN3 = BIT6;
const uint8_t CLSEN2 = BIT5;
const uint8_t CLSEN1 = BIT4;
const uint8_t DETEN4 = BIT3;
const uint8_t DETEN3 = BIT2;
const uint8_t DETEN2 = BIT1;
const uint8_t DETEN1 = BIT0;

const mp3924_register DISCONNECT_ENABLE = {
    .register_start = 0x07,
    .register_size = 1
};

const uint8_t DISEN4 = BIT3;
const uint8_t DISEN3 = BIT2;
const uint8_t DISEN2 = BIT1;
const uint8_t DISEN1 = BIT0;

const mp3924_register FAULT_TIMER = {
    .register_start = 0x08,
    .register_size = 1
};

const mp3924_register FOLDBACK_ILIM = {
    .register_start = 0x0B,
    .register_size = 1
};

const mp3924_register TWO_EVENT_CLASS_FIVE_ENABLE = {
    .register_start = 0x0C,
    .register_size = 1
};

const uint8_t TWO_EVENT4 = BIT3;
const uint8_t TWO_EVENT3 = BIT2;
const uint8_t TWO_EVENT2 = BIT1;
const uint8_t TWO_EVENT1 = BIT0;

const mp3924_register PMAX_SHUTDOWN_PRIORITY = {
    .register_start = 0x0D,
    .register_size = 1
};

const mp3924_register INTERRUPT_ENABLE = {
    .register_start = 0x0E,
    .register_size = 1
};

const mp3924_register GENERAL_ENABLE_CONTROL = {
    .register_start = 0x0F,
    .register_size = 1
};

const uint8_t PMAXEN = BIT2;
const uint8_t ADCEN = BIT1;
const uint8_t WDEN = BIT0;

#pragma endregion

#pragma region Manual Control Registers

const mp3924_register DET_CLS_TRIGGER = {
    .register_start = 0x10,
    .register_size = 1
};

const mp3924_register POWER_ON_OFF_TRIGGER = {
    .register_start = 0x11,
    .register_size = 1
};

const mp3924_register LEGACY_ENABLE = {
    .register_start = 0x12,
    .register_size = 1
};

#pragma endregion

#pragma region Current Limit Configuration Registers

const mp3924_register ICUT1_THRESHOLD = {
    .register_start = 0x13,
    .register_size = 1
};

const mp3924_register ICUT2_THRESHOLD = {
    .register_start = 0x14,
    .register_size = 1
};

const mp3924_register ICUT3_THRESHOLD = {
    .register_start = 0x15,
    .register_size = 1
};

const mp3924_register ICUT4_THRESHOLD = {
    .register_start = 0x16,
    .register_size = 1
};

const mp3924_register ILIM1_THRESHOLD = {
    .register_start = 0x17,
    .register_size = 1
};

const mp3924_register ILIM2_THRESHOLD = {
    .register_start = 0x18,
    .register_size = 1
};

const mp3924_register ILIM3_THRESHOLD = {
    .register_start = 0x19,
    .register_size = 1
};

const mp3924_register ILIM4_THRESHOLD = {
    .register_start = 0x1A,
    .register_size = 1
};

#pragma endregion

#pragma region Status Registers

const mp3924_register POWER_SOURCE_STATUS1 = {
    .register_start = 0x20,
    .register_size = 1
};

const uint8_t FETF4 = BIT7;
const uint8_t FETF3 = BIT6;
const uint8_t FETF2 = BIT5;
const uint8_t FETF1 = BIT4;
const uint8_t VCCUV = BIT3;
const uint8_t OTP = BIT2;
const uint8_t VINOV = BIT1;
const uint8_t VINUV = BIT0;

const mp3924_register POWER_SOURCE_STATUS2 = {
    .register_start = 0x22,
    .register_size = 1
};

const uint8_t VINOK = BIT1;
const uint8_t OVPMAX = BIT0;

const mp3924_register DET_CLS_COMPLETE_STATUS = {
    .register_start = 0x24,
    .register_size = 1
};

const uint8_t CLSC4 = BIT7;
const uint8_t CLSC3 = BIT6;
const uint8_t CLSC2 = BIT5;
const uint8_t CLSC1 = BIT4;
const uint8_t DETC4 = BIT3;
const uint8_t DETC3 = BIT2;
const uint8_t DETC2 = BIT1;
const uint8_t DETC1 = BIT0;

const mp3924_register DET_CLS_RESULT1 = {
    .register_start = 0x26,
    .register_size = 1
};

const mp3924_register DET_CLS_RESULT2 = {
    .register_start = 0x27,
    .register_size = 1
};

const mp3924_register DET_CLS_RESULT3 = {
    .register_start = 0x28,
    .register_size = 1
};

const mp3924_register DET_CLS_RESULT4 = {
    .register_start = 0x29,
    .register_size = 1
};

const uint8_t CLSR = BIT7 | BIT6 | BIT5 | BIT4;
const uint8_t TWO_EVENTC = BIT3;
const uint8_t DETR = BIT2 | BIT1 | BIT0;

const mp3924_register POWER_STATUS = {
    .register_start = 0x2A,
    .register_size = 1
};

const mp3924_register POWER_STATUS_CHANGE = {
    .register_start = 0x2B,
    .register_size = 1
};

const uint8_t PG4 = BIT7;
const uint8_t PG3 = BIT6;
const uint8_t PG2 = BIT5;
const uint8_t PG1 = BIT4;
const uint8_t PEN4 = BIT3;
const uint8_t PEN3 = BIT2;
const uint8_t PEN2 = BIT1;
const uint8_t PEN1 = BIT0;

const mp3924_register OVER_LOAD_STATUS = {
    .register_start = 0x2D,
    .register_size = 1
};

const uint8_t OCUT4 = BIT7;
const uint8_t OCUT3 = BIT6;
const uint8_t OCUT2 = BIT5;
const uint8_t OCUT1 = BIT4;
const uint8_t STF4 = BIT3;
const uint8_t STF3 = BIT2;
const uint8_t STF2 = BIT1;
const uint8_t STF1 = BIT0;

const mp3924_register CURRENT_LIMIT_STATUS = {
    .register_start = 0x2F,
    .register_size = 1
};

const uint8_t OLIM4 = BIT3;
const uint8_t OLIM3 = BIT2;
const uint8_t OLIM2 = BIT1;
const uint8_t OLIM1 = BIT0;

const mp3924_register DISCONNECT_STATUS = {
    .register_start = 0x31,
    .register_size = 1
};

const uint8_t DCDIS4 = BIT3;
const uint8_t DCDIS3 = BIT2;
const uint8_t DCDIS2 = BIT1;
const uint8_t DCDIS1 = BIT0;

const mp3924_register WATCHDOG_STATUS = {
    .register_start = 0x33,
    .register_size = 1
};

const mp3924_register PIN_STATUS = {
    .register_start = 0x34,
    .register_size = 1
};

const mp3924_register LEGACY_DETECT_RESULT1 = {
    .register_start = 0x35,
    .register_size = 1
};

const mp3924_register LEGACY_DETECT_RESULT2 = {
    .register_start = 0x36,
    .register_size = 1
};

#pragma endregion

#pragma region ADC Results Registers

const mp3924_register PORT1_CURRENT = {
    .register_start = 0x40,
    .register_size = 2
};

const mp3924_register OUT1_PIN_VOLTAGE = {
    .register_start = 0x42,
    .register_size = 2
};

const mp3924_register PORT2_CURRENT = {
    .register_start = 0x44,
    .register_size = 2
};

const mp3924_register OUT2_PIN_VOLTAGE = {
    .register_start = 0x46,
    .register_size = 2
};

const mp3924_register PORT3_CURRENT = {
    .register_start = 0x48,
    .register_size = 2
};

const mp3924_register OUT3_PIN_VOLTAGE = {
    .register_start = 0x4A,
    .register_size = 2
};

const mp3924_register PORT4_CURRENT = {
    .register_start = 0x4C,
    .register_size = 2
};

const mp3924_register OUT4_PIN_VOLTAGE = {
    .register_start = 0x4E,
    .register_size = 2
};

const mp3924_register INPUT_VOLTAGE = {
    .register_start = 0x50,
    .register_size = 2
};

const mp3924_register JUNCTION_TEMPERATURE = {
    .register_start = 0x52,
    .register_size = 2
};

const mp3924_register PMAX_POWER_SETTING = {
    .register_start = 0x54,
    .register_size = 2
};

const mp3924_register DIE_ID = {
    .register_start = 0x50,
    .register_size = 1
};

#pragma endregion

#pragma endregion

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
    set_register_value(MODE_SETTING, 0xFF);
    set_register_value(DET_CLS_ENABLE, 0xFF);
    set_register_value(DISCONNECT_ENABLE, 0x0F);
    set_register_value(TWO_EVENT_CLASS_FIVE_ENABLE, 0x0F);
    set_register_value(GENERAL_ENABLE_CONTROL, PMAXEN | ADCEN);
}

void set_register_value(mp3924_register reg, uint8_t value) {
    uint8_t write_buffer[2] = {reg.register_start, value};
    i2c_master_transmit(mp3924_handle, write_buffer, 2, 50);
}

uint16_t get_register_value(mp3924_register reg) {
    uint16_t return_value = 0;
    uint8_t write_buffer[1] = {reg.register_start};
    uint8_t read_buffer[1] = {0};
    i2c_master_transmit_receive(mp3924_handle, write_buffer, 1, read_buffer, 1, 50);
    return_value = read_buffer[0];

    if (reg.register_size == 2) {
        i2c_master_receive(mp3924_handle, read_buffer, 1, 50);
        return_value += read_buffer[0] << 8;
    }

    return return_value;
}