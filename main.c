#include <stdio.h>
#include <string.h>

#define MAX_TEXT 1000
#define MAX_STACK 100

typedef struct {
    char text[MAX_TEXT];
} TextState;

typedef struct {
    TextState states[MAX_STACK];
    int top;
} Stack;

void initializeStack(Stack *s) {
    s->top = -1;
}

int isEmpty(Stack *s) {
    return s->top == -1;
}

int isFull(Stack *s) {
    return s->top == MAX_STACK - 1;
}

int push(Stack *s, const char *text) {
    if (isFull(s)) {
        printf("Stack is full!\n");
        return 0;
    }

    s->top++;
    strcpy(s->states[s->top].text, text);
    return 1;
}

int pop(Stack *s, char *text) {
    if (isEmpty(s)) {
        return 0;
    }

    strcpy(text, s->states[s->top].text);
    s->top--;
    return 1;
}

void displayText(const char *text) {
    printf("\nCurrent Text: %s\n", text);
}

void addText(char *text, Stack *undoStack, Stack *redoStack) {
    char input[MAX_TEXT];
    char newText[MAX_TEXT];

    printf("Enter text to add: ");
    getchar();
    fgets(input, MAX_TEXT, stdin);
    input[strcspn(input, "\n")] = '\0';

    if (strlen(text) + strlen(input) >= MAX_TEXT) {
        printf("Text limit exceeded!\n");
        return;
    }

    strcpy(newText, text);
    strcat(newText, input);

    if (!push(undoStack, text)) {
        return;
    }

    strcpy(text, newText);
    initializeStack(redoStack);

    printf("Text added successfully.\n");
}

void undo(char *text, Stack *undoStack, Stack *redoStack) {
    char previousText[MAX_TEXT];

    if (isEmpty(undoStack)) {
        printf("Nothing to undo!\n");
        return;
    }

    if (!push(redoStack, text)) {
        return;
    }

    pop(undoStack, previousText);
    strcpy(text, previousText);

    printf("Undo successful.\n");
}

void redo(char *text, Stack *undoStack, Stack *redoStack) {
    char nextText[MAX_TEXT];

    if (isEmpty(redoStack)) {
        printf("Nothing to redo!\n");
        return;
    }

    if (!push(undoStack, text)) {
        return;
    }

    pop(redoStack, nextText);
    strcpy(text, nextText);

    printf("Redo successful.\n");
}

void clearText(char *text, Stack *undoStack, Stack *redoStack) {
    if (text[0] == '\0') {
        printf("The editor is already empty.\n");
        return;
    }

    if (!push(undoStack, text)) {
        return;
    }

    text[0] = '\0';
    initializeStack(redoStack);

    printf("Text cleared successfully.\n");
}

int main(void) {
    char text[MAX_TEXT] = "";
    Stack undoStack, redoStack;
    int choice;

    initializeStack(&undoStack);
    initializeStack(&redoStack);

    do {
        printf("\n===== TEXT EDITOR =====\n");
        printf("1. Add Text\n");
        printf("2. Display Text\n");
        printf("3. Undo\n");
        printf("4. Redo\n");
        printf("5. Clear Text\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            return 1;
        }

        switch (choice) {
            case 1:
                addText(text, &undoStack, &redoStack);
                break;
            case 2:
                displayText(text);
                break;
            case 3:
                undo(text, &undoStack, &redoStack);
                break;
            case 4:
                redo(text, &undoStack, &redoStack);
                break;
            case 5:
                clearText(text, &undoStack, &redoStack);
                break;
            case 6:
                printf("Exiting Text Editor. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}
