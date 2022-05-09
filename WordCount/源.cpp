#include<stdio.h>
#include<string.h>

const int file_content_max_length = 100010;//input_file_name文件内容的最大长度

int count_number_words(char* file_content);

int main() {

	char parameter[3];
	char input_file_name[20];
	FILE* fp;
	char file_content[file_content_max_length]="";
	char file_content_line[file_content_max_length/100];//存放文件每一行的内容

	scanf("%s %s", &parameter,&input_file_name);
	fp = fopen(input_file_name, "r");//以只读方式打开文件,暂不作差错处理
	
	//将fp每行不超过file_content_max_length/100-1长度的字符按行依次送到file_content_line数组
	while (fgets(file_content_line, file_content_max_length, fp)) {
		strcat(file_content, file_content_line);
	}
	fclose(fp);

	if (parameter[1] == 'c') {
		int split_input_file_name_count = count_number_words(file_content);
		printf("单词数：%d", split_input_file_name_count);
	}
	else if (parameter[1] == 'w') {
		printf("字符数：%d", strlen(file_content));//由于是统计所有字符总数，所以字符串长度即字符总数
	}

}

//统计单词个数的函数
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