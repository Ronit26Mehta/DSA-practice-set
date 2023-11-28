#include <stdio.h>
#define size 100

void merge(int array[], int beg, int mid, int end);
void merge_sort(int array[], int beg, int end);
int partition(int array[], int beg, int end);
void quick_sort(int array[], int beg, int end);

void main() {
    int array[size], i, len, choice;
    do {
        printf("\nEnter the size of the array:");
        scanf("%d", &len);
        if (len > size) {
            printf("Array size exceeds the maximum limit. Please choose a smaller size.\n");
            continue;
        }
        printf("\nEnter the elements:");
        for (int i = 0; i < len; i++) {
            scanf("%d", &array[i]);
        }
        printf("\nEnter your choice:");
        printf("\n1.Merge Sort");
        printf("\n2.Quick Sort");
        printf("\n3.Exit");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                merge_sort(array, 0, len - 1);
                printf("\nThe sorted array is:");
                for (int i = 0; i < len; i++) {
                    printf("%d\t", array[i]);
                }
                break;
            case 2:
                quick_sort(array, 0, len - 1);
                printf("\nThe sorted array is:");
                for (int i = 0; i < len; i++) {
                    printf("%d\t", array[i]);
                }
                break;

            case 3:
                printf("\nExiting...\n");
                break;

            default:
                printf("\nInvalid choice");
                break;
        }
    } while (choice != 3);

    
}

void merge(int array[], int beg, int mid, int end) {
    int i = beg, j = mid + 1, index = beg, temp[size];

    while (i <= mid && j <= end) {
        if (array[i] < array[j]) {
            temp[index] = array[i];
            i++;
        } else {
            temp[index] = array[j];
            j++;
        }
        index++;
    }

    if (i > mid) {
        while (j <= end) {
            temp[index] = array[j];
            j++;
            index++;
        }
    } else {
        while (i <= mid) {
            temp[index] = array[i];
            i++;
            index++;
        }
    }

    for (int k = beg; k < index; k++) {
        array[k] = temp[k];
    }
}

void merge_sort(int array[], int beg, int end) {
    int mid;
    if (beg < end) {
        mid = (beg + end) / 2;
        merge_sort(array, beg, mid);
        merge_sort(array, mid + 1, end);
        merge(array, beg, mid, end);
    }
}

int partition(int array[], int beg, int end) {
    int left, right, temp, loc, flag;
    loc = left = beg;
    right = end;
    flag = 0;
    while (flag != -1) {
        while ((array[loc] <= array[right]) && (loc != right)) {
            right--;
        }
        if (loc == right) {
            flag = 1;
        } else if (array[loc] > array[right]) {
            temp = array[loc];
            array[loc] = array[right];
            array[right] = temp;
            loc = right;
        }
        if (flag != 1) {
            while ((array[loc] >= array[left]) && (loc != left)) {
                left++;
            }
            if (loc == left) {
                flag = 1;
            } else if (array[loc] < array[left]) {
                temp = array[loc];
                array[loc] = array[left];
                array[left] = temp;
                loc = left;
            }
        }
        if (left == right) {
            flag = -1;
        }
    }
    return loc;
}


void quick_sort(int array[], int beg, int end) {
    int loc;
    if (beg < end) {
        loc = partition(array, beg, end);
        quick_sort(array, beg, loc - 1);
        quick_sort(array, loc + 1, end);
    }
}
