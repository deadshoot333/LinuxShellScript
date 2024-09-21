#include <stdio.h>
#include <pthread.h>

// Global variables
int account_balance = 300000;
pthread_mutex_t mutex;

// Function to perform a withdrawal
void* withdraw(void* arg) {
    int amount = *(int*)arg;
    
    // Lock the mutex to enter critical section
    pthread_mutex_lock(&mutex);
    
    if (account_balance >= amount) {
        account_balance -= amount;
        printf("Withdrawn: $%d, Current Balance: $%d\n", amount, account_balance);
    } else {
        printf("Insufficient balance for withdrawing $%d\n", amount);
    }
    
    // Unlock the mutex to exit critical section
    pthread_mutex_unlock(&mutex);
    
    return NULL;
}

// Function to perform a credit
void* credit(void* arg) {
    int amount = *(int*)arg;
    
    // Lock the mutex to enter critical section
    pthread_mutex_lock(&mutex);
    
    account_balance += amount;
    printf("Credited: $%d, Current Balance: $%d\n", amount, account_balance);
    
    // Unlock the mutex to exit critical section
    pthread_mutex_unlock(&mutex);
    
    return NULL;
}

int main() {
    pthread_t t1, t2, t3, t4;
    int withdraw_amounts[] = {20, 2000, 60};
    int credit_amount = 40000;

    // Initialize the mutex before creating threads
    pthread_mutex_init(&mutex, NULL);

    // Create threads for withdrawals
    pthread_create(&t1, NULL, withdraw, &withdraw_amounts[0]);
    pthread_create(&t2, NULL, withdraw, &withdraw_amounts[1]);
    pthread_create(&t3, NULL, withdraw, &withdraw_amounts[2]);

    // Create thread for credit
    pthread_create(&t4, NULL, credit, &credit_amount);

    // Wait for all threads to finish
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);
    pthread_join(t4, NULL);

    // Destroy the mutex after all threads complete
    pthread_mutex_destroy(&mutex);

    // Print the final account balance
    printf("Final Account Balance: $%d\n", account_balance);

    return 0;
}
