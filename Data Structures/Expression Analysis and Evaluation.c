#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define DELIMITADOR 1
#define VARIAVEL 2
#define NUMERO 3

char *prog; /* contém a expressão a ser analisada */
char token[80];
char tok_type;

void eval_exp(double *answer), eval_exp2(double *answer);
void eval_exp3(double *answer), eval_exp4(double *answer);
void eval_exp5(double *answer);
void eval_exp6(double *answer), atom(double *answer);
void get_token(void), putback(void);
void serror(int error);
int isdelim(char c);

/* Ponto de entrada do analisador. */
void eval_exp(double *answer)
{
    get_token () ;
    if(!*token) {
        serror(2) ;
        return;
    }
    eval_exp2(answer);
    if (*token) serror (0); /* último token deve ser null */
}

/* Soma ou subtrai dois termos. */
void eval_exp2(double *answer)
{
    register char op;
    double temp;

    eval_exp3(answer);
    while((op = *token) == '+' || op == '-')
    {
        get_token() ;
        eval_exp3(&temp);
        switch(op) {
            case '-':
                *answer = *answer - temp;
                break;
            case '+':
                *answer = *answer + temp;
                break;
        }
    }
}

/* Multiplica ou divide dois fatores. */
void eval_exp3(double *answer)
{
    register char op;
    double temp;

    eval_exp4(answer) ;
    while((op = *token) == '*' || op == '/' || op == '%')
    {
        get_token();
        eval_exp4(&temp);
        switch(op) {
            case '*':
                *answer = *answer * temp;
                break;
            case '/':
                *answer = *answer / temp;
                break;
            case '%':
                *answer = (int) *answer % (int) temp;
                break;
        }
    }
}

/* Processa um expoente */
void eval_exp4(double *answer)
{
    double temp, ex;
    register int t;
 
    eval_exp5(answer);
    if(*token=='^')
    {
    get_token();
    eval_exp4(&temp);
    ex = *answer;
    if(temp==0.0)
    {
        *answer = 1.0;
        return;
    }
        for(t=temp-1;t>0;--t) *answer = (*answer) * (double)ex;
    }
}

/* Avalia um + ou - unário. */
void eval_exp5(double *answer)
{
    register char op;

    op = 0;
    if((tok_type == DELIMITADOR) && *token=='+' || *token=='-')
    {
        op = *token;
        get_token();
    }
    eval_exp6(answer) ;
    if(op=='-') *answer -(*answer);
}

/* Processa uma expressão entre parênteses. */
void eval_exp6(double *answer)
{
    if((*token=='('))
    {
        get_token();
        eval_exp2(answer);
        if (*token!=')')
            serror(1);
        get_token();
    }
    else
        atom(answer);
}

/* Obtém o valor real de um número. */
void atom(double *answer)
{
    if(tok_type==NUMERO)
    {
        *answer = atof(token);
        get_token() ;
        return;
    }
    serror(0); /* caso contrário, erro de sintaxe na expressão */
}

/* Devolve um token à stream de entrada. */
void putback(void)
{
    char *t;

    t = token;
    for(; *t; t++) prog--;
}

/* Apresenta um erro de sintaxe. */
void serror(int error)
{
    static char *e[] = {
        "Erro de sintaxe",
        "Falta parenteses",
        "Nenhuma expressao presente"
    };
    printf("%s\n", e[error]);
}

/* Devolve o próximo token. */
void get_token(void)
{
    register char *temp;

    tok_type = 0;
    temp = token;
    *temp = '\0';

    if(!*prog) return; /* final da expressão */
    while(isspace(*prog)) ++prog; /* ignora espaços em branco */
    
    if(strchr("+-*/%^=()", *prog))
    {
        tok_type = DELIMITADOR;
        /* avança para o próximo char */
        *temp++ = *prog++;
    }
    else if(isalpha(*prog)) 
    {
        while(!isdelim(*prog)) *temp++ = *prog++;
        tok_type = VARIAVEL;
    }
    else if(isdigit(*prog)) {
        while(!isdelim(*prog)) *temp++ = *prog++;
        tok_type = NUMERO;
    }
    *temp = '\0';
}

/* Devolve verdadeiro se c é um delimitador. */
int isdelim(char c)
{
    if(strchr(" +-/*%^=()", c) || c==9 || c=='\r' || c==0)
        return 1;
    return 0;
}

int main()
{
    double answer;
    char *p;

    p = malloc(100);
    if(!p)
    {
        printf("\nFalha na alocacao.\n");
        exit(1);
    }
    
    /* Pocessa expressões até que uma linha em branco seja digitada. */

    do {
        prog = p;
        printf("Digite a expressao: ");
        gets(prog);
        if(!*prog) break;
        eval_exp(&answer);
        printf("\nA resposta e %.2f\n", answer);
    } while(*p);

    return 0;
}