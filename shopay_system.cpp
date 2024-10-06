#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

struct customer{
	char name[100];
	char telp[13];
	char address[100];
	char email[100];
	char gender[20];
}customers[100];

struct product{
	char pname[100];
	int qty;
	int weight;
	double price;
	char pay[100];	
}products[100];

void readCustomerFile(customer customers[], int& size);
void insertCustomerData(customer customers[], int& size);
void mainMenu(int& size, int& size2);
void exit();
void insertProductData(product products[], int& size);
void readProductFilePrice(product products[], int& size);
void readProductFileWeight(product products[], int& size);
void readProductFile(product products[], int& size);
void printData(customer customers[], int size);
void printSingleData(customer customers[], int size);
void keySearch(char *key, customer customers[], int size);
//void searchData();
void viewProduct(product products[], int size);
void sortProductFileWeight(product products[], int& size);
void sortProductFilePrice(product products[], int& size);
int recursion(int n);

int main(){
	int size = 0;
	int size2 = 0;
	
	readCustomerFile(customers, size);
	readProductFile(products, size2);
//	readProductFileWeight(products, size);
//	readProductFilePrice(products, size);
	
//	size = 0;
	
	mainMenu(size, size2);
}

// CUSTOMER

void swapCustomer(struct customer *a, struct customer *b)
{
	customer temp = *a;
	*a = *b;
	*b = temp;
}

void customerSort(customer* arr, int length){ // ascending sorting

   int i = 0;
   int j = 0;
   int num = length;
   char name[20][10]; 
   char tempName[20][10];
   char temp[20];   
  
   
   for(i=0; i<num ; i++){

  		strcpy(tempName[i], name[i]);
   }
  
   for(i=0; i < num-1 ; i++){
		for(j=i+1; j< num; j++){
  			if(strcmp(customers[i].name,customers[j].name) > 0){
//  				strcpy(temp, customers[i].name);
//  				strcpy(customers[i].name,customers[j].name);
//  				strcpy(customers[j].name,temp);
					swapCustomer(&customers[i], &customers[j]);
  			}
  		}
  	}
	
}

void customerSortDesc(customer* arr, int length){ // descending sorting 

   int i = 0;
   int j = 0;
   int num = length;
   char name[20][10]; 
   char tempName[20][10];
   char temp[20];   
  
   
   for(i=0; i<num ; i++){

  		strcpy(tempName[i], name[i]);
   }
   
   for(i=0; i < num-1 ; i++){
		for(j=i+1; j< num; j++){
  			if(strcmp(customers[i].name,customers[j].name) < 0){
//  				strcpy(temp, customers[i].name);
//  				strcpy(customers[i].name,customers[j].name);
//  				strcpy(customers[j].name,temp);
				swapCustomer(&customers[i], &customers[j]);
  			}
  		}
  	}
	
}

void customerList(int& size){ //manggil print
//	printf("%d\n", size);
	printf("Ascending Order : ");
	customerSort(customers, size);
	for(int i=0; i<size; i++){
		printf("\nCustomer %d:\n", i+1);
		printf("Nama : %s\nAddress : %s\nEmail : %s\nGender : %s\nPhone Number : %s\n", customers[i].name, customers[i].address, customers[i].email, customers[i].gender, customers[i].telp);
		printf("\n");
	}
	
	printf("Descending Order : ");
	customerSortDesc(customers, size);
	for(int i=0; i<size; i++){
		printf("\nCustomer %d:\n", i+1);
		printf("Nama : %s\nAddress : %s\nEmail : %s\nGender : %s\nPhone Number : %s\n", customers[i].name, customers[i].address, customers[i].email, customers[i].gender, customers[i].telp);
		printf("\n");
	}
	
}

