#include <iostream>
#include <stdio.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
const int MAX_SIZE=100;
int size=0;
int main(int argc, char** argv) {
	int arr[MAX_SIZE];
    int tongUoc=0, count_PerfectNum=0;
	int max1st_idx;
	int max2nd_idx;
	int left,right,found;
	while(1)
	{
		int choice;
		printf("\n===================MENU===================\n");
		printf("1. Nhap so phan tu va gia tri cho mang\n");
		printf("2. In ra cac gia tri phan tu trong mang\n");
		printf("3. Dem so luong cac cac so hoan hao trong mang\n");
		printf("4. Tim ra gia tri lon thu hai trong mang\n");
		printf("5. Them mot phan tu vao mang\n");
		printf("6. Xoa phan tu tai mot vi tri cu the\n");
		printf("7. Sap xep mang theo thu tu tang dan(Insertion Sort)\n");
		printf("8. Tim kiem phan tu\n");
		printf("9. Sap xep toan bo so chan dung truoc, toan bo so le dung sau\n");
		printf("10. Dao nguoc thu tu cac phan tu trong mang\n");
		printf("Lua chon cua ban: ");
		scanf("%d", &choice);
		switch(choice){
			case 1:
				int n;
				printf("Nhap vao so phan tu cho mang: ");
				scanf("%d",&n);
				if(n<0)
				{
					printf("So nhap vao khong hop le!");
					break;
				}
				for(int i=0;i<n;i++)
				{
					printf("Nhap vao gia tri arr[%d]=",i);
					scanf("%d",&arr[i]);
				}
				size=n;
				printf("Nhap du lieu thanh cong!");
				break;			
			case 2:
				if(size==0)
				{
					printf("Mang chua co du lieu");
					break;
				}
				printf("Mang hien tai: \n");
				for(int i=0;i<size;i++)
				{
					printf("arr[%d]=%d\n",i,arr[i]);
				}
				break;
			case 3:
				for(int i=0;i<size;i++)
				{
					for(int j=1;j<arr[i];j++)
					{
						if(arr[i]%j==0 && arr[i]>5)
						{
							tongUoc+=j;
						}
					}
					if(tongUoc==arr[i]){
						count_PerfectNum++;
					}
				}
				printf("So luong so hoan hao trong mang la %d",count_PerfectNum);
				break;
			case 4:
				if(size==0)
				{
					printf("Mang chua co du lieu");
					break;
				}
				max1st_idx=arr[0];
				max2nd_idx=0;
				for(int i=1;i<size;i++)
				{
					if(arr[i]>max1st_idx)
					{
						max1st_idx=arr[i];
					}
				}
				for(int j=0;j<size;j++)
				{
					if(arr[j]<max1st_idx && arr[j]>max2nd_idx)
					{
						max2nd_idx=arr[j];
					}
				}
				printf("Gia tri lon thu hai trong mang la: %d",max2nd_idx);
				break;
			case 5:
				int add_idx, add_value;
				printf("Mang hien tai: \n");
				for(int i=0;i<size;i++)
				{
					printf("arr[%d]=%d\n",i,arr[i]);
				}
				printf("\nNhap vao gia tri muon them: ");
				scanf("%d",&add_value);
				printf("Nhap vi tri muon them(0-100): ");
				scanf("%d",&add_idx);
				if(add_idx<0 || add_idx>MAX_SIZE)
				{
					printf("Vi tri khong hop le!(0-100)");
					break;
				}
				if(add_idx==0)
				{
					add_idx=0;
				}
				else if(add_idx>=size)
				{
					add_idx=size;
				}
				for(int i=size;i>add_idx;i--)
				{
					arr[i]=arr[i-1];
				}
				arr[add_idx]=add_value;
				size++;
				printf("Them thanh cong!");
				break;
			case 6:
				if(size==0)
				{
					printf("Mang chua co du lieu");
					break;
				}
				int delete_idx;
				printf("Mang hien tai: \n");
				for(int i=0;i<size;i++)
				{
					printf("arr[%d]=%d\n",i,arr[i]);
				}
				printf("\nNhap vao vi tri muon xoa: ");
				scanf("%d",&delete_idx);
				if(delete_idx<0 || delete_idx>=size)
				{
					printf("Vi tri khong hop le!");
					break;
				}
				for(int i=delete_idx;i<size;i++)
				{
					arr[i]=arr[i+1];
				}
				printf("Xoa thanh cong!");
				size--;
				break;
			case 7:
				if(size==0)
				{
					printf("Mang chua co du lieu");
					break;
				}
				printf("Mang hien tai: \n");
				for(int i=0;i<size;i++)
				{
					printf("arr[%d]=%d\n",i,arr[i]);
				}
				for(int i=2;i<size;i++)
				{
					int key=arr[i];
					int j=i-1;
					for(;j>=0 && arr[j]>key;j--)
					{
						arr[j+1]=arr[j];
					}
					arr[j+1]=key;
				}
				printf("\nMang sau khi sap xep: \n");
				for(int i=0;i<size;i++)
				{
					printf("arr[%d]=%d\n",i,arr[i]);
				}
				break;
			case 8:
				for(int i=0;i<size;i++)
				{
					for(int j=0;j<size-i-1;j++)
					{
						if(arr[j]>arr[j+1])
						{
							int temp=arr[j];
							arr[j]=arr[j+1];
							arr[j+1]=temp;
						}
					}
				}
				printf("Mang sau khi sap xep: \n");
				for(int i=0;i<size;i++)
				{
					printf("arr[%d]=%d\n",i,arr[i]);
				}
				int searchValue;
                printf("Nhap gia tri can tim: ");
                scanf("%d",&searchValue);
                left=0,right=size-1,found=-1;
                while (left<=right) 
				{
                    int mid=(left+right)/2;
                    if (arr[mid]==searchValue) 
					{
                        found=mid;
                        break;
                    } 
					else if(arr[mid]<searchValue) 
					{
                        left=mid+1;
                    } 
					else 
					{
                        right=mid-1;
                    }
                }
                if (found!=-1) 
            	{
                    printf("Tim thay gia tri %d o vi tri arr[%d]\n",searchValue,found);
                } 
				else 
            	{
                    printf("Khong tim thay gia tri %d trong mang\n",searchValue);
                }
                break;
            case 9:
            	if(size==0)
				{
					printf("Mang chua co du lieu");
					break;
				}
            	printf("Mang hien tai: \n");
				for(int i=0;i<size;i++)
				{
					printf("arr[%d]=%d\n",i,arr[i]);
				}
            	for(int i=0;i<size;i++)
            	{
            		for(int j=0;j<size-i-1;j++)
            		{
            			if(arr[j+1]%2==0)
            			{
            				int temp=arr[j];
            				arr[j]=arr[j+1];
            				arr[j+1]=temp;
						}
					}
				}
				printf("Mang sau khi sap xep: \n");
				for(int i=0;i<size;i++)
				{
					printf("arr[%d]=%d\n",i,arr[i]);
				}
				break;
			case 10:
				if(size==0)
				{
					printf("Mang chua co du lieu");
					break;
				}
				printf("Mang hien tai: \n");
				for(int i=0;i<size;i++)
				{
					printf("arr[%d]=%d\n",i,arr[i]);
				}
				for(int i=0;i<(size/2);i++)
				{
					int temp=arr[i];
					arr[i]=arr[size-i-1];
					arr[size-i-1]=temp;
				}
				printf("Mang sau khi dao nguoc thu tu cac phan tu: \n");
				for(int i=0;i<size;i++)
				{
					printf("arr[%d]=%d\n",i,arr[i]);
				}
				break;
			default:
                printf("Lua chon ko hop le, vui long nhap lai\n");
                break;
		}
    }
	return 0;
}
