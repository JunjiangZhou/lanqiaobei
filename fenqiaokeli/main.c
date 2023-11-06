//
//  main.c
//  fenqiaokeli
//
//  Created by 周俊江 on 2023/11/6.
//

#include <stdio.h>

int main() {
    int N, K;
    scanf("%d %d", &N, &K);

    int chocolates[N][2];
    int maxSide = 0;

    for (int i = 0; i < N; i++) {
        scanf("%d %d", &chocolates[i][0], &chocolates[i][1]);
        // 计算最大的边长上界
        maxSide = (chocolates[i][0] > maxSide) ? chocolates[i][0] : maxSide;
        maxSide = (chocolates[i][1] > maxSide) ? chocolates[i][1] : maxSide;
    }

    int left = 1;
    int right = maxSide;
    int result = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        int count = 0;

        for (int i = 0; i < N; i++) {
            count += (chocolates[i][0] / mid) * (chocolates[i][1] / mid);
        }

        if (count >= K) {
            result = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    printf("%d\n", result);
    return 0;
}
