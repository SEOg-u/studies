#include<stdio.h>
#include<stdlib.h>
#define MAX_SIZE 10

int arr[MAX_SIZE];

void selection_sort(int arr[], int n) {
	int least, tmp;
	for (int i = 0; i < n - 1; i++) {//    n-1단계 수행되도록 반복 횟수 설정
		least = i;
		for (int j = i + 1; j < n; j++) { // 각 단계에 맞는 최솟값의 index 찾기
			if (arr[least] > arr[j]) {
				least = j;
			}
		}
		tmp = arr[i]; //                     값 교환(제 자리 위치에 최솟값 넣기)
		arr[i] = arr[least];
		arr[least] = tmp;
	}
}

int main() {
	srand(time(NULL)); //       씨드 변경 함수
	int n = MAX_SIZE;

	for (int i = 0; i < n; i++) {
		arr[i] = rand() % 100; // 랜덤 값 반환 함수
	}

	printf("정렬 전 : ");
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
	
	selection_sort(arr, n);
	printf("정렬 후 : ");
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");

	return  0;
}
