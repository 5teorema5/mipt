#pragma once

#include <stdint.h>

void init_bme();

int32_t compensate_temp(int32_t adc_T);
uint32_t compensate_pressure(int32_t adc_P);
uint32_t compensate_humidity(int32_t adc_H);

static inline void cs_select();
static inline void cs_deselect();

static void write_register(uint8_t reg, uint8_t data);
static void read_registers(uint8_t reg, uint8_t *buf, uint16_t len);
void read_compensation_parameters();

void indoor_navigation();
void not_indoor_navigation();

void bme280_read_raw(int32_t *humidity, int32_t *pressure, int32_t *temperature);