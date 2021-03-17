#include<stdio.h>

int main()
{	
int no;

printf("Enter the number of elements in page table ");
scanf("%d",&no);
int frameno,f,offset,i,frame[no],page[no];
printf("Enter number of frames: ");
scanf("%d",&frameno);
printf("Enter the elements of PAGE TABLE: Frames and Page no.");

for(i=0;i<frameno;i++)
{
scanf("%d%d",&frame[i],&page[i]);
}
printf("Enter frame and offset to be searched :");
scanf("%d %d",&f,&offset);

for(i=0;i<frameno;i++)
{

if(f==frame[i])
{
printf("Page no is : %d",page[i]);
printf("Offset is : %d",offset);
}
}

return 0;
}


