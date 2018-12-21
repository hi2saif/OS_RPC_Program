#include "sort.h"
#include<stdio.h>
void merge_data(datain *argp);
void sort();
int merge[1000], index_temp;
static int index_all = 0, curr_size_of_data = 0, to_client[1000];
void sort()
{
	int i, j, temp;
   	for (i = 0; i < curr_size_of_data; i++)      
 	{
 		for (j = 0; j < curr_size_of_data-i-1; j++)
 		{
 			if(merge[j] > merge[j+1])
              		{
              			temp = merge[j];
    				merge[j] = merge[j+1];
    				merge[j+1] = temp;
			}
		}
	}
	to_client[0] = merge[0];
	index_temp = 0; 
	for(i=1;i< curr_size_of_data;i++)
	{
		if(merge[i] == to_client[index_temp])
		{
			
		}
		else
		{
			index_temp++;
			to_client[index_temp] = merge[i];
		}
	} 
	index_temp++;
	for (i = 0; i < curr_size_of_data; i++)      
 	{
				
		printf("After sorting complete data:%d\n",merge[i]);
	}
}
void merge_data(datain *argp)
{
	int index = 0, i,j=0;
	if(index_all != 0)
	{
		for(i=0; i<index_all;i++)
		{
			merge[i] = to_client[i];
		}
		
	}
	for(i=index_all; i<(index_all + argp->size);i++,j++)
	{
		merge[i] = argp->data[j];
	}
}

int search(int key,int left, int right)
{
	int middle = -1;
	if(right >= left)
   	{
        	middle = left + (right - left)/2;
        	printf("%d     %d:\n",to_client[middle],key);
		if (to_client[middle] == key)
			return middle;
		if (to_client[middle] > key) 
			return search(key, left, middle-1);
		else if(to_client[middle] < key)
			return search(key, middle+1, right);
   	}
return middle;
}

int delete(int key)
{
	int index,i;
	index = search(key, 0,index_all-1);
	printf("INDEX:%d\n",index);
	if(index == -1)
	{
		printf("Element to be deleted not found\n");
	}
	else
	{
		for(i=index; i<index_all-1;i++)
		{
			to_client[i] = to_client[i+1];
		}
		index_all--;
	}	
return index;
}

dataout * sort_1_svc(datain *argp, struct svc_req *rqstp)
{
	int i;
	dataout *out;
	curr_size_of_data = argp->size + index_all;
	switch(argp->option)
	{	

		case 1:		
			merge_data(argp);
			sort();
			index_all++;
			index_all= index_temp;	
			out->result_size = index_all;
			for(i=0; i<out->result_size; i++){
				out->result[i] = to_client[i];
			}
			break;
		case 2:
			printf("Returned index to client");
			out->index_search = search(argp->key,0,index_all-1);
			break;
		case 3:
			out->delete_status = delete(argp->key);
			out->result_size = index_all;
			for(i=0; i<out->result_size; i++){
				out->result[i] = to_client[i];
			}
			break;
		default:
			printf("Not a valid option\n");	

	}
return out;
}



