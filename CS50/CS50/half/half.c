// Calculate your half of a restaurant bill
// Data types, operations, type casting, return value

#include <cs50.h>
#include <stdio.h>

float half(float bill, float tax, int tip);

int main(void)
{
    float bill_amount = get_float("Bill before tax and tip: ");
    float tax_percent = get_float("Sale Tax Percent: ");
    int tip_percent = get_int("Tip percent: ");

    printf("You will owe $%.2f each!\n", half(bill_amount, tax_percent, tip_percent));

}

// TODO: Complete the function
float half(float bill_amount, float tax_percent, int tip_percent)
{
    float tax = tax_percent*0.01;
    float tip = tip_percent*0.01;
    float aftertax = bill_amount * tax + bill_amount;
    float aftertip = aftertax*tip+aftertax;
    float total = aftertip/2;
    return total;
}


//float tax = tax_percent * 0.01;
//float tip = tip_percent * 0.01;
//float add_tip = bill_amount*tax+bill_amount;
//float total = add_tip*tip;