void insertCustomerData(customer *customers, int& size) // masukin data customer
{
	if(size == 100)
	{
		puts("Customer Limit Reach");
	}
	else
	{
		FILE *fp;
		
		// Name validation (only accepts alphabet of letters for the input)
		char yesno[5];
		do
		{
			int checkname = 0;
			do 		
			{
				system ("cls");
				puts("The name must consist of an alphabet of letters (a-z/A-Z)");
				printf("Customer Name: ");
				scanf("%[^\n]", customers[size].name); getchar();
				for (int a = 0; a < strlen(customers[size].name); a++)
				{
					if (isalpha(customers[size].name[a])) checkname = 1;
					else if (customers[size].name[a] == ' ') checkname = 1;
					else
					{
						checkname = 0;
						break;
					}
				}
			} while(checkname == 0);
		
			// Address
			puts("Insert your home address");
			printf("Address: ");
			scanf("%[^\n]", customers[size].address); getchar();
			
			// Email
			puts("Insert your email adress");
			printf("Email: ");
			scanf("%[^\n]", customers[size].email); getchar();
			
			// Gender validation (only accepts female / male)
			do 
			{
			puts("The gender must choose between female or male");
			printf("Gender: ");
			scanf("%[^\n]", customers[size].gender); getchar();
			} while (strcmpi(customers[size].gender, "female") != 0 && strcmpi(customers[size].gender, "male") != 0);
			
			// Phone Number validation (only accepts 12 digits of numbers for the input)
			int checktelp = 0;
			do
			{
				puts("The Phone Number must consist of 12 digits");
				printf("Phone Number: ");
				scanf("%[^\n]", customers[size].telp); getchar();
				for (int b = 0; b < strlen(customers[size].telp); b++)
				{
					if (isdigit(customers[size].telp[b]) && strlen(customers[size].telp) == 12) checktelp = 1;
					else
					{
						checktelp = 0;
						break;
					}
				}
			} while (checktelp == 0);
			
			fp = fopen("customer.txt", "w");
			for (int i = 0; i < size + 1; i++)
			{
				fprintf(fp, "%s, %s, %s, %s, %s\n", customers[i].name, customers[i].address, customers[i].email, customers[i].gender, customers[i].telp);	
			}
			fclose(fp);
			size++;
			
			do
			{
				puts("Do you want to insert again? [Yes/No]" );
				printf("Answer :  ");
				scanf("%[^\n]", yesno); getchar();
			} while (strcmpi(yesno, "Yes") != 0 && strcmpi(yesno, "No") != 0);
		} while (strcmpi(yesno, "Yes") == 0);
	}
	customerSort(customers, size); //ascending sorting
	customerSortDesc(customers, size); //descending sorting
}

void readCustomerFile(customer customers[], int& size){
	
	FILE *fp =fopen("customer.txt","r+");
	
	if(fp == NULL){
      perror("Error ");
	}

	else{
		while(!feof(fp)){
			
			fscanf(fp,"%[^,],%[^,],%[^,],%[^,],%s\n",&customers[size].name, &customers[size].address, &customers[size].email, &customers[size].gender, &customers[size].telp);
			size++;
		}
	}
	
//	customerSort(customers, size); //ascending
//	customerSortDesc(customers, size); //descending
//	customerList(size);
	
	fclose(fp);
}

void sortCustomerFile(customer customers[], int& size){ //baca file, sorting, panggil print yg customerList
	customerSort(customers, size); //ascending
	customerSortDesc(customers, size); //descending
	customerList(size);
}

// PRODUCTS

void readProductFile(product products[], int& size){
	
	FILE *fp =fopen("product.txt","r+");
	
	if(fp == NULL){
      perror("Error ");
	}

	else{
		while(!feof(fp))
		{
			
			fscanf(fp,"%[^,],%d,%d,%lf,%[^\n]\n",&products[size].pname, &products[size].qty, &products[size].weight, &products[size].price, &products[size].pay);
//			printf("Product %d:\n", size+1);
//			printf("Nama : %s\nQuantity : %d\nWeight : %d\nPrice : Rp%.lf\nPayment Method : %s\n", products[size].pname, products[size].qty, products[size].weight, products[size].price, products[size].pay);
//			printf("\n");
//			products[size].qty == recursion(products[size].qty);
			size++;
		}
	}
//	weightAscending(products, size);
//	weightDescending(products, size);
//	weightList(products, size);
	fclose(fp);
}

void swapProduct(struct product *a, product *b){
	product temp = *a;
	*a = *b;
	*b = temp;
}

void weightAscending(product* arr, int lenght){
	int i = 0;
    int j = 0;
//    int lenght;   
   
   for(i=0; i<lenght ; i++){
  	//	strcpy(tempName[i], name[i]);
	   for(j=0; j < lenght-i-1 ; j++){
	  			if(products[j].weight > products[j+1].weight){
	  				swapProduct(&products[j], &products[j+1]);
//	  				strcpy(temp, customers[i].name);
//	  				strcpy(customers[i].name,customers[j].name);
//	  				strcpy(customers[j].name,temp);
	  			}
	  		}
	  	}
}

