#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100
#define MAX_NAME_LENGTH 50

// Struct to represent a product
typedef struct {
    char name[MAX_NAME_LENGTH];
    float price;
    int quantity;
} Product;
typedef struct {
    Product product;
    int quantity;
} CartItem;

// Function to add a product to the emporium
void update(Product emporium[], int *numProducts) {
    int c;
    int temp=999;
    char pro[MAX_NAME_LENGTH];
    printf("1: To Update Product Enter 0, to Add Product Enter 1\n");
    scanf("%d",&c);
    if(c==0){
        if(*numProducts==0)
    {
        printf("Emporium is Sold Out. Please come again later.\n");
    }
    else
    {
     printf("Enter Product Name (Please Note, 'Product Name' are CASE SENSITIVE): ");
    scanf("%s",pro);
    for(int i=0;i<=*numProducts;i++)
    { 
     short result;
     result=strcmp(emporium[i].name,pro);
     if(result==0)
     {
     temp=i;
     break;
     }
     else
     continue;
    }
    
printf("\nEnter Product Name (If not changed enter the same name): ");
    scanf("%s", emporium[temp].name);
    printf("\nEnter Product Price: ");
    scanf("%f", &emporium[temp].price);
    printf("\nEnter Product Quantity: ");
    scanf("%d", &emporium[temp].quantity);
    }
    }
    else
    {
    if (*numProducts >= MAX_PRODUCTS) {
        printf("\nEmporium is Full, Unable to Add more Products.\n");
        return;
    }

    printf("\nEnter Product Name: ");
    scanf("%s", emporium[*numProducts].name);
    printf("\nEnter Product Price: ");
    scanf("%f", &emporium[*numProducts].price);
    printf("\nEnter Product Quantity: ");
    scanf("%d", &emporium[*numProducts].quantity);

    (*numProducts)++;
}
}

void displayProducts(Product emporium[], int numProducts) 
{
    printf("PRODUCTS IN EMPORIUM:\n");
    for (int i = 0; i < numProducts; i++) {
        printf("----------------------------------------------------------------------------------------------------------\n");
        printf("%d. %s \t - \t\t $%.2f \t - \t Quantity: %d\n", i+1, emporium[i].name, emporium[i].price, emporium[i].quantity);
        printf("----------------------------------------------------------------------------------------------------------\n");
    }
}
    void addcart(Product emporium[], int *numProducts,CartItem cart[], int *ncrt)
    {
        
        if(*ncrt>=MAX_PRODUCTS)
        {
            printf("Cart is Full !!, Please Checkout :)\n");
        return;
        }
        else
        {
            int temp=999;
            char pro[MAX_NAME_LENGTH];
            if(*numProducts==0)
            {
                printf("No products in emporium");
            }
            else
            {
            printf("Enter Product Name (Please Note, 'Product Name' are CASE SENSITIVE): ");
    scanf("%s",pro);
    short result;
    for(int i=0;i<=*numProducts;i++)
    { 
     result=strcmp(emporium[i].name,pro);
     if(result==0)
     {
     temp=i;
     break;
     }
     else
     continue;
    }
    if(temp==999)
    {
        printf("product not found\n");
    }
    else
    {
    printf("\nEnter the quantity of the product required\n");
    scanf("%d",&cart[*ncrt].quantity);
    if(emporium[temp].quantity<cart[*ncrt].quantity)
    {
        if(emporium[temp].quantity==0)
        {
            printf("\nwe are out of stock\n");
        }
        else
        {
        char ch;
        printf("\nNot enough number of products available\n");
        printf("Number of products available = %d\n",emporium[temp].quantity);
        printf("do you want to change the quantity y or n\n");
        scanf("%c", ch);
        if(ch=='y')
        {    
             emporium[temp].quantity -= cart[*ncrt].quantity;
             cart[*ncrt].product = emporium[temp];
             (*ncrt)++;
        }
        }
        
    }
    else
        {
             emporium[temp].quantity -=cart[*ncrt].quantity ;
             cart[*ncrt].product = emporium[temp];
             (*ncrt)++;
        }
        }
        }
        }
    }
        void displayCart(CartItem cart[], int ncrt) {
    printf("Items in the cart:\n");
    for (int i = 0; i < ncrt; i++) {
        printf("%d. %s - $%.2f - Quantity: %d\n", i+1, cart[i].product.name, cart[i].product.price, cart[i].quantity);
    }
        }
    void total(CartItem cart[], int *ncrt)
    {
        int c;
        int total=0;
        for(int i=0;i<*ncrt;i++)
        {
          total=total+(cart[i].product.price*cart[i].quantity);
        }
        printf("Total amount of all items: %d\n",total);
        printf("Do you want to check out 1 for yes 2 for no\n");
        scanf("%d",&c);
        if (c==1)
        {
            *ncrt=0;
            printf("Thank you for shopping, come again\n");
        }
    }
    
int main() {
    Product emporium[MAX_PRODUCTS];
    CartItem cart[MAX_PRODUCTS];
    int ch;
    int numProducts = 0;
    int ncrt=0;
    short pass=0000;
    char choice;
    do
    {
        printf("Welcome to our shop\n");
        printf("press 1 to access the shopkeeper's menu or 2 to access customer's menu, 3 to exit\n");
        scanf("%d",&ch);
        if(ch==1)
        {   int temp;
            printf("enter your password\n");
            scanf("%d",&temp);
            if(temp==pass)
            {
                do {
        printf("\nShopkeeper's Emporium Menu:\n");
        printf("1. Add or Update Product\n");
        printf("2. Display Products\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice) {
            case '1':
                update(emporium, &numProducts);
                break;
            case '2':
                displayProducts(emporium, numProducts);
                break;
            case '3':
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != '3');
            }
            else
            {
                printf("wrong password\nprogram exit");
                exit(0);
            }
        }
        else if(ch==2)
        { do
        {
          printf("\nCustomer's Emporium Menu:\n");
          displayProducts(emporium, numProducts);
         printf("1. Add products to cart\n");
         printf("2. Display Products in cart\n");
         printf("3. Total price\n");
         printf("4. Exit");
         printf("Enter your choice: ");
         scanf(" %c", &choice);  
          switch (choice) {
            case '1':
                addcart(emporium, &numProducts,cart, &ncrt);
                break;
            case '2':
                displayCart(cart, ncrt);
                break;
            case '3':
                 total(cart, &ncrt);
                 break;
            case '4':
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
        }while(choice!='4');
        }
        else if(ch==3)
        {
            printf("Exiting....\n");
        }
        else
        {
            printf("Wrong choice\n");
        }
    }while(ch!=3);
    return 0;
}