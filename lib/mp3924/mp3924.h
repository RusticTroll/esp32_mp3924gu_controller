#ifndef INC_MP3924_H
#define INC_MP3924_H

#pragma region Registers

typedef struct mp3924_register {
    uint8_t register_start;
    uint8_t register_size;
} mp3924_register;

#pragma region Interrupts

extern const mp3924_register INTERRUPT;

extern const mp3924_register INTERRUPT_MASK;

extern const mp3924_register INTERRUPT_PRIORITY;

extern const uint8_t VIN_FAILURE;
extern const uint8_t STARTUP_FAILURE;
extern const uint8_t OVERCURRENT_PROTECTION;
extern const uint8_t CLASSIFICATION_COMPLETION;
extern const uint8_t DETECTION_COMPLETION;
extern const uint8_t DC_DISCONNECTION;
extern const uint8_t POWER_GOOD_CHANGE;
extern const uint8_t POWER_ENABLE_CHANGE;

#pragma endregion

#pragma region Configuration Registers

extern const mp3924_register MODE_SETTING;

extern const uint8_t MODE_4;
extern const uint8_t MODE_3;
extern const uint8_t MODE_2;
extern const uint8_t MODE_1;

extern const mp3924_register MIDSPAN_SETTING;

extern const uint8_t MIDSPAN_4;
extern const uint8_t MIDSPAN_3;
extern const uint8_t MIDSPAN_2;
extern const uint8_t MIDSPAN_1;

extern const mp3924_register PORT_ENABLE;

extern const uint8_t ENAL;
extern const uint8_t EN4;
extern const uint8_t EN3;
extern const uint8_t EN2;
extern const uint8_t EN1;

extern const mp3924_register DET_CLS_ENABLE;

extern const uint8_t CLSEN4;
extern const uint8_t CLSEN3;
extern const uint8_t CLSEN2;
extern const uint8_t CLSEN1;
extern const uint8_t DETEN4;
extern const uint8_t DETEN3;
extern const uint8_t DETEN2;
extern const uint8_t DETEN1;

extern const mp3924_register DISCONNECT_ENABLE;

extern const uint8_t DISEN4;
extern const uint8_t DISEN3;
extern const uint8_t DISEN2;
extern const uint8_t DISEN1;

extern const mp3924_register FAULT_TIMER;

extern const mp3924_register FOLDBACK_ILIM;

extern const mp3924_register TWO_EVENT_CLASS_FIVE_ENABLE;

extern const uint8_t TWO_EVENT4;
extern const uint8_t TWO_EVENT3;
extern const uint8_t TWO_EVENT2;
extern const uint8_t TWO_EVENT1;

extern const mp3924_register PMAX_SHUTDOWN_PRIORITY;

extern const mp3924_register INTERRUPT_ENABLE;

extern const mp3924_register GENERAL_ENABLE_CONTROL;

extern const uint8_t PMAXEN;
extern const uint8_t ADCEN;
extern const uint8_t WDEN;

#pragma endregion

#pragma region Manual Control Registers

extern const mp3924_register DET_CLS_TRIGGER;

extern const mp3924_register POWER_ON_OFF_TRIGGER;

extern const mp3924_register LEGACY_ENABLE;

#pragma endregion

#pragma region Current Limit Configuration Registers

extern const mp3924_register ICUT1_THRESHOLD;

extern const mp3924_register ICUT2_THRESHOLD;

extern const mp3924_register ICUT3_THRESHOLD;

extern const mp3924_register ICUT4_THRESHOLD;

extern const mp3924_register ILIM1_THRESHOLD;

extern const mp3924_register ILIM2_THRESHOLD;

extern const mp3924_register ILIM3_THRESHOLD;

extern const mp3924_register ILIM4_THRESHOLD;

#pragma endregion

#pragma region Status Registers

extern const mp3924_register POWER_SOURCE_STATUS1;

extern const uint8_t FETF4;
extern const uint8_t FETF3;
extern const uint8_t FETF2;
extern const uint8_t FETF1;
extern const uint8_t VCCUV;
extern const uint8_t OTP;
extern const uint8_t VINOV;
extern const uint8_t VINUV;

extern const mp3924_register POWER_SOURCE_STATUS2;

extern const uint8_t VINOK;
extern const uint8_t OVPMAX;

extern const mp3924_register DET_CLS_COMPLETE_STATUS;

extern const uint8_t CLSC4;
extern const uint8_t CLSC3;
extern const uint8_t CLSC2;
extern const uint8_t CLSC1;
extern const uint8_t DETC4;
extern const uint8_t DETC3;
extern const uint8_t DETC2;
extern const uint8_t DETC1;

extern const mp3924_register DET_CLS_RESULT1;

extern const mp3924_register DET_CLS_RESULT2;

extern const mp3924_register DET_CLS_RESULT3;

extern const mp3924_register DET_CLS_RESULT4;

extern const uint8_t CLSR;
extern const uint8_t TWO_EVENTC;
extern const uint8_t DETR;

extern const mp3924_register POWER_STATUS;

extern const mp3924_register POWER_STATUS_CHANGE;

extern const uint8_t PG4;
extern const uint8_t PG3;
extern const uint8_t PG2;
extern const uint8_t PG1;
extern const uint8_t PEN4;
extern const uint8_t PEN3;
extern const uint8_t PEN2;
extern const uint8_t PEN1;

extern const mp3924_register OVER_LOAD_STATUS;

extern const uint8_t OCUT4;
extern const uint8_t OCUT3;
extern const uint8_t OCUT2;
extern const uint8_t OCUT1;
extern const uint8_t STF4;
extern const uint8_t STF3;
extern const uint8_t STF2;
extern const uint8_t STF1;

extern const mp3924_register CURRENT_LIMIT_STATUS;

extern const uint8_t OLIM4;
extern const uint8_t OLIM3;
extern const uint8_t OLIM2;
extern const uint8_t OLIM1;

extern const mp3924_register DISCONNECT_STATUS;

extern const uint8_t DCDIS4;
extern const uint8_t DCDIS3;
extern const uint8_t DCDIS2;
extern const uint8_t DCDIS1;

extern const mp3924_register WATCHDOG_STATUS;

extern const mp3924_register PIN_STATUS;

extern const mp3924_register LEGACY_DETECT_RESULT1;

extern const mp3924_register LEGACY_DETECT_RESULT2;

#pragma endregion

#pragma region ADC Results Registers

extern const mp3924_register PORT1_CURRENT;

extern const mp3924_register OUT1_PIN_VOLTAGE;

extern const mp3924_register PORT2_CURRENT;

extern const mp3924_register OUT2_PIN_VOLTAGE;

extern const mp3924_register PORT3_CURRENT;

extern const mp3924_register OUT3_PIN_VOLTAGE;

extern const mp3924_register PORT4_CURRENT;

extern const mp3924_register OUT4_PIN_VOLTAGE;

extern const mp3924_register INPUT_VOLTAGE;

extern const mp3924_register JUNCTION_TEMPERATURE;

extern const mp3924_register PMAX_POWER_SETTING;

extern const mp3924_register DIE_ID;

#pragma endregion

#pragma endregion

void init_mp3924_port();

void set_register_value(mp3924_register reg, uint8_t value);

uint16_t get_register_value(mp3924_register reg);

#endif