int recursion(int n)
{
	if(n == 1)
	{
		return 1;
	}
	else if(n > 1)
	{
		return n + recursion(n-1);
	}
}

void weightDescending(product* arr, int lenght){
	int i = 0;
    int j = 0;
//    int lenght;   
   
   for(i=0; i<lenght ; i++){
  	//	strcpy(tempName[i], name[i]);
	   for(j=0; j < lenght-i-1 ; j++){
	  			if(products[j].weight < products[j+1].weight){
	  				swapProduct(&products[j], &products[j+1]);
//	  				strcpy(temp, customers[i].name);
//	  				strcpy(customers[i].name,customers[j].name);
//	  				strcpy(customers[j].name,temp);
	  			}
	  		}
	  	}
}

void weightList(product* products, int size){ //manggil print
//	printf("%d\n", size);
	printf("Ascending Order for weight : \n");
	weightAscending(products, size);
	for(int i=0; i<size; i++){
		printf("Product %d:\n", i+1);
		printf("Nama : %s\nQuantity : %d\nWeight : %d\nPrice : Rp%.lf\nPayment Method : %s\n", products[i].pname, recursion(products[i].qty), products[i].weight, products[i].price, products[i].pay);
		printf("\n");
	}
	
	printf("Descending Order : ");
	weightDescending(products, size);
	for(int i=0; i<size; i++){
		printf("Product %d:\n", i+1);
		printf("Nama : %s\nQuantity : %d\nWeight : %d\nPrice : Rp%.lf\nPayment Method : %s\n", products[i].pname, recursion(products[i].qty), products[i].weight, products[i].price, products[i].pay);
		printf("\n");
	}
	
}

void priceAscending(product* arr, int lenght){
	int i = 0;
    int j = 0;
//    int lenght;   
   
   for(i=0; i<lenght ; i++){
  	//	strcpy(tempName[i], name[i]);
	   for(j=0; j < lenght-i-1 ; j++){
	  			if(products[j].price > products[j+1].price){
	  				swapProduct(&products[j], &products[j+1]);
//	  				strcpy(temp, customers[i].name);
//	  				strcpy(customers[i].name,customers[j].name);
//	  				strcpy(customers[j].name,temp);
	  			}
	  		}
	  	}
}

void priceDescending(product* arr, int lenght){
	int i = 0;
    int j = 0;
//    int lenght;   
   
   for(i=0; i<lenght ; i++){
  	//	strcpy(tempName[i], name[i]);
	   for(j=0; j < lenght-i-1 ; j++){
	  			if(products[j].price < products[j+1].price){
	  				swapProduct(&products[j], &products[j+1]);
//	  				strcpy(temp, customers[i].name);
//	  				strcpy(customers[i].name,customers[j].name);
//	  				strcpy(customers[j].name,temp);
	  			}
	  		}
	  	}
}

void priceList(product* products, int size){ //manggil print
	
	printf("Ascending Order for price : \n");
	priceAscending(products, size);
	for(int i=0; i<size; i++){
		printf("Product %d:\n", i+1);
		products[i].qty = recursion(products[i].qty);
		printf("Nama : %s\nQuantity : %d\nWeight : %d\nPrice : Rp%.lf\nPayment Method : %s\n", products[i].pname, recursion(products[i].qty), products[i].weight, products[i].price, products[i].pay);
		printf("\n");
	}
			
	printf("Descending Order : ");
	priceDescending(products, size);
	for(int i=0; i<size; i++){
		printf("Product %d:\n", i+1);
		products[i].qty = recursion(products[i].qty);
		printf("Nama : %s\nQuantity : %d\nWeight : %d\nPrice : Rp%.lf\nPayment Method : %s\n", products[i].pname, recursion(products[i].qty), products[i].weight, products[i].price, products[i].pay);
		printf("\n");
	}
	
}

