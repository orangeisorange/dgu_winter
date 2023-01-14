#include <stdio.h>
#include <stdlib.h>
void merge(int **arr, int left, int mid, int right);
void mergesort(int **arr, int left, int right);
void quickSort(int **arr, int L, int R);

int main()
{
    int size;
    int **axis;
    int count = 0;
    int nowIdx = 0;
    scanf("%d", &size);

    axis = (int**)malloc(size * sizeof(int*));
    for(int i = 0; i < size; i++)
        axis[i] = (int*)malloc(2 * sizeof(int));

    for(int i = 0; i < size; i++)
        scanf("%d%d",&axis[i][0], &axis[i][1]);

    mergesort(axis, 0, size-1);

    for(int i = 0; i < size; i++)
        printf("%d %d\n",axis[i][0],axis[i][1]);

    return 0;
}

void merge(int **arr, int left, int mid, int right)
{
    int fIdx = left;
    int rIdx = mid + 1;
    int i,j;
    int tmp;
    int counter = 0;
    int **sortArr;
    sortArr = (int**)malloc(sizeof(int*)*(right - left + 1));
    for(int j = 0;j < right - left + 1; j++)
        sortArr[j] = (int*)malloc(sizeof(int)*2);

    int sIdx = 0;
    while(fIdx <= mid && rIdx <= right)
    {
        if(arr[fIdx][0] < arr[rIdx][0])
        {
            sortArr[sIdx][0] = arr[fIdx][0];
            sortArr[sIdx][1] = arr[fIdx++][1];
        }
        else if(arr[fIdx][0] == arr[rIdx][0])
        {
            if(arr[fIdx][1] > arr[rIdx][1])
            {
                tmp = arr[fIdx][1];
                arr[fIdx][1] = arr[rIdx][1];
                arr[rIdx][1] = tmp;
                sortArr[sIdx][0] = arr[rIdx][0];
                sortArr[sIdx][1] = arr[rIdx][1];
                rIdx++;
            }
            else
            {
                sortArr[sIdx][0] = arr[fIdx][0];
                sortArr[sIdx][1] = arr[fIdx][1];
                fIdx++;
            }
        }
        else
        {
            sortArr[sIdx][0] = arr[rIdx][0];
            sortArr[sIdx][1] = arr[rIdx++][1];
        }
        counter++;
        sIdx++;
    }
    if(fIdx > mid)
    {
        for(i=rIdx; i <= right; i++, sIdx++)
        {
            if(i != right && arr[i][0] == arr[i+1][0])
                {
                    if(arr[i][1] > arr[i+1][1])
                    {
                        tmp = arr[i][1];
                        arr[i][1] = arr[i+1][1];
                        arr[i+1][1] = tmp;
                        sortArr[sIdx][0] = arr[i][0];
                        sortArr[sIdx][1] = arr[i][1];
                    }
                    else
                    {
                        sortArr[sIdx][0] = arr[i][0];
                        sortArr[sIdx][1] = arr[i][1];
                    }
                }
        }
    }
    else
    {
        for(i=fIdx; i <= mid; i++, sIdx++)
        {
            sortArr[sIdx][0] = arr[i][0];
            sortArr[sIdx][1] = arr[i][1];
        }
    }

    for(j = 0, i = left; i <= right; j++, i++)
    {
        arr[i][0] = sortArr[j][0];
        arr[i][1] = sortArr[j][1];
    }

    free(sortArr);
}

void mergesort(int **arr, int left, int right)
{
    int mid;

    if(left < right)
    {
        mid = (left + right)/2;

        mergesort(arr, left, mid);
        mergesort(arr, mid+1, right);

        merge(arr, left, mid ,right);
    }
}

void quickSort(int **arr, int L, int R) {
      int left = L, right = R;
      int pivot = arr[(L + R) / 2][1];    // pivot 설정 (가운데) 
      int temp;
      do
      {
        while (arr[left][1] < pivot)    // left가 pivot보다 큰 값을 만나거나 pivot을 만날 때까지 
            left++;
        while (arr[right][1] > pivot)    // right가 pivot보다 작은 값을 만나거나 pivot을 만날 때까지 
            right--;
        if (left<= right)    // left가 right보다 왼쪽에 있다면 교환 
        {
            temp = arr[left][1];
            arr[left][1] = arr[right][1];
            arr[right][1] = temp;
            /*left 오른쪽으로 한칸, right 왼쪽으로 한칸 이동*/
            left++;
            right--;
        }
      } while (left<= right);    // left가 right 보다 오른쪽에 있을 때까지 반복 
 
    /* recursion */
    if (L < right)
        quickSort(arr, L, right);    // 왼쪽 배열 재귀적으로 반복 
 
    if (left < R)
        quickSort(arr, left, R);    // 오른쪽 배열 재귀적으로 반복 
}