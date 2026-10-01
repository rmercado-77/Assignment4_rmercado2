#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"

// functions for the grocery item list
void add_item(Item *item_list, double price, char *sku,
              char *category, char *name, int index);

void free_items(Item *item_list, int size);

double average_price(Item *item_list, int size);

void print_items(Item *item_list, int size);

int main(int argc, char *argv[])
{
    Item *item_list;
    int size = 5;
    int ct;
    double average;

    // Check to see that the user entered one SKU to search for.
    if (argc != 2)
    {
        printf("Usage: %s <SKU to search for>\n", argv[0]);
        return 1;
    }

    //  Allocate the  array that holds five Item structures.
    item_list = (Item *) malloc(sizeof(Item) * size);

    if (item_list == NULL)
    {
        printf("Unable to allocate item list.\n");
        return 1;
    }

    //  Fill the five Item structures. add_item allocates memory for each text field.

    add_item(item_list, 4.00, "10169", "breakfast",
             "bagles", 0);

    add_item(item_list, 3.95, "70206", "dairy",
             "gouda cheese", 1);

    add_item(item_list, 2.49, "61066", "produce",
             "lychee", 2);

    add_item(item_list, 4.69, "41706", "frozen",
             "dino nuggies", 3);

    add_item(item_list, 15.00, "20606", "household",
             "cedarwood candle", 4);

    // Print the full list and display the average item price. 
    print_items(item_list, size);

    average = average_price(item_list, size);

    printf("###############\n");
    printf("average price of items = %f\n", average);

    // Search for the SKU entered in the command line. The size test comes first so the array is not accessed after its last valid index.
    ct = 0;

    while (ct < size && strcmp(item_list[ct].sku, argv[1]) != 0)
    {
        ct++;
    }

    // Print the matching item if it was found. 
    if (ct < size)
    {
        printf("###############\n");
        printf("Item found:\n");
        printf("item name = %s\n", item_list[ct].name);
        printf("item sku = %s\n", item_list[ct].sku);
        printf("item category = %s\n", item_list[ct].category);
        printf("item price = %f\n", item_list[ct].price);
    }
    else
    {
        printf("###############\n");
        printf("item not found\n");
    }

    // Free the string fields for each item, then free the main array of Item structure
    free_items(item_list, size);
    free(item_list);

    return 0;
}

    // Add one item to the requested position in item_list. Each string gets its own dynamically allocated memory
void add_item(Item *item_list, double price, char *sku,
              char *category, char *name, int index)
{
    item_list[index].price = price;

    // +1 gives each string room for its ending null character. 
    item_list[index].sku =
        (char *) malloc((strlen(sku) + 1) * sizeof(char));

    item_list[index].category =
        (char *) malloc((strlen(category) + 1) * sizeof(char));

    item_list[index].name =
        (char *) malloc((strlen(name) + 1) * sizeof(char));

    // Copy the input text into this item's allocated string memory.
    strcpy(item_list[index].sku, sku);
    strcpy(item_list[index].category, category);
    strcpy(item_list[index].name, name);
}

    // Free the dynamically allocated strings from every Item. The overall item_list array is freed by main after this function.
void free_items(Item *item_list, int size)
{
    int i;

    for (i = 0; i < size; i++)
    {
        free(item_list[i].sku);
        free(item_list[i].category);
        free(item_list[i].name);
    }
}

  // Calculate the average of the prices in the item list. 
double average_price(Item *item_list, int size)
{
    double total = 0.0;
    int i;

    for (i = 0; i < size; i++)
    {
        total += item_list[i].price;
    }

    return total / size;
}

// Print the name, SKU, category, and price of every item.
void print_items(Item *item_list, int size)
{
    int i;

    for (i = 0; i < size; i++)
    {
        printf("###############\n");
        printf("item name = %s\n", item_list[i].name);
        printf("item sku = %s\n", item_list[i].sku);
        printf("item category = %s\n", item_list[i].category);
        printf("item price = %f\n", item_list[i].price);
    }
}