void viewProduct(product products[], int size){	
	system("cls");
	int input;
	do
	{
		puts("1. Order by Weight");		
		puts("2. Order by Price");

//		do
//		{
			printf("Input (0 to go back):\n");
			printf(">>> ");
			scanf("%d", &input); getchar();
		}
		while(input < 1 || input > 2);
		
//		if(input == 0) 
//			continue;	
		
		switch(input){
			case 1 :
				system("cls");
				sortProductFileWeight(products, size); 
				break;
			
			case 2 : 
			
				system("cls");
				sortProductFilePrice(products, size); 
				break;
			}
//	while(input!=0);
}

void insertProductData(product products[], int& size){
			
	if(size == 100)
	{
		puts("Product Limit Reach");
	}
	else
	{
		FILE *fp;
		
		// Name validation (only accepts alphabet of letters for the input)
		char yesno[5];
		do
		{
			int checkname = 0;
			do 		
			{
				system ("cls");
				puts("The name must consist of an alphabet of letters (a-z/A-Z)");
				printf("Product Name: ");
				scanf("%[^\n]", products[size].pname); getchar();
				for (int a = 0; a < strlen(products[size].pname); a++)
				{
					if (isalpha(products[size].pname[a])) checkname = 1;
					else if (products[size].pname[a] == ' ') checkname = 1;
					else
					{
						checkname = 0;
						break;
					}
				}
			} while(checkname == 0);
		
			// Quantity
			puts("Insert the quantity of product");
			printf("Quantity: ");
			scanf("%d", &products[size].qty);
			
			// Weight
			puts("Insert the weight of product (in kilograms)");
			printf("Weight: ");
			scanf("%d", &products[size].weight);
			
			
			// Price
			puts("Insert the price of product (in Indonesian Rupiah)");
			printf("Price: Rp");
			scanf("%lf", &products[size].price);
			
			// Payment methods validation 
		//	char bank[100];
			getchar();
			do 
			{
			puts("The payment method can only choose between this following options :");
			puts("1. COD (Cash On Delivery)");
			puts("2. Shopaylater");
			puts("3. Bank Transfer (BCA/BNI/Mandiri)");
			printf("Payment Methods : ");
			scanf("%[^\n]", products[size].pay); getchar();
			
			
	//		if(strcmp(products[size].pay, "Bank Transfer") == 0 || strcmpi(products[size].pay, "bank transfer") == 0 || strcmpi(products[size].pay, "Bank transfer") == 0 || strcmpi(products[size].pay, "bank Transfer") == 0 ){
	//			puts("Pick which bank you will use");
	//			puts("1. BCA");
	//			puts("2. BNI");
	//			puts("3. Mandiri");
	//			scanf("[^\n]", bank); getchar();
	//			
	//			products[size].pay += bank;
	//		}
	
			} while (strcmpi(products[size].pay, "COD") != 0 && strcmpi(products[size].pay, "Shopaylater") != 0 && strcmpi(products[size].pay, "Bank Transfer") != 0 && strcmpi(products[size].pay, "bank transfer") != 0 && strcmpi(products[size].pay, "Bank transfer") != 0 && strcmpi(products[size].pay, "bank Transfer") != 0);
		
				
			fp = fopen("product.txt", "w");
			for (int i = 0; i < size + 1; i++){
				fprintf(fp, "%s, %d, %d, %lf, %s\n", products[i].pname, products[i].qty, products[i].weight, products[i].price, products[i].pay);	
			}
			fclose(fp);
			size++;
			
			do
			{
				puts("Do you want to insert again? [Yes/No]" );
				printf("Answer :  ");
				scanf("%[^\n]", yesno); getchar();
			} while (strcmpi(yesno, "Yes") != 0 && strcmpi(yesno, "No") != 0);
		} while (strcmpi(yesno, "Yes") == 0);
	}
	// Sorting Weight
	weightAscending(products, size);
	weightDescending(products, size);
	priceAscending(products, size);
	priceDescending(products, size);
}

void readProductFileWeight(product products[], int& size){ //gajadi
	
	FILE *fp =fopen("product.txt","r+");
	
	if(fp == NULL){
      perror("Error ");
	}

	else{
		while(!feof(fp))
		{
			
			fscanf(fp,"%[^,],%d,%d,%lf,%[^\n]\n",&products[size].pname, &products[size].qty, &products[size].weight, &products[size].price, &products[size].pay);
//			printf("Product %d:\n", size+1);
//			printf("Nama : %s\nQuantity : %d\nWeight : %d\nPrice : Rp%.lf\nPayment Method : %s\n", products[size].pname, products[size].qty, products[size].weight, products[size].price, products[size].pay);
//			printf("\n");
			size++;
		}
	}	
//	weightAscending(products, size);
//	weightDescending(products, size);
//	weightList(products, size);
	fclose(fp);
}

