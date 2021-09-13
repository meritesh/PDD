
#ifndef _ADC_H_
#define _ADC_H_

#ifdef __cplusplus
extern "C" {
#endif


/**
 * \fn void adc_sampling_frequency_availability()
 * \brief shows ADC's available In voltage sampling frequency
 * \param no parameter
 */
void adc_sampling_frequency_availability();

/**
 * \fn void adc_in_voltage_sampling_frequency()
 * \brief shows ADC's current In voltage sampling frequency
 * \param no parameter
 */
void adc_in_voltage_sampling_frequency();

/**
 * \fn void adc_set_in_voltage_sampling_frequency(int new_frequency)
 * \brief sets In voltage sampling frequency for the ADCs
 * \param int sampling frequency to be set
 */
void adc_set_in_voltage_sampling_frequency(int new_frequency);

/**
 * \fn float adc_read(int adc_number)
 * \brief reads the analog input value
 * \param int ADC input number (0/1/8/9)
 */
float adc_read(int adc_number);



#ifdef __cplusplus
}
#endif
#endif
