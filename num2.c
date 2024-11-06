#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Logo(void);

int main(void) {
    Logo();
    int input, target, difference, threshold = 10, max;

    printf("请输入游戏最大值\n");
    scanf_s("%d", &max); 
    srand((unsigned int)time(0)); // 使用当前时间作为种子
    target = rand() % (max + 1); // 生成1~max的随机数

    printf("输入一个数字，我会告诉你大了或者小了，直到你猜中正确数字(1~%d以内的数)\n", max);

    while (1) {
        printf("请输入你的猜测: ");  // 增加提示信息
        scanf_s("%d", &input); 

        difference = input - target;

        if (difference < 0) {
            if (target - input <= threshold) {
                printf("数小了，但非常接近！\n");
            }
            else {
                printf("数太小了！\n");
            }
        }
        else if (difference > 0) {
            if (input - target <= threshold) {
                printf("数大了，但非常接近！\n");
            }
            else {
                printf("数太大了！\n");
            }
        }
        else {
            printf("恭喜你猜对了，游戏结束！正确数字是 %d\n", target);
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
