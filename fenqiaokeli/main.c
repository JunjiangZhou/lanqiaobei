//
//  main.c
//  fenqiaokeli
//
//  Created by 周俊江 on 2023/11/6.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    int n,k;
    scanf("%d %d",&n,&k);
    int c[n][2];
    for (int i=0; i<n; i++) {
        scanf("%d %d",&c[i][0],&c[i][1]);
    }
    int min=c[0][0];
    for (int i=0; i<n; i++) {
        for (int j=0; j<2; j++) {
            if (c[i][j]<min) {
                min=c[i][j];
            }
        }
    }
    int result=0;
    while (result<k&&min>0) {
        for (int i=0; i<n; i++) {
            result+=c[i][0]/min+c[i][1]/min;
        }
        min-=1;
    }
    printf("%d\n",min);
    return 0;
}
