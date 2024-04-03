/**
 * @file pow.h
 * @author SOPER teaching team.
 * @brief Computation of the POW.
 * @version 1.0
 * @date 2022-01-26
 *
 * @copyright Copyright (c) 2022
 *
 */

#ifndef _POW_H
#define _POW_H

#define POW_LIMIT 99997669 /*!< Maximum number for the hash result. */
#define MAX_STR_LGH 256

/**
 * @brief Computes the following hash function:
 * f(x) = (X x + Y) % P.
 *
 * @param x Argument of the hash function, x.
 * @return Result of the hash function, f(x).
 */
long int pow_hash(long int x);

#endif