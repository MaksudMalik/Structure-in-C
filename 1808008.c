#include<stdio.h>
#include<string.h>
typedef struct departmentInfo{
    int department_ID;
    char department_name [51];
    int manager_ID;
}dept;
typedef struct employeeInfo{
    int employee_ID;
    int department_ID;
    float salary;
    char joining_date[11];
}emp;
void dtoi(char *s,int num[])
{
    int i=9,n=0,j=1,index=0;
    while(i>=0)
    {
        n+=(s[i]-'0')*j;
        j*=10;
        i--;
        if (!('0'<=s[i]&&'9'>=s[i]))
        {
            num[index++]=n;
            j=1;
            n=0;
            i--;
            //continue;
        }
    }
}
main()
{
    int m,n,date1[3],date2[3],i,j,dno;
    scanf("%d",&n);
    dept d[n];
    for (int i=0;i<n;i++)
    {
        scanf("%d %s %d",&d[i].department_ID,d[i].department_name,&d[i].manager_ID);
    }
    scanf("%d",&m);
    emp e[m];
    for (int i=0;i<m;i++)
    {
        scanf("%d %d %f %s",&e[i].employee_ID,&e[i].department_ID,&e[i].salary,e[i].joining_date);
    }
    char maxdate[11];
    for(i=0;i<m;i++)
    {
        int found=0;
        for (j=0;j<=n;j++)
        {
            if(e[i].employee_ID==d[j].manager_ID)
            {
                dno=j;
                strcpy(maxdate,e[i].joining_date);
                dtoi(maxdate,date1);
                j++;
                found++;
                break;
            }
        }
        if (found!=0)
        {
            i++;
            break;
        }
    }
    for (i;i<m;i++)
    {
        if (e[i].employee_ID==d[j].manager_ID)
        {
            j++;
            dtoi(e[i].joining_date,date2);
            if(date2[0]<date1[0])
            {
                strcpy(maxdate,e[i].joining_date);
                dtoi(maxdate,date1);
                dno=j-1;
            }
            else if (date2[0]==date1[0])
            {
                if(date2[1]<date1[1])
                {
                    strcpy(maxdate,e[i].joining_date);
                    dtoi(maxdate,date1);
                    dno=j-1;
                }
                else if (date2[1]==date1[1])
                {
                    if(date2[2]<date1[2])
                    {
                        strcpy(maxdate,e[i].joining_date);
                        dtoi(maxdate,date1);
                        dno=j-1;
                    }
                }
            }
        }
    }
    printf("Department with seniormost manager :%s (%d %s)\n",d[dno].department_name,d[dno].manager_ID, maxdate);
    float avgs[n][4];

    for (j=0;j<n;j++)
    {
        avgs[j][1]=0;
        avgs[j][2]=0;
        for (i=0;i<m;i++)
        {
            if(e[i].department_ID==d[j].department_ID)
            {
                avgs[j][1]+=e[i].salary;
                avgs[j][2]++;
            }
        }
        avgs[j][0]=j;
        avgs[j][3]=0;
        avgs[j][1]/=avgs[j][2];
        //printf("%d %0.2f %d \n",d[(int)avgs[j][0]].department_ID,avgs[j][1],(int)avgs[j][2]);
    }
    float temp[3];
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(avgs[i][1]>avgs[j][1])
            {
                temp[0]=avgs[i][0];
                temp[1]=avgs[i][1];
                temp[2]=avgs[i][2];
                avgs[i][0]=avgs[j][0];
                avgs[i][1]=avgs[j][1];
                avgs[i][2]=avgs[j][2];
                avgs[j][0]=temp[0];
                avgs[j][1]=temp[1];
                avgs[j][2]=temp[2];
            }
        }
    }
    for(i=0;i<n;i++)
    {
        printf("%d %s %0.2f %d \n",d[(int)avgs[i][0]].department_ID,d[(int)avgs[i][0]].department_name,avgs[i][1],(int)avgs[i][2]);
    }
}
