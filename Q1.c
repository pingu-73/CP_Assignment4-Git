#include <stdio.h>

struct Complex
{
    float real;
    float imag;
};

struct Complex add(struct Complex c1, struct Complex c2)
{
    struct Complex result;
    result.real = c1.real + c2.real;
    result.imag = c1.imag + c2.imag;
    return result;
}

struct Complex sub(struct Complex c1, struct Complex c2)
{
    struct Complex result;
    result.real = c1.real - c2.real;
    result.imag = c1.imag - c2.imag;
    return result;
}

struct Complex mul(struct Complex c1, struct Complex c2)
{
    struct Complex result;
    result.real = c1.real * c2.real - c1.imag * c2.imag;
    result.imag = c1.real * c2.imag + c1.imag * c2.real;
    return result;
}

int main()
{
    struct Complex c1, c2, res;
    printf("Enter real and imaginary part of first complex number:\n");
    scanf("%f%f", &c1.real, &c1.imag);
    printf("Enter real and imaginary part of second complex number:\n");
    scanf("%f%f", &c2.real, &c2.imag);

    res = add(c1, c2);
    printf("Sum = %.1f + %.1fi\n", res.real, res.imag);

    res = sub(c1, c2);
    printf("Difference = %.1f + %.1fi\n", res.real, res.imag);

    res = mul(c1, c2);
    printf("Product = %.1f + %.1fi\n", res.real, res.imag);
}
