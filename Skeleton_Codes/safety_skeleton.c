/*****************************************************************************************************************************************
 * File: safety_skeleton.c
 *
 * Purpose:
 * Student implementation of is_safe_state() function for Banker's Algorithm.
 * This function implements the safety algorithm to check if the system is in a safe state.
 *
 *****************************************************************************************************************************************/

#include "banker_header.h"

/* =======================================================================================================================================*/
/**
 * Check if the system is in a safe state using Banker's Algorithm
 * 
 * Safety Algorithm:
 * 1. Initialize Work = Available and Finish[i] = false for all threads
 * 2. Find a thread i such that Finish[i] == false and Need[i] <= Work
 * 3. If found: Work = Work + Allocation[i], Finish[i] = true, add i to safe_sequence
 * 4. Repeat step 2-3 until all threads finish or no progress can be made
 * 5. Return true if all threads finished (safe), false otherwise (unsafe)
 * 
 * @param allocation: Current allocation matrix [threads][resources]
 * @param need: Need matrix [threads][resources]
 * @param available: Available resources array
 * @param safe_sequence: Array to store the safe sequence (caller allocated)
 * @param n: Number of threads
 * @param m: Number of resources
 * @return: true if safe state exists, false otherwise
 */
bool is_safe_state(int allocation[][MAX_RESOURCES], 
                   int need[][MAX_RESOURCES], 
                   int available[], 
                   int safe_sequence[], 
                   int n, 
                   int m) {
    
    // TODO: Implement the safety algorithm    

}