#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <sys/types.h>
#include <sys/types.h>
#include <fcntl.h>
#include <time.h>

int a = 202011019, b = 5000000, c = 333, i, j;
int width[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60};

// Functions
int transact();
int transactionProcess();
int depositTransact();
// int receipt();

// Variables
int userCardInput;
int userPin;
int cardNumber;
int pin;
int atmBalance = 0;
int try = 4;
int cancel = 1;
int process;
int num;
char confirm;
char withdraw[];
char deposit[];
char transferCard[];
char transferAmount[];

// Structs
struct atmCard
{
    int cardNum, pin, atmBalance;
};

struct atmCard user1 = {.cardNum = 202011019, .pin = 2487, .atmBalance = 50000};
struct atmCard user2 = {.cardNum = 202011020, .pin = 8989, .atmBalance = 30000};

int withdrawTransact()
{
    system("cls");
    purple();
    printf("\n=================================================================================\n");
    printf("\n============================--WITHDRAWAL TRANSACTION--===========================\n");
    printf("\n=================================================================================\n");
    reset();
    do
    {
        printf("\n\t\t\tEnter ");
        blue();
        printf("'*'");
        reset();
        printf(" to cancel the transaction\n");
        yellow();
        printf("\n\nCurrent Balance: $%d\n\n", atmBalance);
        reset();
        printf("\nEnter the amount of money that you would like to withdraw: $");
        green();
        scanf("%s", &withdraw);
        reset();
        if (withdraw[0] == '*')
        {
            system("cls");
            printf("\n=================================================================================\n");
            red();
            printf("\n\t\t\tWithdraw Transaction is Cancelled\n");
            reset();
            printf("\n=================================================================================\n");
            return transactionProcess();
        }
        if ((withdraw[0] >= 'a' && withdraw[0] <= 'z') || (withdraw[0] >= 'A' && withdraw[0] <= 'Z'))
        {
            return withdrawTransact();
        }

        num = atoi(withdraw);

        if (num > atmBalance)
        {
            system("cls");
            printf("\n=================================================================================\n");
            red();
            printf("\n\t     Insufficient Balance, Please Enter a Different Amount\n");
            reset();
            printf("\n=================================================================================\n");
            if (atmBalance == 0)
            {
                system("cls");
                printf("\n=================================================================================\n");
                red();
                printf("\n\tCurrent Balance is 0, Please Add Appropriate Funds to Account\n");
                reset();
                printf("\n=================================================================================\n");
            }
        }
        else if (num <= atmBalance)
        {
            system("cls");
            atmBalance = atmBalance - num;
            printf("\n=================================================================================\n");
            printf("\n\t\t\tWithdrawn Amount: $%d\n", num);
            yellow();
            printf("\n\t\t\tNew Balance: $%d", atmBalance);
            reset();
            green();
            printf("\n\t\t\tSuccess: Approved Bank Withdrawal\n");
            reset();
            getPrint();
            printf("\n\t\t\tReceipt Successfully Printed...\n");
            return transactionProcess();
        }
        else
        {
            red();
            printf("Invalid Input");
            reset();
            return withdrawTransact();
        }
    } while (withdraw > atmBalance);
}

