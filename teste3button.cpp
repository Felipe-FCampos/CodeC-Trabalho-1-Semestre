#include <cstdio>

void showMessage()
{
    printf("Button clicked!\n");
}

int main()
{
    printf("Press Enter to click the button.\n");
    getchar(); // Wait for Enter key press

    showMessage();

    return 0;
}

