/* Raj Kapadia 
 * PID: 5704911
 *
 *This Program is printing out a description for a number of items along with the item number;
 *the item count, the item description, item price and the extended price.
 *There are 6 items in this program and it uses the print function to print all values. 
 * 
 *
 *
 * */
#include  <stdio.h>

int main(){
	
	int itemNum = 0;// itemNum declared to an int
	char *description = "description "; //decription declared to an array of char 
	double price = 0.0; //price declared to a double 
	int count = 0; //count declared to an int
	//item 1
	itemNum= 345;
	count = 4;
	price = 78.51;
	description = "Bookshelf";
	
	printf("Item Num\tDescription\tPrice\tCount\tExtended Price\n ");
	//prints the columns with the necessary description. 
	
	printf("%06d\t\t%s\t$%.2lf\t%d\t$ %.2lf\n",itemNum,description, price, count, (count * price));
	//item 2
	itemNum= 7474;
        count = 100;
        price = 1.99;
        description = "Pencil";	
	 
	printf("%06d\t\t%s\t\t$%.2lf\t%d\t$ %.2lf\n",itemNum,description, price, count, (count * price));
	//item 3
	itemNum = 987;
	count = 6;
	price = 129.99;
	description ="Chair";
	
	printf("%06d\t\t%s\t\t$%.2lf\t%d\t$ %.2lf\n",itemNum,description, price, count, (count * price));
	//item 4
	itemNum = 2342;
	count = 3;
	price = 1295.40;
	description = "Computer";
	
	printf("%06d\t\t%s\t$%.2lf %d\t$ %.2lf\n",itemNum,description, price, count, (count * price));
	//item 5
	itemNum = 8864;
	count = 54;
	price = 149.99;
	description = "Headset";

	printf("%06d\t\t%s\t\t$%.2lf %d\t$ %.2lf\n",itemNum,description, price, count, (count * price));
}




