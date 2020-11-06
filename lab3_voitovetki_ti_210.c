#include <stdio.h>


int main() {
    const int n = 5;
    int m[5][5] = {
        { 1, 8, -1, 8, 7 },
        { 4, 6, -6, 5, 0},
        { 5, 2, -8, 0, 9 },
        { 6, 1, -6, 1, 9 },
        { 9, 0, -1, 1, 0 },
    };

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }

    int flag = 0, counter = 0;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (m[i][j] == 0) {
                flag=1;
                break;
            }
        }
        if (flag == 1) {
            for (int j=0; j<n; j++) {
                if (m[i][j] < 0) {
                    counter++;
                }
            }
            flag=0;
        }
    }
    printf("counter = %d\n", counter);
    int min, f = 0;
        for (int i=0; i<n; ++i) {
            min = m[i][0];
            for (int j=0; j<n; ++j) {
                if (m[i][j] <= min) {
                    min = m[i][j];
                }
            }
            for (int j=0; j<n; ++j) {
                if (m[i][j] == min) {
                    for (int k=0; k<n; ++k) {
                        if (min >= m[k][j])
                            f++;
                        else {
                            f = 0;
                            break;
                        }
                        }
                        if (f == n) {
                            printf("sedl = %d, stroka = %d, stolbik = %d\n", min, i+1, j+1);
                            f = 0;
                    }
                }
            }
        }
        int a, b, c, d, s, m1[n][n];
        for (int i=0; i<n; ++i) {
            for (int j=0; j<n; ++j) {
                s = 4;
                a = m[i+1][j];
                b = m[i-1][j];
                c = m[i][j+1];
                d = m[i][j-1];
                if (i == 0) {
                    b = 0;
                    --s;
                }
                else if (i == n-1) {
                    a = 0;
                    --s;
                }
                if (j == 0) {
                    d = 0;
                    --s;
                }
                else if (j == n-1) {
                    c = 0;
                    --s;
                }

                m1[i][j] = (a+b+c+d)/s;
                printf("%d ", m1[i][j]);
            }
            printf("\n");
        }

    return 0;
}
