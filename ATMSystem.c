#include <stdio.h>
#include <stdlib.h>

int transact();
int transactionProcess();
int depositTransact();
int userCardInput;
int userPin;
int cardNumber;
int pin;
int atmBalance = 0;
int try = 4;
int process;
char withdraw[];
char deposit[];
char ch;
char transferCard[];
char transferAmount[];
struct atmCard
{
    int cardNum, pin, atmBalance;
};

struct atmCard user1 = {.cardNum = 202011019, .pin = 2487, .atmBalance = 50000};
struct atmCard user2 = {.cardNum = 202011020, .pin = 8989, .atmBalance = 30000};

int withdrawTransact()
{
    printf("\n================== WITHDRAWAL TRANSACTION ==================\n");
    printf("Current Balance: $%d", atmBalance);
    do
    {

        printf("\n\t\tEnter 'c' to cancel the transaction");
        printf("\nEnter the amount of money that you would like to withdraw: ");
        scanf("%s", &withdraw);
        if (withdraw[0] == 'c')
        {
            printf("Transaction is Cancelled\n");
            return transactionProcess();
        }
        else
        {
            int num = atoi(withdraw);
            if (num > atmBalance)
            {
                printf("Insufficient Balance");
                if (atmBalance == 0)
                {
                    printf(" You currently have $%d in your Account, Please Deposit Appropriate Amount\n", atmBalance);
                    return depositTransact();
                }
            }
            else if (num <= atmBalance)
            {
                atmBalance = atmBalance - num;
                printf("\nNew Balance: $%d", atmBalance);
                printf("\nSuccess: Approved Bank Withdrawal\n\n");
                return transactionProcess();
            }
        }
    } while (withdraw > atmBalance);
    printf("\n==========================================================\n");

}

int depositTransact()
{
    printf("\n================== DEPOSIT TRANSACTION ==================\n");
    printf("\n\t\tEnter 'c' to cancel the transaction");
    printf("\nCurrent Balance: $%d\n", atmBalance);
    printf("Enter the amount that you would like to deposit: $");
    scanf("%s", &deposit);
    if (deposit[0] == 'c')
    {
        printf("Transaction is Cancelled\n");
        return transactionProcess();
    }
    else
    {
        int num = atoi(deposit);
        atmBalance += num;
        printf("\nUpdated Balance: $%d", atmBalance);
        return transactionProcess();
    }
    printf("\n==========================================================\n");

}

int inquiryTransact()
{
    printf("\n================== INQUIRY TRANSACTION ==================\n");
    printf("\nAccount Number: %d\n", cardNumber);
    printf("\n\tCurrent Savings: $%d\n", atmBalance);
    printf("\n==========================================================\n");

    return transactionProcess();
}

int transferTransact()
{
    printf("\n================== TRANSFER TRANSACTION ==================\n");
    printf("\n\t\tEnter 'c' to cancel the transaction");
    printf("\nEnter the card number from which you wish to transfer funds: ");
    scanf("%s", &transferCard);
    if (transferCard[0] == 'c')
    {
        printf("Transaction is Cancelled\n");
        return transactionProcess();
    }
    int num = atoi(transferCard);
    if (num == user1.cardNum)
    {
        printf("\n\t\tEnter 'c' to cancel the transaction");
        printf("\n Account Details\n");
        printf("\n Account No: %d\n Current Balance: %d", user1.cardNum, user1.atmBalance);
        printf("\nEnter the amount that you want to transfer: $");
        scanf("%s", &transferAmount);
        if (transferAmount[0] == 'c')
        {
            printf("Transaction is Cancelled\n");
            return transactionProcess();
        }
        else
        {
            int num = atoi(transferAmount);
            atmBalance -= num;
            num += user1.atmBalance;
            printf("\nSuccessfully!! Transferred Funds to %d", user1.cardNum);
            printf("\n Account No: %d New Balance: %d", user1.cardNum, user1.atmBalance);
        }
    }
    else if (num == user2.cardNum)
    {
        printf("\n Account Details\n");
        printf("\n Account No: %d\n Current Balance: %d", user2.cardNum, user2.atmBalance);
        printf("\nEnter the amount that you want to transfer: $");
        scanf("%s", &transferAmount);
        if (transferAmount[0] == 'c')
        {
            printf("Transaction is Cancelled\n");
            return transactionProcess();
        }
        else
        {
            int num = atoi(transferAmount);
            atmBalance -= num;
            num += user2.atmBalance;
            printf("Successfully!! Transferred Funds to %d", user2.cardNum);
            printf("\n Account No: %d \nNew Balance: %d", user2.cardNum, user2.atmBalance);
        }
    }
    else
    {
        printf("\n Invalid Input");
    }
    printf("\n==========================================================\n");

}

int transactionProcess()
{
    printf("\n\t\t\tTransaction Process\n");
    printf("\t1: Withdraw");
    printf("\t2: Deposit");
    printf("\t3: Transfer");
    printf("\t4: Inquiry");
    printf("\t5: Exit");
    printf("\t\t\n\nPlease select a process: ");
    scanf("%d", &process);

    switch (process)
    {
    case 1:
        withdrawTransact();
        break;
    case 2:
        depositTransact();
        break;
    case 3:
        transferTransact();
        break;
    case 4:
        inquiryTransact();
        break;
    case 5:
        printf("\n\nThank you for using CodeD ATM System! :>");
        return 0;
        break;
    default:
        printf("\nInvalid Input");
        break;
    }
}
int transact()
{
    do
    {
        printf("\t\tPlease enter your pin number: ");
        scanf("%d", &userPin);
        if (userPin == pin)
        {
            transactionProcess();
            return 0;
        }
        else
        {
            printf("\t\t\nInvalid Pin\n");
            try = try - 1;
            if (try == 0)
            {
                printf("You have used all of your chances, please contact the bank for further assistance");
                return 0;
            }
            printf("You only have %d tries left\n", try);
        }
    } while (try >= 0);
}

int main()
{
    printf("\n====================--Welcome to CodeD ATM System--====================\n");
    printf("\tPlease enter your account number: ");
    scanf("%d", &userCardInput);
    if (userCardInput == user1.cardNum)
    {
        pin += user1.pin;
        atmBalance += user1.atmBalance;
        cardNumber += user1.cardNum;
        transact();
        return 0;
    }
    else if (userCardInput == user2.cardNum)
    {
        pin += user2.pin;
        atmBalance += user2.atmBalance;
        cardNumber += user2.cardNum;
        transact();
        return 0;
    }
    else
    {
        printf("\t\tAccount number is unidentified");
        return 0;
    }
    return 0;
}
