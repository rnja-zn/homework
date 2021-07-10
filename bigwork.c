# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# define SIZE 256

int i;//患者数据所在位置
int c = 0;//判断是否挂号
int l;//选择功能对应数字的载体
void homepage();//声明主页函数

struct Pinf//定义患者信息类型
{
    int cardnum;
    char name[10];
    int age;
    char sex[10];
}pat[SIZE];

void iden(void)//身份登记
{
    FILE * fp;
    int j = 100;
    int k;
    int h;
    int b;
    printf("————————————登录————————————\n");
    printf("您是否初次到本院就诊？\n");
    printf("1:是; 2.否.\n");
    scanf("%d",&i);
    getchar();
    switch(i)
    {
        case 1:
          {
              if((fp = fopen("information.txt","a+")) == NULL)
                {
                    printf("Cannot open file!\n");
                    exit(0);
                }
              printf("请分别输入您的健康卡号、姓名拼音、年龄、性别拼音:\n");
              scanf("%d",&pat[j].cardnum);
              scanf("%s",pat[j].name);
              scanf("%d",&pat[j].age);
              scanf("%s",pat[j].sex);
              fprintf(fp,"%d %s %d %s\n",pat[j].cardnum,pat[j].name,pat[j].age,pat[j].sex);
              fclose(fp);
              break;
          }
        case 2:
          {
               printf("请输入您的健康卡号：\n");
               scanf("%d",&k);
               if((fp = fopen("information.txt","r+")) == NULL)
                {
                    printf("Cannot open file!\n");
                    exit(0);
                }
                for(i=0; i<SIZE; i++)
                {
                    h = fscanf(fp,"%d %s %d %s",&pat[i].cardnum,pat[i].name,&pat[i].age,pat[i].sex);
                    if(pat[i].cardnum == k)
                    {
                        printf("%s,欢迎您使用本程序！是否需要更新数据？\n",pat[i].name);
                        printf("1.是；2.否\n");
                        scanf("%d",&l);
                        switch(l)
                        {
                            case 1:
                            {
                                printf("请输入您现在的年龄：\n");
                                scanf("%d",&pat[i].age);
                                for(b=0; b<SIZE; b++)
                                   fprintf(fp,"%d %s %d %s\n",pat[b].cardnum,pat[b].name,pat[b].age,pat[b].sex);
                                printf("数据更新完毕！\n");
                                break;
                            }
                            case 2:
                                break;
                            default:
                                printf("出错了！该数字无对应选项！");
                                exit(0);
                        }
                        break;
                    }
                }
                if(h == EOF)
                {
                    printf("您输入的健康码不存在或未保存到本院文件中\n");
                    exit(0);
                }
                fclose(fp);
                break;
          }
        default :
                printf("出错了！该数字无对应功能！");
                exit(0);
    }
    return;
}

void fev(void)//发热识别
{
    printf("————————————疫情防控————————————\n");
    printf("请问您是否有发热症状（如体温高于37℃、干咳、乏力）？\n");
    printf("1:是; 2.否.\n");
    scanf("%d",&l);
    switch(l)
    {
        case 1:
        {
            printf("请留下您的联系方式：");
            scanf("%d",&l);
            printf("由于本院为皮肤专科医院，未设置发热门诊，将为您联系本市有治疗条件的医院，更多内容将与您联系时详谈。\n");
            exit(0);
        }
        case 2:
            break;
        default:
            printf("出错了！该数字无对应选项！");
            exit(0);
            
    }
    return;
}

void reg()//挂号页面
{
    printf("————————————欢迎进入挂号系统————————————\n");
    if(c == 0)
    {
        printf("请选择要挂号的医生：\n");
        printf("1. 郑月  主任医师  擅长治疗慢性荨麻疹   201\n");
        printf("2.药蒙尘 副主任医师   擅长治疗痤疮      202\n");
        printf("3. 吴言  主治医师     擅长治疗湿疹      203\n");
        scanf("%d",&c);
        switch(c)
        {
            case 1:
                    printf("挂号成功，请您移步201就诊。\n");
                    break;
            case 2:
                    printf("挂号成功，请您移步202就诊。\n");
                    break;
            case 3:
                    printf("挂号成功，请您移步203就诊。\n");
                    break;
            default:
                    printf("出错了！该数字无对应医生！");
                    exit(0);
        }
    }
    else
    {
        printf("您已经挂过号了！\n");
        printf("1.重新挂号\n");
        printf("2.返回主页\n");
        scanf("%d",&l);
        switch(l)
        {
            case 1:
            {
                c = 0;
                reg();
                return;
            }
            case 2:
                homepage();
                break;
            default:
                printf("出错了！该数字无对应选项！");
                exit(0);
        }
    }
    system("pause");
    return;
}