int depositTransact()
{
    green();
    printf("\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    printf("\n+++++++++++++++++++++++++++++--DEPOSIT TRANSACTION--+++++++++++++++++++++++++++++\n");
    printf("\n+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
    reset();
    printf("\n\t\t\tEnter ");
    blue();
    printf("'*'");
    reset();
    printf(" to cancel the transaction\n\n");
    if (atmBalance <= 0)
    {
        red();
        printf("\nCurrent Balance: $%d\n", atmBalance);
        reset();
        yellow();
        printf("Please Deposit Appropriate Amount\n");
        reset();
    }
    else
    {
        yellow();
        printf("\nCurrent Balance: $%d\n", atmBalance);
        reset();
    }
    printf("\n\nEnter the amount that you would like to deposit: $");
    green();
    scanf("%s", &deposit);
    reset();
    if (deposit[0] == '*')
    {
        printf("Transaction is Cancelled\n");
        return transactionProcess();
    }
    if ((deposit[0] >= 'a' && deposit[0] <= 'z') || (deposit[0] >= 'A' && deposit[0] <= 'Z'))
    {
        return depositTransact();
    }
    system("cls");
    num = atoi(deposit);
    atmBalance += num;
    printf("\n=================================================================================\n");
    printf("\n\t\t\tDeposited Amount: $%d\n", num);
    yellow();
    printf("\n\t\t\tUpdated Balance: $%d", atmBalance);
    reset();
    green();
    printf("\n\t\t\tSuccess: Approved Back Deposit\n");
    reset();
    getPrint();
    printf("\n\t\t\tReceipt Successfully Printed...\n");
    return transactionProcess();
}

int inquiryTransact()
{
    system("cls");
    blue();
    printf("_________________________________________________________________________________\n\n");
    printf("\n-------------------------------INQUIRY TRANSACTION-------------------------------\n");
    printf("\n_________________________________________________________________________________\n");
    reset();
    yellow();
    printf("\n\n\t\tAccount Number: %d\n", cardNumber);
    reset();
    green();
    printf("\n\t\t\tCurrent Savings: $%d\n", atmBalance);
    reset();
    getPrint();
    printf("\n\t\t\tReceipt Successfully Printed...\n");
    printf("\n_________________________________________________________________________________\n\n");
    return transactionProcess();
}

int transferTransact()
{
    blue();
    printf("\n<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>\n");
    printf("\n><><><><><><><><><><><><><><>--TRANSFER TRANSACTION--<><><><><><><><><><><><><><><\n");
    printf("\n<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>\n");
    reset();
    printf("\n\t\t\tEnter ");
    blue();
    printf("'*'");
    reset();
    printf(" to cancel the transaction\n");
    yellow();
    printf("\n\nCurrent Balance: $%d\n\n", atmBalance);
    reset();
    blue();
    printf("\nEnter the card number from which you wish to transfer funds: ");
    reset();
    scanf("%s", &transferCard);
    if (transferCard[0] == '*')
    {
        system("cls");
        printf("\n=================================================================================\n");
        red();
        printf("\n\t\t\t     Transaction is Cancelled\n");
        reset();
        printf("\n=================================================================================\n");
        return transactionProcess();
    }
    if ((transferCard[0] >= 'a' && transferCard[0] <= 'z') || (transferCard[0] >= 'A' && transferCard[0] <= 'Z'))
    {
        system("cls");
        return transferTransact();
    }
    num = atoi(transferCard);
    if (num == userCardInput)
    {
        system("cls");
        printf("\n=================================================================================\n");
        red();
        printf("\n\t\t\t    Account Currently in Use\n");
        reset();
        printf("\n=================================================================================\n");
        return transferTransact();
    }
    // For User 1
    if (num == user1.cardNum)
    {
        system("cls");
        printf("\n=================================================================================\n\n");
        printf("\n\t\t\tEnter ");
        blue();
        printf("'*'");
        reset();
        printf(" to cancel the transaction\n");
        printf("\n\t\tAccount Details\n");
        blue();
        printf("\n\t\t\tAccount No: %d\n\t\t\tAccount Balance: $%d\n", user1.cardNum, user1.atmBalance);
        reset();
        yellow();
        printf("\n\t\t\tMy Balance: $%d\n\n", atmBalance);
        reset();
        printf("\n\t\tEnter the amount that you want to transfer: $");
        scanf("%s", &transferAmount);
        if (transferAmount[0] == '*')
        {
            printf("\n=================================================================================\n");
            red();
            printf("\n\t\t\t     Transaction is Cancelled\n");
            reset();
            printf("\n=================================================================================\n");
            return transactionProcess();
        }
        else
        {
            int num = atoi(transferAmount);
            atmBalance -= num;
            num += user1.atmBalance;
            system("cls");
            printf("\n=================================================================================\n");
            green();
            printf("\n\t\tSuccessfully Transferred Funds to %d\n", user1.cardNum);
            reset();
            printf("\n\t\tTransferred Money: $%d\n", num);
            yellow();
            printf("\n\t\t\tAccount No: %d \n\t\t\tTransferred Account New Balance: $%d\n", user1.cardNum, num);
            reset();
            blue();
            printf("\n\t\t\tMy New Current Balance: $%d\n", atmBalance);
            reset();
            getPrint();
            printf("\n\t\t\tReceipt Successfully Printed...\n");
            printf("\n\n=================================================================================\n");
            return transactionProcess();
        }
    }

    // For User 2
    else if (num == user2.cardNum)
    {
        system("cls");
        printf("\n=================================================================================\n\n");
        printf("\n\t\t\tEnter ");
        blue();
        printf("'*'");
        reset();
        printf(" to cancel the transaction\n");
        printf("\n\t\tAccount Details\n");
        blue();
        printf("\n\t\t\tAccount No: %d\n\t\t\tAccount Balance: $%d\n", user2.cardNum, user2.atmBalance);
        reset();
        yellow();
        printf("\n\t\t\tMy Balance: $%d\n", atmBalance);
        reset();
        printf("\n\n\t\tEnter the amount that you want to transfer: $");
        scanf("%s", &transferAmount);
        if (transferAmount[0] == '*')
        {
            printf("\n=================================================================================\n");
            red();
            printf("\n\t\t\t     Transaction is Cancelled\n");
            reset();
            printf("\n=================================================================================\n");
            return transactionProcess();
        }
        else
        {
            int num = atoi(transferAmount);
            atmBalance -= num;
            num += user2.atmBalance;
            system("cls");
            printf("\n=================================================================================\n");
            green();
            printf("\n\t\tSuccessfully Transferred Funds to %d\n", user2.cardNum);
            reset();
            printf("\n\t\tTransferred Money: $%d\n", num);
            yellow();
            printf("\n\t\t\tAccount No: %d \n\t\t\tNew Balance: $%d\n", user2.cardNum, num);
            reset();
            blue();
            printf("\n\t\t\tMy New Current Balance: $%d\n", atmBalance);
            reset();
            getPrint();
            printf("\n\t\t\tReceipt Successfully Printed...\n");
            printf("\n\n=================================================================================\n");
            return transactionProcess();
        }
    }
    else
    {
        system("cls");
        printf("\n=================================================================================\n");
        red();
        printf("\n\t\t\t   Please Input Valid Card Number \n");
        reset();
        printf("\n=================================================================================\n");
        return transferTransact();
    }
}

int transactionProcess()
{
    printf("\n#################################################################################");
    printf("\n#                                                                               #");
    printf("\n#                                                                               #");
    printf("\n#                            ");
    blue();
    printf("--TRANSACTION PROCESS--");
    reset();
    printf("                            #");
    printf("\n#                                                                               #");
    printf("\n#                                                                               #");
    printf("\n#################################################################################\n");
    green();
    printf("\n\t\t     Withdraw\t     >>>>>\t    [ 1 ]\n");
    printf("\t\t     Deposit\t     >>>>>\t    [ 2 ]\n");
    printf("\t\t     Transfer\t     >>>>>\t    [ 3 ]\n");
    printf("\t\t     Inquiry\t     >>>>>\t    [ 4 ]\n");
    printf("\t\t     Exit\t     >>>>>\t    [ 5 ]");
    reset();
    yellow();
    printf("\n\n\t\t   Please select a process from 1 to 5: ");
    reset();
    scanf("%d", &process);

    switch (process)
    {
    case 1:
        withdrawTransact();
        break;
    case 2:
        system("cls");
        depositTransact();
        break;
    case 3:
        system("cls");
        transferTransact();
        break;
    case 4:
        inquiryTransact();
        break;
    case 5:
        system("cls");
        green();
        printf("\n#################################################################################");
        printf("\n#                                                                               #");
        printf("\n#                                                                               #");
        printf("\n#                ");
        printf("-- Thank you for using CodeD ATM System! :> --");
        printf("                 #");
        printf("\n#                                                                               #");
        printf("\n#                                                                               #");
        printf("\n#################################################################################\n");
        reset();
        return 0;
        break;
    default:
        system("cls");
        printf("\n=================================================================================\n");
        red();
        printf("\n\t\tInvalid Input, Please Input Appropriate Number \n");
        reset();
        printf("\n=================================================================================\n");
        return transactionProcess();
        break;
    }
}

int transact()
{
    do
    {
        yellow();
        printf("\n\t\t    Please enter your pin number >>> ");
        reset();
        green();
        scanf("%d", &userPin);
        reset();
        if (userPin == cancel)
        {
            system("cls");
            printf("\n=================================================================================\n");
            red();
            printf("\n\t\t\t     Transaction is Cancelled\n");
            reset();
            printf("\n=================================================================================\n");
            return 0;
            break;
        }
        else if (userPin == pin)
        {
            system("cls");
            transactionProcess();
            return 0;
        }
        else
        {
            system("cls");
            printf("\n=================================================================================\n");
            red();
            printf("\n\t\t\t\t   Invalid Pin\n");
            try = try - 1;
            if (try == 0)
            {
                system("cls");
                reset();
                printf("\n=================================================================================\n");
                red();
                printf("\n\t   Invalid Pin! Please Contact the Bank for Further Assitance\n");
                reset();
                printf("\n=================================================================================\n");
                return 0;
            }
            reset();
            printf("\n\t\t\t   You only have ");
            red();
            printf("%d", try);
            reset();
            printf(" tries left\n");
            purple();
            printf("\n\t\t\t       To cancel, type '1'\n");
            reset();
            printf("\n=================================================================================\n");
        }
    } while (try >= 0 || (userPin >= 'a' && userPin <= 'z') || (userPin >= 'A' && userPin <= 'Z'));
}

int getPrint(int argc, char *argv[])
{
    char s[100];
    FILE *receipt;
    size_t i;
    struct tm fileTime;
    time_t current_time;
    current_time = time(NULL);
    fileTime = *(localtime(&current_time));
    i = strftime(s, 100, "./receipts/Bank-Receipt-%b-%d-%Y-%H-%M-%S.txt\0", &fileTime);
    receipt = fopen(s, "w+");
    for (int i = 1; i <= 3; i++)
    {
        for (int j = 1; j <= 47; j++)
        {
            if (i == 1 || i == 47 || j == 1 || j == 47)
            {
                fprintf(receipt, "# ");
            }
            else
            {
                fprintf(receipt, "  ");
            }
        }
        fprintf(receipt, "\n");
    }
    fprintf(receipt, "#%*s%-*s  #\n", width[57], "PHOBOS CALLISTO BANK INC.", width[32], "");
    for (int i = 29; i <= 30; i++)
    {
        for (int j = 1; j <= 47; j++)
        {
            if (i == 1 || i == 47 || j == 1 || j == 47)
            {
                fprintf(receipt, "# ");
            }
            else
            {
                fprintf(receipt, "  ");
            }
        }
        fprintf(receipt, "\n");
    }
    fprintf(receipt, "#  %s", ctime(&current_time), "wwww");
    for (int i = 45; i <= 47; i++)
    {
        for (int j = 1; j <= 47; j++)
        {
            if (i == 1 || i == 47 || j == 1 || j == 47)
            {
                fprintf(receipt, "# ");
            }
            else
            {
                fprintf(receipt, "  ");
            }
        }
        fprintf(receipt, "\n");
    }
    for (int i = 29; i <= 30; i++)
    {
        for (int j = 1; j <= 47; j++)
        {
            if (i == 1 || i == 47 || j == 1 || j == 47)
            {
                fprintf(receipt, "# ");
            }
            else
            {
                fprintf(receipt, "  ");
            }
        }
        fprintf(receipt, "\n");
    }
    fprintf(receipt, "#%*s%-*s  #\n", width[59], "Bank Transaction Receipt", width[30], "");
    for (int i = 29; i <= 30; i++)
    {
        for (int j = 1; j <= 47; j++)
        {
            if (i == 1 || i == 47 || j == 1 || j == 47)
            {
                fprintf(receipt, "# ");
            }
            else
            {
                fprintf(receipt, "  ");
            }
        }
        fprintf(receipt, "\n");
    }
    fprintf(receipt, "#%*s%-*s%-*s%-*s%d%-*s  #\n", width[10], "", width[27], "User ID Number: ", width[5], "========>>", width[12], "", userCardInput, width[21], "");
    for (int i = 29; i <= 30; i++)
    {
        for (int j = 1; j <= 47; j++)
        {
            if (i == 1 || i == 47 || j == 1 || j == 47)
            {
                fprintf(receipt, "# ");
            }
            else
            {
                fprintf(receipt, "  ");
            }
        }
        fprintf(receipt, "\n");
    }
    fprintf(receipt, "#%*s%-*s%-*s #\n", width[48], "", width[20], "=================================", width[9], "");
    for (int i = 30; i <= 30; i++)
    {
        for (int j = 1; j <= 47; j++)
        {
            if (i == 1 || i == 47 || j == 1 || j == 47)
            {
                fprintf(receipt, "# ");
            }
            else
            {
                fprintf(receipt, "  ");
            }
        }
        fprintf(receipt, "\n");
    }
    fprintf(receipt, "#%*s%-*s%-*s%-*s%d \n", width[10], "", width[27], "Current Transaction: ", width[15], "========>>", width[10], "CURRENT BALANCE: $", atmBalance);
    for (int i = 30; i <= 30; i++)
    {
        for (int j = 1; j <= 47; j++)
        {
            if (i == 1 || i == 47 || j == 1 || j == 47)
            {
                fprintf(receipt, "# ");
            }
            else
            {
                fprintf(receipt, "  ");
            }
        }
        fprintf(receipt, "\n");
    }
    fprintf(receipt, "#%*s%-*s%-*s #\n", width[48], "", width[20], "=================================", width[9], "");
    for (int i = 30; i <= 30; i++)
    {
        for (int j = 1; j <= 47; j++)
        {
            if (i == 1 || i == 47 || j == 1 || j == 47)
            {
                fprintf(receipt, "# ");
            }
            else
            {
                fprintf(receipt, "  ");
            }
        }
        fprintf(receipt, "\n");
    }
    for (int i = 45; i <= 47; i++)
    {
        for (int j = 1; j <= 47; j++)
        {
            if (i == 1 || i == 47 || j == 1 || j == 47)
            {
                fprintf(receipt, "# ");
            }
            else
            {
                fprintf(receipt, "  ");
            }
        }
        fprintf(receipt, "\n");
    }
    for (int i = 29; i <= 30; i++)
    {
        for (int j = 1; j <= 47; j++)
        {
            if (i == 1 || i == 47 || j == 1 || j == 47)
            {
                fprintf(receipt, "# ");
            }
            else
            {
                fprintf(receipt, "  ");
            }
        }
        fprintf(receipt, "\n");
    }
    fprintf(receipt, "#%*s%-*s  #\n", width[57], "THANK YOU FOR BANKING WITH US!", width[32], "");
    for (int i = 45; i <= 47; i++)
    {
        for (int j = 1; j <= 47; j++)
        {
            if (i == 1 || i == 47 || j == 1 || j == 47)
            {
                fprintf(receipt, "# ");
            }
            else
            {
                fprintf(receipt, "  ");
            }
        }
        fprintf(receipt, "\n");
    }
    fclose(receipt);
    return (0);
}

// For Font Colors
void red()
{
    printf("\033[1;31m");
}

void blue()
{
    printf("\033[0;34m");
}

void yellow()
{
    printf("\033[1;33m");
}

void green()
{
    printf("\033[0;32m");
}

void purple()
{
    printf("\033[0;35m");
}

void reset()
{
    printf("\033[0m");
}

// Initial Startup
int main()
{
    system("cls");
    blue();
    printf("\n#################################################################################");
    printf("\n#                                                                               #");
    printf("\n#                                                                               #");
    printf("\n#                   --Welcome to Phobos Callisto ATM System--                   #");
    printf("\n#                                                                               #");
    printf("\n#                                                                               #");
    printf("\n#################################################################################\n");
    reset();
    yellow();
    printf("\n\n\t\tPlease enter your account number >>> ");
    reset();
    green();
    scanf("%d", &userCardInput);
    reset();
    // Validate User
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
        printf("\n=================================================================================\n");
        red();
        printf("\n\t\t\tAccount number is unidentified\n");
        reset();
        printf("\n=================================================================================\n");
        return 0;
    }
    return 0;
}
