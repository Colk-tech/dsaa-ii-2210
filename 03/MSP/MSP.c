# include <stdio.h>
# include "MSP.h"

# define MAX_CANDIDATES_NUM 3

/* input data */
extern unsigned num;
extern int data[];

int main() {
    printf("%d\n", maxSubarray(0, num));
}

int maxValue(const int nums[], int n) {
    int max;

    max = nums[0];

    for (int i = 0; i < n; i++) {
        if (nums[i] > max) {
            max = nums[i];
        }
    }

    return max;
}

int maxSubarray(unsigned from, unsigned num) {
    /* stop recursive call */
    if (num == 1) {
        return data[from];
    }
    if (num == 2) {
        int maxCandidates[MAX_CANDIDATES_NUM] = {data[from], data[from + 1], data[from] + data[from + 1]};
        return maxValue(maxCandidates, MAX_CANDIDATES_NUM);
    }

    /* divide */
    int half_num = num / 2;
    int center = from + half_num;

    /* conquer */
    int max1 = maxSubarray(from, half_num);
    int max2 = maxSubarray(center, half_num);

    int max3L = 0;
    int max3LTmp = 0;
    for (int i = center - 1; i + 1 > from; i--) {
        max3LTmp += data[i];
        if (max3L < max3LTmp) {
            max3L = max3LTmp;
        }
    }

    int max3R = 0;
    int max3RTmp = 0;
    for (int i = center; i < (from + num); i++) {
        max3RTmp += data[i];
        if (max3R < max3RTmp) {
            max3R = max3RTmp;
        }
    }

    int max3 = max3L + max3R;

    printf("max1: %d max2: %d max3L: %d max3R: %d max3: %d\n", max1, max2, max3L, max3R, max3);

    /* combine */
    int maxCandidates[MAX_CANDIDATES_NUM] = {max1, max2, max3};
    return maxValue(maxCandidates, MAX_CANDIDATES_NUM);
}
