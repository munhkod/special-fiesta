/*
 * APL121 - Бие даалт №1 (Code Quest)
 * Сэдэв №12: Тооны шидэт хүснэгт
 *
 * Хэрэглэгчээс 3 тоо, хүснэгтийн мөрийн тоог аваад:
 *   - 3 тооны үржүүлэх хүснэгтийг хамтад нь хэвлэнэ,
 *   - тоо бүрийн тэгш/сондгой, цифрийн нийлбэр, урвуу тоо,
 *     ангилал, "шидэт" эсэхийг хүснэгтээр гаргана,
 *   - хамгийн их цифрийн нийлбэртэй тоог олно.
 *
 * Компайл:  gcc main.c -o main
 * Ажиллуулах: ./main   (Windows: main.exe)
 */
#include <stdio.h>

/* ---- Өөрийн тогтоосон дүрмүүд (README-д тайлбарласан) ---- */
#define MIN_NUMBER   1       /* Оруулах тооны доод хязгаар         */
#define MAX_NUMBER   99999   /* Оруулах тооны дээд хязгаар (5 орон) */
#define MIN_ROWS     5       /* Үржүүлэх хүснэгтийн мөр: багадаа 5  */
#define MAX_ROWS     10      /* Үржүүлэх хүснэгтийн мөр: ихдээ 10   */
#define LUCKY_SUM    7       /* Цифрийн нийлбэр 7 бол шидэт тоо     */

/* Дэд алгоритм 1 (Flowgorithm: DigitSum)
 * Тооны цифрүүдийн нийлбэр. Жишээ: 1234 -> 1+2+3+4 = 10 */
int digitSum(int n)
{
    int sum = 0;
    while (n > 0) {
        sum = sum + n % 10;    /* сүүлийн цифрийг нэмнэ */
        n = n / 10;            /* сүүлийн цифрийг хасна */
    }
    return sum;
}

/* Дэд алгоритм 2 (Flowgorithm: Reverse)
 * Урвуу тоо. Жишээ: 1230 -> 321 */
int reverseNum(int n)
{
    int rev = 0;
    while (n > 0) {
        rev = rev * 10 + n % 10;
        n = n / 10;
    }
    return rev;
}

/* Дэд алгоритм 3 (Flowgorithm: ReadNumber)
 * idx-р тоог 1-99999 хооронд байтал дахин асууна (do-while) */
int readNumber(int idx)
{
    int n;
    do {
        printf("%d-r too (%d-%d): ", idx, MIN_NUMBER, MAX_NUMBER);
        if (scanf("%d", &n) != 1) {          /* тоо биш зүйл бичвэл */
            n = -1;
            while (getchar() != '\n');
        }
        if (n < MIN_NUMBER || n > MAX_NUMBER) {
            printf("Aldaa! %d-%d hoorond too oruulna uu.\n", MIN_NUMBER, MAX_NUMBER);
        }
    } while (n < MIN_NUMBER || n > MAX_NUMBER);
    return n;
}

/* Дэд алгоритм 4 (Flowgorithm: PrintInfo процедур, Call блок)
 * Нэг тооны мэдээллийн мөрийг хэвлэнэ */
void printInfo(int n)
{
    int sum = digitSum(n);
    int rev = reverseNum(n);

    printf("%-8d ", n);

    /* Тэгш эсвэл сондгой */
    if (n % 2 == 0) {
        printf("%-8s ", "Tegsh");
    } else {
        printf("%-8s ", "Sondgoi");
    }

    printf("%8d %8d  ", sum, rev);

    /* Цифрийн нийлбэрээр ангилах (else-if шат) */
    if (sum <= 9) {
        printf("%-7s", "Baga");
    } else if (sum <= 18) {
        printf("%-7s", "Dund");
    } else {
        printf("%-7s", "Ih");
    }

    /* Шидэт тоо: 2-оос дээш оронтой тольт тоо, ЭСВЭЛ цифрийн нийлбэр 7 */
    if ((n == rev && n >= 10) || sum == LUCKY_SUM) {
        printf(" %s\n", "Tiim *");
    } else {
        printf(" %s\n", "Ugui");
    }
}

int main(void)
{
    int a, b, c;          /* Хэрэглэгчийн 3 тоо               */
    int rows;             /* Үржүүлэх хүснэгтийн мөрийн тоо   */
    int i;
    int sumA, sumB, sumC;
    int maxNum, maxSum;
    int ch;               /* төгсгөлд Enter хүлээхэд */

    printf("=== TOONY SHIDET HUSNEGT ===\n");

    /* ---- Оролт ба шалгалт ---- */
    a = readNumber(1);
    b = readNumber(2);
    c = readNumber(3);

    do {
        printf("Urjuuleh husnegtiin mor (%d-%d): ", MIN_ROWS, MAX_ROWS);
        if (scanf("%d", &rows) != 1) {
            rows = -1;
            while (getchar() != '\n');
        }
        if (rows < MIN_ROWS || rows > MAX_ROWS) {
            printf("Aldaa! %d-%d hoorond too oruulna uu.\n", MIN_ROWS, MAX_ROWS);
        }
    } while (rows < MIN_ROWS || rows > MAX_ROWS);

    /* ---- 1. Үржүүлэх хүснэгт ---- */
    printf("\n--- Urjuuleh husnegt ---\n");
    printf("%-4s %10d %10d %10d\n", "x", a, b, c);
    printf("-------------------------------------\n");
    for (i = 1; i <= rows; i++) {
        printf("%-4d %10d %10d %10d\n", i, a * i, b * i, c * i);
    }

    /* ---- 2. Тоо бүрийн мэдээлэл ---- */
    printf("\n--- Toony medeelel ---\n");
    printf("%-8s %-8s %8s %8s  %-7s %s\n",
           "Too", "Turul", "Niilber", "Urvuu", "Angilal", "Shidet");
    printf("-------------------------------------------------------\n");
    printInfo(a);
    printInfo(b);
    printInfo(c);

    /* ---- 3. Хайлт: хамгийн их цифрийн нийлбэртэй тоо ---- */
    sumA = digitSum(a);
    sumB = digitSum(b);
    sumC = digitSum(c);

    maxNum = a;
    maxSum = sumA;
    if (sumB > maxSum) {          /* тэнцүү бол эхнийх нь үлдэнэ */
        maxNum = b;
        maxSum = sumB;
    }
    if (sumC > maxSum) {
        maxNum = c;
        maxSum = sumC;
    }

    printf("\nHamgiin ih tsifriin niilbertei too: %d (niilber = %d)\n", maxNum, maxSum);

    /* exe-г давхар товшиж ажиллуулахад цонх шууд хаагдахаас сэргийлнэ */
    printf("\nEnter darj garna uu...");
    while ((ch = getchar()) != '\n' && ch != EOF);   /* үлдсэн мөрийг цэвэрлэнэ */
    getchar();

    return 0;
}
