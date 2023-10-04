#ifndef OTHER_H_INCLUDED
#define OTHER_H_INCLUDED

/**
 * @brief Returns dividend/divisor if divisor != 0, dividend otherwise.
 *
 * @param  dividend
 * @param  divisor
 * @return double
 */
double perform_safe_division(double dividend, double divisor);

/**
 * @brief Prints the static global variable from other.c
 *
 */
void print_static_global_variable_from_other_c();

#endif