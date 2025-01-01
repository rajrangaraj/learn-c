# Exercise 2: Binary File Handling

Create a program to manage a simple inventory system:
1. Define a struct Product with:
   - id (int)
   - name (char[50])
   - price (float)
   - quantity (int)
2. Implement functions to:
   - Add new products to "inventory.bin"
   - Read and display all products
   - Search for a product by ID
   - Update product quantity

Requirements:
- Use binary file operations (fread/fwrite)
- Implement proper error handling
- Use file positioning (fseek) for updates 