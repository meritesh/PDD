

#ifndef _PWM_O_H_
#define _PWM_O_H_

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \fn void pwm_availability(int chip)
 * \brief checksfor PWM port availiability of the corresponding chip number
 * \param int PWM chip number (0/1/2/3)
 */
void pwm_availability(int chip);

/**
 * \fn void pwm_export(int chip)
 * \brief exports the PWM port of the corresponding chip number
 * \param int PWM chip number (0/1/2/3)
 */
void pwm_export(int chip);

/**
 * \fn void pwm_set_period(int chip, int Period)
 * \brief sets PWM period for the PWM port of the corresponding chip number
 * \param int PWM chip number (0/1/2/3)
 * \param int Period in nanoseconds
 */
void pwm_set_period(int chip, int Period);

/**
 * \fn void pwm_set_duty_cycle(int chip, int Period, int dratio)
 * \brief sets PWM duty cycle for the PWM port of the corresponding chip number
 * \param int PWM chip number (0/1/2/3)
 * \param int Period in nanoseconds
 * \param int dratio is the duty ratio in 0 to 100 scale
 */
void pwm_set_duty_cycle(int chip, int Period, int dratio);

/**
 * \fn void pwm_enable(int chip, int enable)
 * \brief enables the PWM port of the corresponding chip number
 * \param int PWM chip number (0/1/2/3)
 * \param int enable in nanoseconds
 */
void pwm_enable(int chip, int enable);

/**
 * \fn void pwm_unexport(int chip)
 * \brief unexports the PWM port of the corresponding chip number
 * \param int PWM chip number (0/1/2/3)
 */
void pwm_unexport(int chip);


#ifdef __cplusplus
}
#endif
#endif
