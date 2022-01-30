#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
void Check_lP_in_CIDR(char* ip, char* cidr);
void read_file()
{
    char str_datapacket[N+1];
    char str_rule[N+1];
    char data_line[N+1];
    char rule_line[N+1];
    printf("datapacket path:");
    gets(str_datapacket);
    printf("rule path:");
    gets(str_rule);
    FILE *fp_input;
    if( (fp_input=fopen(str_datapacket,"rt")) == NULL )
	{
        puts("Fail to open file!");
        exit(0);
    }
    while(fgets(str_datapacket, N, fp_input) != NULL)
    {
       /*未实现功能：按行循环输出到main*/
    }
    fclose(fp_input);

     FILE *fp_rule;
    if( (fp_rule=fopen(str_rule,"rt")) == NULL )
	{
        puts("Fail to read rule!");
        exit(0);
    }
    while(fgets(str_rule, N, fp_rule) != NULL)
    {
        //printf("%s",str_rule);
        /*未实现功能：按行循环输出到main*/
    }
    fclose(fp_rule);
    return 0;
}
/*校验IP地址是否在CIDR范围内*/
void Check_lP_in_CIDR(char* ip, char* cidr)
{
    int i;
    int j = 0;
    int count = 0;
    int ipf = 0;
    int cidrf = 0;
 
    /*输入合法性检查*/
    if( !ip || !cidr )
        return -1;
 
    /*针对ip地址的四个部分分别处理*/
    for(i = 0;i < 4;i++ )
    {
        count = 0;
        for(; ip[j]!='.' && ip[j]!='\0'; j++)
            count = count*10 + ip[j]-'0';
 
        /*判断输入的ip地址是否合法*/
        if( count<0 || count>255 )
            return -1;
 
        j++;
        /*
            移位--移8位
        */
        ipf = ipf*256 + count;
    }
    /*j复用归零*/
    j = 0;
 
    /*针对cidr的四个部分分别处理*/
    for( i=0; i<4; i++ )
    {
        count = 0;
        for( ; cidr[j] != '.' && cidr[j] != '/'; j++ )
            count=count*10 + cidr[j] - '0';
 
        /*判断输入的cidr地址是否合法*/
        if( count<0 || count>255 )
            return -1;
 
        j++;
        cidrf = cidrf*256 + count;
    }
 
    int tail = 0;
    for( ; cidr[j]!='\0'; j++)
        tail = tail*10 + cidr[j] - '0';
 
    /*计算掩码*/
    int mask = ( (1<<tail) - 1) << (32 - tail);
 
    /*判断是否在一个网段-- 按位与*/
    if((ipf&mask) == (cidrf&mask))
        return true;
 
    else
        return -1;
}
int main(void)
{
    fow(int i=0;;i++)
    int ans = Check_lP_in_CIDR(str_datapacket,str_rule);
    printf("%d\n",ans);
    return 0;
}
void output_file()
{
    FILE *fp;
    char str[102] = {0}, strTemp[100];
    if( (fp=fopen("C:\\Users\\Enolaliu\\Desktop\\winter2\\dataset\\data\\res.txt", "at+")) == NULL )
    {
        puts("Fail to open file!");
        exit(0);
    }
    printf("Input a string:");
    gets(strTemp);
    strcat(str, "\n");
    strcat(str, strTemp);
    fputs(str, fp);
    fclose(fp);
    return 0;
}