void doc()//就诊页面
{
    printf("————————————欢迎进入就诊系统————————————\n");
    if(c ==0)
            printf("您未挂号！\n");
    else
    {
        printf("您是否已完成就诊？\n");
        printf("1:是; 2.否.\n");
        scanf("%d",&l);
        if(l==1)
        {
            printf("您的就诊信息如下：\n");
            printf("姓名：%s\n",pat[i].name);
            printf("年龄：%d\n",pat[i].age);
            printf("健康卡号：%d\n",pat[i].cardnum);
            if(c ==0)
                printf("您未挂号！\n");
            switch(c)
            {
                case 1:
                {
                    printf("确诊：胆碱能性荨麻疹\n");
                    printf("确诊医生：郑月\n");
                    printf("医嘱：按时吃药，多运动，减少辛辣油腻食物的摄入。\n");
                    break;
                }
                
                case 2:
                {
                    printf("确诊：痤疮\n");
                    printf("确诊医生：药蒙尘\n");
                    printf("医嘱：按时吃药，多运动，减少辛辣油腻食物的摄入。\n");
                    break;
                }
                case 3:
                {
                    printf("确诊：湿疹\n");
                    printf("确诊医生：吴言\n");
                    printf("医嘱：按时吃药，多运动，减少辛辣油腻食物的摄入。\n");
                    break;
                }
            }
        }
        if(l==2)
        {
            switch(c)
            {
                case 1:
                    printf("请您移步201就诊。\n");
                    break;
                case 2:
                    printf("请您移步202就诊。\n");
                    break;
                case 3:
                    printf("请您移步203就诊。\n");
                    break;
            }
        }
    }
    system("pause");
    return;
}

void get()//取药页面
{
    printf("————————————欢迎进入取药系统————————————\n");
    if(c ==0)
            printf("您未挂号！\n");
    else
    {
        switch(c)
            {
                case 1:
                {
                    printf("氯雷他定片（每日一次） 数量：1 单价：24元\n");
                    printf("多塞平软膏（每日2~3次）数量：1 单价：17元\n");
                    break;
                }
                
                case 2:
                {
                    printf("异维A酸软胶囊（隔天一次）数量：1 单价：28元\n");
                    printf("喜辽妥（每晚一次）数量：1 单价：26元\n");
                    break;
                }
                case 3:
                {
                    printf("盐酸西替利嗪(每日一次) 数量：1 单价：21元\n");
                    printf("多塞平软膏（每日2~3次）数量：1 单价：17元\n");
                    break;
                }
            }
        printf("请您移步105取药，支持现金支付\n");
    }
    system("pause");
    homepage();
}

void onl()//线上问诊页面
{
    printf("————————————欢迎进入线上问诊系统————————————\n");
    printf("当前在线医生数：0，请您移步本院进行线下问诊。\n");
    system("pause");
    return;
}


void homepage(void)//系统主页面
{
    printf("————————————主页————————————\n");
    printf("疫情期间，请务必做好个人及家庭的安全防护工作。少出门、多居家，不聚餐、少聚集，多通风、勤洗手，出门必须戴口罩、不戴口罩不出门！ \n");
    printf("1:挂号；\n");
    printf("2:就诊；\n");
    printf("3:取药；\n");
    printf("4:在线问诊;\n");
    printf("5:退出。\n");
    scanf("%d",&l);
    switch(l)
    {
        case 1:
               reg();
               break;
        case 2:
               doc();
               break;
        case 3:
               get();
               break;
        case 4:
               onl();
               break;
        case 5:
               exit(0);
        default:
               printf("出错了！该数字无对应功能！");
               exit(0);
    }
    return;
}

int main(void)
{
    printf("欢迎进入水闰人圭皮肤医院管理系统!您可以通过输入数字来回答或进入您所需的服务系统。\n");
    iden();
    fev();
    while(i != -1)
    {
      homepage();
    }
    system("pause");
    return 0;
}