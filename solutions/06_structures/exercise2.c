#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_TITLE 100
#define MAX_NAME 50
#define LOAN_PERIOD 14 // days
#define FINE_PER_DAY 1.0 // dollars

typedef struct {
    int day;
    int month;
    int year;
} Date;

typedef struct {
    int id;
    char title[MAX_TITLE];
    char author[MAX_NAME];
    int available;
    int borrower_id;
    Date due_date;
} Book;

typedef struct {
    int id;
    char name[MAX_NAME];
    int books_borrowed;
    double fines;
} Member;

typedef struct {
    Book *books;
    int book_count;
    int book_capacity;
    Member *members;
    int member_count;
    int member_capacity;
} Library;

// Function prototypes
Library* create_library(int book_capacity, int member_capacity);
void free_library(Library *lib);
int add_book(Library *lib, const char *title, const char *author);
int add_member(Library *lib, const char *name);
int borrow_book(Library *lib, int book_id, int member_id);
int return_book(Library *lib, int book_id);
Book* search_book_by_title(Library *lib, const char *title);
void calculate_fines(Library *lib);
Date get_current_date(void);
int days_between_dates(Date d1, Date d2);

// Create library
Library* create_library(int book_capacity, int member_capacity) {
    Library *lib = malloc(sizeof(Library));
    if (!lib) return NULL;
    
    lib->books = malloc(book_capacity * sizeof(Book));
    lib->members = malloc(member_capacity * sizeof(Member));
    
    if (!lib->books || !lib->members) {
        free(lib->books);
        free(lib->members);
        free(lib);
        return NULL;
    }
    
    lib->book_count = 0;
    lib->book_capacity = book_capacity;
    lib->member_count = 0;
    lib->member_capacity = member_capacity;
    
    return lib;
}

// Add book
int add_book(Library *lib, const char *title, const char *author) {
    if (lib->book_count >= lib->book_capacity) return 0;
    
    Book *book = &lib->books[lib->book_count];
    book->id = lib->book_count + 1;
    strncpy(book->title, title, MAX_TITLE - 1);
    strncpy(book->author, author, MAX_NAME - 1);
    book->available = 1;
    book->borrower_id = -1;
    
    lib->book_count++;
    return book->id;
}

// Add member
int add_member(Library *lib, const char *name) {
    if (lib->member_count >= lib->member_capacity) return 0;
    
    Member *member = &lib->members[lib->member_count];
    member->id = lib->member_count + 1;
    strncpy(member->name, name, MAX_NAME - 1);
    member->books_borrowed = 0;
    member->fines = 0.0;
    
    lib->member_count++;
    return member->id;
}

// Get current date (simplified)
Date get_current_date(void) {
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    Date date = {tm->tm_mday, tm->tm_mon + 1, tm->tm_year + 1900};
    return date;
}

// Borrow book
int borrow_book(Library *lib, int book_id, int member_id) {
    if (book_id <= 0 || book_id > lib->book_count) return 0;
    if (member_id <= 0 || member_id > lib->member_count) return 0;
    
    Book *book = &lib->books[book_id - 1];
    Member *member = &lib->members[member_id - 1];
    
    if (!book->available) return 0;
    
    book->available = 0;
    book->borrower_id = member_id;
    
    Date current = get_current_date();
    book->due_date = current;
    book->due_date.day += LOAN_PERIOD;
    
    member->books_borrowed++;
    return 1;
}

// Return book
int return_book(Library *lib, int book_id) {
    if (book_id <= 0 || book_id > lib->book_count) return 0;
    
    Book *book = &lib->books[book_id - 1];
    if (book->available) return 0;
    
    Member *member = &lib->members[book->borrower_id - 1];
    Date current = get_current_date();
    
    int days_late = days_between_dates(book->due_date, current);
    if (days_late > 0) {
        member->fines += days_late * FINE_PER_DAY;
    }
    
    book->available = 1;
    book->borrower_id = -1;
    member->books_borrowed--;
    
    return 1;
}

// Calculate days between dates (simplified)
int days_between_dates(Date d1, Date d2) {
    // Simplified calculation - assumes 30 days per month
    int days1 = d1.year * 365 + d1.month * 30 + d1.day;
    int days2 = d2.year * 365 + d2.month * 30 + d2.day;
    return days2 - days1;
}

int main() {
    Library *lib = create_library(100, 50);
    if (!lib) return 1;
    
    // Add books and members
    int book1 = add_book(lib, "The C Programming Language", "K&R");
    int book2 = add_book(lib, "Data Structures", "Smith");
    
    int member1 = add_member(lib, "John Doe");
    int member2 = add_member(lib, "Jane Smith");
    
    // Test borrowing
    if (borrow_book(lib, book1, member1)) {
        printf("Book borrowed successfully\n");
    }
    
    // Test returning
    if (return_book(lib, book1)) {
        printf("Book returned successfully\n");
    }
    
    free_library(lib);
    return 0;
} 