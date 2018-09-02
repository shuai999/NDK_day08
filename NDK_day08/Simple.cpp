#include<stdio.h>
#include <stdlib.h> 
#include <time.h>   // 这3个都是导包
#include <windows.h>

/*// 生成随机数
void main(){

	
	// 解决方式：初始化发生器 ，每次发生器都是当前时间
	// time表示每次运行时，发生器都是当前时间	
	srand((unsigned)time(NULL));

	// 生成10个 100以内的随机数
	// 可以随机，但是每次运行的随机数都一致
	int i;
	for (i = 0; i < 10;i++){
		printf("%d\n" , rand() % 100);
	}
	getchar();
}*/


/*// 静态开辟
void staticlloc(){

	// 静态开辟：0.8M
	int arr[5];
	int arr[(int)(0.2*1024*1024)];

	// for循环
	int i = 0;
	for (; i < 5;i++){
		// 数组赋值
		arr[i] = i;
		printf("%d, %p", *(arr + i), arr + i);
	}
}


// 内存开辟
void main(){

	// 报错：Stack overflow 栈溢出
	// 定义int类型的数组：数组大小是10M，而int类型占用4个字节，所以占用内存是40M内存空间

	// 在c中有分区，四区模型：前两个是栈、堆
	// int arr[10 * 1024 * 1024];
	while (true){
		Sleep(100);  // 睡100毫秒
		staticlloc();
	}
	
	getchar();
}*/

/*
void dynamic(){
	int* arr = (int*)malloc(1 * 1024 * 1024 * sizeof(int));  // 开辟80M之后，会返回一个指针 

	// 手动释放 arr 这一块内存
	free(arr);
}

// 动态内存开辟
void main(){

	// int arr[10 * 1024 * 1024];
	
	while (true){
		Sleep(100);  // 睡100毫秒
		dynamic();
	}
	getchar();
	}*/

/*
// 动态开辟内存使用场景
void main(){

	// 假设现在需要接收用户所输入的数，然后进行排序
	int num;

	printf("请输入个数：");
	// 获取用户输入的值，&num表示传递的是num的地址
	scanf_s("%d" , &num);  

	// 定义一个数组，用于存放用的数据

	// int arr[num];  这种属于静态开辟，静态开辟的内存大小不能改变，动态可以改变
	// 并且动态开辟出来的是一块连续的内存空间

	// 使用动态开辟
	int* arr = (int*)malloc(sizeof(int)*num);
	// for循环
	int i=0;
	int print_num;
	for (; i < num;i++){
		printf("请输入第%d个的值：",i);
		scanf_s("%d", &print_num);

		arr[i] = print_num;  // arr[i] = *(arr+i)
	}

	// 释放内存
	free(arr);

	getchar();
	}*/

// 改变内存大小空间
void main(){
	int num;
	printf("请输入个数：");

	// 获取用户输入的值，&num表示传递的是num的地址
	scanf_s("%d", &num);

	// 这里比如我要输入5个数，但是发现内存不够，我需要再加一些内存
	int* arr = (int*)malloc(sizeof(int)*num);
	int i = 0;
	int print_num;
	for (; i < num;i++){
		arr[i] = i; // arr[i] = *(arr+i)
	}

	// 打印头指针
	printf("开辟内存的指针：%p\n" , arr);  // 这里打印：arr、&arr、&arr[0]是一样的，这3个值是一样的

	// 由于静态开辟内存大小不能改变，
	// 再加点内存
	printf("请输入新增个数：");
	// 获取用户输入的值
	int new_num;
	scanf_s("%d", &new_num);

	// 参数1：原来那块内存的指针；参数2：总的大小（原来的大小+新的大小）
	// 这里用int* 指针变量来接收，然后强转为int*
	int* new_arr = (int*)realloc(arr,sizeof(int)*(num+new_num));

	// 对new_arr进行非空判断，因为新增内存可能会失败，失败就会返回NULL
	if (new_arr){  // = if (new_arr != NULL)，都表示new_arr不为空，一般直接用if (new_arr)即可

		i = new_num;
		for (; i < num + new_num; i++){
			arr[i] = i; // arr[i] = *(arr+i)
		}

		// 使用 realloc后，新开辟的内存地址；
		printf("新开辟内存的指针：%p\n", new_arr);

		// 打印数组结果
		for (; i < num + new_num;i++){
			printf("%d,%p\n" , *(arr+i) , arr+i);
		}

	}

	// 如果新增内存成功，只需要释放新增的内存就可以，然后将 新增的 new_arr置为 NULL
	if (new_arr){
		// 释放内存：这里需要释放 new_arr
		free(new_arr);
		new_arr = NULL; 
	}
	else{
		// 如果新增失败，就释放原来的 arr内存，
		free(arr);
	}

	// 不要反复去释放内存
	// 因为那块地址一旦被释放，那块内存就有可能被新的应用占用或者自己又占用那块内存，不要去再次释放
	free(new_arr);
	
	getchar();

	// 暂停
	// system("pause");

}