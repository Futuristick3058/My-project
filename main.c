#include<stdio.h>
#include<cs50.h>
#include<math.h>

int main (void)
{
    long card_number = get_long("Enter card number: ");

    long before_last_number = 0;
    long last_number = 0;
    long card_number_sum = 0;
    int digit_number = 0;

    while(card_number != 0)
    {
        long card_number_value = card_number % 10;
        before_last_number = last_number;
        last_number = card_number_value;
        card_number = card_number / 10;        

        if(digit_number % 2 == 0)
        {
            //do nothing
        }
        else
        {
            card_number_value = card_number_value * 2;

            if(card_number_value > 9)
            {
                card_number_value = card_number_value / 10 + card_number_value % 10;
            }
        }

        digit_number++;

        card_number_sum += card_number_value;

    }

    if(digit_number < 13 || digit_number > 16 || card_number_sum % 10 != 0)
    {
        printf("INVALID\n");
    }
    else
    {
        if(last_number == 3  && (before_last_number == 4 || before_last_number == 7))
        {
            printf("AMEX\n");
        }
        else if(last_number == 4)
        {
            printf("VISA\n");
        }
        else if(last_number == 5 && before_last_number >= 1 && before_last_number <= 5)
        {
            printf("MASTERCARD\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
}
