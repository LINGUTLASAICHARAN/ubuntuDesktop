%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TRANSACTIONS 1000
#define MAX_CUSTOMERS 1000
#define MAX_ID_LENGTH 10

typedef struct {
    char id[MAX_ID_LENGTH+1];
    int transactions[MAX_TRANSACTIONS];
    int num_transactions;
} Customer;

Customer customers[MAX_CUSTOMERS];
int num_customers = 0;

char input_date[6];

int num_transactions = 0;
char max_cust_id[MAX_ID_LENGTH+1] = "";
int max_transaction_value = 0;

%}

%option noyywrap

%%

\$[A-Z][A-Z0-9]* { // start of a record
    char cust_id[MAX_ID_LENGTH+1];
    strcpy(cust_id, yytext+1);

    // skip over any whitespace between cust_id and transactions
    while (yytext[yylen] == ' ') yyless(yylen+1);

    // parse transactions
    int transaction_value = 0;
    int day = 0, month = 0;
    int num_transactions_for_cust = 0;
    while (1) {
        if (sscanf(yytext+yylen, "%2d/%2d %d;", &day, &month, &transaction_value) != 3)
            break;
        yyless(yylen+11); // move yytext pointer to end of transaction

        // check if transaction is on the input date
        if (day == input_date[0]-'0'*10 && month == input_date[1]-'0'*10) {
            num_transactions++;
            num_transactions_for_cust++;
            // add transaction value to customer's total transaction value for the input date
            int cust_index = -1;
            for (int i = 0; i < num_customers; i++) {
                if (strcmp(customers[i].id, cust_id) == 0) {
                    cust_index = i;
                    break;
                }
            }
            if (cust_index == -1) {
                cust_index = num_customers++;
                strcpy(customers[cust_index].id, cust_id);
                customers[cust_index].num_transactions = 0;
            }
            customers[cust_index].transactions[customers[cust_index].num_transactions++] = transaction_value;
            if (transaction_value > max_transaction_value) {
                strcpy(max_cust_id, cust_id);
                max_transaction_value = transaction_value;
            }
        }
    }
}


\/\/.* {}


\$[ ]+\d{2}/\d{2} \d+ { }


. {}

%%

int main() {

    FILE* data_file = fopen("data.txt", "r");
    FILE* input_file = fopen("input.txt", "r");
    fscanf(input_file, "%s", input_date);
    fclose(input_file);
    FILE* output_file = fopen("output.txt", "r");
    yyin = data_file;
    yylex();
// continue looking at chat gpt
    
}
