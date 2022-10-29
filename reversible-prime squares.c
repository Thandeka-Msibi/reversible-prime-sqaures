/* @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

author; Thandeka 
purpose; A program that prints the first 10 reversible prime squares in C
email; thandekavioletmsibi@gmail.com

@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*/


#include <stdio.h>
#include <math.h>


int reverse(int n)
{
    int rev = 0, remainder = 0;
    while (n > 0){
        remainder = n % 10;
        rev = rev * 10 + remainder;
        n = n / 10;
    }
    return rev;
}

int isPalindrome(int n)
{
   
    int flag = 0;

    if (n == reverse(n)){
        //printf("Given number is a palindromic number");  
        flag = 1;
        return flag;
    }
    return flag; 
}

int isPrime(int number){
    int i, flag = 1;

    for(i = 2; i <= number/2; i++)    
    {    
        if(number%i==0)    
        {    
            //printf("Number is not prime");    
            flag = 0;   
            break;    
        }    
    }    
    
    return flag; 
}

int findSqrt(int number)
{
   
    int i = 0, rootFloor;
    float root = 1;

    while (1)
    {
        i = i + 1;
        root = (number / root + root) / 2;
        if (i == number + 1) { break; }
    }
    rootFloor = floor(root);
    return rootFloor;

}

int IsSquare_of_prime(int n)
{   
	int sqrt, flag = 0;
    sqrt = findSqrt(n);
    
    if(isPrime(sqrt) == 1){
        flag = 1;
    }
    
    return flag;

}




int main(int argc,char* argv[]) {
 
    int i, count = 1;                                  
    
    for(i = 168; i < 100000; i++)
    {
        int p = isPalindrome(i);
       
        if(p == 0)
        { 
            int s = IsSquare_of_prime(i);
            
            
            if( s == 1 && (i == (findSqrt(i)*findSqrt(i))))
            {
                //printf("%d \n", i);

                int iRev = reverse(i);

                if(IsSquare_of_prime(iRev) == 1){
                    printf("%d \n  ", count);
                    printf("%d ", i);
                    printf("%d \n", iRev);
                    count++;
                }
                
            }
        }

        if(count == 11)
            break;

        //i++;
    }

    return 0;
    
} 

