#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Logo(void);

int main(void) {
    Logo();
    int input, target, difference, threshold = 10, max;

    printf("��������Ϸ���ֵ\n");
    scanf_s("%d", &max); 
    srand((unsigned int)time(0)); // ʹ�õ�ǰʱ����Ϊ����
    target = rand() % (max + 1); // ����1~max�������

    printf("����һ�����֣��һ��������˻���С�ˣ�ֱ���������ȷ����(1~%d���ڵ���)\n", max);

    while (1) {
        printf("��������Ĳ²�: ");  // ������ʾ��Ϣ
        scanf_s("%d", &input); 

        difference = input - target;

        if (difference < 0) {
            if (target - input <= threshold) {
                printf("��С�ˣ����ǳ��ӽ���\n");
            }
            else {
                printf("��̫С�ˣ�\n");
            }
        }
        else if (difference > 0) {
            if (input - target <= threshold) {
                printf("�����ˣ����ǳ��ӽ���\n");
            }
            else {
                printf("��̫���ˣ�\n");
            }
        }
        else {
            printf("��ϲ��¶��ˣ���Ϸ��������ȷ������ %d\n", target);
            break;
        }
    }
    return 0;
}

void Logo(void) {
    printf(" __    __  __                      __      __                     \n");
    printf("/  |  /  |/  |                    /  \\    /  |                    \n");
    printf("$$ |  $$ |$$/   ______    ______  $$  \\  /$$/   ______    ______  \n");
    printf("$$  \\/$$/ /  | /      \\  /      \\  $$  \\/$$/   /      \\  /      \\ \n");
    printf(" $$  $$<  $$ | $$$$$$  |/$$$$$$  |  $$  $$/    $$$$$$  |/$$$$$$  |\n");
    printf("  $$$$  \\ $$ | /    $$ |$$ |  $$ |   $$$$/     /    $$ |$$ |  $$ |\n");
    printf(" $$ /$$  |$$ |/$$$$$$$ |$$ \\__$$ |    $$ |    /$$$$$$$ |$$ \\__$$ |\n");
    printf("$$ |  $$ |$$ |$$    $$ |$$    $$/     $$ |    $$    $$ |$$    $$/ \n");
    printf("$$/   $$/ $$/  $$$$$$$/  $$$$$$/      $$/      $$$$$$$/  $$$$$$/  \n");
    printf("                                                                   \n");
}
