#include <stdio.h>
#include <string.h>

struct Product {
    int id;
    char name[50];
    float price;
    int quantity;
};

void addProduct(FILE *file, struct Product prod) {
    fseek(file, 0, SEEK_END);
    fwrite(&prod, sizeof(struct Product), 1, file);
}

void displayProducts(FILE *file) {
    struct Product prod;
    fseek(file, 0, SEEK_SET);
    
    while (fread(&prod, sizeof(struct Product), 1, file) == 1) {
        printf("ID: %d, Name: %s, Price: %.2f, Quantity: %d\n",
               prod.id, prod.name, prod.price, prod.quantity);
    }
}

void updateQuantity(FILE *file, int id, int newQuantity) {
    struct Product prod;
    fseek(file, 0, SEEK_SET);
    
    while (fread(&prod, sizeof(struct Product), 1, file) == 1) {
        if (prod.id == id) {
            prod.quantity = newQuantity;
            fseek(file, -sizeof(struct Product), SEEK_CUR);
            fwrite(&prod, sizeof(struct Product), 1, file);
            break;
        }
    }
}

int main() {
    FILE *file = fopen("inventory.bin", "wb+");
    if (file == NULL) return 1;

    // Add sample products
    struct Product p1 = {1, "Laptop", 999.99, 10};
    struct Product p2 = {2, "Mouse", 29.99, 50};
    addProduct(file, p1);
    addProduct(file, p2);

    // Display all products
    displayProducts(file);

    // Update quantity
    updateQuantity(file, 1, 5);

    printf("\nAfter update:\n");
    displayProducts(file);

    fclose(file);
    return 0;
} 