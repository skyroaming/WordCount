#include<stdio.h>
#include<string.h>

const int file_content_max_length = 100010;//input_file_name�ļ����ݵ���󳤶�

int count_number_words(char* file_content);

int main() {

	char parameter[3];
	char input_file_name[20];
	FILE* fp;
	char file_content[file_content_max_length]="";
	char file_content_line[file_content_max_length/100];//����ļ�ÿһ�е�����

	scanf("%s %s", &parameter,&input_file_name);
	fp = fopen(input_file_name, "r");//��ֻ����ʽ���ļ�,�ݲ��������
	
	//��fpÿ�в�����file_content_max_length/100-1���ȵ��ַ����������͵�file_content_line����
	while (fgets(file_content_line, file_content_max_length, fp)) {
		strcat(file_content, file_content_line);
	}
	fclose(fp);

	if (parameter[1] == 'c') {
		int split_input_file_name_count = count_number_words(file_content);
		printf("��������%d", split_input_file_name_count);
	}
	else if (parameter[1] == 'w') {
		printf("�ַ�����%d", strlen(file_content));//������ͳ�������ַ������������ַ������ȼ��ַ�����
	}

}

//ͳ�Ƶ��ʸ����ĺ���
int count_number_words(char* file_content) {

	int words_count = 0;
	int i = 0;

	while (file_content[i] != '\0') {
		if (file_content[i] == ' ' || file_content[i] == ',') {
			words_count++;
		}
		i++;
	}

	return words_count+1;
}