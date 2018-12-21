#include<stdlib.h>
#include<stdio.h>
#include "sort.h"
int main (int argc, char **argv)
{
	CLIENT *client;
	datain temp;
	dataout *res;
	int n,i,j;
	//n = argc - 3;
	//temp.size = n;
	client = clnt_create(argv[1], SORTING, SORT_VERS, "tcp");
	while(1)
	{
		printf("Available services:\n1.Sort database\n2.Search database\n3.Delete from Database\n4.Exit\n");
		scanf("%d",&temp.option);
		//temp.option = atoi(argv[2]);
		switch(temp.option)
		{
			case 1:
				printf("Enter data size to sort:\n");
				scanf("%d",&temp.size);
				printf("Enter data  to sort:\n");
				for(i=0; i<temp.size; i++)
				{
					scanf("%d",&temp.data[i]);
					//temp.data[i] = atoi(argv[j]);
				}
				res = sort_1(&temp, client);
				printf(" Data from server after sorting:\n");			
				for(i=0; i< res->result_size; i++)
				{
					printf("%d\n",res->result[i]);
				}
				break;
			case 2:	
				printf("Enter key to search:\n");
				scanf("%d",&temp.key);
				//temp.key = atoi(argv[3]);
				res = sort_1(&temp, client);
				if(res->index_search == -1)
					printf(" Data entered is not found in database\n");
				else
					printf(" Index of the key is: %d\n",res->index_search);
				break;
			case 3:
				printf("Enter data to delete:\n");
				scanf("%d",&temp.key);
				//temp.key = atoi(argv[3]);
				res = sort_1(&temp, client);
				if(res->delete_status == -1)
					printf(" Data to be  deleted not found in database\n");
				else
				{	
					printf(" Data after deleting the key: %d\n",atoi(argv[3]));
					for(i=0; i< res->result_size; i++)
					printf("%d\n",res->result[i]);
				}			
					break;
			case 4:
				exit(0);
			default:
			printf("Not a valid option\n");	
		}
	}
}
