#include<stdio.h>
#include <stdlib.h> 
#include <time.h>   // ��3�����ǵ���
#include <windows.h>

/*// ���������
void main(){

	
	// �����ʽ����ʼ�������� ��ÿ�η��������ǵ�ǰʱ��
	// time��ʾÿ������ʱ�����������ǵ�ǰʱ��	
	srand((unsigned)time(NULL));

	// ����10�� 100���ڵ������
	// �������������ÿ�����е��������һ��
	int i;
	for (i = 0; i < 10;i++){
		printf("%d\n" , rand() % 100);
	}
	getchar();
}*/


/*// ��̬����
void staticlloc(){

	// ��̬���٣�0.8M
	int arr[5];
	int arr[(int)(0.2*1024*1024)];

	// forѭ��
	int i = 0;
	for (; i < 5;i++){
		// ���鸳ֵ
		arr[i] = i;
		printf("%d, %p", *(arr + i), arr + i);
	}
}


// �ڴ濪��
void main(){

	// ����Stack overflow ջ���
	// ����int���͵����飺�����С��10M����int����ռ��4���ֽڣ�����ռ���ڴ���40M�ڴ�ռ�

	// ��c���з���������ģ�ͣ�ǰ������ջ����
	// int arr[10 * 1024 * 1024];
	while (true){
		Sleep(100);  // ˯100����
		staticlloc();
	}
	
	getchar();
}*/

/*
void dynamic(){
	int* arr = (int*)malloc(1 * 1024 * 1024 * sizeof(int));  // ����80M֮�󣬻᷵��һ��ָ�� 

	// �ֶ��ͷ� arr ��һ���ڴ�
	free(arr);
}

// ��̬�ڴ濪��
void main(){

	// int arr[10 * 1024 * 1024];
	
	while (true){
		Sleep(100);  // ˯100����
		dynamic();
	}
	getchar();
	}*/

/*
// ��̬�����ڴ�ʹ�ó���
void main(){

	// ����������Ҫ�����û������������Ȼ���������
	int num;

	printf("�����������");
	// ��ȡ�û������ֵ��&num��ʾ���ݵ���num�ĵ�ַ
	scanf_s("%d" , &num);  

	// ����һ�����飬���ڴ���õ�����

	// int arr[num];  �������ھ�̬���٣���̬���ٵ��ڴ��С���ܸı䣬��̬���Ըı�
	// ���Ҷ�̬���ٳ�������һ���������ڴ�ռ�

	// ʹ�ö�̬����
	int* arr = (int*)malloc(sizeof(int)*num);
	// forѭ��
	int i=0;
	int print_num;
	for (; i < num;i++){
		printf("�������%d����ֵ��",i);
		scanf_s("%d", &print_num);

		arr[i] = print_num;  // arr[i] = *(arr+i)
	}

	// �ͷ��ڴ�
	free(arr);

	getchar();
	}*/

// �ı��ڴ��С�ռ�
void main(){
	int num;
	printf("�����������");

	// ��ȡ�û������ֵ��&num��ʾ���ݵ���num�ĵ�ַ
	scanf_s("%d", &num);

	// ���������Ҫ����5���������Ƿ����ڴ治��������Ҫ�ټ�һЩ�ڴ�
	int* arr = (int*)malloc(sizeof(int)*num);
	int i = 0;
	int print_num;
	for (; i < num;i++){
		arr[i] = i; // arr[i] = *(arr+i)
	}

	// ��ӡͷָ��
	printf("�����ڴ��ָ�룺%p\n" , arr);  // �����ӡ��arr��&arr��&arr[0]��һ���ģ���3��ֵ��һ����

	// ���ھ�̬�����ڴ��С���ܸı䣬
	// �ټӵ��ڴ�
	printf("����������������");
	// ��ȡ�û������ֵ
	int new_num;
	scanf_s("%d", &new_num);

	// ����1��ԭ���ǿ��ڴ��ָ�룻����2���ܵĴ�С��ԭ���Ĵ�С+�µĴ�С��
	// ������int* ָ����������գ�Ȼ��ǿתΪint*
	int* new_arr = (int*)realloc(arr,sizeof(int)*(num+new_num));

	// ��new_arr���зǿ��жϣ���Ϊ�����ڴ���ܻ�ʧ�ܣ�ʧ�ܾͻ᷵��NULL
	if (new_arr){  // = if (new_arr != NULL)������ʾnew_arr��Ϊ�գ�һ��ֱ����if (new_arr)����

		i = new_num;
		for (; i < num + new_num; i++){
			arr[i] = i; // arr[i] = *(arr+i)
		}

		// ʹ�� realloc���¿��ٵ��ڴ��ַ��
		printf("�¿����ڴ��ָ�룺%p\n", new_arr);

		// ��ӡ������
		for (; i < num + new_num;i++){
			printf("%d,%p\n" , *(arr+i) , arr+i);
		}

	}

	// ��������ڴ�ɹ���ֻ��Ҫ�ͷ��������ڴ�Ϳ��ԣ�Ȼ�� ������ new_arr��Ϊ NULL
	if (new_arr){
		// �ͷ��ڴ棺������Ҫ�ͷ� new_arr
		free(new_arr);
		new_arr = NULL; 
	}
	else{
		// �������ʧ�ܣ����ͷ�ԭ���� arr�ڴ棬
		free(arr);
	}

	// ��Ҫ����ȥ�ͷ��ڴ�
	// ��Ϊ�ǿ��ַһ�����ͷţ��ǿ��ڴ���п��ܱ��µ�Ӧ��ռ�û����Լ���ռ���ǿ��ڴ棬��Ҫȥ�ٴ��ͷ�
	free(new_arr);
	
	getchar();

	// ��ͣ
	// system("pause");

}