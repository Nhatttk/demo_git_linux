#include <stdio.h>
#include <stdlib.h>

void print_menu() {
    printf("1. Git Clone\n");
    printf("2. Git Push\n");
    printf("3. Git Pull\n");
    printf("4. Quit\n");
}

int main() {
    int choice;
    char url[1000], message[1000];

    // Token for authentication
    const char *token = "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";

    do {
        print_menu();
        printf("Nhập lựa chọn của bạn: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Nhập URL của kho: ");
                scanf("%s", url);

                // Add token to the URL for git clone
                char clone_command[1500];  // Increased buffer size
                snprintf(clone_command, sizeof(clone_command), "git clone %s%s", url, token);

                if (system(clone_command) != 0) {
                    printf("Lỗi khi thực hiện git clone.\n");
                }
                break;

            case 2:
                printf("Nhập thông điệp commit: ");
                scanf(" %[^\n]s", message);

                // Add token to the URL for git push
                char push_command[1500];  // Increased buffer size
                snprintf(push_command, sizeof(push_command), "git add . && git commit -m \"%s\" && git push origin main", message);

                if (system(push_command) != 0) {
                    printf("Lỗi khi thực hiện git push.\n");
                }
                break;

            case 3:
                if (system("git pull") != 0) {
                    printf("Lỗi khi thực hiện git pull.\n");
                }
                break;

            case 4:
                printf("Thoát chương trình.\n");
                break;

            default:
                printf("Lựa chọn không hợp lệ. Vui lòng nhập một số từ 1 đến 4.\n");
        }
    } while (choice != 4);

    return 0;
}

