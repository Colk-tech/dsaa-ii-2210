# include <stdlib.h>
# include <stdio.h>
# include "Knapsack.h"

/* test data */
extern unsigned num;
extern OBJ object[];
extern float knapsack;

int main() {
    for (unsigned i = 0; i < num; i++)
        object[i].performance = object[i].value / object[i].weight;
    sortObject(object, num);
    /* make it */

    float total_weight = 0.0;
    float total_value = 0.0;

    float empty_weight = knapsack;

    // Assuming that the knapsack will be full AT LEAST until all the items is in.
    // 少なくとも、すべての品物が入るまでにはナップサックは満杯になると仮定する。
    for (int i = 0; i < num; i++) {
        if (object[i].weight <= empty_weight) {
            total_weight += object[i].weight;
            total_value += object[i].value;

            empty_weight -= object[i].weight;

            printf("\"%s\" is put in the knapsack;\n", object[i].name);
            printf("total weight: %f, total_value: %f\n\n", total_weight, total_value);

        } else {
            float ratio_of_item_can_be_put = empty_weight / object[i].weight;

            total_weight += object[i].weight * ratio_of_item_can_be_put;
            total_value += object[i].value * ratio_of_item_can_be_put;

            empty_weight += object[i].weight * ratio_of_item_can_be_put;

            printf("The knapsack is full!\n");
            printf("%f%% of \"%s\" is put in the knapsack;\n", ratio_of_item_can_be_put * 100, object[i].name);
            printf("total weight: %f, total_value: %f\n\n", total_weight, total_value);

            break;
        }

    }
}

void sortObject(OBJ obj[], unsigned n) {
    /* make it! */

    OBJ tmp;

    int i, j;
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (obj[i].performance < obj[j].performance) {
                tmp = obj[i];
                obj[i] = obj[j];
                obj[j] = tmp;
            }
        }
    }

}
