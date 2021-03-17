#include<stdio.h>
#include<stdlib.h>
int physical_address();
int segment_table(int segment,int offset)
{
    //printf("\nsegment %d",segment);
    //printf("\noffset %d",offset);
    int limit[8],base[8];
    limit[0]=26;
    limit[1]=14;
    limit[2]=29;
    limit[3]=8;
    limit[4]=19;
    limit[5]=28;
    limit[6]=100;
    limit[7]=54;
    
    base[0]=90;
    base[1]=86;
    base[2]=102;
    base[3]=43;
    base[4]=5;
    base[5]=122;
    base[6]=74;
    base[7]=212;
    if(limit[segment]>offset)
   {   
        return base[segment];
    }
   else
     { printf("\nTRAP:process accessing illegal address space");
       exit(0);
     }
}
int main()
{
    long int logical_address,temp;
    int p_address;
    printf("Enter logical address: ");//segment is of 3 bits and offset of 5 bits;
    scanf("%li",&logical_address);
    int segment,offset;
    temp=logical_address;
    offset=temp%100000;
    segment=temp/100000;
    p_address= physical_address(segment,offset);
    printf("\nPhysical address : %i",p_address);
  return 0;
}
int physical_address(int segment,int offset)
{
    int base;
    int  decimal_val = 0, b = 1, rem;
   while (segment> 0)
    {
        rem = segment % 10;
        decimal_val = decimal_val + rem * b;
        segment = segment / 10 ;
        b = b * 2;
    }
    segment=decimal_val;
    
    
    b=1;
    decimal_val=0;
    while (offset > 0)
    {
        rem = offset % 10;
        decimal_val = decimal_val + rem * b;
        offset = offset / 10 ;
        b = b* 2;
    }
    offset=decimal_val;
    base=segment_table(segment,offset);
    return (base+offset);
}
 

