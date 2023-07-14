#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool containsNearbyDuplicate(int *nums, int numsSize, int k)
{
    // Create a set to store the elements within the window
    int *set = (int *)calloc(numsSize, sizeof(int));

    for (int i = 0; i < numsSize; i++)
    {
        // Check if the current element is already in the set
        if (set[nums[i]] == 1)
        {
            free(set);
            return true;
        }

        // Add the current element to the set
        set[nums[i]] = 1;

        // Remove the oldest element from the set if the window size exceeds k
        if (i >= k)
        {
            set[nums[i - k]] = 0;
        }
    }

    free(set);
    return false;
}

int main()
{
    int nums[] = {-1, -1};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int k = 1;

    bool result = containsNearbyDuplicate(nums, numsSize, k);

    printf("Contains nearby duplicates within distance %d: %s\n", k, result ? "true" : "false");

    return 0;
}
