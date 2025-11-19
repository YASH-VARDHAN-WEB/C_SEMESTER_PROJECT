#include <stdio.h>

#define MAX 100   // Maximum number of products allowed

// Structure to store product details
struct Product {
    int id;            // Unique ID for each product
    char name[50];     // Product name
    float price;       // Product price
    int stock;         // Quantity in stock
};

int main() {
    struct Product inventory[MAX];  // Array of products
    int count = 0;                  // Tracks number of products added
    int choice;                     // Stores user's menu choice

    while (1) {  // Infinite loop until user chooses to exit
        // Display Menu
        printf("\n=== Inventory Management System ===\n");
        printf("1. Add Product\n");
        printf("2. Display All Products\n");
        printf("3. Search Product by ID\n");
        printf("4. Update Stock\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            // -----------------------------
            // CASE 1: Add new product
            // -----------------------------
            case 1:
                if (count < MAX) {
                    printf("Enter Product ID: ");
                    scanf("%d", &inventory[count].id);

                    printf("Enter Product Name: ");
                    scanf("%s", inventory[count].name);

                    printf("Enter Price: ");
                    scanf("%f", &inventory[count].price);

                    printf("Enter Stock Quantity: ");
                    scanf("%d", &inventory[count].stock);

                    count++;  // Increase product count
                    printf("Product added successfully!\n");
                } else {
                    printf("Inventory full! Cannot add more products.\n");
                }
                break;

            // -----------------------------
            // CASE 2: Display all products
            // -----------------------------
            case 2:
                if (count == 0) {
                    printf("No products in inventory.\n");
                } else {
                    printf("\n--- Product List ---\n");
                    for (int i = 0; i < count; i++) {
                        printf("\nID: %d\n", inventory[i].id);
                        printf("Name: %s\n", inventory[i].name);
                        printf("Price: %.2f\n", inventory[i].price);
                        printf("Stock: %d\n", inventory[i].stock);
                    }
                }
                break;

            // -----------------------------
            // CASE 3: Search product by ID
            // -----------------------------
            case 3: {
                int id, found = 0;

                printf("Enter Product ID to search: ");
                scanf("%d", &id);

                // Search the array
                for (int i = 0; i < count; i++) {
                    if (inventory[i].id == id) {
                        printf("\nProduct Found!\n");
                        printf("ID: %d\n", inventory[i].id);
                        printf("Name: %s\n", inventory[i].name);
                        printf("Price: %.2f\n", inventory[i].price);
                        printf("Stock: %d\n", inventory[i].stock);
                        found = 1;
                        break;
                    }
                }

                if (!found)
                    printf("Product not found!\n");

                break;
            }

            // -----------------------------
            // CASE 4: Update stock of a product
            // -----------------------------
            case 4: {
                int id, newStock, found = 0;

                printf("Enter Product ID to update stock: ");
                scanf("%d", &id);

                // Search for product
                for (int i = 0; i < count; i++) {
                    if (inventory[i].id == id) {
                        printf("Enter new stock quantity: ");
                        scanf("%d", &newStock);

                        inventory[i].stock = newStock;  // Update value
                        printf("Stock updated successfully!\n");
                        found = 1;
                        break;
                    }
                }

                if (!found)
                    printf("Product not found!\n");

                break;
            }

            // -----------------------------
            // CASE 5: Exit program
            // -----------------------------
            case 5:
                printf("Exiting program...\n");
                return 0;

            // -----------------------------
            // INVALID CHOICE
            // -----------------------------
            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}

                 
