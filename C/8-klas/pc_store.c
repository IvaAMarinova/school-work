// PC Store
#include <stdio.h>
#include <stdlib.h>
#define True 1
#define False 0

const float dolar_lev = 1.57;

typedef struct{
    float prise;
    int count;
    float discount;
}product;


int input_info(product *, product *, product *);
int transfer_input(product *, float, int, float);
float total_prise(product *, product *, product *);
int main()
{
    product *product_list;
    product *cpu, *v_card, *ram;
    float result;

    product_list = malloc(sizeof(product) * 3);

    if(product_list == NULL) {
        printf("There is not enough memory, sorry\n");
        return 1;
    }

    cpu = product_list;
    v_card = product_list + 1;
    ram = product_list + 2;

    input_info(cpu, v_card, ram);
    result = total_prise(cpu, v_card, ram);

    printf("The answer is %f", result);

    free(product_list);
    return 0;
}
int input_info(product *cpu, product *v_card, product *ram)
{
    float cpu_s = 0, v_card_s = 0, ram_s = 0, discount = 0;
    int ram_count = 0;

    do {
        printf("What is the cpu's price?\n");
        scanf("%f", &cpu_s);
    } while (cpu_s < 200 || cpu_s > 3000);
    do {
        printf("What is the v_card's price?\n");
        scanf("%f", &v_card_s);
    } while (v_card_s < 100 || v_card_s > 1500);
    do {
        printf("What is the ram's price?\n");
        scanf("%f", &ram_s);
    } while (ram_s < 80 || ram_s > 500);
    do {
        printf("How many rams are you buying? (1-4)\n");
        scanf("%d", &ram_count);
    } while (ram_count < 1 || ram_count > 4);
    do {
        printf("What is the discount?\n");
        scanf("%f", &discount);
    } while (discount < 0.01 || discount > 0.1);

    transfer_input(cpu, cpu_s, 1, discount);
    transfer_input(v_card, v_card_s, 1, discount);
    transfer_input(ram, ram_s, ram_count, 0);

    return 0;
}
int transfer_input(product *p, float prise, int count, float discount)
{
    p->prise = prise;
    p->count = count;
    p->discount = discount;
}
float total_prise(product *cpu, product *v_card, product *ram)
{
    float result;

    result = (cpu->prise - (cpu->prise * cpu->discount)) + (v_card->prise - (v_card->prise* v_card->discount)) + (ram->prise * ram->count);
    result = result * dolar_lev;
    return result;
}
