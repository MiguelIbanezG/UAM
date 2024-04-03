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
#include <mqueue.h>

#define POW_LIMIT 99997669 /*!< Maximum number for the hash result. */
#define MAX_MESSAGE 1024
#define MQ_NAME "/queue_monitor"
#define SHM_NAME "/minerstruct_monitor"
#define SHM_INFO_NAME "/info_of_system"
#define SHM_BLOCK_NAME "/info_of_bloc"
#define MAX_MINERS 100
#define MAX_ROUNDS 100

typedef struct
{
    char type[80];
    long sol;
    long obj;
    pid_t pid;
} Message;

typedef struct
{
    int id;
    long target;
    long solution;
    pid_t winner;
    pid_t miners_pid[MAX_MINERS];
    int coins[MAX_MINERS];
    int n_votes;
    int positive_votes;
} Block;

typedef struct
{
    pid_t pid;
    char votes[MAX_ROUNDS * 2];
    int coins;
    int first;
    int active;
} Miner;

typedef struct
{

    char miners_shr_ids[MAX_MINERS][MAX_MESSAGE];
    pid_t pid_active_miners[MAX_MINERS];
    int sem_empty_id;
    int sem_fill_id;
    int sem_mutex_id;
} Info;

/**
 * @brief Computes the following hash function:
 * f(x) = (X x + Y) % P.
 *
 * @param x Argument of the hash function, x.
 * @return Result of the hash function, f(x).
 */
long int pow_hash(long int x);

#endif