void readProductFilePrice(product products[], int& size){ //gajadi
	
	FILE *fp =fopen("product.txt","r+");
	
	if(fp == NULL){
      perror("Error ");
	}

	else{
		while(!feof(fp))
		{
			
			fscanf(fp,"%[^,],%d,%d,%lf,%[^\n]\n",&products[size].pname, &products[size].qty, &products[size].weight, &products[size].price, &products[size].pay);
//			printf("Product %d:\n", size+1);
//			printf("Nama : %s\nQuantity : %d\nWeight : %d\nPrice : Rp%.lf\nPayment Method : %s\n", products[size].pname, products[size].qty, products[size].weight, products[size].price, products[size].pay);
//			printf("\n");
			size++;
		}
	}	
//	priceAscending(products, size);
//	priceDescending(products, size);
//	priceList(products, size);
	fclose(fp);
}

void sortProductFileWeight(product products[], int& size){
	weightAscending(products, size); //ascending
	weightDescending(products, size); //descending
	weightList(products, size);
}

void sortProductFilePrice(product products[], int& size){
	priceAscending(products, size); //ascending
	priceDescending(products, size); //descending
	priceList(products, size);
}

// SEARCHING
void printData(customer customers[],int size){
	if(size >0){
		for(int i=0;i< size;i++){
			printf("%s %s %s %s %s\n",customers[i].name, customers[i].address, customers[i].email, customers[i].gender, customers[i].telp);
		}
	}
}

void printSingleData(customer customers[],int n){
	puts("data found!");
	printf("%s %s %s %s %s\n",customers[n].name, customers[n].address, customers[n].email, customers[n].gender, customers[n].telp);
	puts("");
}

void keySearch(char *key, customer *customers, int size)
{
//	printf("%d\n", size);
	for(int i=0;i<size;i++)
	{
		if(strncmp(customers[i].name, key, strlen(key)) == 0)
		{
			printSingleData(customers, i);
		}
	}
}

void searchData(customer customers[], int size)
{
	int input;
	char key[100];
	
	do{
		printData(customers, size);
		puts("");
		printf("Input key you want to search : ");
		scanf("%s", &key); getchar();
		
		puts("1. Search by start key");
		puts("2. Back");
		
		do{
//			puts("input 0 to go back");
			printf(">>> ");
			scanf("%d", &input); getchar();
		}while(input < 0 || input > 2);
		
		if(input == 0) continue;
		
		switch(input){
			case 1:
				keySearch(key, customers, size);
				break;
			case 2:
				break;
		}
	}while(input != 0);
}

void exit(){
	system ("cls");
	printf("Thankyou for using our application!");
	
}

// MAIN MENU
void mainMenu(int& size, int& size2){
	
	int choice;
	
	do{
		printf("-------------------------------------\n");
		printf("----------WELCOME TO SHOPAY----------\n");
		printf("-------------------------------------\n\n");
		
		printf(" ===== MAIN MENU =====\n"
				"[1] View Customer Data\n"
				"[2] Insert Customer Data\n"
				"[3] Search Customer Data\n"
				"[4] View Product Data\n"
				"[5] Insert Product Data\n"
				"[6] Exit\n\n");
				
		printf("Enter your choice in numbers : \n");
		scanf("%d", &choice); getchar();
	}while(choice<1 || choice>7);
	switch(choice){
		case 1:
			system("cls");
			sortCustomerFile(customers, size);
//			customerSort(customers, size);
//			customerSortDesc(customers, size);
			break;
		case 2:
			system("cls");
			insertCustomerData(customers, size);
			break;
		case 3:
			system("cls");
			searchData(customers, size);
			break;
		case 4:
			system("cls");
			viewProduct(products, size2);
//			readProductFile(products, size);
//			weightSort(products, size);
//			priceSort(products, size);
			break;
		case 5:
			system("cls");
			insertProductData(products, size2);
			break;
		case 6:
			system("cls");
			exit();
			break;
	}
}
