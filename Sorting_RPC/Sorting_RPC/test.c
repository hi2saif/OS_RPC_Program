#include<stdio.h>
#include<stdlib.h>
struct numbers { 
	int *data; 
	int size; 
}; 
void test(struct numbers *temp){
	int i;
	for(i=0;i<temp->size;i++)
	printf("%d\n",temp->data[i]); 

}
int main(){
	int n=5,i;
	struct numbers temp;
	temp.data = (int *)malloc(n * sizeof(int));
	temp.size = n;
	for(i=0; i<n; i++){
	temp.data[i] = i;;
	}
	test(&temp);
}

