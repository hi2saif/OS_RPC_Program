struct datain { 
	int data[100];
	int size;
	int option;
	int key;
}; 
struct dataout{
	int result[500];
	int result_size;
	int index_search;
	int delete_status;
};
program SORTING { 
	version SORT_VERS { 
		dataout SORT(datain) = 1; 
	} = 1; 
} = 0x23451111;
