#include<stdio.h>

int binary_search_increasing(int a[],int size,int key)
{
	int l,r,mid;
	while(l<=r)
	{
			mid=(l+r)/2;

		if(a[mid]==key)
		{
			return mid;
		}
		else if(a[mid]<key)
		{
			l=mid+1;	
		}

		else
		{
			r=mid-1;
		}
	}
	return -1;
}

int binary_search_decreasing(int a[],int sixe,int key)
{
	int l,r,mid;
	while(l<=r)
	{
			mid=(l+r)/2;

		if(a[mid]==key)
		{
			return mid;
		}
		else if(a[mid]<key)
		{
			r=mid-1;
			
		}
		else
		{
			l=mid+1;
		}
		
	}
	return -1;
}
int main()
{
	int size,key,index,i;
	printf("enter the array size:");
	scanf("%d",&size);
	
	int a[size];
	printf("enter the array elements:");
	for(i=0;i<size;i++){
		scanf("%d",&a[i]);
	}
	printf("enter the element you want to search: ");
	scanf("%d",&key);
	
	if(a[0]<a[1])
	{
	index=binary_search_increasing(a,size,key);	
	}
	else
	{
		index=binary_search_decreasing(a,size,key);
	}
	
	if(index==-1)
	{
		printf("element %d is not present in an array.",key);
		
	}
	else
	{
		printf("element %d is present and found at index %d",key,index);
	}
	return 0;
}
