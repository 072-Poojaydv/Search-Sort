#include<stdio.h>
#include<string.h>
#include<math.h>
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
        int num,i;
        printf("Enter number of elements\n");
        scanf("%d",&num);
        int arr[num];
        printf("Enter the elements\n");
        for(i=0;i<num;i++)
        {
                scanf("%d",&arr[i]);
        }
        printf("Enter the element to be searched.\n");
        int ser, choice;
        scanf("%d",&ser);
        printf("****** MAIN MENU *******\n1.Linear Search\n2.Binary Search\n3.Jump Search\n4.Ternary Search \n5.Interpolation Search \n6.exit\nEnter your choice::\n");
        scanf("%d",&choice);
        switch(choice)
        {
                case 1:
                        {
                                Linear(arr, num, ser);
                                break;
                        }
                case 2:
                        {
                                int ans;
                                ans = Sort(arr, num, ser);
                                if(ans == -1)
                                {
                                        printf("No such element is present");
                                }
                                break;
                        }
                case 3:
                        {
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
                case 4:
                        {
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
                case 5:
                        {
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
                case 6:
                                break;
                default:
                        {
                                printf("Invalid Choice");
                                break;
                        }
        }
        return 0;
}
