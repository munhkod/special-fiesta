# Псевдокод — Сэдэв №12: Тооны шидэт хүснэгт

Блок схем (`quest.fprg`)-ийн блок бүртэй дарааллаараа тохирно.

## Main

```
ЭХЛЭХ Main
    ХЭВЛЭХ "=== TOONY SHIDET HUSNEGT ==="

    // 1. Оролт (шалгалт нь ReadNumber функц дотор)
    a ← ReadNumber(1)
    b ← ReadNumber(2)
    c ← ReadNumber(3)

    ДАВТАХ
        ХЭВЛЭХ "Urjuuleh husnegtiin mor (5-10): "
        УНШИХ rows
        ХЭРЭВ rows < 5 ЭСВЭЛ rows > 10 БОЛ ХЭВЛЭХ "Aldaa!..."
    ХҮРТЭЛ НЬ БИШ (rows < 5 ЭСВЭЛ rows > 10)

    // 2. Үржүүлэх хүснэгт
    ХЭВЛЭХ "x | a | b | c"
    i = 1-ээс rows хүртэл ДАВТАХ
        ХЭВЛЭХ i | a×i | b×i | c×i
    ДАВТАЛТ ДУУСАХ

    // 3. Тоо бүрийн мэдээлэл (Call блок)
    ХЭВЛЭХ "Too | Turul | Niilber | Urvuu | Angilal | Shidet"
    ДУУДАХ PrintInfo(a)
    ДУУДАХ PrintInfo(b)
    ДУУДАХ PrintInfo(c)

    // 4. Хайлт: хамгийн их цифрийн нийлбэр
    sumA ← DigitSum(a), sumB ← DigitSum(b), sumC ← DigitSum(c)
    maxNum ← a, maxSum ← sumA
    ХЭРЭВ sumB > maxSum БОЛ maxNum ← b, maxSum ← sumB
    ХЭРЭВ sumC > maxSum БОЛ maxNum ← c, maxSum ← sumC
    ХЭВЛЭХ "Hamgiin ih tsifriin niilbertei too: " maxNum, maxSum
ДУУСАХ
```

## Function ReadNumber(idx) → n

```
    ДАВТАХ
        ХЭВЛЭХ idx "-r too (1-99999): "
        УНШИХ n
        ХЭРЭВ n < 1 ЭСВЭЛ n > 99999 БОЛ ХЭВЛЭХ "Aldaa!..."
    ХҮРТЭЛ НЬ БИШ (n < 1 ЭСВЭЛ n > 99999)
    БУЦААХ n
```

## Function DigitSum(n) → sum

```
    sum ← 0, x ← n
    x > 0 БАЙХ ҮЕД ДАВТАХ
        sum ← sum + (x mod 10)       // сүүлийн цифрийг нэмнэ
        x ← x div 10                  // сүүлийн цифрийг хасна
    БУЦААХ sum
```

## Function Reverse(n) → rev

```
    rev ← 0, x ← n
    x > 0 БАЙХ ҮЕД ДАВТАХ
        rev ← rev × 10 + (x mod 10)
        x ← x div 10
    БУЦААХ rev
```

## Procedure PrintInfo(n)

```
    sum ← DigitSum(n), rev ← Reverse(n)
    ХЭРЭВ n mod 2 = 0 БОЛ kind ← "Tegsh" ҮГҮЙ БОЛ kind ← "Sondgoi"

    ХЭРЭВ sum <= 9             БОЛ level ← "Baga"
    ҮГҮЙ БӨГӨӨД sum <= 18       БОЛ level ← "Dund"
    ҮГҮЙ БОЛ                       level ← "Ih"

    ХЭРЭВ (n = rev БА n >= 10) ЭСВЭЛ sum = 7 БОЛ lucky ← "Tiim *"
    ҮГҮЙ БОЛ                                       lucky ← "Ugui"

    ХЭВЛЭХ n | kind | sum | rev | level | lucky
```

> Flowgorithm-д `x div 10`-ийг `ToInteger((x - x % 10) / 10)` гэж бичсэн, C-д `x / 10` (бүхэл тооны хуваалт).
