#include<stdio.h>
#include<stdlib.h>
#include <string.h>

#define MAX_LINE 1024
void main (int argc, char* argv[])
{
    char file_name[100]="F:\\file.txt";
	char buffer[MAX_LINE] ;
	int len = 0; //���ַ�����
	int total = 0;
	int sum = 0;
    FILE *fp;
    int i;
    fp=fopen (file_name, "r") ; //"w+"ģʽ����д������
    if(NULL==fp)
    {
        printf ("Failed to open the file !\n");
        exit (0);
    }
	//��ȡ�ļ�����
	while(! feof(fp)){

		// fgets() �ڶ��� MAX_LINE ���ַ�֮ǰ������ ���з� �� EOF ���������
		if(fgets(buffer, MAX_LINE, fp) != NULL){
			len = strlen(buffer);
			total+=len;
			//������һ���ո�֮ǰ����һ������
			sum ++;
			//len - 1 ��Ϊ��ȥ�����з���ռλ��
			for(i = 0; i < len - 1; i++){
				if(buffer[i] == ' '){
				sum ++;
				}
			}
		}
	}
	if(!strcmp(argv[1],"-w")){
		printf("��������%d\n",sum);
	}
	if(!strcmp(argv[1],"-c")){
		printf("�ַ�����%d\n",total);
	}
    fclose(fp);
}
