#pragma region Registers

typedef struct mp3924_register {
    uint8_t register_start;
    uint8_t register_size;
} mp3924_register;

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

#pragma endregion

#pragma region Configuration Registers

const mp3924_register MODE_SETTING = {
    .register_start = 0x03,
    .register_size = 1
};

const mp3924_register MIDSPAN_SETTING = {
    .register_start = 0x04,
    .register_size = 1
};

const mp3924_register PORT_ENABLE = {
    .register_start = 0x05,
    .register_size = 1
};

const mp3924_register DET_CLS_ENABLE = {
    .register_start = 0x06,
    .register_size = 1
};

const mp3924_register DISCONNECT_ENABLE = {
    .register_start = 0x07,
    .register_size = 1
};

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

const mp3924_register PMAX_SHUTDOWN_PRIORITY = {
    .register_start = 0x0D,
    .register_size = 1
};

const mp3924_register INTERRUPT_ENABLE = {
    .register_start = 0x0E,
    .register_size = 1
};

const mp3924_register GENERAL_CONTROL = {
    .register_start = 0x0F,
    .register_size = 1
};

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

const mp3924_register POWER_SOURCE_STATUS2 = {
    .register_start = 0x22,
    .register_size = 1
};

const mp3924_register DET_CLS_COMPLETE_STATUS = {
    .register_start = 0x24,
    .register_size = 1
};

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

const mp3924_register POWER_STATUS = {
    .register_start = 0x2A,
    .register_size = 1
};

const mp3924_register POWER_STATUS_CHANGE = {
    .register_start = 0x2B,
    .register_size = 1
};

const mp3924_register OVER_LOAD_STATUS = {
    .register_start = 0x2D,
    .register_size = 1
};

const mp3924_register CURRENT_LIMIT_STATUS = {
    .register_start = 0x2F,
    .register_size = 1
};

const mp3924_register DISCONNECT_STATUS = {
    .register_start = 0x31,
    .register_size = 1
};

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

void init_mp3924_port();

uint16_t get_register_value(mp3924_register reg);