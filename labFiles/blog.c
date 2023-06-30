#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Data Access Layer (DAL)
struct Blog {
    int id;
    char title[100];
    char category[100];
    char content[1000];
};

struct Blog *blogs = NULL; // Array of blogs
int numBlogs = 0; // Number of blogs

// Service Layer
void addBlog(struct Blog blog) {
    blogs = (struct Blog *)realloc(blogs, (numBlogs + 1) * sizeof(struct Blog));
    if (blogs == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    blog.id = numBlogs + 1;
    blogs[numBlogs++] = blog;
    printf("Blog added successfully.\n");
}

void displayBlogs() {
    if (numBlogs == 0) {
        printf("No blogs available.\n");
        return;
    }

    printf("------ List of Blogs ------\n");
    for (int i = 0; i < numBlogs; i++) {
        printf("Blog ID: %d\n", blogs[i].id);
        printf("Title: %s\n", blogs[i].title);
        printf("Category: %s\n", blogs[i].category);
        printf("Content: %s\n\n", blogs[i].content);
    }
}

// Control Layer
int main() {
    int choice;
    struct Blog blog;

    do {
        printf("------ Blog System ------\n");
        printf("1. Add Blog\n");
        printf("2. Display All Blogs\n");
        printf("3. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the title: ");
                scanf(" %[^\n]", blog.title);
                printf("Enter the category: ");
                scanf(" %[^\n]", blog.category);
                printf("Enter the content: ");
                scanf(" %[^\n]", blog.content);
                addBlog(blog);
                break;
            case 2:
                displayBlogs();
                break;
            case 3:
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 3);

    free(blogs); // Free dynamically allocated memory

    return 0;
}