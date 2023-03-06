%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_RECORD_LENGTH 1000
#define MAX_CUST_ID_LENGTH 20
#define MAX_DATE_LENGTH 10
#define MAX_TRANSACTIONS 100

// Structure to represent a transaction
struct Transaction {
    char date[MAX_DATE_LENGTH];
    int value;
};

// Structure to represent a customer record
struct Record {
    char custId[MAX_CUST_ID_LENGTH];
    struct Transaction transactions[MAX_TRANSACTIONS];
    int numTransactions;
    int totalValue;
};

// Array to hold all customer records
struct Record records[MAX_TRANSACTIONS];
int numRecords = 0;

char input_date[MAX_DATE_LENGTH];

// Function to parse a transaction from the input string
void parseTransaction(char* str, struct Transaction* trans) {
    char* p = strtok(str, " ");
    strcpy(trans->date, p);
    p = strtok(NULL, ";");
    trans->value = atoi(p);
}

// Function to parse a record from the input string
void parseRecord(char* str, struct Record* rec) {
    char* p = strtok(str, " ");
    if (p == NULL || strlen(p) <= 1) {
        // Invalid record, ignore it
        return;
    }
    strcpy(rec->custId, p + 1);
    rec->numTransactions = 0;
    rec->totalValue = 0;
    p = strtok(NULL, ";");
    while (p != NULL) {
        parseTransaction(p, &rec->transactions[rec->numTransactions]);

        
        rec->totalValue += rec->transactions[rec->numTransactions].value;
        rec->numTransactions++;
        p = strtok(NULL, ";");
    }
}

// Function to find the customer with maximum transaction value on a given date
char* findMaxCustomer(char* date) {
    int maxIndex = -1;
    int maxValue = -1;
    for (int i = 0; i < numRecords; i++) {
        for (int j = 0; j < records[i].numTransactions; j++) {
            if (strcmp(records[i].transactions[j].date, date) == 0) {
                if (records[i].transactions[j].value > maxValue) {
                    maxValue = records[i].transactions[j].value;
                    maxIndex = i;
                }
                break;
            }
        }
    }
    if (maxIndex >= 0) {
        return records[maxIndex].custId;
    } else {
        return NULL;
    }
}

%}



%%


"//".* {}


$[" "]*[A-Z][A-Z0-9]*[^$"\n"]* {
    parseRecord(yytext, &records[numRecords]);
    numRecords++;
}



%%

int main(int argc, char** argv) {
    FILE* data_file = fopen("data.txt", "r");
    FILE* input_file = fopen("input.txt", "r");
    fscanf(input_file, "%s", input_date);
    fclose(input_file);
    FILE* output_file = fopen("output.txt", "w");
    yyin = data_file;
    yylex();
    /* printf("%s" , findMaxCustomer(input_date)); */
    /* fprintf(output_file,"$%d$%s#",num_transactions,max_cust_id);
    printf("$%d$%s#",num_transactions,max_cust_id); */
    for(int i = 0 ; i < numRecords ;i++){
        records[i];
        printf("id : %s ",records[i].custId);
        for(int j = 0; j < records[i].numTransactions;j++){
            printf("date :  %s ",records[i].transactions[j].date);
            printf("value :  %d ",records[i].transactions[j].value);
        }
        printf("\n-----------------\n");
    }
}