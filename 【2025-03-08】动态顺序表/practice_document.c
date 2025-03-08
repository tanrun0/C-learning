//#define _CRT_SECURE_NO_WARNINGS
//#include<stdio.h>
//#include<stdlib.h>
//
//// document function
//int main()
//{
//	FILE* fp_read = fopen("data.txt", "r");
//	FILE* fp_write = fopen("data_copy.txt", "w");
//	if (fp_read != NULL && fp_write != NULL) 
//	{
//		char s[20];
//		while (fgets(s, sizeof(s), fp_read)) 
//		{
//			fputs(s, fp_write);
//		}
//		if (feof(fp_read)) {
//			printf("you have finished");
//		}
//		else if (ferror(fp_read)) {
//			printf("There are something wrong");
//		}
//		fclose(fp_read);
//		fclose(fp_write);
//		return 0;
//	}
//}