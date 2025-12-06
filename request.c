/*****************************************************************************************************************************************
 * File: request_skeleton.c
 *
 * Purpose:
 * Student implementation of thread_resource_request() function for Banker's Algorithm.
 * This function processes resource allocation and deallocation requests.
 *
 *****************************************************************************************************************************************/

#include "banker_header.h"

/* =======================================================================================================================================*/
/**
 * Process a resource request from a thread
 * 
 * Algorithm:
 * 1. Validate thread_id bounds
 * 2. Handle resource requests (positive = allocate, negative = release):
 *    a. For allocation: Check if request <= need (don't exceed remaining need)
 *       For release: Check if thread has enough allocated resources
 *    b. Check if request <= available (resources must be available)
 * 3. Temporarily apply the changes:
 *    a. Update available resources: available[j] -= request[j]
 *    b. Update allocation: allocation[thread_id][j] += request[j]
 *    c. Update need: need[thread_id][j] -= request[j]
 * 4. Check if resulting state is safe using is_safe_state()
 * 5. If safe, keep allocation; if unsafe, rollback and deny
 * 
 * @param thread_id: ID of the requesting thread (0 to n-1)
 * @param request: Array of requested resources (positive = allocate, negative = release)
 * @param allocation: Current allocation matrix (may be modified)
 * @param need: Need matrix (may be modified)
 * @param available: Available resources array (may be modified)
 * @param n: Number of threads
 * @param m: Number of resources
 * @return: true if request is granted, false if denied
 */
bool thread_resource_request(int thread_id, int request[], 
                            int allocation[][MAX_RESOURCES], 
                            int need[][MAX_RESOURCES], 
                            int available[], int n, int m) {
    
    // TODO: Implement resource request processing    
    // Check request <= need
    for (int j = 0; j < m; j++) {
        if (request[j] > need[thread_id][j]) {
            return false;
        }
    }

    // Check request <= available
    for (int j = 0; j < m; j++) {
        if (request[j] > available[j]) {
            return false;
        }
    }

    // Temporary backups
    int old_available[m];
    int old_allocation[n][MAX_RESOURCES];
    int old_need[n][MAX_RESOURCES];

    // Save state
    for (int j = 0; j < m; j++) old_available[j] = available[j];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            old_allocation[i][j] = allocation[i][j];
            old_need[i][j] = need[i][j];
        }

    // Apply tentative request
    for (int j = 0; j < m; j++) {
        available[j] -= request[j];
        allocation[thread_id][j] += request[j];
        need[thread_id][j] -= request[j];
    }

    // Check safe state
    int temp_safe[n];
    if (is_safe_state(allocation, need, available, temp_safe, n, m)) {
        return true;
    }

    // Rollback
    for (int j = 0; j < m; j++) available[j] = old_available[j];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            allocation[i][j] = old_allocation[i][j];
            need[i][j] = old_need[i][j];
        }

    return false;
}