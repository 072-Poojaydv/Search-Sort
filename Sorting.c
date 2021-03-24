#include<stdio.h>
#include<math.h>
#include<string.h>

void Selection(int arr[],int len)
{
	int i,j,min,temp;
	for(i=0;i<len-1;i++)
	{
		min = i;		
		for(j=i+1;j<len;j++)
		{
			if(arr[min]>arr[j])
			{
				min = j;
			}
		}
		if(min != i)
		{
			temp = arr[i];
			arr[i] = arr[min];
			arr[min] = temp;
		}
		
	}
	printf("Array after sorting is::");
	for(i=0;i<len;i++)
	{
		printf("%d\t",arr[i]);
	}
}

void Bubble(int arr[],int len)
{
	int i,j,min,temp;
	for(i=0;i<len-1;i++)
	{
		min = i;
		for(j=0;j<len-i-1;j++)
		{
			if(arr[j+1]<arr[j])
			{
				arr[j] = arr[j] + arr[j+1];
				arr[j+1] = arr[j] - arr[j+1];
				arr[j] = arr[j] - arr[j+1];
			}
		}
	}
	printf("Array after sorting is::");
	for(i=0;i<len;i++)
	{
		printf("%d\t",arr[i]);
	}
}
void Insertion(int arr[],int len)
{
	int i,j,temp;
	for(i=1;i<len;i++)
	{
		temp = arr[i];
		j=i-1;
		while(j>=0 && arr[j]>temp)
		{
			arr[j+1] = arr[j];
			j=j-1;
		}
		arr[j+1] = temp;
	}
	printf("Array after sorting is::");
	for(i=0;i<len;i++)
	{
		printf("%d\t",arr[i]);
	}
}
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2) 
	{
        if (L[i] <= R[j]) 
		{
            arr[k] = L[i];
            i++;
        }
        else 
		{
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) 
	{
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(int arr[], int l, int r)
{
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
		merge(arr, l, m, r);
    }
}
void printArray(int A[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d\t", A[i]);
    printf("\n");
}
void swap(int *a, int *b) 
{
  int t = *a;
  *a = *b;
  *b = t;
}
int partition(int array[], int low, int high) 
{
  int pivot = array[high];
  int i = (low - 1);
  for (int j = low; j < high; j++) 
  {
    if (array[j] <= pivot) 
	{
      i++;
      swap(&array[i], &array[j]);
    }
  }

  swap(&array[i + 1], &array[high]);
  return (i + 1);
}
void quickSort(int array[], int low, int high) {
  if (low < high)
  { 
    int pi = partition(array, low, high);
    quickSort(array, low, pi - 1);
    quickSort(array, pi + 1, high);
  }
}
void Linear(int arr[], int len, int ser)
{
        int i,count = 0;
        for(i=0;i<len;i++)
        {
                if(ser == arr[i])
                {
                        count++;
                        printf("Element present at index::%d",i+1);
                }
        }
        if(count==0)
        {
                printf("No such element is present");
        }
}
int Binary(int arr[], int len, int ser)
{
        int i,low=0,mid,high,count = 0;
        high = len-1;
        while(low<=high)
        {
                mid = (low+high)/2;
                if(ser == arr[mid])
                {
                        printf("Element present at index::%d",mid);
                        return 0;
                }
                else if(ser>arr[mid])
                {
                        low = mid+1;
                }
                else if(ser<arr[mid])
                {
                        high = mid-1;
                }
        }
        return -1;
}
int Sort(int arr[],int len,int ser)
{
        int i,j,ans;
        for(i=0;i<len;i++)
        {
                for(j=0;j<len-i-1;j++)
                {
                        if(arr[j+1]<arr[j])
                        {
                                arr[j] = arr[j] + arr[j+1];
                                arr[j+1] = arr[j] - arr[j+1];
                                arr[j] = arr[j] - arr[j+1];
                        }
                }
        }
        ans = Binary(arr,len,ser);
        return ans;
}
int jumpSearch(int array[], int size, int key) {
   int start = 0;
   int end = sqrt(size); 
        while(array[end] <= key && end < size) {
      start = end; 
      end += sqrt(size);
      if(end > size - 1)
         end = size; 
   }
   for(int i = start; i<end; i++) 
   { 
      if(array[i] == key)
         return i+1; 
   }
   return -1;
}
int ternarySearch(int arr[], int s, int e, int value) {
   if(s <= e) {
      int a = (s + (e - s) /3); 
      int b = (a + (e - s) /3); 
      if(arr[a] == value)
         return a+1;
      if(arr[b] == value)
         return b+1;
      if(value < arr[a])
         return ternarySearch(arr, s, a-1, value);
      if(value > arr[b])
         return ternarySearch(arr, b+1, e, value);
      return ternarySearch(arr, a+1, b-1, value);
   }
   return -1;
}
int interpolationSearch(int arr[], int s, int e, int value) 
{
   int i,j,k,l;
   float f;

   while(s <= e && value >= arr[s] && value <= arr[e]) 
   {
      i = value - arr[s];
      j = arr[e] - arr[s]; 
      f = i / j;
      k = e - s;
      l = s + (f * k); 

      if(arr[l] == value)
         return l;
      if(arr[l] < value)
         s = l;
      else
         e = l - 1;
   }
   return -1;
}
int main()
{
	
	printf("Enter the number of elements.\n");
	unsigned int num;
	int ser;
	scanf("%d",&num);
	int i,arr[num];
	printf("Enter the  elements.\n");
	for(i=0;i<num;i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("******************* Sorting.*****************\n1.Selection Sort\n2.Bubble Sort\n3.Insertion Sort\n4.Merge Sort\n5.Quick Sort\n*********************Searching****************.\n6.Linear Search\n7.Binary Search\n8.Jump Search\n9.Ternary Search \n10.Interpolation Search \n11.Exit\n");
	int ch;
	scanf("\n%d",&ch);
	switch(ch)
	{
		case 1:
			{
				Selection(arr,num);
				break;
			}
		case 2:
			{
				Bubble(arr,num);
				break;
			}
		case 3:
			{
				Insertion(arr,num);
				break;
			}
		case 4:
			{
				mergeSort(arr,0,num-1);
				printf("After sorting  will be::");
				printArray(arr,num);
				break;
			}
		case 5:
			{
				quickSort(arr,0,num-1);
				printf("After sorting  will be::");
				printArray(arr,num);
				break;
			}
        case 6:
            {
				printf("Enter the element to be searched.\n");
				scanf("%d",&ser);
                Linear(arr, num, ser);
                break;
            }
        case 7:
            {
				printf("Enter the element to be searched.\n");
				scanf("%d",&ser);
                int ans;
                ans = Sort(arr, num, ser);
                if(ans == -1)
                {
                    printf("No such element is present");
                }
                break;
            }
        case 8:
            {
				printf("Enter the element to be searched.\n");
				scanf("%d",&ser);
                int ans;
                ans = jumpSearch(arr, num, ser);
                if(ans == -1)
                {
                    printf("No such element is present");
                }
                else
                    printf("The element present at index ::%d",ans);
                break;
            }
        case 9:
            {
				printf("Enter the element to be searched.\n");
				scanf("%d",&ser);
                int ans;
                ans =ternarySearch(arr,0, num, ser);
                if(ans == -1)
                {
                    printf("No such element is present");
                }
                else
                    printf("The element present at index ::%d",ans);
			    break;
            }
        case 10:
            {
				printf("Enter the element to be searched.\n");
				scanf("%d",&ser);
                int ans;
                ans =interpolationSearch(arr,0, num, ser);
                if(ans == -1)
                {
                    printf("No such element is present");
                }
                else
                    printf("The element present at index ::%d",ans);
                break;
            }			
		case 11:
			{
				break;
			}
		default:
			{
				printf("Invalid Choice!!!");
				main();
				break;
			}
	}
	return 0;
}


