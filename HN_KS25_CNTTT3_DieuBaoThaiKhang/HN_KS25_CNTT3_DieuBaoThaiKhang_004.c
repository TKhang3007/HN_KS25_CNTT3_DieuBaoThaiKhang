#include <stdio.h>

#define MAX_SIZE 50

int main() {
	int usage[MAX_SIZE] = {120, 250, 180, 95, 310};
	int n = 5;
	int choice;
	int pos;
	int value;
	int newValue;
	int target;
	int count = 0;
	do {
		printf("\n");
		printf("======================================\n");
		printf("CHUONG TRINH QUAN LY DIEN NANG SAO MAI\n");
		printf("======================================\n");
		printf("1. Them chi so dien tieu thu\n");
		printf("2. Sua chi so dien tieu thu\n");
		printf("3. Xoa chi so dien tieu thu\n");
		printf("4. Tim kiem chi so dien tieu thu\n");
		printf("0. Thoat chuong trinh\n");
		printf("======================================\n");
		printf("Vui long nhap lua chon cua ban (0-4): ");
		scanf("%d", &choice);
		printf("\n");
		switch(choice) {
			case 1:
				printf("Mang truoc khi them: \n");
				printf("[");
				for (int i = 0; i< n; i++) {
					printf("%d", usage[i]);
					if (i < n-1) {
						printf(", ");
					}
				}
				printf("]");
				printf("\n");
				if (n == MAX_SIZE) {
					printf("Mang da day, khong the them!");
				}
				
				printf("Nhap gia tri can chen: ");
				scanf("%d", &value);
				
				printf("Nhap vi tri can chen: ");
				scanf("%d", &pos);
				if (pos < 1 || pos >= n + 1) {
					printf("Vi tri chen khong hop le!");
					break;
				}
				
				for (int i = n; i >= pos; i--) {
					usage[i] = usage[i-1];
				}
				usage[pos-1] = value;
				n++;
				printf("Mang sau khi them: \n");
				printf("[");
				for (int i = 0; i< n; i++) {
					printf("%d", usage[i]);
					if (i < n-1) {
						printf(", ");
					}
				}
				printf("]");
				printf("\n");
				break;
				
			case 2:
				printf("Mang truoc khi sua: \n");
				printf("[");
				for (int i = 0; i< n; i++) {
					printf("%d", usage[i]);
					if (i < n-1) {
						printf(", ");
					}
				}
				printf("]");
				printf("\n");
				printf("Nhap vi tri can sua: ");
				scanf("%d", &pos);
				if (pos < 1 || pos >= n + 1) {
					printf("Vi tri sua khong hop le!");
					break;
				}
				
				printf("Nhap gia tri moi: ");
				scanf("%d", &newValue);
				
				usage[pos -1] = newValue;
				printf("Mang sau khi sua: \n");
				printf("[");
				for (int i = 0; i< n; i++) {
					printf("%d", usage[i]);
					if (i < n-1) {
						printf(", ");
					}
				}
				printf("]");
				printf("\n");
				break;
				
			case 3:
				printf("Mang truoc khi xoa: \n");
				printf("[");
				for (int i = 0; i< n; i++) {
					printf("%d", usage[i]);
					if (i < n-1) {
						printf(", ");
					}
				}
				printf("]");
				printf("\n");
				if (n==0) {
					printf("Mang rong, khong the xoa");
					break;
				}
				printf("Nhap vi tri can xoa: ");
				scanf("%d", &pos);
				if (pos < 1 || pos >= n + 1) {
					printf("Vi tri xoa khong hop le!");
					break;
				}
				
				for (int i = pos - 1; i < n - 1; i++) {
					usage[i] = usage[i+1];
				}
				n--;
				printf("Mang sau khi xoa: \n");
				printf("[");
				for (int i = 0; i< n; i++) {
					printf("%d", usage[i]);
					if (i < n-1) {
						printf(", ");
					}
				}
				printf("]");
				printf("\n");
				break;
				
			case 4:
				printf("Nhap gia tri can tim: ");
				scanf("%d", &target);
				
				printf("Tim thay tai vi tri: ");
				for (int i = 0; i < n; i++) {
					if (usage[i] == target) {
						printf("%d ", i+1);
						count += 1;
					}
				}
				printf("\n");
				if (count == 0) {
					printf("Khong tim thay gia tri trong mang!");
					break;
				} else {
					printf("Tong so lan xuat hien: %d", count);
				}
				count = 0;
				printf("\n");
				break;
			case 0:
				printf("Thoat chuong trinh!");
				break;
			default:
				printf("Lua chon khong hop le!\n");
		}
	} while (choice != 0);
	return 0;
}