#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void Logo(void);

int main(void) {
    Logo();
    int input, target, difference, threshold = 10, max, chance;

    printf("请输入游戏最大值\n");
    if (scanf_s("%d", &max) != 1 || max <= 0) { // 检查输入
        printf("请输入有效的正整数。\n");
        system("pause");
        return 1;
    }
    srand((unsigned int)time(0)); // 使用当前时间作为种子
    target = rand() % (max + 1); // 生成0~max的随机数
    chance = max / 15 + 2;

    printf("输入一个数字，我会告诉你大了或者小了，直到你猜中正确数字(1~%d以内的数),你一共有%d次机会\n", max, chance);

    while (chance > 0) {
        printf("请输入你的猜测: ");
        if (scanf_s("%d", &input) != 1) { // 检查输入
            printf("请输入有效的数字。\n");
            fflush(stdin); // 清除输入缓冲区
            continue;
        }

        difference = input - target;
        --chance;

        if (difference == 0) {
            printf("恭喜你猜对了，游戏结束！正确数字是 %d\n", target);
            break;
        }
        else if (difference < 0) {
            if (target - input <= threshold) {
                printf("数小了，但非常接近！你还有%d次机会\n",chance);
            }
            else {
                printf("数太小了！你还有%d次机会\n", chance);
            }
        }
        else {
            if (input - target <= threshold) {
                printf("数大了，但非常接近！你还有%d次机会\n", chance);
            }
            else {
                printf("数太大了！你还有%d次机会\n", chance);
            }
        }

        if (chance == 0) {
            printf("次数用尽，你输了！正确的数字是 %d\n", target);
        }
    }

    system("pause");
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
