#include <stdio.h>
#include <stdlib.h>
#define N 501
/*void read_formated_text_by_struct(const char* packet1)
	{
	struct read packet;
	FILE *file = fopen(C:\Users\Enolaliu\Desktop\第二次寒假作业资料\dataset\data\dataset1\packet1,"rt");
	if(!file)read
		return;
	printf("路由名单为:\n");
	while(1)
	{
		//文件读取结束
		if(EOF == fscanf(file,"%s %s %d %d %s",stu.source_ip,stu.destination_ip,&stu.source_port,&stu.destination_port,stu.protocol))
			break;
		printf("source_ip:%s destination_ip:%s source_port:%d destination_port:%d protocol:%s\n",stu.source_ip,stu.destination_ip,stu.source_port,stu.destination_port,stu.protocol);		
	}
	fclose(file);
}*/
int main()
{
    FILE *fp;
    char str[N+1];
    if( (fp=fopen("c:\\Users\\Enolaliu\\Desktop\\winter2\\dataset\\data\\dataset1\\packet1.txt","rt")) == NULL )
	{
        puts("Fail to open file!");
        exit(0);
    }
   
    while(fgets(str, N, fp) != NULL){
        printf("%s", str);
    }

    fclose(fp);
    return 0;
}
