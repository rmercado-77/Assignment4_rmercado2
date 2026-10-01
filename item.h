#ifndef ITEM_H
#define ITEM_H

// Stores the info for one grocery store item.
struct _Item
{
    double price;
    char *sku;
    char *name;
    char *category;
};

typedef struct _Item Item;

#endif
