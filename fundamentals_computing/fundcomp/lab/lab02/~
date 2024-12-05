//amortization table
#include <stdio.h>

int main (){

  float  principal, intrate, monpay;

  printf("Enter the inital amount: ");
  scanf("%f", &principal);

  if(principal <= 0){
    printf("You have entered a negative number.");
    printf(" Enter the new initial amount: ");
    scanf("%f", &principal);
  }

  printf("\n");

  printf("Enter the interest rate: ");
  scanf("%f", &intrate);

  if(intrate <= 0){
    printf("You have entered a negative interest rate.");
    printf(" Enter a new interest rate: ");
    scanf("%f", &intrate);
  }

  printf("\n");

  printf("Enter the desired monthly payment: ");
  scanf("%f", &monpay);

  if(monpay <= 0){
    printf("You have entered a negative monthly payement.");
    printf(" Enter a new monthly payment: ");
    scanf("%f", &monpay);
  }

  printf("\n");

  float temp = ((intrate/12) / 100) * principal;
  if(monpay <= temp){
    printf("ERROR: The desired montly payment is too small, and the balance will go up every month.\n");
    printf("Enter a new montly payment: ");
    scanf("%f", &monpay);
    printf("\n");
  }

  //create table
  printf("Month\t Payment \tInterest  \tBalance");
  printf("\n");

  float intrate_peryear = (intrate/12) / 100;

  float balance = principal;
  int month = 1;

  while(balance > monpay){
    float x = balance * intrate_peryear;
    float v = (balance - monpay) + x;
    printf("  %d\t $%10.2f\t $%10.2f\t $%10.2f", month, monpay, x, v);
    month = month + 1;
    balance = v;
    printf("\n");
  }

  float z = balance * intrate_peryear;
  float t = balance + z;
  float g = 0.00;
  printf("  %d\t $%10.2f\t $%10.2f\t $%10.2f", month, t, z, g);
  printf("\n");

  return 0;

}
