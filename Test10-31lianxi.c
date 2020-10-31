#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
//我们可以选择在"abcdef"的后面追加一个字符串，就是他自己本身，然后我们进行判断，字符串arr2是否为这个arr1的子串就好了
//int is_left_move(char* str1, char* str2)
//{
//	int len1 = (int)strlen(str1);  //这里因为需要自己得自己追加字符串所以在使用函数的时候需要知道str1 长度
//	int len2 = (int)strlen(str2);   //因为返回的是一个size_t的数字  所以我强制类型转换一下
//	if (len1 != len2)
//	{
//		return 0;
//	}
//	//1.在str1中追加一个字符串
//	//这里的strcat  和 strncat 我给忘记了  需要补强
//    //但是自己在给自己追加的时候不能使用strcat函数
//	//例如abc\0 这个后面追加一个自己  你会把a放到\0的位置 后面再一次放过去，但是你会发现\0不见了  你找不到了，他不知道何时才能够停下来
//	//但是使用两个字符串来追加就没有关系  
//	//所以这里需要使用strncat
//	//strcat   
//	//char* strcat(char* strDestination ,const char* strSource)
//	//strncat
//	//char* strcat(char* strDestination ,const char* strSource,size_t count)这里具体追加了几个字符 不在考虑后面的\0
//	//例如strcat(arr1,arr2) 在arr1 后面追加一个arr2
//	strncat(str1,str1, 6); //abcdefabcdef
//	//2.判断str2 指向的字符串是否是str1指向的字符串的子串
//	//strstr--找子串的
//	char* ret = strstr(str1, str2);  //如果找到了就会在返回找到了的那个地址（c的地址）  找不到就会返回一个NULL
//	if (ret == NULL)
//	{
//		return 0;
//	}
//	else
//	{
//		return 1;
//	}
//
//}
//int main()
//{
//	char arr1[30] = "abcdef" ;      //这里还考虑了一种情况  比如     arr1[30] = "abcdef"    arr2[] = "cdef"  arr2不可能是arr1旋转得来的
//	                                 //         因为这里字符串的长度压根就不相等，只有长度相等的情况下才能考虑是否为旋转得来的
//	char arr2[] = "cdefab";   //这里我们需要判断arr2 是否是arr1左旋转而来的
//	int ret = is_left_move(arr1, arr2);
//	if (ret == 1)
//	{
//		printf("Yes\n");
//	}
//	else
//	{
//		printf("No\n");
//	}
//	return 0;
//}

//July CSDN 的博客里面去看一下这个   程序员的编程艺术   里面会有很多的有意思的思考解题方法，来求解某些面试题目


//杨氏矩阵
//有一个数字矩阵，矩阵的每行从左到右是递增的，矩阵从上到下是递增的，请编写程序再这样的矩阵中查找某个数字是否存在
//要求：时间复杂度小于O(N)  这个是什么意思好好理解一下   需要一行一行的来进行查找 但是最坏的可能性就是找N次 ，所以时间复杂度就是o(N)
                                                     //   所以这里我们需要在N次之前就找到我们需要找的数

//   1 2 3
//   2 3 4
//   3 4 5
//每行从左到右是递增的，矩阵从上到下是递增的   这一步就在告诉你应该创建一个二维数组来解题

//这题可以使用二分法
// 这里的每一行的数都是递增的，我们找到这一行最后面的那个数（他已经是这一行最大的数了）和我们需要找到的某个数 进行一个比较
//这里使用的方法就是不停的和右上角的那个元素进行比较   如果比要找的数小排除一行 ，如果比要找的数大，就排除一列
//或者使用左下角的想法来实现这个
//现在在题目后面在追加一问  当找到之后需要把其对应的下标打印出来
//int FindNum(int arr[3][3], int k, int row, int col)
//{
//	//先定义坐标
//	int x = 0;
//	int y = col - 1;
//	while (x<=2 && y>=0)  //你会发现你要找的这个数是一只再向着左下角收缩的  这里的判断条件需要看下面的y--，看x++  
//	{
//		if (arr[x][y] > k)
//		{
//			y--;
//		}
//		else if (arr[x][y] < k)
//		{
//			x++;
//		}
//		else
//		{
//			return 1;
//		}
//	}
//}
//int main()
//{
//	int arr[3][3] = { {1,2,3},{4,5,6},{7,8,9} };
//	int k = 7;
//	int ret = FindNum(arr, k, 3, 3);
//	if (ret == 1)
//	{
//		printf("找到了\n");
//	}
//	else
//	{
//		printf("找不到\n");
//	}
//	return 0;
//}


int FindNum(int arr[3][3], int k, int* px,int* py)
{
	//先定义坐标
	int x = 0;
	int y = *py - 1;
	while (x <= *px-1 && y >= 0)  //你会发现你要找的这个数是一只再向着左下角收缩的  这里的判断条件需要看下面的y--，看x++  
	{
		if (arr[x][y] > k)
		{
			y--;
		}
		else if (arr[x][y] < k)
		{
			x++;
		}
		else
		{
			*px = x;
			*py = y;
			return 1;
		}
	}
}
int main()
{
	int arr[3][3] = { {1,2,3},{4,5,6},{7,8,9} };
	int k = 7;
	int x = 3;
	int y = 3;
	int ret = FindNum(arr, k, &x, &y);
	if (ret == 1)
	{
		printf("找到了\n");
		printf("下标是：%d %d\n", x, y);
	}
	else
	{
		printf("找不到\n");
	}
	return 0;
}